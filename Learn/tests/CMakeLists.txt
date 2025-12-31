# tests/CMakeLists.txt
add_executable(test_sort src/test_sort.cpp)

# Link with your library
target_link_libraries(test_sort PRIVATE SusAlgos)

# Optional: enable CTest
enable_testing()
add_test(NAME SortTest COMMAND test_sort)
