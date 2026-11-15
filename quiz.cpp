#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdexcept>
using namespace std;

// A class describing one quiz question
class Question {
public:
    string text;
    vector<string> options;
    int correct;   // number of the correct option (1 to 4)

    // Constructor: runs when a Question object is created
    Question(string t, vector<string> o, int c) {
        text = t;
        options = o;
        correct = c;
    }

    // Returns true if the user's choice is the right answer
    bool isCorrect(int choice) const {
        return choice == correct;
    }
};

// Function 1: create and return the list of questions
vector<Question> loadQuestions() {
    vector<Question> questions;
    questions.push_back({"What is the capital of France?",
                         {"Berlin", "Paris", "Madrid", "Rome"}, 2});
    questions.push_back({"Which planet is known as the Red Planet?",
                         {"Venus", "Jupiter", "Mars", "Saturn"}, 3});
    questions.push_back({"How many days are there in a week?",
                         {"5", "6", "7", "8"}, 3});
    questions.push_back({"Which language is this project written in?",
                         {"Python", "C++", "Java", "Ruby"}, 2});
    questions.push_back({"What is 9 x 3?",
                         {"27", "21", "24", "36"}, 1});
    return questions;
}

// Function 2: show one question with its options
void showQuestion(const Question& q, int number) {
    cout << endl;
    cout << "Question " << number << ": " << q.text << endl;
    for (int i = 0; i < q.options.size(); i++) {
        cout << i + 1 << ". " << q.options[i] << endl;
    }
}

// Function 3: keep asking until the user enters a valid number from 1 to 4
int getChoice() {
    int choice = 0;
    while (true) {
        cout << "Your answer (1-4): ";
        cin >> choice;
        if (cin.fail() || choice < 1 || choice > 4) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter a number from 1 to 4." << endl;
        } else {
            break;
        }
    }
    return choice;
}

// Function 4: save the name and score to a file
// Throws an error if the file cannot be opened
void saveScore(const string& name, int score, int total, double percentage) {
    ofstream file("scores.txt", ios::app);
    if (!file.is_open()) {
        throw runtime_error("could not open scores.txt");
    }
    file << name << " - " << score << "/" << total
         << " (" << percentage << "%)" << endl;
    file.close();
}

int main() {
    string name;

    cout << "Welcome to the Quiz App!" << endl;
    cout << "Enter your name: ";
    getline(cin, name);

    cout << "Hello, " << name << "! Let's begin." << endl;

    vector<Question> questions = loadQuestions();
    int score = 0;

    for (int q = 0; q < questions.size(); q++) {
        showQuestion(questions[q], q + 1);
        int choice = getChoice();

        // The score is updated in only one place
        if (questions[q].isCorrect(choice)) {
            cout << "Correct!" << endl;
            score++;
        } else {
            cout << "Wrong! The correct answer was option "
                 << questions[q].correct << "." << endl;
        }
    }

    int total = questions.size();
    double percentage = (score * 100.0) / total;

    cout << endl;
    cout << "===== RESULT =====" << endl;
    cout << "Name: " << name << endl;
    cout << "Score: " << score << " / " << total << endl;
    cout << "Percentage: " << percentage << "%" << endl;

    // Exception handling: try to save, catch any error
    try {
        saveScore(name, score, total, percentage);
        cout << "Your score has been saved to scores.txt" << endl;
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}