#include <iostream>
#include "listcode.hpp"

using namespace std;

int main(){

    list *l = new list;;//creates a new list
    l->createHead(0);
    l->addNode(1);
    l->addNode(3);
    l->pop();
    l->printList();
    free(l);

    return 0;

}