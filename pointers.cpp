#include<bits/stdc++.h>
using namespace std;
int main(){

	int i = 10;
	cout << &i << endl;
	int *p = &i;
	cout << p << endl;

	cout << sizeof(p) << endl;

	cout << i << endl;
	cout << *p << endl;

	i++;

	cout << i << endl;
	cout << *p << endl;

	int a = *p;
	a++;

	cout << a << endl;
	cout << *p << endl;

	(*p)++;

	int *q = p;
	*q = 0; // null pointer

	p++;
	cout << p << endl;

	int arr[10];
	cout << arr << endl;
	cout << &arr[0] << endl;
	arr[0] = 5;
	cout << *arr << endl; 
	cout <<*(arr + 1)<< endl;

	p = &(arr[0]);

	cout << arr << endl;
	cout << p << endl;

	cout << &arr << endl;
	cout << &p << endl;

	cout << sizeof(arr) << endl;
	cout << sizeof(p) << endl;

	p++;
	// arr = arr + 1;

	int *b = arr;
	arr[2] = 7;
	cout << b[2] << endl;

	int arr1[] = {1,2,3};
	char barr[] = "abc";

	cout << arr1  << endl;
	cout << barr << endl;

	char *cp = &barr[0];
	cout << cp << endl;

	char ch = 'a';
	char* pc = &ch;

	cout << ch << endl;
	cout << pc << endl;

	char s[]= "hello";
	char *ps = s;
	cout << s[0] << " " << ps[0];

	return 0;
}