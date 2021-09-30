#include <cstdio>
#include <cassert>
#include <cstdint>

#include "text_sort_functions.h"
#include "text_input_functions.h"

int const INT_NAN = -1;

void my_qsort(void *arr, size_t n_of_element, size_t size_of_element, int (*string_cmp)(const void *a, const void *b)) {
    assert (arr != NULL        && "my_qsort:        arr ptr = NULL");
    assert (string_cmp != NULL && "my_qsort: string cmp ptr = NULL");

    Line_info *start = (Line_info *) arr;

    int right = (int)n_of_element - 1;
    int last = 0;
    int tmp = right / 2;

    if (0 >= right) {
        return;
    }

    partition(start, right, &last, tmp, size_of_element, string_cmp);

    my_qsort((Line_info *) start, last, size_of_element, string_cmp);
    my_qsort(((Line_info *) start + last + 1), n_of_element - last - 1,
             size_of_element, string_cmp);
}

void partition(void *start, int right, int *last, int tmp, size_t size_of_element,
               int (*string_cmp)(const void *a, const void *b)) {
    assert(string_cmp != nullptr && "partition");
    assert(start != nullptr && "partition");
    assert(size_of_element != NULL && "partition");
    assert(string_cmp != nullptr && "partition");


    swap(((Line_info *) start), ((Line_info *) start + tmp), size_of_element);

    for (int i = 1; i <= right; ++i) {
        if (string_cmp(((Line_info *) start + i), ((Line_info *) start)) < 0) {
            ++(*last);
            swap(((Line_info *) start + i), ((Line_info *) start + *last), sizeof(Line_info));
        }
    }

    swap(((Line_info *) start + *last), (Line_info *) start, size_of_element);
}

bool is_letter(char ch) {
    return ('А' <= ch  &&  ch <= 'Я') || ('а' <= ch  &&  ch <= 'я') ||
           (ch == 'I') || (ch == 'X') || (ch == 'V') || (ch == 'L');
}

int strcmp_forward(const void *a, const void *b) {
    assert(a != NULL && "strcmp_forward: a = NULL");
    assert(b != NULL && "strcmp_forward: b = NULL");

    return string_cmp(((Line_info*)a)->ptr_begin, ((Line_info*)b)->ptr_begin, 1);
}

int strcmp_reverse(const void *a, const void *b) {
    assert(a != NULL && "strcmp_reverse: a = NULL");
    assert(b != NULL && "strcmp_reverse: b = NULL");

    return string_cmp(((Line_info*)a)->ptr_begin + ((Line_info*)a)->str_len - 2,
                      ((Line_info*)b)->ptr_begin + ((Line_info*)b)->str_len - 2, -1);
}

int string_cmp(const void *a, const void *b, int step) {
    assert (a != NULL && "cmp: &a = nullptr");
    assert (b != NULL && "cmp: &b = nullptr");

    char *ch1 = (char *) a;
    char *ch2 = (char *) b;

    while (!is_letter(*ch1)) {
        ch1 += step;
    }

    while (!is_letter(*ch2)) {
        ch2 += step;
    }

    while (*ch1 == *ch2 && *ch1 != '\n' && *ch2 != '\n') {
        ch1 += step;
        ch2 += step;
    }

    return *ch1 - *ch2;
}

int swap(Line_info *elem1, Line_info *elem2, size_t size_of_element) {
    assert(elem1 != NULL && "swap: elem1 = NULL");
    assert(elem2 != NULL && "swap: elem2 = NULL");


    Line_info temp = *(Line_info *) elem1;
    *elem1 = *elem2;
    *elem2 = temp;

    return 0;
}
