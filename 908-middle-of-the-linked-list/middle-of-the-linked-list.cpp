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
    int getLength(ListNode* &head){
        ListNode*temp = head;
        int length = 0;

        while(temp != 0){
            length++;
            temp = temp -> next;
        }
        return length;
    }

    ListNode* middleNode(ListNode* head) {
        int length = getLength(head);
        int position = length/2 + 1;
        int track = 1;
        ListNode*temp = head;

        while(track != position){
            temp = temp -> next;
            track++;
        }
        return temp;
    }
};