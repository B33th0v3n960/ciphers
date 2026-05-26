#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ciphers/affine.h"
#include <unistd.h>

int main(int argc, char **argv) {
    printf("==== Ciphers ====\n");

    char buffer[BUFFER_SIZE];
    int multiplier;
    int constant;
    FILE *input_file;
    FILE *output_file;
    bool cipher_encrypt = true;

    char opt;
    while ((opt = getopt(argc, argv, "f:o:a:b:d")) != -1) {
        switch (opt) {
        case 'f':
            printf("Input file: %s\n", optarg);
            input_file = fopen(optarg, "r");
            break;
        case 'o':
            printf("Output file: %s\n", optarg);
            output_file = fopen(optarg, "w");
            break;
        case 'a':
            if (sscanf(optarg, "%d", &multiplier) != 1) {
                printf("Failed to convert input to integer.\n");
                exit(EXIT_FAILURE);
            }
            break;
        case 'b':
            if (sscanf(optarg, "%d", &constant) != 1) {
                printf("Failed to convert input to integer.\n");
                exit(EXIT_FAILURE);
            }
            break;
        case 'd':
            cipher_encrypt = false;
            break;
        }
    }

    if (cipher_encrypt) {
        encrypt(input_file, output_file, buffer, multiplier, constant);
    } else {
        decrypt(input_file, output_file, buffer, multiplier, constant);
    }

    return EXIT_SUCCESS;
}
