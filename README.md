# Array-implementation
Implementation of data structure - array

# Custom Array Implementation in C++

This project implements a dynamic array (similar to `std::vector`) from scratch in C++. It supports various features like adding, inserting, resizing, and iterating over elements, and also includes support for pairs (similar to `std::pair`). The array is templated to work with any data type.

## Features

- **Dynamic resizing:** Automatically resizes the array when it's full.
- **Custom types:** Supports any data type, including user-defined classes and structures.
- **Operator overloading:** Supports `[]` for accessing elements and comparison operators (`==`, `!=`).
- **Range-based for loop:** Allows iterating over the array using C++11 range-based for loops.
- **Move semantics:** Implements move constructor and move assignment for better performance with temporary objects.
- **Custom Pair class:** A lightweight version of `std::pair` for storing pairs of values in the array.

## How It Works

The Array class dynamically resizes when more elements are added than it can hold.
It supports copy and move semantics for better memory management.
The resize function ensures the array capacity grows by doubling its size when needed.
Elements are stored in contiguous memory, providing fast random access via the [] operator.

## Key Functions
Push_back(const type& element): Adds a new element to the end of the array.
Insert(size_t index, const type& element): Inserts an element at a specified index, shifting other elements.
Resize(size_t new_capacity): Resizes the internal storage array when the capacity is exceeded.
begin() and end(): Provides support for range-based loops.

## Requirements
C++11 or later
A modern C++ compiler such as g++, clang, or MSVC.

## Contribution
Contributions are welcome! If you want to add new features or fix bugs, feel free to fork the repository and submit a pull request.
