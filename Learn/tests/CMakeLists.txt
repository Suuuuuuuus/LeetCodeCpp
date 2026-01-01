# tests/CMakeLists.txt
add_executable(test_sort src/test_sort.cpp)
add_executable(test_datstruc src/test_datstruc.cpp)

# Link with your library
target_link_libraries(test_sort PRIVATE SusAlgos)
target_link_libraries(test_datstruc PRIVATE SusAlgos)

# # Optional: enable CTest
enable_testing()
add_test(NAME SortTest COMMAND test_sort)
add_test(NAME DatStrucTest COMMAND test_datstruc)
 