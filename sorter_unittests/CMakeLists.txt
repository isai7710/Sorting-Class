set(This sorter_unittests)
add_executable(${This} sorter_unittests.cpp)

target_link_libraries(${This} PRIVATE GTest::gtest_main Sorter)

include(GoogleTest)
gtest_discover_tests(${This})