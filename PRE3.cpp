// #include<bits/stdc++.h>
// using namespace std;

// int calc_sum(int matrix[][100],int n){

// 	int sum = 0;
// 	for(int i = 1; i < (n-1); i++){
// 		sum += matrix[0][i];
// 	}
// 	for(int i = 1; i < (n-1); i++){
// 		sum += matrix[n-1][i];
// 	}
// 	for(int i = 1; i < (n-1); i++){
// 		sum += matrix[i][0];
// 	}
// 	for(int i = 1; i < (n-1); i++){
// 		sum += matrix[i][n-1];
// 	}

// 	for(int i = 0; i < n; i++){
// 		for(int j = 0; j < n; j++){
// 			if((i+j==(n-1)) || (i==j)){
// 				sum += matrix[i][j];
// 			}
// 		}
// 	}
// 	return sum;
// }

// int main(){
// 	int n;
// 	cin >> n; 
// 	int matrix[n][100];
// 	for(int i = 0; i < n; i++){
// 		for(int j = 0; j < n; j++){
// 			cin >> matrix[i][j];
// 		}
// 	}

// 	int ans = calc_sum(matrix,n);
// 	cout << ans << endl;
// 	return 0;
// }
#include<iostream>
using namespace std;
int main()
{
	int N;
	int sum=0;
	cout<<"enter size of array";
	cin>>N;
	int array[N][N];

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> array[i][j];
		}
	}

	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(i == 0 || j == 0 || i == N-1 || j == N-1){
				sum += array[i][j];
			}
		}
	}
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (i==j||i+j==N-1)
			{
			sum=sum+array[i][j];	/* code */
			}
		}// tumne n ki value  pass ki thi.. firse run krro and
	}
	sum=sum-(array[0][0]+array[0][N-1]+array[N-1][0]+array[N-1][N-1]);
	cout<<"sum of odd"<<sum<<"\n";
	return 0;
	

}