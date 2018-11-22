//
//  main.cpp
//  搜索树：B树
//
//  Created by apple on 2017/12/6.
//  Copyright © 2017年 apple. All rights reserved.
//

#include <iostream>
#include <deque>
#define T 2
#include <fstream>
#include <ctime>
using namespace std;
fstream input("/Users/apple/Documents/random.txt");

typedef struct BTnode{
    int keyNum;         /* number of keys */
    int* keyValue;      /* array storing the keys */
    BTnode** children;  /* array storing the pointers to child nodes */
    bool leaf;          /* true when the node is a leaf, otherwise false */
    BTnode(bool il=true, int n=0):leaf(il), keyNum(n){}
}BTnode, *PBTnode;

class Btree{
private:
    PBTnode root;
    void DELETE_TREE(PBTnode pNode);
    PBTnode ALLOACT_NODE();
    void B_TREE_SPLIT_CHILD(PBTnode x, int i);
    void B_TREE_INSERT_NONFULL(PBTnode x, int k);
    void DELETE_NODE(PBTnode &node);
    void B_TREE_MERGE_CHILD(PBTnode x, int index);
    int B_TREE_FIND_PREDECESSOR(PBTnode x); // 前驱关键字
    int B_TREE_FIND_SUCCESSOR(PBTnode x);   // 后继关键字
    void B_TREE_DELETE_RECURSIVE(PBTnode x, int k);
    
public:
    Btree(){
        root = NULL;
    }
    ~Btree(){
        DELETE_TREE(root);
    }
    PBTnode getRoot(){
        return root;
    }
    
    PBTnode B_TREE_SEARCH(PBTnode x, int k, int& index);
    bool KEY_IS_EXIST(int key);
    void PRINT_TREE(PBTnode x);
    void B_TREE_INSERT(int k);
    void B_TREE_DELETE(int k);
};

int main(){
    Btree tree1;
    tree1.B_TREE_INSERT(1);
    tree1.B_TREE_INSERT(2);
    tree1.B_TREE_INSERT(3);
    tree1.B_TREE_INSERT(4);
    tree1.B_TREE_INSERT(5);
    tree1.B_TREE_INSERT(6);
    tree1.B_TREE_INSERT(7);
    tree1.B_TREE_INSERT(8);
    tree1.B_TREE_INSERT(9);
    tree1.B_TREE_INSERT(10);
    std::cout << "build tree(1~10): " << std::endl;
    tree1.PRINT_TREE(tree1.getRoot());
    std::cout << "delete key 2(test case 2): " << std::endl;
    tree1.B_TREE_DELETE(2);
    tree1.PRINT_TREE(tree1.getRoot());
    std::cout << "delete key 4(test case 3): " << std::endl;
    tree1.B_TREE_DELETE(4);
    tree1.PRINT_TREE(tree1.getRoot());
    std::cout << "delete key 10(test case 1): " << std::endl;
    tree1.B_TREE_DELETE(10);
    tree1.PRINT_TREE(tree1.getRoot());
    
    
    
    
    
    
    int arr[100000];
    for (int i = 0; i < 100000; i++) {
        input >> arr[i];
    }
    
    clock_t start, end;
    
    cout << "inorder_order" << endl;
    for (int j = 1000; j <= 100000; j += 3000) {
        start = clock();
        
        Btree tree;
        for(int i = 0;i < j;i++)
        {
            tree.B_TREE_INSERT(i);
            //avl_inssert(T,i);
        }
        for (int i = 0; i < j; i++) {
            tree.B_TREE_DELETE(i);
            //avl_delete(T,i);
        }
        
        end = clock();
        cout << j << " ";
        cout << (double)(end - start) / CLOCKS_PER_SEC << endl;
        
    }
    
    cout << "inorder_reverse" << endl;
    for (int j = 1000; j <= 100000; j += 3000) {
        start = clock();
        
        Btree tree;
        for(int i = 0;i < j;i++)
        {
            tree.B_TREE_INSERT(i);
        }
        for (int i = 0; i < j; i++) {
            tree.B_TREE_DELETE(j-i);

        }
        
        end = clock();
        cout << j << " ";
        cout << (double)(end - start) / CLOCKS_PER_SEC << endl;
        
    }
    
    
    cout << "random" << endl;
    for (int j = 1000; j <= 100000; j += 3000) {
        start = clock();
        
        Btree tree;
        for(int i = 0;i < j;i++)
        {
            tree.B_TREE_INSERT(arr[i]);
        }
        for (int i = 0; i < j; i++) {
            tree.B_TREE_DELETE(arr[i]);
        }
        
        end = clock();
        cout << j << " ";
        cout << (double)(end - start) / CLOCKS_PER_SEC << endl;
        
    }
    
    
    
    
    return 0;
}

void Btree::DELETE_TREE(PBTnode pNode){
    if(pNode == NULL) return;
    else{
        if(!pNode->leaf){
            for(int i=0; i<=pNode->keyNum; i++){
                DELETE_TREE(pNode->children[i]);
            }
        }
        delete pNode;
        pNode = NULL;
    }
}

