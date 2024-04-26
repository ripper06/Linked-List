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

 int getDecimalValue(node* head) {
        node* temp = head;
        int num=0,i=0;
        int arr[30];

        while(temp){
            arr[i] = temp->data;
            i++;
            temp=temp->next;
        }
       int cnt = i-1;
       cout<<cnt<<endl;
        for(int j = 0; j<i; j++){
                num += arr[j]*pow(2,cnt);
                cnt--;
        }
        return num;
    }

int main(){
    vector<int>arr = {1,0,1};
    node* head = convertARRtoLL(arr);
    int val = getDecimalValue(head);
    cout<<val<<" ";
}