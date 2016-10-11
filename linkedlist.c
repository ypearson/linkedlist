
#include "linkedlist.h"

// void *malloc(size_t size);
// void free(void *ptr);

static llnode_t * m_linked_list;

int ll_new (llnode_t *ll_ptr_t, int data)
{
    m_linked_list = malloc(sizeof(llnode_t) );
    m_linked_list->data = data;
    m_linked_list->next = 0;
    m_linked_list->previous = 0;

    return 0;
}
int ll_destroy (llnode_t *ll_ptr_t, int data)
{
    return 0;
}

int ll_add     (llnode_t *ll_ptr_t,  int data)
{
    llnode_t  * ll_p = m_linked_list;
    llnode_t  * ll_pv;

    while(ll_p->next)
    {
        ll_p++;
    }
    ll_p->next = malloc( sizeof(llnode_t) );

    ll_pv = (llnode_t*) ll_p->next;
    ll_pv->next = 0;
    ll_pv->previous = (void *)ll_p;
    ll_pv->data = data;

    return 0;

}
int ll_remove(llnode_t *ll_ptr_t)
{

    return 0;
}
