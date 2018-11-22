//
//  main.cpp
//  搜索树：AVL树
//
//  Created by apple on 2017/12/6.
//  Copyright © 2017年 apple. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;
fstream input("/Users/apple/Documents/random.txt");
struct TreeNode {
    int key;
    int height; //记录以该节点为root的树高度
    TreeNode* left; // left child
    TreeNode* right; // right child
};



// 比较左右子树高度，取最大的
int maxh(int ha, int hb) {
    return ha > hb ? ha : hb;
}

// 计算树的高度
int height(TreeNode* tree) {
    if (NULL == tree) return 0;
    return tree->height;
}


// single right rotate for LL model
TreeNode* singleRightRotate(TreeNode* aNode) {
    TreeNode* bNode = aNode->left;
    // rebuild relation
    aNode->left = bNode->right;
    bNode->right = aNode;
    // adjust the height
    aNode->height = maxh(height(aNode->right), height(aNode->left)) + 1;
    bNode->height = maxh(height(bNode->right), height(bNode->left)) + 1;
    return bNode;
}

// single left rotate for RR model
TreeNode* singleLeftRotate(TreeNode* aNode) {
    TreeNode* bNode = aNode->right;
    // rebuild relation
    aNode->right = bNode->left;
    bNode->left = aNode;
    // adjust height
    aNode->height = maxh(height(aNode->right), height(aNode->left)) + 1;
    bNode->height = maxh(height(bNode->right), height(bNode->left)) + 1;
    return bNode;
}

// double rotate for LR model
// left rotate first and then right rotate
TreeNode* leftRightRotate(TreeNode* aNode) {
    aNode->left = singleLeftRotate(aNode->left);
    return singleRightRotate(aNode);
}

// double rotate for RL model
// right rotate first and then left rotate
TreeNode* rightLeftRotate(TreeNode* aNode) {
    aNode->right = singleRightRotate(aNode->right);
    return singleLeftRotate(aNode);
}

// insert a key to AVL tree.
TreeNode* avl_inssert(TreeNode* &tree, int key) {
    if (NULL == tree) {
        tree = (TreeNode*) malloc(sizeof(TreeNode));
        tree->key = key;
        tree->height = 1;
        tree->left = tree->right = NULL;
    } else if (key > tree->key) { // insert into the right subtree
        tree->right = avl_inssert(tree->right, key);
        int balanceFactor = height(tree->right) - height(tree->left);
        if (balanceFactor == 2) {
            if (key > tree->right->key) { // RR 型 , 右侧单旋
                tree = singleLeftRotate(tree);
            } else { // RL型 , 右侧双旋
                tree = rightLeftRotate(tree);
            }
        }
    } else if (key < tree->key) { // insert into the left subtree
        tree->left = avl_inssert(tree->left, key);
        int balanceFactor = height(tree->left) - height(tree->right);
        if (balanceFactor == 2) {
            if (key < tree->left->key) { // LL型 , 左侧单旋
                tree = singleRightRotate(tree);
            } else { // LR型 ， 左侧双旋
                tree = rightLeftRotate(tree);
            }
        }
    } else { // if the key is already exists, nothing to do....
    }
    // 重新计算树的高度
    tree->height = maxh(height(tree->left), height(tree->right)) + 1;
    
    return tree;
}

// delete the given key from AVL tree.
TreeNode* avl_delete(TreeNode* &tree, int key) {
    if (NULL == tree) {
        return NULL;
    }
    // delete the node with the given key
    if (key > tree->key) { // key exists in the right subtree
        tree->right = avl_delete(tree->right, key);
    } else if (key < tree->key) { // key exists in the left subtree
        tree->left = avl_delete(tree->left, key);
    } else {
        if (NULL != tree->left) { // when left is not NULL
            // find max node if left tree
            TreeNode* dn = NULL;
            for (dn = tree->left; NULL != dn->right; dn = dn->right) {
            }
            // change the value
            tree->key = dn->key;
            // delete the max node
            tree->left = avl_delete(tree->left, dn->key);
        } else if (NULL != tree->right) { // when the right tree is not NULL
            // find the minimal node
            TreeNode* dn = NULL;
            for (dn = tree->right; NULL != dn->left; dn = dn->left) {
            }
            // change the value
            tree->key = dn->key;
            // delete the minimal node
            tree->right = avl_delete(tree->right, dn->key);
        } else {            // when the node has no child
            free(tree);
            // the tree is Empty now, no need to do any operation
            return NULL;
        }
    }
    // adjust the tree to balance state after deletion
    if (height(tree->left) - height(tree->right) == 2) { // when the left subtree is too high
        if (height(tree->left->right) - height(tree->left->left) == 1) { // LR model
            tree = leftRightRotate(tree);
        } else { // LL model
            tree = singleRightRotate(tree);
        }
    } else if (height(tree->left) - height(tree->right) == -2) { // when the right subtree is too high
        if (height(tree->right->left) - height(tree->right->right) == 1) { // RL model
            tree = rightLeftRotate(tree);
        } else { // RR model
            tree = singleLeftRotate(tree);
        }
    } else {
        // the tree is already balanced, nothing to do ...
    }
    
    // recalculate the height of the tree.
    tree->height = maxh(height(tree->right), height(tree->left)) + 1;
    
    return tree;
}



int main(int argc, const char * argv[]) {
    
    int arr[100000];
    for (int i = 0; i < 100000; i++) {
        input >> arr[i];
    }
    
    clock_t start, end;
    
    cout << "inorder_order" << endl;
    for (int j = 1000; j <= 100000; j += 3000) {
        start = clock();
        
        TreeNode* T=new TreeNode;
        T = NULL;
        for(int i = 0;i < j;i++)
        {
            avl_inssert(T,i);
        }
        for (int i = 0; i < j; i++) {
            avl_delete(T,i);
        }
        
        end = clock();
        cout << j << " ";
        cout << (double)(end - start) / CLOCKS_PER_SEC << endl;
        
    }
    
    cout << "inorder_reverse" << endl;
    for (int j = 1000; j <= 100000; j += 3000) {
        start = clock();
        
        TreeNode* T=new TreeNode;
        T = NULL;
        for(int i = 0;i < j;i++)
        {
            avl_inssert(T,i);
        }
        for (int i = 0; i < j; i++) {
            avl_delete(T,j-i);
        }
        
        end = clock();
        cout << j << " ";
        cout << (double)(end - start) / CLOCKS_PER_SEC << endl;
        
    }
    
    
    cout << "random" << endl;
    for (int j = 1000; j <= 100000; j += 3000) {
        start = clock();
        
        TreeNode* T=new TreeNode;
        T = NULL;
        for(int i = 0;i < j;i++)
        {
            avl_inssert(T,arr[i]);
        }
        for (int i = 0; i < j; i++) {
            avl_delete(T,arr[i]);
        }
        
        end = clock();
        cout << j << " ";
        cout << (double)(end - start) / CLOCKS_PER_SEC << endl;
        
    }
    

    
    
    return 0;
}






