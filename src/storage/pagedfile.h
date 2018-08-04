#ifndef __MARISDB_PAGED_FILE_H__
#define __MARISDB_PAGED_FILE_H__

#include <cstdio>
#include <string>

namespace MarisDB
{
    class PagedFile
    {
    public:
        PagedFile(const std::string& fileName, std::FILE* file);
        ~PagedFile();

        const std::string& fileName() const
        {
            return fileName_;
        }

        FILE* rawFile() const
        {
            return file_;
        }

    private:
        std::string fileName_;
        FILE* file_ = nullptr;
    };
}

#endif // __MARISDB_PAGED_FILE_H__
