// Last updated: 26/11/2025, 22:34:58
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      ListNode* ans = new ListNode(-1);
      ListNode* current = ans;
      int sum, carry = 0;

      while (l1 != NULL || l2 != NULL || carry) {
        int sum = carry;  

        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10;
        sum = sum % 10;

        current->next = new ListNode(sum);
        current = current->next;
    }
      return ans->next; 
    }
};