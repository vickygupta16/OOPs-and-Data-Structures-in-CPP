#include<iostream>

using namespace std;

class Date
{
	private:
		int day,month,year;
	public:
		void getDate(int,int,int);
		void printDate();
		int validate();				//simple date validation
		int operator > (Date);		//overloading comparison operator
		int operator < (Date);		//overloading comparison operator
		int operator == (Date);		//overloading comparison operator
		int operator != (Date);		//overloading comparison operator
		void operator ++ (int);		//overloading post increment operator
		void operator ++ ();		//overloading pre increment operator
		void operator -- (int);		//overloading post decrement operator
		void operator -- ();		//overloading pre decrement operator
};

void Date::getDate(int d,int m,int y)
{
	day=d;
	month=m;
	year=y;
}

void Date::printDate()
{
	cout<<"\n\t"<<day<<":"<<month<<":"<<year;
}

int Date::validate()
{
	if(!(day>=1 && day<=31 && month>=1 && month<=12 && year>=1))
	{
		return 0;
	}
	if(month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12)
	{
		if(day<=31)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else if(month==2 || month==4 || month==6 || month==9 || month==11)
	{
		if(day<=30)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		if((year%4==0 && year%100!=0) || year%400==0)
		{
			if(day<=29)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			if(day<=28)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
	}
}

int Date::operator <(Date d)
{
	if(year<d.year)
	{
		return 1;
	}
	else if(year==d.year && month<d.month)
	{
		return 1;
	}
	else if(year==d.year && month==d.month && day<d.day)
	{
		return 1;
	}
	return 0;
}

int Date::operator >(Date d)
{
	if(year>d.year)
	{
		return 1;
	}
	else if(year==d.year && month>d.month)
	{
		return 1;
	}
	else if(year==d.year && month==d.month && day>d.day)
	{
		return 1;
	}
	return 0;
}

int Date::operator ==(Date d)
{
	if(year==d.year && month==d.month && day==d.day)
	{
		return 1;
	}
	return 0;
}

int Date::operator !=(Date d)
{
	if(!(year==d.year && month==d.month && day==d.day))
	{
		return 1;
	}
	return 0;
}

void Date::operator ++(int ay)
{
	year=year+ay;
}

void Date::operator ++()
{
	++year;
}

void Date::operator --(int ay)
{
	year=year-ay;
}

void Date::operator --()
{
	--year;
}

int main()
{
	Date d1,d2,d3,d4;
	d1.getDate(16,5,1999);
	d2.getDate(30,4,2019);
	d3.getDate(30,7,2018);
	d4.getDate(16,5,1999);
	
	if(d1.validate()==0 || d2.validate()==0 || d3.validate()==0 || d4.validate()==0)
	{
		cout<<"\n\tError in date";
		exit(0);
	}
	
	cout<<"\n\n";
	if(d1<d2)
	{
		d1.printDate();
		cout<<"\n\tis less than";
		d2.printDate();
	}
	
	cout<<"\n\n";
	if(d2>d3)
	{
		d2.printDate();
		cout<<"\n\tis greater than";
		d3.printDate();
	}
	
	cout<<"\n\n";
	if(d1==d4)
	{
		d1.printDate();
		cout<<"\n\tis equal to";
		d4.printDate();
	}
	
	cout<<"\n\n";
	if(d3!=d4)
	{
		d3.printDate();
		cout<<"\n\tis not equal to";
		d4.printDate();
	}
	
	cout<<"\n\n";
	d2.printDate();
	d2.operator ++(3);
	d2.printDate();
	
	cout<<"\n\n";
	d4.printDate();
	d4.operator ++();
	d4.printDate();
	
	cout<<"\n\n";
	d3.printDate();
	d3.operator --(2);
	d3.printDate();
	
	cout<<"\n\n";
	d4.printDate();
	d4.operator --();
	d4.printDate();
	return 0;
}
