#include "pagedfile.h"
#include <mutex>
#include <optional>
#include <set>

namespace MarisDB
{
    class HeaderPage
    {
    public:
        std::optional<int32_t> allocPage();

    private:
        std::mutex mutex_;
        std::set<int32_t> freePages_;
        std::set<int32_t> allocatedPages_;
    };

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

    PagedFile::PagedFile(const std::filesystem::path& path, std::FILE* file)
        : path_{ path }, file_{ file }
    {
    }

    PagedFile::~PagedFile()
    {
    }
}
