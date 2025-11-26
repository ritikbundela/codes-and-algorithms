// Last updated: 26/11/2025, 22:32:34
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
    bool isPalindrome(ListNode* head) {
        if(head == NULL|| head->next == NULL)
        return true;
        ListNode* slow = head;
        ListNode* fast = head;
        vector<int>v;
        while(fast and fast->next){
            v.push_back(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast != NULL) 
        slow = slow->next;
        int n = v.size()-1;
        while(slow){
            if(slow->val != v[n--])
            return false;
            slow = slow->next;
        }
        return true;
    }
};