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

//Delete head

 node* deleteHeadDL(node* head){
    if( head==NULL || head->next == NULL) return head;

    node* prev = head;
    head = head->next;
    head->back = NULL;
   
    delete(prev);

    return head;
 }

 //Delete Tail

 node* deleteTailDL(node* head){
    if(head == NULL || head->next == NULL) return head;

    node* tail = head;
    while(tail->next != NULL){
        tail = tail->next;
                             }
        node* newTail = tail->back;
        newTail->next = NULL;
        tail->back = NULL;
       
        delete tail;

        return head;
 }

 //Delete nth position

 node* deleteanypositionDL(node* head, int k){
    if(head == NULL)return NULL;

    int cnt=0;
    node* knode = head;

    while(knode != NULL){
        cnt++;
        if(cnt==k) {break;}
        knode = knode->next;
    }
    node* prev = knode->back;
    node* front = knode->next;

    if(prev == NULL && front == NULL) return NULL;
    else if(prev == NULL){
        return deleteHeadDL(head);
    }
    else if(front == NULL){
        return deleteTailDL(head);
    }

    prev->next = front;
    front->back = prev;

    knode->next = NULL;
    knode->back = NULL;

    delete knode ;

    return head;

 }



//Printing function

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

    head = deleteHeadDL(head);
    print(head);

     cout<<endl;

    head = deleteTailDL(head);
    print(head);

     cout<<endl;

    head = deleteanypositionDL(head,4);
    print(head);


    return 0;
}