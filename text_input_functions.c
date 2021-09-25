#include <cstdlib>
#include "text_input_functions.h"

char *text_read(char *argv, FILE *txt_file, size_t *file_size) {
    fopen_s(&txt_file, &argv[0], "r");

    *file_size = text_get_size(txt_file);
    char *dynamic_memory = (char *) calloc(*file_size, sizeof(char));

    fread(dynamic_memory, sizeof(char), *file_size, txt_file);
    return dynamic_memory;
}

size_t text_get_size(FILE *tgs_txt_file) {
    int tgs_file_size = 0;

    fseek(tgs_txt_file, 0l, SEEK_END);
    tgs_file_size = ftell(tgs_txt_file);
    fseek(tgs_txt_file, 0l, SEEK_SET);

    return tgs_file_size;
}

int text_ptrs_realoc_to_nstings(char **array_of_pointers, int **text_lines_starts_index, char **dynamic_text, size_t tprtn_text_size) {
    int dynam_index = 0, temporary_nstrings = 1;
    int temporary_size = tprtn_text_size - 1;

    *array_of_pointers = (char *) calloc(temporary_size, sizeof(char *));
    *text_lines_starts_index = (int *)calloc(14, sizeof(int));
    //*(*text_lines_starts_index + 2) = 15;
    //printf("%d\n", *(*text_lines_starts_index + 2));

    //printf("temporary size here %d\n", temporary_size);
    while (temporary_size > 0) {
        temporary_size--;
        if (*(*dynamic_text + dynam_index) == '\n') {
            temporary_nstrings++;
            *(*dynamic_text + dynam_index) = '\0';

            //printf("strings %d %d\n", temporary_nstrings - 1, dynam_index + 1);
            *(*text_lines_starts_index + temporary_nstrings - 1) = dynam_index + 1;
        }
        dynam_index++;
    }
    //printf("%d\n", *(*text_lines_starts_index + 13));

    //printf("at all %d strings\n", temporary_nstrings);
    *array_of_pointers = (char *) realloc(*array_of_pointers, sizeof(char *));
    return temporary_nstrings;
}

void text_create_ptrs(char **pointers, char **dynamic_memory, size_t file_n_strings, int *text_lines_starts_index) {
    printf("index: %d\n", text_lines_starts_index[13]);
    printf("test string: %s\n", (*dynamic_memory + 28));
    *pointers = (*dynamic_memory + 28);

    //printf("index: %s\n", pointers[0]);
    /*for (int str = 0; str < file_n_strings; str++) {
        *pointers + str = *(*dynamic_memory + text_lines_starts_index[str]);
    }*/
    //(pointers[0]) = (char *)(*dynamic_memory);
    //(pointers[1]) = (char *)(*dynamic_memory + 28);


    //printf("here %s\n", *pointers[13]);
    /*for (int str = 0; str < num_strings; str++) {

    }*/
}
