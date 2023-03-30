#include "container/stack.hpp"
#include <gtest/gtest.h>
#include <string>

TEST(MaxStack, EmptyStackPeek) {
    Max::Stack<int> tempStack;
    EXPECT_THROW(tempStack.peek(), const char*);
}