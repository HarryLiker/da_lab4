import random
import string
from random import choice

def main():
    pattern_size = random.randint(3, 20)
    pattern = ""
    text = ""
    words_in_pattern = ["dog", "cat", "bird"]
    words_in_text = ["dog", "cat", "bird", "umbrella", "kiss", "jump", "get", "hello", "python"]
    pattern_list = []
    text_list = []
    for i in range(pattern_size):
        if (i != 0):
            pattern = pattern + ' '
        pattern = pattern + choice(words_in_pattern)
    count = 0
    while (count < 100):
        rand = random.randint(1, 100)
        if (count != 0):
            text_list.append(text)
            text = text + ' '
        if (rand > 95):
            for k in range(pattern_size):
                text_list.append()
            text = text + pattern
            cout  = count + pattern_size
        else:
            text = text + choice(words_in_text)
            count += 1
    print(text)
    print(pattern)
    test_file = open('test.txt', 'w')
    test_file.write(pattern)
    test_file.write('\n')
    test_file.write(text)
    test_file.close()

    #result_file = open('result.txt', 'w')
    #for i in range count:
    #    for j in range (i, i + len(pattern_size)):
    #        if (text[i]):


main()

    