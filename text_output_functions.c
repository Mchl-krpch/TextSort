#include "text_output_functions.h"

void print_text_to_file(Line_info *pointers, int number_of_strings, FILE *output_file) {
    for (int str = 0; str < number_of_strings - 1; str++) {
        my_fprintf(output_file, pointers[str].ptr_begin);
    }
}

void my_fprintf(FILE *output_file, char *pointers) {
    int i = 0;
    while (pointers[i] != '\n') {
        fputc(pointers[i], output_file);
        i++;
    }
    fputc('\n', output_file);
}

