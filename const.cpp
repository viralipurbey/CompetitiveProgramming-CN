#include<bits/stdc++.h>
using namespace std;

void g(int const &a){
	//a++;
}
void f(const int* p){
	//(*p)++;
}
int main(){

	//constant int
	int const i2 = 12;
	const int i = 10;

	//constant reference from a non const integer
	int j = 12;
	const int &k = j;
	//i = 12;
	j++;
	cout << k << endl;

	//constant reference from a constant integer
	int const j2 = 12;
	int const &k2 = j2;

	//reference from a constant integer
	int const j3 = 12;
	//int &k3 = j3;
	//we cannot modify k3

	//pointer to constants
	// int *p = &i;
	int const *p = &i;  // i is constant
	p = &j;

	int const *p2 = &j;  // j is not constant
	cout << *p2 << endl;
	j++;
	cout << *p2 << endl;
	f(&j);
	g(j);


	//constant pointer
	int* const p3 = &j;
	(*p3)++;
	//p3 = &j;

	int const * const p4 = &j;

	return 0; 
}