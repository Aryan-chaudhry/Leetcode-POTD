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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return 0;
        if(head -> next == 0) return head;
        
        ListNode*prev = head;
        ListNode*curr = head -> next;

        while(curr != 0){
            if(prev -> val == curr -> val){
                curr = curr -> next;
            }
            else{
                prev -> next = curr;
                // update pointers
                prev = curr;
                curr = curr -> next;
            }
        }
        // jab bahar aaye hai to ho saktra hai ki last ke duplicate 
        // remove na hue ho to unko delete kardo
        prev -> next = curr;

        return head;
    }
};