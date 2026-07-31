# LeetCode 23 - Merge k Sorted Lists

## Problem Statement

You are given an array of `k` linked-lists where each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

---

## Examples

### Example 1

```text id="6x6s7m"
Input:

lists = [
  [1,4,5],
  [1,3,4],
  [2,6]
]

Output:

[1,1,2,3,4,4,5,6]
```

Explanation:

The three sorted lists are merged into one sorted linked list.

---

### Example 2

```text id="f7k5r9"
Input:

lists = []

Output:

[]
```

---

### Example 3

```text id="0b2z1p"
Input:

lists = [[]]

Output:

[]
```

---

# Approach

This problem can be efficiently solved using a **Min Heap (Priority Queue)**.

Instead of comparing all nodes repeatedly, we maintain a heap containing the smallest available node from each linked list.

### Idea:

* Insert the first node of every non-empty list into the min heap.
* The heap always gives the node with the smallest value.
* Remove the smallest node and add it to the result list.
* If that node has a next node, insert it into the heap.
* Continue until the heap becomes empty.

This ensures that we always pick the next smallest element among all lists.

---

# Algorithm

1. Create a min heap to store linked list nodes.
2. Insert the head node of every non-empty linked list.
3. Create a dummy node to build the final sorted list.
4. While the heap is not empty:

   * Remove the smallest node.
   * Attach it to the result list.
   * Insert its next node into the heap if it exists.
5. Return the merged linked list.

---

# Dry Run

### Input

```text id="z9e1qf"
lists = [
  1 -> 4 -> 5,
  1 -> 3 -> 4,
  2 -> 6
]
```

Initial Heap:

```text id="1n7l7m"
[1,1,2]
```

Processing:

```text id="u0y9t2"
Remove 1 → Result: 1
Add next node 4

Remove 1 → Result: 1,1
Add next node 3

Remove 2 → Result: 1,1,2
Add next node 6

...
```

Final:

```text id="4phxk5"
1 -> 1 -> 2 -> 3 -> 4 -> 4 -> 5 -> 6
```

---

# C++ Solution

```cpp id="w0h1iq"
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

    struct compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;   // Min heap based on node value
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        for(ListNode* node : lists) {
            if(node != nullptr)
                pq.push(node);
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;

        while(!pq.empty()) {

            ListNode* smallest = pq.top();
            pq.pop();

            curr->next = smallest;
            curr = curr->next;

            if(smallest->next != nullptr)
                pq.push(smallest->next);
        }

        return dummy->next;
    }
};
```

---

# Complexity Analysis

Let:

* `k` = number of linked lists
* `N` = total number of nodes across all lists

## Time Complexity

```text id="jxyh5w"
O(N log k)
```

Explanation:

* Each node is inserted into and removed from the heap once.
* Heap operations take `O(log k)` time.

## Space Complexity

```text id="7q3t2m"
O(k)
```

The heap stores at most one node from each linked list.

---

# Concepts Used

* Priority Queue
* Min Heap
* Linked List
* Heap Optimization
* Divide and Conquer (Alternative Approach)

---

# LeetCode Details

* **Problem:** 23. Merge k Sorted Lists
* **Difficulty:** Hard
* **Language:** C++
* **Approach:** Min Heap
* **Time Complexity:** O(N log k)
* **Space Complexity:** O(k)

---

The min heap approach efficiently merges multiple sorted linked lists by always selecting the smallest available node, avoiding the need to repeatedly scan all lists.
