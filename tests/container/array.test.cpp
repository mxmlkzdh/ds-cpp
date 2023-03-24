#include "container/array.hpp"
#include <gtest/gtest.h>
#include <string>

TEST(MaxArray, ArraySize) {
    Max::Array<int, 17> tempArray;
    EXPECT_EQ(tempArray.size(), 17);
}

TEST(MaxArray, SizeOfArray) {
    Max::Array<std::string, 23> tempArray;
    EXPECT_EQ(sizeof(tempArray), sizeof(std::string) * tempArray.size());
}

TEST(MaxArray, Front) {
    Max::Array<int, 3> tempArray;
    tempArray[0] = 11;
    tempArray[1] = 15;
    tempArray[2] = 19;
    EXPECT_EQ(tempArray.front(), 11);
}

TEST(MaxArray, Back) {
    Max::Array<int, 3> tempArray;
    tempArray[0] = 11;
    tempArray[1] = 15;
    tempArray[2] = 19;
    EXPECT_EQ(tempArray.back(), 19);
}

TEST(MaxArray, Data) {
    Max::Array<int, 5> tempArray;
    tempArray[3] = 15;
    EXPECT_EQ(*(tempArray.data() + 3), 15);
}

TEST(MaxArray, EmptyArrayFront) {
    Max::Array<int, 0> tempArray;
    EXPECT_THROW(tempArray.front(), const char*);
}

TEST(MaxArray, EmptyArrayBack) {
    Max::Array<int, 0> tempArray;
    EXPECT_THROW(tempArray.back(), const char*);
}

TEST(MaxArray, OutOfBounds) {
    Max::Array<int, 3> tempArray;
    EXPECT_THROW(tempArray.at(4), const char*);
}