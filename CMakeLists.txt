cmake_minimum_required(VERSION 3.12)
project(project-euler)

set(CMAKE_CXX_STANDARD 14)

# Add MacPorts
include_directories(/opt/local/include)
include_directories(${PROJECT_SOURCE_DIR}/src)
link_directories(/opt/local/lib)
find_library(HAVE_GMP gmp)
find_library(HAVE_GMPXX gmpxx)

add_executable(euler-001 src/001-050/euler-001.cpp)
add_executable(euler-002 src/001-050/euler-002.cpp src/fibonacci.cpp src/fibonacci.h src/number.h src/factorial.h)
add_executable(euler-003 src/001-050/euler-003.cpp src/prime.cpp src/prime.h)
add_executable(euler-004 src/001-050/euler-004.cpp src/number.h)
add_executable(euler-005 src/001-050/euler-005.cpp src/multiple.cpp src/multiple.h)
add_executable(euler-006 src/001-050/euler-006.cpp src/squares.cpp src/squares.h src/sum.cpp src/sum.h)
add_executable(euler-007 src/001-050/euler-007.cpp src/prime.cpp src/prime.h)
add_executable(euler-008 src/001-050/euler-008.cpp)
add_executable(euler-009 src/001-050/euler-009.cpp)
add_executable(euler-010 src/001-050/euler-010.cpp src/prime.cpp src/prime.h)
add_executable(euler-011 src/001-050/euler-011.cpp)
add_executable(euler-012 src/001-050/euler-012.cpp src/prime.cpp src/prime.h)
add_executable(euler-013 src/001-050/euler-013.cpp)
target_link_libraries(euler-013 PRIVATE gmpxx)
target_link_libraries(euler-013 PRIVATE gmp)
add_executable(euler-014 src/001-050/euler-014.cpp)
add_executable(euler-016 src/001-050/euler-016.cpp)
add_executable(euler-018 src/001-050/euler-018.cpp src/triangle.cpp src/triangle.h)
add_executable(euler-019 src/001-050/euler-019.cpp)
add_executable(euler-020 src/001-050/euler-020.cpp src/factorial.h)
target_link_libraries(euler-020 PRIVATE gmpxx)
target_link_libraries(euler-020 PRIVATE gmp)
add_executable(euler-021 src/001-050/euler-021.cpp src/divisors.h)
add_executable(euler-022 src/001-050/euler-022.cpp)
add_executable(euler-023 src/001-050/euler-023.cpp src/divisors.h)
add_executable(euler-024+brute-force src/001-050/euler-024+brute-force.cpp)
add_executable(euler-024 src/001-050/euler-024.cpp)
add_executable(euler-025 src/001-050/euler-025.cpp)
target_link_libraries(euler-025 PRIVATE gmpxx)
target_link_libraries(euler-025 PRIVATE gmp)
add_executable(euler-026 src/001-050/euler-026.cpp src/prime.cpp src/prime.h)
target_link_libraries(euler-026 PRIVATE gmpxx)
target_link_libraries(euler-026 PRIVATE gmp)
add_executable(euler-027 src/001-050/euler-027.cpp src/prime.cpp src/prime.h)
add_executable(euler-028 src/001-050/euler-028.cpp)
add_executable(euler-029+brute-force src/001-050/euler-029+brute-force.cpp src/prime.cpp src/prime.h)
target_link_libraries(euler-029+brute-force PRIVATE gmpxx)
target_link_libraries(euler-029+brute-force PRIVATE gmp)
add_executable(euler-029 src/001-050/euler-029.cpp src/prime.cpp src/prime.h)
add_executable(euler-030 src/001-050/euler-030.cpp)
add_executable(euler-031 src/001-050/euler-031.cpp)
add_executable(euler-032 src/001-050/euler-032.cpp src/number.h)
add_executable(euler-033 src/001-050/euler-033.cpp src/multiple.cpp src/multiple.h)
add_executable(euler-034 src/001-050/euler-034.cpp src/factorial.h)
add_executable(euler-035 src/001-050/euler-035.cpp src/prime.h src/prime.cpp)
add_executable(euler-036 src/001-050/euler-036.cpp src/number.h)
add_executable(euler-037 src/001-050/euler-037.cpp src/prime.h src/prime.cpp src/number.h)
add_executable(euler-038 src/001-050/euler-038.cpp src/number.h)
add_executable(euler-039+brute-force src/001-050/euler-039+brute-force.cpp)
add_executable(euler-039 src/001-050/euler-039.cpp)
add_executable(euler-040+brute-force src/001-050/euler-040+brute-force.cpp src/number.h)
add_executable(euler-040 src/001-050/euler-040.cpp src/number.h)
add_executable(euler-041 src/001-050/euler-041.cpp src/number.h src/prime.h src/prime.cpp)
add_executable(euler-042 src/001-050/euler-042.cpp src/number.h)
add_executable(euler-043 src/001-050/euler-043.cpp src/number.h)
add_executable(euler-044 src/001-050/euler-044.cpp src/number.h)
add_executable(euler-045 src/001-050/euler-045.cpp src/number.h)
add_executable(euler-046 src/001-050/euler-046.cpp src/prime.h src/prime.cpp)
add_executable(euler-047 src/001-050/euler-047.cpp src/prime.h src/prime.cpp)
add_executable(euler-048 src/001-050/euler-048.cpp)
add_executable(euler-049 src/001-050/euler-049.cpp src/number.h src/prime.h src/prime.cpp)
add_executable(euler-050+brute-force src/001-050/euler-050+brute-force.cpp src/prime.h src/prime.cpp)
add_executable(euler-050 src/001-050/euler-050.cpp src/prime.h src/prime.cpp)
add_executable(euler-051 src/051-100/euler-051.cpp src/prime.h src/prime.cpp)
add_executable(euler-052 src/051-100/euler-052.cpp src/number.h)
add_executable(euler-053 src/051-100/euler-053.cpp)
add_executable(euler-054 src/051-100/euler-054.cpp src/poker/card.cpp src/poker/card.h src/poker/hand.cpp src/poker/hand.h)
add_executable(euler-055 src/051-100/euler-055.cpp src/number.h)
add_executable(euler-056 src/051-100/euler-056.cpp)
target_link_libraries(euler-056 PRIVATE gmpxx)
target_link_libraries(euler-056 PRIVATE gmp)
add_executable(euler-057 src/051-100/euler-057.cpp)
add_executable(euler-067 src/051-100/euler-067.cpp src/triangle.cpp src/triangle.h)

