#include <catch2/catch.hpp>
#include <filesystem>
#include "pagedfile.h"
#include "storagemanager.h"

using namespace MarisDB;
namespace fs = std::filesystem;

static fs::path tempFilePath()
{
    return fs::temp_directory_path() / std::tmpnam(nullptr);
}

TEST_CASE("Create paged file", "[StorageManager]")
{
    StorageManager manager;
    auto path = tempFilePath();
    auto pagedFile = manager.create(path);

    REQUIRE(pagedFile->path() == path);
    REQUIRE(fs::exists(path));

    manager.close(pagedFile);
}

TEST_CASE("Open paged file", "[StorageManager]")
{
    StorageManager manager;
    auto path = tempFilePath();
    auto pagedFile = manager.create(path);
    manager.close(pagedFile);

    auto samePagedFile = manager.open(path);
    REQUIRE(samePagedFile->path() == path);
    REQUIRE(samePagedFile);

    manager.close(samePagedFile);
}

TEST_CASE("Close paged file", "[StorageManager]")
{
    StorageManager manager;
    auto path = tempFilePath();
    auto pagedFile = manager.create(path);

    manager.close(pagedFile);
    REQUIRE_FALSE(pagedFile);
}
