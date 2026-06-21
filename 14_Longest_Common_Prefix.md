# 14_Longest_Common_Prefix

## Problem

Write a function to find the **longest common prefix string** amongst an array of strings.

If there is no common prefix, return an empty string `""`.

---

## Examples

### Example 1

Input:

```text
strs = ["flower", "flow", "flight"]
```

Output:

```text
"fl"
```

Explanation:

```text
flower
flow
flight
```

The longest prefix shared by all strings is:

```text
fl
```

---

### Example 2

Input:

```text
strs = ["dog", "racecar", "car"]
```

Output:

```text
""
```

Explanation:

There is no common prefix among all strings.

---

## Intuition

Since every common prefix must be part of the first string, we can compare each character of the first string with the corresponding character in all other strings.

* If all strings have the same character at a position, add it to the answer.
* If any string has a different character, stop and return the current prefix.

---

## Approach

1. Start with an empty result string.
2. Traverse each character of the first string.
3. Compare that character with the character at the same position in every other string.
4. If a mismatch is found:

   * Return the current result.
5. Otherwise:

   * Add the character to the result.
6. Continue until the end of the first string.

---

## Dry Run

Input:

```text
["flower", "flow", "flight"]
```

### Step 1

Check index `0`:

```text
f == f == f
```

Result:

```text
"f"
```

### Step 2

Check index `1`:

```text
l == l == l
```

Result:

```text
"fl"
```

### Step 3

Check index `2`:

```text
o == o
i != o
```

Mismatch found.

Return:

```text
"fl"
```

---

## Code Logic

```cpp
for(int i = 0; i < strs[0].size(); i++) {
    for(auto s : strs) {
        if(s[i] != strs[0][i]) {
            return res;
        }
    }
    res += strs[0][i];
}
```

### How It Works

* `i` represents the current character position.
* Compare the character at position `i` in every string.
* If all characters match, add it to the answer.
* Stop immediately when a mismatch occurs.

---

## Complexity Analysis

### Time Complexity

```text
O(N × M)
```

Where:

* `N` = Number of strings
* `M` = Length of the shortest prefix checked

Each character may be compared across all strings.

---

### Space Complexity

```text
O(1)
```

Ignoring the output string, only a few extra variables are used.

---

## Key Concepts

* String Traversal
* Nested Loops
* Character Comparison
* Early Termination
* Prefix Matching

---

## Result

The algorithm checks characters position by position across all strings and builds the longest common prefix until a mismatch is found, making it a simple and efficient solution.