PBTnode Btree::ALLOACT_NODE(){
    PBTnode newNode = new BTnode();
    newNode->keyValue = new int[2*T-1];
    newNode->children = new PBTnode[2*T];
    for(int i=0; i<2*T; i++)
        newNode->children[i] = NULL;
    
    return newNode;
}

/*
 /* 找到对应的节点返回，并且通过index传引用得到在节点x中的位置
 */
PBTnode Btree::B_TREE_SEARCH(PBTnode x, int k, int& index){
    if(x == NULL) return NULL;
    else{
        int i=0;
        while(i<x->keyNum && k>x->keyValue[i]){
            i++;
        }
        if(i<x->keyNum && k==x->keyValue[i]){
            index = i;
            return x;
        }
        else{
            if(x->leaf)
                return NULL;
            else
                return B_TREE_SEARCH(x->children[i], k, index);
        }
    }
}

bool Btree::KEY_IS_EXIST(int key){
    int index;
    if(B_TREE_SEARCH(root, key, index)==NULL) return false;
    return true;
}

void Btree::PRINT_TREE(PBTnode x){
    if(NULL == x) return;
    
    // 输出当前节点的所有关键字
    std::cout << "[";
    for(int i=0; i<x->keyNum; i++)
        std::cout << " " << x->keyValue[i];
    std::cout << " ]";
    
    // 递归输出所有子树
    for(int i=0; i<=x->keyNum; i++)
        PRINT_TREE(x->children[i]);
    
    std::cout << std::endl;
}


void Btree::B_TREE_SPLIT_CHILD(PBTnode x, int index){
    PBTnode z = ALLOACT_NODE();
    PBTnode y = x->children[index];
    z->leaf = y->leaf;
    z->keyNum = T-1;
    for(int i=0; i<T-1; i++){ // 截取后半段关键字作为新子节点的关键字
        z->keyValue[i] = y->keyValue[T+i];
    }
    if(!y->leaf){
        for(int i=0; i<T; i++){
            z->children[i] = y->children[T+i];
        }
    }
    
    y->keyNum = T-1; // 更新原子树的关键字个数
    // 将父节点x中，位于index后的所有关键字和子树后移一位
    for(int i=x->keyNum; i>index; i--){
        x->children[i+1] = x->children[i];
        x->keyValue[i] = x->keyValue[i-1];
    }
    x->keyNum++;
    x->children[index+1] = z; // 存储新子树
    x->keyValue[index] = y->keyValue[T-1]; // 将节点中间值提升到父节点
}

void Btree::B_TREE_INSERT_NONFULL(PBTnode x, int k){
    int i=x->keyNum-1;
    if(x->leaf){
        for(; i>=0&&k<x->keyValue[i]; i--){
            x->keyValue[i+1] = x->keyValue[i];
        }
        i++;
        (x->keyNum)++;
        x->keyValue[i] = k;
    }
    else{
        while(i>=0&&k<x->keyValue[i])
            i--;
        i++;
        if(x->children[i]->keyNum == 2*T-1){
            B_TREE_SPLIT_CHILD(x, i);
            if(k>x->keyValue[i]) i++;
        }
        B_TREE_INSERT_NONFULL(x->children[i], k);
    }
}

void Btree::B_TREE_INSERT(int k){
    if(!KEY_IS_EXIST(k)){
        if(root == NULL){ // 假如为空树
            root = ALLOACT_NODE();
        }
        if(root->keyNum == 2*T-1){ // 根节点满，生成新根，分裂根节点
            PBTnode newRoot = ALLOACT_NODE();
            newRoot->children[0] = root;
            newRoot->leaf = false;
            B_TREE_SPLIT_CHILD(newRoot, 0);
            root = newRoot; // 更新根节点
        }
        B_TREE_INSERT_NONFULL(root, k);
    }
}

void Btree::DELETE_NODE(PBTnode &node){
    if(node != NULL){
        delete node;
        node = NULL;
    }
}

void Btree::B_TREE_MERGE_CHILD(PBTnode x, int index){
    PBTnode xchild1 = x->children[index];
    PBTnode xchild2 = x->children[index+1];
    xchild1->keyValue[T-1] = x->keyValue[index];
    for(int j=0; j<T-1; j++)
        xchild1->keyValue[T+j] = xchild2->keyValue[j];
    if(!xchild1->leaf){ // 假如节点不是叶节点，则需要移动孩子
        for(int j=0; j<T; j++){
            xchild1->children[j+T] = xchild2->children[j];
        }
    }
    xchild1->keyNum = 2*T-1;
    
    // 恢复父节点：删除了一个关键字，index之后的关键字及指针需要前移
    x->keyNum--;
    for(int j=index; j<=x->keyNum; j++){
        x->keyValue[j] = x->keyValue[j+1];
        x->children[j+1] = x->children[j+2];
    }
    DELETE_NODE(xchild2);
    if(x->keyNum == 0) DELETE_NODE(x);
}

int Btree::B_TREE_FIND_PREDECESSOR(PBTnode x){
    while(!x->leaf){
        x = x->children[x->keyNum];
    }
    return x->keyValue[x->keyNum-1];
}

