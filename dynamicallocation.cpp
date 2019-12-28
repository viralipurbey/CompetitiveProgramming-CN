#include<bits/stdc++.h>
using namespace std;

int main(){
	int* p = new int;
	*p = 10;
	cout << *p << endl;
	delete p;

	int n;
	cin >> n;
	int *pa = new int[n];
	*(pa + 0) = 10;
	for(int i = 1; i < n; i++){
		cin >> pa[i];
	}

	int max = -1;
	for(int i = 0; i < n; i++){
		if (pa[i] > max)
			max = pa[i];
	}
	cout << max << endl;

	int** p1 = new int*[n];
	for(int i = 0; i < n; i++){
		p1[i]= new int[i+1];
		for(int j = 0;j <= i; j++ ){
			cin >> p1[i][j];
		}
	}
	for(int i = 0; i < n;i++){
		delete [] p1[i];
	}
	delete [] p1;

	return 0;
}