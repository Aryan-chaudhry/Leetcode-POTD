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
        unordered_map<ListNode*,bool>mp;
        ListNode*temp = head;

        while(temp != 0){
            ListNode*node = temp;
            if(mp.find(node) != mp.end()){
                if(mp[node] == true){
                    return true;
                }
            }
            mp[node] = true;
            temp = temp -> next;
        }
        return false;
    }
};