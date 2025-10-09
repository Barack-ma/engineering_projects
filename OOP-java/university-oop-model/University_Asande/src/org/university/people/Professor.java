package org.university.people;

import java.util.ArrayList;
import org.university.software.Course;
import org.university.hardware.Department;

public class Professor {
	// fields, constructors, methods
	private String name;
    private Department department;
    private ArrayList<Course> teachingSchedule = new ArrayList<>();
    
    // Constructor
    public Professor() {
        this.name = "";
    }
    
 // Getters and Setters
    public String getName() { 
    	return name; 
    }
    
    public void setName(String name) { 
    	this.name = name;
    }

    public Department getDepartment() { 
    	return department; 
    }
    
    public void setDepartment(Department dept) { 
    	this.department = dept; 
    }

    public ArrayList<Course> getTeachingSchedule() { 
    	return teachingSchedule; 
    }
    
    // helper
    private static String codeOf(org.university.software.Course c) {
        String dept = (c.getDepartment() != null) ? c.getDepartment().getName() : "";
        return dept + c.getCourseNumber(); // e.g., "ECE320"
    }

    public void addCourse(org.university.software.Course c) {
        if (c == null) return;

        if (c.getProfessor() != null && c.getProfessor() != this) {
        	System.out.println("The professor cannot be assigned to this course because professor "
        			+ c.getProfessor().getName() + " is already assigned to the course "
        		    + c.getCourseName() + ".");
            return;
        }

        // Checking for time conflicts against professor's current courses
        java.util.List<Integer> overlaps = new java.util.ArrayList<>();
        org.university.software.Course conflictWith = null;

        for (org.university.software.Course ex : teachingSchedule) {
            for (int slot : ex.getSchedule()) {
                if (c.getSchedule().contains(slot)) {
                    overlaps.add(slot);
                    conflictWith = ex; 
                }
            }
        }

        if (!overlaps.isEmpty()) {
            for (int slot : overlaps) {
                String s = org.university.software.Course.formatSlot(slot);
                System.out.println(codeOf(c) + " course cannot be added to " + this.getName()
                    + "'s Schedule. " + codeOf(c) + " conflicts with " + codeOf(conflictWith)
                    + ". Conflicting time slot is " + s + ".");
            }
            return;
        }

        // if no conflict, assign course to professor
        if (!teachingSchedule.contains(c)) teachingSchedule.add(c);
        c.setProfessor(this);
    }    
    
    public void printSchedule() {
        java.util.List<String> entries = new java.util.ArrayList<>();
        for (org.university.software.Course c : teachingSchedule) {
            for (int code : c.getSchedule()) {
                String key = String.format("%03d", code);
                entries.add(key + " " + org.university.software.Course.formatSlot(code)
                            + " " + codeOf(c) + " " + c.getCourseName());
            }
        }
        java.util.Collections.sort(entries);
        for (String e : entries) System.out.println(e.substring(4));
    }
    
    // Boolean flag for Driver 2
    public boolean detectConflict(org.university.software.Course aCourse) {
        for (org.university.software.Course existing : teachingSchedule) {
            for (int a : existing.getSchedule()) {
                for (int b : aCourse.getSchedule()) {
                    if (a == b) return true;
                }
            }
        }
        return false;
    }

}
