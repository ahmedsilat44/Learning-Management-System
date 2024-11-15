


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

    User(string userId, string username, string password, string email, string role);

    void login(string username, string password);
    void logout();
    void viewProfile();
    void getRole();
    string getUsername();
};

class Student : public User {
private:
    string studentId;
    float gpa;
    vector<Course> enrolledCourses;
    string Category ;
public:
    Student(string userId, string username, string password, string email, string role, string studentId,);
    void viewDashboard();
    void checkGPARequirement();
    float getGPA();
};

class Teacher : public User {
private:
    string teacherId;
public:
    Teacher(string userId, string username, string password, string email, string role,string teacherId);
    void viewDashboard();
    void gradeAssignment();
    void createAssignment();
    void postAnnouncement();
};

class Admin : public User {
    private:
    string adminId;

public:
    Admin(string userId, string username, string password, string email, string role, string adminId);
    void viewDashboard();
    void createCourse();
    void createSection();
};

class Grade {
    private:
    string studentId;
    string courseId;
    float grade;
public:
        Grade();
        void addGrade();
        void viewGrade();
        void updateGrade();
    
};

class Section {

};

class Course {
    private:
    string courseId;
    string courseName;
    string description;
    Teacher assignedTeacher;
    vector<Section> sections;
    vector<Student> students;
    vector<Assignment> Assignment;
public:
    Course(string courseId, string courseName, string description, Teacher assignedTeacher);
    void addStudent();
    void removeStudent();
    void addAssignment();
};

class Assignment {
    private:
    string assignmentId;
    string dueDate;
    int maxScore;
    vector<Submission> submissions;
public:
        Assignment(string assignmentId, string dueDate, int maxScore);
        void submitAssignment();
        void gradeSubmission();
    };

class Submission {
    private:
    string submissionId;
    string assignmentId;
    string studentId;
    string submissionDate;
    int grade;
public:
    
        void submit();
        void viewFeedback();
    };



