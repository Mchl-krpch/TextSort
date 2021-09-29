#ifndef ONEGIN6_CONSOLE_H
#define ONEGIN6_CONSOLE_H

///\param RUS_wCODE stores the encoding number windows1251
unsigned int const RUS_wCODE = 1251;

///\param help stores the message that the program prints if it has only one (initial) console parameter
char *const help = "\tThis is a text sorting program\nSpecify the first argument argv [1] the name of the sorted file located"
                   "in the program folder\nthen enter sorting mode - begin string - sorts the text by arranging lines\nbased"
                   "on lexicographic comparison, the comparison starts from the beginning of the line\nend string mode - "
                   "sorts similarly, but starts comparing characters from the end\n";

///\brief puts Russian encoding
void encoding_set_rus();

///\brief prints a "help" message for a user who hasn't entered anything into the console
///(presumably runs the program for the first time)
void print_help_onegin();

#endif //ONEGIN6_CONSOLE_H
