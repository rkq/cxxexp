include_directories(
    include
    .
)

add_library(
    gtest STATIC
    src/gtest-death-test.cc
    src/gtest-filepath.cc
    src/gtest-port.cc
    src/gtest-printers.cc
    src/gtest-test-part.cc
    src/gtest-typed-test.cc
    src/gtest.cc
)

add_library(
    gtest_main STATIC
    src/gtest_main.cc
)

