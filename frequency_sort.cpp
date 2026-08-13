#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution{
    public:
    void frequencysort(vector<int> nums){

        unordered_map<int , int> mp;

        for(int i = 0 ; i < nums.size(); i ++){
            
            mp[nums[i]]++;

        }

        priority_queue<
        pair<int , int> ,
        vector< pair <int , int>>,
        less<pair<int, int>>
        >
        maxHeap;

        for (auto i = mp.begin(); i != mp.end(); i++) {
                 maxHeap.push({i->second, i->first});
        }

        while(!maxHeap.empty()){
            int frequency = maxHeap.top().first;
            int ele = maxHeap.top().second;

            for(int i = 0 ; i < frequency; i++){
                cout<<ele<<" ";

            }

            maxHeap.pop();
        }
    }
};

int main() {

    Solution obj;

    vector<int> nums = {1, 1, 1, 2, 2, 3};

    obj.frequencysort(nums);

    return 0;
}