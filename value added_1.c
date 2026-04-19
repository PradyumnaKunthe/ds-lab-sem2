#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

int main() {
    struct node *root, *n1, *n2, *n3, *n4;

    root = (struct node*)malloc(sizeof(struct node));
    n1   = (struct node*)malloc(sizeof(struct node));
    n2   = (struct node*)malloc(sizeof(struct node));
    n3   = (struct node*)malloc(sizeof(struct node));
    n4   = (struct node*)malloc(sizeof(struct node));

    root->data = 17;
    n1->data = 4;
    n2->data = 18;
    n3->data = 2;
    n4->data = 9;

    root->left = n1;
    root->right = n2;

    n1->left = n3;
    n1->right = n4;

    n2->left = NULL;
    n2->right = NULL;

    n3->left = NULL;
    n3->right = NULL;

    n4->left = NULL;
    n4->right = NULL;

    int low = 4, high = 24;

    struct node* stack[100];
    int top = -1;
    struct node* curr = root;

    while (curr != NULL || top != -1) {

        while (curr != NULL) {
            stack[++top] = curr;
            curr = curr->left;
        }

        curr = stack[top--];

        if (curr->data >= low && curr->data <= high)
            printf("%d ", curr->data);

        curr = curr->right;
    }

    printf("Pradyumna kunthe");

    return 0;
}
