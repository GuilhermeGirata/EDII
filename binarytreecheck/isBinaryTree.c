#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

int isBSTUtil(struct node* node, int min, int max);

int isBST(struct node* node)
{
    return (isBSTUtil(node, INT_MIN, INT_MAX));
}

int isBSTUtil(struct node* node, int min, int max)
{
    if (node == NULL)
        return 1;

    if (node->data < min || node->data > max)
        return 0;

    return isBSTUtil(node->left, min, node->data - 1)
           &&
           isBSTUtil(node->right, node->data + 1,
                     max);
}

struct node* newNode(int data)
{
    struct node* node
        = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}

int main()
{
    struct node* root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(5);

    if (isBST(root))
        printf("Arvore binaria de busca");
    else
        printf("Nao e arvore binaria de busca");

    getchar();
    return 0;
}
