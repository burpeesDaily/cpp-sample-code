// Copyright © 2021 by Shun Huang. All rights reserved.
// Licensed under MIT License.
// See LICENSE in the project root for license information.

#include <iostream>
#include <queue>
#include <stack>

#include "Traversal.hpp"

namespace CppSampleCode
{

    void PreOrderTraverseRecursive(const Node_p &root, TraversalOutput &output)
    {
        if (root)
        {
            output.emplace_back(root->key, root->data);
            PreOrderTraverseRecursive(root->left, output);
            PreOrderTraverseRecursive(root->right, output);
        }
    }

    TraversalOutput PreOrderTraverse(const BinaryTree_p &tree, bool isRecursive)
    {
        TraversalOutput output;
        if (isRecursive)
        {
            PreOrderTraverseRecursive(tree->getRoot(), output);
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

    void InOrderTraverseRecursive(const Node_p &root, TraversalOutput &output)
    {
        if (root)
        {
            InOrderTraverseRecursive(root->left, output);
            output.emplace_back(root->key, root->data);
            InOrderTraverseRecursive(root->right, output);
        }
    }

    TraversalOutput InOrderTraverse(const BinaryTree_p &tree, bool isRecursive)
    {
        TraversalOutput output;
        if (tree->empty())
        {
            return output;
        }
        if (isRecursive)
        {
            InOrderTraverseRecursive(tree->getRoot(), output);
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
                            // std::cout << "(" << current->key << ", " << current->data
                            // << ")" << std::endl;
                            output.emplace_back(current->key, current->data);
                            current = nullptr;
                            continue;
                        }
                        else
                        { // current->right is not nullptr
                            if (!tempStack.empty())
                            {
                                if (current->right == tempStack.top())
                                {
                                    // std::cout << "(" << current->key << ", " <<
                                    // current->data << ")" << std::endl;
                                    output.emplace_back(current->key, current->data);
                                    current = nullptr;
                                }
                                continue;
                            }
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

    void PostOrderTraverseRecursive(const Node_p &root, TraversalOutput &output)
    {
        if (root)
        {
            PostOrderTraverseRecursive(root->left, output);
            PostOrderTraverseRecursive(root->right, output);
            // std::cout << "(" << root->key << ", " << root->data << ")" << std::endl;
            output.emplace_back(root->key, root->data);
        }
    }

    TraversalOutput PostOrderTraverse(const BinaryTree_p &tree, bool isRecursive)
    {
        TraversalOutput output;
        if (tree->empty())
        {
            return output;
        }
        if (isRecursive)
        {
            PostOrderTraverseRecursive(tree->getRoot(), output);
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
                    else
                    { // current->right is not nullprt
                        // std::cout << "(" << current->key << ", " << current->data <<
                        // ")" << std::endl;
                        output.emplace_back(current->key, current->data);
                        current = nullptr;
                    }
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

    TraversalOutput LevelOrderTraverse(const BinaryTree_p &tree)
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
                // std::cout << "(" << node->key << ", " << node->data << ")" <<
                // std::endl;
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
