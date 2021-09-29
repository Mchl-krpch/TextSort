#ifndef ONEGIN6_CONSOLE_H
#define ONEGIN6_CONSOLE_H

///\param RUS_wCODE stores the encoding number windows1251
unsigned int const RUS_wCODE = 1251;

///\brief special char const. Use it when you need to explain user how to work your program
extern char *const help;

///\brief puts Russian encoding
void encoding_set_rus();

///\brief prints a "help" message for a user who hasn't entered anything into the console
///(presumably runs the program for the first time)
void print_help_onegin();

#endif //ONEGIN6_CONSOLE_H
