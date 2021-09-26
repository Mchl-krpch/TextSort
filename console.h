#ifndef ONEGIN6_CONSOLE_H
#define ONEGIN6_CONSOLE_H

///\param RUS_wCODE хранит в себе номер кодировки windows1251
unsigned int const RUS_wCODE = 1251;

///\param help хранит в себе сообщение, которое печатает программа, если имеет всего один (начальный) параметр консоли
char *const help = "\tThis is a text sorting program\nSpecify the first argument argv [1] the name of the sorted file located"
                   "in the program folder\nthen enter sorting mode - begin string - sorts the text by arranging lines\nbased"
                   "on lexicographic comparison, the comparison starts from the beginning of the line\nend string mode - "
                   "sorts similarly, but starts comparing characters from the end\n";

///\brief ставит русскую кодировку
void encoding_set_rus();

///\brief выводит сообщение help для пользователея, который ничего не ввел в консоль
///(предположительно запускает программу в первый раз)
void print_help_onegin();

#endif //ONEGIN6_CONSOLE_H
