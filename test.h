/*
 * Все функций не потокобезопасны
 */

typedef struct list_s {
    struct list_s *next; /* NULL for the last item in a list */
    int data;
} list_t;

/* Counts the number of items in a list.
 * входной параметр может быть нулевым
 * при большом кол-ве элементов возможно переполнение стека -> через цикл или хвостовую рекурсию
*/
int count_list_items2pi(const list_t *head, int acc) {
    return head ? count_list_items2pi(head->next, acc + 1) : acc;
}
int count_list_items(const list_t *head) {
    return count_list_items2pi(head, 0);
}

/* Inserts a new list item after the one specified as the argument.
 * входной параметр item может быть нулевым
 * проверить удачно ли выделена память функцией malloc
 * поле next у нового элемента указывает на себя
*/
void insert_next_to_list(list_t *item, int data) {
    list_t *new_item;
    if (!item) return;
    new_item = malloc(sizeof(list_t));
    if (!new_item) return;
    new_item->next = item->next;
    item->next = new_item;
    item->next->data = data;
}

/* Removes an item following the one specificed as the argument.
 * входной параметр item может быть нулевым
 * обращение к освобожденному участку памяти
*/
void remove_next_from_list(list_t *item) {
    list_t *rem_item;
    if (!item) return;
    rem_item = item->next;
    if (rem_item) {
        item->next = rem_item->next;
        free(rem_item);
    }
}

/* Returns item data as text.
 * входной параметр item может быть нулевым
 * возврат локальной(стековой) переменной -> добавить входной параметр для результата
*/

char *item_data(const list_t *list, char *buf) {
    if (!list) return NULL;
    if (!buf) return NULL;
    sprintf(buf, "%d", list->data);
    return buf;
}
