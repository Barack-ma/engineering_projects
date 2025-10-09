package org.university.hardware;

import java.util.ArrayList;
import org.university.people.Student;
import org.university.people.Professor;
import org.university.software.Course;

public class Department{
	// fields, constructors, methods
	private String name; 
	private ArrayList<Student> studentList = new ArrayList<>();
	private ArrayList<Professor> professorList = new ArrayList<>();
	private ArrayList<Course> courseList = new ArrayList<>();
	
	// Constructor
	public Department() {
		this.name = "";
	}
	
	// Getter and Setters
	public String getName() {return name;}
	public void setName(String name) {this.name = name;}
	public ArrayList<Student> getStudentList(){ return studentList; }
	public ArrayList<Professor> getProfessorList() {return professorList; }
	public ArrayList<Course> getCourseList(){return courseList;}
	
	// alias for driver
	public void setDepartmentName(String name) { this.name = name; }

	public void addStudent(org.university.people.Student s) {
	    if (s != null && !studentList.contains(s)) {
	        studentList.add(s);
	        s.setDepartment(this);
	    }
	}
	public void addProfessor(org.university.people.Professor p) {
	    if (p != null && !professorList.contains(p)) {
	        professorList.add(p);
	        p.setDepartment(this);
	    }
	}
	
	public void addCourse(org.university.software.Course c) {
	    if (c == null) return;

	    
	    org.university.hardware.Department prev = c.getDepartment();
	    if (prev != null && prev != this) {
	        prev.getCourseList().remove(c);
	    }

	    // Add to this department's list if not already present
	    if (!courseList.contains(c)) {
	        courseList.add(c);
	    }
	    
	    c.setDepartment(this);
	}

	public void printStudentList() {
	    for (Student s : studentList) {
	        System.out.println(s.getName());
	    }
	}

	public void printProfessorList() {
	    for (Professor p : professorList) {
	        System.out.println(p.getName());
	    }
	}

	public void printCourseList() {
	    for (Course c : courseList) {
	        String dept = (c.getDepartment() != null) ? c.getDepartment().getName() : this.name;
	        System.out.println(dept + c.getCourseNumber());
	    }
	}

	public String getDepartmentName() { return name; }  
}

