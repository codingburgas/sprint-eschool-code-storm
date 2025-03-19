#include "drawObjects.h"

void setColor(int textColor) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, textColor);
}

void drawClassroom() {
    setColor(6);
    cout << "\n     CLASSROOM  \n";
    cout << "  \n";
    cout << " |     BLACKBOARD    |\n";
    cout << " |  with Question    |\n";
    cout << " ||\n";

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