int Btree::B_TREE_FIND_SUCCESSOR(PBTnode x){
    while(!x->leaf){
        x = x->children[0];
    }
    return x->keyValue[0];
}

void Btree::B_TREE_DELETE_RECURSIVE(PBTnode x, int k){
    int index=0;
    while(index<x->keyNum && k>x->keyValue[index])
        index++;
    if(k==x->keyValue[index]){ // 关键字在节点x
        if(x->leaf){ // case 1
            for(int j=index; j<x->keyNum; j++)
                x->keyValue[j] = x->keyValue[j+1];
            x->keyNum--;
            std::cout << "aaa" << std::endl;
            return;
        }
        else{ // 节点x为内部节点
            PBTnode y = x->children[index]; // 节点x中前于k的子节点
            PBTnode z = x->children[index+1]; // 节点x中后于k的子节点
            
            if(y->keyNum >= T){ // case 2a: 节点y至少包含T个关键字
                int prevKey = B_TREE_FIND_PREDECESSOR(y); // 获得key的前驱关键字
                B_TREE_DELETE_RECURSIVE(y, prevKey);
                x->keyValue[index] = prevKey;
                return;
            }
            else if(z->keyNum >= T){ // case 2b: 节点z至少包含T个关键字
                int nextKey = B_TREE_FIND_SUCCESSOR(z); // 获得key的后驱关键字
                B_TREE_DELETE_RECURSIVE(z, nextKey);
                x->keyValue[index] = nextKey;
                return;
            }
            else{ // case 2c: 节点y和z都只包含T-1个关键字
                B_TREE_MERGE_CHILD(x, index);
                B_TREE_DELETE_RECURSIVE(y, k);
            }
        }
    }
    else{ // 关键字k不在节点x中，则x->children[index]为包含k的子树的根节点
        PBTnode xchild = x->children[index]; // 包含k的子树根节点
        if(xchild->keyNum == T-1){ // 只有T-1个关键字
            PBTnode pLeft = index>0? x->children[index-1]:NULL; // 左兄弟节点
            PBTnode pRight = index<x->keyNum? x->children[index+1]:NULL; // 右兄弟节点
            if(pLeft && pLeft->keyNum>=T){ // case 3a: 左兄弟节点中的关键字数不少于T
                // 父节点中i-1个关键字下降至合并节点
                for(int j=xchild->keyNum; j>0; j--){
                    xchild->keyValue[j] = xchild->keyValue[j-1];
                }
                xchild->keyValue[0] = x->keyValue[index-1];
                if(!pLeft->leaf){
                    // 将左兄弟节点中合适的孩子指针移植到xchild
                    for(int j=xchild->keyNum+1; j>0; j--){
                        xchild->children[j] = xchild->children[j-1];
                    }
                    xchild->children[0] = pLeft->children[pLeft->keyNum];
                }
                xchild->keyNum++;
                x->keyValue[index] = pLeft->keyValue[pLeft->keyNum-1]; // 左兄弟节点中的最大关键字上升到其父节点中
                pLeft->keyNum--; 
            }
            else if(pRight && pRight->keyNum>=T){ // case 3a: 右兄弟节点中的关键字数不少于T	
                // 父节点中i个关键字下降至合并节点 
                xchild->keyValue[xchild->keyNum] = x->keyValue[index];
                xchild->keyNum++;
                x->keyValue[index] = pRight->keyValue[0]; // 右兄弟节点中的最小关键字上升至父节点x
                pRight->keyNum--;
                for(int j=0; j<pRight->keyNum; j++){
                    pRight->keyValue[j] = pRight->keyValue[j+1];
                } 
                if(!pRight->leaf){
                    // 将右兄弟节点中合适的孩子指针移植到xchild 
                    xchild->children[xchild->keyNum] = pRight->children[0];
                    for(int j=0; j<=pRight->keyNum; j++){
                        pRight->children[j] = pRight->children[j+1];
                    } 
                }
            } 
            else if(pLeft){ // 左兄弟节点非空：与左兄弟合并 
                B_TREE_MERGE_CHILD(x, index-1);
                xchild = pLeft;
            }
            else if(pRight){ // 右兄弟节点非空：与右兄弟合并 
                B_TREE_MERGE_CHILD(x, index-1);
            }
        } 	
        B_TREE_DELETE_RECURSIVE(xchild, k); 
    } 
}	

void Btree::B_TREE_DELETE(int k){
    if(KEY_IS_EXIST(k)){
        if(root->keyNum == 1){
            if(root->leaf)
                DELETE_TREE(root);
            else{ // case 3b: 根据插入规则，当父节点只有一个关键字时，只可能有2个孩子
                PBTnode rchild1 = root->children[0];
                PBTnode rchild2 = root->children[1];
                if(rchild1->keyNum == T-1 && rchild2->keyNum == T-1){
                    B_TREE_MERGE_CHILD(root, 0);
                    root = rchild1;
                } 	
            }
        }
        B_TREE_DELETE_RECURSIVE(root, k);
    }
}
