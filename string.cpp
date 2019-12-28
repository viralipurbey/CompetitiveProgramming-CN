#include<bits/stdc++.h>
using namespace std;
int main(){
	string *sp = new string;
	*sp = "def";

	cout << sp << endl;
	cout << *sp << endl;

	string s;
	// cin >> s;   // breaks at space
	// cout << s<< endl;
	// getline(cin,s);
	// cout << s<< endl;

	s= "defdef";
	s[0] = 'a';
	string s1 = "def";

	string s2 = s + s1;
	cout << s2 << endl;

	cout << s2.size() << endl;
	cout << s2.substr(3) << endl;
	cout << s2.substr(3,3) << endl;

	cout << s2.find("def") << endl;

	char ch = 97;
	cout << ch << endl;
}