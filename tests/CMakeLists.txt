project(ds)

add_executable(array.test container/array.test.cpp)
add_test(NAME Array COMMAND array.test)

add_executable(vector.test container/vector.test.cpp)
add_test(NAME Vector COMMAND vector.test)
