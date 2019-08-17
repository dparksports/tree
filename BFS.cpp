#include <iostream>
#include <cstddef>
#include <queue>
#include <string>
#include <cstdlib>

using namespace std;
class Node{
public:
    int data;
    Node *left,*right;
    Node(int d){
        data=d;
        left=right=NULL;
    }
};
class BFS{
private:
    queue<Node*> levelQueue;

public:
    Node* insert(Node* root, int data){
        if(root==NULL){
            return new Node(data);
        }
        else{
            Node* cur;
            if(data<=root->data){
                cur=insert(root->left,data);
                root->left=cur;
            }
            else{
                cur=insert(root->right,data);
                root->right=cur;
            }
            return root;
        }
    }


    void levelOrder(Node * root){
        if (root == NULL) {
            return;
        }

        cout << root->data << " ";

        if (root->left != NULL) {
            levelQueue.push(root->left);
        }
        if (root->right != NULL) {
            levelQueue.push(root->right);
        }

        while (! levelQueue.empty()) {
            Node *node = levelQueue.front();
            levelQueue.pop();

            levelOrder(node);
        }
    }

};//End of Solution
int main(){
    BFS myTree;
    Node* root=NULL;
    int T,data;
    cin>>T;
    while(T-->0){
        cin>>data;
        root= myTree.insert(root,data);
    }
    myTree.levelOrder(root);
    return 0;
}
