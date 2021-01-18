find_package(Boost REQUIRED COMPONENTS unit_test_framework)

include_directories("${PROJECT_SOURCE_DIR}/include")

set(TEST_SOURCES
    ${PROJECT_SOURCE_DIR}/test/BinarySearchTreeTests.cpp
    ${PROJECT_SOURCE_DIR}/test/main.cpp
    ${PROJECT_SOURCE_DIR}/test/TraversalTests.cpp
)

set(TEST_LIBS CppSample)

add_executable(test_main ${TEST_SOURCES})
target_link_libraries(test_main ${TEST_LIBS} ${Boost_LIBRARIES})
add_test(CppSampleTest test_main COMMAND test_main)
