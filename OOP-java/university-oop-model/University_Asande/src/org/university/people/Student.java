package org.university.people;

import java.util.ArrayList;
import org.university.software.Course;
import org.university.hardware.Department;

public class Student {
	// fields, constructors, methods
	private String name;
	private Department department;
	private ArrayList<Course> schedule = new ArrayList<>();
	
	private int unitsCompleted;
	private int totalUnitsNeeded;
	
	// Constructor
	public Student() {
		this.name = "";
		this.unitsCompleted = 0;
		this.totalUnitsNeeded = 120;
	}
	
	// Getters and setters
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
	
	public int getUnitsCompleted() { 
		return unitsCompleted;
	}
	
    public void setUnitsCompleted(int units) { this.unitsCompleted = units; }

    public int getTotalUnitsNeeded() { 
    	return totalUnitsNeeded;
    }
    
    public void setTotalUnitsNeeded(int total) { this.totalUnitsNeeded = total; }

    private static String codeOf(org.university.software.Course c) {
        String dept = (c.getDepartment() != null) ? c.getDepartment().getName() : "";
        return dept + c.getCourseNumber();
    }

    public void addCourse(org.university.software.Course c) {
    	
    	java.util.List<Integer> overlaps = new java.util.ArrayList<>();
    	org.university.software.Course conflictWith = null;

    	for (org.university.software.Course ex : schedule) {
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

    	if (!schedule.contains(c)) {
    	    schedule.add(c);
    	    if (!c.getRoster().contains(this)) c.getRoster().add(this);
    	}  	
    }
    

    public void dropCourse(org.university.software.Course aCourse) {
        if (aCourse == null) return;
        if (schedule.remove(aCourse)) {
            aCourse.removeStudent(this);
        } else {
            String code = codeOf(aCourse); // ECE373, CS345, etc.
            System.out.println("The course " + code + " could not be dropped because "
                + name + " is not enrolled in " + code + ".");
        }
    }

    public void printSchedule() {
        java.util.List<String> entries = new java.util.ArrayList<>();
        for (org.university.software.Course c : schedule) {
            String code = codeOf(c);
            for (int t : c.getSchedule()) {
                String key = String.format("%03d", t);
                entries.add(key + " " + org.university.software.Course.formatSlot(t)
                            + " " + code + " " + c.getCourseName());
            }
        }
        java.util.Collections.sort(entries);
        for (String e : entries) System.out.println(e.substring(4));
    }
        
    
    // For Driver 2
    public void setRequiredCredits(int total) { this.totalUnitsNeeded = total; }
    public void setCompletedUnits(int done)   { this.unitsCompleted = done; }
    public int requiredToGraduate() {
        int rem = totalUnitsNeeded - unitsCompleted;
        return (rem < 0) ? 0 : rem;
    }
    
    public boolean detectConflict(org.university.software.Course aCourse) {
        for (org.university.software.Course ex : schedule) {
            for (int s1 : ex.getSchedule())
                for (int s2 : aCourse.getSchedule())
                    if (s1 == s2) return true;
        }
        return false;
    }
}
