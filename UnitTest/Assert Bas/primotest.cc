#include "gtest/gtest.h"
#include "primos.h"

TEST(TestStack, pushtest){
	char x[256];
    scanf ("%s",&x);
    int size;
    sscanf(x, "%d", &size);
    size=log10(size);
	ASSERT_EQ(1, checkAll(x, 0, size, 1));
}