#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

//Enum to manage different screens
enum ScreenState{
    MainScreen,
    StudentScreen,
    TeacherScreen,
    AdminScreen,
};

//Func to display the student screen
void showStudentScreen(sf::RenderWindow &window, sf::Font &font) {
    window.clear(sf::Color::White);

    //Title
    sf::Text studentTitle("Student Section", font, 40);
    studentTitle.setPosition(250, 50);
    studentTitle.setFillColor(sf::Color::Blue);

    //Buttons on screen
    sf::RectangleShape courseButton(sf::Vector2f(300, 50));
    courseButton.setPosition(250, 200);
    courseButton.setFillColor(sf::Color::Cyan);

    sf::RectangleShape studentDetailsButton(sf::Vector2f(300, 50));
    studentDetailsButton.setPosition(250, 300);
    studentDetailsButton.setFillColor(sf::Color::Cyan);

    //Button text
    sf::Text courseText("Course Details", font, 25);
    courseText.setPosition(300, 210);
    courseText.setFillColor(sf::Color::Black);

    sf::Text studentDetailsText("Student Details", font, 25);
    studentDetailsText.setPosition(300, 310);
    studentDetailsText.setFillColor(sf::Color::Black);

    //presenting on screen
    window.draw(studentTitle);
    window.draw(courseButton);
    window.draw(studentDetailsButton);
    window.draw(courseText);
    window.draw(studentDetailsText);
    window.display();
} 
bool isButtonClicked(const sf::RectangleShape &button, const sf::Vector2i &mousePos) {
    return button.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
}//copy all of the above to make teacher and admin screens make changes where necesarry

void showTeacherScreen(sf::RenderWindow &window, sf::Font &font) {
    window.clear(sf::Color::White);

    //Title
    sf::Text teacherTitle("Teacher Section", font, 40);
    teacherTitle.setPosition(250, 50);
    teacherTitle.setFillColor(sf::Color::Blue);

    //Buttons on screen
    sf::RectangleShape createButton(sf::Vector2f(300, 50));
    createButton.setPosition(250, 200);
    createButton.setFillColor(sf::Color::Cyan);

    sf::RectangleShape gradeButton(sf::Vector2f(300, 50));
    gradeButton.setPosition(250, 300);
    gradeButton.setFillColor(sf::Color::Cyan);

    //Button text
    sf::Text createText("Create Assignment", font, 25);
    createText.setPosition(300, 210);
    createText.setFillColor(sf::Color::Black);

    sf::Text gradeText("Grade Assignment", font, 25);
    gradeText.setPosition(300, 310);
    gradeText.setFillColor(sf::Color::Black);

    //presenting on screen
    window.draw(teacherTitle);
    window.draw(createButton);
    window.draw(gradeButton);
    window.draw(createText);
    window.draw(gradeText);
    window.display();
}
bool isButtonClicked2(const sf::RectangleShape &button, const sf::Vector2i &mousePos) {
    return button.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
}

void showAdminScreen(sf::RenderWindow &window, sf::Font &font) {
    window.clear(sf::Color::White);

    //Title
    sf::Text adminTitle("Admin Section", font, 40);
    adminTitle.setPosition(250, 50);
    adminTitle.setFillColor(sf::Color::Blue);

    //Buttons on screen
    sf::RectangleShape createCButton(sf::Vector2f(300, 50));
    createCButton.setPosition(250, 200);
    createCButton.setFillColor(sf::Color::Cyan);

    sf::RectangleShape existButton(sf::Vector2f(300, 50));
    existButton.setPosition(250, 300);
    existButton.setFillColor(sf::Color::Cyan);

    //Button text
    sf::Text createCText("Create Course", font, 25);
    createCText.setPosition(300, 210);
    createCText.setFillColor(sf::Color::Black);

    sf::Text existText("Existing Courses", font, 25);
    existText.setPosition(300, 310);
    existText.setFillColor(sf::Color::Black);

    //presenting on screen
    window.draw(adminTitle);
    window.draw(createCButton);
    window.draw(existButton);
    window.draw(createCText);
    window.draw(existText);
    window.display();
}
bool isButtonClicked3(const sf::RectangleShape &button, const sf::Vector2i &mousePos) {
    return button.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
}

