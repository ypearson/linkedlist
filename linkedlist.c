
#include "linkedlist.h"

// void *malloc(size_t size);
// void free(void *ptr);

static llnode_t * m_linked_list;

int ll_init(llnode_t *ll_ptr_t, int data)
{
    m_linked_list = malloc(sizeof(llnode_t) );
    m_linked_list->data = data;
    m_linked_list->next = 0;
    m_linked_list->previous = 0;

    return 0;
}
int ll_add(llnode_t *ll_ptr_t)
{


    return 0;

}
int ll_remove(llnode_t *ll_ptr_t)
{

    return 0;
}
