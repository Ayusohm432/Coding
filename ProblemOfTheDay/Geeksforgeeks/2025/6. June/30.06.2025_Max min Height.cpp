/*
Problem Link: https://www.geeksforgeeks.org/problems/max-min-height--170647/1
*/

/*Max min Height

Given a garden with n flowers planted in a row, that is represented by an array arr[], where arr[i] denotes the height of the ith flower.You will water them for k days. In one day you can water w continuous flowers. Whenever you water a flower its height increases by 1 unit. You have to maximize the minimum height of all flowers after  k days of watering.

Examples:

Input: arr[] = [2, 3, 4, 5, 1], k = 2, w = 2
Output: 2
Explanation: The minimum height after watering is 2.
Day 1: Water the last two flowers -> arr becomes [2, 3, 4, 6, 2]
Day 2: Water the last two flowers -> arr becomes [2, 3, 4, 7, 3]
Input: arr[] = [5, 8], k = 5, w = 1
Output: 9
Explanation: The minimum height after watering is 9.
Day 1 - Day 4: Water the first flower -> arr becomes [9, 8]
Day 5: Water the second flower -> arr becomes [9, 9]
Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ w ≤ arr.size()
1 ≤ k ≤ 105
1 ≤ arr[i] ≤ 109

*/

class Solution
{
public:
    int maxMinHeight(vector<int> &arr, int k, int w)
    {
        // code here
        int n = arr.size();
        int low = *min_element(arr.begin(), arr.end());
        int high = low + k;

        int result = -1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (solve(mid, arr, k, w))
            {
                result = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return result;
    }

private:
    bool solve(int mid, vector<int> &arr, int k, int w)
    {
        int n = arr.size();
        vector<long long> freq(n + 1, 0);

        long long count = 0;
        long long sum = 0;

        for (int i = 0; i < n; i++)
        {
            sum += freq[i];
            if (arr[i] + sum < mid)
            {
                long long difference = 1LL * mid - (arr[i] + sum);
                count += difference;
                if (count > k)
                {
                    return false;
                }
                freq[i] += difference;
                sum += difference;

                if (i + w < n)
                {
                    freq[i + w] -= difference;
                }
            }
        }
        return true;
    }
};