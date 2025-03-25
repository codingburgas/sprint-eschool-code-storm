#pragma once
#ifndef QUIZ_FUNCTIONS_H
#define QUIZ_FUNCTIONS_H

#include "question.h"
#include <string>

using namespace std;

string InitWindow();
string DrawMenu(int selectedOption);
string DrawQuestion(const Question& question, int selectedAnswer, bool answered, bool correct);
string DrawScore();
string DrawResult(bool correct, const string& correctAnswer);
QuizResult RunQuiz(const vector<Question>& questions);
string ShowQuizResults(int correct, int wrong);

#endif