#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* next;

    public:
    node(int data1){//constructor
        data = data1;
        next = nullptr;
    }

};
typedef node SL;
int main(){
  vector<int> arr = {2,5,8,7};

  SL* y = new SL{arr[0]};

  cout<<y;

  return 0;
}