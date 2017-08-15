#include <stack>

using namespace std;

template <class T>
class myStack{
public:
	void push(T value){
		st.push(value);
	}
	T pop(){
		st.pop();
	}
	int size(){
		return st.size();
	}
protected:
	stack <T> st;
};