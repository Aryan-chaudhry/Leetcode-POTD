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
        ListNode*temp1 = l1;
        ListNode*temp2 = l2;

        ListNode*node = new ListNode(-1);
        ListNode*track = node;

        int carry = 0;

        while(temp1 != NULL || temp2 != NULL || carry){
            int a = temp1 ? temp1 -> val : 0;
            int b = temp2 ? temp2 -> val : 0;
            int sum = a + b + carry;
            
            int digit = sum%10;
            carry = sum/10;

            ListNode*insert = new ListNode(digit);
            track -> next = insert;
            track = insert;

            temp1 = temp1 ? temp1 -> next : nullptr;
            temp2 = temp2 ? temp2 -> next : nullptr;
        }

        return node -> next;
    }
};