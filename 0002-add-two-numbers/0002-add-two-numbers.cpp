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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
     ListNode *temp1=l1;
        ListNode *temp2=l2;
        ListNode *dummyHead=new ListNode(-1);
        ListNode *dummyNode=dummyHead;   
        int carry=0;
        while(temp1 || temp2){
            int sum=0;
            if(temp1){
                sum+=temp1->val;
                temp1=temp1->next;
            }
            if(temp2){
                sum+=temp2->val;
                 temp2=temp2->next;
            }
            sum+=carry;
            dummyNode->next=new ListNode (sum%10);
            carry=sum/10;
            dummyNode=dummyNode->next;
        }
        if(carry!=0)dummyNode->next=new ListNode(carry);
        return dummyHead->next;
    }
};