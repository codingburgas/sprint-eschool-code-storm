#include "quiz_functions.h"
#include "subjects.h"
#include "question.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "raylib.h"

using namespace std;

int score = 0;
int screenWidth = 1024;
int screenHeight = 768;
Color backgroundColor = { 29, 43, 83, 255 };
Color primaryColor = { 129, 178, 154, 255 };
Color secondaryColor = { 224, 122, 95, 255 };
Color textColor = { 243, 238, 234, 255 };

int main() {
    srand(time(0));
    string initResult = InitWindow();
    if (initResult.find("error") != string::npos) {
        cout << "Window initialization failed: " << initResult << endl;
        return 1;
    }

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
            string result;
            switch (selectedOption) {
            case 0: result = mathematics(); break;
            case 1: result = bulgarianLanguage(); break;
            case 2: result = history(); break;
            case 3: result = geography(); break;
            case 4: result = biology(); break;
            case 5: isRunning = false; break;
            }
            if (result.find("error") != string::npos) {
                cout << "Error in subject: " << result << endl;
            }
        }

        BeginDrawing();
        ClearBackground(backgroundColor);
        string menuResult = DrawMenu(selectedOption);
        string scoreResult = DrawScore();
        EndDrawing();

        if (menuResult.find("error") != string::npos || scoreResult.find("error") != string::npos) {
            cout << "Drawing error: " << menuResult << " " << scoreResult << endl;
        }
    }

    CloseWindow();
    cout << "Thank you for using the Digital School! Your final score is: " << score << " points.\n";
    return 0;
}
