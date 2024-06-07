#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Mapa słów na cyfry
typedef struct {
    const char* word;
    char digit;
} WordToDigitMap;

WordToDigitMap map[] = {
        {"zero", '0'}, {"one", '1'}, {"two", '2'}, {"three", '3'},
        {"four", '4'}, {"five", '5'}, {"six", '6'}, {"seven", '7'},
        {"eight", '8'}, {"nine", '9'}
};

#define MAP_SIZE (sizeof(map) / sizeof(map[0]))

void replace_word_with_digit(char* line, const char* word, char digit) {
    char buffer[1000];
    char* pos;
    size_t word_len = strlen(word);
    size_t digit_len = 1;
    while ((pos = strstr(line, word)) != NULL) {
        // Skopiuj część przed znalezionym słowem
        strncpy(buffer, line, pos - line);
        buffer[pos - line] = digit;
        // Dodaj resztę po słowie
        strcpy(buffer + (pos - line) + digit_len, pos + word_len);
        // Przenieś wynik z powrotem do linii
        strcpy(line, buffer);
    }
}

void replace_words_with_digits(char* line) {
    for (size_t i = 0; i < MAP_SIZE; i++) {
        replace_word_with_digit(line, map[i].word, map[i].digit);
    }
}

int extract_energy_value(const char* line) {
    char first_digit = '\0';
    char last_digit = '\0';
    for (const char* p = line; *p != '\0'; p++) {
        if (isdigit(*p)) {
            if (first_digit == '\0') {
                first_digit = *p;
            }
            last_digit = *p;
        }
    }
    if (first_digit != '\0' && last_digit != '\0') {
        return (first_digit - '0') * 10 + (last_digit - '0');
    }
    return 0;
}

int main() {
    char lines[][100] = {
            "1abc2",
            "pqr3stu8vwx",
            "a1b2c3d4e5f",
            "portal7magic",
            "two1nine",
            "eightwothree",
            "abcone2threexyz",
            "xtwone3four",
            "4nineeightseven2",
            "zoneight234",
            "7pqrstsixteen"
    };
    int num_lines = sizeof(lines) / sizeof(lines[0]);

    int total_energy = 0;
    for (int i = 0; i < num_lines; i++) {
        replace_words_with_digits(lines[i]);
        total_energy += extract_energy_value(lines[i]);
    }

    printf("Suma wartości energetycznych: %d\n", total_energy);
    return 0;
}
