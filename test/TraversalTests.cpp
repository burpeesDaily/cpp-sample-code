#include "BinarySearchTree.hpp"
#include "Traversal.hpp"

#include <string>
#include <vector>

#include <boost/test/unit_test.hpp>

using namespace CppSampleCode;

// Test data to build a tree
const std::vector<std::pair<int32_t, std::string>> TEST_DATA{
    {23, "23"}, {4, "4"},   {30, "30"}, {11, "11"}, {7, "7"}, {34, "34"},
    {20, "20"}, {24, "24"}, {22, "22"}, {15, "15"}, {1, "1"}};

BOOST_AUTO_TEST_SUITE(TraversalTestsSuite)

BOOST_AUTO_TEST_CASE(BinarySearchTreeTraversalTest)
{

    BinarySearchTree_p tree{std::make_shared<BinarySearchTree>()};

    for (const auto &item : TEST_DATA)
    {
        tree->insertNode(item.first, item.second);
    }

    {
        const std::vector<std::pair<int32_t, std::string>> expectedData{
            {1, "1"}, {7, "7"},   {15, "15"}, {22, "22"}, {20, "20"}, {11, "11"},
            {4, "4"}, {24, "24"}, {34, "34"}, {30, "30"}, {23, "23"}};
        TraversalOutput output = postOrderTraverse(tree);
        for (size_t index = 0; index < output.size(); ++index)
        {
            BOOST_CHECK(output.at(index).first == expectedData.at(index).first); // NOLINT
            BOOST_CHECK(std::any_cast<std::string>(output.at(index).second) ==   // NOLINT
                        expectedData.at(index).second);
        }
    }

    {
        const std::vector<std::pair<int32_t, std::string>> expectedData{
            {1, "1"}, {7, "7"},   {15, "15"}, {22, "22"}, {20, "20"}, {11, "11"},
            {4, "4"}, {24, "24"}, {34, "34"}, {30, "30"}, {23, "23"}};
        TraversalOutput output = postOrderTraverse(tree, false);
        for (size_t index = 0; index < output.size(); ++index)
        {
            BOOST_CHECK(output.at(index).first == expectedData.at(index).first); // NOLINT
            BOOST_CHECK(std::any_cast<std::string>(output.at(index).second) ==   // NOLINT
                        expectedData.at(index).second);
        }
    }

    {
        const std::vector<std::pair<int32_t, std::string>> expectedData{
            {23, "23"}, {4, "4"},   {1, "1"},   {11, "11"}, {7, "7"},  {20, "20"},
            {15, "15"}, {22, "22"}, {30, "30"}, {24, "24"}, {34, "34"}};
        TraversalOutput output = preOrderTraverse(tree);
        for (size_t index = 0; index < output.size(); ++index)
        {
            BOOST_CHECK(output.at(index).first == expectedData.at(index).first); // NOLINT
            BOOST_CHECK(std::any_cast<std::string>(output.at(index).second) ==   // NOLINT
                        expectedData.at(index).second);
        }
    }

    {
        const std::vector<std::pair<int32_t, std::string>> expectedData{
            {23, "23"}, {4, "4"},   {1, "1"},   {11, "11"}, {7, "7"},  {20, "20"},
            {15, "15"}, {22, "22"}, {30, "30"}, {24, "24"}, {34, "34"}};
        TraversalOutput output = preOrderTraverse(tree, false);
        for (size_t index = 0; index < output.size(); ++index)
        {
            BOOST_CHECK(output.at(index).first == expectedData.at(index).first); // NOLINT
            BOOST_CHECK(std::any_cast<std::string>(output.at(index).second) ==   // NOLINT
                        expectedData.at(index).second);
        }
    }

    {
        const std::vector<std::pair<int32_t, std::string>> expectedData{
            {1, "1"},   {4, "4"},   {7, "7"},   {11, "11"}, {15, "15"}, {20, "20"},
            {22, "22"}, {23, "23"}, {24, "24"}, {30, "30"}, {34, "34"}};
        TraversalOutput output = inOrderTraverse(tree);
        for (size_t index = 0; index < output.size(); ++index)
        {
            BOOST_CHECK(output.at(index).first == expectedData.at(index).first); // NOLINT
            BOOST_CHECK(std::any_cast<std::string>(output.at(index).second) ==   // NOLINT
                        expectedData.at(index).second);
        }
    }

    {
        const std::vector<std::pair<int32_t, std::string>> expectedData{
            {1, "1"},   {4, "4"},   {7, "7"},   {11, "11"}, {15, "15"}, {20, "20"},
            {22, "22"}, {23, "23"}, {24, "24"}, {30, "30"}, {34, "34"}};
        TraversalOutput output = inOrderTraverse(tree, false);
        for (size_t index = 0; index < output.size(); ++index)
        {
            BOOST_CHECK(output.at(index).first == expectedData.at(index).first); // NOLINT
            BOOST_CHECK(std::any_cast<std::string>(output.at(index).second) ==   // NOLINT
                        expectedData.at(index).second);
        }
    }
}

BOOST_AUTO_TEST_SUITE_END()
