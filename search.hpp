#pragma once
#include <iostream>
#include <vector>

const unsigned short MAX_SIZE = 16;

struct TWord {
    char Word[MAX_SIZE+1];
    unsigned int StringId;
    unsigned int WordId;
};

void WordClear(char *word);

std::vector<unsigned int> ZFunction(const std::vector<TWord> & vector);