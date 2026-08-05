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
        vector<ListNode *> lis;
        while(head){
            lis.push_back(head);
            head = head->next;
        }
        int n = lis.size();
        int i = 1; 
        int j = n-1;
        ListNode* prev = nullptr;
        head = lis[0];
        prev = head;
        while(i <= j){
            prev->next = lis[j];
            j--;
            prev = prev->next;
            if(i <= j){
                prev->next = lis[i];
                prev = prev->next;
                i++;
            }
        }
        prev->next = NULL;
    }
};
