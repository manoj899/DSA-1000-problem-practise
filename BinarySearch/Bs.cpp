#include<iostream>
#include<vector>
using namespace std;


//iterative approach : T(log-n of base 2)
//recursive : T(log-n of base 2) + some constant - O(1)
void BS(vector<int>& arr, int target){

    int si = 0;
    int ei = arr.size()-1;
    while(si <= ei){
        int mid = si + (ei-si)/2;

        if(target == arr[mid]){
            cout<<"YES"<<endl;
            return;
        }
        else if(arr[mid] < target){
            si = mid+1;
        }
        else{
            ei = mid-1;
        }
    }

    cout<<"NO"<<endl;
}

bool binarySearchRecursive(vector<int>& arr, int si, int ei, int target){

    if(si > ei){
        return false;
    }

    int mid = si + (ei-si)/2;

    if(arr[mid] == target){
        return true;
    }
    else if(arr[mid] < target){
        si = mid+1;
        return binarySearchRecursive(arr, si,ei,target);
    }
    else{
        ei = mid - 1;
        return binarySearchRecursive(arr, si,ei,target);
    }
}

/*
Lower Bound: Smallest index i where arr[i] >= target.
    ○ Uses binary search to find the first occurrence.

● Upper Bound: Smallest index i where arr[i] > target.

    ● Example: In [1, 2, 4, 4, 5, 6], for target = 4
    ○ Lower Bound = 2, Upper Bound = 4
*/

void lowerBound(vector<int>& arr,int num){
    //Smallest index i where arr[i] >= target.
    int idx = lower_bound(arr.begin(), arr.end(), num) - arr.begin();
    if(idx == arr.size()) cout<<"required number doesnt exist"<<endl;
    else cout<<"found:"<<idx<<endl;
}

void upperBound(vector<int>& arr,int num){
    
    // Smallest index i where arr[i] > target.
    int idx = upper_bound(arr.begin(), arr.end(), num) - arr.begin();
    if(idx == arr.size()) cout<<"required number doesnt exist"<<endl;
    else cout<<"found:"<<idx<<endl;
}

int main(){

    // cout<<"Binary search"<<endl;

    vector<int> arr = {3,4,4,5,5,5,6,7,8};
    // BS(arr,9);

    // cout<<binarySearchRecursive(arr,0,arr.size()-1,3);

    upperBound(arr, 5);
    return 0;
}

