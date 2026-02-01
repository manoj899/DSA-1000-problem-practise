#include<iostream>
#include<vector>
#include <algorithm>
typedef long long ll;

using namespace std;
/*
--How to find which type to use here
-on reading description you find that its an monotonic fxn as on increasing height , required water also increases..(shows BS nature)
-here and h - a[i] = water at that level. so sum(h-a[i]) <= x(given water unit)

- remember the template, so that no need to think ..just think the helper fxn
*/

bool helper(vector<ll>& arr, ll mid, ll w){
    ll sum = 0;
    for(auto it:arr){
       sum += max(0ll, mid - it);// if coral hieght is larger than water unit.. 0 water
    }

    return sum <= w;
}


void buildingAcqa(vector<ll>& arr,ll w){

    ll si = 0, ei = ei = 1e12;//note:checking all possible height in ll range
    ll ans = -1;

    while(si <= ei){
        ll mid = si + (ei-si)/2;

        if(helper(arr, mid,w)){// as it monotonically inc fxn so ans will be like TTTTTTFFFFF
            ans = mid;
            si = mid+1;
        }
        else{
            ei = mid-1;
        }
    }

    cout<<ans<<endl;
}



int main(){

    vector<ll> arr = {3, 1, 2, 4, 6, 2, 5};
    vector<ll> arr2 = {2, 6, 5, 9, 1, 8};

    ll water = 9;
    ll water2 = 1984;

    buildingAcqa(arr2,water2);
    return 0;
}