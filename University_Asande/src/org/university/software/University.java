package org.university.software;

import java.util.ArrayList;

import org.university.hardware.Classroom;
import org.university.hardware.Department;
import org.university.people.Professor;
import org.university.people.Student;

public class University {

    private String name;

    private ArrayList<Department> departments = new ArrayList<>();
    private ArrayList<Classroom> classrooms  = new ArrayList<>();
    private ArrayList<Student>   students    = new ArrayList<>();
    private ArrayList<Professor> professors  = new ArrayList<>();
    private ArrayList<Course>    courses     = new ArrayList<>();

    // Ensures no duplication storage
    public final ArrayList<Department> departmentList = departments;
    public final ArrayList<Classroom>  classroomList  = classrooms;

    
    public University() {
        this.name = "";
    }

    // Getters 
    public String getName() { return name; }
    public ArrayList<Department> getDepartments() { return departments; }
    public ArrayList<Classroom>  getClassrooms()  { return classrooms; }
    public ArrayList<Student>    getStudents()    { return students; }
    public ArrayList<Professor>  getProfessors()  { return professors; }
    public ArrayList<Course>     getCourses()     { return courses; }

    public void addDepartment(Department d) { if (d != null) departments.add(d); }
    public void addClassroom(Classroom r)   { if (r != null) classrooms.add(r); }
    public void addStudent(Student s)       { if (s != null) students.add(s); }
    public void addProfessor(Professor p)   { if (p != null) professors.add(p); }
    public void addCourse(Course c)         { if (c != null) courses.add(c); }

    // Printing functions
    public void printStudentList() {
        System.out.println("Students at " + name + ":");
        for (Student s : students) System.out.println(" - " + s.getName());
    }

    public void printProfessorList() {
        System.out.println("Professors at " + name + ":");
        for (Professor p : professors) System.out.println(" - " + p.getName());
    }

    public void printCourseList() {
        System.out.println("Courses at " + name + ":");
        for (Course c : courses)
            System.out.println(" - " + c.getCourseNumber() + " " + c.getCourseName());
    }
}
