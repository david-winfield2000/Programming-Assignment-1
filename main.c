// David Winfield

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
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
    
    while (a != EOF)
    {
        // a character management
        if (isalpha(a) == 0 || isspace(a) == 1)
        {
            a = tolower(fgetc(text));
            continue;
        }

        // b character management
        // ignore new line characters
        if (b == '\n')
        {
            // printf("eol\n");
            b = fgetc(key);
        }
        // reset key file as needed
        if (b == EOF)
        {
            // printf("eof\n");
            rewind(key);
            b = fgetc(key);
        }

        char c = ((a - 'a' + b - 'a') % 26) + 'a';
        // printf("%c & %c -> %c\n", a, b, c);
        printf("%c", c);

        // linecounter++;
        // totalcounter++;

        // if (linecounter == 79)
        //     printf("\n");

        // get next characters
        a = tolower(fgetc(text));
        b = tolower(fgetc(key));
    }

    // while (totalcounter != 511)
    // {
    //     // b character management
    //     // reset key file as needed
    //     if (b == EOF)
    //     {
    //         rewind(key);
    //         b = fgetc(key);
    //     }
    //     // ignore new line characters
    //     if (b == '\n')
    //     {
    //         b = fgetc(key);
    //     }

    //     char c = (('x' - 'a' + b - 'a') % 26) + 'a';
    //     printf("%c", c);

    //     linecounter++;
    //     totalcounter++;

    //     if (linecounter == 79)
    //         printf("\n");

    //     b = tolower(fgetc(key));
    // }

    return 0;
}