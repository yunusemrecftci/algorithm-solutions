#include <stdio.h>
#include <string.h>
#include <ctype.h>

void reverseString(char* str, int start, int end) {
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

char* reverseWords(char* s) {
    int length = strlen(s);
    int start = 0;

    while (isspace(s[start])) start++;

    reverseString(s, start, length - 1);

    start = 0;
    for (int i = 0; i <= length; i++) {
        if (s[i] == ' ' || s[i] == '\0') {
            int word_end = i - 1;
            reverseString(s, start, word_end);
            start = i + 1;
        }
    }

    int j = 0;
    int space_found = 0;
    for (int i = 0; i < length; i++) {
        if (s[i] != ' ' || (i > 0 && s[i-1] != ' ')) {
            s[j++] = s[i];
        }
    }

    s[j] = '\0';

    int start_idx = 0;
    while (s[start_idx] == ' ') {
        start_idx++;
    }

    for (int i = 0; i <= length; i++) {
        s[i] = s[start_idx + i];
        if (s[start_idx + i] == '\0') break;
    }

    return s;
}