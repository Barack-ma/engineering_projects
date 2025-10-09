package org.university.hardware;

import java.util.ArrayList;
import org.university.software.Course;

public class Classroom {
	private String roomNumber;
	private ArrayList<Course> coursesInRoom = new ArrayList<>();
	
	// codeOf (converting an object to course code string
	private static String codeOf(org.university.software.Course c) {
	    String dept = (c.getDepartment() != null) ? c.getDepartment().getName() : "";
	    return dept + c.getCourseNumber();
	}
	
	public void addCourse(org.university.software.Course aCourse) {
	    for (org.university.software.Course ex : coursesInRoom) {
	        for (int slot : ex.getSchedule()) {
	            if (aCourse.getSchedule().contains(slot)) {
	                String s = org.university.software.Course.formatSlot(slot);
	                System.out.println(codeOf(aCourse) + " conflicts with " + codeOf(ex)
	                    + ". Conflicting time slot " + s + ". " + codeOf(aCourse)
	                    + " course cannot be added to " + roomNumber + "'s Schedule.");
	                return;
	            }
	        }
	    }
	    coursesInRoom.add(aCourse);
	    aCourse.setClassroom(this);
	}
	
	// constructor
	public Classroom() {
		this.roomNumber = "";
	}
	
	//Getter and setters
	public String getRoomNumber() { return roomNumber; }
	public void setRoomNumber(String roomNumber) {this.roomNumber = roomNumber;}
	
	public ArrayList<Course> getCoursesInRoom(){
		return coursesInRoom;
	}
	
	public void printSchedule() {
	    java.util.List<String> entries = new java.util.ArrayList<>();
	    for (org.university.software.Course c : coursesInRoom) {
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
	
}
