/*=============================================================================
| Assignment: pa01 - Encrypting a plaintext file using the Vigenere cipher
|
| Author: David Winfield
| Language: C
|
| To Compile: javac pa01.java
| gcc -o pa01 pa01.c
|
| To Execute:
| or c -> ./pa01 kX.txt pX.txt
| where kX.txt is the keytext file
| and pX.txt is plaintext file
|
| Note: All input files are simple 8 bit ASCII input
|
| Class: CIS3360 - Security in Computing - Summer 2022
| Instructor: McAlpin
| Due Date: June 19, 2022
|
+=============================================================================*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char const *argv[]) {
    // function takes in 2 arguments (argument 1 = encryption key file, argument 2 = file to be encrypted)

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
            break;
        }
        
        // b character management
        while (isalpha(b) == 0) {
            b = tolower(fgetc(key));

            if (b == '\n') {
                b = tolower(fgetc(key));
            }
            // reset key file as needed
            if (b == EOF) {
                rewind(key);
                b = tolower(fgetc(key));
            }
        }

        // b character management
        if (b == '\n') {
            b = tolower(fgetc(key));
        }
        // reset key file as needed
        if (b == EOF) {
            rewind(key);
            b = tolower(fgetc(key));
        }

        char c = ((a - 'a' + b - 'a') % 26) + 'a';
        printf("%c", c);

        linecounter++;
        totalcounter++;

        // reached size limit
        if (totalcounter == 512)
            return 0;

        // only allow 80 characters on each line
        if (linecounter == 80) {
            linecounter = 0;
            printf("\n");
        }

        // get next characters
        a = tolower(fgetc(text));
        b = tolower(fgetc(key));
    }

    while (totalcounter != 512)
    {
        while (isalpha(b) == 0) {
            b = tolower(fgetc(key));

            if (b == '\n') {
                b = tolower(fgetc(key));
            }
            // reset key file as needed
            if (b == EOF) {
                rewind(key);
                b = tolower(fgetc(key));
            }
        }

        // b character management
        if (b == '\n') {
            b = tolower(fgetc(key));
        }
        if (b == EOF) {
            rewind(key);
            b = tolower(fgetc(key));
        }

        char c = (('x' - 'a' + b - 'a') % 26) + 'a';
        printf("%c", c);

        linecounter++;
        totalcounter++;

        // only allow 80 characters on each line
        if (linecounter == 80) {
            linecounter = 0;
            printf("\n");
        }

        b = tolower(fgetc(key));
    }

    return 0;
}

/*=============================================================================
| I David Winfield (4707545) affirm that this program is
| entirely my own work and that I have neither developed my code together with
| any another person, nor copied any code from any other person, nor permitted
| my code to be copied or otherwise used by any other person, nor have I
| copied, modified, or otherwise used programs created by others. I acknowledge
| that any violation of the above terms will be treated as academic dishonesty.
+=============================================================================*/
