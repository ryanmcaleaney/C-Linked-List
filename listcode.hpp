#ifndef LLIST.HPP
#define LLIST.HPP

class node{//node class contains integer data and points to the next node in the list

    public:
        int data;
        node *next; 

};

class list{//list class contains the head variable and the functions to use the list

    public://refer to the file listcode.cpp for comments on these functions
        node* createNode(int data);
        void createHead(int data);
        void addNode(int data);
        void prependList(int data);
        void printList();
    private:
        node *head;

};

#endif