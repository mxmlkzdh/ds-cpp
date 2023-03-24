#pragma once

#include <cstddef>
#include <spdlog/spdlog.h>

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
    ValueType* mData;
    SizeType mSize;
    SizeType mCapacity;

    void reAlloc(SizeType newSize) {
        spdlog::debug("reAlloc with the new size {}.", newSize);
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
    Vector(): mData(nullptr), mSize(0), mCapacity(0) {
        spdlog::debug("Vector creations starts.");
        reAlloc(INIT_CAPACITY);
        spdlog::debug("Vector created.");
    }
    ~Vector() {
        spdlog::debug("Vector destruction starts.");
        delete[] mData;
        spdlog::debug("Vector destroyed.");
    }
    Vector(const Vector& other) = default;
    Vector(Vector&& other) = default;
    Vector& operator=(const Vector& other) = default;
    Vector& operator=(Vector&& other) = default;

    // Element Access
    Reference operator[](const SizeType index) {
        return mData[index];
    }
    ConstReference operator[](const SizeType index) const {
        return mData[index];
    }
    Reference front() {
        if (empty()) {
            throw("Empty array!");
        }
        return mData[0];
    }
    ConstReference front() const {
        if (empty()) {
            throw("Empty array!");
        }
        return mData[0];
    }
    Reference back() {
        if (empty()) {
            throw("Empty array!");
        }
        return mData[mSize - 1];
    }
    ConstReference back() const {
        if (empty()) {
            throw("Empty array!");
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
    void emplace_back(Reference value) {
        if (mSize == mCapacity) {
            reAlloc(mSize * 2);
        }
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
