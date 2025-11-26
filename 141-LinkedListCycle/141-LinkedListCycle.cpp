// Last updated: 26/11/2025, 22:33:23
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
        if(head == NULL || head->next == NULL)
        return false;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(slow != NULL){
            if(slow == fast)
            return true;
            slow = slow->next;
            if(fast->next == NULL|| fast->next->next == NULL)
            return false;
            fast = fast->next->next;
        }
        return false;
    }
};