// Last updated: 26/11/2025, 22:33:21
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
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) {
        return NULL;
    }

    ListNode* slow = head;
    ListNode* fast = head;

    // Phase 1: Determine if there is a cycle
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            // Cycle detected
            break;
        }
    }

    // If no cycle was detected
    if (fast == NULL || fast->next == NULL) {
        return NULL;
    }

    // Phase 2: Find the start of the cycle
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow; 
    }
};