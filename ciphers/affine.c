#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "affine.h"

#define BUFFER_SIZE 256
#define CHUNK_SIZE 256

int extended_gcd(int a, int b, int *x, int *y) {
    if (a == 0) {
        *x = 0;
        *y = 1;
        return b;
    }

    int x1, y1;
    int gcd = extended_gcd(b % a, a, &x1, &y1);

    *x = y1 - (b / a) * x1;
    *y = x1;
    return gcd;
}

int mod_inverse(int a, int m) {
    int x, y;
    int g = extended_gcd(a, m, &x, &y);
    if (g != 1)
        return -1;

    return (x % m + m) % m;
}

void encrypt(FILE *input_file, FILE *output_file, char buffer[BUFFER_SIZE],
             int multiplier, int constant) {
    if (input_file == NULL) {
        printf("Error: Could not open file.\n");
        exit(EXIT_FAILURE);
    } else if (output_file == NULL) {
        output_file = fopen("encrypted.txt", "w");
    }

    while (fgets(buffer, BUFFER_SIZE, input_file) != NULL) {
        for (int char_index = 0; buffer[char_index] != '\0'; char_index++) {
            int hash_out =
                (multiplier * buffer[char_index] + constant) % CHUNK_SIZE;

            fprintf(output_file, "%c", hash_out);
        }
    }
}

void decrypt(FILE *input_file, FILE *output_file, char buffer[BUFFER_SIZE],
             int multiplier, int constant) {

    if (input_file == NULL) {
        printf("Error: Could not open file.\n");
        exit(EXIT_FAILURE);
    } else if (output_file == NULL) {
        output_file = fopen("decrypted.txt", "w");
    }

    int mul_inverse = mod_inverse(multiplier, CHUNK_SIZE);
    while (fgets(buffer, BUFFER_SIZE, input_file) != NULL) {
        for (int char_index = 0; buffer[char_index] != '\0'; char_index++) {
            int hash_out =
                (mul_inverse * (buffer[char_index] - constant)) % CHUNK_SIZE;

            fprintf(output_file, "%c", hash_out);
        }
    }
}

