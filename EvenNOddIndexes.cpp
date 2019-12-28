#include<iostream>
using namespace std;
int main()
{
	int N,sum_even=0,sum_odd=0;
	cout<<"enter size of array";
	cin>>N;
	int array[N];
	for (int i = 0; i < N; ++i)
	{
		cin>>array[i];
	}
	for (int i = 0; i < N; ++i)
	{
	if (i%2==0&&array[i]%2==0)
	{
		sum_even=sum_even+array[i];
	}
	 if (i%2!=0&&array[i]%2!=0)
	{
		sum_odd=sum_odd+array[i];
	}
	}
	cout<<"sum of odd"<<sum_odd<<"\n";
	cout<<"sum of sum_even"<<sum_even<<"\n";
	/*for (int i = 0; i < N; ++i)
	{
		cout<<array[i];
	}*/



}