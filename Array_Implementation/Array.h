#pragma once
#include <stdexcept>
#include <cstring>
#include <initializer_list>

template<typename type>
class Array {
private:
    type* arr;
    size_t size;
    size_t capacity;

    void resize(size_t new_capacity) {
        type* new_arr = new type[new_capacity];
        std::memcpy(new_arr, arr, size * sizeof(type));
        delete[] arr;
        arr = new_arr;
        capacity = new_capacity;
    }

public:
    Array(std::initializer_list<type> list) : size(list.size()), capacity(list.size() * 2), arr(new type[++capacity]) {
        size_t i = 0;
        for (const auto& el : list) {
            arr[i++] = el;
        }
    }

    Array(size_t Init_capacity = 2) : size(0), capacity(Init_capacity), arr(new type[capacity]) {}

    ~Array() {
        delete[] arr;
        arr = nullptr;
    }

    Array(const Array& other) : size(other.size), capacity(other.capacity) {
        arr = new type[capacity];
        std::memcpy(arr, other.arr, size * sizeof(type));
    }

    Array& operator=(const Array& other) noexcept {
        if (this == &other) {
            return *this;
        }
        delete[] arr;
        size = other.size;
        capacity = other.capacity;
        arr = new type[capacity];
        std::memcpy(arr, other.arr, size * sizeof(type));
        return *this;
    }

    Array(Array&& other) noexcept : arr(other.arr), size(other.size), capacity(other.capacity) {
        other.arr = nullptr;
        other.size = 0;
        other.capacity = 0;
    }

    Array& operator=(Array&& other) noexcept {
        if (this == &other) {
            return *this;
        }
        delete[] arr;

        arr = other.arr;
        size = other.size;
        capacity = other.capacity;

        other.arr = nullptr;
        other.size = 0;
        other.capacity = 0;

        return *this;
    }

    type& operator[](size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of bounds");
        }
        return arr[index];
    }

    friend bool operator==(const Array<type>& arr1, const Array<type>& arr2) {
        if (arr1.size != arr2.size) {
            return false;
        }
        for (size_t i = 0; i < arr1.size; ++i) {
            if (arr1[i] != arr2[i]) {
                return false;
            }
        }
        return true;
    }

    friend bool operator!=(const Array<type>& arr1, const Array<type>& arr2) {
        return !(arr1 == arr2);
    }

    inline void Push_back(const type& element) noexcept {
        if (size == capacity) {
            resize(capacity == 0 ? 1 : capacity * 2);
        }
        arr[size++] = element;
    }

    inline void Pop_back() {
        if (size == 0) {
            throw std::out_of_range("Array is empty");
        }
        --size;
    }

    void erase(size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of bounds");
        }
        for (size_t i = index; i < size - 1; ++i) {
            arr[i] = arr[i + 1];
        }
        --size;
    }

    void insert(const type& element, size_t index) {
        if (index > size) {
            throw std::out_of_range("Index out of bounds");
        }
        if (size == capacity) {
            resize(capacity * 2);
        }
        for (size_t i = size; i > index; --i) {
            arr[i] = arr[i - 1];
        }
        arr[index] = element;
        ++size;
    }

    bool IsEmpty() const noexcept {
        return size == 0;
    }

    void clear() noexcept {
        arr = {};
        size = 0;
    }

    type* begin() {
        return arr;
    }
    const type* begin() const {
        return arr;
    }

    type* end() {
        return arr + size;
    }
    const type* end() const {
        return arr + size;
    }

    size_t Size() const noexcept {
        return size;
    }
    size_t GetCapacity() const noexcept {
        return capacity;
    }
};

template<typename type1, typename type2>
class Pair {
public:
    type1 first;
    type2 second;
    Pair() : first(type1()), second(type2()) {}
    Pair(const type1& f, const type2& s) : first(f), second(s) {}

    bool operator==(const Pair& other) const {
        return first == other.first && second == other.second;
    }

    bool operator!=(const Pair& other) const {
        return !(*this == other);
    }
};
