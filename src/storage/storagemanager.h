#ifndef __MARISDB_SOTRAGE_MANAGER_H__
#define __MARISDB_SOTRAGE_MANAGER_H__

#include "common/noncopyable.h"

namespace MarisDB
{
    class StorageManager : private NonCopyable
    {
    public:
        StorageManager();
        ~StorageManager();
    };
}

#endif // __MARISDB_SOTRAGE_MANAGER_H__
