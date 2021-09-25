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
    //printf("%d", text_str.file_size);

    text_str.file_n_strings = text_ptrs_realoc_to_nstings(&text_str.orig_lines, &text_str.text_lines_starts_index, &text_str.dynamic_memory, text_str.file_size);
    /*if (text_str.dynamic_memory[26] == '\0') {
        printf("yes\n");
    }*/
    //printf("%d\n", text_str.text_lines_starts_index[13]);

    //text_create_ptrs(&text_str.orig_lines, &text_str.dynamic_memory, text_str.file_n_strings, text_str.text_lines_starts_index);
    //printf("%s\n", text_str.orig_lines[0]);
    //printf("%s", text_str.orig_lines);

    return 0;
}
