#include "pagedfile.h"

namespace MarisDB
{
    PagedFile::PagedFile(const std::filesystem::path& path, std::FILE* file)
        : path_{ path }, file_{ file }
    {
    }

    PagedFile::~PagedFile()
    {
    }
}
