#include "subjects.h"
#include "quiz_functions.h"
#include "question.h"
#include <vector>
#include <string>

using namespace std;

extern int score;

string mathematics() {
    vector<Question> questions = {
        {
            "What is the square root of 169?",
            {"12", "13", "14", "15"},
            1
        },
        {
            "Solve the equation: 2x + 5 = 17",
            {"x = 5", "x = 6", "x = 7", "x = 8"},
            1
        },
        {
            "What is the value of ? (pi) to two decimal places?",
            {"3.12", "3.14", "3.16", "3.18"},
            1
        },
        {
            "Which of these shapes has the largest perimeter with equal side lengths?\n(side = 5 cm)",
            {"Square", "Rectangle (4x6)", "Equilateral triangle", "Rhombus"},
            1
        },
        {
            "What is 5! (5 factorial)?",
            {"60", "100", "120", "150"},
            2
        },
        {
            "What is the probability of rolling an even number with a die?",
            {"1/6", "1/3", "1/2", "2/3"},
            2
        },
        {
            "Which of these numbers is prime?",
            {"9", "15", "21", "23"},
            3
        },
        {
            "What is the formula for the area of a rectangle?",
            {"a*b", "a+b", "2(a+b)", "a?"},
            0
        },
        {
            "Which equation describes a straight line?",
            {"y = x?", "y = 1/x", "y = 2x + 3", "y = ?x"},
            2
        },
        {
            "What is the name of a polygon with 8 sides?",
            {"Hexagon", "Heptagon", "Octagon", "Nonagon"},
            2
        }
    };
    QuizResult result = RunQuiz(questions);
    return "Mathematics quiz completed with " + to_string(result.correct) + " correct and " + to_string(result.wrong) + " wrong answers";
}

string bulgarianLanguage() {
    vector<Question> questions = {
        {
            "Which of these words is a noun?",
            {"quick", "beautiful", "school", "reads"},
            2
        },
        {
            "Which sentence is correctly punctuated?",
            {"He said: I will come tomorrow.", "He said - I will come tomorrow.", "He said, I will come tomorrow.", "He said, I will come tomorrow."},
            0
        },
        {
            "Which word is spelled incorrectly?",
            {"man", "chocolate", "yellow", "monstrous"},
            3
        },
        {
            "What is a synonym for 'magnificent'?",
            {"small", "beautiful", "ordinary", "old"},
            1
        },
        {
            "Which of these is a literary genre?",
            {"Sonnet", "Meter", "Rhyme", "Verse"},
            0
        },
        {
            "Which of these authors is a Bulgarian writer?",
            {"Ivan Vazov", "Leo Tolstoy", "Charles Dickens", "Victor Hugo"},
            0
        },
        {
            "Which word is an antonym of 'bright'?",
            {"clear", "dark", "clean", "warm"},
            1
        },
        {
            "Which sentence contains a gerund?",
            {"He reads a book.", "He sat down to read.", "Reading a book, he lost track of time.", "The book was read."},
            2
        },
        {
            "Which word is an adverb?",
            {"quickly", "quick", "quickness", "hurry"},
            0
        },
        {
            "Which part of the compound sentence is: 'I went to the cinema, but the movie was boring.'?",
            {"Subordinate sentence", "Coordinated sentence", "Exclamatory sentence", "Simple sentence"},
            1
        }
    };
    QuizResult result = RunQuiz(questions);
    return "Bulgarian Language quiz completed with " + to_string(result.correct) + " correct and " + to_string(result.wrong) + " wrong answers";
}

