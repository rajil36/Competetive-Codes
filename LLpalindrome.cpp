#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* createNode(int value)
{
    Node* tmp = new(Node);
    tmp->data = value;
    tmp->next = NULL;
    return tmp;
}

Node* insertNode(int value, Node* head)
{
    if(head == NULL){
        head->data = value;
        head->next = NULL;
    }
    else{
        Node* tmp = createNode(value);
        tmp->next = head;
        head = tmp;
    }
    return head;
}

void print(Node* head){
    while(head->next !=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    return;
}


int main()
{
    Node* head = new(Node);
    for (int i = 2; i <= 8; i+=2)
    {
        head = insertNode(i,head);
    }
    for (int i = 6; i > 0; i-=2)
    {
        head = insertNode(i,head);
    }
    print(head);

    stack<int> s;
    Node* tmp = head;
    while(tmp->next!=NULL){
        s.push(tmp->data);
        tmp = tmp->next;
    }
    tmp = head;
    bool flag = true;
    while (tmp->next!=NULL)
    {
        int value = s.top();
        s.pop();
        if(tmp->data!= value){
            flag = false;
            break;
        }
        tmp = tmp->next;
    }
    if(flag)
        cout<<"\n List is Palindrome\n";
    else
        cout<<"\n List is not Palindrome\n";
return 0;
}