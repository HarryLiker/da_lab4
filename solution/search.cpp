#include "search.hpp"

#include <algorithm>
#include <iostream>

void WordClear(char word[MAX_SIZE]) {
    for (int i = 0; i < MAX_SIZE; ++i) {
        word[i] = 0;
    }
}

void RightWord(unsigned int index, char *word) {
    for (unsigned int i = index; i < MAX_SIZE + 1; i++) {
        word[i] = 0;
    }
}

bool operator == (const TWord &left_value, const TWord &right_value) {
    for (int i = 0; i < MAX_SIZE + 1; ++i) {
        if (left_value.Word[i] != right_value.Word[i]) {
            return false;
        }
    }
    return true;
}

bool operator != (const TWord &left_value, const TWord &right_value) {
    return !(left_value == right_value);
}

std::vector<unsigned int> ZFunction(const std::vector<TWord> &text) {
    unsigned int size = text.size();
    unsigned int left = 0;
    unsigned int right = 0;
    std::vector<unsigned int> z_function(size);
    for (unsigned int i = 1; i < size; ++i) {
        if (i <= right) {
            z_function[i] = std::min(z_function[i-left], right - i);
        }
        while ((z_function[i] + i < size) && (text[z_function[i]] == text[z_function[i] + i])) {
            ++z_function[i];
        }
        if (i + z_function[i] > right) {
            left = i;
            right = z_function[i] + i;
        }
    }
    return z_function;
}
