# ---------------------------------------------------------------------------
# IMLAB
# ---------------------------------------------------------------------------

include("${CMAKE_SOURCE_DIR}/tools/schemac/local.cmake")
include("${CMAKE_SOURCE_DIR}/tools/queryc/local.cmake")

# ---------------------------------------------------------------------------
# Sources
# ---------------------------------------------------------------------------

file(GLOB_RECURSE TOOLS_SRC "tools/imlabdb.cc")

# ---------------------------------------------------------------------------
# Executables
# ---------------------------------------------------------------------------

add_executable(imlabdb tools/imlabdb.cc ${QUERYC_CC})
target_link_libraries(imlabdb ${CMAKE_DL_LIBS} imlab gflags Threads::Threads)

# ---------------------------------------------------------------------------
# Linting
# ---------------------------------------------------------------------------

add_cpplint_target(lint_tools "${TOOLS_SRC}")
list(APPEND lint_targets lint_tools)

