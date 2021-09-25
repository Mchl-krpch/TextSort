#include <cstdio>
#include <cstdlib>

#include "console.h"
#include "text_input_functions.h"
#include "text_sort_functions.h"
#include "text_output_functions.h"

struct Repository text_str;

int main(int argc, char *argv[]) {
    //console.h
    encoding_set_rus();

    if (argc == 1) {
        print_help_onegin();
        exit(0);
    }

    //text_input_functions
    text_str.dynamic_memory = text_read(argv[1], text_str.txt_file, &text_str.file_size);

    text_str.file_n_strings = text_ptrs_realoc_to_nstings(&text_str.orig_lines, &text_str.text_lines_starts_index, &text_str.dynamic_memory, text_str.file_size);

    text_create_ptrs(&text_str.orig_lines, &text_str.dynamic_memory, text_str.file_n_strings, text_str.text_lines_starts_index);

    //sort part
    text_str.sorted_lines = (char **)calloc(text_str.file_n_strings, sizeof(char *));
    for (int str = 0; str < text_str.file_n_strings; str++) {
        text_str.sorted_lines[str] = text_str.orig_lines[str];
    }

    int sort_method = choose_method_of_sorting();

    switch (sort_method) {
        case 0:
            printf("you choose begin\n");
            my_qsort((void *)text_str.sorted_lines, text_str.file_n_strings, sizeof(char *), cmp);
            break;

        case 1:
            printf("you choose end\n");
            my_qsort((void *)text_str.sorted_lines, text_str.file_n_strings, sizeof(char *), cmp_reverse);
            break;

        default:
            printf("Incorrect data: use only program sorts\n");
            exit(0);
    }

    //output part
    FILE *outut_file = fopen("output_onegin.txt", "w");
    fprintf(outut_file, "\nsorted\n");
    text_to_file(text_str.sorted_lines, text_str.file_n_strings, outut_file);
    fprintf(outut_file, "\norigin\n");
    text_to_file(text_str.orig_lines, text_str.file_n_strings, outut_file);

    printf("origin\n\n");
    for (int str = 0; str < text_str.file_n_strings; str++) {
        printf("%s\n", text_str.orig_lines[str]);
    }

    printf("sorted\n\n");
    for (int str = 0; str < text_str.file_n_strings; str++) {
        printf("%s\n", text_str.sorted_lines[str]);
    }

    free(text_str.orig_lines);
    free(text_str.dynamic_memory);
    free(text_str.sorted_lines);
    free(text_str.text_lines_starts_index);

    return 0;
}
