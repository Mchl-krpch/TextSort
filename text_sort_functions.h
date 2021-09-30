#ifndef ONEGIN6_TEXT_SORT_FUNCTIONS_H
#define ONEGIN6_TEXT_SORT_FUNCTIONS_H

#include "text_input_functions.h"

///\param INT_NAN an initial value that signals that the variable has not
/// yet been entered by the user or changed by the program
extern int const INT_NAN;

///\brief sorts the entered text in user-selected sorts and outputs it to a specific file
/// \param text_str is a text structure that contains an array of pointers to lines of the original text
/// \param output_file file to output sorted and original text
void my_sort_and_print(Text_struct *text_str, FILE *output_file);

///\brief comparator of two variable types (void *) works with values within one array
///refers to functions *is_letter ()** and *equal ()* used by **my_qsort ()**
/// when using ** SORTING_BEGIN ** method
/// \param a path of first string to compare
/// \param b path of second string to compare
/// \param step in which way string cmp should move when compare chars
/// \return
int string_cmp(const void *a, const void *b, int step);

/// \brief similar to qsort function accepts an array of type (void *) number of elements,
/// size of one element and a composer function
/// \param arr array (void *)
/// \param n_of_element number of elements
/// \param size_of_element size of one element
/// \param cmp string comparator
void my_qsort(void *arr, size_t n_of_element, size_t size_of_element, int (*cmp)(const void *a, const void *b));

///\brief comparator of two variable types (void *) works with values within one array
///refers to functions *is_letter ()** and *equal ()* used by **my_qsort ()**
/// when using ** SORTING_BEGIN ** method
/// \param a path of first string to compare
/// \param b path of second string to compare
int strcmp_forward(const void *a, const void *b);

///\brief comparator of two variable types (void *) works with values within one array
///refers to functions *is_letter ()** and *equal ()* used by **my_qsort ()**
/// when using ** SORTING_BEGIN ** method
/// \param a path of first string to compare
/// \param b path of second string to compare
int strcmp_reverse(const void *a, const void *b);

///\brief finds out if * ch is a letter (bool answer = true) or not (bool answer = false)
bool is_letter(char const *ch);

///\brief swaps bytes from one place to another in a loop, first by 8 bytes, when
///the total size of non-swapped bytes is more than 8 bytes, and 1 each when there are less than 8 bytes left to swap
/// \param elem1 reference to the first byte array of type (void *)
/// \param elem2 reference to the second byte array of type (void *)
/// \param size_of_element total size of bytes to be swapped
/// \return
int swap(Line_info *elem1, Line_info *elem2, size_t size_of_element);

///\brief takes one step of sorting qsort, swaps the position of the lines and data about the lines
/// \param start array of structures containing data about strings
/// \param right array of the "right" element of the string
/// \param last array of the last element, which will subsequently change with the new pivot
/// \param tmp middle pivot
/// \param size_of_element the size of one element that we want to shift
/// \param mode_of_sorting sorting modification (sorting from end of line / beginning of line)
/// \param cmp selected comprator
void partition(void *start, int right, int *last, int tmp, size_t size_of_element,
               int (*cmp)(const void *a, const void *b));

#endif //ONEGIN6_TEXT_SORT_FUNCTIONS_H
