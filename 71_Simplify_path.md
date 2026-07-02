# 71. Simplify Path

## 🟢 Difficulty
Medium

## 📝 Problem Statement
Given an absolute Unix-style file path, simplify it into its canonical form.

Rules:
- `.` refers to the current directory.
- `..` moves to the parent directory.
- Multiple `/` are treated as a single `/`.
- Any other sequence (including `...`) is considered a valid directory name.

Return the simplified absolute path.

---

## 💡 Approach

Use a **stack** to simulate directory traversal.

1. Traverse the path and extract directory names between `/`.
2. Ignore:
   - Empty strings (caused by multiple `/`)
   - `.`
3. If the directory is `..`:
   - Pop from the stack if it isn't empty.
4. Otherwise:
   - Push the directory name onto the stack.
5. Build the final path by joining all stack elements with `/`.
6. If the stack is empty, return `/`.

---

## 🧠 Algorithm

1. Create an empty stack.
2. Traverse the path character by character.
3. Skip consecutive slashes.
4. Extract the current directory name.
5. Process:
   - `.` → Ignore
   - `..` → Pop if possible
   - Otherwise → Push into stack
6. Construct the answer from the stack.
7. Return `/` if the stack is empty.

---

## ⏱️ Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(n)`

where `n` is the length of the path.

---

## 🛠️ Concepts Used

- Stack
- String Parsing
- Simulation
- String Manipulation

---

## 🚀 Key Insight

The stack always stores the current valid directory path.

- Entering a directory → **Push**
- Going back (`..`) → **Pop**
- Staying in place (`.`) → **Ignore**

After processing the entire path, the stack contains the simplified canonical path.

---

## 📌 Example

**Input**
```text
path = "/home/user/Documents/../Pictures/"
```

**Processing**

```
home      -> Push
user      -> Push
Documents -> Push
..        -> Pop Documents
Pictures  -> Push
```

**Stack**

```
home
user
Pictures
```

**Output**

```text
"/home/user/Pictures"
```

---

## ✅ Solution Highlights

- Handles multiple consecutive slashes.
- Correctly processes `.` and `..`.
- Treats names like `...` as valid directories.
- Returns `/` when the final path is the root directory.
- Runs in linear time.