//
// Created by 杨霖 on 2019/1/27.
// 建立二叉排序树，并且遍历
//

#include <cstdio>
using namespace std;

typedef struct Node {
    int data;
    Node *lchild;
    Node *rchild;
}Node;
Node *BTree;

Node *find(Node *Tree, int element) {
    while(Tree) {
        if(element > Tree->data) {
            if(Tree->rchild) Tree = Tree->rchild;
            else break;
        }
        else if(element < Tree->data){
            if(Tree->lchild) Tree = Tree->lchild;
            else break;
        } else return NULL;
    }
    return Tree;
}
void insert(Node *Tree, int element) {
    Node *node = new Node;
    node->data = element;
    node->lchild = node->rchild = NULL;
    if(element > Tree->data)
        Tree->rchild = node;
    else
        Tree->lchild = node;
}
void preDo(Node *Tree) {
    if(Tree) {
        printf("%d ", Tree->data);
        preDo(Tree->lchild);
        preDo(Tree->rchild);
    }
}
void midDo(Node *Tree) {
    if(Tree) {
        midDo(Tree->lchild);
        printf("%d ", Tree->data);
        midDo(Tree->rchild);
    }
}
void latDo(Node *Tree) {
    if(Tree) {
        latDo(Tree->lchild);
        latDo(Tree->rchild);
        printf("%d ", Tree->data);
    }
}
int main() {
    int i, n, element = 0;
    scanf("%d", &n);
    // 初始化头
    BTree = new Node;
    BTree->rchild = BTree->lchild = NULL;
    // 建树
    for(i=0; i<n; i++) {
        scanf("%d", &element);
        if(i == 0) BTree->data = element;
        else {
            Node *t = find(BTree, element);
            if(t) insert(t, element);
        }
    }

    preDo(BTree);
    printf("\n");
    midDo(BTree);
    printf("\n");
    latDo(BTree);
    return 0;
}
