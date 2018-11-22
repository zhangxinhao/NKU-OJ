//
//  rbt.hpp
//  rbtree
//
//  Created by apple on 2017/12/28.
//  Copyright © 2017年 apple. All rights reserved.
//


#pragma once
/**
 * C++ ”Ô—‘: ∫Ï∫⁄ ˜
 *
 * @author skywang
 * @date 2013/11/07
 */

#ifndef _RED_BLACK_TREE_HPP_
#define _RED_BLACK_TREE_HPP_

#include <iomanip>
#include <iostream>
using namespace std;

enum RBTColor { RED, BLACK };

template <class T>
class RBTNode {
public:
    RBTColor color;    // —’…´
    T key;            // πÿº¸◊÷(º¸÷µ)
    RBTNode *left;    // ◊Û∫¢◊”
    RBTNode *right;    // ”“∫¢◊”
    RBTNode *parent; // ∏∏Ω·µ„
    
    RBTNode(T value, RBTColor c, RBTNode *p, RBTNode *l, RBTNode *r) :
    key(value), color(c), parent(), left(l), right(r) {}
};

template <class T>
class RBTree {
private:
    RBTNode<T> *mRoot;    // ∏˘Ω·µ„
    
public:
    RBTree();
    ~RBTree();
    
    // «∞–Ú±È¿˙"∫Ï∫⁄ ˜"
    void preOrder();
    // ÷––Ú±È¿˙"∫Ï∫⁄ ˜"
    void inOrder();
    // ∫Û–Ú±È¿˙"∫Ï∫⁄ ˜"
    void postOrder();
    
    // (µ›πÈ µœ÷)≤È’“"∫Ï∫⁄ ˜"÷–º¸÷µŒ™keyµƒΩ⁄µ„
    RBTNode<T>* search(T key);
    // (∑«µ›πÈ µœ÷)≤È’“"∫Ï∫⁄ ˜"÷–º¸÷µŒ™keyµƒΩ⁄µ„
    RBTNode<T>* iterativeSearch(T key);
    
    // ≤È’“◊Ó–°Ω·µ„£∫∑µªÿ◊Ó–°Ω·µ„µƒº¸÷µ°£
    T minimum();
    // ≤È’“◊Ó¥ÛΩ·µ„£∫∑µªÿ◊Ó¥ÛΩ·µ„µƒº¸÷µ°£
    T maximum();
    
    // ’“Ω·µ„(x)µƒ∫ÛºÃΩ·µ„°£º¥£¨≤È’“"∫Ï∫⁄ ˜÷– ˝æ›÷µ¥Û”⁄∏√Ω·µ„"µƒ"◊Ó–°Ω·µ„"°£
    RBTNode<T>* successor(RBTNode<T> *x);
    // ’“Ω·µ„(x)µƒ«∞«˝Ω·µ„°£º¥£¨≤È’“"∫Ï∫⁄ ˜÷– ˝æ›÷µ–°”⁄∏√Ω·µ„"µƒ"◊Ó¥ÛΩ·µ„"°£
    RBTNode<T>* predecessor(RBTNode<T> *x);
    
    // Ω´Ω·µ„(keyŒ™Ω⁄µ„º¸÷µ)≤Â»ÎµΩ∫Ï∫⁄ ˜÷–
    void insert(T key);
    
    // …æ≥˝Ω·µ„(keyŒ™Ω⁄µ„º¸÷µ)
    void remove(T key);
    
    // œ˙ªŸ∫Ï∫⁄ ˜
    void destroy();
    
    // ¥Ú”°∫Ï∫⁄ ˜
    void print();
private:
    // «∞–Ú±È¿˙"∫Ï∫⁄ ˜"
    void preOrder(RBTNode<T>* tree) const;
    // ÷––Ú±È¿˙"∫Ï∫⁄ ˜"
    void inOrder(RBTNode<T>* tree) const;
    // ∫Û–Ú±È¿˙"∫Ï∫⁄ ˜"
    void postOrder(RBTNode<T>* tree) const;
    
    // (µ›πÈ µœ÷)≤È’“"∫Ï∫⁄ ˜x"÷–º¸÷µŒ™keyµƒΩ⁄µ„
    RBTNode<T>* search(RBTNode<T>* x, T key) const;
    // (∑«µ›πÈ µœ÷)≤È’“"∫Ï∫⁄ ˜x"÷–º¸÷µŒ™keyµƒΩ⁄µ„
    RBTNode<T>* iterativeSearch(RBTNode<T>* x, T key) const;
    
