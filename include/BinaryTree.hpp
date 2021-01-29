// Copyright © 2021 by Shun Huang. All rights reserved.
// Licensed under MIT License.
// See LICENSE in the project root for license information.

#pragma once

#include <any>
#include <memory>
#include <string>

namespace CppSampleCode
{
    class Node
    {
    public:
        Node(int32_t key, const std::any &data) : key{key}, data{data} {}

        ~Node() = default;

        int32_t key;
        std::any data;
        std::shared_ptr<Node> left;
        std::shared_ptr<Node> right;
        std::shared_ptr<Node> parent;
    };

    using Node_p = std::shared_ptr<Node>;

    class BinaryTree
    {
    public:
        virtual ~BinaryTree() = default;

        virtual Node_p search(int32_t key) const = 0;

        virtual void insertNode(int32_t key, const std::any &data) = 0;

        virtual void deleteNode(int32_t key) = 0;

        virtual Node_p getLeftmost(const Node_p &node) const = 0;

        virtual Node_p getRightmost(const Node_p &node) const = 0;

        virtual Node_p getPredecessor(const Node_p &node) const = 0;

        virtual Node_p getSuccessor(const Node_p &node) const = 0;

        virtual size_t getHeight(const Node_p &node) const = 0;

        Node_p getRoot() const { return root; }

        bool empty() const { return (!root) ? true : false; }

    protected:
        Node_p root;
    };

    using BinaryTree_p = std::shared_ptr<BinaryTree>;

    bool checkBalance(const BinaryTree_p &tree);

    bool verifyBinarySearchTreeProperties(const BinaryTree_p &tree);

} // namespace CppSampleCode
