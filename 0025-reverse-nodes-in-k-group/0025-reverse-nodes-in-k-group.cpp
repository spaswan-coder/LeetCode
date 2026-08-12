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
    ListNode* getkthnode(ListNode* temp,int k){
        k-=1;
        while(temp!=NULL && k>0){
            k--;
            temp=temp->next;
        }
        return temp;
    }
    ListNode* reverseLL(ListNode* head){
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr!=NULL){
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* prev=NULL;
        while(temp!=NULL){
            ListNode* kthnode=getkthnode(temp,k);
            if(kthnode==NULL){
                if(prev) prev->next=temp;
                break;
            }
            ListNode* nextnode=kthnode->next;
            kthnode->next=NULL;
            reverseLL(temp);
            if (temp==head){
                head=kthnode;
            }else{
                prev->next=kthnode;
            }
            prev=temp;
            temp=nextnode;
        }
        return head;
        
    }
};