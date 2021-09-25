#ifndef ONEGIN6_TEXT_SORT_FUNCTIONS_H
#define ONEGIN6_TEXT_SORT_FUNCTIONS_H

int choose_method_of_sorting();

void my_qsort(void *arr, size_t n_of_element, size_t size_of_element, int (*cmp)(const void *a, const void *b));

bool is_alpha(char const *ch);

int equal(const void *ch1, const void *ch2);

int cmp(const void *a, const void *b);

int cmp_reverse(const void *a, const void *b);

int swap(void *elem1, void *elem2, size_t size_of_element);

#endif //ONEGIN6_TEXT_SORT_FUNCTIONS_H
