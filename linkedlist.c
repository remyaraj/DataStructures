//Linked List and its basic operations.

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};


void insert(struct node **root, int a) {

    struct node * elem = (struct node *) calloc(sizeof(struct node), 1);

    elem->data = a;
    elem->next = NULL;

    if(*root == NULL ) {
        *root = elem;
    } else if((*root)->next == NULL ) {
        (*root)->next = elem;
    } else {
        insert(&(*root)->next, a);
    }
}    

void printList(struct node * root) {
    
    if(root == NULL ) {
        printf("No elements\n");
        return;
    } 

    while(root->next != NULL ) {
        printf("%d ->", root->data);
        root = root->next;
    }

    printf("%d\n", root->data);
}

void insertAtBegining(struct node **root, int a) {
    
    struct node * elem = (struct node *) calloc(sizeof(struct node) , 1);
    elem->data = a;
    
    if(*root == NULL)  {
        elem->next = NULL;
    } else {
        elem->next = *root;
    }

    *root = elem;
}

int main()
{
    struct node * root = NULL;

    int a = 0;

    do {
        
        printf("Enter the choice\n1.Insertion at tail  2. Print 3. Insert at begining\n");
        scanf("%d",&a);

        int b = 0;

        switch(a) {

            case 1:
                printf("Enter the element\n");
                scanf("%d", &b);
                insert(&root, b);
                break;
            case 2:
                printList(root);
                break;
            case 3:
                printf("Enter the element\n");
                scanf("%d", &b);
                insertAtBegining(&root, b);
                break;
            case 4:
                exit(0);
        }

    } while(a < 4);
}
