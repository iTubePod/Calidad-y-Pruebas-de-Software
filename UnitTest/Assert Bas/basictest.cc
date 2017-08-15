#include "gtest/gtest.h"

TEST(TestCaseName, TestNameOne){

	EXPECT_FALSE(false);
	ASSERT_TRUE(true);

}

TEST(TestCaseName, TestNameTwo){

	EXPECT_TRUE(true);
	ASSERT_TRUE(true);

}

TEST(TestCaseName, TestNameThree){

	ASSERT_EQ(true, true);
	ASSERT_TRUE(true);

}

TEST(TestCaseName, TestNameFour){

	ASSERT_NE(true, false);
	ASSERT_TRUE(true);

}

TEST(TestCaseName, TestNameFive){

	ASSERT_LT(1, 3);
	ASSERT_TRUE(true);

}

TEST(TestCaseName, TestNameSix){

	ASSERT_LE(3, 3);
	ASSERT_TRUE(true);

}

TEST(TestCaseName, TestNameSeven){

	ASSERT_GT(5, 4);
	ASSERT_TRUE(true);

}
TEST(TestCaseName, TestNameEight){

	ASSERT_GE(true, true);
	ASSERT_TRUE(true);

}
TEST(TestCaseName, TestNameNine){

	ASSERT_STREQ("mau", "mau");
	ASSERT_TRUE(true);

}
TEST(TestCaseName, TestNameTen){

	ASSERT_STRNE("mau", "mauro");
	ASSERT_TRUE(true);
}
TEST(TestCaseName, TestNameElf){

	ASSERT_STRCASEEQ("mau", "Mau");
	ASSERT_TRUE(true);

}
TEST(TestCaseName, TestNameTwelve){

	ASSERT_STRCASENE("mau", "Hector");
	ASSERT_TRUE(true);

}
TEST(TestCaseName, TestNameTr){

	ASSERT_FLOAT_EQ(1.233333, 1.233333);
	ASSERT_TRUE(true);
}


TEST(TestCaseName, TestNameCAT){

	ASSERT_DOUBLE_EQ(1.233333, 1.233333);
	ASSERT_TRUE(true);

}
TEST(TestCaseName, TestNameQUIN){

	ASSERT_NEAR(1.233333, 1.233334, 0.000001);
	ASSERT_TRUE(true);

}