#include "page.h"

namespace MarisDB
{
    Page::Page(int32_t pageNO, std::array<uint8_t, PAGE_SIZE> data)
        : pageNO_{pageNO}, data_{std::move(data)}
    {
    }
}
