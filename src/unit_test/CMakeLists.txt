add_executable(connect_exchange_test connect_exchange_test.cpp)
target_compile_options(connect_exchange_test PRIVATE -g -O0 --coverage -fprofile-arcs -ftest-coverage)
target_link_libraries(connect_exchange_test GTest::gtest_main gcov libcoinexchange)
gtest_discover_tests(connect_exchange_test)
