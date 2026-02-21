// BinarySearchInsert.cpp : This file contains the 'main' function. Program
// execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int searchInsert(vector<int> &nums, int target) {
    int low = 0;
    int high = nums.size();
    int mid;
    if (target > nums[high - 1]) {
      return high;
    }
    while (low <= high) {
      mid = (low + high) / 2;
      if (nums[mid] == target) {
        return mid;
      }

      if (target < nums[mid]) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    return low;
  }
};

int main() {
  vector<int> nums = {1, 3, 5, 6};
  vector<int> &numsRef = nums;
  Solution mySolution;
  int returnIndex = mySolution.searchInsert(numsRef, 5);
  cout << "Hello World!\n";
  cout << returnIndex << " should be " << 2;
}
