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
    struct compare{
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;   // min heap based on node value
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;


        for (ListNode* node : lists){
            if (node != nullptr)
                pq.push(node);
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;

        while (!pq.empty()) {
            ListNode* smallest = pq.top();
            pq.pop();

            curr->next = smallest;
            curr = curr->next;

            if (smallest->next != nullptr)
                pq.push(smallest->next);
        }

        return dummy->next;
    }
};