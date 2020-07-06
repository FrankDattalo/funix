#ifndef FUNIX_UTIL_STATIC_ASSERT_H_
#define FUNIX_UTIL_STATIC_ASSERT_H_

#define STATIC_ASSERT(predicate) __STATIC_ASSERT(predicate, __FILE__, __LINE__)

#define __STATIC_ASSERT(predicate, file, line) typedef char error_at ## file ## on_line ## line ## in_static_assert [2*!!(predicate)-1];

#endif
