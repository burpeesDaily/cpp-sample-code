#include <any>
#include <string>
#include <vector>

#include <boost/test/unit_test.hpp>

#include "BinarySearchTree.hpp"
#include "Traversal.hpp"

using namespace CppSampleCode;

// Test data to build a tree
const std::vector<std::pair<int32_t, std::string>> TEST_DATA{
    {23, "23"}, {4, "4"},   {30, "30"}, {11, "11"}, {7, "7"}, {34, "34"},
    {20, "20"}, {24, "24"}, {22, "22"}, {15, "15"}, {1, "1"}};

BOOST_AUTO_TEST_SUITE(BinarySearchTreeTestsSuite)

BOOST_AUTO_TEST_CASE(BasicTest)
{
    BinarySearchTree tree;

    for (const auto &item : TEST_DATA)
    {
        tree.insertNode(item.first, std::make_any<std::string>(item.second));
    }

    BOOST_CHECK(!tree.empty()); // NOLINT

    BOOST_CHECK_EQUAL(tree.getLeftmost(tree.getRoot())->key, 1);
    BOOST_CHECK_EQUAL(
        std::any_cast<std::string>(tree.getLeftmost(tree.getRoot())->data), "1");

    BOOST_CHECK_EQUAL(tree.getRightmost(tree.getRoot())->key, 34);
    BOOST_CHECK_EQUAL(
        std::any_cast<std::string>(tree.getRightmost(tree.getRoot())->data), "34");

    BOOST_CHECK_EQUAL(std::any_cast<std::string>(tree.search(24)->data), "24");

    BOOST_CHECK_EQUAL(tree.getPredecessor(tree.getRoot())->key, 22);
    BOOST_CHECK_EQUAL(tree.getSuccessor(tree.getRoot())->key, 24);

    tree.deleteNode(15); // NOLINT
    tree.deleteNode(22); // NOLINT
    tree.deleteNode(7);  // NOLINT
    tree.deleteNode(20); // NOLINT

    BOOST_CHECK(!tree.search(15)); // NOLINT
}

BOOST_AUTO_TEST_CASE(DeletionTest)
{
    BinarySearchTree_p tree{std::make_shared<BinarySearchTree>()};

    for (const auto &item : TEST_DATA)
    {
        tree->insertNode(item.first, std::make_any<std::string>(item.second));
    }

    // No child
    tree->deleteNode(15); // NOLINT
    {
        const std::vector<std::pair<int32_t, std::string>> expectedData{
            {23, "23"}, {4, "4"},   {30, "30"}, {1, "1"},   {11, "11"},
            {24, "24"}, {34, "34"}, {7, "7"},   {20, "20"}, {22, "22"}};

        TraversalOutput output = levelOrderTraverse(tree);

        for (size_t index = 0; index < output.size(); ++index)
        {
            BOOST_CHECK(output.at(index).first == expectedData.at(index).first); // NOLINT
            BOOST_CHECK(std::any_cast<std::string>(output.at(index).second) ==   // NOLINT
                        expectedData.at(index).second);
        }
    }

    // One right child
    tree->deleteNode(20); // NOLINT
    {
        const std::vector<std::pair<int32_t, std::string>> expectedData{
            {23, "23"}, {4, "4"},   {30, "30"}, {1, "1"},  {11, "11"},
            {24, "24"}, {34, "34"}, {7, "7"},   {22, "22"}};
        TraversalOutput output = levelOrderTraverse(tree);

        for (size_t index = 0; index < output.size(); ++index)
        {
            BOOST_CHECK(output.at(index).first == expectedData.at(index).first); // NOLINT
            BOOST_CHECK(std::any_cast<std::string>(output.at(index).second) ==   // NOLINT
                        expectedData.at(index).second);
        }
    }

    // One left child
    tree->insertNode(17, std::make_any<std::string>("17")); // NOLINT
    tree->deleteNode(22); // NOLINT
    {
        const std::vector<std::pair<int32_t, std::string>> expectedData{
            {23, "23"}, {4, "4"},   {30, "30"}, {1, "1"},  {11, "11"},
            {24, "24"}, {34, "34"}, {7, "7"},   {17, "17"}};
        TraversalOutput output = levelOrderTraverse(tree);

        for (size_t index = 0; index < output.size(); ++index)
        {
            BOOST_CHECK(output.at(index).first == expectedData.at(index).first); // NOLINT

            BOOST_CHECK(std::any_cast<std::string>(output.at(index).second) ==   // NOLINT
                        expectedData.at(index).second);
        }
    }

    // Two children
    tree->deleteNode(11); // NOLINT
    {
        const std::vector<std::pair<int32_t, std::string>> expectedData{
            {23, "23"}, {4, "4"},   {30, "30"}, {1, "1"},
            {17, "17"}, {24, "24"}, {34, "34"}, {7, "7"}};
        TraversalOutput output = levelOrderTraverse(tree);

        for (size_t index = 0; index < output.size(); ++index)
        {
            BOOST_CHECK(output.at(index).first == expectedData.at(index).first); // NOLINT
            BOOST_CHECK(std::any_cast<std::string>(output.at(index).second) ==   // NOLINT
                        expectedData.at(index).second);
        }
    }
}

BOOST_AUTO_TEST_SUITE_END()
