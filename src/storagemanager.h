#ifndef __MARISDB_SOTRAGE_MANAGER_H__
#define __MARISDB_SOTRAGE_MANAGER_H__

#include <exception>
#include <memory>
#include <string>
#include <unordered_map>
#include "noncopyable.h"

namespace MarisDB
{
    class PagedFile;
    using PagedFilePtr = std::shared_ptr<PagedFile>;

    class StorageManager : private NonCopyable
    {
    public:
        StorageManager() = default;
        ~StorageManager() = default;

        PagedFilePtr create(const std::string& fileName);
        PagedFilePtr open(const std::string& fileName);
        void close(const PagedFilePtr& pagedFile);

    private:
        std::unordered_map<std::string, PagedFilePtr> openPagedFiles_;
    };

    class StorageManagerError : public std::exception
    {
    public:
        StorageManagerError(const std::string& op, const std::string& fileName, const std::string& message);

        virtual const char* what() const override;

    private:
        std::string what_;
    };
}

#endif // __MARISDB_SOTRAGE_MANAGER_H__
