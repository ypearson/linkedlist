#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

#include <stdint.h>
#include <stdlib.h>

typedef struct
{
    uint32_t data;
    void   *next;
    void   *previous;
}llnode_t;

int ll_new     (llnode_t *ll_ptr_t, int data);
int ll_destroy (llnode_t *ll_ptr_t, int data);
int ll_add     (llnode_t *ll_ptr_t,  int data);
int ll_remove  (llnode_t *ll_ptr_t);


#endif
