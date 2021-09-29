#ifndef ONEGIN6_TEXT_OUTPUT_FUNCTIONS_H
#define ONEGIN6_TEXT_OUTPUT_FUNCTIONS_H

#include "text_input_functions.h"

///\brief печатает массив символов в текстовый файл
/// \param arr_pointers ссылка на массив типа (char **), массив состоит из указателей на начала строк
/// \param number_of_strings количество строк для печати
/// \param output_file текстовый файл, куда происходит печать
void print_text_to_file(Line_info *sorted_pointers, int number_of_strings, FILE *output_file);

///\brief save output sorted text in special text file
/// \param output_file file which store your sorted text
/// \param pointers array of pointers that you can save in text file
void my_fprintf(FILE *output_file, char *pointers);

#endif //ONEGIN6_TEXT_OUTPUT_FUNCTIONS_H
