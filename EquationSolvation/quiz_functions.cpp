#include "quiz_functions.h"
#include "question.h"
#include <iostream>
#include "raylib.h"

using namespace std;

extern int score;
extern int screenWidth;
extern int screenHeight;
extern Color backgroundColor;
extern Color primaryColor;
extern Color secondaryColor;
extern Color textColor;

string InitWindow() {
    InitWindow(screenWidth, screenHeight, "Digital School - 9th Grade");
    if (GetScreenWidth() != screenWidth || GetScreenHeight() != screenHeight) {
        return "error: window size not set correctly";
    }
    SetTargetFPS(60);
    return "success";
}

string DrawMenu(int selectedOption) {
    const char* options[] = {
        "1. Math",
        "2. Bulgarian Language",
        "3. History",
        "4. Geography",
        "5. Biology",
        "6. Exit"
    };

    if (selectedOption < 0 || selectedOption >= 6) {
        return "error: invalid selected option";
    }

    DrawText("DIGITAL SCHOOL - 9TH GRADE", screenWidth / 2 - MeasureText("DIGITAL SCHOOL - 9TH GRADE", 40) / 2, 50, 40, textColor);
    DrawText("Choose a subject:", screenWidth / 2 - MeasureText("Choose a subject:", 30) / 2, 120, 30, textColor);

    for (int i = 0; i < 6; i++) {
        Color color = (i == selectedOption) ? secondaryColor : primaryColor;
        DrawText(options[i], screenWidth / 2 - MeasureText(options[i], 25) / 2, 180 + i * 50, 25, color);
    }
    return "success";
}

string DrawScore() {
    string scoreText = "Score: " + to_string(score);
    if (scoreText.empty()) {
        return "error: empty score text";
    }
    DrawText(scoreText.c_str(), 20, 20, 25, textColor);
    return "success";
}

string DrawQuestion(const Question& question, int selectedAnswer, bool answered, bool correct) {
    if (question.text.empty() || question.answers.empty()) {
        return "error: invalid question data";
    }

    DrawText(question.text.c_str(), 50, 100, 30, textColor);

    for (size_t i = 0; i < question.answers.size(); i++) {
        Color color = primaryColor;
        if (i == selectedAnswer) color = secondaryColor;
        if (answered && i == question.correctAnswer) color = GREEN;
        if (answered && i == selectedAnswer && !correct) color = RED;

        DrawText(TextFormat("%c. %s", 'A' + i, question.answers[i].c_str()),
            100, 180 + static_cast<int>(i) * 50, 25, color);
    }
    return "success";
}

string DrawResult(bool correct, const string& correctAnswer) {
    if (correctAnswer.empty()) {
        return "error: empty correct answer";
    }

    if (correct) {
        DrawText("Correct! +10 points.", screenWidth / 2 - MeasureText("Correct! +10 points.", 30) / 2, 500, 30, GREEN);
    }
    else {
        string text = "Incorrect. Correct answer: " + correctAnswer;
        DrawText(text.c_str(), screenWidth / 2 - MeasureText(text.c_str(), 30) / 2, 500, 30, RED);
    }
    return "success";
}

