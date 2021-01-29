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

    TraversalOutput PreOrderTraverse(const BinaryTree_p &tree,
                                     bool isRecursive = true);

    TraversalOutput InOrderTraverse(const BinaryTree_p &tree,
                                    bool isRecursive = true);

    TraversalOutput PostOrderTraverse(const BinaryTree_p &tree,
                                      bool isRecursive = true);

    TraversalOutput LevelOrderTraverse(const BinaryTree_p &tree);

} // namespace CppSampleCode
