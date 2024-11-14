// Our project will implement a Learning Management System (LMS) using an ObjectOriented methodology. The LMS will have a login page, asking users to enter their details.
// The details will determine whether the user will be an administrator, faculty member, or
// student, with separate methods for each.
// Administrators will be able to:
// 1) Create new courses and/or sections for each semester
// 2) Add students and teachers to sections
// 3) Add credit count
// 4) View existing courses
// 5) Delete existing courses
// Teachers will be able to:
// 1) View courses they are teaching
// 2) Create new assignments
// 3) Assign each assignment a weightage out of 100
// 4) Grade assignments
// 5) View students in each of their sections
// Students will be able to:
// 1) View their grade in each assignment
// 2) View courses they are enrolled in
// 3) View grades in each course
// 4) View GPA
// 5) View grades required to maintain their scholarship
// 6) View GPA required to maintain scholarship
// 7) View weightage of each assignment


// Header file for the LMS class


// User

// Description: Base class for all users in the system, including attributes and methods common to all users.
// Attributes: userId, username, password, email, role
// Methods: login(), logout(), viewProfile()
// Relationships:
// Inheritance: Parent class for Student, Teacher, Admin

// Student (inherits from User)

// Description: Base class for different types of students, providing common student attributes and methods.
// Attributes: studentId, gpa, enrolledCourses , category (YohsinStudent, HighScholarshipStudent, LowScholarshipStudent, NoScholarshipStudent)
// Methods: viewDashboard(), checkGPARequirement()


// Teacher (inherits from User)

// Description: Represents teachers with attributes and methods to manage courses and assignments.
// Attributes: teacherId, assignedCourses
// Methods: createCourse(), gradeAssignment(), postAnnouncement()
// Admin (inherits from User)

// Description: Represents administrators with permissions to manage users and monitor the system.
// Attributes: adminId, permissions
// Methods: createUser(), manageCourses(), generateReports()
// Course

// Description: Represents a course with attributes for its content and enrolled students.
// Attributes: courseId, courseName, description, assignedTeacher, students, content
// Methods: addStudent(), removeStudent(), addContent(), postAnnouncement()
// Relationships:
// Composition: Contains Content, Assignment, Announcement








// Assignment

// Description: Specific type of content representing assignments with submission and grading features.
// Attributes: assignmentId, dueDate, maxScore, submissions
// Methods: submitAssignment(), gradeSubmission()
// Relationships:
// Aggregation: Contains Submission
// Submission

// Description: Represents individual assignment submissions by students.
// Attributes: submissionId, assignmentId, studentId, file, submissionDate, grade
// Methods: submit(), viewFeedback()

#ifdef LMS_H // If the LMS_H macro is not defined, the code will be included in the compilation process
#define LMS_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <iterator>
#include <fstream>

using namespace std;

class User {
    private:
    string userId;
    string username;
    string password;
    string email;
    string role;
public:

    void login();
    void logout();
    void viewProfile();
};

class Student : public User {
private:
    string studentId;
    float gpa;
    vector<string> enrolledCourses;
    string category;
public:

    void viewDashboard();
    void checkGPARequirement();
};

class Teacher : public User {
private:
    string teacherId;
    vector<string> assignedCourses;
public:

    void createCourse();
    void gradeAssignment();
    void postAnnouncement();
};

class Admin : public User {
    private:
    string adminId;
    string permissions;
public:

    void createUser();
    void manageCourses();
    void generateReports();
};

class Course {
    private:
    string courseId;
    string courseName;
    string description;
    string assignedTeacher;
    vector<string> students;
    vector<string> Assignment;
public:

    void addStudent();
    void removeStudent();
    void addContent();
    void postAnnouncement();
};

class Assignment {
    private:
    string assignmentId;
    string dueDate;
    int maxScore;
    vector<string> submissions;
public:
    
        void submitAssignment();
        void gradeSubmission();
    };

class Submission {
    private:
    string submissionId;
    string assignmentId;
    string studentId;
    string file;
    string submissionDate;
    int grade;
public:
    
        void submit();
        void viewFeedback();
    };

#endif

