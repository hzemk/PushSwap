# Push_swap

## 📌 Overview

**Push_swap** is a sorting project from the 42 School curriculum, developed by hal-taha and leobeida.

The objective is to sort a stack of integers using a **limited set of stack operations**, while minimizing the number of moves.

The program takes integers as arguments and outputs the sequence of operations required to sort them in ascending order.

---

## ⚙️ Features

* Efficient sorting with minimal operations
* Handles small, medium, and large datasets
* Custom parsing and error handling
* Optimized algorithms depending on input size
* Benchmark/testing support

---

## 🧠 Algorithms

The project uses multiple strategies depending on input size:

* **Simple Algorithm**

  * Optimized for small datasets (≤ 5 numbers)

* **Medium Algorithm**

  * Chunk-based sorting strategy

* **Complex Algorithm**

  * Advanced optimization for large inputs

---

## 🛠️ Operations

The program uses only the allowed operations:

* `sa`, `sb`, `ss`
* `pa`, `pb`
* `ra`, `rb`, `rr`
* `rra`, `rrb`, `rrr`

---

## 👥 Contributors

This is a group project. Both contributors fully understand and can defend all parts of the code.

### 👨‍💻 hal-taha

* Adaptive
* Main function
* Flag handling (`flagcheck`)
* Stack operations implementation
* Simple sorting algorithm

### 👨‍💻 leobeida

* Parsing & validation
* Utility functions
* Medium algorithm
* Complex algorithm

---

## 🚀 Installation & Usage

### Clone repository

```bash
git clone git@github.com:42learners/Common-Core---Push_Swap-9233bf73-6072-4e07-812d-dfece7920e37.git
cd push_swap
```

### Compile

```bash
make
```

### Run

```bash
./push_swap 3 2 1
```

---

## 🧪 Testing

Example with checker:

```bash
ARG="4 67 3 87 23"
./push_swap $ARG | ./checker_OS $ARG
```

Expected output:

```
OK
```

---

## ⚠️ Error Handling

* Non-numeric arguments
* Duplicate numbers
* Overflow/underflow
* Empty input

All errors return:

```
Error
```

---

<h2>Descriptions</h2>

<p>
Push_swap is a project that sorts a stack of integers using a limited set of operations. The goal is to achieve the smallest number of moves possible. The program receives integers as command-line arguments and prints the operations needed to sort them in ascending order.
</p>

---

<h2>Instructions</h2>

<h3>Compilation</h3>

```bash
git clone git@github.com:42learners/Common-Core---Push_Swap-9233bf73-6072-4e07-812d-dfece7920e37.git
cd push_swap
make
```

<h3>Installation</h3>

<p>
After compilation, run the program directly using:
</p>

```bash
./push_swap 3 2 1
```

---

<h2>Resources</h2>

<ul>
<li>GeeksforGeeks</li>
<li>YouTube tutorials</li>
<li>W3Schools</li>
<li>Peer discussions</li>
<li>AI tools for testing and deeper algorithm understanding</li>
</ul>

---

## 📝 Notes

* Both contributors must be present during evaluation
* Each contributor can explain any part of the project
* You may be asked to modify or extend a feature during defense

---

## 🔗 Repository

```bash
git@github.com:42learners/Common-Core---Push_Swap-9233bf73-6072-4e07-812d-dfece7920e37.git
```

---

## ✅ Final Goal

Achieve the **lowest possible number of operations** while maintaining clean, efficient, and readable code.