QuizResult RunQuiz(const vector<Question>& questions) {
    int currentQuestion = 0;
    int selectedAnswer = 0;
    bool answered = false;
    bool correct = false;
    int correctCount = 0;
    int wrongCount = 0;
    bool testFinished = false;

    while (!WindowShouldClose()) {
        if (!testFinished) {
            if (!answered) {
                if (IsKeyPressed(KEY_DOWN)) {
                    selectedAnswer = (selectedAnswer + 1) % questions[currentQuestion].answers.size();
                }
                if (IsKeyPressed(KEY_UP)) {
                    selectedAnswer = (selectedAnswer - 1 + questions[currentQuestion].answers.size()) % questions[currentQuestion].answers.size();
                }
                if (IsKeyPressed(KEY_ENTER)) {
                    answered = true;
                    correct = (selectedAnswer == questions[currentQuestion].correctAnswer);
                    if (correct) {
                        score += 10;
                        correctCount++;
                    }
                    else {
                        wrongCount++;
                    }
                }
            }
            else {
                if (IsKeyPressed(KEY_ENTER)) {
                    if (currentQuestion < questions.size() - 1) {
                        currentQuestion++;
                        selectedAnswer = 0;
                        answered = false;
                    }
                    else {
                        testFinished = true;
                    }
                }
            }
        }
        else {
            if (IsKeyPressed(KEY_SPACE)) {
                int totalQuestions = correctCount + wrongCount;
                float percentage = (float)correctCount / totalQuestions * 100;

            while (!WindowShouldClose()) {
                    if (IsKeyPressed(KEY_ENTER)) break;

                    BeginDrawing();
                    ClearBackground(backgroundColor);

                    DrawText("Quiz Results", screenWidth / 2 - MeasureText("Quiz Results", 40) / 2, 80, 40, textColor);

             string totalText = "Total questions: " + to_string(totalQuestions);
               DrawText(totalText.c_str(), screenWidth / 2 - MeasureText(totalText.c_str(), 30) / 2, 150, 30, textColor);
                    string correctText = "Correct answers: " + to_string(correctCount);
                 DrawText(correctText.c_str(), screenWidth / 2 - MeasureText(correctText.c_str(), 30) / 2, 200, 30, GREEN);

                 string wrongText = "Wrong answers: " + to_string(wrongCount);
                    DrawText(wrongText.c_str(), screenWidth / 2 - MeasureText(wrongText.c_str(), 30) / 2, 250, 30, RED);

                    string percentageText = "Success rate: " + to_string((int)percentage) + "%";
                    Color percentageColor = percentage >= 70 ? GREEN : (percentage >= 50 ? ORANGE : RED);
                DrawText(percentageText.c_str(), screenWidth / 2 - MeasureText(percentageText.c_str(), 30) / 2, 300, 30, percentageColor);

            string scoreText = "Total score: " + to_string(correctCount * 10) + " points";
                    DrawText(scoreText.c_str(), screenWidth / 2 - MeasureText(scoreText.c_str(), 30) / 2, 350, 30, textColor);

                    string message;
               if (percentage == 100) message = "Perfect! You got all answers right!";
                    else if (percentage >= 80) message = "Excellent work!";
                    else if (percentage >= 60) message = "Good job!";
                    else if (percentage >= 40) message = "Not bad, but you can do better!";
               else message = "Keep practicing!";

                    DrawText(message.c_str(), screenWidth / 2 - MeasureText(message.c_str(), 25) / 2, 420, 25, textColor);

               DrawText("Press ENTER to return to menu", screenWidth / 2 - MeasureText("Press ENTER to return to menu", 25) / 2, 500, 25, textColor);

                    EndDrawing();
                }
                return { correctCount, wrongCount };
            }
        }

        BeginDrawing();
        ClearBackground(backgroundColor);
        string scoreResult = DrawScore();
        if (scoreResult.find("error") != string::npos) {
            cout << scoreResult << endl;
        }

        if (!testFinished) {
            string questionResult = DrawQuestion(questions[currentQuestion], selectedAnswer, answered, correct);
            if (questionResult.find("error") != string::npos) {
                cout << questionResult << endl;
            }
            if (answered) {
                string resultText = DrawResult(correct, questions[currentQuestion].answers[questions[currentQuestion].correctAnswer]);
                if (resultText.find("error") != string::npos) {
                    cout << resultText << endl;
                }
                if (currentQuestion < questions.size() - 1) {
                    DrawText("Press ENTER for next question", screenWidth / 2 - MeasureText("Press ENTER for next question", 25) / 2, 550, 25, textColor);
                }
                else {
                    DrawText("Test finished! Press ENTER to see results", screenWidth / 2 - MeasureText("Test finished! Press ENTER to see results", 25) / 2, 550, 25, textColor);
                }
            }
            else {
                DrawText("Use UP/DOWN arrows to select answer, ENTER to confirm",
                    screenWidth / 2 - MeasureText("Use UP/DOWN arrows to select answer, ENTER to confirm", 20) / 2,
                    550, 20, textColor);
            }
        }
        else {
            DrawText("Test finished! Press SPACE to see results", screenWidth / 2 - MeasureText("Test finished! Press SPACE to see results", 25) / 2, 300, 25, textColor);
        }

        EndDrawing();
    }

    return { correctCount, wrongCount };
}