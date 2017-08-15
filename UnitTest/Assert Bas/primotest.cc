#include "gtest/gtest.h"
#include "primos.h"

TEST(TestStack, esPrimoCircular){
	char x[256] = "199";
    int size;
    sscanf(x, "%d", &size);
    size=log10(size);
	ASSERT_EQ(1, checkAll(x, 0, size, 1));
}
TEST(TestStack, noPrimoCircular){
	char x[256] = "198";
    int size;
    sscanf(x, "%d", &size);
    size=log10(size);
	ASSERT_EQ(0, checkAll(x, 0, size, 1));
}