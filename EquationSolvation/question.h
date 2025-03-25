#pragma once
#ifndef QUESTION_H
#define QUESTION_H

#include <string>
#include <vector>

using namespace std;

struct Question {
    string text;
    vector<string> answers;
    int correctAnswer;
};

struct QuizResult {
    int correct;
    int wrong;
};

#endif