#include "storagemanager.h"

#include <cassert>
#include <cstdio>
#include <filesystem>
#include "pagedfile.h"

namespace MarisDB
{
    PagedFilePtr StorageManager::create(const std::filesystem::path& path)
    {
        assert(!path.empty() && "file path can not be empty");

        if (std::filesystem::exists(path))
        {
            throw StorageManagerError{ "create", path.string(), "already exists" };
        }

        FILE* f = std::fopen(path.string().c_str(), "w");
        auto pagedFile = std::make_shared<PagedFile>(path, f);
        openPagedFiles_.insert(std::make_pair(path.string(), pagedFile));
        return pagedFile;
    }

    PagedFilePtr StorageManager::open(const std::filesystem::path& path)
    {
        assert(!path.empty() && "file path can not be empty");

        if (!std::filesystem::exists(path))
        {
            throw StorageManagerError{ "open", path.string(), "does not exist" };
        }

        FILE* f = std::fopen(path.string().c_str(), "r+");
        auto pagedFile = std::make_shared<PagedFile>(path, f);
        openPagedFiles_.insert(std::make_pair(path.string(), pagedFile));
        return pagedFile;
    }

    void StorageManager::close(PagedFilePtr& pagedFile)
    {
        assert(pagedFile && "parameter is null pointer");

        auto it = openPagedFiles_.find(pagedFile->path().string());
        if (it != openPagedFiles_.end())
        {
            openPagedFiles_.erase(it);
        }
        std::fclose(pagedFile->rawFile());

        pagedFile = nullptr;
    }

    StorageManagerError::StorageManagerError(const std::string& op, const std::string& fileName, const std::string& message)
        : what_{ op + " " + fileName + " failed" }
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
