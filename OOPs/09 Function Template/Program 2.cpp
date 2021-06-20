#include<iostream>
using namespace std;
template<class G>
G MODE(G *ar,int size)
{
	G e=ar[0];
	int c,oc;
	G element;
	for(int i=0;i<size;++i)
	{
		oc=0;
		for(int j=0;j<size;++j)
		{
			if(ar[i]==ar[j])
			{
				++oc;
			}
		}
		if(c<oc)
		{
			c=oc;
			element=ar[i];
		}
	}
	return element;
}
int main()
{
	int I[]={9,9,4};
	int i=MODE(I,sizeof(I)/sizeof(I[0]));
	cout<<"\n\tInteger Array : ";
	for(int i=0;i<sizeof(I)/sizeof(I[0]);++i)
	{
		cout<<"\t"<<I[i];
	}
	cout<<"\n\tMode from Integer Array : "<<i;
	
	float F[]={8.94,34.66,34.66,4.22,34.66,8.94};
	double d=MODE(F,sizeof(F)/sizeof(F[0]));
	cout<<"\n\n\tFloat Array : ";
	for(int i=0;i<sizeof(F)/sizeof(F[0]);++i)
	{
		cout<<"\t"<<F[i];
	}
	cout<<"\n\tMode from Double Array : "<<d;
	
	char C[]={'a','b','r','a','k','a','d','a','b','r','a','s'};
	char c=MODE(C,sizeof(C)/sizeof(C[0]));
	cout<<"\n\n\tChar Array : ";
	for(int i=0;i<sizeof(C)/sizeof(C[0]);++i)
	{
		cout<<"\t"<<C[i];
	}
	cout<<"\n\tMode from Char Array : "<<c;
}
