// Copyright © 2021 by Shun Huang. All rights reserved.
// Licensed under MIT License.
// See LICENSE in the project root for license information.

#include "BinaryTree.hpp"
#include "Traversal.hpp"

#include <cstdlib>

namespace CppSampleCode
{

  bool isBalance(const BinaryTree_p &tree, const Node_p &node)
  {

    size_t leftHeight = tree->getHeight(node->left);
    size_t rightHeight = tree->getHeight(node->right);

    if (std::abs(static_cast<int64_t>(leftHeight - rightHeight)) > 1)
    {
      return false;
    }

    if (node->left)
    {
      if (!isBalance(tree, node->left))
      {
        return false;
      }
    }

    if (node->right)
    {
      if (!isBalance(tree, node->right))
      {
        return false;
      }
    }

    return true;
  }

  bool checkBalance(const BinaryTree_p &tree)
  {
    TraversalOutput inorderOutput = inOrderTraverse(tree);

    for (size_t index = 0; index < inorderOutput.size() - 1; ++index)
    {
      if (inorderOutput.at(index).first > inorderOutput.at(index + 1).first)
      {
        return false;
      }
    }
    return true;
  }

  bool verifyBinarySearchTreeProperties(const BinaryTree_p &tree)
  {
    if (!tree)
    {
      return true;
    }
    return isBalance(tree, tree->getRoot());
  }

} // namespace CppSampleCode
