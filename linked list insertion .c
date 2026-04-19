#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtPosition(int data, int position){

    struct Node* newNode = createNode(data);

    if(position == 0){
        newNode->next = head;
        head = newNode;
        printf("Element %d inserted at position %d\n", data, position);
        return;
    }

    struct Node* temp = head;

    for(int i = 0; i < position - 1 && temp != NULL; i++){
        temp = temp->next;
    }

    if(temp == NULL){
        printf("Invalid position\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    printf("Element %d inserted at position %d\n", data, position);
}

void display(){
    struct Node* temp = head;

    if(temp == NULL){
        printf("List is empty\n");
        return;
    }

    printf("Linked List: ");
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {

    int choice, data, position;

    do{
        printf("\n---Menu---\n");
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Reverse\n");
        printf("4.Display\n");
        printf("5.Exit\n");

        printf("Enter Choice: ");
        scanf("%d",&choice);

        switch(choice){

            case 1:
                printf("Enter data: ");
                scanf("%d",&data);

                printf("Enter position: ");
                scanf("%d",&position);

                insertAtPosition(data , position);
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    }while(choice != 5);

    return 0;
}
