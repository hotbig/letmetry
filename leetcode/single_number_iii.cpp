#include<iostream>
#include<numeric>
#include<vector>
#include<string>
#include<limits>

using namespace std;
#if 0
Once again, we need to use XOR to solve this problem. But this time, we need to do it in two passes:

In the first pass, we XOR all elements in the array, and get the XOR of the two numbers we need to find. 
Note that since the two numbers are distinct, so there must be a set bit (that is, the bit with value '1') 
in the XOR result. Find out an arbitrary set bit (for example, the rightmost set bit).

In the second pass, we divide all numbers into two groups, one with the aforementioned bit set, another 
with the aforementinoed bit unset. Two different numbers we need to find must fall into thte two distrinct 
groups. XOR numbers in each group, we can find a number in either group.

Complexity:

Time: O (n)

    Space: O (1)

    A Corner Case:

    When diff == numeric_limits<int>::min(), -diff is also numeric_limits<int>::min(). Therefore, the value 
    of diff after executing diff &= -diff is still numeric_limits<int>::min(). The answer is still correct.

#endif
class Solution{
    public:
        vector<int> singleNumber(vector<int>& nums){
            int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
            diff &= -diff;

            vector<int> rets(2, 0);

            for(int i=0; i < nums.size(); i++)
            {
                if(diff & nums[i]) 
                    rets[0] ^= nums[i];
                else               
                    rets[1] ^= nums[i];
            }

            return rets;
        }
};


int main()
{
    Solution s;
    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(1);
    v.push_back(5);
    vector<int> r=s.singleNumber(v) ;
    cout << r[0] << " " << r[1] << endl;
    
    return 0;
}
