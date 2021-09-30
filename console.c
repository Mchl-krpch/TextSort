#include <xlocinfo>
#include <Windows.h>

#include "console.h"
unsigned int const RUS_wCODE = 1251;

///\param help stores the message that the program prints if it has only one (initial) console parameter
const char *const help = "\tThis is a text sorting program"
                         "\nSpecify the first argument argv [1] the name of the sorted file located in the program\n"
                         "folder then enter sorting mode - begin string - sorts the text by arranging lines\n"
                         "based on lexicographic comparison, the comparison starts from the beginning of the line\n"
                         "end string mode - sorts similarly, but starts comparing characters from the end\n";

void encoding_set_rus() {
    setlocale            (LC_ALL, "rus");
    SetConsoleCP         (RUS_wCODE);
    SetConsoleOutputCP   (RUS_wCODE);

    printf("\tRussian is set\n");
}

void print_help_onegin() {
    printf("%s", help);
}
