#include "questions.h"


void shuffleQuestions() {
    srand(time(0));
    for (size_t i = 0; i < questions.size(); i++) {
        int j = rand() % questions.size();
        swap(questions[i], questions[j]);
    }
}