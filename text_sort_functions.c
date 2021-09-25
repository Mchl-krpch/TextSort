#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstdint>

#include "text_sort_functions.h"

int const INT_NAN = -1;

int choose_method_of_sorting() {
    int temporary_method = INT_NAN;
    printf("How should i sort strings?\n"
           "0.begin str\n"
           "1.end str\n");

    if (scanf_s("%d", &temporary_method) != 1) {
        printf("Incorrect data: use ints");
        exit(0);
    }
    return temporary_method;
}

void my_qsort(void *arr, size_t n_of_element, size_t size_of_element, int (*cmp)(const void *a, const void *b)){
    assert (arr != nullptr);
    assert (cmp != nullptr);

    char *start = (char *) arr;

    int right = (int) n_of_element - 1;
    int last = 0;
    int tmp = right / 2;

    if (0 >= right) return;

    swap(start, start + tmp * size_of_element, size_of_element);

    for (int i = 1; i <= right; ++i) {
        if (cmp(start + i * size_of_element, start) < 0) {
            ++last;
            swap(start + i * size_of_element, start + last * size_of_element, size_of_element);
        }
    }

    swap(start + last * size_of_element, start, size_of_element);

    my_qsort(start, last, size_of_element, cmp);
    my_qsort(start + (last + 1) * size_of_element, n_of_element - last - 1, size_of_element, cmp);
}

bool is_alpha(char const *ch) {
    assert (ch != nullptr && "is_alpha: &ch = nullptr");

    wchar_t bad_chars[] = L"—«» !;,.:()\"";

    for (int i = 0; i < sizeof(bad_chars) / sizeof(*bad_chars); i++) {
        if (*ch == bad_chars[i]) return false;
    }

    return true;
}

int cmp(const void *a, const void *b) {
    assert (a != nullptr && "cmp: &a = nullptr");
    assert (b != nullptr && "cmp: &b = nullptr");

    char *ch1 = *(char **) a;
    char *ch2 = *(char **) b;

    while (is_alpha(ch1) == 0) ch1++;

    while (is_alpha(ch2) == 0) ch2++;

    while (equal(ch1, ch2) == 1) {
        ch1++;
        ch2++;
    }

    return *ch1 - *ch2;
}

int cmp_reverse(const void *a, const void *b) {
    assert (a != nullptr && "cmp: &a = nullptr");
    assert (b != nullptr && "cmp: &b = nullptr");

    char *ch1 = *(char **) a;
    char *ch2 = *(char **) b;

    while (*ch1 != '\0') ch1++;
    while (*ch2 != '\0') ch2++;
    ch1--;
    ch2--;


    while (is_alpha(ch1) == 0) ch1--;

    while (is_alpha(ch2) == 0) ch2--;

    while (equal(ch1, ch2) == 1) {
        ch1--;
        ch2--;
    }

    return *ch1 - *ch2;
}

int equal(const void *b, const void *a) {
    char ch1 = *(char *) a;
    char ch2 = *(char *) b;

    if (ch1 == ch2) return 1;
    return 0;
}

int swap(void *elem1, void *elem2, size_t size_of_element) {
    assert (elem1 != nullptr && "swap: &elem1 = nullptr");
    assert (elem2 != nullptr && "swap: &elem2 = nullptr");

    while (size_of_element > 0) {
        if (size_of_element >= 8) {
            uint64_t tmp = *(uint64_t*) elem1;
            *(uint64_t*) elem1 = *(uint64_t*) elem2;
            *(uint64_t*) elem2 = tmp;
        } else {
            uint8_t tmp = *(uint8_t*) elem1;
            *(uint8_t*) elem1 = *(uint8_t*) elem2;
            *(uint8_t*) elem2 = tmp;
        }

        size_t step = (size_of_element >= 8 ? 8 : 1);
        size_of_element -= step;

        elem1 = (char *)elem1 + step;
        elem2 = (char *)elem2 + step;
    }

    return 0;
}