    // ≤È’“◊Ó–°Ω·µ„£∫∑µªÿtreeŒ™∏˘Ω·µ„µƒ∫Ï∫⁄ ˜µƒ◊Ó–°Ω·µ„°£
    RBTNode<T>* minimum(RBTNode<T>* tree);
    // ≤È’“◊Ó¥ÛΩ·µ„£∫∑µªÿtreeŒ™∏˘Ω·µ„µƒ∫Ï∫⁄ ˜µƒ◊Ó¥ÛΩ·µ„°£
    RBTNode<T>* maximum(RBTNode<T>* tree);
    
    // ◊Û–˝
    void leftRotate(RBTNode<T>* &root, RBTNode<T>* x);
    // ”“–˝
    void rightRotate(RBTNode<T>* &root, RBTNode<T>* y);
    // ≤Â»Î∫Ø ˝
    void insert(RBTNode<T>* &root, RBTNode<T>* node);
    // ≤Â»Î–ﬁ’˝∫Ø ˝
    void insertFixUp(RBTNode<T>* &root, RBTNode<T>* node);
    // …æ≥˝∫Ø ˝
    void remove(RBTNode<T>* &root, RBTNode<T> *node);
    // …æ≥˝–ﬁ’˝∫Ø ˝
    void removeFixUp(RBTNode<T>* &root, RBTNode<T> *node, RBTNode<T> *parent);
    
    // œ˙ªŸ∫Ï∫⁄ ˜
    void destroy(RBTNode<T>* &tree);
    
    // ¥Ú”°∫Ï∫⁄ ˜
    void print(RBTNode<T>* tree, T key, int direction);
    
#define rb_parent(r)   ((r)->parent)
#define rb_color(r) ((r)->color)
#define rb_is_red(r)   ((r)->color==RED)
#define rb_is_black(r)  ((r)->color==BLACK)
#define rb_set_black(r)  do { (r)->color = BLACK; } while (0)
#define rb_set_red(r)  do { (r)->color = RED; } while (0)
#define rb_set_parent(r,p)  do { (r)->parent = (p); } while (0)
#define rb_set_color(r,c)  do { (r)->color = (c); } while (0)
};

/*
 * ππ‘Ï∫Ø ˝
 */
template <class T>
RBTree<T>::RBTree() :mRoot(NULL)
{
    mRoot = NULL;
}

/*
 * Œˆππ∫Ø ˝
 */
template <class T>
RBTree<T>::~RBTree()
{
    destroy();
}

/*
 * «∞–Ú±È¿˙"∫Ï∫⁄ ˜"
 */
template <class T>
void RBTree<T>::preOrder(RBTNode<T>* tree) const
{
    if (tree != NULL)
    {
        cout << tree->key << " ";
        preOrder(tree->left);
        preOrder(tree->right);
    }
}

template <class T>
void RBTree<T>::preOrder()
{
    preOrder(mRoot);
}

/*
 * ÷––Ú±È¿˙"∫Ï∫⁄ ˜"
 */
template <class T>
void RBTree<T>::inOrder(RBTNode<T>* tree) const
{
    if (tree != NULL)
    {
        inOrder(tree->left);
        cout << tree->key << " ";
        inOrder(tree->right);
    }
}

template <class T>
void RBTree<T>::inOrder()
{
    inOrder(mRoot);
}

/*
 * ∫Û–Ú±È¿˙"∫Ï∫⁄ ˜"
 */
template <class T>
void RBTree<T>::postOrder(RBTNode<T>* tree) const
{
    if (tree != NULL)
    {
        postOrder(tree->left);
        postOrder(tree->right);
        cout << tree->key << " ";
    }
}

template <class T>
void RBTree<T>::postOrder()
{
    postOrder(mRoot);
}

/*
 * (µ›πÈ µœ÷)≤È’“"∫Ï∫⁄ ˜x"÷–º¸÷µŒ™keyµƒΩ⁄µ„
 */
template <class T>
RBTNode<T>* RBTree<T>::search(RBTNode<T>* x, T key) const
{
    if (x == NULL || x->key == key)
        return x;
    
    if (key < x->key)
        return search(x->left, key);
    else
        return search(x->right, key);
}

template <class T>
RBTNode<T>* RBTree<T>::search(T key)
{
    search(mRoot, key);
}

/*
 * (∑«µ›πÈ µœ÷)≤È’“"∫Ï∫⁄ ˜x"÷–º¸÷µŒ™keyµƒΩ⁄µ„
 */
