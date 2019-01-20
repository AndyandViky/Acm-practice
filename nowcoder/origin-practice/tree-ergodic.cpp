//
// Created by 杨霖 on 2019/1/20.
//

#include <cstdio>
#include <string.h>
using namespace std;
#define MAXSIZE 26

typedef struct Node{
    char data;
    Node *lchild;
    Node *rchild;
}Node;
char pre[MAXSIZE], middle[MAXSIZE];
Node *BiTree;

// 建树
Node *buildTree(char *pre, char *mid, int length) {
    char rootKey = pre[0];
    Node* root = new Node;
    root->data = rootKey;
    root->lchild = root->rchild = NULL;
    if(length == 1 && pre[0] == mid[0])
        return root;

    char* rootMidOrder = mid;
    int rootIndex = 0;
    while(rootMidOrder[0] != rootKey && rootMidOrder <= (mid+length-1))
    {
        ++rootMidOrder;
        ++rootIndex;
    }
    if(rootIndex > 0)
    {
        root->lchild = buildTree(pre+1, mid, rootIndex);
    }
    if(length-rootIndex-1 > 0)
    {
        root->rchild = buildTree(pre+rootIndex+1, rootMidOrder+1, length-rootIndex-1);
    }
    return root;
}
// 后续遍历
void backE(Node *BiTree) {
    if(BiTree) {
        backE(BiTree->lchild);
        backE(BiTree->rchild);
        printf("%c", BiTree->data);
    }
}

int main() {
    scanf("%s", pre);
    scanf("%s", middle);
    int length = strlen(pre);
    BiTree = buildTree(pre, middle, length);
    backE(BiTree);
    return 0;
}
