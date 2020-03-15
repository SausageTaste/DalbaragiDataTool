#pragma once

#include <memory>

#include "d_mapdata.h"


namespace dal {

    // Returns nullptr if parsing fails.
    std::unique_ptr<v1::MapChunkInfo> parseDLB_v1(const uint8_t* const buf, const size_t bufSize);

}
