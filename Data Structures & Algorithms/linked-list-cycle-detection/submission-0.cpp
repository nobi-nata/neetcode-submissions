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
    bool hasCycle(ListNode* head) {
        if(!head) return false;
        if(!head->next) return false;

        ListNode* fast = head, * slow = head;

        do{
            if(!fast->next || !fast->next->next) return false;
            if(fast->next && fast->next->next){
                fast = fast->next->next;
            }
            if(slow->next){
                slow = slow->next;
            }
        }while((fast != slow));
        if(fast == slow) return true;
        return false;
    }
};
