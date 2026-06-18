/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL) return NULL;
        Node* temp=root;
        queue<pair<Node*,int>>q;
        q.push({temp,0});
        while(!q.empty()){
            auto top=q.front();
            q.pop();
            Node* curr=top.first;
            int level=top.second;
            if(curr->left) q.push({curr->left,level+1});
            if(curr->right) q.push({curr->right,level+1});
            if(!q.empty() && q.front().second==level){
                curr->next=q.front().first;
            }else{ 
                curr->next=NULL;
            }
        }
        return root;
    }
};