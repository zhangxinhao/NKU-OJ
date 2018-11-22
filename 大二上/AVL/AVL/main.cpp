//
//  main.cpp
//  AVL
//
//  Created by apple on 2017/12/8.
//  Copyright © 2017年 apple. All rights reserved.
//

#include <queue>
#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;
fstream input("/Users/apple/Documents/random.txt");
struct TreeNode
{
    int val;
    int height;
    TreeNode *left;
    TreeNode *right;
};

int GetHeight(TreeNode *treeNode)
{
    return treeNode == NULL ? -1 : treeNode->height;
    
    //if use the code below,there is no need to use member "height"
    //and there is no need to update height anymore
    //but it may cost much time as it uses recursion to get the height every time
    /*if(treeNode == NULL)
     return -1;
     return 1 + max(GetHeight(treeNode->left), GetHeight(treeNode->right));*/
}

//case 1,add "1" to 3,2(left-left)
/*
 3         2
 2    ->   1   3
 1
 */
void RotateWithLeftChild(TreeNode *&treeNode)
{
    TreeNode *p = treeNode->left;
    treeNode->left = p->right;
    p->right = treeNode;
    treeNode->height = max(GetHeight(treeNode->left), GetHeight(treeNode->right)) + 1;
    p->height =  max(GetHeight(p->left), treeNode->height) + 1;
    treeNode = p;
}

//case 4,add "3" to 1,2(right-right)
/*
 1             2
 2    ->   1   3
 3
 */
void RotateWithRightChild(TreeNode *&treeNode)
{
    TreeNode *p = treeNode->right;
    treeNode->right = p->left;
    p->left = treeNode;
    treeNode->height = max(GetHeight(treeNode->left), GetHeight(treeNode->right)) + 1;
    p->height = max(GetHeight(p->right), treeNode->height) + 1;
    treeNode = p;
}

//case 2,add "2" to 3,1(left-right)
/*
 3         3      2
 1    ->   2   ->  1 3
 2     1
 */
void DoubleWithLeftChild(TreeNode *&treeNode)
{
    RotateWithRightChild(treeNode->left);
    RotateWithLeftChild(treeNode);
}

//case 3,add "2" to 1,3(right-left)
/*
 1         1          2
 3    ->   2   ->  1 3
 2             3
 */
void DoubleWithRightChild(TreeNode *&treeNode)
{
    RotateWithLeftChild(treeNode->right);
    RotateWithRightChild(treeNode);
}

TreeNode *FindMin(TreeNode *treeNode)
{
    if(treeNode == NULL)
        return NULL;
    else if(treeNode->left == NULL)
        return treeNode;
    else
        return FindMin(treeNode->left);
}

TreeNode *FindMax(TreeNode *treeNode)
{
    if (treeNode == NULL)
        return NULL;
    else if (treeNode->right == NULL)
        return treeNode;
    else
        return FindMax(treeNode->right);
}

void avl_inssert(TreeNode *&treeNode, int data)
{
    if(treeNode == NULL)
    {
        treeNode = new TreeNode;
        treeNode->left = NULL;
        treeNode->right = NULL;
        treeNode->val = data;
    }
    
    else if (treeNode->val > data)//go to left subtree
    {
        avl_inssert(treeNode->left,data);
        if (GetHeight(treeNode->left) - GetHeight(treeNode->right) == 2)
        {
            if(data < treeNode->left->val) //left-left
                RotateWithLeftChild(treeNode);
            else                            //left-right
                DoubleWithLeftChild(treeNode);
        }
    }
    
    else if (treeNode->val < data) //go to right subtree
    {
        avl_inssert(treeNode->right,data);
        if(GetHeight(treeNode->right) - GetHeight(treeNode->left) == 2)
        {
            if (data > treeNode->right->val)
                RotateWithRightChild(treeNode);
            else
                DoubleWithRightChild(treeNode);
        }
    }
    
    else
        ;//duplicate, do nothing
    
    //it's impossible that treeNode is NULL here
    //so update it's height is safe
    treeNode->height = max(GetHeight(treeNode->left),GetHeight(treeNode->right)) + 1;
}

