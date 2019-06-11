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

    if(this->head == NULL){//checks if there is a head
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

void list::pop(){//removes end of the list
    node* heed = this->head;
    node* temp;
    while(heed != NULL){
        if(heed->next == NULL){
            temp->next = NULL;
            free(heed);
            break;
        }
        temp = heed;
        heed = heed->next;
    }
}

void list::insertByKey(int key, int data){//inserts element after a given element

    node* newNode = createNode(data);//Creates new node to be inserted
    node* heed = this->head;//assigns a node for traversal
    while(heed != NULL){//loops till NULL
        if(heed->getData() == key){//if the data is = to the key
            newNode->next = heed->next;//make newnode link to the node in front of the traversal node
            heed->next = newNode;//linkes the current node to the new node in front of it
            break;//break from the loop
        }else if(heed->next == NULL){//if no key is found, tell
            std::cout << "Key not found" << std::endl;
        }

        heed = heed->next;//traverses list

    }

}

void list::removeByKey(int key){//removes list element by key
    node* temp;
    node* aheed;
    node* heed = this->head;
    while(heed != NULL){//while head is not equal to null loop
        if(heed->getData() == key){//if the key is found
            if(heed == this->head){//if the current node is the header node
                this->head = heed->next;//set head to the node after
                free(heed);//free deleted node
            }else if(heed->next == NULL){//if it's the final element in the array
                temp->next = NULL;//set the previous node.next to NULL
                free(heed);//free deleted node

            }else{
                temp->next = aheed;//link the previous node to the after node
                free(heed);//free current node
            }
            
            break;//break from loop
        }
        temp = heed;
        heed = heed->next;
        aheed = heed->next;
    }

}

int list::getLength(){
    node* heed = this->head;
    int counter = 0;
    while(heed != NULL){
        heed = heed->next;
        counter+=1;


    }

    return counter;
}

void list::sortList(){
    node* heed = this->head;
    int temp;
    int counter = 0;

    while(counter < this->getLength()){
        while(heed->next != NULL){
            if(heed->getData() > heed->next->getData()){
                
                temp = heed->getData();
                heed->setData(heed->next->getData());
                heed->next->setData(temp);

            }
            heed = heed->next;
        }
    heed = this->head;
    counter+=1;
}
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
