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
    int getLength(ListNode* head){
        
        ListNode*temp = head;
        int length = 0;

        while(temp != 0){
            length++;
            temp = temp -> next;
        }
        return length;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next) return head;

        int length = getLength(head);
        k = k%length;
         if(k == 0) return head;

        int position = length-k;
        int count = 0;
        ListNode*prev = 0;
        ListNode*curr = head;

        while(count < position){
            ListNode*frwd = curr -> next;
            prev = curr;
            curr = frwd;
            count++;
        }
        prev -> next = 0;
        ListNode*newHead = curr;
        while(curr -> next != 0){
            curr = curr -> next;
        }

        curr -> next = head;
        return newHead;
    }
};