
#include "linkedlist.h"

// void *malloc(size_t size);
// void free(void *ptr);

int ll_new (llnode_t **ll_ptr, int data)
{
    llnode_t * n;
    *ll_ptr = (llnode_t*) malloc(sizeof(llnode_t));
    n = *ll_ptr;
    n->data = data;
    n->size = 1;
    n->next = 0;
    n->previous = 0;
    //printf("0x%p\n",n );

    return 0;
}
int ll_destroy (llnode_t *ll_ptr, int data)
{
    return 0;
}

int ll_add     (llnode_t **ll_ptr,  int data)
{
    llnode_t  * ll_p = *ll_ptr;
    llnode_t  * ll_pnext;

    while(ll_p->next)
    {
        ll_p = ll_p->next;
    }
    ll_p->next = (llnode_t*) malloc( sizeof(llnode_t) );

    ll_pnext = (llnode_t*) ll_p->next;
    ll_pnext->next = 0;
    ll_pnext->previous = (void *)ll_p;
    ll_pnext->data = data;

    return 0;

}
int ll_remove(llnode_t *ll_ptr)
{
    llnode_t  * ll_p = ll_ptr;
    llnode_t  * ll_pv;

    while(ll_p->next)
    {
        ll_p++;
    }
    ll_pv = ll_p->previous;
    ll_pv->next = 0;

    free(ll_p);
    return 0;
}

int ll_print(llnode_t **ll_ptr)
{
    llnode_t  * ll_p = *ll_ptr;

    //printf("0x%p\n",*ll_ptr );

    while(ll_p)
    {
        printf("-->%" PRIu32, ll_p->data);
        ll_p = ll_p->next;
    }
    printf("\n");
}

