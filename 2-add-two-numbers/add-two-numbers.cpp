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
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;


        ListNode*&temp1 = l1;
        ListNode*&temp2 = l2;
        ListNode*ans = new ListNode(-1);
        ListNode*mynext = ans;
        int carry = 0;
        

        while(temp1 != NULL && temp2 != NULL){
            int sum = temp1->val + temp2 -> val + carry;
            carry = sum/10;
            int digit = sum%10;
            ListNode*node_to_insert = new ListNode(digit);
            mynext -> next = node_to_insert;
            mynext = mynext -> next;
            temp1 = temp1 -> next;
            temp2 = temp2 -> next;
        }

        while(temp1 != NULL){
            int sum = temp1 -> val + carry;
            carry = sum/10;
            int digit = sum%10;
            ListNode*node_to_insert = new ListNode(digit);
            mynext -> next = node_to_insert;
            mynext = mynext -> next;
            temp1 = temp1 -> next;
        }

        while(temp2 != NULL){
            int sum = temp2 -> val + carry;
            carry = sum/10;
            int digit = sum%10;
            ListNode*node_to_insert = new ListNode(digit);
            mynext -> next = node_to_insert;
            mynext = mynext -> next;
            temp2 = temp2 -> next;
        }

        while(carry){
            ListNode*node_to_insert = new ListNode(carry%10);
            carry /= 10;
            mynext -> next = node_to_insert;
            mynext = mynext -> next;
        }

        return ans -> next;
    }
};