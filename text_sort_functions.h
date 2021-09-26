#ifndef ONEGIN6_TEXT_SORT_FUNCTIONS_H
#define ONEGIN6_TEXT_SORT_FUNCTIONS_H

///\param INT_NAN начальное значение, которое сигнализирует о том, что переменная еще не введена пользователем или не изменена программой
int const INT_NAN = -1;

enum {
    ///\param SORTING_BEGIN показывает, что выбран режим лексикографического сравнения с начала строки
    SORTING_BEGIN = 0,
    ///\param SORTING_END показывает, что выбран режим лексикографического сравнения с конца строки
    SORTING_END = 1
};

///\brief возвращает номер режима типа **int**
int choose_method_of_sorting();

///\brief принимает массив "from" и массив "to" и размеры массивов (они должны быть равны)
/// \param from откуда копируются элементы массива
/// \param to куда копируются элементы массива
/// \param array_len длина массивов
void array_copy(char **from, char **to, size_t array_len);

/// \brief аналогична функции qsort принимает массив типа (void *) количество элементов, размер одного элемента и функцию компоратора
/// \param arr массив типа (void *)
/// \param n_of_element количество элементов
/// \param size_of_element размер одного элемента
/// \param cmp компоратор
void my_qsort(void *arr, size_t n_of_element, size_t size_of_element, int (*cmp)(const void *a, const void *b));

///\brief узнает является ли *ch буквой (bool answer = true) или нет (bool answer = false)
bool is_alpha(char const *ch);

///\brief узнает равны ли значения *ch1 и *ch2 (оба значения подается типа (void *)) возвращает 1 если равны, 0 если не равны
int equal(const void *ch1, const void *ch2);

///\brief компоратор двух переменнты типов (void *) работает со значениями в рамках одного массива
///ссылается на функции *is_alpha()** и *equal()* используется **my_qsort()** при использовании **SORTING_BEGIN** метода
int cmp(const void *a, const void *b);

///\brief компоратор двух переменнты типов (void *) работает со значениями в рамках одного массива
///ссылается на функции *is_alpha()** и *equal()* используется **my_qsort()** при использовании **SORTING_END** метода
int cmp_reverse(const void *a, const void *b);

///\brief меняет местами байты из одного места в другое по циклу сначала по 8 байт, когда
///суммарный размер непереложенных байт больше 8 байт, и по 1, когда осталось переложить меньше 8-ми байт
/// \param elem1 сслыка на первый массив байт типа (void *)
/// \param elem2 сслыка на второй массив байт типа (void *)
/// \param size_of_element суммарный размер байт, который нужно поменять местами
/// \return
int swap(void *elem1, void *elem2, size_t size_of_element);

#endif //ONEGIN6_TEXT_SORT_FUNCTIONS_H
