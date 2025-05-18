#include<bits/stdc++.h>
using namespace std;
struct ListNode{int val;ListNode*next;ListNode(int x):val(x),next(nullptr){}};
class Solution{public:
ListNode* mergeKLists(vector<ListNode*>&lists){
    auto cmp=[](ListNode*a,ListNode*b){return a->val>b->val;};
    priority_queue<ListNode*,vector<ListNode*>,decltype(cmp)>pq(cmp);
    for(auto l:lists)if(l)pq.push(l);
    ListNode dummy(0);ListNode*cur=&dummy;
    while(!pq.empty()){auto node=pq.top();pq.pop();cur->next=node;cur=cur->next;if(node->next)pq.push(node->next);}
    return dummy.next;
}};
int main(){return 0;}
