#include "LMS.h"
    


using namespace std;



User::User(string userId, string username, string password, string email, string role) {
    this->userId = userId;
    this->username = username;
    this->password = password;
    this->email = email;
    this->role = role;
}

Student::Student(string userId, string username, string password, string email, string role, string studentId) : User(userId, username, password, email, role) {
    this->studentId = studentId;
}

Teacher::Teacher(string userId, string username, string password, string email, string role, string teacherId) : User(userId, username, password, email, role) {
    this->teacherId = teacherId;
}

Admin::Admin(string userId, string username, string password, string email, string role, string adminId) : User(userId, username, password, email, role) {
    this->adminId = adminId;
}

string User::getUsername() {
    return username;
}

// User class methods
void User::login(string id, string pass, vector<User> users) {
    for (int i = 0; i < users.size(); ++i) {
        if (users[i].getUsername() == id) {
            if (users[i].password == pass) {
                cout << "Login successful!" << endl;
            } else {
                cout << "Incorrect password!" << endl;
            }
        } else {
            cout << "User not found!" << endl;
        }
    }
}

void User::logout() {
    cout << "Logout successful!" << endl;

}


void User::viewProfile() {
    // Send to viewProfile page
}

// Student class methods
void Student::viewDashboard() {
    // Send to Dashboard page
}

float Student::getGPA() {
    float totalGrade = 0;
    for (int i = 0; i < grades.size(); ++i) {
        if (grades[i].studentId == studentId) {
            totalGrade =  grades[i].grade;
        }
    }
    float gradePercentage = totalGrade / grade.size();
   return gradePercentage;
}

void Student::checkGPARequirement() {
    float gradePercentage = getGPA();
     if (this->Category == "Yohsin") {
        if (gradePercentage >= 87.5) {
            cout << "Good Grade Standing" << endl;
        } else {
            cout << "Academic Warning" << endl;
        }
    } else if (this->Category == "High") {
        if (gradePercentage >= 75) {
            cout << "Good Grade Standing" << endl;
        } else {
            cout << "Academic Warning" << endl;
        }
    } else{
        if (gradePercentage >= 67.5) {
            cout << "Good Grade Standing" << endl;
        } else {
            cout << "Academic Warning" << endl;
        }
    }
}

// Teacher class methods
void Teacher::createAssignment(string courseID) {
    for (int i = 0; i < courses.size(); ++i) {
        if (courses[i].courseId == courseID) {
            courses[i].addAssignment();
        }
    }

}

void Teacher::viewDashboard() {
    // Send to Dashboard page
}

void Teacher::gradeAssignment(string assignmentId, string studentId) {
    for (int i = 0; i < assignments.size(); ++i) {
        if (assignments[i].assignmentId == assignmentId) {
            assignments[i].gradeSubmission();
        }
    }
}



// Admin class methods
void Admin::createUser(string userId, string username, string password, string email, string role, vector<User> users) {
    User user = User(userId, username, password, email, role);
    users.push_back(user);

}

void Admin::viewDashboard() {
    // Send to Dashboard page
}


void Admin::manageCourses() {
}

void Admin::generateReports() {
}

// Course class methods
void Course::addStudent() {
}

void Course::removeStudent() {
}

void Course::addAssignment() {
}

void Course::postAnnouncement() {
}

// Assignment class methods
void Assignment::submitAssignment() {
}

void Assignment::gradeSubmission() {
}

// Submission class methods
void Submission::submit() {
}

void Submission::viewFeedback() {
}

vector<User> users;


int main() {
    // Create instances of User, Student, Teacher, Admin, Course, Assignment, and Submission classes
    vector<User> users;
    for (int i = 1; i <= 15; ++i) {
        users.push_back(Student("student" + to_string(i), "pass" + to_string(i), "Student" + to_string(i), "student" + to_string(i) + "@example.com", "student"));
    }

    for (int i = 1; i <= 5; ++i) {
        users.push_back(Teacher("teacher" + to_string(i), "pass" + to_string(i), "Teacher" + to_string(i), "teacher" + to_string(i) + "@example.com", "teacher"));
    }

    users.push_back(Admin("admin1", "pass1", "Admin1", "admin1@example.com", "admin"));


    for (int i = 0; i < users.size(); ++i) {
        cout << "User " << i + 1 << ": " << users[i].getUsername() << endl;
    }

    vector<Course> courses;

    for (int i = 1; i <= 5; ++i) {
        courses.push_back(Course("course" + to_string(i), "Course " + to_string(i), "Description for Course " + to_string(i)));
    }

    return 0;
}