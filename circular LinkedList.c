#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

typedef struct node* NODE;

NODE createNode(int x) {
    NODE newNode = (NODE)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = x;
    newNode->next = newNode;
    return newNode;
}

NODE insertBegin(NODE last, int x) {
    NODE newNode = createNode(x);

    if (last == NULL) {
        return newNode;
    }

    newNode->next = last->next;
    last->next = newNode;

    return last;
}

NODE insertEnd(NODE last, int x) {
    NODE newNode = createNode(x);

    if (last == NULL) {
        return newNode;
    }

    newNode->next = last->next;
    last->next = newNode;

    return newNode;
}

NODE insertAtPos(NODE last, int x, int pos) {
    if (pos == 1) {
        return insertBegin(last, x);
    }

    NODE temp = last->next;
    int i = 1;

    while (i < pos - 1 && temp->next != last->next) {
        temp = temp->next;
        i++;
    }

    NODE newNode = createNode(x);
    newNode->next = temp->next;
    temp->next = newNode;

    if (temp == last) {
        return newNode;
    }

    return last;
}

NODE deleteBegin(NODE last) {
    if (last == NULL) {
        return NULL;
    }

    NODE first = last->next;

    if (first == last) {
        free(first);
        return NULL;
    }

    last->next = first->next;
    free(first);

    return last;
}

NODE deleteEnd(NODE last) {
    if (last == NULL) {
        return NULL;
    }

    NODE temp = last->next;

    if (temp == last) {
        free(last);
        return NULL;
    }

    while (temp->next != last) {
        temp = temp->next;
    }

    temp->next = last->next;
    free(last);

    return temp;
}

NODE deleteValue(NODE last, int x) {
    if (last == NULL) {
        return NULL;
    }

    NODE curr = last->next, prev = last;

    do {
        if (curr->data == x) {
            if (curr == last && curr == last->next) {
                free(curr);
                return NULL;
            }
            else if (curr == last->next) {
                last->next = curr->next;
                free(curr);
                return last;
            }
            else if (curr == last) {
                prev->next = curr->next;
                free(curr);
                return prev;
            }
            else {
                prev->next = curr->next;
                free(curr);
                return last;
            }
        }
        prev = curr;
        curr = curr->next;
    } while (curr != last->next);

    return last;
}

int search(NODE last, int key) {
    if (last == NULL) {
        return -1;
    }

    NODE temp = last->next;
    int pos = 1;

    do {
        if (temp->data == key) {
            return pos;
        }
        temp = temp->next;
        pos++;
    } while (temp != last->next);

    return -1;
}

void display(NODE last) {
    if (last == NULL) {
        printf("List is empty\n");
        return;
    }

    NODE temp = last->next;

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != last->next);

    printf("(back to start)\n");
}

int main() {
    NODE last = NULL;

    last = insertEnd(last, 10);
    last = insertEnd(last, 20);
    last = insertEnd(last, 30);

    display(last);

    last = insertBegin(last, 5);
    display(last);

    last = insertAtPos(last, 15, 3);
    display(last);

    last = deleteBegin(last);
    display(last);

    last = deleteEnd(last);
    display(last);

    last = deleteValue(last, 20);
    display(last);

    int pos = search(last, 15);
    if (pos != -1)
        printf("Found at position %d\n", pos);
    else
        printf("Not found\n");

    return 0;
}
