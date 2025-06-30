
//Approach (Using map and counting)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> mp;

        int result = 0; //to store maximum subsequence length

        for(int &num : nums) {
            mp[num]++;
        }

        for(int &num : nums) {
            int minNum = num;
            int maxNum = num+1;

            if(mp.count(maxNum)) {
                result = max(result, mp[minNum] + mp[maxNum]);
            }
        }

        return result;
    }
};


//Approach (Using map and counting)
//T.C : O(nlogn)
//S.C : O(n)


class Solution {
public:
    int findLHS(vector<int>& v) {
        map<int, int>mp;
        int n=v.size();
        for(int i=0; i<n; i++){
            mp[v[i]]++;
        }
        vector<pair<int,int>>r(mp.begin(),mp.end);
        
        int max=0;
        int currMax=0;
        for(int i=1;i<r.size(); i++){
            if(r[i].first-r[i-1].first==1)currMax=r[i].second + r[i-1].second;
            if(currMax>max)max=currMax;
        }
        return max;
    }
};

//it can also be done by sorting then using using the the sliding window
