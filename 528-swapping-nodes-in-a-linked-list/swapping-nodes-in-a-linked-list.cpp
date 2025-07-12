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
    
    ListNode* swapNodes(ListNode* head, int k) {
        if(head -> next == 0) return head;

        int length = getLength(head);
        
        // make sure the k always in a range
        if(k > length) k = k%length;;

        // find the kth node from begning 
        ListNode* kthBeg = head;
        int count1 = 1;

        while(count1 < k){
            kthBeg = kthBeg -> next;
            count1++;
        }

        // find the kth node from end
        ListNode* kthEnd = head;
        int count2 = 1;

        while(count2 < (length-k+1) ){
            kthEnd = kthEnd -> next;
            count2++;
        }

        // swap the kthnode val from bigning to keth node value from end
        swap(kthBeg ->val, kthEnd -> val);

        // return ans;
        return head;
    }
};