# tests
include(CTest)

add_test(euler-001 euler-001)
set_tests_properties(euler-001 PROPERTIES PASS_REGULAR_EXPRESSION "^233168\n$")

add_test(euler-002 euler-002)
set_tests_properties(euler-002 PROPERTIES PASS_REGULAR_EXPRESSION "^4613732\n$")

add_test(euler-003 euler-003)
set_tests_properties(euler-003 PROPERTIES WILL_FAIL true)

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

add_test(euler-004 euler-004)
set_tests_properties(euler-004 PROPERTIES PASS_REGULAR_EXPRESSION "^906609\n$")

add_test(euler-005 euler-005)
set_tests_properties(euler-005 PROPERTIES PASS_REGULAR_EXPRESSION "^232792560\n$")

add_test(euler-006 euler-006)
set_tests_properties(euler-006 PROPERTIES PASS_REGULAR_EXPRESSION "^25164150\n$")

add_test(euler-007 euler-007)
set_tests_properties(euler-007 PROPERTIES PASS_REGULAR_EXPRESSION "^104743\n$")

add_test(euler-008 euler-008)
set_tests_properties(euler-008 PROPERTIES PASS_REGULAR_EXPRESSION "^23514624000\n$")

add_test(euler-009 euler-009)
set_tests_properties(euler-009 PROPERTIES PASS_REGULAR_EXPRESSION "^31875000\n$")

add_test(euler-010 euler-010)
set_tests_properties(euler-010 PROPERTIES PASS_REGULAR_EXPRESSION "^142913828922\n$")

