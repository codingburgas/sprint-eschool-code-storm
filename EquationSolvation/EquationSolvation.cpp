#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <conio.h>
#include <windows.h>
#include <ctime>
using namespace std;

struct Question {
    string question;
    vector<string> answers;
    int correctIndex;
};

vector<Question> questions = {
    {"23 x 2", {"46", "44", "42", "48"}, 0},
    {"15 + 7", {"20", "22", "24", "21"}, 2},
    {"30 / 5", {"6", "5", "7", "4"}, 0},
    {"45 - 18", {"27", "26", "28", "29"}, 0},
    {"9 x 9", {"81", "72", "91", "99"}, 0},
    {"12 + 25", {"37", "35", "40", "38"}, 0},
    {"100 - 47", {"53", "50", "55", "57"}, 0},
    {"6 x 7", {"42", "36", "48", "49"}, 0}
};

int score = 0;
void setColor(int textColor) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, textColor);
}

void drawClassroom() {
    setColor(6);
    cout << "\n     CLASSROOM  \n";
    cout << "  ___________________\n";
    cout << " |     BLACKBOARD    |\n";
    cout << " |  with Question    |\n";
    cout << " |___________________|\n";

    setColor(7);
}

void drawHuman(string text, bool isQuestion) {
    if (isQuestion) {
        cout << "    O" << endl;
        cout << "   /|\\" << endl;
        cout << "   / \\" << endl;
        cout << "  [ " << text << " ]" << endl;
    }
    else {
        cout << "    O   [ " << text << " ]" << endl;
        cout << "   /|\\" << endl;
        cout << "   / \\" << endl;
    }
}

void shuffleQuestions() {
    srand(time(0));
    for (size_t i = 0; i < questions.size(); i++) {
        int j = rand() % questions.size();
        swap(questions[i], questions[j]);
    }
}

void displayScoreboard() {
    system("cls");
    setColor(11);
    cout << "SCOREBOARD\n";
    cout << "Your score: " << score << " / " << questions.size() << "\n";
    if (score == questions.size()) {
        cout << "Excellent! You answered all questions correctly! \n";
    }
    else if (score > questions.size() / 2) {
        cout << "Good job! You got more than half correct. \n";
    }
    else {
        cout << "Better luck next time! \n";
    }
    setColor(7);
    system("pause");
}

void playGame() {
    shuffleQuestions();
    for (const auto& q : questions) {
        system("cls");
        drawClassroom();
        setColor(14);
        drawHuman(q.question, true);
        setColor(7);
        for (size_t i = 0; i < q.answers.size(); ++i) {
            drawHuman(to_string(i + 1) + ". " + q.answers[i], false);
        }

        int choice;
        cout << "\n Choose an answer (1-4): ";
        string input;
        getline(cin, input);
        size_t pos = input.find_first_not_of("1234");
        if (pos != string::npos || input.empty()) {
            setColor(4);
            cout << "\nINVALID ANSWER! Please choose a valid option.\n";
            system("pause");
            continue;
        }

        choice = stoi(input);

        if (choice - 1 == q.correctIndex) {
            setColor(2);
            cout << "\nCORRECT ANSWER!\n";
            score++;
        }
        else {
            setColor(4);
            cout << "\nWRONG ANSWER!\n";
        }
        setColor(7);
        system("pause");
    }
    displayScoreboard();
}

void menu() {
    int option = 0;
    char key;

    while (true) {
        system("cls");
        setColor(9);
        cout << "\n===== QUIZ GAME MENU =====\n";
        setColor(14);
        cout << "1. NEW GAME\n";
        cout << "2. SCOREBOARD\n";
        cout << "3. ABOUT GAME\n";
        cout << "4. EXIT\n";
        setColor(7);

        key = _getch();
        if (key == '1') {
            score = 0;
            playGame();
        }
        else if (key == '2') {
            displayScoreboard();
        }
        else if (key == '3') {
            system("cls");
            cout << "This is a fun quiz game where you answer math questions!\n";
            cout << "Try to get as many correct as possible!\n";
            system("pause");
        }
        else if (key == '4') {
            exit(0);
        }
    }
}

int main() {
    menu();
}
