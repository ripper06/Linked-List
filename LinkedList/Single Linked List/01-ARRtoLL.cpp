#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;

    public:
    node(int data1){
        data = data1;
        next = nullptr;
    }

};

node* convertARRtoLL(vector<int>&arr){
    node* head = new node(arr[0]);
    node* mover = head;

    for(int i=1; i<arr.size(); i++){
        node* temp = new node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

int main(){
    vector<int>arr = {2,5,8,7};
    node* head = convertARRtoLL(arr);

    while(head->next != NULL){
    cout<<head->data<<" ";
    head = head->next;
    }
}