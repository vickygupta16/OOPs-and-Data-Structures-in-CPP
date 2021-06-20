#include<iostream>

using namespace std;

class ALPHA
{
	private:
		static int total;			//static data member
		int ID;
	public:
		ALPHA();
		~ALPHA();
		static void showTotal();	//static member function
		void showID();
};

ALPHA::ALPHA()
{
	++total;
	ID=total;
}

ALPHA::~ALPHA()
{
	cout<<"\n\n\tDestroying ID number : "<<ID;
	--total;
}

void ALPHA::showTotal()
{
	cout<<"\n\n\tTotal : "<<total;
	//cout<<"\n\tID : "<<ID;	
	//static member function can only access static data members
}

void ALPHA::showID()
{
	//cout<<"\n\n\tTotal : "<<total;
	//normal member functions can access normal data members as well as static data members
	cout<<"\n\n\tID : "<<ID;
}

int ALPHA::total=0;		//syntax to initialize a static data member

int main()
{
	ALPHA A1;
	ALPHA::showTotal();
	ALPHA A2,A3;
	ALPHA::showTotal();
	A1.showID();
	A2.showID();
	A3.showID();
	cout<<"\n\n\tEnd of program";
	return 0;
}