int main() {
    //the main window (mw)
    sf::RenderWindow window(sf::VideoMode(800, 600), "Sasta LMS");
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        cerr << "Error loading font" <<endl;
        return -1;
    }


    //mw Title
    sf::Text title("Sasta LMS", font, 50);
    title.setPosition(300, 50);
    title.setFillColor(sf::Color::Blue);

    // Buttons for Student, Teacher, Admin
    sf::RectangleShape studentButton(sf::Vector2f(150, 50));
    studentButton.setPosition(150, 150);
    studentButton.setFillColor(sf::Color::Cyan);

    sf::RectangleShape teacherButton(sf::Vector2f(150, 50));
    teacherButton.setPosition(325, 150);
    teacherButton.setFillColor(sf::Color::Cyan);

    sf::RectangleShape adminButton(sf::Vector2f(150, 50));
    adminButton.setPosition(500, 150);
    adminButton.setFillColor(sf::Color::Cyan);

    //Button text
    sf::Text studentText("Student", font, 20);
    studentText.setPosition(175, 160);
    studentText.setFillColor(sf::Color::Black);

    sf::Text teacherText("Teacher", font, 20);
    teacherText.setPosition(350, 160);
    teacherText.setFillColor(sf::Color::Black);

    sf::Text adminText("Admin", font, 20);
    adminText.setPosition(535, 160);
    adminText.setFillColor(sf::Color::Black);

    //login section
    sf::Text loginText("LOGIN", font, 30);
    loginText.setPosition(350, 250);
    loginText.setFillColor(sf::Color::Black);

    sf::Text usernameText("Username:", font, 20);
    usernameText.setPosition(200, 320);
    usernameText.setFillColor(sf::Color::Black);

    sf::Text passwordText("Password:", font, 20);
    passwordText.setPosition(200, 370);
    passwordText.setFillColor(sf::Color::Black);

    //Input
    sf::RectangleShape usernameBox(sf::Vector2f(300, 30));
    usernameBox.setPosition(320, 320);
    usernameBox.setFillColor(sf::Color::White);

    sf::RectangleShape passwordBox(sf::Vector2f(300, 30));
    passwordBox.setPosition(320, 370);
    passwordBox.setFillColor(sf::Color::White);

    //Variable to track the current screen
    ScreenState currentScreen = MainScreen;
    //the main thing in mkain
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) { // taken from lab 9
            if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) { 
                cout << "Closed the window"; 
                window.close(); 
            } 

            //Check for mouse click
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                if (currentScreen == MainScreen) {
                    // check for which button is clicked
                    if (isButtonClicked(studentButton, mousePos)) {
                        currentScreen = StudentScreen; // Switch to student screen
                    }
                    else if (isButtonClicked2(teacherButton, mousePos)) {
                        currentScreen = TeacherScreen; //switch to teacher screen
                    }
                    else if (isButtonClicked3(adminButton, mousePos)) {
                        currentScreen = AdminScreen; //switch to admin screen
                    }
                }
            }
        }

        //rendering appropriate screen
        if (currentScreen == MainScreen) {
            window.clear(sf::Color::White);
            window.draw(title);
            window.draw(studentButton);
            window.draw(teacherButton);
            window.draw(adminButton);
            window.draw(studentText);
            window.draw(teacherText);
            window.draw(adminText);
            window.draw(loginText);
            window.draw(usernameText);
            window.draw(passwordText);
            window.draw(usernameBox);
            window.draw(passwordBox);
            window.display();
        } 
        else if (currentScreen == StudentScreen) {
            showStudentScreen(window, font);
        }
        else if (currentScreen == TeacherScreen) {
            showTeacherScreen(window, font);
        }
        else if (currentScreen == AdminScreen) {
            showAdminScreen(window, font);
        }
    }

    return 0;
}
