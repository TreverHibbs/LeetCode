#include <iostream>
#include <queue>
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
  int maxDepth(TreeNode *root) {
    // to do this with breadth first approach we need to iterate
    // over each node in the first layer then the second ect...
    if (!root) {
      return 0;
    }
    int depth = 0;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      int levelSize = q.size();
      depth++;
      for (int i = 0; i < levelSize; i++) {
        TreeNode *node = q.front();
        q.pop();
        if (node->left != nullptr) {
          q.push(node->left);
        }
        if (node->right != nullptr) {
          q.push(node->right);
        }
      }
    }
    return depth;
  }
};

int main(void) {
  TreeNode N9(9);
  TreeNode N15(15);
  TreeNode N7(7);
  TreeNode N20(20, &N15, &N7);
  TreeNode N3(3, &N9, &N20);
  Solution mySolution;
  cout << mySolution.maxDepth(&N3) << " should be 3" << endl;
  TreeNode N2(2);
  TreeNode N1(1, nullptr, &N2);
  cout << mySolution.maxDepth(&N1) << " should be 2" << endl;
  return 0;
};