add_test(euler-011 euler-011)
set_tests_properties(euler-011 PROPERTIES PASS_REGULAR_EXPRESSION "^70600674\n$")

add_test(euler-012 euler-012)
set_tests_properties(euler-012 PROPERTIES PASS_REGULAR_EXPRESSION "^76576500\n$")

add_test(euler-013 euler-013)
set_tests_properties(euler-013 PROPERTIES PASS_REGULAR_EXPRESSION "^5537376230\n$")

add_test(euler-014 euler-014)
set_tests_properties(euler-014 PROPERTIES PASS_REGULAR_EXPRESSION "^837799\n$")

add_test(euler-016 euler-016)
set_tests_properties(euler-016 PROPERTIES PASS_REGULAR_EXPRESSION "^1366\n$")

add_test(euler-018 euler-018)
set_tests_properties(euler-018 PROPERTIES PASS_REGULAR_EXPRESSION "^1074\n$")

add_test(euler-019 euler-019)
set_tests_properties(euler-019 PROPERTIES PASS_REGULAR_EXPRESSION "^171\n$")

add_test(euler-020 euler-020)
set_tests_properties(euler-020 PROPERTIES PASS_REGULAR_EXPRESSION "^648\n$")

add_test(euler-021 euler-021)
set_tests_properties(euler-021 PROPERTIES PASS_REGULAR_EXPRESSION "^31626\n$")

add_test(euler-022 euler-022 ${PROJECT_SOURCE_DIR}/src/001-050/p022_names.txt)
set_tests_properties(euler-022 PROPERTIES PASS_REGULAR_EXPRESSION "^871198282\n$")

add_test(euler-023 euler-023)
set_tests_properties(euler-023 PROPERTIES PASS_REGULAR_EXPRESSION "^4179871\n$")

add_test(euler-024+brute-force euler-024+brute-force)
set_tests_properties(euler-024+brute-force PROPERTIES PASS_REGULAR_EXPRESSION "^2783915460\n$")

add_test(euler-024 euler-024)
set_tests_properties(euler-024 PROPERTIES PASS_REGULAR_EXPRESSION "^2783915460\n$")

add_test(euler-025 euler-025)
set_tests_properties(euler-025 PROPERTIES PASS_REGULAR_EXPRESSION "^4782\n$")

add_test(euler-026 euler-026)
set_tests_properties(euler-026 PROPERTIES PASS_REGULAR_EXPRESSION "^983\n$")

add_test(euler-027 euler-027)
set_tests_properties(euler-027 PROPERTIES PASS_REGULAR_EXPRESSION "^-59231\n$")

add_test(euler-028 euler-028)
set_tests_properties(euler-028 PROPERTIES PASS_REGULAR_EXPRESSION "^669171001\n$")

add_test(euler-029+brute-force euler-029+brute-force)
set_tests_properties(euler-029+brute-force PROPERTIES PASS_REGULAR_EXPRESSION "^9183\n$")

add_test(euler-029 euler-029)
set_tests_properties(euler-029 PROPERTIES PASS_REGULAR_EXPRESSION "^9183\n$")

add_test(euler-030 euler-030)
set_tests_properties(euler-030 PROPERTIES PASS_REGULAR_EXPRESSION "^443839\n$")

add_test(euler-031 euler-031)
set_tests_properties(euler-031 PROPERTIES PASS_REGULAR_EXPRESSION "^73682\n$")

add_test(euler-032 euler-032)
set_tests_properties(euler-032 PROPERTIES PASS_REGULAR_EXPRESSION "^45228\n$")

add_test(euler-033 euler-033)
set_tests_properties(euler-033 PROPERTIES PASS_REGULAR_EXPRESSION "^100\n$")

add_test(euler-034 euler-034)
set_tests_properties(euler-034 PROPERTIES PASS_REGULAR_EXPRESSION "^40730\n$")

add_test(euler-035 euler-035)
set_tests_properties(euler-035 PROPERTIES PASS_REGULAR_EXPRESSION "^55\n$")

add_test(euler-036 euler-036)
set_tests_properties(euler-036 PROPERTIES PASS_REGULAR_EXPRESSION "^872187\n$")

