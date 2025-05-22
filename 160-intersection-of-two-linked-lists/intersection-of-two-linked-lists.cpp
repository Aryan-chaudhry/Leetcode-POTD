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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*, bool>mp;
        ListNode*temp1 = headA;
        ListNode*temp2 = headB;

        while(temp1 != NULL){
            ListNode*insert = temp1;
            temp1 = insert -> next;
            mp[insert] = true;
        }

        while(temp2 != NULL){
            ListNode*insert = temp2;
            temp2 = insert -> next;

            if(mp.find(insert) != mp.end()){
                if(mp[insert] == true){
                    return insert;
                }
            }
        }
        return nullptr;
    }
};