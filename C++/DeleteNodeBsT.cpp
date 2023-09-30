void delete1(TreeNode* h , map <TreeNode* , pair<TreeNode*,int>> &mp){  
       if(h->right ==NULL && h->left == NULL){
          auto it = mp[h];
          if(it.second ==0){
              it.first->right = NULL;
              return ;
          } 
          if(it.second ==1){
              it.first->left = NULL;
              return ;
          }
       }
       
       if(h->right != NULL){
           h->val = h->right->val;  
           mp[h->right]= {h,0} ; 
           delete1(h->right,mp);   
       }
       else if(h->left != NULL){
           h->val = h->left->val;    
           mp[h->left]= {h,1} ; 
           delete1(h->left,mp);   
       } 
    }
    void Find( TreeNode* root, int key, map <TreeNode* , pair<TreeNode*,int>> &mp ){
    
    if(root ==NULL) return ; 
    if(root->val == key){
       delete1(root,mp); 
       return ; 
    } 
    if(root->left!=NULL){
        mp[root->left]={root,1};
    }
    if(root->right !=NULL){
        mp[root->right] = {root,0};
    }
    Find(root->left, key,mp); 
    Find(root->right , key,mp);
    } 
    TreeNode* deleteNode(TreeNode* root, int key) { 
        map <TreeNode* , pair<TreeNode*,int>> mp; 
        if(root == NULL) return NULL; 
        if(root->left == NULL && root->right == NULL&& root->val == key) {
            return NULL;
        }
        Find(root , key,mp); 
        return root;
    }