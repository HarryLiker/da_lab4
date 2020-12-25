#include <iostream>
#include "search.hpp"

int main() {
    std::vector<TWord> text;
    bool pattern_string = 1;
    unsigned int pattern_size = 0;
    TWord current_word;
    char c = getchar(); // For every character in text
    unsigned int i = 0; // Character index in word
    while (c > 0) {
        if (c == '\n') {
            if (i > 0) {
                text.push_back(current_word);
                WordClear(current_word.Word);
                i = 0;
            }
            ++current_word.StringId;
            if (pattern_string) {
                TWord stop_word;
                stop_word.Word[0] = '$';
                text.push_back(stop_word);
                current_word.StringId = 1;
                ++pattern_size;
                pattern_string = 0;
            }
            current_word.WordId = 1;
        } else if (c == ' ' || c == '\t') {
            if (i > 0) {
                RightWord(i, current_word.Word);
                text.push_back(current_word);
                WordClear(current_word.Word);
                i = 0;
                ++current_word.WordId;
                if (pattern_string) {
                    ++pattern_size;
                }
            }
        } else {
            if ('A' <= c && c <= 'Z') {
                c = c - 'A' + 'a';
            }
            current_word.Word[i] = c;
            ++i;
        }
        c = getchar();
    }
    if (i > 0) {
        text.push_back(current_word);
    }

    std::vector<unsigned int> res = ZFunction(text);
    for (unsigned int i = pattern_size + 1; i < res.size(); i++) {
        if (res[i] == pattern_size) {
            std::cout << text[i].StringId << ", " << text[i].WordId << "\n";
        }
    }
}

