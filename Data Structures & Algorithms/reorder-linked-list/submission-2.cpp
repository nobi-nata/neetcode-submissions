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
    

    void reorderList(ListNode* head) {
        if(!head->next) return;
        ListNode* fast = head, * slow = head, *prev = nullptr;
        while(fast && fast->next){
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        if(prev) prev->next = nullptr;

        
        ListNode* curr = slow;
        prev = nullptr;

        while(curr){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        ListNode* head2 = prev;
        ListNode* head1 = head;

        while(head1 && head2){
            ListNode* n1 = head1->next;
            ListNode* n2 = head2->next;
            head1->next = head2;
            if(n1) head2->next = n1;
            head1 = n1;
            head2 = n2;
        }

    }
};
