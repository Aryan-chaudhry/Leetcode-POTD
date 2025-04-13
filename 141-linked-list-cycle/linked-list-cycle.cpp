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
        ListNode*temp = head;

        unordered_map<ListNode*, bool>mp;

        while(temp != NULL){
            if(mp[temp] == true){
                return true;
            }
            mp[temp] = true;

            temp = temp -> next;
        }
        return false;
    }
};