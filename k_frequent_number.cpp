#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {

public:

    vector<int> kfrequentnum(vector<int> nums, int k) {

        vector<int> result;

        unordered_map<int, int> mp;

        // Count frequency
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        // Min heap
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > minHeap;

        // Keep only k elements
        for (auto i = mp.begin(); i != mp.end(); i++) {

            minHeap.push({i->second, i->first});

            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        // Store answer
        while (!minHeap.empty()) {

            result.push_back(minHeap.top().second);

            minHeap.pop();
        }

        return result;
    }
};

int main() {

    Solution obj;

    vector<int> nums = {1, 1, 1, 2, 2, 3};

    int k = 2;

    vector<int> result = obj.kfrequentnum(nums, k);

    cout << "Top " << k << " frequent numbers: ";

    for (int x : result) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}