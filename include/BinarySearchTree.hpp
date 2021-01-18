// Copyright © 2021 by Shun Huang. All rights reserved.
// Licensed under MIT License.
// See LICENSE in the project root for license information.

#include <any>

#include "BinaryTree.hpp"

namespace CppSampleCode
{
    class BinarySearchTree : public BinaryTree
    {
    public:
        Node_p search(int32_t key) const override;

        void insertNode(int32_t key, const std::any &data) override;

        void deleteNode(int32_t key) override;

        Node_p getLeftmost(const Node_p &node) const override;

        Node_p getRightmost(const Node_p &node) const override;

        Node_p getPredecessor(const Node_p &node) const override;

        Node_p getSuccessor(const Node_p &node) const override;

        size_t getHeight(const Node_p &node) const override;

    private:
        void transplant(Node_p &deletingNode, Node_p &replacingNode);
    };

    using BinarySearchTree_p = std::shared_ptr<BinarySearchTree>;

} // namespace CppSampleCode
