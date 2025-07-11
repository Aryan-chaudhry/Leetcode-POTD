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
    ListNode* findMiddle(ListNode*&head){
        if(!head) return 0;
        ListNode*prev = head;
        ListNode*frwd = head;

        while(frwd != 0){
            frwd = frwd -> next;
            if(frwd != 0){
                frwd = frwd -> next;
                prev = prev -> next;
            }
        }
        return prev;
    }
    ListNode* deleteMiddle(ListNode* head) {
        if(!head || !head -> next) return 0;
        ListNode*middle = findMiddle(head);
        ListNode*temp = head;

        while(temp -> next != middle){
            temp = temp -> next;
        }

        temp -> next = middle -> next;
        middle -> next = 0;
        delete(middle);

        return head;
    }
};