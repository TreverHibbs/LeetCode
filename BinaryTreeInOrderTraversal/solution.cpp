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
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> returnVector;
    if (root == nullptr) {
      return (returnVector);
    } else if (root->left != nullptr) {
      vector<int> leftOrder = inorderTraversal(root->left);
      leftOrder.insert(leftOrder.begin(), root->val);
      return (leftOrder);
    } else if (root->right != nullptr) {
      vector<int> rightOrder = inorderTraversal(root->right);
      rightOrder.insert(rightOrder.end(), root->val);
      return (rightOrder);
    } else {
      returnVector.insert(returnVector.begin(), root->val);
      return returnVector;
    }
  }
};

int main(void) {
  struct TreeNode testTree1 = TreeNode(2, TreeNode(3), TreeNode(5));

  Solution mySolution;
  cout << mySolution.mySqrt(4) << " should be 2" << endl;
  return 0;
};
