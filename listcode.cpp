#include <iostream>
#include "listcode.hpp"

node* list::createNode(int data){//creates first node

    node *n = new node;//assigns memory to node
    n->setData(data);//assigns numerical data to node

    return n;//returns the node to variable

}

void list::createHead(int data){

    this->head = createNode(data);//creates the new node and assigns it as thehead node

}

void list::addNode(int data){//adds a new node to the end of the list
    
    node *heed = this->head;//assigns traversal node to head
    node *newNode = createNode(data);//creates newnode as a variable

    if(heed == NULL){//checks if there is a head
        this->createHead(data);//if there isn't a head create a new head
        std::cout << "Head created since not already initialised" << std::endl;//lets the user know a new head was created
    }else{
            if(heed->next == NULL){//if the next node doesn't exist

                heed->next = newNode;//create new node

            }else{
                while(heed->next != NULL){//while the next head is not null
                    heed = heed->next;//go to next node
                    if(heed->next == NULL){//when the next node is null
                        heed->next = newNode;//add new node to the end
                        break;//break from the loop
                    }
                    
                }
            }
        }
}

void list::prependList(int data){//adds a node to the start of the list and makes it the head

    node* newNode = createNode(data);//creates new node
    node* heed = this->head;//creates temp node as head

    newNode->next = heed;//sets the next for newNode to the head
    this->head = newNode;//sets new head to newNode

}

void list::printList(){//prints the list

    node* heed = this->head;//sets traversal node to head
    if(heed != NULL){//if the head is not null
        while(heed != NULL){// while the head is not null

            std::cout << heed->getData() << " -> ";//output the data and an arrow to indicate the pointer
            if(heed->next == NULL)//if the next node is null
                std::cout << "NULL\n";//print null
            heed = heed->next;//traverse the list

        }
    }
}