add_test(euler-037 euler-037)
set_tests_properties(euler-037 PROPERTIES PASS_REGULAR_EXPRESSION "^748317\n$")

add_test(euler-038 euler-038)
set_tests_properties(euler-038 PROPERTIES PASS_REGULAR_EXPRESSION "^932718654\n$")

add_test(euler-039+brute-force euler-039+brute-force)
set_tests_properties(euler-039+brute-force PROPERTIES PASS_REGULAR_EXPRESSION "^840\n$")

add_test(euler-039 euler-039)
set_tests_properties(euler-039 PROPERTIES PASS_REGULAR_EXPRESSION "^840\n$")

add_test(euler-040+brute-force euler-040+brute-force)
set_tests_properties(euler-040+brute-force PROPERTIES PASS_REGULAR_EXPRESSION "^210\n$")

add_test(euler-040 euler-040)
set_tests_properties(euler-040 PROPERTIES PASS_REGULAR_EXPRESSION "^210\n$")

add_test(euler-041 euler-041)
set_tests_properties(euler-041 PROPERTIES PASS_REGULAR_EXPRESSION "^7652413\n$")

add_test(euler-042 euler-042 ${PROJECT_SOURCE_DIR}/src/001-050/p042_words.txt)
set_tests_properties(euler-042 PROPERTIES PASS_REGULAR_EXPRESSION "^162\n$")

add_test(euler-043 euler-043)
set_tests_properties(euler-043 PROPERTIES PASS_REGULAR_EXPRESSION "^16695334890\n$")

add_test(euler-044 euler-044)
set_tests_properties(euler-044 PROPERTIES PASS_REGULAR_EXPRESSION "^5482660\n$")

add_test(euler-045 euler-045)
set_tests_properties(euler-045 PROPERTIES PASS_REGULAR_EXPRESSION "^1533776805\n$")

add_test(euler-046 euler-046)
set_tests_properties(euler-046 PROPERTIES PASS_REGULAR_EXPRESSION "^5777\n$")

add_test(euler-047 euler-047)
set_tests_properties(euler-047 PROPERTIES PASS_REGULAR_EXPRESSION "^134043\n$")

add_test(euler-048 euler-048)
set_tests_properties(euler-048 PROPERTIES PASS_REGULAR_EXPRESSION "^9110846700\n$")

add_test(euler-049 euler-049)
set_tests_properties(euler-049 PROPERTIES PASS_REGULAR_EXPRESSION "^296962999629\n$")

add_test(euler-050+brute-force euler-050+brute-force)
set_tests_properties(euler-050+brute-force PROPERTIES PASS_REGULAR_EXPRESSION "^997651\n$")

add_test(euler-050 euler-050)
set_tests_properties(euler-050 PROPERTIES PASS_REGULAR_EXPRESSION "^997651\n$")

add_test(euler-051 euler-051)
set_tests_properties(euler-051 PROPERTIES PASS_REGULAR_EXPRESSION "^121313\n$")

add_test(euler-052 euler-052)
set_tests_properties(euler-052 PROPERTIES PASS_REGULAR_EXPRESSION "^142857\n$")

add_test(euler-053 euler-053)
set_tests_properties(euler-053 PROPERTIES PASS_REGULAR_EXPRESSION "^4075\n$")

add_test(euler-054 euler-054 ${PROJECT_SOURCE_DIR}/src/051-100/p054_poker.txt)
set_tests_properties(euler-054 PROPERTIES PASS_REGULAR_EXPRESSION "^376\n$")

add_test(euler-055 euler-055)
set_tests_properties(euler-055 PROPERTIES PASS_REGULAR_EXPRESSION "^249\n$")

add_test(euler-057 euler-057)
set_tests_properties(euler-057 PROPERTIES PASS_REGULAR_EXPRESSION "^972\n$")

add_test(euler-067 euler-067 ${PROJECT_SOURCE_DIR}/src/051-100/p067_triangle.txt)
set_tests_properties(euler-067 PROPERTIES PASS_REGULAR_EXPRESSION "^7273\n$")
