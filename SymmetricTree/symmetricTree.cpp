#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  bool isSymmetric(TreeNode *root) {
    // so we will solve this with breadth first search
    // we will check at every level for if it is symetrical
    // or not.
    vector<TreeNode *> q;
    if (!root) {
      return false;
    }
    q.push_back(root);

    while (!q.empty()) {
      int levelSize = q.size();
      bool isAllNullptr = true;
      for (int i = 0; i < levelSize; i++) {
        if (q[i] != nullptr) {
          isAllNullptr = false;
          break;
        }
      }
      if (isAllNullptr) {
        return true;
      }
      for (int i = 0, j = levelSize - 1; i <= j; i++, j--) {
        // iterate over the current level
        // checking that the first elements
        // is equal to last
        // element + i == element - i
        if (i == j && q[i] != nullptr) {
          q.insert(q.begin() + levelSize + i, nullptr);
          q.insert(q.begin() + levelSize + 1 + i, nullptr);
        } else if (i == j) {
          q.insert(q.begin() + levelSize + i, q[i]->left);
          q.insert(q.begin() + levelSize + 1 + i, q[i]->right);
        } else if (q[i] == nullptr ^ q[j] == nullptr) {
          return false;
        } else if (q[i] == nullptr && q[j] == nullptr) {
          q.insert(q.begin() + levelSize + i, nullptr);
          q.insert(q.begin() + levelSize + 1 + i, nullptr);
          q.insert(q.end() - i, nullptr);
          q.insert(q.end() - i, nullptr);
        } else if (q[i]->val == q[j]->val) {
          q.insert(q.begin() + levelSize + i, q[i]->left);
          q.insert(q.begin() + levelSize + 1 + i, q[i]->right);
          q.insert(q.end() - i, q[j]->left);
          q.insert(q.end() - i, q[j]->right);
        } else {
          return false;
        }
      }
      // remove the elements from q that have
      // been checked
      q.erase(q.begin(), q.begin() + levelSize);
    }
    return true;
  }
};

int main(void) {
  TreeNode N3(3);
  TreeNode N4(4);
  TreeNode NL2(2, &N3, &N4);
  TreeNode NR2(2, &N4, &N3);
  TreeNode N1(1, &NL2, &NR2);
  Solution mySolution;
  cout << mySolution.isSymmetric(&N1) << " should be 1" << endl;
  TreeNode NI2(2, nullptr, &N3);
  TreeNode NI1(1, &NI2, &NI2);
  cout << mySolution.isSymmetric(&NI1) << " should be 0" << endl;
  TreeNode NIL2(2, &N3, nullptr);
  TreeNode N3I1(1, &NI2, &NIL2);
  cout << mySolution.isSymmetric(&N3I1) << " should be 1" << endl;
  return 0;
};
