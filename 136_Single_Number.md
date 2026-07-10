# ⚡ LeetCode 136 - Single Number

## 📌 Problem

Given a **non-empty** integer array `nums`, every element appears **twice** except for one.

Return the element that appears only once.

You must implement a solution with:
- **Linear runtime** `O(n)`
- **Constant extra space** `O(1)`

---

## 💡 Approach

The optimal solution uses the **Bitwise XOR (`^`)** operator.

### XOR Properties

- `a ^ a = 0`
- `a ^ 0 = a`
- XOR is **commutative** and **associative**, meaning the order does not matter.

Since every number except one appears exactly twice:

- Duplicate numbers cancel each other out.
- The remaining value is the unique number.

---

## ✅ Algorithm

1. Initialize `result = 0`.
2. Traverse every number in the array.
3. Perform:

```cpp
result ^= num;
```

4. After processing all elements, return `result`.

---

## 🧠 Why It Works

Example:

```text
nums = [4,1,2,1,2]
```

Perform XOR sequentially:

```text
0 ^ 4 = 4
4 ^ 1 = 5
5 ^ 2 = 7
7 ^ 1 = 6
6 ^ 2 = 4
```

All duplicate values cancel each other:

```text
1 ^ 1 = 0
2 ^ 2 = 0
```

Remaining value:

```text
4
```

---

## ⏱️ Complexity Analysis

- **Time Complexity:** `O(n)`
  - Traverse the array once.

- **Space Complexity:** `O(1)`
  - Only one variable is used.

---

## 🧠 Key Concepts

- Bit Manipulation
- XOR Operator
- Constant Space Algorithm
- Linear Traversal

---

## 🚀 Example

### Input

```text
nums = [2,2,1]
```

### Output

```text
1
```

---

### Input

```text
nums = [4,1,2,1,2]
```

### Output

```text
4
```

---

### Input

```text
nums = [1]
```

### Output

```text
1
```

---

## 📖 What I Learned

- XOR is a powerful tool for eliminating duplicate values.
- Using bit manipulation can reduce both time and space complexity.
- Sometimes mathematical properties lead to much simpler solutions than using hash maps.

---

## 🏷️ Tags

`Bit Manipulation` `XOR` `Array`