
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
class Solution
{
public:
    string getPermutation(int n, int k)
    {
        int fact = 1;
        vector<int> num;
        for (int i = 1; i <= n; i++)
        {
            fact = fact * i;
            num.push_back(i);
        }
        string ans = "";
        k = k - 1;
        int blockSize = fact / n;

        while (true)
        {
            int index = k / blockSize;
            ans += to_string(num[index]);
            num.erase(num.begin() + index);

            if (num.empty())
            {
                break;
            }
            k = k % blockSize;
            blockSize = blockSize / num.size();
        }

        return ans;
    }
};

int main()
{
    int n = 3; // number of elements
    int k = 3; // kth permutation

    Solution solution;
    string result = solution.getPermutation(n, k);

    cout << "The " << k << "th permutation of numbers from 1 to " << n << " is: " << result << endl;

    return 0;
}