template <class T>
RBTNode<T>* RBTree<T>::iterativeSearch(RBTNode<T>* x, T key) const
{
    while ((x != NULL) && (x->key != key))
    {
        if (key < x->key)
            x = x->left;
        else
            x = x->right;
    }
    
    return x;
}

template <class T>
RBTNode<T>* RBTree<T>::iterativeSearch(T key)
{
    iterativeSearch(mRoot, key);
}

/*
 * ≤È’“◊Ó–°Ω·µ„£∫∑µªÿtreeŒ™∏˘Ω·µ„µƒ∫Ï∫⁄ ˜µƒ◊Ó–°Ω·µ„°£
 */
template <class T>
RBTNode<T>* RBTree<T>::minimum(RBTNode<T>* tree)
{
    if (tree == NULL)
        return NULL;
    
    while (tree->left != NULL)
        tree = tree->left;
    return tree;
}

template <class T>
T RBTree<T>::minimum()
{
    RBTNode<T> *p = minimum(mRoot);
    if (p != NULL)
        return p->key;
    
    return (T)NULL;
}

/*
 * ≤È’“◊Ó¥ÛΩ·µ„£∫∑µªÿtreeŒ™∏˘Ω·µ„µƒ∫Ï∫⁄ ˜µƒ◊Ó¥ÛΩ·µ„°£
 */
template <class T>
RBTNode<T>* RBTree<T>::maximum(RBTNode<T>* tree)
{
    if (tree == NULL)
        return NULL;
    
    while (tree->right != NULL)
        tree = tree->right;
    return tree;
}

template <class T>
T RBTree<T>::maximum()
{
    RBTNode<T> *p = maximum(mRoot);
    if (p != NULL)
        return p->key;
    
    return (T)NULL;
}

/*
 * ’“Ω·µ„(x)µƒ∫ÛºÃΩ·µ„°£º¥£¨≤È’“"∫Ï∫⁄ ˜÷– ˝æ›÷µ¥Û”⁄∏√Ω·µ„"µƒ"◊Ó–°Ω·µ„"°£
 */
template <class T>
RBTNode<T>* RBTree<T>::successor(RBTNode<T> *x)
{
    // »Áπ˚x¥Ê‘⁄”“∫¢◊”£¨‘Ú"xµƒ∫ÛºÃΩ·µ„"Œ™ "“‘∆‰”“∫¢◊”Œ™∏˘µƒ◊” ˜µƒ◊Ó–°Ω·µ„"°£
    if (x->right != NULL)
        return minimum(x->right);
    
    // »Áπ˚x√ª”–”“∫¢◊”°£‘Úx”–“‘œ¬¡Ω÷÷ø…ƒ‹£∫
    // (01) x «"“ª∏ˆ◊Û∫¢◊”"£¨‘Ú"xµƒ∫ÛºÃΩ·µ„"Œ™ "À¸µƒ∏∏Ω·µ„"°£
    // (02) x «"“ª∏ˆ”“∫¢◊”"£¨‘Ú≤È’“"xµƒ◊ÓµÕµƒ∏∏Ω·µ„£¨≤¢«“∏√∏∏Ω·µ„“™æﬂ”–◊Û∫¢◊”"£¨’“µΩµƒ’‚∏ˆ"◊ÓµÕµƒ∏∏Ω·µ„"æÕ «"xµƒ∫ÛºÃΩ·µ„"°£
    RBTNode<T>* y = x->parent;
    while ((y != NULL) && (x == y->right))
    {
        x = y;
        y = y->parent;
    }
    
    return y;
}

/*
 * ’“Ω·µ„(x)µƒ«∞«˝Ω·µ„°£º¥£¨≤È’“"∫Ï∫⁄ ˜÷– ˝æ›÷µ–°”⁄∏√Ω·µ„"µƒ"◊Ó¥ÛΩ·µ„"°£
 */
