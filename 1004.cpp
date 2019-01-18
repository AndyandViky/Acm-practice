//
// Created by 杨霖 on 2019/1/16.
//

#include <cstdio>
using namespace std;
#define MAX_N 110

struct Node
{
    int ID;
    Node *Brother;
    Node *Child;
};

int N, M;
int maxLevel = 0;
Node *nodes[MAX_N];
int levelCnt[MAX_N];

void count(Node *root, int level)
{
    if (root == NULL)
        return;
    count(root->Child, level + 1);
    count(root->Brother, level);
    if (root->Child == NULL)
    {
        levelCnt[level]++;
        if (maxLevel <= level)
        {
            maxLevel = level;
        }
    }
}

int main()
{
    scanf("%d%d", &N, &M);
    //init nodes
    for (int i = 0; i < MAX_N; i++)
    {
        Node *node = new Node;
        node->ID = i;
        node->Brother = NULL;
        node->Child = NULL;
        nodes[i] = node;
    }
    //input
    for (int i = 0; i < M; i++)
    {
        int nodeID, childNum, childID;
        scanf("%d%d", &nodeID, &childNum);
        Node *parent = nodes[nodeID];
        for (int k = 0; k < childNum; k++)
        {
            scanf("%d", &childID);
            Node *newChild = nodes[childID];
            // first child,add to parent left
            if (k == 0)
            {
                parent->Child = newChild;
                continue;
            }
            // other child,add to child brother
            newChild->Brother = parent->Child;
            parent->Child = newChild;
        }
    }
    count(nodes[1], 0);
    for (int i = 0; i <= maxLevel; i++)
    {
        if (i != 0)
            printf(" ");
        printf("%d", levelCnt[i]);
    }
    return 0;
}