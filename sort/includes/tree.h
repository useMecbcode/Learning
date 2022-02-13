//
// Created by dev on 17/1/2022.
//

#ifndef SORT_TREE_H
#define SORT_TREE_H
#include <iostream>
#include <queue>
namespace tree {
    /// Define two-Nodes' Node
    class [[maybe_unused]] TNode;
    class [[maybe_unused]] TNode{
    public:
        int data;
        TNode *rchild;
        TNode *lchild;
        explicit TNode(int value);
        explicit TNode(int value,TNode *rchild, TNode* lchild);
    };
    class BinaryTree{
    private:
        TNode*root;
    public:
        BinaryTree();
        void add(int);
        ~BinaryTree();
        void print()const;
        void levelorder()const;
    private:
        void makeEmpty(TNode *&);
        void add(TNode*&,int);
        void print(TNode *)const;
        void levelorder(TNode * x)const;
    };
}
#endif //SORT_TREE_H
