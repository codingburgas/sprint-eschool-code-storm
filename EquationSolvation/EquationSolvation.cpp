#include <iostream>
#include <cstdlib>
#include <string>
#include <conio.h>
#include <windows.h>
using namespace std;

void setColor(int textColor) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, textColor);
}

void menu() {
    setlocale(LC_ALL, "");
    int currentOption = 0;
    char key;

    while (true) {
        system("cls");

        setColor(14);
        cout << " +=================================================================================================+\n";
        cout << "   |||      |||   |||||||   |||||||  ||||   |||      |||      |||  ||||||||  ||||   |||  |||   |||  \n";
        cout << "   ||||   /||||  |||   |||    |||    |||||  |||      |||||  /||||  |||       |||||  |||  |||   |||  \n";
        cout << "   ||| |||/ |||  |||||||||    |||    ||| || |||      ||| |||/ |||  ||||||    ||| || |||  |||   |||  \n";
        cout << "   |||      |||  |||   |||    |||    |||  |||||      |||      |||  |||       |||  |||||  |||   |||  \n";
        cout << "   |||      |||  |||   |||  |||||||  |||   ||||      |||      |||  ||||||||  |||    |||  |||||||||  \n";
        cout << " +=================================================================================================+\n";

        setColor(2);
        cout << (currentOption == 0 ? "-> " : "   ") << " 1. NEW GAME\n";
        setColor(4);
        cout << (currentOption == 1 ? "-> " : "   ") << " 2. EXIT\n";

        setColor(15);
        cout << "  #~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#\n";
        cout << "    Use UP and DOWN arrow keys to navigate, ENTER to select.\n";
        cout << "  #~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#\n";



        setColor(7);
        key = _getch();

        if (key == 72) { // UP arrow key
            currentOption = (currentOption - 1 + 2) % 2; // Move up, wrap around
        }
        else if (key == 80) { // DOWN arrow key
            currentOption = (currentOption + 1) % 2; // Move down, wrap around
        }
        else if (key == '\r') { // ENTER key
            switch (currentOption) {
            case 0:
                system("cls");
                cout << "Starting the game...\n";
                return;
            case 1:
                system("cls");
                cout << "Exiting program. Goodbye!\n";
                exit(0);      // exits the game...Lives in library "cstdlib"
            }
        }
    }
}

int main()
{
    menu();
}