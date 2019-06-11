#include <iostream>
#include "listcode.hpp"

using namespace std;

int main(){

    list *l = new list;;//creates a new list
    for(int i = 0; i < 20; i++){
        l->prependList(i);
    }
    l->sortList();
    l->printList();
    free(l);

    return 0;

}