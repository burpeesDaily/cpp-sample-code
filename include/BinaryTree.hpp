// Copyright © 2021 by Shun Huang. All rights reserved.
// Licensed under MIT License.
// See LICENSE in the project root for license information.

#pragma once

#include <any>
#include <memory>
#include <string>

namespace CppSampleCode
{
    /**
     * \brief Basic binary tree node definition.
     */
    struct Node
    {
        /**
         * Constructor.
         *
         * @param key an integer to identify the node
         * @param data any data the node stores
         */
        Node(int32_t key, std::any &data) : key{key}, data{std::move(data)} {}

        ~Node() = default;

        Node(const Node &other) = default;
        Node & operator=(const Node &other) = default;

        Node(Node &&other) = default;
        Node & operator=(Node &&other) = default;

        int32_t key;                  //!< The key of the node
        std::any data;                //!< The data of the node
        std::shared_ptr<Node> left;   //!< The pointer points to its left node
        std::shared_ptr<Node> right;  //!< The pointer points to its right node
        std::shared_ptr<Node> parent; //!< The pointer points to its parent
    };

    using Node_p = std::shared_ptr<Node>;

    /**
     * \brief An abstract base class for any types of binary trees.
     *
     * This base class defines the interface of all types of binary tress should
     * provide. One reason to use abstract base class is to make sure binary tree
     * traversal can be performed on any type of binary trees.
     */
    class BinaryTree
    {
      public:
        BinaryTree() = default;
        virtual ~BinaryTree() = default;

        BinaryTree(const BinaryTree &other) = delete;
        BinaryTree & operator=(const BinaryTree &other) = delete;

        BinaryTree(BinaryTree &&other) = delete;
        BinaryTree & operator=(BinaryTree &&other) = delete;

        /**
         * Search data based on the given key.
         *
         * @param key an interger key associated with the data.
         * @return The node found by the given key.
         */
        virtual Node_p search(int32_t key) const = 0;

        /**
         * Insert data and its key into the binary tree.
         *
         * @param key an integer key associated with the data.
         * @param data the data to be inserted.
         */
        virtual void insertNode(int32_t key, std::any data) = 0;

        /**
         * Delete the node based on the given key.
         *
         * @param key the key of the node to be deleted.
         */
        virtual void deleteNode(int32_t key) = 0;

        /**
         * Get the leftmost node from a given subtree.
         * The key of the leftmost node is the smallest key in the given subtree.
         *
         * @param node the root of the sub tree.
         * @return the pointer to the leftmost node.
         */
        virtual Node_p getLeftmost(const Node_p &node) const = 0;

        /**
         * Get the rightmost node from a given subtree.
         * The key of the rightmost node is the smallest key in the given subtree.
         *
         * @param node the root of the sub tree.
         * @return the pointer to the rightmost node.
         */
        virtual Node_p getRightmost(const Node_p &node) const = 0;

        /**
         * Get the predecessor node in the in-order order.
         *
         * @param node the node to get its predecessor.
         * @return the pointer to the predecessor.
         */
        virtual Node_p getPredecessor(const Node_p &node) const = 0;

        /**
         * Get the successor node in the in-order order.
         *
         * @param node the node to get its successor.
         * @return the pointer to the successor.
         */
        virtual Node_p getSuccessor(const Node_p &node) const = 0;

        /**
         * Get the height of the given node.
         *
         * @param node the node to get its height.
         * @return the height.
         */
        virtual size_t getHeight(const Node_p &node) const = 0;

        /**
         * @return the root of the tree.
         */
        Node_p getRoot() const { return root; }

        /**
         * @return true if the tree is empty; false otherwise.
         */
        bool empty() const { return (!root) ? true : false; }

      protected:
        Node_p root; //!< The root of the tree. nullptr if the tree is empty.
    };

    using BinaryTree_p = std::shared_ptr<BinaryTree>;

    /**
     * Help function to check if a tree is a valid binary tree.
     *
     * @param tree the tree to be checked.
     * @return true if the tree is a valid binary tree; false otherwise.
     */
    bool checkBalance(const BinaryTree_p &tree);

    /**
     * Help function to check if a binary tree satisfies the binary search tree
     * properties.
     *
     * @param tree the tree to be checked.
     * @return true if the tree is a valid binary search tree; false otherwise.
     */
    bool verifyBinarySearchTreeProperties(const BinaryTree_p &tree);

} // namespace CppSampleCode
