/*
 * Copyright 2014-present Alibaba Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#pragma once

#include <cstdint>
#include <limits>

#include "autil/TimeUtility.h"

namespace indexlibv2::index {

class KKVTimestampHelper
{
public:
    static uint32_t NormalizeTimestamp(int64_t microSeconds)
    {
        auto seconds = autil::TimeUtility::us2sec(microSeconds);
        if (seconds >= std::numeric_limits<uint32_t>::max()) {
            seconds = std::numeric_limits<uint32_t>::max() - 1;
        }
        return static_cast<uint32_t>(seconds);
    }
};

} // namespace indexlibv2::index
