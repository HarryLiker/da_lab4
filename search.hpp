#pragma once
#include <iostream>
#include <vector>

const unsigned short MAX_SIZE = 16;

struct TWord {
    char Word[MAX_SIZE+1];
    unsigned int StringId;
    unsigned int WordId;
};

void WordClear(char word[MAX_SIZE+1]) {
    for (int i = 0; i < MAX_SIZE + 1; ++i) {
        word[i] = 0;
    }
}