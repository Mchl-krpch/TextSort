#include <cstdio>
#include <cassert>
#include <cstdint>

#include "text_sort_functions.h"
#include "text_input_functions.h"

void my_qsort(void *arr, size_t n_of_element, size_t size_of_element, size_t mode_of_sorting,
              int (*string_cmp)(const void *a, const void *b, int mode)) {
    assert (arr != nullptr);
    assert (string_cmp != nullptr);
    assert(string_cmp != nullptr);

    Line_info *start = (Line_info *) arr;

    int right = (int) n_of_element - 1;
    int last = 0;
    int tmp = right / 2;

    if (0 >= right) {
        return;
    }

    partition(start, &right, &last, &tmp, size_of_element, mode_of_sorting, string_cmp);

    my_qsort((Line_info *) start, last, size_of_element, mode_of_sorting, string_cmp);
    my_qsort(((Line_info *) start + last + 1), n_of_element - last - 1,
             size_of_element, mode_of_sorting, string_cmp);
}

void partition(void *start, int *right, int *last, int *tmp, size_t size_of_element, size_t mode_of_sorting,
               int (*string_cmp)(const void *a, const void *b, int mode)) {
    assert(string_cmp != nullptr && "partition");
    assert(start != nullptr && "partition");
    assert(size_of_element != NULL && "partition");
    assert(string_cmp != nullptr && "partition");


    swap(((Line_info *) start), ((Line_info *) start + *tmp), size_of_element);

    for (int i = 1; i <= *right; ++i) {
        if (string_cmp(((Line_info *) start + i), ((Line_info *) start), mode_of_sorting) < 0) {
            ++(*last);
            swap(((Line_info *) start + i), ((Line_info *) start + *last), sizeof(Line_info));
        }
        if (*last >= 14) {
            return;
        }
    }

    swap(((Line_info *) start + *last), (Line_info *) start, size_of_element);
}

bool is_letter(char ch) {
    return ('А' <= ch && ch <= 'Я') || ('а' <= ch && ch <= 'я');
}

int str_cmp_with_mode(const void *a, const void *b, int mode) {
    if (mode == SORTING_BEGIN) {
        return string_cmp(((Line_info *) a)->ptr_begin, ((Line_info *) b)->ptr_begin, 1);
    }
    if (mode == SORTING_END) {
        return string_cmp(((Line_info *) a)->ptr_begin + ((Line_info *) a)->str_len - 1,
                          ((Line_info *) b)->ptr_begin + ((Line_info *) b)->str_len - 1, -1);
    }
    return 1;
}

// int str_cmp_forward(const void *a, const void *b)
// return string_cmp(char*(a), ...b, +1);
// int str_cmp_rev(const void *a, const void *b)
//
// int string_cmp(const void *a, const void *b, int step)
int string_cmp(const void *a, const void *b, int step) {
    assert (a != nullptr && "cmp: &a = nullptr");
    assert (b != nullptr && "cmp: &b = nullptr");


    char *ch1 = (char *) a;
    char *ch2 = (char *) b;

    while (!is_letter(*ch1)) {
        ch1 += step;
    }

    while (!is_letter(*ch2)) {
        ch2 += step;
    }

    if (*ch1 == *ch2) {
        ch1 += step;
        ch2 += step;
    }

    return *ch1 - *ch2;
}

int swap(Line_info *elem1, Line_info *ele2, size_t size_of_element) {
    Line_info temp = *(Line_info *) elem1;
    *elem1 = *elem2;
    *elem2 = temp;

    return 0;
}
