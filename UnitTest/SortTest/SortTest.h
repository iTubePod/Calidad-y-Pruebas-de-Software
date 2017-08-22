#include <iostream>

class Padre {
private:
	int x[6];
public:
	Padre()
	{
		x={6,4,5,1,5,3};
	}
	virtual void Sort() = 0;
};

class H1 : public Padre{
public:
	void Sort()
	{
		
		
	}
};
class H2 : public Padre{
public:
	void Sort()
	{
		std::cout<<"H2"<<std::endl;
	}
};
class H3 : public Padre{
public:
	void Sort()
	{
		std::cout<<"H3"<<std::endl;
	}
};