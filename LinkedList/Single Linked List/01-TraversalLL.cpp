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

node* TraversalLL(node* head){
 node* temp = head;

      while(temp){
        cout<< temp->data<<" ";
        temp = temp->next;
      }
}

node* lengthLL(node* head){
    node* temp = head;
    int cnt=0;
    while(temp){
        cnt ++;
        temp=temp->next;
    }
    cout<<"\nLength: "<<cnt;
}

int searchLL(node* head, int k){
    node* temp = head;
    
    while(temp){
        if(temp->data == k) return 1;
        temp = temp->next;
    }
    return 0;
}

int main(){
    vector<int>arr = {2,5,8,7};
    node* head = convertARRtoLL(arr);

    TraversalLL(head);

    lengthLL(head);

    cout<<endl<<searchLL(head,9);

  return 0; 
}