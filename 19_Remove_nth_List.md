# 19. Remove Nth Node From End of List

## Problem Statement

Given the head of a linked list, remove the `n`th node from the end of the list and return its head.

### Example 1

```text
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
```

### Example 2

```text
Input: head = [1], n = 1
Output: []
```

### Example 3

```text
Input: head = [1,2], n = 1
Output: [1]
```

---

## Approach

This solution follows a **Two-Pass Traversal** approach.

### Step 1: Count Nodes

Traverse the linked list once to determine its total length.

### Step 2: Find Node to Remove

The node to remove is located at:

```text
(length - n)
```

from the beginning of the list.

### Step 3: Handle Edge Cases

* If the head itself needs to be removed (`length == n`), return `head->next`.
* Otherwise, traverse to the node just before the target node and adjust pointers.

---

## Code

```cpp
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* curr = head;
        int count = 0;

        while (curr != NULL) {
            curr = curr->next;
            count++;
        }

        if (count == n) {
            return head->next;
        }

        curr = head;

        for (int i = 1; i < count - n; i++) {
            curr = curr->next;
        }

        curr->next = curr->next->next;

        return head;
    }
};
```

---

## Dry Run

### Input

```text
head = [1,2,3,4,5]
n = 2
```

### Step 1

Count total nodes:

```text
Length = 5
```

### Step 2

Position to remove from beginning:

```text
5 - 2 = 3
```

Node at position 4 (value = 4) should be removed.

### Result

```text
1 -> 2 -> 3 -> 5
```

Output:

```text
[1,2,3,5]
```

---

## Complexity Analysis

### Time Complexity

```text
O(N)
```

* First traversal to count nodes.
* Second traversal to locate the node.

### Space Complexity

```text
O(1)
```

Only a few pointers are used.

---

## Key Concepts

* Linked List
* Pointer Manipulation
* Two-Pass Traversal
* Node Deletion

---

## Follow-Up (One Pass Solution)

The follow-up can be solved using the **Fast & Slow Pointer** technique:

1. Move `fast` pointer `n` steps ahead.
2. Move both pointers simultaneously.
3. When `fast` reaches the end, `slow` will be just before the node to remove.
4. Delete the target node in a single traversal.

Time Complexity: **O(N)**
Space Complexity: **O(1)**

---

## Tags

`Linked List` `Two Pointers` `Fast & Slow Pointers` `LeetCode Medium`

## LeetCode

Problem #19 - Remove Nth Node From End of List
