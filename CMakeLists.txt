cmake_minimum_required(VERSION 3.12)
project(project-euler)

set(CMAKE_CXX_STANDARD 14)

# Add MacPorts
include_directories(/opt/local/include)
link_directories(/opt/local/lib)
find_library(HAVE_GMP gmp)
find_library(HAVE_GMPXX gmpxx)

add_executable(euler-001 euler-001.cpp)
add_executable(euler-002 euler-002.cpp fibonacci.cpp fibonacci.h palindrome.cpp palindrome.h)
add_executable(euler-003 euler-003.cpp prime.cpp prime.h)
add_executable(euler-004 euler-004.cpp palindrome.cpp palindrome.h)
add_executable(euler-005 euler-005.cpp multiple.cpp multiple.h)
add_executable(euler-006 euler-006.cpp squares.cpp squares.h sum.cpp sum.h)
add_executable(euler-007 euler-007.cpp prime.cpp prime.h)
add_executable(euler-008 euler-008.cpp)
add_executable(euler-009 euler-009.cpp)
add_executable(euler-010 euler-010.cpp prime.cpp prime.h)
add_executable(euler-011 euler-011.cpp)
add_executable(euler-012 euler-012.cpp prime.cpp prime.h)
add_executable(euler-013 euler-013.cpp)
target_link_libraries(euler-013 PRIVATE gmpxx)
target_link_libraries(euler-013 PRIVATE gmp)
add_executable(euler-014 euler-014.cpp)
add_executable(euler-016 euler-016.cpp)
add_executable(euler-018 euler-018.cpp triangle.cpp triangle.h)
add_executable(euler-019 euler-019.cpp)
add_executable(euler-020 euler-020.cpp)
target_link_libraries(euler-020 PRIVATE gmpxx)
target_link_libraries(euler-020 PRIVATE gmp)
add_executable(euler-021 euler-021.cpp divisors.h)
add_executable(euler-022 euler-022.cpp)
add_executable(euler-023 euler-023.cpp divisors.h)
add_executable(euler-024 euler-024.cpp)
add_executable(euler-025 euler-025.cpp)
target_link_libraries(euler-025 PRIVATE gmpxx)
target_link_libraries(euler-025 PRIVATE gmp)
add_executable(euler-026 euler-026.cpp prime.cpp prime.h)
target_link_libraries(euler-026 PRIVATE gmpxx)
target_link_libraries(euler-026 PRIVATE gmp)
add_executable(euler-027 euler-027.cpp prime.cpp prime.h)
add_executable(euler-028 euler-028.cpp)
add_executable(euler-029+brute-force euler-029+brute-force.cpp prime.cpp prime.h)
target_link_libraries(euler-029+brute-force PRIVATE gmpxx)
target_link_libraries(euler-029+brute-force PRIVATE gmp)
add_executable(euler-029 euler-029.cpp prime.cpp prime.h)
add_executable(euler-030 euler-030.cpp)
add_executable(euler-031 euler-031.cpp)
add_executable(euler-032 euler-032.cpp)
add_executable(euler-033 euler-033.cpp multiple.cpp multiple.h)
add_executable(euler-067 euler-067.cpp triangle.cpp triangle.h)

# tests
include(CTest)

add_test(euler-001-runs euler-001)
set_tests_properties(euler-001-runs PROPERTIES PASS_REGULAR_EXPRESSION "^233168\n$")

add_test(euler-003-runs euler-003)
set_tests_properties(euler-003-runs PROPERTIES WILL_FAIL true)

add_test(euler-003-0 euler-003 0)
set_tests_properties(euler-003-0 PROPERTIES PASS_REGULAR_EXPRESSION "^0\n$")

add_test(euler-003-1 euler-003 1)
set_tests_properties(euler-003-1 PROPERTIES PASS_REGULAR_EXPRESSION "^0\n$")

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

add_test(euler-012-runs euler-012)
set_tests_properties(euler-012-runs PROPERTIES PASS_REGULAR_EXPRESSION "^76576500\n$")

add_test(euler-013-runs euler-013)
set_tests_properties(euler-013-runs PROPERTIES PASS_REGULAR_EXPRESSION "^5537376230\n$")

add_test(euler-014-runs euler-014)
set_tests_properties(euler-014-runs PROPERTIES PASS_REGULAR_EXPRESSION "^837799\n$")

add_test(euler-016-runs euler-016)
set_tests_properties(euler-016-runs PROPERTIES PASS_REGULAR_EXPRESSION "^1366\n$")

add_test(euler-018-runs euler-018)
set_tests_properties(euler-018-runs PROPERTIES PASS_REGULAR_EXPRESSION "^1074\n$")

add_test(euler-019-runs euler-019)
set_tests_properties(euler-019-runs PROPERTIES PASS_REGULAR_EXPRESSION "^171\n$")

add_test(euler-020-runs euler-020)
set_tests_properties(euler-020-runs PROPERTIES PASS_REGULAR_EXPRESSION "^648\n$")

add_test(euler-021-runs euler-021)
set_tests_properties(euler-021-runs PROPERTIES PASS_REGULAR_EXPRESSION "^31626\n$")

add_test(euler-022-runs euler-022 ${PROJECT_SOURCE_DIR}/p022_names.txt)
set_tests_properties(euler-022-runs PROPERTIES PASS_REGULAR_EXPRESSION "^871198282\n$")

add_test(euler-023-runs euler-023)
set_tests_properties(euler-023-runs PROPERTIES PASS_REGULAR_EXPRESSION "^4179871\n$")

add_test(euler-024-runs euler-024)
set_tests_properties(euler-024-runs PROPERTIES PASS_REGULAR_EXPRESSION "^2783915460\n$")

add_test(euler-025-runs euler-025)
set_tests_properties(euler-025-runs PROPERTIES PASS_REGULAR_EXPRESSION "^4782\n$")

add_test(euler-026-runs euler-026)
set_tests_properties(euler-026-runs PROPERTIES PASS_REGULAR_EXPRESSION "^983\n$")

add_test(euler-027-runs euler-027)
set_tests_properties(euler-027-runs PROPERTIES PASS_REGULAR_EXPRESSION "^-59231\n$")

add_test(euler-028-runs euler-028)
set_tests_properties(euler-028-runs PROPERTIES PASS_REGULAR_EXPRESSION "^669171001\n$")

add_test(euler-029+brute-force-runs euler-029+brute-force)
set_tests_properties(euler-029+brute-force-runs PROPERTIES PASS_REGULAR_EXPRESSION "^9183\n$")

add_test(euler-029-runs euler-029)
set_tests_properties(euler-029-runs PROPERTIES PASS_REGULAR_EXPRESSION "^9183\n$")

add_test(euler-030-runs euler-030)
set_tests_properties(euler-030-runs PROPERTIES PASS_REGULAR_EXPRESSION "^443839\n$")

add_test(euler-031-runs euler-031)
set_tests_properties(euler-031-runs PROPERTIES PASS_REGULAR_EXPRESSION "^73682\n$")

add_test(euler-032-runs euler-032)
set_tests_properties(euler-032-runs PROPERTIES PASS_REGULAR_EXPRESSION "^45228\n$")

add_test(euler-033-runs euler-033)
set_tests_properties(euler-033-runs PROPERTIES PASS_REGULAR_EXPRESSION "^100\n$")

add_test(euler-067-runs euler-067 ${PROJECT_SOURCE_DIR}/p067_triangle.txt)
set_tests_properties(euler-067-runs PROPERTIES PASS_REGULAR_EXPRESSION "^7273\n$")
