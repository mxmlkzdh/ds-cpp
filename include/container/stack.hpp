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
    
};

}