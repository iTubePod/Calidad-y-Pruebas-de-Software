#include "gtest/gtest.h"
#include "SortTest.h"
#include <iostream>

template <class T>
class Fixture : public ::testing::Test{
public:
	void SetUp(){
		parent = new T();
	}
	void TearDown(){
		delete parent;
	}
	Padre* parent;
};

typedef ::testing::Types<H1, H2, H3> implementations;

TYPED_TEST_CASE (Fixture, implementations);

TYPED_TEST(Fixture, testDoSomething){
	this->parent->Sort();
}