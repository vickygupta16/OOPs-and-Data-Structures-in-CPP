#include<iostream>
#include<string.h>

using namespace std;

class Publication
{
	private:
		char title[20];
		float price;
	public:
		Publication();
		void getData(char *,float);
		void printData();
		~Publication();
};

Publication::Publication()
{
	strcpy(title,"");
	price=0.0;
}

void Publication::getData(char *t,float p)
{
	strcpy(title,t);
	price=p;
}

void Publication::printData()
{
	cout<<"\n\n\tTitle : "<<title;
	cout<<"\n\tPrice : "<<price;
}

Publication::~Publication()
{
	cout<<"\n\n\tDestructor call from Publication";
}

class Book
{
	private:
		int pageCount;
		Publication P;	//container class object P
	public:
		Book();
		void getData(int,char *,float);
		void printData();
		~Book();
};

Book::Book()
{
	pageCount=0;
}

void Book::getData(int pc,char *t,float p)
{
	pageCount=pc;
	P.getData(t,p);		//using container class object to call it's member functions
}

void Book::printData()
{
	P.printData();		//using container class object to call it's member functions
	cout<<"\n\tPage Count : "<<pageCount;
}

Book::~Book()
{
	cout<<"\n\n\tDestructor call from Book";
}

class Tape
{
	private:
		float playTime;
		Publication P;	//container class object P
	public:
		Tape();
		void getData(float,char *,float);
		void printData();
		~Tape();
};

Tape::Tape()
{
	playTime=0;
}

void Tape::getData(float pt,char *t,float p)
{
	playTime=pt;
	P.getData(t,p);		//using container class object to call it's member functions
}

void Tape::printData()
{
	P.printData();		//using container class object to call it's member functions
	cout<<"\n\tPlay Time : "<<playTime;
}

Tape::~Tape()
{
	cout<<"\n\n\tDestructor call from Tape";
}

int main()
{
	Book b;
	b.getData(16,"OOPs",250.0);
	b.printData();
	
	Tape t;
	t.getData(3.4,"DS",160.0);
	t.printData();
	return 0;
}
