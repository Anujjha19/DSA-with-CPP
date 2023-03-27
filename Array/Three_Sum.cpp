#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> temp;
    int i, j, k;
    for (i = 0; i < nums.size() - 2; i++)
    {
        for (j = i + 1; j < nums.size() - 1; j++)
        {
            for (k = j + 1; k < nums.size(); k++)
            {
                temp.clear();
                if (nums[i] + nums[j] + nums[k] == 0)
                {
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                }
                if (temp.size() != 0)
                    ans.push_back(temp);
            }
        }
    }

    return ans;
}

int main()
{
    vector<int> arr{-1, 0, 1, 2, -1, -4};
    vector<vector<int>> ans;
    ans = threeSum(arr);
    cout << "The triplets are as follows: " << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}


/* class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() < 3) return {};
        vector<vector<int>> ret;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;++i){
            if(i>0 && nums[i] == nums[i-1]) continue;
            int tar = 0 - nums[i],hi=nums.size()-1,lo=i+1;
            while(hi>lo){
                int summ = nums[hi]+nums[lo];
                if(summ > tar)
                    hi--;
                else if(summ < tar)
                    lo++;
                else{
                    ret.push_back({nums[i],nums[lo],nums[hi]});
                    lo++,hi--;
                    while(hi>lo && nums[hi]==nums[hi+1]) hi--;
                    while(hi>lo && nums[lo]==nums[lo-1]) lo++;
                }    
            }
        }
        return ret;
    }
}; */