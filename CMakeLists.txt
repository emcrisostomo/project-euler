cmake_minimum_required(VERSION 3.12)
project(project-euler)

set(CMAKE_CXX_STANDARD 14)

add_executable(euler-001 euler-001.cpp)
add_executable(euler-002 euler-002.cpp fibonacci.cpp fibonacci.h palindrome.cpp palindrome.h)
add_executable(euler-003 euler-003.cpp multiple.cpp multiple.h)
add_executable(euler-004 euler-004.cpp palindrome.cpp palindrome.h)
add_executable(euler-005 euler-005.cpp multiple.cpp multiple.h)
add_executable(euler-006 euler-006.cpp squares.cpp squares.h sum.cpp sum.h)
add_executable(euler-007 euler-007.cpp prime.cpp prime.h)
add_executable(euler-008 euler-008.cpp)
add_executable(euler-009 euler-009.cpp)
add_executable(euler-010 euler-010.cpp prime.cpp prime.h)
add_executable(euler-011 euler-011.cpp)
add_executable(euler-012 euler-012.cpp)

# tests
include(CTest)

add_test(euler-001-runs euler-001)
set_tests_properties(euler-001-runs PROPERTIES PASS_REGULAR_EXPRESSION "^233168\n$")

add_test(euler-003-runs euler-003)
set_tests_properties(euler-003-runs PROPERTIES WILL_FAIL true)

add_test(euler-003-0 euler-003 0)
set_tests_properties(euler-003-0 PROPERTIES PASS_REGULAR_EXPRESSION "^0\n$")

add_test(euler-003-1 euler-003 1)
set_tests_properties(euler-003-1 PROPERTIES PASS_REGULAR_EXPRESSION "^1\n$")

add_test(euler-003-2 euler-003 2)
set_tests_properties(euler-003-2 PROPERTIES PASS_REGULAR_EXPRESSION "^2\n$")

add_test(euler-003-3 euler-003 3)
set_tests_properties(euler-003-3 PROPERTIES PASS_REGULAR_EXPRESSION "^3\n$")

add_test(euler-003-4 euler-003 4)
set_tests_properties(euler-003-4 PROPERTIES PASS_REGULAR_EXPRESSION "^2\n$")

add_test(euler-003-13195 euler-003 13195)
set_tests_properties(euler-003-13195 PROPERTIES PASS_REGULAR_EXPRESSION "^29\n$")

add_test(euler-003-600851475143 euler-003 600851475143)
set_tests_properties(euler-003-600851475143 PROPERTIES PASS_REGULAR_EXPRESSION "^6857\n$")

add_test(euler-007-runs euler-007)
set_tests_properties(euler-007-runs PROPERTIES PASS_REGULAR_EXPRESSION "^104743\n$")

add_test(euler-010-runs euler-010)
set_tests_properties(euler-010-runs PROPERTIES PASS_REGULAR_EXPRESSION "^142913828922\n$")

add_test(euler-011-runs euler-011)
set_tests_properties(euler-011-runs PROPERTIES PASS_REGULAR_EXPRESSION "^70600674\n$")