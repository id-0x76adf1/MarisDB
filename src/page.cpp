#include "page.h"

namespace MarisDB
{
    Page::Page(std::array<uint8_t, PAGE_SIZE> data)
        : data_(std::move(data))
    {
    }
}
