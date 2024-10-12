#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int element;
    void *next;
} Node;

Node *head = NULL;

void printOpions()
{
    printf("Adicionar à lista\n");
    printf("Remover da lista\n");
    printf("Mostrar lista\n ");
    printf("Sair\n");
}

Node *addnode(int element)
{
    Node *new = malloc(sizeof(Node));

    if (head == NULL)
    {
        if (new == NULL)
            return NULL;

        new->element = element;
        head = new;
        new->next = NULL;
    }
    else
    {
        if (new == NULL)
            return NULL;
        new->element = element;
        new->next = head;
        head = new;
    }
    return new;
}

int removeElement(int element) {
    Node *current = head;
    Node *prev = NULL; 

    int found = 0; 

    while (current != NULL) {
        if (current->element == element) {
            if (current == head) {
                head = current->next; 
            } else {
                prev->next = current->next; 
            }

            free(current);
            
            found = 1; 
            break; 
        }

        prev = current; 
        current = current->next; 
    }

    return found; 
}


void printList()
{
    Node *current = head;
    while (current != NULL)
    {
        printf("%d -> ", current->element);
        current = current->next;
    }
    printf("\n");
}

int main(void)
{


    int option = -1;
    while (option != 4)
    {
    printOpions();
        int numRecieved = scanf("%d", &option);

        if (numRecieved == 1 && option > 0 && option < 4)
        {
            switch (option)
            {
            case 1:
                printf("What data want you save?");
                scanf("%d", &option);
                Node *new = addnode(option);
            case 2:
                printf("What should i remove?");
                scanf("%d", &option);
                int success = removeElement(option); 
                if (!success)
                {
                    printf("Element not found");
                }
            case 3:
            case 4:
            default:
                printList();
            }
        }
    }
}