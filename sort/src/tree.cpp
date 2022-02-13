//
// Created by dev on 17/1/2022.
//
#include "../includes/tree.h"

tree::TNode::TNode(int value) : TNode{value, nullptr, nullptr} {

}

tree::TNode::TNode(int value, tree::TNode *rchild, tree::TNode *lchild) : data{value}, rchild{rchild}, lchild{lchild} {

}

tree::BinaryTree::BinaryTree() : root{nullptr} {

}

void tree::BinaryTree::add(int val) {
    add(root, val);
}

void tree::BinaryTree::add(tree::TNode *&node, int val) {
    if (!node) {
        node = new TNode{val};
    } else {
        if (val < 4)
            add(node->lchild, val);
        else
            add(node->rchild, val);
    }
}

tree::BinaryTree::~BinaryTree() {
    makeEmpty(root);
}

void tree::BinaryTree::makeEmpty(tree::TNode *&node) {
    if (node != nullptr) {
        makeEmpty(node->lchild);
        makeEmpty(node->rchild);
        delete node;
    }
    node = nullptr;
}

void tree::BinaryTree::print() const {
    print(root);
}

void tree::BinaryTree::print(tree::TNode *node) const {
    if (node != nullptr) {
        std::cout << node->data << " ";
        print(node->lchild);
        print(node->rchild);
    }
}

void tree::BinaryTree::levelorder() const {
    levelorder(root);
}

void tree::BinaryTree::levelorder(tree::TNode *x) const {
        std::queue<tree::TNode*> queue;

        if(x == nullptr)
        {
            return;
        }

        /*根节点先入队*/
        queue.push(x);

        while(!queue.empty())
        {
            auto node = queue.front();
            queue.pop();
            printf(" %d ",node->data);

            if(node->lchild != nullptr)
            {
                queue.push(node->lchild);
            }

            if(node->rchild != nullptr)
            {
                queue.push(node->rchild);
            }
        }
}
