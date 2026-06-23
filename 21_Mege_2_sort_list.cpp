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
private:
    ListNode* solve(ListNode* l1, ListNode* l2) {

        // If first list has only one node
        if (l1->next == NULL) {
            l1->next = l2;
            return l1;
        }

        ListNode* curr1 = l1;
        ListNode* next1 = l1->next;

        ListNode* curr2 = l2;
        ListNode* next2 = NULL;

        while (next1 != NULL && curr2 != NULL) {

            if (curr2->val >= curr1->val &&
                curr2->val <= next1->val) {

                // Insert curr2 between curr1 and next1
                next2 = curr2->next;

                curr1->next = curr2;
                curr2->next = next1;

                curr1 = curr2;
                curr2 = next2;
            }
            else {
                curr1 = next1;
                next1 = next1->next;

                // Reached end of first list
                if (next1 == NULL) {
                    curr1->next = curr2;
                    return l1;
                }
            }
        }

        return l1;
    }

public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if (list1 == NULL)
            return list2;

        if (list2 == NULL)
            return list1;

        if (list1->val <= list2->val)
            return solve(list1, list2);
        else
            return solve(list2, list1);
    }
};