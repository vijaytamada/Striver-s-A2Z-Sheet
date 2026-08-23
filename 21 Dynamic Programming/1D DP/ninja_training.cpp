#include <bits/stdc++.h>
using namespace std;

// Soln 01: Recursion
class Solution {
	public:
	int helper(int day, int lastTask, vector<vector<int>> & mat) {
		int maxPoints = INT_MIN;
		
		if (day == 0) {
		    // Return the max val task which was not performed on last day
			for (int i = 0; i<3; i++) {
				if (i != lastTask) {
					maxPoints = max(maxPoints, mat[day][i]);
				}
			}
			
			return maxPoints;
		}
		
		for(int i=0; i<3; i++){
		    if(i != lastTask){
		        int points = mat[day][i] + helper(day - 1, i, mat);
		        maxPoints = max(maxPoints, points);
		    }
		}
		
		return maxPoints;
		
	}
	
	int maximumPoints(vector<vector<int>> & mat) {
		// code here
		return helper(mat.size() - 1, -1, mat);
	}
};

// Soln 02: Memoization
class Solution {
	public:
	int helper(int day, int lastTask, vector<vector<int>> & mat, vector<vector<int>>& dp) {
		int maxPoints = INT_MIN;
		
		if (day == 0) {
		    // Return the max val task which was not performed on last day
			for (int i = 0; i<3; i++) {
				if (i != lastTask) {
					maxPoints = max(maxPoints, mat[day][i]);
				}
			}
			
			return maxPoints;
		}
		
		if(dp[day][lastTask] != -1){
		    return dp[day][lastTask];
		}
		
		for(int i=0; i<3; i++){
		    if(i != lastTask){
		        int points = mat[day][i] + helper(day - 1, i, mat, dp);
		        maxPoints = max(maxPoints, points);
		    }
		}
		
		return dp[day][lastTask] = maxPoints;
		
	}
	
	int maximumPoints(vector<vector<int>> & mat) {
		// code here
		vector<vector<int>> dp(mat.size(), vector<int>(4, -1));
		return helper(mat.size() - 1, 3, mat, dp);
	}
};

// Soln 03: Tabulation
class Solution {
public:
    int maximumPoints(vector<vector<int>> &mat) {
        int n = mat.size();
        vector<vector<int>> dp(n, vector<int>(4, -1));

        // Day 0: dp[0][task] = best points on day 0 given "last task" constraint = task
        for (int task = 0; task < 4; task++) {
            for (int i = 0; i < 3; i++) {
                if (i != task) {
                    dp[0][task] = max(dp[0][task], mat[0][i]);
                }
            }
        }

        // Remaining days
        for (int day = 1; day < n; day++) {
            for (int lastTask = 0; lastTask < 4; lastTask++) {
                int maxPoints = INT_MIN;

                for (int i = 0; i < 3; i++) {
                    if (i != lastTask) {
                        int points = mat[day][i] + dp[day - 1][i];
                        maxPoints = max(maxPoints, points);
                    }
                }

                dp[day][lastTask] = maxPoints;
            }
        }

        return dp[n - 1][3];
    }
};

int main()
{
    

    return 0;
}