template <class T>
RBTNode<T>* RBTree<T>::predecessor(RBTNode<T> *x)
{
    // »Áπ˚x¥Ê‘⁄◊Û∫¢◊”£¨‘Ú"xµƒ«∞«˝Ω·µ„"Œ™ "“‘∆‰◊Û∫¢◊”Œ™∏˘µƒ◊” ˜µƒ◊Ó¥ÛΩ·µ„"°£
    if (x->left != NULL)
        return maximum(x->left);
    
    // »Áπ˚x√ª”–◊Û∫¢◊”°£‘Úx”–“‘œ¬¡Ω÷÷ø…ƒ‹£∫
    // (01) x «"“ª∏ˆ”“∫¢◊”"£¨‘Ú"xµƒ«∞«˝Ω·µ„"Œ™ "À¸µƒ∏∏Ω·µ„"°£
    // (01) x «"“ª∏ˆ◊Û∫¢◊”"£¨‘Ú≤È’“"xµƒ◊ÓµÕµƒ∏∏Ω·µ„£¨≤¢«“∏√∏∏Ω·µ„“™æﬂ”–”“∫¢◊”"£¨’“µΩµƒ’‚∏ˆ"◊ÓµÕµƒ∏∏Ω·µ„"æÕ «"xµƒ«∞«˝Ω·µ„"°£
    RBTNode<T>* y = x->parent;
    while ((y != NULL) && (x == y->left))
    {
        x = y;
        y = y->parent;
    }
    
    return y;
}

/*
 * ∂‘∫Ï∫⁄ ˜µƒΩ⁄µ„(x)Ω¯––◊Û–˝◊™
 *
 * ◊Û–˝ æ“‚Õº(∂‘Ω⁄µ„xΩ¯––◊Û–˝)£∫
 *      px                              px
 *     /                               /
 *    x                               y
 *   /  \      --(◊Û–˝)-->           / \                #
 *  lx   y                          x  ry
 *     /   \                       /  \
 *    ly   ry                     lx  ly
 *
 *
 */
template <class T>
void RBTree<T>::leftRotate(RBTNode<T>* &root, RBTNode<T>* x)
{
    // …Ë÷√xµƒ”“∫¢◊”Œ™y
    RBTNode<T> *y = x->right;
    
    // Ω´ °∞yµƒ◊Û∫¢◊”°± …ËŒ™ °∞xµƒ”“∫¢◊”°±£ª
    // »Áπ˚yµƒ◊Û∫¢◊”∑«ø’£¨Ω´ °∞x°± …ËŒ™ °∞yµƒ◊Û∫¢◊”µƒ∏∏«◊°±
    x->right = y->left;
    if (y->left != NULL)
        y->left->parent = x;
    
    // Ω´ °∞xµƒ∏∏«◊°± …ËŒ™ °∞yµƒ∏∏«◊°±
    y->parent = x->parent;
    
    if (x->parent == NULL)
    {
        root = y;            // »Áπ˚ °∞xµƒ∏∏«◊°±  «ø’Ω⁄µ„£¨‘ÚΩ´y…ËŒ™∏˘Ω⁄µ„
    }
    else
    {
        if (x->parent->left == x)
            x->parent->left = y;    // »Áπ˚ x «À¸∏∏Ω⁄µ„µƒ◊Û∫¢◊”£¨‘ÚΩ´y…ËŒ™°∞xµƒ∏∏Ω⁄µ„µƒ◊Û∫¢◊”°±
        else
            x->parent->right = y;    // »Áπ˚ x «À¸∏∏Ω⁄µ„µƒ◊Û∫¢◊”£¨‘ÚΩ´y…ËŒ™°∞xµƒ∏∏Ω⁄µ„µƒ◊Û∫¢◊”°±
    }
    
    // Ω´ °∞x°± …ËŒ™ °∞yµƒ◊Û∫¢◊”°±
    y->left = x;
    // Ω´ °∞xµƒ∏∏Ω⁄µ„°± …ËŒ™ °∞y°±
    x->parent = y;
}

/*
 * ∂‘∫Ï∫⁄ ˜µƒΩ⁄µ„(y)Ω¯––”“–˝◊™
 *
 * ”“–˝ æ“‚Õº(∂‘Ω⁄µ„yΩ¯––◊Û–˝)£∫
 *            py                               py
 *           /                                /
 *          y                                x
 *         /  \      --(”“–˝)-->            /  \                     #
 *        x   ry                           lx   y
 *       / \                                   / \                   #
 *      lx  rx                                rx  ry
 *
 */
