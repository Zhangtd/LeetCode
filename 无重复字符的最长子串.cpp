#include<iostream>
#include<string>
#include<map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty())
            return 0;
        int left, right, res;
        map<char, int> hashmap;
        left = 0;
        right = 0;
        res = 0;
        while(left<=s.size()-1 && right<=s.size()-1)
        {
            if(hashmap.find(s[right])==hashmap.end()){
                hashmap[s[right]] = 0;
                right++;
                res = max(right-left, res);
            }
            else{
                hashmap.erase(s[left]);
                left++;
            }

        }
        return res;
    }
};

int main()
{
    Solution solution;
    string s("abcabcbb");
    cout<<s.empty()<<endl;
    cout<<solution.lengthOfLongestSubstring(s);
    return 0;
}
