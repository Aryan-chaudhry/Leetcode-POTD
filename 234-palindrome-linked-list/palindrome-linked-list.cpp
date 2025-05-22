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
    int getLength(ListNode*&head){
        ListNode*temp = head;
        int length = 0;

        while(temp != 0){
            length++;
            temp = temp -> next;
        }
        return length;
    }

    ListNode* getMid(ListNode*&fast, ListNode*&slow){
        while(fast != 0){
            fast = fast -> next;
            if(fast != 0){
                fast = fast -> next;
                slow = slow -> next;
            }
        }
        return slow;
    }

    bool isPalindrome(ListNode* head) {
        if(head -> next == 0){
            return true;
        }
        int length = getLength(head);

        ListNode*fast = head;
        ListNode*slow = head;
        ListNode*mid = getMid(fast, slow);

        ListNode*prev = 0;
        ListNode*curr = head;

        while(curr != mid){
           ListNode*frwd = curr -> next;
           curr -> next = prev;
           prev = curr;
           curr = frwd; 
        }

        if(length&1) curr = curr -> next; // odd
        
        while(prev != 0 && curr != 0){
            if(prev -> val != curr -> val){
                return false;
            }
            prev = prev -> next;
            curr = curr -> next;
        }
        return true;
    }
};