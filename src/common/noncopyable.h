#ifndef __MARISDB_NONCOPYABLE_H__
#define __MARISDB_NONCOPYABLE_H__

namespace MarisDB
{
    class NonCopyable
    {
    protected:
        NonCopyable() = default;
        ~NonCopyable() = default;

        NonCopyable(const NonCopyable&) = delete;
        NonCopyable& operator=(const NonCopyable&) = delete;
    };
}

#endif
