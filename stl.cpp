#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <set>
//#include <map>
#include <unordered_map>
//g++ -std=c++0x stl.cpp
// using unordered map getting an error in compiling, now it is solved

using namespace std;
int main(){
	// Vector

	// vector<int> v(5);
	// for(int i = 0; i < v.size(); i++){
	// 	v[i] = i+1;
	// }
	// vector<int> v;
	// for(int i =0; i <5; i++){
	// 	v.push_back(i+1);
	// }
	// vector<int>::iterator it;

	// for(it = v.begin();it != v.end(); it++){
	// 	cout <<*it << endl;
	// }

	// String
	// string s = "Virali";
	// //string s1(s);   // Copy s to s1
	// string s1(s,2,4);
	// string s2 = s.substr(1,4);
	// cout << s << endl;
	// cout << s1 << endl;
	// cout << s2 << endl;

	// if(s1.compare(s2) == 0){
	// 	cout << s1 <<" is equal to " << s2 << endl;
	// }
	// else{
	// 	cout << s1 <<" is not equal to " << s2 << endl;
	// }

	// Pair

	// pair<int,char> p;
	// p = make_pair(2, 'b');
	// pair<int, char> p2(1,'a');

	// cout << p.first << " " <<p.second <<endl;
	// cout << p2.first << " " << p2.second << endl;

	// Set

	// set<int> s;
	// int arr[] = {1,2 ,3,4 ,5,6,5};
	// for(int i = 0; i < 7; i++){
	// 	s.insert(arr[i]);
	// }

	// set<int>::iterator it;
	// for(it = s.begin(); it != s.end(); it++){
	// 	cout << *it << endl;
	// }

	// if(s.find(6) == s.end()){
	// 	cout << "Element not found" << endl;
	// }
	// else{
	// 	cout << "Element is found" << endl;
	// }

	// Map

	// int arr[] = {1,2 ,3,4 ,5,6,5};
	// map<int,int> m;
	// for(int i = 0; i < 7; i++){
	//  	m[arr[i]]++;
	// }

	// map<int,int>::iterator it;
	// for(it = m.begin(); it != m.end(); it++){
	// 	cout << it->first << " : " <<it->second << endl;
	// }
	// cout <<endl;

	// m.erase(1);
	// for(it = m.begin(); it != m.end(); it++){
	// 	cout << it->first << " : " <<it->second << endl;
	// }

	// Unordered Map

	int arr[] = {1,2 ,3,4 ,5,6,5};
	unordered_map<int, int> m;
	for(int i = 0; i < 7; i++){
	 	m[arr[i]]++;
	}

	unordered_map<int,int>::iterator it;
	for(it = m.begin(); it != m.end(); it++){
		cout << it->first << " : " <<it->second << endl;
	}
	cout <<endl;

	m.erase(1);
	for(it = m.begin(); it != m.end(); it++){
		cout << it->first << " : " <<it->second << endl;
	}


	return 0;
} 