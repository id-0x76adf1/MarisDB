#include <catch2/catch.hpp>
#include <filesystem>
#include "storagemanager.h"

using namespace MarisDB;
namespace fs = std::filesystem;

TEST_CASE("Create paged file", "[StorageManager]")
{
    StorageManager manager;
    auto path = fs::temp_directory_path() / "page1";
    manager.create(path);

    REQUIRE(fs::exists(path));
}
