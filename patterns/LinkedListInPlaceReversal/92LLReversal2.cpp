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

void reverse2(struct node *n, int left, int right){
    struct node* curr = n;
    int cnt = 1;
    std::stack<int> st;
    while(curr != nullptr){
        if((cnt >= left) && (cnt <= right)){
            st.push(curr->data);
        }
        curr = curr->next;
        cnt++;
    }

    curr = n;
    cnt=1;
    while(curr != nullptr){
        if((cnt >= left) && (cnt <= right)){
            curr->data = st.top();
            st.pop();
        }
        curr = curr->next;
        cnt++;
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
    reverse2(first, 2, 4);
    display(first);

    return 0;
}