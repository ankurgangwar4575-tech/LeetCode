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
        ListNode *KthNode(ListNode *head,int k){
        ListNode *temp=head;
        int ctr=0;
        while(temp!=nullptr){
            ctr++;
            if(ctr==k) return temp;
            temp=temp->next;
        }
        return NULL;
    }
    ListNode *reverseLL(ListNode *head){
        ListNode *temp=head,*prev=nullptr;
        while(temp!=nullptr){
            ListNode *nextNode=temp->next;
            temp->next=prev;
            prev=temp;
            temp=nextNode;
        }
        return prev;
    }
    ListNode* swapPairs(ListNode* head) {
     ListNode *temp=head,*prev=nullptr;
        while(temp!=nullptr){
            ListNode *KthNodePtr=KthNode(temp,2);
            if(KthNodePtr==NULL){
                if(prev!=nullptr) prev->next=temp;
                break;
            }
            ListNode *front=KthNodePtr->next;
            KthNodePtr->next=NULL;
            ListNode *revHead=reverseLL(temp);
            if(temp==head) head=revHead;
            else prev->next=revHead;
            prev=temp;
            temp=front;
        }
        return head;
    }
};