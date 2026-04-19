#include <stdio.h>
#include <stdlib.h>

struct BST {
    int value;
    struct BST *left, *right;
};

struct BST* newNode(int x) {
    struct BST* temp = (struct BST*)malloc(sizeof(struct BST));
    temp->value = x;
    temp->left = temp->right = NULL;
    return temp;
}

struct BST* add(struct BST* root, int x) {
    if (root == NULL)
        return newNode(x);

    if (x < root->value)
        root->left = add(root->left, x);
    else
        root->right = add(root->right, x);

    return root;
}

void display(struct BST* root, int l, int h) {
    if (root == NULL)
        return;

    if (root->value >= l)
        display(root->left, l, h);

    if (root->value >= l && root->value <= h)
        printf("%d ", root->value);

    if (root->value <= h)
        display(root->right, l, h);
}

int main() {
    int n, i, x, l, h;
    struct BST* root = NULL;

    printf("PRN: 25070521341\n");
    printf("Pradyumna kunthe\n");

    printf("NO of  nodes:\n");
    scanf("%d", &n);

    printf("Enter values:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &x);
        root = add(root, x);
    }

    printf("enter lower and upper limit:\n");
    scanf("%d %d", &l, &h);

    printf("values in given range:\n");
    display(root, l, h);

    return 0;
}
