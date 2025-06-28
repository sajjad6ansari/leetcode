class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        if (k == nums.size())
            return nums;

        // Copy nums to a temp vector to find k largest elements
        vector<int> temp(nums);
        
        // Use nth_element to put the k largest elements in the first k positions (unordered)
        nth_element(begin(temp), begin(temp) + k - 1, end(temp), greater<int>()); //Average TC is O(n)

        // Determine the threshold value (k-th largest element)
        int threshold = temp[k - 1];

        // Count how many times threshold appears in top k elements
        int countThreshold = count(temp.begin(), temp.begin() + k, threshold); //O(k)

        vector<int> result;
        for (int num : nums) {
            if (num > threshold) {
                result.push_back(num);
            } else if (num == threshold && countThreshold > 0) {
                result.push_back(num);
                --countThreshold;
            }
            if (result.size() == k)
                break;
        }

        return result;
    }
};
