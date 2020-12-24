#include "search.hpp"

#include <algorithm>
#include <iostream>

void WordClear(char word[MAX_SIZE+1]) {
    for (int i = 0; i < MAX_SIZE + 1; ++i) {
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

std::vector<unsigned int> ZFunction(const std::vector<TWord> &string) {
    unsigned int size = string.size();
    unsigned int left = 0;
    unsigned int right = 0;
    std::vector<unsigned int> z_function(size);
    for (unsigned int i = 1; i < size; i++) {
        if (left <= right) {
            z_function[i] = std::min(z_function[i-left], right - left);
        }
        while (z_function[i] + i < size && string[z_function[i] + i] == string[z_function[i]]) {
            ++z_function[i];
        }
        if (z_function[i] > right) {
            left = i;
            right = z_function[i] + i;
        }
    }
    return z_function;
}

std::vector<unsigned int> ZFunctionForPrefix