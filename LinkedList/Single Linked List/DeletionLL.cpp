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

// node* LLdeletionhead(node* head){
//     if(head == NULL) return head;
//     node* temp = head;
//     head = head->next;
//     delete temp;

//     return head;
// }

// node* LLdeletetail(node* head){
//     if(head==NULL || head->next == NULL) return NULL;
//     node* temp = head;

//     while(temp->next->next != NULL){
//         temp = temp->next;
//     }
//     free(temp->next);

//     temp->next = NULL;
//     return head;
// }


// node* LLdeleterandom(node* head, int n){
//         if(head==NULL ) return head;
        
//         if(n==1){
//             node* temp = head;
//             head = head->next;
//             delete temp;
//             return head;
//         }

//         else if(n==2){
//             node* temp = head->next;
//             head->next = temp->next;
//             delete temp;
//             return head;
//         }

      
//       else{
//         node* temp = head;
//         node* backup=NULL;
//         for(int i=1; i<n-1; i++){
//           temp=temp->next;
//           backup=temp->next;
//         }
//         temp->next = backup->next;
//         delete backup;
//       }
//         return head;
// }



node* LLdeleterandomvalue(node* head, int n){
        if(head==NULL ) return head;
        
        if(head->data==n){
            node* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        else if(head->next->data==n){
            node* temp = head->next;
            head->next = temp->next;
            delete temp;
            return head;
        }

      
      else{
        node* temp = head;
        node* backup=temp->next;
        
        while(backup->data != n){
          temp=backup;
          backup=temp->next;
        }
        temp->next = backup->next;
        delete backup;
      }
        return head;
}

int main(){
     vector<int>arr = {2,5,8,7,9,14};
     node* head = convertARRtoLL(arr);
     

    //  LLdeletionhead(head);
    //  LLdeletetail(head);

    // temp = LLdeleterandom(head,6);

    node* temp = LLdeleterandomvalue(head,14);

   
while(temp){
     cout<<temp->data<<" ";
     temp = temp->next;
}
}