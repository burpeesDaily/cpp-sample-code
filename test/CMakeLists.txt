find_package(Boost REQUIRED COMPONENTS unit_test_framework)

include_directories("${PROJECT_SOURCE_DIR}/include")

set(TEST_SOURCES
    ${PROJECT_SOURCE_DIR}/test/BinarySearchTreeTests.cpp
    ${PROJECT_SOURCE_DIR}/test/main.cpp
    ${PROJECT_SOURCE_DIR}/test/TraversalTests.cpp
)

set(TEST_LIBS CppSample)

add_executable(test_sample ${TEST_SOURCES})
target_link_libraries(test_sample ${TEST_LIBS} ${Boost_LIBRARIES})
add_test(test_sample test_sample)
