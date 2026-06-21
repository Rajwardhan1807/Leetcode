# 9_Palindrome_Number

## Problem

Given an integer `x`, return:

* `true` if `x` is a palindrome
* `false` otherwise

A palindrome number reads the same forward and backward.

---

## What is a Palindrome?

Examples:

```text
121  -> Palindrome ✅
1331 -> Palindrome ✅
123  -> Not Palindrome ❌
```

Just like the word:

```text
MOM
```

reads the same from both directions.

---

## Simple Explanation (Like a 2-Year-Old)

Imagine you have the number:

```text
121
```

Read it from the left:

```text
1 → 2 → 1
```

Now read it from the right:

```text
1 → 2 → 1
```

They are exactly the same.

So the answer is:

```text
true
```

---

## Approach

1. Store the original number in a temporary variable.
2. Reverse the number digit by digit.
3. Compare the reversed number with the original number.
4. If both are equal, it is a palindrome.
5. Otherwise, it is not.

---

## Example Walkthrough

### Example 1

Input:

```text
x = 121
```

Reverse Process:

```text
121 → 12 → 1 → 0

Reversed Number = 121
```

Comparison:

```text
121 == 121
```

Output:

```text
true
```

---

### Example 2

Input:

```text
x = -121
```

Reverse:

```text
121-
```

This is not the same as:

```text
-121
```

Output:

```text
false
```

---

### Example 3

Input:

```text
x = 10
```

Reverse:

```text
01 = 1
```

Comparison:

```text
10 != 1
```

Output:

```text
false
```

---

## Code Logic

```cpp
int temp = x;
int rev = 0;

while(x > 0){
    int dig = x % 10;
    rev = rev * 10 + dig;
    x = x / 10;
}

return rev == temp;
```

### What Happens Here?

For:

```text
x = 123
```

Iteration 1:

```text
digit = 3
rev = 3
```

Iteration 2:

```text
digit = 2
rev = 32
```

Iteration 3:

```text
digit = 1
rev = 321
```

Now compare:

```text
321 == 123 ? No
```

Return:

```text
false
```

---

## Time Complexity

```text
O(log10(n))
```

We process each digit exactly once.

---

## Space Complexity

```text
O(1)
```

Only a few variables are used.

---

## Key Learning

* Integer Manipulation
* Modulus Operator (`%`)
* Reversing Numbers
* Comparing Original and Reversed Values
* Basic Math-Based Solution

---

## Result

The algorithm reverses the given number and checks whether the reversed number is equal to the original number. If they are equal, the number is a palindrome; otherwise, it is not.
