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
        ListNode*ans = new ListNode(-1);
        ListNode*gonext = ans;
        int carry = 0;

        while(l1 || l2 || carry){
            int a = l1 ? l1->val : 0;
            int b = l2 ? l2 -> val : 0;
            int sum = a + b + carry;
            carry = sum/10;
            int digit = sum%10;
            ListNode* node_to_insert = new ListNode(digit);
            gonext -> next = node_to_insert;
            gonext = gonext -> next;
            l1 = l1 ? l1 -> next : nullptr;
            l2 = l2 ? l2 -> next : nullptr;
        }
    return ans -> next;
    }
};