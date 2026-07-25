# 205. Isomorphic Strings

## 📝 Problem Statement

Given two strings `s` and `t`, determine whether they are **isomorphic**.

Two strings are isomorphic if:

- Every character in `s` maps to exactly one character in `t`.
- No two different characters in `s` map to the same character in `t`.
- A character may map to itself.
- The order of characters must remain the same.

**LeetCode Link:** https://leetcode.com/problems/isomorphic-strings/

---

## 💡 Approach

Use **two hash maps** to maintain a **bidirectional mapping**.

- `m1` maps characters from `s` → `t`.
- `m2` maps characters from `t` → `s`.

For every character pair:

1. If the character already has a mapping, verify that it matches.
2. Otherwise, create a new mapping.
3. Perform the same check in the reverse direction.

If any mapping conflicts, return `false`.

If the entire string is processed without conflicts, return `true`.

---

## 🚀 Algorithm

1. Create two unordered maps:
   - `m1` for `s → t`
   - `m2` for `t → s`
2. Traverse both strings simultaneously.
3. For each pair of characters:
   - Check if `s[i]` already maps to a different character.
   - Check if `t[i]` already maps to a different character.
   - Otherwise, store the new mapping.
4. If all mappings are valid, return `true`.

---

## ✅ C++ Solution

```cpp
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> m1;
        unordered_map<char, char> m2;

        for (int i = 0; i < s.length(); i++) {

            if (m1.find(s[i]) != m1.end()) {
                if (m1[s[i]] != t[i])
                    return false;
            }
            else if (m2.find(t[i]) != m2.end()) {
                if (m2[t[i]] != s[i])
                    return false;
            }

            m1[s[i]] = t[i];
            m2[t[i]] = s[i];
        }

        return true;
    }
};
```

---

## 🌳 Example 1

### Input

```text
s = "egg"
t = "add"
```

### Mapping

```text
e → a
g → d
```

Both mappings are consistent.

### Output

```text
true
```

---

## 🌳 Example 2

### Input

```text
s = "foo"
t = "bar"
```

### Mapping

```text
f → b
o → a

Next 'o' should map to 'a'
But it maps to 'r' ❌
```

### Output

```text
false
```

---

## 🌳 Example 3

### Input

```text
s = "paper"
t = "title"
```

### Mapping

```text
p → t
a → i
e → l
r → e
```

All mappings remain unique and consistent.

### Output

```text
true
```

---

## 🔍 Dry Run

```
s = "egg"
t = "add"

i = 0
e → a

i = 1
g → d

i = 2
g already maps to d ✔

Return true
```

---

## ⏱️ Complexity Analysis

- **Time Complexity:** `O(n)`
  - Traverse both strings once.

- **Space Complexity:** `O(1)`
  - At most 256 ASCII characters are stored in the hash maps.

---

## 🔑 Key Insight

Checking only one-directional mapping (`s → t`) is **not enough**.

Example:

```text
s = "ab"
t = "aa"
```

```
a → a
b → a
```

This is invalid because **two different characters map to the same character**.

Using **two hash maps** guarantees a one-to-one correspondence between characters.

---

## 🏷️ Tags

`Hash Table` `String`