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

    ll_add(&node, 40);
    ll_print(&node);

    ll_add(&node, 50);
    ll_print(&node);

    ll_add(&node, 60);
    ll_print(&node);

    ll_add(&node, 70);
    ll_print(&node);

    while(ll_remove(&node) >=0)
    {
        ll_print(&node);
    }

    printf("%s\n", "Done.");
    return 0;
}
