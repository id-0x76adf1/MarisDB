#ifndef __MARISDB_PAGE_H__
#define __MARISDB_PAGE_H__

#include <array>
#include <cstdint>
#include <mutex>
#include <optional>
#include <set>
#include "marisdb.h"

namespace MarisDB
{
    class Page
    {
    public:
        Page(int32_t pageNO, std::array<uint8_t, PAGE_SIZE> data);
        virtual ~Page();

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

    class HeaderPage : public Page
    {
    public:
        std::optional<int32_t> allocPage();

    private:
        std::mutex mutex_;
        std::set<int32_t> freePages_;
        std::set<int32_t> allocatedPages_;
    };
}

#endif // __MARISDB_PAGE_H__
