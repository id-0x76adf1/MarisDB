#ifndef __MARISDB_PAGE_H__
#define __MARISDB_PAGE_H__

#include <array>
#include <cstdint>
#include "marisdb.h"

namespace MarisDB
{
    class Page
    {
    public:
        Page(int32_t pageNO, std::array<uint8_t, PAGE_SIZE> data);

        const std::array<uint8_t, PAGE_SIZE> data() const
        {
            return data_;
        }

        int32_t pageNO() const
        {
            return pageNO_;
        }

    private:
        int32_t pageNO_;
        std::array<uint8_t, PAGE_SIZE> data_;
    };
}

#endif // __MARISDB_PAGE_H__
