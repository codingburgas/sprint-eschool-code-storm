#pragma once
#include "pch.h"

struct Question {
    string question;
    vector<string> answers;
    int correctIndex;
};

vector<Question> questions = {
    {"23 x 2", {"46", "44", "42", "48"}, 0},
    {"15 + 7", {"20", "22", "24", "21"}, 2},
    {"30 / 5", {"6", "5", "7", "4"}, 0},
    {"45 - 18", {"27", "26", "28", "29"}, 0},
    {"9 x 9", {"81", "72", "91", "99"}, 0},
    {"12 + 25", {"37", "35", "40", "38"}, 0},
    {"100 - 47", {"53", "50", "55", "57"}, 0},
    {"6 x 7", {"42", "36", "48", "49"}, 0}
};

void shuffleQuestions();
