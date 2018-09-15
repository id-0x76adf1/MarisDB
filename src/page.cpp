#include "page.h"

namespace MarisDB
{
    std::optional<int32_t> HeaderPage::allocPage()
    {
        std::lock_guard<std::mutex> lg{ mutex_ };

        if (freePages_.empty())
        {
            return std::nullopt;
        }

        int32_t pageNO = *freePages_.begin();
        allocatedPages_.insert(pageNO);
        freePages_.erase(freePages_.begin());
        return pageNO;
    }

    Page::~Page()
    {
    }

    Page::Page(int32_t pageNO, std::array<uint8_t, PAGE_SIZE> data)
        : pageNO_{pageNO}, data_{std::move(data)}
    {
    }
}
