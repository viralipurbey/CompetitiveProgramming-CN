#include<bits/stdc++.h>
using namespace std;

void print(int* p){
	cout << *p << endl;
}

void increment_p(int* p){
	p++;
}

void increment(int* p){
	(*p)++;
}
void sum(int a[], int size){
	int sum = 0;
	cout << sizeof(a) << endl;
	for(int i = 0; i < size; i++){
		sum+=a[i];
	}
	cout << sum << endl;
}
int main(){

	int i = 10;
	int* p = &i;

	print(p);
	increment_p(p);
	print(p);

	print(p);
	increment(p);
	print(p);

	int a[10];
	cout << sizeof(a) << endl;
	sum(a, 10);

	int** p2 = &p;
	cout << p2 << endl;
	cout << &p << endl;

	cout << p << endl;
	cout << *p2 << endl;
	cout << &i << endl;

	cout << i << endl;
	cout <<*p << endl;
	cout <<**p2 << endl;

	return 0;
}