#include <stdio.h>

#include "Repos_struct/console.h"
#include "Repos_struct/text_input_functions.h"
#include "Repos_struct/text_sort_functions.h"

int main(int argc, char *argv[]) {
    Text_struct text_str;
    encoding_set_rus();

    if (argc == 1) {
        print_help_onegin();
        return 0;
    }

    txt_struct_ctor(argv[1], &text_str);

    FILE    *output_file;
    fopen_s(&output_file, "output_onegin.txt", "w");

    my_sort_and_print(&text_str, output_file);

    fclose(output_file);
    txt_struct_dtor(&text_str);

    return 0;
}
