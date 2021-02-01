// Copyright © 2021 by Shun Huang. All rights reserved.
// Licensed under MIT License.
// See LICENSE in the project root for license information.

#pragma once

#include <any>
#include <string>
#include <vector>

#include "BinaryTree.hpp"

namespace CppSampleCode
{

    using TraversalOutput = std::vector<std::pair<int32_t, std::any>>;

    TraversalOutput preOrderTraverse(const BinaryTree_p &tree,
                                     bool isRecursive = true);

    TraversalOutput inOrderTraverse(const BinaryTree_p &tree,
                                    bool isRecursive = true);

    TraversalOutput postOrderTraverse(const BinaryTree_p &tree,
                                      bool isRecursive = true);

    TraversalOutput levelOrderTraverse(const BinaryTree_p &tree);

} // namespace CppSampleCode
