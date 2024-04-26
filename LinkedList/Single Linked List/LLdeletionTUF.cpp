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

    node* convertARRtoLL(vector<int>arr){
        node* head = new node(arr[0]);
        node* temp = head;
        for(int i=1; i<arr.size(); i++){
            node* mover = new node(arr[i]);
            temp->next = mover;
            temp = mover;
        }
        return head;
    }

    node* LLdeleterandom(node* head, int n){
        if(head==NULL ) return head;
        
        if(n==1){
            node* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        int cnt =0;
        node* temp = head;
        node* prev = NULL;

        while(temp!=NULL){
            cnt++;
            if(cnt == n){
              prev->next = prev->next->next;
              free(temp);
              break;
            }
            prev = temp;
            temp = temp->next;
        }
        return head;
    }

    int main(){
        vector<int>arr = {2,5,8,7,9,14};
        node* head = convertARRtoLL(arr);
         node* temp = LLdeleterandom(head,1);
   
while(temp){
     cout<<temp->data<<" ";
     temp = temp->next;
}
      }