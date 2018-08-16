#include <catch2/catch.hpp>
#include <filesystem>
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
    manager.create(path);

    REQUIRE(fs::exists(path));
}

TEST_CASE("Open paged file", "[StorageManager]")
{
    StorageManager manager;
    auto path = tempFilePath();
    auto pageFile = manager.create(path);
    manager.close(pageFile);

    REQUIRE_FALSE(pageFile);
    REQUIRE(manager.open(path));
}