template <class T>
void RBTree<T>::rightRotate(RBTNode<T>* &root, RBTNode<T>* y)
{
    // …Ë÷√x «µ±«∞Ω⁄µ„µƒ◊Û∫¢◊”°£
    RBTNode<T> *x = y->left;
    
    // Ω´ °∞xµƒ”“∫¢◊”°± …ËŒ™ °∞yµƒ◊Û∫¢◊”°±£ª
    // »Áπ˚"xµƒ”“∫¢◊”"≤ªŒ™ø’µƒª∞£¨Ω´ °∞y°± …ËŒ™ °∞xµƒ”“∫¢◊”µƒ∏∏«◊°±
    y->left = x->right;
    if (x->right != NULL)
        x->right->parent = y;
    
    // Ω´ °∞yµƒ∏∏«◊°± …ËŒ™ °∞xµƒ∏∏«◊°±
    x->parent = y->parent;
    
    if (y->parent == NULL)
    {
        root = x;            // »Áπ˚ °∞yµƒ∏∏«◊°±  «ø’Ω⁄µ„£¨‘ÚΩ´x…ËŒ™∏˘Ω⁄µ„
    }
    else
    {
        if (y == y->parent->right)
            y->parent->right = x;    // »Áπ˚ y «À¸∏∏Ω⁄µ„µƒ”“∫¢◊”£¨‘ÚΩ´x…ËŒ™°∞yµƒ∏∏Ω⁄µ„µƒ”“∫¢◊”°±
        else
            y->parent->left = x;    // (y «À¸∏∏Ω⁄µ„µƒ◊Û∫¢◊”) Ω´x…ËŒ™°∞xµƒ∏∏Ω⁄µ„µƒ◊Û∫¢◊”°±
    }
    
    // Ω´ °∞y°± …ËŒ™ °∞xµƒ”“∫¢◊”°±
    x->right = y;
    
    // Ω´ °∞yµƒ∏∏Ω⁄µ„°± …ËŒ™ °∞x°±
    y->parent = x;
}

/*
 * ∫Ï∫⁄ ˜≤Â»Î–ﬁ’˝∫Ø ˝
 *
 * ‘⁄œÚ∫Ï∫⁄ ˜÷–≤Â»ÎΩ⁄µ„÷Æ∫Û( ß»•∆Ω∫‚)£¨‘Ÿµ˜”√∏√∫Ø ˝£ª
 * ƒøµƒ «Ω´À¸÷ÿ–¬À‹‘Ï≥…“ªø≈∫Ï∫⁄ ˜°£
 *
 * ≤Œ ˝Àµ√˜£∫
 *     root ∫Ï∫⁄ ˜µƒ∏˘
 *     node ≤Â»ÎµƒΩ·µ„        // ∂‘”¶°∂À„∑®µº¬€°∑÷–µƒz
 */
template <class T>
void RBTree<T>::insertFixUp(RBTNode<T>* &root, RBTNode<T>* node)
{
    RBTNode<T> *parent, *gparent;
    
    // »Ù°∞∏∏Ω⁄µ„¥Ê‘⁄£¨≤¢«“∏∏Ω⁄µ„µƒ—’…´ «∫Ï…´°±
    while ((parent = rb_parent(node)) && rb_is_red(parent))
    {
        gparent = rb_parent(parent);
        
        //»Ù°∞∏∏Ω⁄µ„°± «°∞◊Ê∏∏Ω⁄µ„µƒ◊Û∫¢◊”°±
        if (parent == gparent->left)
        {
            // Case 1Ãıº˛£∫ Â ÂΩ⁄µ„ «∫Ï…´
            {
                RBTNode<T> *uncle = gparent->right;
                if (uncle && rb_is_red(uncle))
                {
                    rb_set_black(uncle);
                    rb_set_black(parent);
                    rb_set_red(gparent);
                    node = gparent;
                    continue;
                }
            }
            
            // Case 2Ãıº˛£∫ Â Â «∫⁄…´£¨«“µ±«∞Ω⁄µ„ «”“∫¢◊”
            if (parent->right == node)
            {
                RBTNode<T> *tmp;
                leftRotate(root, parent);
                tmp = parent;
                parent = node;
                node = tmp;
            }
            
            // Case 3Ãıº˛£∫ Â Â «∫⁄…´£¨«“µ±«∞Ω⁄µ„ «◊Û∫¢◊”°£
            rb_set_black(parent);
            rb_set_red(gparent);
            rightRotate(root, gparent);
        }
        else//»Ù°∞zµƒ∏∏Ω⁄µ„°± «°∞zµƒ◊Ê∏∏Ω⁄µ„µƒ”“∫¢◊”°±
        {
            // Case 1Ãıº˛£∫ Â ÂΩ⁄µ„ «∫Ï…´
            {
                RBTNode<T> *uncle = gparent->left;
                if (uncle && rb_is_red(uncle))
                {
                    rb_set_black(uncle);
                    rb_set_black(parent);
                    rb_set_red(gparent);
                    node = gparent;
                    continue;
                }
            }
            
            // Case 2Ãıº˛£∫ Â Â «∫⁄…´£¨«“µ±«∞Ω⁄µ„ «◊Û∫¢◊”
            if (parent->left == node)
            {
                RBTNode<T> *tmp;
                rightRotate(root, parent);
                tmp = parent;
                parent = node;
                node = tmp;
            }
            
            // Case 3Ãıº˛£∫ Â Â «∫⁄…´£¨«“µ±«∞Ω⁄µ„ «”“∫¢◊”°£
            rb_set_black(parent);
            rb_set_red(gparent);
            leftRotate(root, gparent);
        }
    }
    
    // Ω´∏˘Ω⁄µ„…ËŒ™∫⁄…´
    rb_set_black(root);
}

