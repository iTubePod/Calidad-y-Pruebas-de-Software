#include "gtest/gtest.h"
#include "pila.h"

class TestStack : public ::testing::Test{
public:
	void SetUp(){
		myst.push(10);
		myst.push(20);
	}
	void TearDown(){

	}
	myStack<int> myst;
};

TEST_F(TestStack, pushtest){
	myst.push(30);
	myst.push(40);
	EXPECT_EQ(4, myst.size());
}
TEST_F(TestStack, poptest){
	myst.pop();
	myst.pop();
	EXPECT_EQ(2, myst.size());
}