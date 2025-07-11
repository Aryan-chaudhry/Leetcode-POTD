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
    ListNode* solve(ListNode*&prev, ListNode*&curr){
        // base case
        if(!curr) return prev;

        // ek case me solve karunga
        ListNode*frwd = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = frwd;

        return solve(prev, curr);
    }
    ListNode* reverseList(ListNode* head) {
        if(!head) return 0;
        ListNode*prev = 0;
        ListNode*curr = head;

        ListNode*ans = solve(prev,curr);
        return ans;
    }
};