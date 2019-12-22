/*

22) Insert a given element into an ordered list and display the contents. (ONE IMPLEMENTATION)

*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
    struct node* prev;
};

typedef struct node Node;

Node* getnode(int item)
{
    Node* newnode = (Node*)malloc(sizeof(int));
    newnode->data = item;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}

Node* insertAtPos(Node* start, int item, int pos)
{
    if (start == NULL) {
        start = getnode(item);
        return start;
    }

    else if (pos == 1) {
        Node* currptr = start;
        Node* newnode = getnode(item);
        newnode->next = currptr;
        currptr->prev = newnode;
        start = newnode;
        return start;
    }
    else {
        Node* currptr = start;
        Node* prevptr = NULL;
        Node* newnode = getnode(item);
        for (int i = 1; i < pos; i++) {
            prevptr = currptr;
            currptr = currptr->next;
        }
        if (currptr != NULL) {

            newnode->prev = prevptr;
            newnode->next = currptr;
            prevptr->next = newnode;
            currptr->prev = newnode;
        }
        else {
            prevptr->next = newnode;
            newnode->prev = prevptr;
        }
        return start;
    }
}

Node* insert(Node* start, int item)
{
    int pos = 1;
    if (start == NULL)
        start = insertAtPos(start, item, 1);

    else {
        Node* currptr = start;
        if (currptr->data >= item)
            start = insertAtPos(start, item, 1);
        else {
            for (currptr = start; currptr != NULL; currptr = currptr->next) {
                if (currptr->data >= item) {
                    start = insertAtPos(start, item, pos);
                    break;
                }
                else
                    pos++;
            }
            if (currptr == NULL)
                start = insertAtPos(start, item, pos);
        }
    }
    return start;
}

void display(Node* start)
{
    Node* currptr = start;
    if (start != NULL) {
        printf("List: ");
        while (currptr != NULL) {
            printf("%d  ", currptr->data);
            currptr = currptr->next;
        }
        printf("\n");
    }
    else
        printf("List is Empty\n");
}
int main()
{
    Node* start = NULL;
    int ch, item;
    printf("1.Insert\n2.Display\n3.Exit\n");
    do {
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
        case 1:
            printf("Enter the element: ");
            scanf("%d", &item);
            start = insert(start, item);
            break;
        case 2:
            display(start);
            break;
        case 3:
            printf("Terminated...");
            return 0;
        default:
            printf("Invalid choice\n");
        }
    } while (ch != 3);
}
