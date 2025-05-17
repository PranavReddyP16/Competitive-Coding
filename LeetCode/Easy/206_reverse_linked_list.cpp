#include<bits/stdc++.h>
using namespace std;
struct ListNode{int val;ListNode*next;ListNode(int x):val(x),next(nullptr){}};
class Solution{public:
ListNode* reverseList(ListNode*head){
    ListNode*prev=nullptr;
    while(head){ListNode*nxt=head->next;head->next=prev;prev=head;head=nxt;}
    return prev;
}};
int main(){return 0;}
