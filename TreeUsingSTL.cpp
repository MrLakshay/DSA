/*Created by Lakshay Goel
  Github Profile link: https://github.com/MrLakshay
  
  
  In this program we create a binary tree and output it in preorder postorder and inorder 
*/
#include<bits/stdc++.h>
using namespace std;
struct Node{
    Node* lchild;
    Node* rchild;
    int data;
};
void Preorder(Node *p) {
    if (p!=nullptr){
        cout << p->data << ", " << flush;
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}
void Postorder(Node *p) {
    if (p!=nullptr){
        Preorder(p->lchild);
        Preorder(p->rchild);
        cout << p->data << ", " << flush;
    }
}
void Inorder(Node *p) {
    if (p!=nullptr){
        Preorder(p->lchild);
        cout << p->data << ", " ;
        Preorder(p->rchild);
        
    }
}

void Createtree(){
    Node* t;
    Node* root;
    Node* p;
    root = nullptr;
    root = new Node;
    queue <Node*> q;
    cout<<"Enter root data : ";
    int x;
    cin>>x;
    root->data=x;
    root->lchild=nullptr;
    root->rchild=nullptr;
    q.push(root);
    while(!q.empty()){
        p=q.front();
        q.pop();
        cout<<"\nEnter left child of "<<p->data<<" :";
        cin>>x;
        if(x!=-1){
            t=new Node;
            t->data=x;
            t->lchild=nullptr;
            t->rchild=nullptr;
            p->lchild=t;
            q.push(t);
        }
        cout<<"\nEnter right child of "<<p->data<<" :";
        cin>>x;
        if(x!=-1){
            t=new Node;
            t->data=x;
            t->lchild=nullptr;
            t->rchild=nullptr;
            p->rchild=t;
            q.push(t);
        }
    }
    Preorder(root);
    Postorder(root);
    Inorder(root);
}
int main(){
    //Tree tr;
    Createtree();
    //cout << "Preorder: " << flush;
    
    cout << endl;

}
