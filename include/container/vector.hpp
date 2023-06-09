#pragma once

#include <cstddef>

namespace Max {

template <typename _T>
class Vector {

    using SizeType = std::size_t;
    using ValueType = _T;
    using Reference = ValueType&;
    using ConstReference = const _T&;
    using Pointer = ValueType*;
    using ConstPointer = const _T*;
    using TemporaryReference = ValueType&&;

private:

    static const int INIT_CAPACITY = 2;
    ValueType* mData = nullptr;
    SizeType mSize = 0;
    SizeType mCapacity = 0;

    void reAlloc(SizeType newSize) {
        ValueType* temp = new ValueType[newSize];
        for (size_t i = 0; i < mSize; i++) {
            temp[i] = std::move(mData[i]);
        }
        delete[] mData;
        mData = temp;
        mCapacity = newSize;
    }

public:
    // Special Members
    Vector() {
        reAlloc(INIT_CAPACITY);
    }
    ~Vector() {
        delete[] mData;
    }
    Vector(const Vector& other) = default;
    Vector(Vector&& other) noexcept = default;
    Vector& operator=(const Vector& other) = default;
    Vector& operator=(Vector&& other) noexcept= default;

    // Element Access
    Reference operator[](const SizeType index) {
        return mData[index];
    }
    ConstReference operator[](const SizeType index) const {
        return mData[index];
    }
    Reference at(const SizeType index) {
        if (index >= mSize) {
            throw("Index out of bound!");
        }
        return mData[index];
    }
    ConstReference at(const SizeType index) const {
        if (index >= mSize) {
            throw("Index out of bound!");
        }
        return mData[index];
    }
    Reference front() {
        if (empty()) {
            throw("Empty vector!");
        }
        return mData[0];
    }
    ConstReference front() const {
        if (empty()) {
            throw("Empty vector!");
        }
        return mData[0];
    }
    Reference back() {
        if (empty()) {
            throw("Empty vector!");
        }
        return mData[mSize - 1];
    }
    ConstReference back() const {
        if (empty()) {
            throw("Empty vector!");
        }
        return mData[mSize - 1];
    }

    // Element Insertion
    void push_back(ConstReference value) {
        if (mSize == mCapacity) {
            reAlloc(mSize * 2);
        }
        mData[mSize++] = std::move(value);
    }
    void push_back(TemporaryReference value) {
        if (mSize == mCapacity) {
            reAlloc(mSize * 2);
        }
        mData[mSize++] = std::move(value);
    }
    template<typename... Args>
    Reference emplace_back(Args&&... args) {
        if (mSize == mCapacity) {
            reAlloc(mSize * 2);
        }
        new(&mData[mSize]) ValueType(std::forward<Args>(args) ...);
        return mData[mSize++];
    }

    /// @brief Get the capacity of the vector.
    /// @return The capacity of the vector.
    SizeType capacity() const {
        return mCapacity;
    }
    /// @brief Get the size of the vector.
    /// @return The size of the vector.
    SizeType size() const {
        return mSize;
    }

    /// @brief Indicates if the vector is empty.
    /// @return true if vector is empty and false otherwise.
    bool empty() const {
        return mSize == 0;
    }

};

}
