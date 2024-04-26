#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node* back;
    public:
    node(int data1, node* next1, node* back1){
        data = data1;
        next = next1;
        back = back1;
    }
    public:
    node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }

};

//Function->array to DLL conversion
node* convertArraytoDLL(vector<int>&arr,int n){
    node* head = new node(arr[0]);
    node* prev = head;

    for(int i=1; i<n; i++){
        node* temp = new node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

//Delete Node

node* deleteNodeDLL(node* temp){
   node* front = temp->next;
   node* prev = temp->back;

   if(front == NULL){
      prev->next = NULL;
      temp->next = NULL;
      temp->back = NULL;
      delete temp;
   }

   prev->next = front;
   front->back = prev;

   temp->next = NULL;
   temp->back = NULL;
   delete temp;
}

void print(node* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}

int main(){
    vector<int>arr={1,5,8,9,4,5,9,4};
    node* head = convertArraytoDLL(arr,arr.size());
    print(head);

    cout<<endl;

    deleteNodeDLL(head->next->next);
    print(head);

    cout<<endl;
    
    return 0;
}