#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isKeyword(char *word) {
    char keywords[][10] = {"int", "float", "if", "else", "while", "for", "return", "char"};
    for (int i = 0; i < 8; i++) {
        if (strcmp(word, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int main() {
    FILE *fp;
    char ch, word[50];
    int i = 0;

    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Cannot open file.\n");
        return 1;
    }

    printf("Lexical Analysis Output:\n\n");

    while ((ch = fgetc(fp)) != EOF) {
        if (isalnum(ch)) {
            word[i++] = ch;
        } else {
            word[i] = '\0';
            i = 0;

            if (strlen(word) > 0) {
                if (isKeyword(word))
                    printf("Keyword: %s\n", word);
                else if (isalpha(word[0]))
                    printf("Identifier: %s\n", word);
                else
                    printf("Constant/Number: %s\n", word);
            }

            if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=')
                printf("Operator: %c\n", ch);
        }
    }

    fclose(fp);
    return 0;
}
