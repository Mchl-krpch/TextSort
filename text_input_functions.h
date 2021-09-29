#ifndef ONEGIN6_TEXT_INPUT_FUNCTIONS_H
#define ONEGIN6_TEXT_INPUT_FUNCTIONS_H

#include <stdio.h>

///\brief structure which store pointer of begin and end of any string in in the read file
struct Line_info {
    char *ptr_begin;
    size_t  str_len;
};

///\brief suggested structure to work with .txt file
///\param txt_file text document FILE* which keep input_file.txt
///\param buffer_size size of dynamic buffer in bites
///\param number_of_strings количество строк в файле
///\param text_buffer array which keeps text of file
struct Text_struct {
    FILE *txt_file               = NULL;
    size_t buffer_size           = NULL;
    size_t number_of_strings     = NULL;
    char *text_buffer            = NULL;
    Line_info *sorted_pointers   = NULL;
    size_t mode_of_sorting       = NULL;
};

/// \ brief function creates a buffer where all text and an array of pointers to the beginning and end of lines will be saved
/// \ param argv the name of the file that is opened to read the text
/// \ param text_str is a structure containing a buffer where text can be stored in dynamic memory
void txt_struct_ctor(char *argv, Text_struct *text_str);

///\brief reads text file and save him in text_buffer
/// \param argv int form char * (file.txt) which get from console
/// \param txt_file хранимый текстовый файл
/// \param file_size размер файла в байтах
/// \return
char *text_read(Text_struct *txt, char *argv);

///\brief returns size of text document in bites
/// \param txt_file
/// \return
size_t get_size(FILE *txt_file);

///\brief creates mmarray of size pointers equal to the number of lines in the text file
/// \param array_of_pointers an array of pointers where the addresses of the beginning of lines of a text document are stored
/// \param text_lents_strint array of string lengths where the index is stored (starting from the zero element of the dynamic text array) where the string begins
/// \param dynamic_text array where text is stored
/// \param text_size text size in bytes
/// \return
int create_ptr_begin_and_ptr_end(Text_struct *txt);

///\brief clears dynamic memory from the created array of pointers and the buffer with the source text
/// \param text_str a supplied structure that contains pointers to buffers in heap
void txt_struct_dtor(Text_struct *text_str);

#endif //ONEGIN6_TEXT_INPUT_FUNCTIONS_H
