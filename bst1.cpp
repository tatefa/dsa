#include<iostream>
#include<cstdlib>
using namespace std;
class node{
    public:
    int data;
    node *left;
    node *right;
};
class binarytree{
    public:
    int count,key;
    node *root;
    node *temp;
    binarytree(){
        root = NULL;
        count = 0;
    }
    void create();
    void insert(node *root, node *temp);
    void search(node *root, int key);
    void inorder(node *root);
    void mirror(node *root);
    int height(node *root);
    void min(node *root);
};
void binarytree :: create(){
    char ch;
    do{
        temp = new node;
        cout<<"Enter the data: ";
        cin>>temp->data;
        temp->left=temp->right=NULL;
        if(root==NULL){
            root = temp;
        }
        else{
            insert(root,temp);
        }
        cout<<"Do you want to insert more values(y/n): ";
        cin>>ch;
        count++;
        cout<<endl;
    }while(ch == 'y');
    cout<<"Total number of nodes are: "<<count<<endl;
}
void binarytree :: insert(node *root, node *temp){
    if(temp->data > root->data){
        if(root->right == NULL){
            root->right = temp;
        }
        else{
            insert(root->right,temp);
        }
    }
    else{
        if(temp->data < root->data){
            if(root->left == NULL){
                root->left = temp;
            }
            else{
                insert(root->left,temp);
            }
        }
    }
}
void binarytree :: search(node *root, int key){
    int flag = 0;
    cout<<"Enter the key to be searched: ";
    cin>>key;
    temp = root;
    while(temp!=NULL){
        if(key == temp->data){
            cout<<"Key Found"<<endl;
            flag = 1;
            break;
        }
        node *parent = temp;
        if(key> parent->data){
            temp = temp->right;
        }
        else{
            temp = temp->left;
        }
    }
    if(flag == 0){
            cout<<"Key not found."<<endl;
    }
}
void binarytree :: inorder(node *root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->data;
        inorder(root->right);
        count++;
    }
}
void binarytree :: mirror(node *root){
    if(root!= NULL){
        mirror(root->left);
        mirror(root->right);
        temp = root->left;
        root->left= root->right;
        root->right = temp;
    }
}
void binarytree :: min(node *root){
    temp = root;
    while(root->left != NULL){
        temp=temp->left;
    }
    cout<<"The minimum element is: "<<temp->data<<endl;
}
int binarytree :: height(node*root){
    if(root==NULL || (root->left==NULL && root->right==NULL)){
        return 0;
    }
    int hleft = height(root->left);
    int hright = height(root->right);
    if(hleft > hright){
        return(1+hleft);
    }
    else{
        return (1+hright);
    }
}
int main() {
    binarytree bt;
    int ch;
    char ans;
    do {
        cout << "Enter your choice:" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Number of nodes longest in path from root" << endl;
        cout << "3. Minimum" << endl;
        cout << "4. Mirror" << endl;
        cout << "5. Search" << endl;
        cin >> ch;
        switch (ch) {
            case 1:
                bt.create();
                break;
            case 2:
                cout << "Number of nodes in longest path: " << (1 + bt.height(bt.root)) << endl;
                break;
            case 3:
                bt.min(bt.root);
                break;
            case 4:
                bt.mirror(bt.root);
                cout << "The mirror of the tree is: ";
                bt.inorder(bt.root);
                cout << endl;
                break;
            case 5:
                bt.search(bt.root, bt.key);
                break;
        }
        cout << "Do you want to continue (y/n): ";
        cin >> ans;
    } while (ans == 'y');
    return 0;
}