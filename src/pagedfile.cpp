#include "pagedfile.h"

namespace MarisDB
{
    PagedFile::PagedFile(const std::string& fileName, std::FILE* file)
        : fileName_{ fileName }, file_{ file }
    {
    }

    PagedFile::~PagedFile()
    {
    }
}
