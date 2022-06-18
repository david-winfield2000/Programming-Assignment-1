// David Winfield

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char const *argv[]) {
    // function takes in 2 arguments
    // argument 1 = encryption key file
    // argument 2 = file to be encrypted

    // open both files in read mode
    FILE *text;
    FILE *key;
    
    text = fopen(argv[2], "r");
    key = fopen(argv[1], "r");
    
    char a, b;
    a = tolower(fgetc(text));
    b = tolower(fgetc(key));

    int linecounter = 0;
    int totalcounter = 0;
    
    while (a != EOF) {
        // a character management
        while (isalpha(a) == 0) {
            a = tolower(fgetc(text));
            if (a == EOF)
                break;
        }
        if (a == EOF) {
            // printf("EOF\n\n");
            break;
        }
           

        while (isalpha(b) == 0) {
            b = tolower(fgetc(key));

            if (b == '\n') {
                // printf("eol\n");
                b = fgetc(key);
            }
            // reset key file as needed
            if (b == EOF) {
                // printf("eof\n");
                rewind(key);
                b = fgetc(key);
            }
        }

        // b character management
        // ignore new line characters
        if (b == '\n') {
            // printf("eol\n");
            b = fgetc(key);
        }
        // reset key file as needed
        if (b == EOF) {
            // printf("eof\n");
            rewind(key);
            b = fgetc(key);
        }

        char c = ((a - 'a' + b - 'a') % 26) + 'a';
        // printf("%c & %c -> %c\n", a, b, c);
        printf("%c", c);

        linecounter++;
        totalcounter++;

        // only allow 80 characters on each line
        if (linecounter == 79) {
            linecounter = 0;
            printf("\n");
        }

        // get next characters
        a = tolower(fgetc(text));
        b = tolower(fgetc(key));
    }

    while (totalcounter != 511)
    {
        while (isalpha(b) == 0) {
            b = tolower(fgetc(key));

            if (b == '\n') {
                // printf("eol\n");
                b = fgetc(key);
            }
            // reset key file as needed
            if (b == EOF) {
                // printf("eof\n");
                rewind(key);
                b = fgetc(key);
            }
        }
        // b character management
        // ignore new line characters
        if (b == '\n') {
            // printf("eol\n");
            b = fgetc(key);
        }
        // reset key file as needed
        if (b == EOF) {
            // printf("eof\n");
            rewind(key);
            b = fgetc(key);
        }

        char c = (('x' - 'a' + b - 'a') % 26) + 'a';
        // printf("%c & %c -> %c\n", a, b, c);
        printf("%c", c);

        linecounter++;
        totalcounter++;

        // only allow 80 characters on each line
        if (linecounter == 79) {
            linecounter = 0;
            printf("\n");
        }

        b = tolower(fgetc(key));
    }

    return 0;
}