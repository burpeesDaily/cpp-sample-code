// Copyright © 2021 by Shun Huang. All rights reserved.
// Licensed under MIT License.
// See LICENSE in the project root for license information.

#include <iostream>
#include <queue>
#include <stack>

#include "Traversal.hpp"

namespace CppSampleCode
{

    void preOrderTraverseRecursive(const Node_p &root, TraversalOutput &output)
    {
        if (root)
        {
            output.emplace_back(root->key, root->data);
            preOrderTraverseRecursive(root->left, output);
            preOrderTraverseRecursive(root->right, output);
        }
    }

    TraversalOutput preOrderTraverse(const BinaryTree_p &tree, bool isRecursive)
    {
        TraversalOutput output;
        if (isRecursive)
        {
            preOrderTraverseRecursive(tree->getRoot(), output);
        }
        else
        {
            std::stack<Node_p> tempStack;
            tempStack.push(tree->getRoot());
            while (!tempStack.empty())
            {
                Node_p node = tempStack.top();
                tempStack.pop();
                output.emplace_back(node->key, node->data);

                if (node->right)
                {
                    tempStack.push(node->right);
                }

                if (node->left)
                {
                    tempStack.push(node->left);
                }
            }
        }
        return output;
    }

    void inOrderTraverseRecursive(const Node_p &root, TraversalOutput &output)
    {
        if (root)
        {
            inOrderTraverseRecursive(root->left, output);
            output.emplace_back(root->key, root->data);
            inOrderTraverseRecursive(root->right, output);
        }
    }

    TraversalOutput inOrderTraverse(const BinaryTree_p &tree, bool isRecursive)
    {
        TraversalOutput output;
        if (tree->empty())
        {
            return output;
        }
        if (isRecursive)
        {
            inOrderTraverseRecursive(tree->getRoot(), output);
        }
        else
        {
            std::stack<Node_p> tempStack;
            if (tree->getRoot()->right)
            {
                tempStack.push(tree->getRoot()->right);
                tempStack.push(tree->getRoot());
            }
            Node_p current = tree->getRoot()->left;

            while (true)
            {
                if (current)
                {
                    if (current->right)
                    {
                        tempStack.push(current->right);
                        tempStack.push(current);
                        current = current->left;
                        continue;
                    }
                    tempStack.push(current);
                    current = nullptr;
                }
                else
                { // current is nullptr
                    if (!tempStack.empty())
                    {
                        current = tempStack.top();
                        tempStack.pop();

                        if (!current->right)
                        {
                            output.emplace_back(current->key, current->data);
                            current = nullptr;
                            continue;
                        }
                        // current->right is not nullptr
                        if (!tempStack.empty())
                        {
                            if (current->right == tempStack.top())
                            {
                                output.emplace_back(current->key, current->data);
                                current = nullptr;
                            }
                            continue;
                        }
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
        return output;
    }

    void postOrderTraverseRecursive(const Node_p &root, TraversalOutput &output)
    {
        if (root)
        {
            postOrderTraverseRecursive(root->left, output);
            postOrderTraverseRecursive(root->right, output);
            // std::cout << "(" << root->key << ", " << root->data << ")" << std::endl;
            output.emplace_back(root->key, root->data);
        }
    }

    TraversalOutput postOrderTraverse(const BinaryTree_p &tree, bool isRecursive)
    {
        TraversalOutput output;
        if (tree->empty())
        {
            return output;
        }
        if (isRecursive)
        {
            postOrderTraverseRecursive(tree->getRoot(), output);
        }
        else
        {
            std::stack<Node_p> tempStack;
            if (tree->getRoot()->right)
            {
                tempStack.push(tree->getRoot()->right);
            }
            tempStack.push(tree->getRoot());
            Node_p current = tree->getRoot()->left;

            while (tree)
            {
                if (current)
                {
                    if (current->right)
                    {
                        tempStack.push(current->right);
                        tempStack.push(current);
                        current = current->left;
                        continue;
                    }
                    // current->right is not nullprt
                    output.emplace_back(current->key, current->data);
                    current = nullptr;
                }
                else
                { // current is nullprt
                    if (!tempStack.empty())
                    {
                        current = tempStack.top();
                        tempStack.pop();
                        if (current->right == nullptr)
                        {
                            // std::cout << "(" << current->key << ", " << current->data
                            // << ")" << std::endl;
                            output.emplace_back(current->key, current->data);
                            current = nullptr;
                        }
                        else
                        { // current->right is not nullptr
                            if (!tempStack.empty())
                            {
                                if (current->right != tempStack.top())
                                {
                                    // std::cout << "(" << current->key << ", " <<
                                    // current->data << ")" << std::endl;
                                    output.emplace_back(current->key, current->data);
                                    current = nullptr;
                                }
                                else
                                { // current->right is tempStack.top()
                                    Node_p temp = tempStack.top();
                                    tempStack.pop();
                                    tempStack.push(current);
                                    current = temp;
                                }
                            }
                            else
                            { // tempStack is empty
                                // std::cout << "(" << current->key << ", " <<
                                // current->data << ")" << std::endl;
                                output.emplace_back(current->key, current->data);
                                break;
                            }
                        }
                    }
                }
            }
        }
        return output;
    }

    TraversalOutput levelOrderTraverse(const BinaryTree_p &tree)
    {
        TraversalOutput output;
        if (tree->empty())
        {
            return output;
        }
        std::queue<Node_p> tempQueue;
        tempQueue.push(tree->getRoot());

        while (!tempQueue.empty())
        {
            Node_p node = tempQueue.front();
            tempQueue.pop();
            if (node)
            {
                output.emplace_back(node->key, node->data);
                if (node->left)
                {
                    tempQueue.push(node->left);
                }
                if (node->right)
                {
                    tempQueue.push(node->right);
                }
            }
        }
        return output;
    }

} // namespace CppSampleCode
