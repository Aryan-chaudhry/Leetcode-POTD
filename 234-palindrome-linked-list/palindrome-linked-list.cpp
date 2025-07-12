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
        int length = 0;
        ListNode*temp = head;

        while(temp != 0){
            length++;
            temp = temp -> next;
        }
        return length;
    }

    ListNode* findMid(ListNode*&head){
        if(!head) return 0;

        ListNode*slow = head;
        ListNode*fast = head;

        while(fast != 0){
            fast = fast -> next;
            if(fast != 0){
                fast = fast -> next;
                slow = slow -> next;
            }
        }
        return slow;
    }

   

    bool compare(ListNode*&head, ListNode*&prev, ListNode*&curr){
        
        while(prev != 0 && curr != 0){
            if(prev -> val != curr -> val) return false;
            prev = prev -> next;
            curr = curr -> next;
        }
        return true;
    }

    bool isPalindrome(ListNode* head) {
        if(head -> next == 0) return true; // ek hi node hai to vo palindrome hoi

        // step 1 --> find the length of linkedlist
        int length = getLength(head);

        // step 2 --> find mid Node
        ListNode*mid = findMid(head);

        // step 3 --> reverse the first half of the node
        
        ListNode*prev = 0;
        ListNode*curr = head;
        
        while(curr != mid){
            ListNode*frwd = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = frwd;
        }

        // step 4 --> check karo length of linkedlist and get your ans
        // agar even hai to curr se hi compare karte chalange
        // agar odd hai to ek node extra hai to curr ko ek node aage move kardo
        if(length&1) curr = curr -> next; // odd length thi aage move kar gaye
        
        bool ans = compare(head, prev, curr);
        return ans;
    }
};