#include<bits/stdc++.h>
#include<cmath>
using namespace std;

double calcHappiness(vector<pair< pair<int,int> , int> > cities, int n){
	double *dp = new double[n];

	dp[0] = cities[0].second;

	for(int i = 1; i < n; i++){

		double temp = -999999999.000;
		double x1 = cities[i].first.first;
		double y1 = cities[i].first.second;

		for(int j = 0; j < i; j++){

			double x2 = cities[j].first.first;
			double y2 = cities[j].first.second;

			double dist = (x1 - x2) * (x1 - x2) + (y1 -y2) * (y1 - y2);
			dist = sqrt(dist);

			temp = max(temp, dp[j] + cities[i].second - dist);

		}

		dp[i] = temp;
	}

	double ans = dp[n-1];
	delete[] dp;
	return ans;

}

int main(){

	int n;
	cin >> n;

	vector<pair< pair<int,int> , int> > cities;

	for(int i = 0; i < n; i++){
		int a, b, c;

		cin >> a >> b >> c;
		cities.push_back(make_pair(make_pair(a,b), c));

	}

	double happy = calcHappiness(cities, n);
	cout << fixed << setprecision(6) << happy << endl;
}