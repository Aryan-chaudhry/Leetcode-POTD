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
    bool hasCycle(ListNode *head) {
        if(!head) return false;
        ListNode*rabbit = head;
        ListNode*tortoise = head;

        while(rabbit != 0){
            rabbit = rabbit -> next;
            if(rabbit != 0){
                rabbit = rabbit -> next;
                tortoise = tortoise -> next;

                if(rabbit == tortoise) return true;
            }
        }
        return false;
    }
};