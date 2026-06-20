# 2_Add_Two_Nums

## Problem

We are given two linked lists.

Each linked list stores a number, but the digits are written in reverse order.

Example:

l1 = [2,4,3]

l2 = [5,6,4]

This means:

* l1 = 342
* l2 = 465

Now add them:

342 + 465 = 807

Return the answer as a linked list in reverse order:

[7,0,8]

---

## Simple Explanation (Like a 2-Year-Old)

Imagine you have:

🍎🍎 = 2 apples

🍎🍎🍎🍎🍎 = 5 apples

2 + 5 = 7 apples

Now imagine the numbers are very long, so we add them one digit at a time.

Just like adding numbers on paper:

```
  342
+ 465
-----
  807
```

But the digits come backwards:

```
2 -> 4 -> 3
5 -> 6 -> 4
```

So we start from the front and keep adding.

---

## Approach

1. Create a dummy node to store the result.
2. Keep a variable called `carry`.
3. Traverse both linked lists together.
4. Add:

   * current digit from l1
   * current digit from l2
   * carry
5. Store the last digit of the sum in a new node.
6. Update the carry.
7. Move to the next nodes.
8. Continue until both lists and carry are finished.

---

## Example Walkthrough

Input:

```
l1 = [2,4,3]
l2 = [5,6,4]
```

Step 1:

```
2 + 5 = 7
Result = [7]
Carry = 0
```

Step 2:

```
4 + 6 = 10
Result = [7,0]
Carry = 1
```

Step 3:

```
3 + 4 + 1 = 8
Result = [7,0,8]
Carry = 0
```

Output:

```
[7,0,8]
```

---

## Time Complexity

```
O(max(N, M))
```

We visit each node once.

---

## Space Complexity

```
O(max(N, M))
```

Space is used for the new linked list.

---

## Key Learning

* Linked Lists
* Carry Handling
* Dummy Node Technique
* Traversing Multiple Lists Together

---

## Result

The algorithm efficiently adds two numbers represented as linked lists and returns the answer as a new linked list.
