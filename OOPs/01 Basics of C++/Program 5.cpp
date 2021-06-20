#include<iostream>
#include<ctime>
#include<iomanip>
#include<algorithm>

using namespace std;

int main()
{
	srand(time(0));
	int magic=rand()%6+1,guess,chance=4;
	//cout<<"\n\n\t"<<magic;
	while(chance>0)
	{
		cout<<"\n\n\tEnter a number between 1 to 6 : ";
		cin>>guess;
		if(guess>=1 && guess<=6)
		{
			if(guess==magic)
			{
				cout<<"\n\tCorrect Guess!";
				exit(0);
			}
			else
			{
				cout<<"\n\tWrong Guess!";
				--chance;
				cout<<"\n\tChances left "<<chance;
				continue;
			}	
		}
		else
		{
			cout<<"\n\t"<<guess<<" is not in range of 1-6";
		}
	}
	return 0;
}
