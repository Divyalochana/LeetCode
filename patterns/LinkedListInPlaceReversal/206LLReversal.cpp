// Given the head of a singly linked list, reverse the list, and return the reversed list.
#include <iostream>

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

void reverse(struct node *n){
    struct node* curr, *j, *prev;
    prev = nullptr;
    curr = j = n;

    while(curr != nullptr){
        curr = curr->next;
        j->next = prev;
        prev = j;
        j = curr;
    }
    first = prev;
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
    reverse(first);
    display(first);

    return 0;
}