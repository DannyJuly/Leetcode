//DFS

TreeNode* invertTree(TreeNode* root) {//先序优先遍历
        if(root==NULL) return root;
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
   TreeNode* invertTree(TreeNode* root) {//后序优先遍历
         if(root==NULL) return root;
         invertTree(root->left);
         invertTree(root->right);
         TreeNode* temp = root->left;
         root->left = root->right;
         root->right = temp;
         return root;
    }
   TreeNode* invertTree(TreeNode* root) {//中序优先遍历
         if(root==NULL) return root;
         invertTree(root->left);
         TreeNode* temp = root->left;
         root->left = root->right;
         root->right = temp;
         invertTree(root->left);
         return root;
    }

