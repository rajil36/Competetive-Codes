#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int value;
    Node* next;
};

Node* createNode(int value){
    Node* tmp = new(Node);
    tmp->value = value;
    tmp->next = NULL;
    return tmp;
}

Node* addNode(int value, Node* head){
    Node* tmp = createNode(value);
    tmp->next = head;
    return tmp;
}

Node* reverseUtil(Node* head, int k, Node* previous){
    int count = 0;
    Node *prev= NULL, *curr =head, *next = head->next;
    while(curr!=NULL && count<k){
        curr->next = prev;
        prev = curr;
        curr = next;
        if(next!=NULL)
            next = next->next;
        count++;
    }
    head->next = curr;
    previous->next = prev;
    return head;
}

void reverse(Node* head, int k){
    Node* temp = head;
    while(temp->next!=NULL){
        temp = reverseUtil(temp->next, k, temp);
    }
}

void printList(Node* head){
    while(head!=NULL){
        cout<<head->value<<" ";
        head = head->next;
    }
    cout<<endl;
}

int main(){
    Node* head = new(Node);
    head = NULL;
    for (int i = 2; i <= 8; i++)
    {
        head = addNode(i,head);
    }
    printList(head);
    int k = 4;
    int count = 0;
    Node *prev= NULL, *curr =head, *next = head->next;
    while(curr!=NULL && count<k){
        curr->next = prev;
        prev = curr;
        curr = next;
        if(next!=NULL)
            next = next->next;
        count++;
    }
    head->next = curr;
    Node* previous = head;
    head = prev;
    reverse(previous,k);
    printList(head);
    return 0;
}
