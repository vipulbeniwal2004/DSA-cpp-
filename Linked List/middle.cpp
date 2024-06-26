#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int a){
        data = a;
        next = NULL;
    }
};

// int middle(Node *head){
//     if(head==NULL) return -1;
//     int a=1;
//     Node *ptr = head;
//     while(ptr->next != NULL){
//         a++;
//         ptr=ptr->next;
//     }
//     int mid = a/2+1;
//     Node *ans = head;
//     for(int i=1; i<mid; i++){
//         ans=ans->next;
//     }
//     return ans->data;
// }

int middle(Node *head){
    if(head == NULL) return -1;
    Node *slow = head;
    Node *fast = head;
    while(fast != NULL and fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}

int main(){
    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *forth = new Node(40);
    head->next = second;
    second->next = third;
    third->next = forth;
    int ans = middle(head);
    cout<<ans<<endl;
    return 0;
}