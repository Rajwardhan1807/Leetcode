# 70. Climbing Stairs

> **Difficulty:** Easy  
> **Language:** C++  
> **Runtime:** 0 ms *(Beats 100%)*

## 📝 Problem Statement

You are climbing a staircase that has **n** steps.

Each time you can either:
- Climb **1 step**, or
- Climb **2 steps**

Return the **total number of distinct ways** to reach the top.

---

## 💡 Approach

This problem follows the **Fibonacci Pattern**.

To reach step `i`, there are only two possibilities:

- Jump from step `i-1` (1-step jump)
- Jump from step `i-2` (2-step jump)

Therefore,

```text
ways(i) = ways(i-1) + ways(i-2)
```

Instead of using recursion (which is slow), we use **Dynamic Programming with two variables**.

We only keep track of:

- `prev` → ways to reach previous step
- `curr` → ways to reach current step

This gives us an **O(1)** space solution.

---

## 🔄 Algorithm

1. If `n` is 0 or 1, return 1.
2. Initialize:
   - `prev = 1`
   - `curr = 1`
3. Iterate from step `2` to `n`.
4. Calculate the current number of ways:
   - `curr = prev + curr`
5. Update variables.
6. Return `curr`.

---

## ✅ Code

```cpp
class Solution {
public:
    int climbStairs(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }

        int prev = 1, curr = 1;

        for (int i = 2; i <= n; i++) {
            int temp = curr;
            curr = prev + curr;
            prev = temp;
        }

        return curr;
    }
};
```

---

## 📊 Example

### Input

```text
n = 5
```

### Execution

| Step | Ways |
|------|-----:|
|0|1|
|1|1|
|2|2|
|3|3|
|4|5|
|5|8|

### Output

```text
8
```

---

## ⏱ Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

---

## 🧠 Key Insight

The number of ways to reach a step depends only on the **previous two steps**, making this a classic **Fibonacci Dynamic Programming** problem.

Instead of storing every result, keeping only the last two values is enough, reducing the space complexity from **O(n)** to **O(1)**.

---

⭐ If you found this solution helpful, consider giving the repository a star!