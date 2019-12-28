#include <iostream>
using namespace std;

#define PI 3.14
int a ;
void g(){
	a++;
	cout << a<< endl;
}
void f(){
	cout << a<< endl;
	a++;
	g();

}
int main(){
	int r;
	cin >> r;
	cout << PI * r* r <<endl;
	a = 10;
	{
		int a= 5;
		cout << a << endl;
	}
	//f();
	cout << a<< endl;
	return 0;
}