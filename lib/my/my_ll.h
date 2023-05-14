/*
** EPITECH PROJECT, 2022
** my linked lists
** File description:
** sub module providing everything needed to make linked lists
*/

#ifndef INCLUDED_LL_H
    #define INCLUDED_LL_H

typedef struct dbl_linked_list_part_s {
    struct dbl_linked_list_part_s *prev;
    void *data;
    struct dbl_linked_list_part_s *next;
} linked_list_part;

linked_list_part *ll_create(void *data);
void ll_append(linked_list_part *from,
        linked_list_part *object, int null_if_before);
void ll_remove(linked_list_part *object);
void ll_insert(linked_list_part *ref,
        linked_list_part *object, int null_if_before);
void ll_destroy(linked_list_part *obj, int null_to_free);

#endif
