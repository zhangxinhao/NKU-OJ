//
//  main.cpp
//  搜索树：二叉搜索树
//
//  Created by apple on 2017/12/5.
//  Copyright © 2017年 apple. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
#include <fstream>
#include <ctime>
using namespace std;
fstream input("/Users/apple/Documents/random.txt");
ofstream output("/Users/apple/Documents/1.txt");
class TreeNode{
public:
    int key;
    TreeNode* left;
    TreeNode* right;
    TreeNode* p;//parents
    
    TreeNode();
    TreeNode(int val);
    
};
TreeNode::TreeNode()
{
    key=0;
    left=right=p=NULL;
}
TreeNode::TreeNode(int val)
{
    key=val;
    left=right=p=NULL;
}
void inorder_tree_walk(TreeNode* x)
{
    if(x!=NULL)
    {
        inorder_tree_walk(x->left);
        output<<x->key<<endl;
        inorder_tree_walk(x->right);
    }else
        return;
}
void preorder_tree_walk(TreeNode*x)
{
    if(x)
    {
        output<<x->key<<endl;
        preorder_tree_walk(x->left);
        preorder_tree_walk(x->right);
    }
}
TreeNode* tree_search(TreeNode* x, int k)
{
    if(x==NULL||k==x->key)
        return x;
    if(k<x->key)
        return tree_search(x->left,k);
        else return tree_search(x->right,k);
}
TreeNode* tree_minmum(TreeNode* x)
{
    while(x->left!=NULL)
        x=x->left;
    return x;
}
TreeNode* tree_maxmum(TreeNode* x)
{
    while(x->right!=NULL)
        x=x->right;
    return x;
}
TreeNode* tree_successor(TreeNode* x)//大于x.key的最小关键字的节点为后继
{
    if(x->right)
        return tree_minmum(x->right);
    TreeNode* y=x->p;
    while(y&& x==y->right)
    {
        x=y;
        y=y->p;
    }
    return y;
}
TreeNode* tree_predecessor(TreeNode* x)//小于x.key的最大关键字的节点为前驱
{
    if(x->left)
        return tree_maxmum(x->left);
    TreeNode* y=x->p;
    while(y&& x==y->left)
    {
        x=y;
        y=y->p;
    }
    return y;
}
//插入节点
void tree_insert(TreeNode* T, TreeNode* z) //T是现在的BST的树根
{
    TreeNode * y,*x=T;
    while(x)
    {
        y=x;
        if(z->key<x->key)
            x=x->left;
        else x=x->right;
    }
    z->p=y;
    if(!y)
        T=z;//T是颗空树
    else if(z->key<y->key)
        y->left=z;
    else y->right=z;
    //   return T;
}
//用一颗子树代v替另一个子树u
void transplant(TreeNode* T, TreeNode* u,TreeNode* v)
{
    if(u->p==NULL)
        T=v;
    else if(u==u->p->left)
        u->p->left=v;
    else u->p->right=v;
    if(v)
        v->p=u->p;
}
//删除节点
void tree_delete(TreeNode* T, TreeNode* z)
{
    if(!z->left)
        transplant(T,z,z->right);
    else if(!z->right)
        transplant(T,z,z->left);
    else {
        TreeNode* y=tree_minmum(z->right);
        if(y->p!=z)
        {
            transplant(T,y,y->right);
            y->right=z->right;
            y->right->p=y;
        }
        transplant(T,z,y);
        y->left=z->left;
        y->left->p=y;
    }
}
int main(){
    int arr[100000];
    for (int i = 0; i < 100000; i++) {
        input >> arr[i];
    }
    
    clock_t start, end;
    
    cout << "inorder_order" << endl;
    for (int j = 1000; j <= 100000; j += 3000) {
        start = clock();
        
        TreeNode* T=new TreeNode(0);
        for(int i = 1;i < j;i++)
        {
            TreeNode* z=new TreeNode(i);
            tree_insert(T,z);
        }
        for (int i = 0; i < j; i++) {
            
            TreeNode* z=new TreeNode(i);
            tree_delete(T,z);
        }
        
        end = clock();
        //cout << j << " ";
        cout << (double)(end - start) / CLOCKS_PER_SEC << endl;
        
    }

    cout << "inorder_reverse" << endl;
    for (int j = 1000; j <= 100000; j += 3000) {
        start = clock();
        
        TreeNode* T=new TreeNode(0);
        for(int i = 1;i < j;i++)
        {
            TreeNode* z=new TreeNode(i);
            tree_insert(T,z);
        }
        for (int i = 0; i < j; i++) {
            
            TreeNode* z=new TreeNode(j-i);
            tree_delete(T,z);
        }
        
        end = clock();
        //cout << j << " ";
        cout << (double)(end - start) / CLOCKS_PER_SEC << endl;
        
    }

    
    cout << "random" << endl;
    for (int j = 1000; j <= 100000; j += 3000) {
        start = clock();
        
        TreeNode* T=new TreeNode(arr[0]);
        for(int i = 1;i < j;i++)
        {
            TreeNode* z=new TreeNode(arr[i]);
            tree_insert(T,z);
        }
        for (int i = 0; i < j; i++) {
            
            TreeNode* z=new TreeNode(arr[i]);
            tree_delete(T,z);
        }
        
        end = clock();
        //cout << j << " ";
        cout << (double)(end - start) / CLOCKS_PER_SEC << endl;

    }
    
    
}