/*
 * Ω´Ω·µ„≤Â»ÎµΩ∫Ï∫⁄ ˜÷–
 *
 * ≤Œ ˝Àµ√˜£∫
 *     root ∫Ï∫⁄ ˜µƒ∏˘Ω·µ„
 *     node ≤Â»ÎµƒΩ·µ„        // ∂‘”¶°∂À„∑®µº¬€°∑÷–µƒnode
 */
template <class T>
void RBTree<T>::insert(RBTNode<T>* &root, RBTNode<T>* node)
{
    RBTNode<T> *y = NULL;
    RBTNode<T> *x = root;
    
    // 1. Ω´∫Ï∫⁄ ˜µ±◊˜“ªø≈∂˛≤Ê≤È’“ ˜£¨Ω´Ω⁄µ„ÃÌº”µΩ∂˛≤Ê≤È’“ ˜÷–°£
    while (x != NULL)
    {
        y = x;
        if (node->key < x->key)
            x = x->left;
        else
            x = x->right;
    }
    
    node->parent = y;
    if (y != NULL)
    {
        if (node->key < y->key)
            y->left = node;
        else
            y->right = node;
    }
    else
        root = node;
    
    // 2. …Ë÷√Ω⁄µ„µƒ—’…´Œ™∫Ï…´
    node->color = RED;
    
    // 3. Ω´À¸÷ÿ–¬–ﬁ’˝Œ™“ªø≈∂˛≤Ê≤È’“ ˜
    insertFixUp(root, node);
}

/*
 * Ω´Ω·µ„(keyŒ™Ω⁄µ„º¸÷µ)≤Â»ÎµΩ∫Ï∫⁄ ˜÷–
 *
 * ≤Œ ˝Àµ√˜£∫
 *     tree ∫Ï∫⁄ ˜µƒ∏˘Ω·µ„
 *     key ≤Â»ÎΩ·µ„µƒº¸÷µ
 */
template <class T>
void RBTree<T>::insert(T key)
{
    RBTNode<T> *z = NULL;
    
    // »Áπ˚–¬Ω®Ω·µ„ ß∞‹£¨‘Ú∑µªÿ°£
    if ((z = new RBTNode<T>(key, BLACK, NULL, NULL, NULL)) == NULL)
        return;
    
    insert(mRoot, z);
}

/*
 * ∫Ï∫⁄ ˜…æ≥˝–ﬁ’˝∫Ø ˝
 *
 * ‘⁄¥”∫Ï∫⁄ ˜÷–…æ≥˝≤Â»ÎΩ⁄µ„÷Æ∫Û(∫Ï∫⁄ ˜ ß»•∆Ω∫‚)£¨‘Ÿµ˜”√∏√∫Ø ˝£ª
 * ƒøµƒ «Ω´À¸÷ÿ–¬À‹‘Ï≥…“ªø≈∫Ï∫⁄ ˜°£
 *
 * ≤Œ ˝Àµ√˜£∫
 *     root ∫Ï∫⁄ ˜µƒ∏˘
 *     node ¥˝–ﬁ’˝µƒΩ⁄µ„
 */
