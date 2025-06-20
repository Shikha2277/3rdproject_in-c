#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// List of all C keywords
char keywords[32][10] = {
    "auto", "break", "case", "char", "const", "continue", "default",
    "do", "double", "else", "enum", "extern", "float", "for", "goto", 
    "if", "int", "long", "register", "return", "short", "signed",
    "sizeof", "static", "struct", "switch", "typedef", "union",
    "unsigned", "void", "volatile", "while"
};

// Check if a string is a keyword
int isKeyword(char buffer[]) {
    for (int i = 0; i < 32; ++i) {
        if (strcmp(keywords[i], buffer) == 0)
            return 1;
    }
    return 0;
}

int main() {
    char ch, buffer[20], operators[] = "+-*/%=<>!&|";
    FILE *fp;
    int i, j = 0;

    // Open the input file
    fp = fopen("input.c", "r");
    if (fp == NULL) {
        printf(" Unable to open the file.\n");
        return 1;
    }

    printf(" Lexical Analysis  \n");

    while ((ch = fgetc(fp)) != EOF) {
        // Check for operators
        for (i = 0; i < strlen(operators); ++i) {
            if (ch == operators[i]) {
                printf("%c is an Operator\n", ch);
            }
        }

        // Build words (keywords or identifiers)
        if (isalnum(ch)) {
            buffer[j++] = ch;
        } else if ((ch == ' ' || ch == '\n' || ch == '\t' || ch == ';' || ch == '(' || ch == ')') && j > 0) {
            buffer[j] = '\0';
            j = 0;

            if (isKeyword(buffer)) {
                printf("%s is a Keyword\n", buffer);
            } else {
                printf("%s is an Identifier\n", buffer);
            }
        }
    }

    fclose(fp);
    return 0;
}