#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <vector>
#include "gtest/gtest.h"

using ::testing::EmptyTestEventListener;
using ::testing::InitGoogleTest;
using ::testing::UnitTest;
using ::testing::TestEventListeners;
using ::testing::TestPartResult;

using namespace std;

class Scanner{
private:
    string command;
public:
	static int nw;
    bool checkPort(int port){
        string prefix = "netstat -ltun | grep :";
        stringstream ss;
        ss << port;
        string str = ss.str();
        string all = prefix + str + " ";
        string ls = GetStdoutFromCommand(all);
        if (ls=="")
            return false;
        return true;
    }
    string GetStdoutFromCommand(string cmd) {
        string data;
        FILE * stream;
        const int max_buffer = 256;
        char buffer[max_buffer];
        cmd.append(" 2>&1");
        stream = popen(cmd.c_str(), "r");
        if (stream) {
            while (!feof(stream))
                if (fgets(buffer, max_buffer, stream) != NULL) data.append(buffer);
            pclose(stream);
        }
        return data;
    }
    vector<string> writeFile(){
        vector<string> x;
        string cmd = "sudo lsof -PiTCP -sTCP:LISTEN";
        string ls = GetStdoutFromCommand(cmd);
        ofstream myfile;
        string in;
        ifstream infile;
        try{
            myfile.open ("parse.txt");
            myfile << ls;
            myfile.close();
        }
        catch (int x) {
            cout<<"Error opening file"<<endl;
        }
        try {
            infile.open ("parse.txt");
            while(std::getline(infile, in))
            {
                getline(infile,in);
                x.push_back(in);
            }
            infile.close();
        } catch (int x) {
            cout<<"Error opening file"<<endl;
        }
        return x;
    }
    void* operator new(std::size_t n)
	{
		nw++;
		void* temp = ::operator new(n);
        return temp;
	}
    void operator delete (void *p) {
    	nw--;
		return ::operator delete(p);
  	}   
};

int Scanner::nw = 0;

class EventListener : public EmptyTestEventListener
{
public:
	int port = 80;
	Scanner* s;
	EventListener(){
		s = new Scanner();
	}
	virtual void OnTestProgramStart(const UnitTest&){
		s->writeFile();
		cout<<"CHECKING PORTS..."<<endl;
	    if(s->checkPort(port))
	        cout<<"Found!"<<endl;
	    else
	        cout<<"Not found!"<<endl;
	    delete s;
	}
	virtual void OnTestPartResult(const TestPartResult& tpr){
		if(tpr.failed())
		{
			cout<<"Failed: "<<tpr.summary()<<endl;
		}
		else
		{
			cout<<tpr.summary()<<endl;
		}
		
	}
};

TEST(TcnUno, tname){
	ASSERT_EQ(Scanner::nw, 1);
}

int main(int argc, char** argv){
	InitGoogleTest(&argc, argv);
	TestEventListeners& listener = UnitTest::GetInstance()->listeners();
	listener.Append(new EventListener);
	return RUN_ALL_TESTS();
}
