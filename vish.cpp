#include <stdio.h>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll count(ll a[],ll k,ll sti,ll endi)
{
    ll sum = 0;
    if(sti < endi)
    {
        ll midi = (sti+endi)/2;
        sum += count(a,k,sti,midi);
        sum += count(a,k,midi+1,endi);
        ll li = sti;
        ll ri=midi+1;
        vector<ll> temp;
        while(li <= midi && ri <= endi)
        {
            if(a[li] > a[ri])
            {
                temp.push_back(a[ri]);
                if(a[li] - a[ri] >= k)
                {
                    sum += (midi+1-li);
                }
                ri++;
            }
                
            else
            {
                temp.push_back(a[li]);
                if(a[ri] - a[li] >= k)
                {
                    sum += (endi + 1-ri);
                }
                li++;
            }
        }
        while(li <= midi)
        {
            temp.push_back(a[li++]);
        }
        while( ri <= midi)
        {
            temp.push_back(a[ri++]);
        }

        for(ll i = sti, k = 0; i <= endi; i++, k++){
		    a[i] = temp[k];
	    }
    }
    return sum;
}

int main(void) {
	// your code goes here
	ll n;
	cin>>n;
	ll k;
	cin>>k;
	ll arr[n];
	for(ll i=0;i<n;i++)
	{
	    ll ele;
	    cin>>ele;
	    arr[i] = ele;
	}
	cout<<count(arr,k,0,n-1)<<endl;
	//delete []arr;
	return 0;
}

