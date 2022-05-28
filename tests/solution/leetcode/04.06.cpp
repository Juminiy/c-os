#include <map>
using namespace std ; 
// Definition for a binary tree node.
struct TreeNode {
    int val ;
    TreeNode *left ;
    TreeNode *right ;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution {
private:
    map< TreeNode* , TreeNode* > parents ;
    TreeNode * aim ; 
    int fin ;
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        aim = p ;
        fin = 0 ;
        parents[root] = nullptr ; 
        dfs(root) ; 
        if (p->right) {
            TreeNode *prlll = p->right ; 
            while (prlll -> left) { 
                prlll = prlll -> left ; 
            } 
            return prlll ;
        } else {
            if (parents[p] && parents[p]->left == p) {
                return parents[p] ; 
            } else { 
                TreeNode *pppl = parents[p] ; 
                while ( pppl ) { 
                    if (parents[pppl] && parents[pppl]->left == pppl) {
                        return parents[pppl] ; 
                    }
                    pppl = parents[pppl] ; 
                }
                return nullptr ; 
            }
        } 
        return nullptr ; 
    }
    void dfs(TreeNode *cur) { 
        if (cur == nullptr ) { 
            return ; 
        }
        if (cur == aim || fin == 1) {
            fin = 1 ; 
            return ;
        }
        if (cur->left != nullptr) {
            parents[cur->left] = cur ;
            dfs(cur -> left) ; 
        }
        if (cur->right != nullptr) {
            parents[cur->right] = cur ; 
            dfs(cur -> right) ; 
        } 
        
    }
};