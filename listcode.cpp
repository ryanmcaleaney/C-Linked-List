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
        createHead(data);//if there isn't a head create a new head
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

int list::getLength(){//gets length of list
    node* heed = this->head;//sets traversal node
    int counter = 0;//makes counter 0
    while(heed != NULL){
        heed = heed->next;
        counter+=1;//increments counter


    }

    return counter;//returns final counter value
}

void list::sortList(){//sorts list data smallest to biggest
    node* heed = this->head;//sets traversal node
    int temp;//temporary variable to make swap
    int counter = 0;//counter to check when the whole list has been done

    while(counter < this->getLength()){//if the counter is less than the length of the list keep looping
        while(heed->next != NULL){//if the traversal variable next is null exit loop
            if(heed->getData() > heed->next->getData()){//if head is greater than the next node
                
                temp = heed->getData();//temp = the heed data
                heed->setData(heed->next->getData());//heed = nexts data
                heed->next->setData(temp);//heed = temp data

            }
            heed = heed->next;//traversal
        }
    heed = this->head;//resets traversal variable to the start to loop again
    counter+=1;//increments counter
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
