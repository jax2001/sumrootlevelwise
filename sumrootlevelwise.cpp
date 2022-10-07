#include <iostream>
#include <queue>
using namespace std;

//define node via class for tree
class Node{
public:
    int data;
    Node *right;
    Node *left;
    Node(){
        right=NULL;
        left=NULL;
    }
    Node(int n){
        data=n;
        right=NULL;
        left=NULL;
    }
};

Node *root=NULL;

//function to create tree
Node* createTree(Node *node=NULL){
    int data;
    cout << "Enter number (Enter -1 to stop creation) : ";
    cin >> data;
    if(data==-1){
        return NULL;
    }else{
        cout << "Enter data at left node : ";
        Node* tmp=new Node(data);
        tmp->left=createTree();
        cout << "Enter data at right node : ";
        tmp->right=createTree();
        return tmp;
    }
}

//function to print the sum of leaf node at each level
void printLevelLeafSum(){
    queue<pair<Node*,int>> qu;
    Node *tmp;
    int sum{0};
    int lvl{1};
    if(root==NULL){
        cout << sum;
    }else{
        qu.push({root,lvl});
        while(!qu.empty()){
            tmp=qu.front().first;
            if(lvl!=qu.front().second){
                cout << sum << endl;
                sum=0;
            }
            lvl=qu.front().second;
            if(tmp->right==NULL && tmp->left==NULL){
                sum+=tmp->data;
            }else{
                if(tmp->left!=NULL)     qu.push({tmp->left,lvl+1});
                if(tmp->right!=NULL)    qu.push({tmp->right,lvl+1});
            }
            qu.pop();
        }
        cout << sum << endl;
    }
}

int main(int argc, const char * argv[]) {
    root=createTree();
    cout << "\n";
    printLevelLeafSum();
    cout << "\n";
    return 0;
}
