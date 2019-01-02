#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        if(nums.empty())
            return res;
        map<int, int> dict;
        int length = nums.size();
        for(int i=0; i<length; i++)
        {
            if(dict.count(target-nums[i])!=0)
            {
                res.push_back(dict[target-nums[i]]);
                res.push_back(i);
                break;
            }
            dict[nums[i]] = i;
        }
        return res;
    }
};

int main()
{
    int a[] = {3,2,4};
    vector<int> arr(a, a+3);
    Solution solution;
    vector<int> res = solution.twoSum(arr, 6);
    for(int i=0; i<res.size(); i++)
        cout<<res[i]<<" ";
    return 0;
}
