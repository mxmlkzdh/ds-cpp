project(ds)

# add_executable(array.test container/array.test.cpp)
# add_test(NAME Array COMMAND array.test)

# add_executable(vector.test container/vector.test.cpp)
# add_test(NAME Vector COMMAND vector.test)

include(FetchContent)
FetchContent_Declare(googletest URL https://github.com/google/googletest/archive/974e18ee6f146a2418f9cea83170c640e7d622d6.zip)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(array.test container/array.test.cpp)
target_link_libraries(array.test GTest::gtest_main)
add_executable(vector.test container/vector.test.cpp)
target_link_libraries(vector.test GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(array.test)
gtest_discover_tests(vector.test)