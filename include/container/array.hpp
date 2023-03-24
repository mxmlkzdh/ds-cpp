#pragma once

#include <cstddef>

namespace Max {

template <typename _T, std::size_t _Size>
class Array {

    static_assert(_Size > 0, "Size of Max::Array cannot be negative.");

    using SizeType = std::size_t;
    using ValueType = _T;
    using Reference = ValueType&;
    using ConstReference = const _T&;
    using Pointer = ValueType*;
    using ConstPointer = const _T*;

private:
    ValueType mData[_Size];

public:

    // Special Members
    Array() = default;
    ~Array() = default;
    Array(const Array& other) = default;
    Array(Array&& other) noexcept = default;
    Array& operator=(const Array& other) = default;
    Array& operator=(Array&& other) noexcept = default;

    void fill(ConstReference data) {
        for (SizeType i = 0; i < _Size; i++) {
            mData[i] = data;
        }
    }

    // Element Access
    Reference operator[](const SizeType index) {
        return mData[index];
    }
    ConstReference operator[](const SizeType index) const {
        return mData[index];
    }
    Reference at(const SizeType index) {
        if (index >= _Size) {
            throw("Index out of bound!");
        }
        return mData[index];
    }
    ConstReference at(const SizeType index) const {
        if (index >= _Size) {
            throw("Index out of bound!");
        }
        return mData[index];
    }
    Reference front() {
        return mData[0];
    }
    ConstReference front() const {
        return mData[0];
    }
    Reference back() {
        return mData[_Size - 1];
    }
    ConstReference back() const {
        return mData[_Size - 1];
    }
    /// @brief Get the pointer to the first element in the array.
    /// @return The pointer to the first element in the array.
    Pointer data() noexcept {
        return mData;
    }
    /// @brief Get the const pointer to the first element in the array.
    /// @return The const pointer to the first element in the array.
    ConstPointer data() const noexcept {
        return mData;
    }

    /// @brief Get the size of the array.
    /// @return The size of the array.
    SizeType size() const {
        return _Size;
    }

};

}
