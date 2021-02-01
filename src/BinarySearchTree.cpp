// Copyright © 2021 by Shun Huang. All rights reserved.
// Licensed under MIT License.
// See LICENSE in the project root for license information.

#include <algorithm>
#include <any>

#include "BinarySearchTree.hpp"
#include "TreeException.hpp"

namespace CppSampleCode
{
    Node_p BinarySearchTree::search(int32_t key) const
    {
        Node_p current = root;
        while (current)
        {
            if (key > current->key)
            {
                current = current->right;
            }
            else if (key < current->key)
            {
                current = current->left;
            }
            else
            {
                return current;
            }
        }
        return nullptr;
    }

    void BinarySearchTree::insertNode(int32_t key, std::any data)
    {
        Node_p node = std::make_shared<Node>(key, data);

        Node_p parent;
        Node_p current = root;
        while (current)
        {
            parent = current;
            if (node->key == current->key)
            {
                throw DuplicateKeyException(key);
            }

            if (node->key < current->key)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }
        node->parent = parent;
        if (!parent)
        {
            root = node;
        }
        else if (node->key < parent->key)
        {
            parent->left = node;
        }
        else
        {
            parent->right = node;
        }
    }

    Node_p BinarySearchTree::getLeftmost(const Node_p &node) const
    {
        Node_p current = node;
        while (current->left)
        {
            current = current->left;
        }
        return current;
    }

    Node_p BinarySearchTree::getRightmost(const Node_p &node) const
    {
        Node_p current = node;
        while (current->right)
        {
            current = current->right;
        }
        return current;
    }

    Node_p BinarySearchTree::getPredecessor(const Node_p &node) const
    {
        Node_p current = node;
        if (current->left)
        {
            return getRightmost(current->left);
        }
        // Left child is empty
        Node_p parent = current->parent;
        while (parent && (current == parent->left))
        {
            current = parent;
            parent = parent->parent;
        }
        return parent;
    }

    Node_p BinarySearchTree::getSuccessor(const Node_p &node) const
    {
        Node_p current = node;
        if (current->right)
        {
            return getLeftmost(current->right);
        }
        // Right child is empty
        Node_p parent = current->parent;
        while (parent && (current == parent->right))
        {
            current = parent;
            parent = parent->parent;
        }
        return parent;
    }

    void BinarySearchTree::transplant(const Node_p &deletingNode, const Node_p &replacingNode)
    {
        if (!deletingNode->parent)
        {
            root = replacingNode;
        }
        else if (deletingNode == deletingNode->parent->left)
        {
            deletingNode->parent->left = replacingNode;
        }
        else
        {
            deletingNode->parent->right = replacingNode;
        }

        if (replacingNode)
        {
            replacingNode->parent = deletingNode->parent;
        }
    }

    void BinarySearchTree::deleteNode(int32_t key)
    {
        Node_p deletingNode = search(key);

        // No child or only one right child
        if (!deletingNode->left)
        {
            transplant(deletingNode, deletingNode->right);
        }
        else if (!deletingNode->right)
        { // Only one left child
            transplant(deletingNode, deletingNode->left);
        }
        else
        { // Two children
            Node_p leftmostNode = getLeftmost(deletingNode->right);
            // the leftmost node is not the direct child of the deleting node
            if (leftmostNode->parent != deletingNode)
            {
                transplant(leftmostNode, leftmostNode->right);
                leftmostNode->right = deletingNode->right;
                leftmostNode->right->parent = leftmostNode;
            }
            transplant(deletingNode, leftmostNode);
            leftmostNode->left = deletingNode->left;
            leftmostNode->left->parent = deletingNode;
        }
    }

    size_t BinarySearchTree::getHeight(const Node_p &node) const
    {
        if (!node)
        {
            return 0;
        }

        if (!node->left && !node->right)
        {
            return 0;
        }

        return std::max(getHeight(node->left), getHeight(node->right));
    }

} // namespace CppSampleCode
