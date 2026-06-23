# 21. Merge Two Sorted Lists

## Problem Statement

You are given the heads of two sorted linked lists `list1` and `list2`.

Merge the two lists into one sorted linked list by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

---

## Example 1

```text
Input: list1 = [1,2,4]
       list2 = [1,3,4]

Output: [1,1,2,3,4,4]
```

## Example 2

```text
Input: list1 = []
       list2 = []

Output: []
```

## Example 3

```text
Input: list1 = []
       list2 = [0]

Output: [0]
```

---

## Approach

### In-Place Linked List Merging

Instead of creating a new linked list, we can directly merge the existing nodes by adjusting their pointers.

### Algorithm

1. Handle edge cases:

   * If `list1` is empty, return `list2`.
   * If `list2` is empty, return `list1`.

2. Ensure `list1` starts with the smaller value.

3. Traverse both lists:

   * Find the correct position where the current node of `list2` should be inserted into `list1`.
   * Update pointers to insert nodes without creating new ones.

4. Continue until all nodes are merged.

---

## Code

```cpp
class Solution {
private:
    ListNode* solve(ListNode* l1, ListNode* l2) {

        ListNode* curr1 = l1;
        ListNode* next1 = curr1->next;

        ListNode* curr2 = l2;
        ListNode* next2 = curr2->next;

        while (next1 != NULL && curr2 != NULL) {

            if ((curr2->val >= curr1->val) &&
                (curr2->val <= next1->val)) {

                curr1->next = curr2;
                next2 = curr2->next;

                curr2->next = next1;

                curr1 = curr2;
                curr2 = next2;
            }
            else {

                curr1 = next1;
                next1 = next1->next;

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
```

---

## Dry Run

### Input

```text
list1 = [1,2,4]
list2 = [1,3,4]
```

### Step-by-Step

Initial Lists:

```text
1 -> 2 -> 4
1 -> 3 -> 4
```

Insert first `1` from list2:

```text
1 -> 1 -> 2 -> 4
```

Insert `3` between `2` and `4`:

```text
1 -> 1 -> 2 -> 3 -> 4
```

Append remaining `4`:

```text
1 -> 1 -> 2 -> 3 -> 4 -> 4
```

### Output

```text
[1,1,2,3,4,4]
```

---

## Complexity Analysis

### Time Complexity

```text
O(N + M)
```

Where:

* `N` = length of list1
* `M` = length of list2

Each node is visited at most once.

### Space Complexity

```text
O(1)
```

No extra linked list or auxiliary data structure is used.

---

## Key Concepts

* Linked Lists
* Pointer Manipulation
* In-Place Merging
* Two Pointer Technique

---

## Alternative Approach

A common interview solution uses a **dummy node**:

1. Create a dummy node.
2. Compare nodes from both lists.
3. Attach the smaller node to the merged list.
4. Move forward until one list is exhausted.
5. Attach the remaining nodes.

This approach is often easier to understand, while the current solution is more space-efficient and performs the merge directly on existing nodes.

---

## Tags

`Linked List` `Recursion` `Two Pointers` `Easy`

---

## LeetCode

**Problem #21 – Merge Two Sorted Lists**
