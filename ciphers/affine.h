#ifndef AFFINE_H
#define AFFINE_H

#include <stdio.h>

#define BUFFER_SIZE 256
#define CHUNK_SIZE 256

int extended_gcd(int a, int b, int *x, int *y);
int mod_inverse(int a, int m);

void encrypt(FILE *input_file, FILE *output_file, char buffer[BUFFER_SIZE], int multiplier, int constant);
void decrypt(FILE *input_file, FILE *output_file, char buffer[BUFFER_SIZE], int multiplier, int constant);

#endif // !AFFINE_H
