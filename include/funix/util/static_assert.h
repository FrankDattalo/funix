#ifndef FUNIX_UTIL_STATIC_ASSERT_H_
#define FUNIX_UTIL_STATIC_ASSERT_H_

#define STATIC_ASSERT(predicate) __STATIC_ASSERT(predicate, __LINE__, __FILE__)

#define __STATIC_ASSERT(predicate, line, file) typedef char (file ## line) [2*!!(predicate)-1];

#endif
