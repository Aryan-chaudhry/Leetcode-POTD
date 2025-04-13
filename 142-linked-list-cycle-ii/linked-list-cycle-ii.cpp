/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* hasCycle(ListNode*&head){
        ListNode*fast = head;
        ListNode*slow = head;

        while(fast != NULL){
            fast = fast -> next;
            if(fast != NULL){
                fast = fast -> next;
                slow = slow -> next;

                if(fast == slow){
                    return fast;
                }
            }
        }
        return nullptr;
    }

    ListNode *detectCycle(ListNode *head) {
        ListNode*fast = hasCycle(head);
        if(!fast) return nullptr;
        
        ListNode*slow = head;

        while(slow != fast){
            slow = slow -> next;
            fast = fast -> next;
        }
        return slow;
    }
};