#ifndef ONEGIN6_TEXT_INPUT_FUNCTIONS_H
#define ONEGIN6_TEXT_INPUT_FUNCTIONS_H

#include <cstdio>

///\brief предлагаемая структура хранения информации о файле
///\param txt_file текстовый документ типа FILE* который хранит input_file.txt
///\param file_size размер файла в байтах
///\param file_n_strings количество строк в файле
///\param dynamic_memory массив, куда считывается весь текст, хранится в динамической памяти
struct Repository {
    FILE *txt_file;
    size_t file_size;
    size_t file_n_strings;
    char *dynamic_memory;
    //struct Line_info *origin_text;
    char **orig_lines;
    int *text_lines_starts_index;
    char **sorted_lines;
    //struct Line_info *sorted_text;
};

///\brief функция, которая считывает текстовый файл полностью в динамически-расширяемый массив
/// \param argv имя файла формата (file.txt) который считывается с консоли
/// \param txt_file хранимый текстовый файл
/// \param file_size размер файла в байтах
/// \return
char *text_read(char *argv, FILE *txt_file, size_t *file_size);

///\brief возвращает размер тектового файла в байтах
/// \param txt_file текстовый файл, размер которого хотим узнать
/// \return
size_t text_get_size(FILE *txt_file);

///\brief создает ммассив указателей размера равным количеству строк в текстовом файле
/// \param array_of_pointers массив указателей, куда сохраняются адреса начала строк текстового документа
/// \param text_lents_strint  массив длин строк, где хранится индекс (начиная от нулевого элемента массива dynamic text) где начинается строка
/// \param dynamic_text массив, где хранится текст
/// \param text_size размер текста в байтах
/// \return
int
text_ptrs_realoc_to_nstings(char ***array_of_pointers, int **text_lents_strint, char **dynamic_text, size_t text_size);

///\brief помещает адреса в массив указателей на начала строк
/// \param pointers массив указателей на начала строк
/// \param dynamic_memory динамическая память
/// \param file_n_strings количество строк в текстовом файле
/// \param text_lines_starts_index массив с индексами начал строк по тексту
void text_create_ptrs(char ***pointers, char **dynamic_memory, size_t file_n_strings, int *text_lines_starts_index);

#endif //ONEGIN6_TEXT_INPUT_FUNCTIONS_H
