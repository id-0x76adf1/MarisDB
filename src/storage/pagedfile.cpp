#include "pagedfile.h"

namespace MarisDB
{
    PagedFile::PagedFile(std::FILE* file)
        : file_(file)
    {
    }

    PagedFile::~PagedFile()
    {
    }
}
