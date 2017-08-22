#include "gtest/gtest.h"
#include <future>
#include <numeric>
#include <algorithm>
#include <fstream>
#include <string>

using ::testing::EmptyTestEventListener;
using ::testing::InitGoogleTest;
using ::testing::UnitTest;
using ::testing::TestEventListeners;
using ::testing::TestPartResult;


class EventListener : public EmptyTestEventListener
{
private:
	clock_t tStart;
	std::ofstream myfile;
public:
	EventListener(){
		myfile.open ("log.txt");
	}
	virtual void OnTestProgramStart(const UnitTest&){
		tStart = clock();
		myfile<<"	--------LOG--------\n"<<std::endl;
		fprintf(stdout, "	--------Bienvenido a las pruebas--------\n");
	}
	virtual void OnTestPartResult(const TestPartResult& tpr){
		if(tpr.failed())
		{
			myfile<<"	    --Algo salió mal-- \n";
			myfile<<tpr.summary();
			myfile<<"\n";
		}
		else
		{
			myfile<<"OK! ";
			myfile<<tpr.summary();
			myfile<<"\n";
		}
		myfile<<"	--------LOG--------\n"<<std::endl;
	}
};

TEST(TcnUno, tname){	
	ASSERT_EQ(1, -1);
}

int main(int argc, char** argv){
	InitGoogleTest(&argc, argv);
	TestEventListeners& listener = UnitTest::GetInstance()->listeners();
	listener.Append(new EventListener);
	return RUN_ALL_TESTS();
}