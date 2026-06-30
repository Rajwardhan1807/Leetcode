# 58. Length of Last Word

## Problem Statement

Given a string `s` consisting of words and spaces, return the **length of the last word**.

A word is defined as a sequence of **non-space characters**.

---

## Example 1

```text
Input:
s = "Hello World"

Output:
5
```

**Explanation**

The last word is `"World"`, which has **5** characters.

---

## Example 2

```text
Input:
s = "   fly me   to   the moon  "

Output:
4
```

**Explanation**

Ignore the trailing spaces. The last word is `"moon"`.

---

## Example 3

```text
Input:
s = "luffy is still joyboy"

Output:
6
```

---

# Approach

### Traverse from the End

Since we only need the **last word**, it is easier to start from the end of the string.

Steps:

1. Start from the last character.
2. Skip all trailing spaces.
3. Count characters until another space or the beginning of the string is reached.
4. Return the count.

---

# Why This Works

Suppose:

```text
s = "Hello World   "
```

Start from the end:

```text
Hello World___
             ↑
```

Skip trailing spaces:

```text
Hello World
           ↑
```

Now count characters:

```text
d → 1
l → 2
r → 3
o → 4
W → 5
```

Stop when a space is found.

Answer:

```text
5
```

---

# Code

```cpp
class Solution {
public:
    int lengthOfLastWord(string s) {

        int i = s.length() - 1;
        int length = 0;

        // Skip trailing spaces
        while(i >= 0 && s[i] == ' ') {
            i--;
        }

        // Count characters of the last word
        while(i >= 0 && s[i] != ' ') {
            length++;
            i--;
        }

        return length;
    }
};
```

---

# Dry Run

### Input

```text
s = "Hello World"
```

Start from the end:

```text
Hello World
           ↑
```

Count:

```text
d → 1
l → 2
r → 3
o → 4
W → 5
```

Encounter a space.

Final Answer:

```text
5
```

---

# Complexity Analysis

### Time Complexity

```text
O(n)
```

In the worst case, we may traverse the entire string once.

---

### Space Complexity

```text
O(1)
```

Only a few variables are used.

---

# Key Concepts

* String Traversal
* Reverse Iteration
* Handling Spaces

---

# LeetCode

**Problem #58 – Length of Last Word**

### Stats

* **Difficulty:** Easy
* **Runtime:** **0 ms**
* **Topics:** String

### Learning Outcome

This problem demonstrates how traversing a string **from the end** can simplify finding the last word. It reinforces reverse iteration and careful handling of trailing spaces while achieving an optimal **O(n)** time and **O(1)** space solution.