template <class T>
void RBTree<T>::removeFixUp(RBTNode<T>* &root, RBTNode<T> *node, RBTNode<T> *parent)
{
    RBTNode<T> *other;
    
    while ((!node || rb_is_black(node)) && node != root)
    {
        if (parent->left == node)
        {
            other = parent->right;
            if (rb_is_red(other))
            {
                // Case 1: xµƒ–÷µ‹w «∫Ï…´µƒ
                rb_set_black(other);
                rb_set_red(parent);
                leftRotate(root, parent);
                other = parent->right;
            }
            if ((!other->left || rb_is_black(other->left)) &&
                (!other->right || rb_is_black(other->right)))
            {
                // Case 2: xµƒ–÷µ‹w «∫⁄…´£¨«“wµƒ¡©∏ˆ∫¢◊”“≤∂º «∫⁄…´µƒ
                rb_set_red(other);
                node = parent;
                parent = rb_parent(node);
            }
            else
            {
                if (!other->right || rb_is_black(other->right))
                {
                    // Case 3: xµƒ–÷µ‹w «∫⁄…´µƒ£¨≤¢«“wµƒ◊Û∫¢◊” «∫Ï…´£¨”“∫¢◊”Œ™∫⁄…´°£
                    rb_set_black(other->left);
                    rb_set_red(other);
                    rightRotate(root, other);
                    other = parent->right;
                }
                // Case 4: xµƒ–÷µ‹w «∫⁄…´µƒ£ª≤¢«“wµƒ”“∫¢◊” «∫Ï…´µƒ£¨◊Û∫¢◊”»Œ“‚—’…´°£
                rb_set_color(other, rb_color(parent));
                rb_set_black(parent);
                rb_set_black(other->right);
                leftRotate(root, parent);
                node = root;
                break;
            }
        }
        else
        {
            other = parent->left;
            if (rb_is_red(other))
            {
                // Case 1: xµƒ–÷µ‹w «∫Ï…´µƒ
                rb_set_black(other);
                rb_set_red(parent);
                rightRotate(root, parent);
                other = parent->left;
            }
            if ((!other->left || rb_is_black(other->left)) &&
                (!other->right || rb_is_black(other->right)))
            {
                // Case 2: xµƒ–÷µ‹w «∫⁄…´£¨«“wµƒ¡©∏ˆ∫¢◊”“≤∂º «∫⁄…´µƒ
                rb_set_red(other);
                node = parent;
                parent = rb_parent(node);
            }
            else
            {
                if (!other->left || rb_is_black(other->left))
                {
                    // Case 3: xµƒ–÷µ‹w «∫⁄…´µƒ£¨≤¢«“wµƒ◊Û∫¢◊” «∫Ï…´£¨”“∫¢◊”Œ™∫⁄…´°£
                    rb_set_black(other->right);
                    rb_set_red(other);
                    leftRotate(root, other);
                    other = parent->left;
                }
                // Case 4: xµƒ–÷µ‹w «∫⁄…´µƒ£ª≤¢«“wµƒ”“∫¢◊” «∫Ï…´µƒ£¨◊Û∫¢◊”»Œ“‚—’…´°£
                rb_set_color(other, rb_color(parent));
                rb_set_black(parent);
                rb_set_black(other->left);
                rightRotate(root, parent);
                node = root;
                break;
            }
        }
    }
    if (node)
        rb_set_black(node);
}

/*
 * …æ≥˝Ω·µ„(node)£¨≤¢∑µªÿ±ª…æ≥˝µƒΩ·µ„
 *
 * ≤Œ ˝Àµ√˜£∫
 *     root ∫Ï∫⁄ ˜µƒ∏˘Ω·µ„
 *     node …æ≥˝µƒΩ·µ„
 */
