#ifndef __MARISDB_PAGED_FILE_H__
#define __MARISDB_PAGED_FILE_H__

#include <cstdio>

namespace MarisDB
{
    class PagedFile
    {
    public:
        explicit PagedFile(std::FILE* file);
        ~PagedFile();

        FILE* rawFile() const
        {
            return file_;
        }

    private:
        FILE* file_ = nullptr;
    };
}

#endif // __MARISDB_PAGED_FILE_H__
