#ifndef FUNIX_UTIL_COMPILER_CHECK_H_
#define FUNIX_UTIL_COMPILER_CHECK_H_

#include "funix/util/static_assert.h"

#define EXPECTED_BYTE_SIZE 1
#define EXPECTED_SHORT_SIZE 2
#define EXPECTED_INT_SIZE 4
#define EXPECTED_LONG_SIZE 4
#define EXPECTED_LONG_LONG_SIZE 8

STATIC_ASSERT(sizeof(char) == EXPECTED_BYTE_SIZE);
STATIC_ASSERT(sizeof(unsigned char) == EXPECTED_BYTE_SIZE);

STATIC_ASSERT(sizeof(short) == EXPECTED_SHORT_SIZE);
STATIC_ASSERT(sizeof(unsigned short) == EXPECTED_SHORT_SIZE);

STATIC_ASSERT(sizeof(int) == EXPECTED_INT_SIZE);
STATIC_ASSERT(sizeof(unsigned int) == EXPECTED_INT_SIZE);

STATIC_ASSERT(sizeof(long) == EXPECTED_LONG_SIZE);
STATIC_ASSERT(sizeof(unsigned long) == EXPECTED_LONG_SIZE);

STATIC_ASSERT(sizeof(long long) == EXPECTED_LONG_LONG_SIZE);
STATIC_ASSERT(sizeof(unsigned long long) == EXPECTED_LONG_LONG_SIZE);

#endif
