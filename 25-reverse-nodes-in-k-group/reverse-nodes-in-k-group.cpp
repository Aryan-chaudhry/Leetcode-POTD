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
    private:
    int getLength(ListNode* head){
        int length =0;
        ListNode*temp = head;
        while(temp != NULL){
            temp = temp -> next;
            length++;
        }
        return length;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // base case 
        int length = getLength(head);

        if(head == NULL || k > length){
            return head;
        }

        // ek case solve karlo
        ListNode*curr = head;
        ListNode*prev = NULL;
        int count = 0;
    
        

        while(curr != NULL && count < k ){
            ListNode*next = curr -> next;
            curr -> next = prev ;
            prev = curr;
            curr = next;
            count++;
        }


        // bake recursion sambhal lega

        if(curr  != NULL ){
            head -> next = reverseKGroup(curr , k);
        }

        // return head of the reverse linked list
        return prev;
    }
};