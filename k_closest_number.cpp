#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

vector<int> Kclosestnumber(vector<int> nums, int k, int x) {

    vector<int> result;

    priority_queue<pair<int, int>> maxheap;

    for (int i = 0; i < nums.size(); i++) {

        maxheap.push({abs(nums[i] - x), nums[i]});

        if (maxheap.size() > k) {
            maxheap.pop();
        }
    }

    while (!maxheap.empty()) {
        result.push_back(maxheap.top().second);
        maxheap.pop();
    }

    return result;
}

int main() {

    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 4;
    int x = 3;

    vector<int> result = Kclosestnumber(nums, k, x);

    cout << "K closest numbers: ";

    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}