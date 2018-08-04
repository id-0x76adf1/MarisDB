#include "storagemanager.h"

#include <cassert>
#include <cstdio>
#include <filesystem>
#include "pagedfile.h"

namespace MarisDB
{
    PagedFilePtr StorageManager::create(const std::string& fileName)
    {
        assert(!fileName.empty() && "file name can not be empty string");

        if (std::filesystem::exists(fileName))
        {
            throw StorageManagerError{ "create", fileName, "already exists" };
        }

        FILE* f = std::fopen(fileName.c_str(), "w");
        return std::make_shared<PagedFile>(f);
    }

    PagedFilePtr StorageManager::open(const std::string& fileName)
    {
        assert(!fileName.empty() && "file name can not be empty string");

        if (!std::filesystem::exists(fileName))
        {
            throw StorageManagerError{ "open", fileName, "does not exist" };
        }

        FILE* f = std::fopen(fileName.c_str(), "r+");
        return std::make_shared<PagedFile>(f);
    }

    void StorageManager::close(const PagedFilePtr& pagedFile)
    {
        assert(pagedFile && "parameter is null pointer");

        std::fclose(pagedFile->rawFile());
    }

    StorageManagerError::StorageManagerError(const std::string& op, const std::string& fileName, const std::string& message)
        : what_(op + " " + fileName + " failed")
    {
        if (!message.empty())
        {
            what_ = what_ + ": " + message;
        }
    }

    const char* StorageManagerError::what() const
    {
        return what_.c_str();
    }
}
