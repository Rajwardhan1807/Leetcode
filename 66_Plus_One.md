# ➕ LeetCode 66 - Plus One

## 📌 Problem

You are given a large integer represented as an array of digits, where each element represents a single digit.

Increment the integer by **one** and return the resulting array of digits.

---

## 💡 Approach

Since addition starts from the **least significant digit**, we traverse the array from **right to left**.

- If the current digit is **less than 9**, simply increment it and return the array.
- If the current digit is **9**, it becomes `0` and a carry is generated.
- Continue propagating the carry to the left.
- If all digits were `9`, insert `1` at the beginning.

---

## ✅ Algorithm

1. Start from the last digit.
2. If the digit is not `9`:
   - Increment it.
   - Return the array.
3. Otherwise:
   - Change it to `0`.
4. Continue moving left.
5. If every digit becomes `0`, insert `1` at the front.
6. Return the updated array.

---

## 🧠 Why It Works

Example:

```text
digits = [1,2,9]
```

Traversal:

```text
129 + 1

9 → 0 (carry)
2 → 3

Result = [1,3,0]
```

---

Example:

```text
digits = [9,9,9]
```

Traversal:

```text
999 + 1

9 → 0
9 → 0
9 → 0

Insert 1 at the beginning

Result = [1,0,0,0]
```

---

## ⏱️ Complexity Analysis

- **Time Complexity:** `O(n)`
  - In the worst case, every digit is visited once.

- **Space Complexity:** `O(1)`
  - No extra space is used (excluding the possible insertion of one digit in the result).

---

## 🧠 Key Concepts

- Array Traversal
- Carry Propagation
- Simulation

---

## 🚀 Example

### Input

```text
digits = [1,2,3]
```

### Output

```text
[1,2,4]
```

---

### Input

```text
digits = [4,3,2,1]
```

### Output

```text
[4,3,2,2]
```

---

### Input

```text
digits = [9]
```

### Output

```text
[1,0]
```

---

### Input

```text
digits = [9,9,9]
```

### Output

```text
[1,0,0,0]
```

---

## 📖 What I Learned

- How to simulate addition on an array of digits.
- How carry propagation works from right to left.
- Why traversing from the least significant digit simplifies the solution.
- How to handle the special case when every digit is `9`.

---

## 🏷️ Tags

`Array` `Math` `Simulation`