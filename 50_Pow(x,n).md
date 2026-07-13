# 50. Pow(x, n)

> **Difficulty:** Medium  
> **Language:** C++  
> **Runtime:** 0 ms *(Beats 100%)*

## 📝 Problem Statement

Implement the function `pow(x, n)` that calculates:

```text
xⁿ
```

where:

- `x` is a floating-point number.
- `n` is a 32-bit signed integer.

The solution should efficiently handle:

- Large positive exponents
- Negative exponents
- The edge case where `n = INT_MIN`

---

## 💡 Approach

A naive solution multiplies `x` by itself `n` times, resulting in **O(n)** time complexity.

Instead, we use **Binary Exponentiation (Exponentiation by Squaring)**.

### Key Idea

Every exponent can be represented in binary.

If the current exponent is odd:

- Multiply the answer by `x`.

Regardless:

- Square the base.
- Divide the exponent by 2.

For negative exponents:

```text
x⁻ⁿ = (1/x)ⁿ
```

Since `INT_MIN` cannot be directly negated, we first convert `n` to a `long` using `labs()`.

---

## 🔄 Algorithm

1. If `n` is negative:
   - Replace `x` with `1/x`.
2. Store `abs(n)` in a `long`.
3. Initialize answer as `1`.
4. While exponent > 0:
   - If exponent is odd, multiply answer by current base.
   - Square the base.
   - Divide exponent by 2.
5. Return the answer.

---

## ✅ Code

```cpp
class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0) {
            x = 1 / x;
        }

        long num = labs(n);
        double ans = 1;

        while (num) {
            if (num & 1) {
                ans *= x;
            }

            x *= x;
            num >>= 1;
        }

        return ans;
    }
};
```

---

## 📊 Example

### Input

```text
x = 2.0
n = 10
```

### Execution

```text
2¹⁰

ans = 1
x = 2

10 → even → x = 4
5  → odd  → ans = 4
2  → even → x = 256
1  → odd  → ans = 1024
```

### Output

```text
1024.00000
```

---

## ⏱ Complexity Analysis

- **Time Complexity:** `O(log n)`
- **Space Complexity:** `O(1)`

---

## 🧠 Key Insight

Binary Exponentiation reduces the number of multiplications by repeatedly squaring the base.

Instead of performing `n` multiplications, it performs only **log₂(n)** iterations, making it one of the most efficient methods for computing powers.

---

⭐ If you found this solution helpful, consider giving the repository a star!