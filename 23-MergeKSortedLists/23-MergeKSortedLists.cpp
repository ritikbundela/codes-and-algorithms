// Last updated: 26/11/2025, 22:34:41
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
 // Custom comparator for the priority queue to create a min-heap
struct compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode* ,vector<ListNode*>, compare> pq;
        int size = lists.size();
        if(size == 0) 
        return NULL;
        for(int i=0; i<size; i++){
            if(lists[i] != NULL)
            pq.push(lists[i]);
        }
        ListNode* dummy=new ListNode;
        ListNode* ans=dummy;
        while(!pq.empty()){
        auto x=pq.top();
        pq.pop();
        ListNode* node= x;
        ans->next=node;
        ans=ans->next;
        if(node->next!=NULL) 
        pq.push({node->next});
        }
        return dummy->next;
    }
};