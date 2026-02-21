#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  // what number multiplied by itself is x.
  // to find this we can search through the list of numbers that are
  // half as big or less than x.
  // we can search through these numbers using binary search.
  int mySqrt(int x) {
    double doubleX = static_cast<double>(x);
    // first get an array of all the numbers half as big as x or less.
    // TODO: Fix this, the integer division is truncating the value before ceil
    // sees it. I need to use floating point division.
    double halfX = ceil(doubleX / 2.0);
    vector<int> nums;
    for (double i = 0; i <= halfX; i++) {
      nums.push_back(i);
    }

    // now binary search this array for a number that multiplied by itself is
    // equal to x. Or if that number isn't found, find the index that it should
    // be at and return the number that is actually at that index.
    double left = 0;
    double right = nums.size() - 1;
    while (left < right) {
      int mid = floor((right + left) / 2.0);
      if (nums[mid] * nums[mid] == doubleX) {
        return nums[mid];
      } else if (nums[mid] * nums[mid] < doubleX) {
        left = mid + 1;
      } else if (nums[mid] * nums[mid] > doubleX) {
        right = mid - 1;
      }
    }
    if (nums[right] * nums[right] > doubleX) {
      return nums[right - 1];
    } else {
      return nums[right];
    }
    return -1;
  }
};

int main(void) {
  Solution mySolution;
  cout << mySolution.mySqrt(4) << " should be 2" << endl;
  cout << mySolution.mySqrt(8) << " should be 2" << endl;
  cout << mySolution.mySqrt(1) << " should be 1" << endl;
  cout << mySolution.mySqrt(2) << " should be 1" << endl;
  cout << mySolution.mySqrt(3) << " should be 1" << endl;
  return 0;
};
