#include<queue>
class Solution {
public:
    int run(TreeNode *root) {
        if(!root)  
    {  
          return 0;  
    }  
      int height = 0;  
       queue<TreeNode*>q;  
      q.push(root);  
        while(!q.empty())  
       {  
          ++height;  
          int size = q.size();  
          while(size--)  
           {  
                TreeNode* pnode = q.front(); 
               q.pop();  
              if(!pnode->left && !pnode->right)  
              {  
                 return height;  
              }  
                if(pnode->left)  
              {  
                   q.push(pnode->left);  
              }  
             if(pnode->right)  
              {  
                  q.push(pnode->right);  
              }  
         }  
      }
    return height;

    }
};
