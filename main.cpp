#include <iostream>
#include "search.hpp"

int main() {
    std::vector<TWord> text;
    std::vector<TWord> pattern;
    bool pattern_string = 1;
    TWord current_word;
    char c = getchar();
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
                std::swap(pattern, text);
                pattern_string = 0;
                current_word.StringId = 1;
            }
            current_word.WordId = 1;
        } else if (c == ' ' || c == '\t') {
            if (i > 0) {
                text.push_back(current_word);
                WordClear(current_word.Word);
                i = 0;
                ++current_word.WordId;
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
}