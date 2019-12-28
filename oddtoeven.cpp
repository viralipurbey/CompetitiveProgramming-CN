#include<bits/stdc++.h>
using namespace std;
int maxLen(int arr[], int n)
{
int n0=0,n1=0;
for(int i=0;i<n;i++)
{
    if(arr[i]==0){ n0++;}
    if(arr[i]==1){ n1++;}
}
int x=n0-n1;
int X=abs(x);
int N = X;
if(!N){
	N = n0 * 2;
}
return N;
}

int main()
{
	int n;
	cin>>n;
	int array[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>array[i];
	}
	cout << maxLen(array,n);

}
