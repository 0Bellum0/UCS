#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}NODE;
/*
NODE* newNode(int data) {
    NODE* node = (NODE*)malloc(sizeof(NODE));
    node->data = data;
    node->next = NULL;
    return node;
}
*/
NODE* newNode(NODE* head){
    srand(time(NULL));
    int i, value;
    NODE *aux = (NODE*)malloc(sizeof(NODE));
    for(i=0; i<1000; i++){
        value = rand() % 1000;
        if(i==0){
            head->data = value;
            head->next = NULL;
        }
        else{
            aux = head;
            head->next = aux;
            head->data = value;
        }
    }
    free(aux);
}

NODE* bubbleSort(NODE* head) {
    if (head == NULL || head->next == NULL)
        return head;

    int swapped;
    NODE *ptr1, *lptr = NULL;

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);

    return head;
}

void printList(NODE* head) {
    NODE* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    NODE* head = (NODE*)malloc(sizeof(NODE));;
    newNode(head);
    /*head->next = newNode(3);
    head->next->next = newNode(8);
    head->next->next->next = newNode(1);
*/
    printf("Lista original:\n");
    printList(head);

    head = bubbleSort(head);

    printf("Lista ordenada:\n");
    printList(head);

    return 0;
}