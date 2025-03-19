#include "menu.h"


void menu() {
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