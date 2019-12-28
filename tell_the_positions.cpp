#include<bits/stdc++.h>
#include<string>
#include<algorithm>
using namespace std;

struct student{
	int roll_no;
	string name;
	int total_marks;
};

// bool comp(student s1, student s2){
// 	if(s1.total_marks == s2.total_marks){
// 		if(s1.roll_no < s2.roll_no){
// 			return s1 < s2;
// 		}
// 		else{
// 			return s1 > s2;
// 		}
// 	}else{
// 		return s1 < s2;
// 	}
// }

bool comp(student s1, student s2)
{
    if(s1.total_marks == s2.total_marks){
        return s1.roll_no < s2.roll_no;
    }
    return s1.total_marks > s2.total_marks;
}

int main(){
	int n;
	cin >> n;
	student students[n];
	int *marks = new int[3];

	for(int i = 0 ; i < n; i++){
		students[i].roll_no = i+1;
		cin >> students[i].name>> marks[0] >> marks[1] >> marks[2];
		students[i].total_marks = marks[0] + marks[1] + marks[2];
	}
	
	sort(students, students + n, comp);

	for(int i = 0; i < n; i++){
		cout << i+1 <<" " << students[i].name << endl;
	}
	delete[] marks;
	return 0;


}