void avl_delete(TreeNode *&treeNode, int data)
{
    if(treeNode == NULL)//not found
        return;
    if (treeNode->val > data) //go to left subtree
    {
        avl_delete(treeNode->left,data);
        if (GetHeight(treeNode->right) - GetHeight(treeNode->left) == 2)
        {
            if(treeNode->right->right != NULL)
                RotateWithRightChild(treeNode);
            else
                DoubleWithRightChild(treeNode);
        }
    }
    else if (treeNode->val < data) //go to right subtree
    {
        avl_delete(treeNode->right,data);
        if (GetHeight(treeNode->left) - GetHeight(treeNode->right) == 2)
        {
            if (treeNode->left->left != NULL)
                RotateWithLeftChild(treeNode);
            else
                DoubleWithLeftChild(treeNode);
        }
    }
    else if(treeNode->left != NULL && treeNode->right != NULL)//found,has two children
    {
        treeNode->val = FindMin(treeNode->right)->val;
        avl_delete(treeNode->right,treeNode->val);//not "data"!!
        if (GetHeight(treeNode->left) - GetHeight(treeNode->right) == 2)
        {
            if(treeNode->left->left != NULL)
                RotateWithLeftChild(treeNode);
            else
                DoubleWithLeftChild(treeNode);
        }
    }
    else // found,has one or no child
    {
        TreeNode *tmp = treeNode;
        treeNode = (treeNode->left != NULL) ? treeNode->left : treeNode->right;
        delete tmp;
        tmp = NULL;
    }
    
    //if treeNode is NULL,treeNode->height will cause error
    //so if treeNode is a leaf, there is no need to update its height
    if(treeNode != NULL)
        treeNode->height = max(GetHeight(treeNode->left), GetHeight(treeNode->right)) + 1;
}

void LevelOrderTraverse(TreeNode *root)
{
    if(root == NULL) return;
    
    queue<TreeNode*> Q;
    Q.push(root);
    while(!Q.empty())
    {
        TreeNode *p = Q.front();
        if (p->left != NULL)
            Q.push(p->left);
        if (p->right != NULL)
            Q.push(p->right);
        cout << p->val <<"("<<p->height<<") ";
        Q.pop();
    }
    cout << "\n";
}

void PreOrderTraverse(TreeNode *treeNode)
{
    if (treeNode != NULL)
    {
        cout << treeNode->val <<"("<<treeNode->height<<") ";
        PreOrderTraverse(treeNode->left);
        PreOrderTraverse(treeNode->right);
    }
}

void InOrderTraverse(TreeNode *treeNode)
{
    if (treeNode != NULL)
    {
        InOrderTraverse(treeNode->left);
        cout << treeNode->val <<"("<<treeNode->height<<") ";
        InOrderTraverse(treeNode->right);
    }
}

void PostOrderTraverse(TreeNode *treeNode)
{
    if (treeNode != NULL)
    {
        PostOrderTraverse(treeNode->left);
        PostOrderTraverse(treeNode->right);
        cout << treeNode->val <<"("<<treeNode->height<<") ";
    }
}

void MakeEmpty(TreeNode *&treeNode)
{
    if (treeNode != NULL)
    {
        MakeEmpty(treeNode->left);
        MakeEmpty(treeNode->right);
        delete treeNode;
    }
    treeNode = NULL;
}

void BuildAVLTree(TreeNode *&root,int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        avl_inssert(root,a[i]);
    }
}

int main(void)
{
    
    int arr[100000];
    for (int i = 0; i < 100000; i++) {
        input >> arr[i];
    }
    
    clock_t start, end;
    
    cout << "inorder_order" << endl;
    for (int j = 1000; j <= 100000; j += 3000) {
        start = clock();
        
        TreeNode* T = NULL;
        for(int i = 0;i < j;i++)
        {
            avl_inssert(T,i);
        }
        for (int i = 0; i < j; i++) {
            avl_delete(T,i);
        }
        
        end = clock();
        //cout << j << " ";
        cout << (double)(end - start) / CLOCKS_PER_SEC << endl;
        
    }
    
    cout << "inorder_reverse" << endl;
    for (int j = 1000; j <= 100000; j += 3000) {
        start = clock();
        
        TreeNode* T = NULL;
        for(int i = 0;i < j;i++)
        {
            avl_inssert(T,i);
        }
        for (int i = 0; i < j; i++) {
            avl_delete(T,j-i);
        }
        
        end = clock();
        //cout << j << " ";
        cout << (double)(end - start) / CLOCKS_PER_SEC << endl;
        
    }
    
    
    cout << "random" << endl;
    for (int j = 1000; j <= 100000; j += 3000) {
        start = clock();
        
        TreeNode* T = NULL;
        for(int i = 0;i < j;i++)
        {
            avl_inssert(T,arr[i]);
        }
        for (int i = 0; i < j; i++) {
            avl_delete(T,arr[i]);
        }
        
        end = clock();
        //cout << j << " ";
        cout << (double)(end - start) / CLOCKS_PER_SEC << endl;
        
    }

    
    
    return 0;
}
