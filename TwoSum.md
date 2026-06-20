### Explanation of the Two Sum Solution

The goal of this problem is to find two numbers in the array whose sum equals the given target and return their indices.

#### Step 1: Create a result vector

```cpp
vector<int> res;
```

This vector will store the indices of the two numbers that add up to the target.

#### Step 2: Iterate through each element

```cpp
for(auto it1 = nums.begin(); it1 != nums.end(); ++it1)
```

The loop selects one number at a time from the array.

#### Step 3: Find the required second number

```cpp
auto it2 = find(it1 + 1, nums.end(), target - *it1);
```

For the current number `*it1`, we calculate the value needed to reach the target:

```cpp
required_number = target - current_number
```

The `find()` function searches for this required number in the remaining part of the array.

#### Step 4: Check if the number exists

```cpp
if(it2 != nums.end())
```

If `find()` does not return `nums.end()`, the required number has been found.

#### Step 5: Store the indices

```cpp
res.push_back(it1 - nums.begin());
res.push_back(it2 - nums.begin());
```

Subtracting `nums.begin()` from an iterator gives its index in the vector.

#### Step 6: Stop searching

```cpp
break;
```

Since the problem guarantees exactly one valid answer, we can stop once the pair is found.

#### Step 7: Return the result

```cpp
return res;
```

The function returns the indices of the two numbers whose sum equals the target.

### Example

Input:

```cpp
nums = {2, 7, 11, 15}
target = 9
```

Execution:

* Current number = 2
* Required number = 9 - 2 = 7
* 7 is found in the remaining array
* Indices stored = [0, 1]

Output:

```cpp
[0, 1]
```

### Time Complexity

* Outer loop runs `n` times.
* `find()` may take up to `n` comparisons.

Therefore, the overall time complexity is:

```cpp
O(n²)
```

### Space Complexity

Only the result vector is used, so the extra space complexity is:

```cpp
O(1)
```
