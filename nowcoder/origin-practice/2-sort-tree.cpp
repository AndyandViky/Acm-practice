//
// Created by 杨霖 on 2019/1/18.
//

#include <cstdio>
using namespace std;
#define MAXSIZE 100

struct Node{
    int data;
    Node *lchild;
    Node *rchild;
};

int N, data;
bool isPrint = false;
void insert(Node *tree, Node *node) {
    if(tree) {
        if(tree->data > node->data) {
            insert(tree->lchild, node);
            if (!tree->lchild) tree->lchild = node;
            if (!isPrint) printf("%d\n", tree->data);
        }
        else {
            insert(tree->rchild, node);
            if (!tree->rchild) tree->rchild = node;
            if (!isPrint) printf("%d\n", tree->data);
        }
        isPrint = true;
    }
}
int main() {
    int i;
    scanf("%d", &N);
    if(N <= 0) {
        printf("%d", -1);
        return 0;
    };
    // 初始化头节点
    scanf("%d", &data);
    Node *tree = new Node;
    tree->data = data;
    tree->lchild = NULL;
    tree->rchild = NULL;
    printf("%d\n", -1);
    for(i = 1; i < N; i++) {
        scanf("%d", &data);
        Node *node = new Node;
        node->data = data;
        node->lchild = NULL;
        node->rchild = NULL;
        isPrint = false;
        insert(tree, node);
    }

    return 0;
}
