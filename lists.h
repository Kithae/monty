#ifndef LISTS_H
#define LISTS_H

#include "monty.h"

/* 1list.c */
size_t list_len(const dlistint_t *h);
size_t listprint (const dlistint_t *h);
dlistint_t *dnodeadd(dlistint_t **head, const int n);
dlistint_t *read_index_dnode(dlistint_t *head, unsigned int index);
int del_index_dnode(dlistint_t **head, unsigned int index);

/* 2list.c */
void dlistfree(dlistint_t *head);
dlistint_t *dnodeadd_end(dlistint_t **head, const int n);
dlistint_t *insert_index_dnode(dlistint_t **h, unsigned int idx, int n);

#endif
