#include <iostream>
#include "listcode.hpp"

using namespace std;

int main(){

    list *l = new list;;//creates a new list
    l->createHead(2);
    l->addNode(1);
    l->addNode(4);
    l->addNode(3);
    l->sortList();
    l->printList();
    free(l);

    return 0;

}