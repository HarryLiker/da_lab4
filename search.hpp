#pragma once
#include <iostream>
#include <vector>

const unsigned short MAX_SIZE = 16;

struct TWord {
    char Word[MAX_SIZE+1];
    unsigned long long StringId;
    unsigned long long WordId;
};

void WordClear(char *word);
void RightWord(unsigned int index, char *word);

std::vector<unsigned long long> ZFunction(const std::vector<TWord> & text);