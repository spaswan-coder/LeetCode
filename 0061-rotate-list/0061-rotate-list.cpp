/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* findnthnode(ListNode *temp,int k){
    int cnt=1;
    while(temp!=NULL){
    if(cnt==k) return temp;
        cnt+=1;
        temp=temp->next;
    }
    return temp;
    }
    ListNode* rotateRight(ListNode* head, int k) {
       
        int len=1;
        ListNode* tail=head;
        if(head==NULL || k==0) return head;
        while(tail->next!=NULL){
            len+=1;
            tail=tail->next;
        }
        if(k%len==0) return head;
        k=k%len;
        tail->next=head;
        ListNode* newLastnode=findnthnode(head,len-k);
        head=newLastnode->next;
        newLastnode->next=NULL;
        return head;

        
    }
};