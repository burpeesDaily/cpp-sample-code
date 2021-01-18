// Copyright © 2021 by Shun Huang. All rights reserved.
// Licensed under MIT License.
// See LICENSE in the project root for license information.

#pragma once

#include <exception>
#include <string>

namespace CppSampleCode
{
    class DuplicateKeyException : public std::exception
    {
    public:
        explicit DuplicateKeyException(int32_t key)
            : key{key}
        {
        }

        std::string message() const
        {
            return std::to_string(key) + " already exists";
        }

    private:
        int32_t key;
    };

} // namespace CppSampleCode
