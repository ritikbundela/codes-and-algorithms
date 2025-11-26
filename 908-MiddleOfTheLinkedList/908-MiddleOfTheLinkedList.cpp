// Last updated: 26/11/2025, 22:31:25
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
    ListNode* middleNode(ListNode* head) {
       ListNode* curr = head;
        ListNode* next = curr;
        while(next and next->next)
        {
            curr = curr->next;
            next = next->next->next;
        }
        return curr;
    }
};