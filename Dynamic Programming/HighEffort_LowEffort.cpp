//https://www.geeksforgeeks.org/dynamic-programming-high-effort-vs-low-effort-tasks-problem/
#include <iostream>
#include <vector>
using namespace std;

int maxTasks(vector<int>high, vector<int>low, int n){

	if (n <= 0)
		return 0;
    // Determines which task to choose on day n, then returns the maximum till that day
	return max(high[n - 1] + maxTasks(high, low, (n - 2)),low[n - 1] + maxTasks(high, low, (n - 1)));
}

int maxTasks2(vector<int>high, vector<int>low, int n){

    // An array task_dp that stores the maximum
    int task_dp[n+1];

    // If n = 0, no solution exists
    task_dp[0] = 0;

    // If n = 1, high effort task on that day will be the solution
    task_dp[1] = high[0];

    // Fill the entire array determining which task to choose on day i
    for (int i = 2; i <= n; i++){
        task_dp[i] = max(high[i-1] + task_dp[i-2],low[i-1] + task_dp[i-1]);
    }

    return task_dp[n];
}

int main(){
    vector<int>high={3, 6, 8, 7, 6};
    vector<int>low={1, 5, 4, 5, 3};
    cout<<maxTasks2(high,low,5);
	return 0;
}