string history() {
    vector<Question> questions = {
        {
            "When is the Liberation of Bulgaria from Ottoman rule?",
            {"1876", "1878", "1885", "1908"},
            1
        },
        {
            "Who is known as the 'Tsar-liberator'?",
            {"Alexander II", "Alexander I", "Nicholas I", "Nicholas II"},
            0
        },
        {
            "Which battle was decisive for the Liberation of Bulgaria?",
            {"Battle of Shipka", "Battle of Pleven", "Battle of Stara Zagora", "Battle of Shipka Pass"},
            1
        },
        {
            "Who was the first prince of Bulgaria after Liberation?",
            {"Ferdinand", "Boris I", "Alexander Battenberg", "Simeon I"},
            2
        },
        {
            "When was the Union of the Principality of Bulgaria and Eastern Rumelia?",
            {"1878", "1885", "1908", "1912"},
            1
        },
        {
            "Which Bulgarian ruler is known for the Golden Age of Bulgarian culture?",
            {"Khan Asparukh", "Tsar Simeon", "Tsar Samuil", "Tsar Boris I"},
            1
        },
        {
            "What was the capital of the First Bulgarian State?",
            {"Sofia", "Pliska", "Preslav", "Turnovo"},
            1
        },
        {
            "Who signed the Treaty of San Stefano on behalf of Russia?",
            {"Alexander II", "Nicholas I", "Mikhail Skobelev", "Nicholas Ignatyev"},
            3
        },
        {
            "When was Bulgaria's independence declared?",
            {"1878", "1885", "1908", "1912"},
            2
        },
        {
            "Who was the last Bulgarian tsar?",
            {"Ferdinand", "Boris III", "Simeon II", "Peter I"},
            2
        }
    };
    QuizResult result = RunQuiz(questions);
    return "History quiz completed with " + to_string(result.correct) + " correct and " + to_string(result.wrong) + " wrong answers";
}

string geography() {
    vector<Question> questions = {
        {
            "What is the highest mountain in Bulgaria?",
            {"Stara Planina", "Rila", "Pirine", "Rodopi"},
            1
        },
        {
            "What is the longest river in Bulgaria?",
            {"Danube", "Maritsa", "Iskar", "Struma"},
            2
        },
        {
            "What is the largest city in Bulgaria after Sofia?",
            {"Plovdiv", "Varna", "Burgas", "Ruse"},
            0
        },
        {
            "Which countries border Bulgaria to the north?",
            {"Serbia and Romania", "Romania and Serbia", "Romania and Ukraine", "Romania and North Macedonia"},
            1
        },
        {
            "What is the largest peninsula in Europe?",
            {"Iberian", "Apennine", "Balkan", "Scandinavian"},
            3
        },
        {
            "What is the largest desert in the world?",
            {"Sahara", "Gobi", "Arabian", "Kalahari"},
            0
        },
        {
            "What is the longest river in the world?",
            {"Amazon", "Nile", "Yangtze", "Mississippi"},
            0
        },
        {
            "What is the highest peak in the world?",
            {"Kilimanjaro", "Everest", "Aconcagua", "Mont Blanc"},
            1
        },
        {
            "Which ocean is the largest?",
            {"Atlantic", "Pacific", "Indian", "Arctic"},
            1
        },
        {
            "What is the capital of Japan?",
            {"Beijing", "Seoul", "Tokyo", "Bangkok"},
            2
        }
    };
    QuizResult result = RunQuiz(questions);
    return "Geography quiz completed with " + to_string(result.correct) + " correct and " + to_string(result.wrong) + " wrong answers";
}

string biology() {
    vector<Question> questions = {
        {
            "What is the basic structural unit of living organisms?",
            {"Tissue", "Organ", "Cell", "System"},
            2
        },
        {
            "Which organelle is the energy powerhouse of the cell?",
            {"Nucleus", "Mitochondrion", "Ribosome", "Endoplasmic reticulum"},
            1
        },
        {
            "What is the process of cell division called?",
            {"Photosynthesis", "Mitosis", "Osmosis", "Diffusion"},
            1
        },
        {
            "Which organisms are producers in the food chain?",
            {"Animals", "Fungi", "Plants", "Bacteria"},
            2
        },
        {
            "What is the science of classifying organisms called?",
            {"Ecology", "Genetics", "Taxonomy", "Cytology"},
            2
        },
        {
            "What is the main function of chloroplasts?",
            {"Cellular respiration", "Photosynthesis", "Protein synthesis", "Transport of substances"},
            1
        },
        {
            "What is DNA in the nucleus called?",
            {"Chromosome", "Ribosome", "Mitochondrion", "Lysosome"},
            0
        },
        {
            "What are the main elements in organic compounds?",
            {"Carbon, hydrogen, oxygen", "Calcium, iron, sodium", "Nitrogen, phosphorus, potassium", "Sulfur, magnesium, chlorine"},
            0
        },
        {
            "What is the process of passing on hereditary traits called?",
            {"Evolution", "Adaptation", "Hybridization", "Genetics"},
            3
        },
        {
            "Which of these is not a type of RNA?",
            {"mRNA", "tRNA", "rRNA", "dRNA"},
            3
        }
    };
    QuizResult result = RunQuiz(questions);
    return "Biology quiz completed with " + to_string(result.correct) + " correct and " + to_string(result.wrong) + " wrong answers";
}