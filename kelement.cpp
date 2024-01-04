//k-divisible elements subarray
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countDistinct(vector<int> &nums, int k, int p)
    {
        set<vector<int>> s;
        for (int i = 0; i < nums.size(); i++)
        {
            int count = 0;
            vector<int> temp;
            for (int j = i; j < nums.size(); j++)
            {
                if (count < k)
                {
                    temp.push_back(nums[j]);
                    s.insert(temp);

                    if (nums[j] % p == 0)
                        count++;
                }
                else if (count == k)
                {
                    if (nums[j] % p != 0)
                    {
                        temp.push_back(nums[j]);
                        s.insert(temp);
                    }
                    else
                        break;
                }
            }
            temp.clear();
        }
        return s.size();
    }
};
int main()
{
    Solution solution;

    cout << "Enter the number of elements in nums: ";
    int n;
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of nums: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int k, p;
    cout << "Enter the value of k: ";
    cin >> k;
    cout << "Enter the value of p: ";
    cin >> p;

    int result = solution.countDistinct(nums, k, p);

    cout << "Distinct Subarrays Count: " << result << endl;

    return 0;
}
