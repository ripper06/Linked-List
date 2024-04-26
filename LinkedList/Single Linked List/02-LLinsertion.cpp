#include<bits/stdc++.h>
using namespace std;
class node {
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

node* LLinsertionHEAD(node* head, int val){
    node* temp = new node(val);
    temp->next = head;
    return temp;
};
 
node* LLinsertionTAIL(node* head, int val){
    node* temp = head;
    node* tail = new node(val);

    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = tail;
    return head;
}

node* LLinsertionRANDOM(node* head,int k,int val){
    if(head == NULL){
        if(k==1) return new node(val);
        else return NULL;
    }
    if(k==1){
        node* temp = new node(val);
        temp->next = head;
        return temp;
    }

    int cnt = 0;
    node* temp = head;
    while(temp != NULL){
        cnt++;
        if(cnt == k-1){
            node* newNode = new node(val);
            newNode->next = temp->next;
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
        return head;
}

node* LLinsertionRANDOMVALUE(node* head,int k,int val){
    if(head == NULL){
      return NULL;
    }
    if(head->data==val){
        node* temp = new node(val);
        temp->next = head;
        return temp;
    }

    node* temp = head;
    while(temp->next != NULL){
    
        if(temp->next->data ==  val){
            node* newNode = new node(val);
            newNode->next = temp->next;
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
        return head;
}

int main(){
     vector<int>arr = {2,5,8,7,9,14};
     node* head = convertARRtoLL(arr);

//Insertion at HEAD

     node* temp = LLinsertionHEAD(head,16);
     
     node* head1 = new node(100);
     head1->next = temp;

     node* temp1 = head1;

     while(temp1){
       cout<<temp1->data<<" ";
       temp1 = temp1->next;
     }   

//Insertion at END

     cout<<"\n Insertion at end: ";
     node* x = LLinsertionTAIL(head,225); 
     node* y =x;
     while(y){
        cout<<y->data<<" ";
        y = y->next;
     }

//Insertion at Random Position

    cout<<"\nInsertion at random position: ";
     node* p = LLinsertionRANDOM(head,4,59); 
     node* q =p;
     while(q){
        cout<<q->data<<" ";
        q = q->next;
     }

//Insertion before a given Value

     cout<<"\n Insertion before a random value: ";
     p = LLinsertionRANDOMVALUE(head,8,59); 
     q =p;
     while(q){
        cout<<q->data<<" ";
        q = q->next;
     }
}