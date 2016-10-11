#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>

typedef struct
{
    uint32_t data;
    uint32_t size;
    void    *next;
    void    *previous;
} llnode_t;

int ll_new     (llnode_t **ll_ptr, int data);
int ll_destroy (llnode_t **ll_ptr, int data);
int ll_add     (llnode_t **ll_ptr,  int data);
int ll_remove  (llnode_t **ll_ptr);
int ll_print   (llnode_t **ll_ptr);


#endif
