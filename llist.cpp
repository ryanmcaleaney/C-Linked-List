#include <iostream>
#include "listcode.hpp"

using namespace std;

int main(){

    list l;//creates a new list
    l.createHead(2);
    l.addNode(14);
    l.prependList(200);
    l.printList();

    return 0;

}