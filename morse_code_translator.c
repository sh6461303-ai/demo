/*
 * Morse Code Translator - Milestone 2 prototype
 * Language: C (standard C, console-based prototype)
 *
 * Features:
 * 1. English text -> Morse code
 * 2. Morse code -> English text
 * 3. Clear/reset prompt
 * 4. Handles letters, digits, common punctuation, and word spaces
 *
 * Morse formatting:
 * - One space separates letters.
 * - A slash (/) separates words.
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT 1000

static const char *letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.,?!'()/&:;=+-_@";
static const char *morse[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--", "--..",
    "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...",
    "---..", "----.",
    ".-.-.-", "--..--", "..--..", "-.-.--", ".----.", "-..-.", "-.--.",
    "-.--.-", ".-...", "---...", "-.-.-.", "-...-", ".-.-.", "-....-",
    "..--.-", ".--.-."
};

#define MAP_COUNT (sizeof(morse) / sizeof(morse[0]))

static int find_char_index(char ch) {
    size_t i;
    ch = (char)toupper((unsigned char)ch);
    for (i = 0; i < strlen(letters); i++) {
        if (letters[i] == ch) return (int)i;
    }
    return -1;
}

static int find_morse_index(const char *code) {
    size_t i;
    for (i = 0; i < MAP_COUNT; i++) {
        if (strcmp(morse[i], code) == 0) return (int)i;
    }
    return -1;
}

static void text_to_morse(const char *input) {
    size_t i;
    int printed_any = 0;
    int after_space = 0;

    printf("\\nMorse output:\\n");
    for (i = 0; input[i] != '\\0'; i++) {
        unsigned char raw = (unsigned char)input[i];
        char ch = (char)toupper(raw);

        if (ch == '\\n' || ch == '\\r') continue;

        if (ch == ' ') {
            if (printed_any && !after_space) {
                printf(" /");
                after_space = 1;
            }
            continue;
        }

        {
            int index = find_char_index(ch);
            if (index >= 0) {
                if (printed_any && !after_space) printf(" ");
                else if (after_space) printf(" ");
                printf("%s", morse[index]);
                printed_any = 1;
                after_space = 0;
            } else {
                printf("\\nWarning: unsupported character '%c' was skipped.\\n", ch);
            }
        }
    }

    if (!printed_any) printf("(No translatable characters)");
    printf("\\n\\n");
}

static void morse_to_text(char *input) {
    char *token;
    int printed_any = 0;
    int invalid_found = 0;

    printf("\\nEnglish output:\\n");

    /* Token convention: spaces separate letters; / separates words. */
    token = strtok(input, " \\t\\r\\n");
    while (token != NULL) {
        if (strcmp(token, "/") == 0) {
            if (printed_any) printf(" ");
        } else {
            int index = find_morse_index(token);
            if (index >= 0) {
                printf("%c", letters[index]);
                printed_any = 1;
            } else {
                printf("?");
                printed_any = 1;
                invalid_found = 1;
            }
        }
        token = strtok(NULL, " \\t\\r\\n");
    }

    if (!printed_any) printf("(No translatable codes)");
    if (invalid_found) {
        printf("\\nNote: '?' means an unknown or invalid Morse code.");
    }
    printf("\\n\\n");
}

int main(void) {
    char input[MAX_INPUT];
    char choice_text[20];
    int choice;

    printf("=====================================\\n");
    printf("       MORSE CODE TRANSLATOR\\n");
    printf("=====================================\\n");

    while (1) {
        printf("Choose an option:\\n");
        printf("1. English Text -> Morse Code\\n");
        printf("2. Morse Code -> English Text\\n");
        printf("3. Clear / Reset\\n");
        printf("4. Exit\\n");
        printf("Enter choice: ");

        if (fgets(choice_text, sizeof(choice_text), stdin) == NULL) {
            printf("\\nInput ended. Goodbye!\\n");
            break;
        }

        if (sscanf(choice_text, "%d", &choice) != 1) {
            printf("Please enter a number from 1 to 4.\\n\\n");
            continue;
        }

        if (choice == 1) {
            printf("Enter English text: ");
            if (fgets(input, sizeof(input), stdin) == NULL) break;
            text_to_morse(input);
        } else if (choice == 2) {
            printf("Enter Morse code (spaces between letters, / between words):\\n");
            if (fgets(input, sizeof(input), stdin) == NULL) break;
            morse_to_text(input);
        } else if (choice == 3) {
            input[0] = '\\0';
            printf("\\nInput/output reset. You can start again.\\n\\n");
        } else if (choice == 4) {
            printf("Thank you for using Morse Code Translator!\\n");
            break;
        } else {
            printf("Invalid choice. Please enter 1, 2, 3, or 4.\\n\\n");
        }
    }

    return 0;
}
