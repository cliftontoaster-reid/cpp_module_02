# C++ Module 02: Fixed-Point Numbers and BSP

This project is part of the 42 curriculum and serves as an introduction to fixed-point number representation and its practical application in C++. The module is divided into three exercises, progressively building a `Fixed` class and then using it to implement a Binary Space Partitioning (BSP) based point-in-triangle test.

## Exercises

### Exercise 00: A Class in Orthodox Canonical Form

This exercise introduces the `Fixed` class, which represents a fixed-point number.

- **Orthodox Canonical Form**: The class is implemented following the canonical requirements, including a default constructor, a copy constructor, a copy assignment operator, and a destructor.
- **Constructors**: It includes constructors to convert from `int` and `float` types into the internal fixed-point representation (8 fractional bits).
- **`toFloat()`**: A member function to convert the fixed-point value back to a `float`.
- **Stream Operator**: The `<<` operator is overloaded to allow easy printing of `Fixed` objects to output streams.

### Exercise 01: Towards a More Useful Fixed-Point Number Class

This exercise extends the `Fixed` class with more functionality to make it more practical.

- **Comparison Operators**: Overloads for `>`, `<`, `>=`, `<=`, `==`, and `!=`.
- **Arithmetic Operators**: Overloads for `+`, `-`, `*`, and `/`.
- **Increment/Decrement Operators**: Prefix and postfix versions of `++` and `--`.
- **Static Functions**: `min` and `max` functions to compare two `Fixed` numbers.

### Exercise 02: BSP (Binary Space Partitioning)

This exercise applies the `Fixed` class to a geometrical problem.

- **`Point` Class**: A simple `Point` class is created, using `Fixed` numbers for its `x` and `y` coordinates.
- **`bsp` Function**: A function `bsp(a, b, c, point)` is implemented to determine if a given `point` is strictly inside the triangle defined by vertices `a`, `b`, and `c`.
  - It uses the cross-product method to determine which side of each triangle edge the point lies on.
  - The function returns `true` only if the point is strictly inside the triangle; points on the edges or vertices are considered outside.

## How to Compile and Run

Each exercise is self-contained in its own directory (`ex00`, `ex01`, `ex02`) and includes a `Makefile`.

To compile and run an exercise:

1.  Navigate to the exercise directory:
    ```bash
    cd ex01
    ```
2.  Use the `Makefile` to build the executable:
    ```bash
    make
    ```
3.  Run the demonstration program:
    ```bash
    ./fixed
    ```
4.  To clean up all generated files:
    ```bash
    make fclean
    ```
