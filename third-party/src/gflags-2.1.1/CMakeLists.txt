include_directories (include/gflags .)
add_library (gflags src/gflags.cc src/gflags_reporting.cc src/gflags_completions.cc)
target_link_libraries(gflags pthread)
