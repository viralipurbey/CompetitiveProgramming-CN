#include<bits/stdc++.h>
using namespace std;

struct obj{
	int weight;
	int value;
	double val_weight;
};

bool comp(obj o1, obj o2){
	return o1.val_weight > o2.val_weight;
}

double frac_knap(obj object[],int n, int W){

	double cost = 0.0;
	sort(object,object + n, comp);

	for(int i = 0; i < n; i++){
		if(object[i].weight <= W){
			W = W - object[i].weight;
			cost += object[i].value;
		}
		else{
			double frac = ((double) W)/object[i].weight;
			cost += object[i].value * frac;
		}
	}

	return cost;

}
int main(){
	int n;
	cin >> n;
	int W;
	cin >> W;
	obj object[n];
	for(int i = 0; i < n; i++){
		cin >> object[i].weight >> object[i].value;
		object[i].val_weight = ((double)object[i].value) / (object[i].weight);
	}

	double cost = frac_knap(object, n,W);
	cout << cost << endl;
	return 0;
}