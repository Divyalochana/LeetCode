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

node* reverseLinks(node *curr, int cnt, int right){
    node *head, *prev, *p;
    head = p = curr;
    prev=NULL;

    while(cnt <= right && curr!=nullptr){
        curr = curr->next;
        p->next = prev;
        prev = p;
        p = curr;
        cnt++;
    }

    if(curr != nullptr){head->next = curr;}
    return prev;
}

void reverse2(struct node *n, int left, int right){
    int cnt =1;
    node *curr = n;
    while(cnt<left-1){
        curr = curr->next;
        cnt++;
    } 
    node *start = curr;
    std::cout << "startNode: " << curr->next->data << std::endl;
    std::cout << "cnt: " << cnt << std::endl;
    if(left == 1){
        first = reverseLinks(curr, cnt, right);
    }else{
        start->next = reverseLinks(curr->next, cnt+1, right);
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
    reverse2(first, 1, 1);
    display(first);

    return 0;
}