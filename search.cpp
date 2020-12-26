#include "search.hpp"

#include <algorithm>
#include <iostream>

void WordClear(char word[MAX_SIZE]) {
    for (int i = 0; i < MAX_SIZE; ++i) {
        word[i] = 0;
    }
}

void RightWord(unsigned int index, char *word) {
    for (int i = index; i < MAX_SIZE + 1; i++) {
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

std::vector<unsigned long long> ZFunction(const std::vector<TWord> &text) {
    unsigned long long size = text.size();
    unsigned long long left = 0;
    unsigned long long right = 0;
    std::vector<unsigned long long> z_function(size);
    for (unsigned long long i = 1; i < size; ++i) {
        if (i <= right) {
            z_function[i] = std::min(z_function[i-left], right - i + 1);
        }
        while ((z_function[i] + i < size) && (text[z_function[i]] == text[z_function[i] + i])) {
            ++z_function[i];
        }
        if (i + z_function[i] - 1 > right) {
            left = i;
            right = z_function[i] + i - 1;
        }
    }
    return z_function;
}
