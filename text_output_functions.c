#include <cstdio>

#include "text_output_functions.h"

void text_to_file(char **arr_pointers, int number_of_strings, FILE *output_file) {
    for (int str = 0; str < number_of_strings; str++) {
        fprintf(output_file, arr_pointers[str]);
        fprintf(output_file, "\n");
    }
}
