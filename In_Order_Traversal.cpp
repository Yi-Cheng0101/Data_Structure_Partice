vector<int> inorderTraversal(TreeNode* root) {
  vector<int> res;
  if (!root) return res;

  stack<TreeNode *> s;
  TreeNode *cur = root;
  while (cur || !s.empty()) {
    if (cur) {
      s.push(cur);
      cur = cur->left;
    } else {
      TreeNode *node = s.top();
      s.pop();
      res.push_back(node->val);
      cur = node->right;
    }
  }

  return res;
}
