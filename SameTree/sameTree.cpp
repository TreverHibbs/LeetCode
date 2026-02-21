#include <iostream>
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
  bool isSameTree(TreeNode *p, TreeNode *q) {
    if (p == nullptr && q == nullptr) {
      return true;
    } else if (p == nullptr || q == nullptr) {
      return false;
    }

    if (isSameTree(p->left, q->left) == false) {
      return false;
    }
    if (p->val != q->val) {
      return false;
    }
    if (isSameTree(p->right, q->right) == false) {
      return false;
    }
    return true;
  }
};

int main(void) {
  TreeNode a(2);
  TreeNode b(3);
  TreeNode tree123(1, &a, &b);
  Solution mySolution;
  cout << mySolution.isSameTree(&tree123, &tree123) << " should be 1" << endl;
  TreeNode treeX(1, &a, nullptr);
  TreeNode treeY(1, nullptr, &a);
  cout << mySolution.isSameTree(&treeX, &treeY) << " should be 0" << endl;
  TreeNode tree1(1);
  TreeNode tree121(1, &a, &tree1);
  TreeNode tree112(1, &tree1, &a);
  cout << mySolution.isSameTree(&tree121, &tree112) << " should be 0" << endl;
  return 0;
};
