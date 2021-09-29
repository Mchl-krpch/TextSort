#include <assert.h>
#include <stdlib.h>

#include "text_input_functions.h"
#include "text_sort_functions.h"
#include "text_output_functions.h"

void txt_struct_ctor(char *argv, Text_struct *txt) {
    assert(argv && "txt_ctor: argv is nullptr");
    assert  (txt && "txt_ctor: txt is nullptr");

    txt->text_buffer = text_read(txt, argv);

    txt->number_of_strings = count_strings_in_buffer(txt->text_buffer, txt->buffer_size);

    txt->number_of_strings = create_ptr_begin_and_ptr_end(txt);
}

size_t count_strings_in_buffer (char *buffer, size_t buffer_size) {
    size_t temporary_number_of_strings = 0;
    for (int ch = 0; ch < buffer_size; ch++) {
        if (buffer[ch] == '\n') {
            temporary_number_of_strings++;
        }
    }

    return temporary_number_of_strings;
}

char *text_read(Text_struct *txt, char *argv) {
    assert(txt != nullptr  && "text_read: txt is nullptr\n");
    assert(argv != nullptr && "text_read: argv is nullptr\n");

    fopen_s(&txt->txt_file, argv, "r");

    txt->buffer_size = get_size(txt->txt_file);

    char *dynamic_memory = (char *) calloc(txt->buffer_size + 1, sizeof(char));
    txt->buffer_size = fread(dynamic_memory, sizeof(char), txt->buffer_size, txt->txt_file);

    fclose(txt->txt_file);
    return dynamic_memory;
}

size_t get_size(FILE *txt_file) {
    assert(txt_file != nullptr);

    fseek(txt_file, 0l, SEEK_END);
    int temp_size = ftell(txt_file);
    fseek(txt_file, 0l, SEEK_SET);

    return temp_size;
}

int create_ptr_begin_and_ptr_end(Text_struct *txt) {

    int temporary_number_of_strings = 1;
    size_t temporary_str_len = 0;

    txt->sorted_pointers = (Line_info *) calloc(txt->buffer_size, sizeof(Line_info));

    txt->sorted_pointers->ptr_begin = &txt->text_buffer[0];

    for (size_t temporary_size = 0; temporary_size < txt->buffer_size + 1; temporary_size++) {//for
        temporary_str_len++;
        if (txt->text_buffer[temporary_size] == '\n') {
            txt->sorted_pointers[temporary_number_of_strings - 1].str_len = temporary_str_len;
            temporary_str_len = 0;
            
            if (txt->text_buffer[temporary_size + 1] != '\n') {
                txt->sorted_pointers[temporary_number_of_strings].ptr_begin = &txt->text_buffer[temporary_size + 1];
            }
            temporary_number_of_strings++;
        }
    }
    txt->text_buffer[txt->buffer_size + 1] = '\0';

    txt->sorted_pointers = (Line_info *)realloc((Line_info *)txt->sorted_pointers, temporary_number_of_strings * sizeof(Line_info) );

    return temporary_number_of_strings;
}

void my_sort_and_print(Text_struct *txt, FILE *output_file) {
    assert(output_file != nullptr);
    assert(txt != nullptr);

    txt->mode_of_sorting = 0;
    my_qsort(txt->sorted_pointers, txt->number_of_strings, sizeof(Line_info), txt->mode_of_sorting, str_cmp_with_mode);
    fprintf(output_file, "sorted text\n");
    print_text_to_file(txt->sorted_pointers, txt->number_of_strings, output_file);

    txt->mode_of_sorting = 1;
    fprintf(output_file, "\nsorted end text\n");
    my_qsort(txt->sorted_pointers, txt->number_of_strings, sizeof(Line_info), txt->mode_of_sorting, str_cmp_with_mode);
    print_text_to_file(txt->sorted_pointers, txt->number_of_strings, output_file);

    fprintf(output_file, "\noriginal text\n");
    fprintf(output_file, txt->text_buffer);

}

void txt_struct_dtor(Text_struct *txt) {
    assert(txt->sorted_pointers);
    assert(txt->text_buffer);
    
    free(txt->sorted_pointers);
    free(txt->text_buffer);
}
