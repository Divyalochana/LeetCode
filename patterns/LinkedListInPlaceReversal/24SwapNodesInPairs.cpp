// Given the head of a singly linked list and two integers left and right where left <= right,
//  reverse the nodes of the list from position left to position right, and return the reversed list.

#include<iostream>
#include <stack>

struct node{
    int data;
    struct node *next;  
}*first;

void display (struct node *n) {
    while (n != NULL) {
        std::cout << n->data << " -> ";
        n=n->next;
    }
    std::cout << "NULL";
}

void insert (struct node *n) {
    int val=8;
    for (int i=1; i<6; i++) {
        struct node *temp = new node;
        temp->data = val++;
        temp->next = NULL;
        n->next = temp;
        n=temp;
    }
}

void swapNodes(struct node *n){
    node *curr, *dummyNode, *nextNode, *prev;
    curr = n;
    dummyNode = new node;
    dummyNode->next = n;

    prev = dummyNode;

    while(curr != nullptr && curr->next!=nullptr){
        nextNode = curr->next;
        curr->next = nextNode->next;
        nextNode->next = curr;

        prev->next = nextNode;

        prev = curr;
        curr = curr->next;
    }
}

int main(){
    struct node  *last;
    first = new node;

    //first Node creation
    first->data = 6;
    first->next = NULL;
    last = first;

    insert(last);
    display(first);

std::cout << std::endl << "----------------" << std::endl;
    swapNodes(first);
    display(first);

    return 0;
}