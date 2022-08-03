//https://www.codingninjas.com/codestudio/problems/aggressive-cows_1082559?leftPanelTab=1
//https://youtu.be/wSOfYesTBRk
#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> arr,int cows,int minDist) {
    int n= arr.size();
    int cntCows = 1;
    int lastPlacedCow = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] - lastPlacedCow >= minDist) {
            cntCows++;
            lastPlacedCow = arr[i];
        }
    }
    if (cntCows >= cows) return true;
    return false;
}
int findDistance(vector<int> arr,int cows){
    sort(arr.begin(),arr.end());
    int n= arr.size();
    int start = 1, end = arr[n - 1] - arr[0];   //Range : 1 to max distance
    int result=-1;
    while (start <= end) {
        int mid = (start + end) >> 1;
        if (isPossible(arr,cows,mid)){
            result=mid;
            start = mid + 1;
        }
        else {
          end = mid - 1;
        }
    }
    return result;
}
int main() {
    vector<int>arr={1,2,8,4,9};
    int cows = 3;

    cout << "The largest minimum distance is " <<findDistance(arr,cows)<< endl;

    return 0;
}