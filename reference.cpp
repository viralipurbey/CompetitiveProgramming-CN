#include<bits/stdc++.h>
using namespace std;

void increment(int &n){
	n++;
}

int& f(int n){
	int a = n;
	return a;

}

int* f2(){
	int i = 10;
	return &i;
}
int main(){
	int i = 10;
	int& j = i;

	int& k = f(i);  // Galti kar rhe h
	cout << k << endl;

	increment(i);
	cout << i << endl;

	i++;
	cout << j << endl;
	j++;
	cout << i << endl;
	k = 50;
	j = k;
	cout << j << endl;
	cout << i << endl;
	return 0;
}