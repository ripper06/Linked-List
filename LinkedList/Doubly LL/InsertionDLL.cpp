
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

void print(node* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}

//Insert at beginning

node* insertionAtBeginning(node* head, int val){
     node* temp = new node(val,head,NULL);
     head->back = temp;

     return temp;
}

//Insert at tail

node* insertionAtTail(node* head, int val){

    if(head==NULL) return new node(val);

    node* temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }
    node* newTail = new node(val,NULL,temp);
    temp->next = newTail;

    return head;
}

//Insert at any given position

node*  insertAtanyPos(node* head,int val, int k){
    if(k==1) return insertionAtBeginning(head,val);

    int cnt = 1;
    node* temp = head;
    while(temp->next != NULL){
        cnt++;
        if(cnt==k){
            temp = temp->next;
            break;
        }
       temp = temp->next;
    }

    node* prev = temp->back;
    node* front = temp->next;
    
    if(front == NULL) return insertionAtTail(head,val);
    node* newNode = new node(val,temp,prev);
    temp->back = newNode;
    prev->next = newNode;

    return head;

}

int main(){
    vector<int>arr={1,5,8,9,4,5,9,4};
    node* head = convertArraytoDLL(arr,arr.size());

    cout<<"\nInsertion at beginning"<<endl;
    head = insertionAtBeginning(head,15);
    print(head);
    
    cout<<"\nInsertion at Tail"<<endl;
    head = insertionAtTail(head,25);
    print(head);
    cout<<endl;

     cout<<"\nInsertion at any given position"<<endl;
     head = insertAtanyPos(head,35,10);
     print(head);
    
    return 0;
}