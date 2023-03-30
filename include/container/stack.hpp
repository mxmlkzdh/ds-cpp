#pragma once

#include <cstddef>

namespace Max {

template <typename _T>
class Stack {

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
    Stack() {
        reAlloc(INIT_CAPACITY);
    };
    ~Stack() {
        delete[] mData;
    };
    Stack(const Stack& other) = default;
    Stack(Stack&& other) noexcept = default;
    Stack& operator=(const Stack& other) = default;
    Stack& operator=(Stack&& other) noexcept = default;

    Reference peek() {
        if (empty()) {
            throw("Empty stack!");
        }
        return mData[mSize - 1];
    }

    ConstReference peek() const {
        if (empty()) {
            throw("Empty stack!");
        }
        return mData[mSize - 1];
    }

    Reference pop() {
        if (empty()) {
            throw("Empty stack!");
        }
        //ToDo: Implement this!
    }

    void push(ConstReference value) {
        if (mSize == mCapacity) {
            reAlloc(mSize * 2);
        }
        mData[mSize++] = value;
    }
    void push(TemporaryReference value) {
        if (mSize == mCapacity) {
            reAlloc(mSize * 2);
        }
        mData[mSize++] = std::move(value);
    }

    /// @brief Get the size of the stack.
    /// @return The size of the stack.
    SizeType size() const {
        return mSize;
    }

    /// @brief Indicates if the stack is empty.
    /// @return true if stack is empty and false otherwise.
    bool empty() const {
        return mSize == 0;
    }

};

}