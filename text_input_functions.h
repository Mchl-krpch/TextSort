#ifndef ONEGIN6_TEXT_INPUT_FUNCTIONS_H
#define ONEGIN6_TEXT_INPUT_FUNCTIONS_H

#include <cstdio>

struct Line_info {
    char *str_ptr;
    size_t str_len;
};

struct Repository {
    FILE *txt_file;
    size_t file_size;
    size_t file_n_strings;
    char *dynamic_memory;
    //struct Line_info *origin_text;
    char *orig_lines;
    int *text_lines_starts_index;
    //struct Line_info *sorted_text;
};

char *text_read(char *argv, FILE *txt_file, size_t *file_size);

size_t text_get_size(FILE *txt_file);

int text_ptrs_realoc_to_nstings(char **array_of_pointers, int **text_lents_strint, char **dynamic_text, size_t text_size);

void text_create_ptrs(char **pointers , char **dynamic_memory, size_t file_n_strings, int *text_lines_starts_index);

#endif //ONEGIN6_TEXT_INPUT_FUNCTIONS_H
