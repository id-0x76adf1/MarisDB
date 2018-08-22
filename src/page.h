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
        explicit Page(std::array<uint8_t, PAGE_SIZE> data);

        const std::array<uint8_t, PAGE_SIZE> data() const
        {
            return data_;
        }

    private:
        std::array<uint8_t, PAGE_SIZE> data_;
    };
}

#endif // __MARISDB_PAGE_H__
