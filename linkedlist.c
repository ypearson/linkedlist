#include "linkedlist.h"

int ll_new (llnode_t **ll_ptr, int data)
{
    llnode_t * n;
    *ll_ptr = (llnode_t*) malloc(sizeof(llnode_t));
    n = *ll_ptr;
    n->data = data;
    n->size = 1;
    n->next = 0;
    n->previous = 0;

    return 0;
}
int ll_destroy (llnode_t **ll_ptr, int data)
{
    llnode_t  * ll_p = *ll_ptr;

    while(ll_remove(ll_p) >=0);

    return 0;
}

int ll_add     (llnode_t **ll_ptr,  int data)
{
    llnode_t  * ll_p = *ll_ptr;
    llnode_t  * ll_pv;

    if(!ll_p)
        return -1;

    while(ll_p)
    {
        ll_pv = ll_p;
        ll_p = ll_p->next;
    }
    ll_pv->next = (llnode_t*) malloc(sizeof(llnode_t));

    ll_p = (llnode_t*) ll_pv->next;
    ll_p->next = 0;
    ll_p->previous = (void *)ll_pv;
    ll_p->data = data;

    return 0;
}

int ll_remove(llnode_t **ll_ptr)
{
    llnode_t  * ll_p = *ll_ptr;
    llnode_t  * ll_pv;

    if(!ll_p) // null list
    {
        return -1;
    }

    while(ll_p)
    {
        ll_pv = ll_p;
        ll_p = ll_p->next;
    }
    ll_p = ll_pv;

    if(ll_p->previous) // more than one nodes
    {
        ll_pv = ll_p->previous;
        free(ll_p);
        ll_pv->next = 0;
    }
    else  // one node
    {
        free(ll_p);
        *ll_ptr = 0;
    }

    return 0;
}

int ll_print(llnode_t **ll_ptr)
{
    llnode_t  * ll_p = *ll_ptr;

    if(!ll_p)
        return -1;

    while(ll_p)
    {
        printf("<--->%" PRIu32, ll_p->data);
        ll_p = ll_p->next;
    }
    printf("\n");
}

