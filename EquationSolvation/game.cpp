#include "game.h"


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