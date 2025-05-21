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
    ListNode* reverseList(ListNode* head) {
        if(!head) return nullptr;
        ListNode*prev = 0;
        ListNode*curr = head;

        while(curr != 0){
            ListNode*frwd = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = frwd;
        }
        return prev;
    }
};