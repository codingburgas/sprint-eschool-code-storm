#include "quiz.h"
#include "raylib.h"
#include <string>


int score = 0;
int screenWidth = 1024;
int screenHeight = 768;
Color backgroundColor = { 29, 43, 83, 255 };
Color primaryColor = { 129, 178, 154, 255 };
Color secondaryColor = { 224, 122, 95, 255 };
Color textColor = { 243, 238, 234, 255 };

void InitWindow() {
    InitWindow(screenWidth, screenHeight, "Digital School - 9th Grade");
    SetTargetFPS(60);
}

void DrawMenu(int selectedOption) {
    const char* options[] = {
        "1. Math",
        "2. Bulgarian Language",
        "3. History",
        "4. Geography",
        "5. Biology",
        "6. Exit"
    };

    DrawText("DIGITAL SCHOOL - 9TH GRADE", screenWidth / 2 - MeasureText("DIGITAL SCHOOL - 9TH GRADE", 40) / 2, 50, 40, textColor);
    DrawText("Choose a subject:", screenWidth / 2 - MeasureText("Choose a subject:", 30) / 2, 120, 30, textColor);

    for (int i = 0; i < 6; i++) {
        Color color = (i == selectedOption) ? secondaryColor : primaryColor;
        DrawText(options[i], screenWidth / 2 - MeasureText(options[i], 25) / 2, 180 + i * 50, 25, color);
    }
}

void DrawScore() {
    std::string scoreText = "Score: " + std::to_string(score);
    DrawText(scoreText.c_str(), 20, 20, 25, textColor);
}

void DrawQuestion(const Question& question, int selectedAnswer, bool answered, bool correct) {
    DrawText(question.text.c_str(), 50, 100, 30, textColor);

    for (size_t i = 0; i < question.answers.size(); i++) {
        Color color = primaryColor;
        if (i == selectedAnswer) color = secondaryColor;
        if (answered && i == question.correctAnswer) color = GREEN;
        if (answered && i == selectedAnswer && !correct) color = RED;

        DrawText(TextFormat("%c. %s", 'A' + i, question.answers[i].c_str()),
            100, 180 + static_cast<int>(i) * 50, 25, color);
    }
}

void DrawResult(bool correct, const std::string& correctAnswer) {
    if (correct) {
        DrawText("Correct! +10 points.", screenWidth / 2 - MeasureText("Correct! +10 points.", 30) / 2, 500, 30, GREEN);
    }
    else {
        std::string text = "Incorrect. Correct answer: " + correctAnswer;
        DrawText(text.c_str(), screenWidth / 2 - MeasureText(text.c_str(), 30) / 2, 500, 30, RED);
    }
}

QuizResult RunQuiz(const std::vector<Question>& questions) {
   
}

void ShowQuizResults(int correct, int wrong) {
    
    
    
}