/*
** EPITECH PROJECT, 2022
** my linked lists
** File description:
** module providing functions for linked lists
*/

#include "my_ll.h"
#include <stdlib.h>

linked_list_part *ll_create(void *data)
{
    linked_list_part *new_object = malloc(sizeof(linked_list_part));
    new_object->prev = NULL;
    new_object->data = data;
    new_object->next = NULL;
    return new_object;
}

void ll_remove(linked_list_part *object)
{
    linked_list_part *prev = object->prev;
    linked_list_part *next = object->next;

    if (prev != NULL)
        prev->next = next;
    if (next != NULL)
        next->prev = prev;
    free(object);
}

void ll_append(linked_list_part *from,
        linked_list_part *object, int null_if_before)
{
    linked_list_part *current = from;

    if (null_if_before == 0) {
        for (; current->prev; current = current->prev);
        current->prev = object;
        object->next = current;
    } else {
        for (; current->next; current = current->next);
        current->next = object;
        object->prev = current;
    }
}

void ll_insert(linked_list_part *ref,
        linked_list_part *object, int null_if_before)
{
    linked_list_part *other;

    if (ref == NULL || object == NULL)
        return;

    if (null_if_before == 0) {
        other = ref->prev;
        if (other != NULL)
            other->next = object;
        ref->prev = object;
        object->prev = other;
        object->next = ref;
    } else {
        other = ref->next;
        if (other != NULL)
            other->prev = object;
        ref->next = object;
        object->prev = ref;
        object->next = other;
    }
}

void ll_destroy(linked_list_part *obj, int null_to_free)
{
    linked_list_part *current = obj;
    for (; current->prev; current = current->prev);
    for (; current->next; current = current->next) {
        if (!null_to_free)
            free(current->data);
        if (current->prev)
            ll_remove(current->prev);
    }
    ll_remove(current);
}
