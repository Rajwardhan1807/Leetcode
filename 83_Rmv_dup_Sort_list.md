# 83. Remove Duplicates from Sorted List

> **Difficulty:** Easy  
> **Language:** C++  
> **Runtime:** 0 ms *(Accepted)*

## 📝 Problem Statement

Given the `head` of a **sorted linked list**, delete all duplicates such that each element appears **only once**.

Return the linked list after removing the duplicates.

---

## 💡 Approach

Since the linked list is **already sorted**, duplicate values will always appear **next to each other**.

We traverse the list using a single pointer:

- If the current node and the next node have the same value, skip the next node by updating the `next` pointer.
- Otherwise, move to the next node.

This modifies the list **in-place** without using extra memory.

---

## 🔄 Algorithm

1. Store the original head in `res`.
2. Traverse the linked list while both the current node and the next node exist.
3. If the current value equals the next value:
   - Skip the duplicate node.
4. Otherwise:
   - Move to the next node.
5. Return the original head.

---

## ✅ Code

```cpp
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
    ListNode* deleteDuplicates(ListNode* head) {

        ListNode* res = head;

        while (head && head->next) {

            if (head->val == head->next->val) {
                head->next = head->next->next;
            }
            else {
                head = head->next;
            }
        }

        return res;
    }
};
```

---

## 📊 Example

### Input

```text
head = [1,1,2,3,3]
```

### Traversal

```text
1 → 1 → 2 → 3 → 3

Duplicate 1 found
↓

1 → 2 → 3 → 3

Duplicate 3 found
↓

1 → 2 → 3
```

### Output

```text
[1,2,3]
```

---

## ⏱ Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

Where `n` is the number of nodes in the linked list.

---

## 🧠 Key Insight

Because the linked list is **sorted**, duplicate elements are always adjacent.

This allows us to remove duplicates by simply adjusting pointers during a single traversal, making the solution both time and space efficient.

---

⭐ If you found this solution helpful, consider giving the repository a star!