#include "quiz.h"
#include "subjects.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    InitWindow();

    int selectedOption = 0;
    bool isRunning = true;

    while (!WindowShouldClose() && isRunning) {
        if (IsKeyPressed(KEY_DOWN)) {
            selectedOption = (selectedOption + 1) % 6;
        }
        if (IsKeyPressed(KEY_UP)) {
            selectedOption = (selectedOption - 1 + 6) % 6;
        }
        if (IsKeyPressed(KEY_ENTER)) {
            switch (selectedOption) {
            case 0: mathematics(); break;
            case 1: bulgarianLanguage(); break;
            case 2: history(); break;
            case 3: geography(); break;
            case 4: biology(); break;
            case 5: isRunning = false; break;
            }
        }

        BeginDrawing();
        ClearBackground(backgroundColor);
        DrawMenu(selectedOption);
        DrawScore();
        EndDrawing();
    }

    CloseWindow();
    cout << "Thank you for using the Digital School! Your final score is: " << score << " points.\n";
    return 0;
}