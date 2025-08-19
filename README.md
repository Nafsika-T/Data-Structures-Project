# 📚 Data Structures Word Search Project

This project implements and compares the performance of various **data structures** for word search operations on a large text file (`gutenberg.txt`, ~10,000 words).

The implementation is done **without the use of external libraries**, except for the C++ `<algorithm>` library, used **only** for converting lowercase to uppercase characters.

---

## 🧠 Implemented Data Structures

1. **Unsorted Array** (`UnSorted`)
2. **Sorted Array** (`Sorted`)
3. **Hash Table** (`HashTable`)
4. **Binary Search Tree (BST)`**
5. **Balanced Binary Search Tree (AVL Tree)`**

---

## 🧪 Description

- The program reads and cleans each word from the file.
- It inserts all words into each structure using their respective `insert` methods.
- Then, a query array `Q` of 10,000 words is formed (sampled uniformly).
- Each word in `Q` is searched in each structure using its own `search` method.
- Total search time for each structure is recorded and printed.

---

## ⚙️ Notes

- All implementations are custom-built in C++.
- The project uses `algorithm` **only for uppercase transformation**, not for sorting or search.
- No external libraries or STL containers like `map`, `set`, etc. are used.
- All classes include explanatory comments within the source code.

---

## 📁 File Structure

| File              | Description                                      |
|-------------------|--------------------------------------------------|
| `main.cpp`        | Main program logic                               |
| `UnSorted.h/cpp`  | Unsorted array structure                         |
| `Sorted.h/cpp`    | Sorted array structure                           |
| `HashTable.h/cpp` | Hash table implementation                        |
| `BST.h/cpp`       | Binary Search Tree                               |
| `AVL.h/cpp`       | Balanced AVL Tree (inherits from BST)           |
| `clean.h`         | String cleaning function (punctuation + casing) |
| `gutenberg.txt`   | Input file (not included in repo)                |

---

## 📝 License

This project is for academic and educational purposes.
