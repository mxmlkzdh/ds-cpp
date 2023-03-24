#include "container/vector.hpp"
#include <gtest/gtest.h>
#include <string>

TEST(MaxVector, VectorSizePush) {
    Max::Vector<int> tempVector;
    tempVector.push_back(1);
    tempVector.push_back(2);
    tempVector.push_back(3);
    tempVector.push_back(4);
    tempVector.push_back(5);
    EXPECT_EQ(tempVector.size(), 5);
}

TEST(MaxVector, VectorSizeEmplace) {
    Max::Vector<int> tempVector;
    tempVector.emplace_back(1);
    tempVector.emplace_back(2);
    tempVector.emplace_back(3);
    EXPECT_EQ(tempVector.size(), 3);
}

TEST(MaxVector, VectorCapacity) {
    Max::Vector<int> tempVector;
    tempVector.push_back(1);
    tempVector.push_back(2);
    tempVector.push_back(3);
    tempVector.push_back(4);
    tempVector.push_back(5);
    EXPECT_EQ(tempVector.capacity(), 8);
}

TEST(MaxVector, Front) {
    Max::Vector<int> tempVector;
    tempVector.push_back(1);
    tempVector.push_back(2);
    tempVector.push_back(3);
    EXPECT_EQ(tempVector.front(), 1);
}

TEST(MaxVector, Back) {
    Max::Vector<int> tempVector;
    tempVector.push_back(1);
    tempVector.push_back(2);
    tempVector.push_back(3);
    EXPECT_EQ(tempVector.back(), 3);
}

TEST(MaxVector, EmptyVectorFront) {
    Max::Vector<int> tempVector;
    EXPECT_THROW(tempVector.front(), const char*);
}

TEST(MaxVector, EmptyVectorBack) {
    Max::Vector<int> tempVector;
    EXPECT_THROW(tempVector.back(), const char*);
}

TEST(MaxVector, OutOfBounds) {
    Max::Vector<int> tempVector;
    tempVector.push_back(1);
    tempVector.push_back(2);
    tempVector.push_back(3);
    EXPECT_THROW(tempVector.at(4), const char*);
}

TEST(MaxVector, At) {
    Max::Vector<int> tempVector;
    tempVector.push_back(1);
    tempVector.push_back(21);
    tempVector.push_back(3);
    EXPECT_EQ(tempVector.at(1), 21);
}