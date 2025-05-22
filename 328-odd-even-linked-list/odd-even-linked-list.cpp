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
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return 0;

        ListNode*odd = new ListNode(-1);
        ListNode*oddtemp = odd;

        ListNode*even = new ListNode(-1);
        ListNode*eventemp = even;

        int index = 1;
        ListNode*temp = head;

        while(temp != 0){
            ListNode*insert = temp;
            temp = temp -> next;
            insert -> next = 0;
            if(index&1){
                // odd
                oddtemp -> next = insert;
                oddtemp = oddtemp -> next;
            }
            else{
                // even
                eventemp -> next = insert;
                eventemp = eventemp -> next;
            }
            index++;
        }
        oddtemp -> next  = even -> next;
        even -> next = 0; // completely optional
        eventemp -> next = 0;

        return odd -> next;
    }
};