template <class T>
void RBTree<T>::remove(RBTNode<T>* &root, RBTNode<T> *node)
{
    RBTNode<T> *child, *parent;
    RBTColor color;
    
    // ±ª…æ≥˝Ω⁄µ„µƒ"◊Û”“∫¢◊”∂º≤ªŒ™ø’"µƒ«Èøˆ°£
    if ((node->left != NULL) && (node->right != NULL))
    {
        // ±ª…æΩ⁄µ„µƒ∫ÛºÃΩ⁄µ„°£(≥∆Œ™"»°¥˙Ω⁄µ„")
        // ”√À¸¿¥»°¥˙"±ª…æΩ⁄µ„"µƒŒª÷√£¨»ª∫Û‘ŸΩ´"±ª…æΩ⁄µ„"»•µÙ°£
        RBTNode<T> *replace = node;
        
        // ªÒ»°∫ÛºÃΩ⁄µ„
        replace = replace->right;
        while (replace->left != NULL)
            replace = replace->left;
        
        // "nodeΩ⁄µ„"≤ª «∏˘Ω⁄µ„(÷ª”–∏˘Ω⁄µ„≤ª¥Ê‘⁄∏∏Ω⁄µ„)
        if (rb_parent(node))
        {
            if (rb_parent(node)->left == node)
                rb_parent(node)->left = replace;
            else
                rb_parent(node)->right = replace;
        }
        else
            // "nodeΩ⁄µ„" «∏˘Ω⁄µ„£¨∏¸–¬∏˘Ω⁄µ„°£
            root = replace;
        
        // child «"»°¥˙Ω⁄µ„"µƒ”“∫¢◊”£¨“≤ «–Ë“™"µ˜’˚µƒΩ⁄µ„"°£
        // "»°¥˙Ω⁄µ„"øœ∂®≤ª¥Ê‘⁄◊Û∫¢◊”£°“ÚŒ™À¸ «“ª∏ˆ∫ÛºÃΩ⁄µ„°£
        child = replace->right;
        parent = rb_parent(replace);
        // ±£¥Ê"»°¥˙Ω⁄µ„"µƒ—’…´
        color = rb_color(replace);
        
        // "±ª…æ≥˝Ω⁄µ„" «"À¸µƒ∫ÛºÃΩ⁄µ„µƒ∏∏Ω⁄µ„"
        if (parent == node)
        {
            parent = replace;
        }
        else
        {
            // child≤ªŒ™ø’
            if (child)
                rb_set_parent(child, parent);
            parent->left = child;
            
            replace->right = node->right;
            rb_set_parent(node->right, replace);
        }
        
        replace->parent = node->parent;
        replace->color = node->color;
        replace->left = node->left;
        node->left->parent = replace;
        
        if (color == BLACK)
            removeFixUp(root, child, parent);
        
        delete node;
        return;
    }
    
    if (node->left != NULL)
        child = node->left;
    else
        child = node->right;
    
    parent = node->parent;
    // ±£¥Ê"»°¥˙Ω⁄µ„"µƒ—’…´
    color = node->color;
    
    if (child)
        child->parent = parent;
    
    // "nodeΩ⁄µ„"≤ª «∏˘Ω⁄µ„
    if (parent)
    {
        if (parent->left == node)
            parent->left = child;
        else
            parent->right = child;
    }
    else
        root = child;
    
    if (color == BLACK)
        removeFixUp(root, child, parent);
    delete node;
}

/*
 * …æ≥˝∫Ï∫⁄ ˜÷–º¸÷µŒ™keyµƒΩ⁄µ„
 *
 * ≤Œ ˝Àµ√˜£∫
 *     tree ∫Ï∫⁄ ˜µƒ∏˘Ω·µ„
 */
template <class T>
void RBTree<T>::remove(T key)
{
    RBTNode<T> *node;
    
    // ≤È’“key∂‘”¶µƒΩ⁄µ„(node)£¨’“µΩµƒª∞æÕ…æ≥˝∏√Ω⁄µ„
    if ((node = search(mRoot, key)) != NULL)
        remove(mRoot, node);
}

/*
 * œ˙ªŸ∫Ï∫⁄ ˜
 */
template <class T>
void RBTree<T>::destroy(RBTNode<T>* &tree)
{
    if (tree == NULL)
        return;
    
    if (tree->left != NULL)
        return destroy(tree->left);
    if (tree->right != NULL)
        return destroy(tree->right);
    
    delete tree;
    tree = NULL;
}

template <class T>
void RBTree<T>::destroy()
{
    destroy(mRoot);
}

/*
 * ¥Ú”°"∂˛≤Ê≤È’“ ˜"
 *
 * key        -- Ω⁄µ„µƒº¸÷µ
 * direction  --  0£¨±Ì æ∏√Ω⁄µ„ «∏˘Ω⁄µ„;
 *               -1£¨±Ì æ∏√Ω⁄µ„ «À¸µƒ∏∏Ω·µ„µƒ◊Û∫¢◊”;
 *                1£¨±Ì æ∏√Ω⁄µ„ «À¸µƒ∏∏Ω·µ„µƒ”“∫¢◊”°£
 */
template <class T>
void RBTree<T>::print(RBTNode<T>* tree, T key, int direction)
{
    if (tree != NULL)
    {
        if (direction == 0)    // tree «∏˘Ω⁄µ„
            cout << setw(2) << tree->key << "(B) is root" << endl;
        else                // tree «∑÷÷ßΩ⁄µ„
            cout << setw(2) << tree->key << (rb_is_red(tree) ? "(R)" : "(B)") << " is " << setw(2) << key << "'s " << setw(12) << (direction == 1 ? "right child" : "left child") << endl;
        
        print(tree->left, tree->key, -1);
        print(tree->right, tree->key, 1);
    }
}

template <class T>
void RBTree<T>::print()
{
    if (mRoot != NULL)
        print(mRoot, mRoot->key, 0);
}

#endif
