# ➕ LeetCode 67 - Add Binary

## 📌 Problem

Given two binary strings `a` and `b`, return their sum as a binary string.

The input strings contain only `'0'` and `'1'`.

---

## 💡 Approach

This solution simulates **binary addition**, just like adding decimal numbers by hand.

- Start from the last character of both strings.
- Add the current bits along with any carry.
- Append the result bit (`sum % 2`) to the answer.
- Update the carry (`sum / 2`).
- Continue until both strings are processed and no carry remains.
- Reverse the result since it is built from right to left.

---

## ✅ Algorithm

1. Initialize:
   - `i` = last index of `a`
   - `j` = last index of `b`
   - `carry = 0`
   - `answer = ""`
2. While either string has remaining digits or `carry` is not zero:
   - Add the current bit from `a` (if available).
   - Add the current bit from `b` (if available).
   - Append `carry % 2` to the answer.
   - Update `carry = carry / 2`.
3. Reverse the answer.
4. Return the final binary string.

---

## 🧠 Why It Works

Example:

```text
a = "1010"
b = "1011"
```

Addition from right to left:

```text
0 + 1 = 1
1 + 1 = 10
0 + 0 + carry = 1
1 + 1 = 10
carry = 1
```

Result before reversing:

```text
10101 (stored in reverse order)
```

After reversing:

```text
10101
```

---

## ⏱️ Complexity Analysis

- **Time Complexity:** `O(max(n, m))`
  - Each digit is processed once.

- **Space Complexity:** `O(max(n, m))`
  - To store the resulting binary string.

---

## 🧠 Key Concepts

- String Traversal
- Binary Addition
- Carry Propagation
- Simulation

---

## 🚀 Example

### Input

```text
a = "11"
b = "1"
```

### Output

```text
"100"
```

---

### Input

```text
a = "1010"
b = "1011"
```

### Output

```text
"10101"
```

---

## 📖 What I Learned

- How to perform binary addition without converting strings to integers.
- How carry propagation works in binary arithmetic.
- Why building the answer from right to left requires reversing it at the end.
- How to handle binary strings of different lengths.

---

## 🏷️ Tags

`String` `Math` `Simulation` `Binary`