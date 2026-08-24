## Problem Statement

Alice and Bob take turns playing a game, with **Alice starting first**. 
There are $n$ stones arranged in a row. While there is more than one stone remaining, the current player:
1. Chooses an integer $x > 1$.
2. Removes the leftmost $x$ stones.
3. Adds the sum of the removed stones to their score.
4. Places a new stone with that sum on the left side of the row.

The game stops when only one stone remains. 
* **Alice** wants to maximize the score difference: `Alice's Score - Bob's Score`
* **Bob** wants to minimize it.

Return the score difference when both players play optimally.

---

## Approach & Logic

### Prefix Sums
When the leftmost $x$ stones are removed, their sum is exactly a prefix sum of the original array. For example:
* **stones** = `[1, 2, 3, 4]`
* **Prefix Sums** = `[1, 3, 6, 10]`

Instead of simulating the actual game, we use these prefix sums to calculate the best possible score difference.

### Dynamic Programming
We maintain a variable `best` that represents the best score difference that can be achieved from the current state.
1. **Initial state:** `best = prefix[n - 1]` (the total sum of all stones).
2. We process the prefix sums from right to left.
3. For every possible move, we update:
   $$\text{best} = \max(\text{best}, \text{prefix}[i] - \text{best})$$

If the current player takes a prefix with sum `prefix[i]`, they gain that amount. After that move, the opponent gets a position whose optimal score difference is `best`. Therefore, the current player's resulting advantage is `prefix[i] - best`. We take the maximum because the current player plays optimally.

---

## Algorithm & Dry Run

### Algorithm Steps
1. Create the prefix sum array.
2. Initialize `best` with the total sum of all stones (`prefix[n - 1]`).
3. Traverse the prefix sums backwards from $n - 2$ down to $1$.
4. At each position, update: $\text{best} = \max(\text{best}, \text{prefix}[i] - \text{best})$.
5. Return `best`.

### Dry Run Example
* **Input:** `stones = [1, 2, 3, 4]`
* **Step 1:** Calculate Prefix Sum $\rightarrow$ `prefix = [1, 3, 6, 10]`
* **Initial value:** `best = 10`
* **Step 2:** Iterate Backwards:
  * For $i = 2$: $\text{best} = \max(10, 6 - 10) = \max(10, -4) = 10$
  * For $i = 1$: $\text{best} = \max(10, 3 - 10) = \max(10, -7) = 10$
* **Final Answer:** `10`

---

## C++ Solution

```cpp
class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();

        vector<int> prefix = stones;

        for(int i = 1; i < n; i++)
            prefix[i] += prefix[i - 1];

        int best = prefix[n - 1];

        for(int i = n - 2; i >= 1; i--) {
            best = max(best, prefix[i] - best);
        }

        return best;
    }
};