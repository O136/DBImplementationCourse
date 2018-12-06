# ---------------------------------------------------------------------------
# IMLAB
# ---------------------------------------------------------------------------

# ---------------------------------------------------------------------------
# Files
# ---------------------------------------------------------------------------

file(GLOB_RECURSE TEST_CC test/*.cc)
list(REMOVE_ITEM TEST_CC test/tester.cc)

# ---------------------------------------------------------------------------
# Tester
# ---------------------------------------------------------------------------

add_executable(tester_imlab test/tester.cc ${TEST_CC} ${INCLUDE_H})
target_link_libraries(tester_imlab imlab gtest gmock Threads::Threads)
enable_testing()
add_test(imlab tester_imlab)

# ---------------------------------------------------------------------------
# Linting
# ---------------------------------------------------------------------------

add_cpplint_target(lint_test "${TEST_CC}")
list(APPEND lint_targets lint_test)