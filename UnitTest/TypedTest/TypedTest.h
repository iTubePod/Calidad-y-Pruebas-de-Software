#include <iostream>

class Padre {
public:
	Padre(){}
	virtual void doSomething() = 0;
};

class H1 : public Padre{
public:
	void doSomething()
	{
		std::cout<<"H1"<<std::endl;
	}
};
class H2 : public Padre{
public:
	void doSomething()
	{
		std::cout<<"H2"<<std::endl;
	}
};
class H3 : public Padre{
public:
	void doSomething()
	{
		std::cout<<"H3"<<std::endl;
	}
};