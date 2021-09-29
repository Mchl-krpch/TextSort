#include <xlocinfo>
#include <Windows.h>

#include "console.h"

void encoding_set_rus() {
    setlocale(LC_ALL, "rus");
    SetConsoleCP(RUS_wCODE);
    SetConsoleOutputCP(RUS_wCODE);

    printf("\tRussian is set\n");
}

void print_help_onegin() {
    printf("%s", help);
}
