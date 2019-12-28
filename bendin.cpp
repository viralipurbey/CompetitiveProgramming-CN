#include<bits/stdc++.h>
using namespace std;

int main(){


	// freopen("bendin.txt","r",stdin);
	// freopen("bendout.txt","w",stdout);

	int x1, x2 , x3, x4, y1, y2, y3, y4;

	cin >> x1 >> y1 >> x2 >> y2;
	cin >> x3 >> y3 >> x4 >> y4;

	int A1, A2 , Aint;

	A1 = (x2 - x1)*(y2 - y1);
	A2 = (x4 - x3)*(y4 - y3);

	int lint, rint, tint, bint;

	lint = max(x1 , x3);
	rint = min(x2 , x4);
	bint = max(y1 , y3);
	tint = min(y2 , y4);

	if((lint < rint)&&(bint < tint)){
		Aint = (rint - lint)*(tint - bint);
	}
	else {
		Aint = 0;
	}

	int Tarea = A1 + A2 - Aint;
	cout << Tarea << endl;

	return 0;
}
