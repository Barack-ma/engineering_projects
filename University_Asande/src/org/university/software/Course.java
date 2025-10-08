package org.university.software;

import java.util.ArrayList;
import org.university.people.Student;
import org.university.people.Professor;
import org.university.hardware.Department;
import org.university.hardware.Classroom;

public class Course {
	// fields, constructors, methods
	private String courseName;
    private int courseNumber;
    private Department department;
    private Professor professor;
    private ArrayList<Student> roster = new ArrayList<>();
    private ArrayList<Integer> schedule = new ArrayList<>();
    private Classroom classroom;
    
    // Given from Assignment 2
    public static final String[] WEEK = {"Mon", "Tue", "Wed", "Thu", "Fri"};
    public static final String[] SLOT = {
        "8:00am to 9:15am",
        "9:30am to 10:45am",
        "11:00am to 12:15pm",
        "12:30pm to 1:45pm",
        "2:00pm to 3:15pm",
        "3:30pm to 4:45pm"
    };

    public static String formatSlot(int code) {
        int dayIndex = (code / 100) - 1;  
        int slotIndex = (code % 100) - 1; 
        if (dayIndex < 0 || dayIndex >= WEEK.length || slotIndex < 0 || slotIndex >= SLOT.length) {
            return "Invalid time";
        }
        return WEEK[dayIndex] + " " + SLOT[slotIndex];
    }

    public java.util.ArrayList<org.university.people.Student> getStudentRoster() { 
    	return roster; 
    }
    
    public String getName() { return courseName; }


    // Prints course meeting times
    public void printSchedule() {
        java.util.ArrayList<Integer> times = new java.util.ArrayList<>(schedule);
        java.util.Collections.sort(times);
        for (int t : times) {
            String room = (classroom != null) ? classroom.getRoomNumber() : "";
            System.out.println(formatSlot(t) + " " + room);
        }
    }


    // Simple overlap check - to be used with other classes
    public boolean conflictsWith(Course other) {
        for (int a : this.schedule) {
            for (int b : other.schedule) {
                if (a == b) return true;
            }
        }
        return false;
    }

    
    // constructor
    public Course() {
    	this.courseName = "";
    	this.courseNumber = 0;
    }
    
    // getters and setters
    public String getCourseName() { return courseName;}
    public void setCourseName(String courseName) {this.courseName = courseName;}
    
    public int getCourseNumber() {return courseNumber;}
    public void setCourseNumber(int courseNumber) {this.courseNumber = courseNumber;}
    
    public org.university.hardware.Department getDepartment() { return department; }
    
    public void setDepartment(org.university.hardware.Department department) {
        if (this.department != null && this.department != department) {
            this.department.getCourseList().remove(this);
        }
        this.department = department;
        if (department != null && !department.getCourseList().contains(this)) {
            department.getCourseList().add(this);
        }
    }

    
    
    public Professor getProfessor() {return professor; }
    public void setProfessor(Professor professor) {this.professor = professor; }
    
    public ArrayList<Student> getRoster() {return roster; }
    public ArrayList<Integer> getSchedule() {return schedule;}
    
    public Classroom getClassroom() {return classroom; }
    public void setClassroom(Classroom classroom) {this.classroom = classroom; }   
    
    public void setName(String name) { this.courseName = name; }

    
    public void setSchedule(int slot) { 
        if (!schedule.contains(slot)) schedule.add(slot); 
    }

    public void setRoomAssigned(org.university.hardware.Classroom room) {
        if (room == null) {
            this.classroom = null;
            return;
        }
        room.addCourse(this);
    }

    public void addStudent(org.university.people.Student s) {
        if (s == null) return;
        if (!roster.contains(s)) roster.add(s);
    }
    
    public void removeStudent(org.university.people.Student s) {
        roster.remove(s);
    }

   
}
