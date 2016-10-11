#include "linkedlist.h"

int main(int argc, char **argv)
{

    llnode_t *node;

    ll_new(&node, 10);
    ll_print(&node);

    ll_add(&node, 20);
    ll_print(&node);

    ll_add(&node, 30);
    ll_print(&node);


    return 0;
}
