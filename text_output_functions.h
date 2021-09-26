#ifndef ONEGIN6_TEXT_OUTPUT_FUNCTIONS_H
#define ONEGIN6_TEXT_OUTPUT_FUNCTIONS_H

///\brief печатает массив символов в текстовый файл
/// \param arr_pointers ссылка на массив типа (char **), массив состоит из указателей на начала строк
/// \param number_of_strings количество строк для печати
/// \param output_file текстовый файл, куда происходит печать
void text_to_file(char **arr_pointers, int number_of_strings, FILE *output_file);

#endif //ONEGIN6_TEXT_OUTPUT_FUNCTIONS_H
