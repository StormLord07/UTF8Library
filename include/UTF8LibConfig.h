#ifndef UTF8LIB_CONFIG_H
#define UTF8LIB_CONFIG_H

#ifdef _WIN32
#ifdef BUILDING_UTF8LIB
#define UTF8LIB_API __declspec(dllexport)
#else
#define UTF8LIB_API __declspec(dllimport)
#endif
#else
#define UTF8LIB_API __attribute__((visibility("default")))
#endif

#endif // UTF8LIB_CONFIG_H
