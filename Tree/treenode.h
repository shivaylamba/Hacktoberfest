#include<vector>
using namespace std;
template<typename T>
class TreeNode{
    public:
    T data;
    vector<TreeNode <T>*> children;//to carry next pointer

    TreeNode(T data){
        this->data=data;
    }
};