# 20_Valid_Parentheses

## Problem

Given a string `s` containing only:

```text
( ) { } [ ]
```

Determine whether the string is valid.

A string is valid if:

1. Every opening bracket has a matching closing bracket.
2. Brackets are closed in the correct order.
3. Every closing bracket corresponds to the correct type of opening bracket.

---

## Examples

### Example 1

Input:

```text
s = "()"
```

Output:

```text
true
```

---

### Example 2

Input:

```text
s = "()[]{}"
```

Output:

```text
true
```

---

### Example 3

Input:

```text
s = "(]"
```

Output:

```text
false
```

Explanation:

```text
( opens
] closes

Types do not match.
```

---

### Example 4

Input:

```text
s = "([])"
```

Output:

```text
true
```

---

### Example 5

Input:

```text
s = "([)]"
```

Output:

```text
false
```

Explanation:

Brackets are closed in the wrong order.

---

## Intuition

Think of brackets like plates stacked on top of each other.

When an opening bracket appears:

```text
(
[
{
```

Place it on the stack.

When a closing bracket appears:

```text
)
]
}
```

Check the top of the stack:

* If it matches, remove it.
* If it does not match, the string is invalid.

At the end:

* Stack should be empty.
* Otherwise some opening brackets were never closed.

---

## Approach

1. Create an empty stack.
2. Traverse each character in the string.
3. If the character is an opening bracket:

   * Push it onto the stack.
4. If the character is a closing bracket:

   * Check if the stack is empty.
   * Compare it with the top element.
   * If they don't match, return `false`.
   * Otherwise pop the stack.
5. After processing all characters:

   * If the stack is empty, return `true`.
   * Otherwise return `false`.

---

## Dry Run

Input:

```text
s = "([])"
```

### Step 1

Read:

```text
(
```

Stack:

```text
(
```

---

### Step 2

Read:

```text
[
```

Stack:

```text
(
[
```

---

### Step 3

Read:

```text
]
```

Top of stack:

```text
[
```

Match found.

Pop it.

Stack:

```text
(
```

---

### Step 4

Read:

```text
)
```

Top of stack:

```text
(
```

Match found.

Pop it.

Stack:

```text
Empty
```

Result:

```text
true
```

---

## Code Logic

```cpp
if(ch == '(' || ch == '[' || ch == '{'){
    st.push(ch);
}
```

Push all opening brackets onto the stack.

---

For closing brackets:

```cpp
if(st.empty())
    return false;
```

If no opening bracket exists, the string is invalid.

---

Match pairs:

```cpp
'(' -> ')'
'[' -> ']'
'{' -> '}'
```

If the top bracket matches the current closing bracket:

```cpp
st.pop();
```

Otherwise:

```cpp
return false;
```

---

## Complexity Analysis

### Time Complexity

```text
O(N)
```

Where `N` is the length of the string.

Each character is processed once.

---

### Space Complexity

```text
O(N)
```

In the worst case, all characters are opening brackets and are stored in the stack.

---

## Key Concepts

* Stack Data Structure
* LIFO (Last In, First Out)
* String Traversal
* Bracket Matching
* Balanced Parentheses

---

## Why Stack Works?

The most recently opened bracket must be closed first.

Example:

```text
({[]})
```

The closing order is:

```text
]
}
)
```

Which is exactly how a stack works:

```text
Last Opened → First Closed
```

---

## Result

The algorithm uses a stack to keep track of opening brackets and ensures every closing bracket matches the most recent opening bracket. If all brackets are matched correctly and the stack becomes empty, the string is valid.
