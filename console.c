#include <xlocinfo>
#include <Windows.h>

#include "console.h"

///\param help stores the message that the program prints if it has only one (initial) console parameter
char *const help = "\tThis is a text sorting program\nSpecify the first argument argv [1] the name of the sorted file located"
                   "in the program folder\nthen enter sorting mode - begin string - sorts the text by arranging lines\nbased"
                   "on lexicographic comparison, the comparison starts from the beginning of the line\nend string mode - "
                   "sorts similarly, but starts comparing characters from the end\n";

void encoding_set_rus() {
    setlocale(LC_ALL, "rus");
    SetConsoleCP(RUS_wCODE);
    SetConsoleOutputCP(RUS_wCODE);

    printf("\tRussian is set\n");
}

void print_help_onegin() {
    printf("%s", help);
}
