//number of way to reach a position  after exactly  k steps

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int countWays(int startPos, int endPos, int k)
    {
        const int MOD = 1e9 + 7;
        const int MAX_POSITION = 2001; // Adjust based on the problem constraints

        vector<vector<int>> dp(k + 1, vector<int>(MAX_POSITION, 0));

        // Base case: At step 0, there's only one way to be at the starting position
        dp[0][startPos] = 1;

        // Dynamic Programming to calculate the number of ways
        for (int step = 1; step <= k; ++step)
        {
            for (int pos = 0; pos < MAX_POSITION; ++pos)
            {
                // Move left
                dp[step][pos] = (dp[step][pos] + (pos > 0 ? dp[step - 1][pos - 1] : 0)) % MOD;
                // Move right
                dp[step][pos] = (dp[step][pos] + dp[step - 1][pos + 1]) % MOD;
            }
        }

        // The result is the number of ways to reach the endPos after k steps
        return dp[k][endPos];
    }
};

int main()
{
    Solution solution;

    // Input
    int startPos, endPos, k;
    cout << "Enter the starting position: ";
    cin >> startPos;
    cout << "Enter the ending position: ";
    cin >> endPos;
    cout << "Enter the number of steps: ";
    cin >> k;

    // Calculate and output the result
    int result = solution.countWays(startPos, endPos, k);
    cout << "Number of Ways: " << result << endl;

    return 0;
}
