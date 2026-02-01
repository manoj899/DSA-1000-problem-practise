#include<iostream>
#include<vector>
typedef long long ll;
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

void lowerBoundCode(vector<int>& arr, int target) {
    int si = 0;
    int ei = arr.size() - 1;
    int ans = -1;

    while (si <= ei) {
        int mid = si + (ei - si) / 2;

        if (arr[mid] >= target) {
            ans = mid;
            ei = mid - 1;   // move left
        } else {
            si = mid + 1;   // move right
        }
    }

    if (ans != -1)
        cout << "YES: " << ans << endl;
    else
        cout << "NO" << endl;
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

/*.  Imp:  Binary search on answer
    ● Used when searching for a minimum or maximum satisfying
condition.
    -- maximise the minimum or minimise the maximum

    ● Example: Finding the smallest k that satisfies a function.
    ● Typical Form:
    ○ TTTTTTFFFFF, where T = true and F = false.
    ■ Binary search for the last True or first False.
    ○ FFFFFFTTTTT, where T = true and F = false.
    ■ Binary search for the first True or last False.

    remember code tempalate
*/

/*
Problem: Given a number N, return square root of N rounded down to an
integer.
Example: Input: N = 14 , Output: 3 

from outside it look simple, difficult to guess its binary search problem, you have to recognize and break it out the problem
*/

bool helper(ll mid,int target){
    return mid*mid <= target;
}

void solve(){
    ll n;
    cin>>n;
    ll si=1,ei=1e9,ans=-1;
    // TTTTTTTTTTTFFFFFFFFF
    // auto helper = [&](ll mid)->bool{ // lambda fxn
    //     return (mid*mid<=n);
    // };
    vector<int>arr(n);

    int num = 14;
    while(si<=ei){
        ll mid = si + (ei-si)/2;
        if(helper(mid, num)){
            ans=mid;
            si=mid+1;
        }
        else{
            ei=mid-1;
        }
    }
    cout<<ans<<endl;

    // FFFFFFFTTTTTTT
    // while(si<=ei){
    //     ll mid = si + (ei-si)/2;
    //     if(helper(mid,n)){
    //         ans=mid;
    //         ei=mid-1;
    //     }
    //     else{
    //         si=mid+1;
    //     }
    // }
}

/*
Lower_bound and upper_bound also follow the same approach
*/

bool helperLowerBound(vector<int>& arr,int mid, int target){
    return (arr[mid]>= target);
}
void lowerBoundImplementation(vector<int> arr, int target){
    int si=0;
    int ei = arr.size()-1;
    int ans = -1;

    //lambda fxn approach
    // auto helper = [&](int mid)->bool{
    //     return (arr[mid]>= target);
    // };
    //FFFFFFTTTTTTT
    while(si <= ei){
        int mid = si + (ei-si)/2;
        if(helperLowerBound(arr,mid,target)){
            ans = mid;
            ei = mid-1;
        }
        else{
            si = mid+1;
        }
    }

    if(ans != -1){
        cout<<"Upper bound: "<<ans<<":"<<arr[ans]<<endl;
    }
    else{
        cout<<"Not found"<<endl;
    }
}

//find peak element
//ans : you dont need to scan both side array.. observe slop..increasing slope move right else left
int findPeakElement(vector<int>& nums) {
        int si = 0;
        int ei = nums.size() - 1;

        while (si < ei) {// it will end when there is only 1 element is left si== ei, at that point both index pos are same..
            int mid = si + (ei - si) / 2;

            if (nums[mid] < nums[mid + 1]) {
                si = mid + 1;   // move right
            } else {
                ei = mid;       // move left (or stay)
            }
        }

        return si; // or ei (both same).. it will end when there is only 1 element is left si== ei, at that point both index pos are same..
}

/*
    when should be use si<ei and si <= ei in binary search?

    Use si <= ei when:
    You are searching for an exact value
    (Classical binary search)

    Why <=?
    Because:
    You are checking each mid explicitly
    Even when si == ei, that last element still needs to be checked
    After that, search space becomes invalid (si > ei) → stop

    "I must test every possible candidate"

    2. Use si < ei when:
    You are shrinking a search space with a guarantee
    (Answer is guaranteed to exist)
    This problem: Find Peak Element
    Also used in:
        Lower bound
        Upper bound
        First true in monotonic function
        Rotated array minimum
        Binary search on answer
*/



int main(){

    // cout<<"Binary search"<<endl;

    vector<int> arr = {3,4,4,5,5,5,6,7,9};
    // BS(arr,9);

    // cout<<binarySearchRecursive(arr,0,arr.size()-1,3);

    // lowerBoundCode(arr, 8);

    lowerBoundImplementation(arr,5);
    return 0;
}

