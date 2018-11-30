/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node * next;
}Node;

void printList(const Node * head)
{
    printf("Print Linked List\n");

    if(NULL == head)
        printf("List is NULL\n");

    while(NULL != head)
    {
        printf("%d\n",head->data);
        head = head->next;
    }
}

void push(Node **head, int data)
{
    Node *new_node = NULL;

    if(NULL == *head)
        return;

    new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

void insertAfter(Node *prev_node, int new_data)
{
    if(prev_node == NULL)
        return;

    Node * new_node = (Node *)malloc(sizeof(Node));
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

//add a node at the end of the linked List
void append(Node **head, int new_data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = new_data;
    new_node->next = NULL;

    if(*head == NULL)
    {
        *head = new_node;
        return;
    }

    Node * last = *head;
    while(last->next != NULL)
        last = last->next;
    last->next = new_node;
}

// delete a node with a key
void delete_node(Node **head_ref, int key)
{
    if(*head_ref == NULL)
        return;
    if((*head_ref)->data == key)
    {
        Node * tmp = *head_ref;
        *head_ref = (*head_ref)->next;
        free(tmp);
        return;
    }
    Node * cur_node = *head_ref;
    Node * prev_node = NULL;
    while(cur_node != NULL)
    {
        if(cur_node->data == key)
        {
            Node * tmp = cur_node;
            prev_node->next = cur_node->next;
            free(tmp);
            return;
        }
        prev_node = cur_node;
        cur_node = cur_node->next;
    }
}

//Delete a Linked List node at a given position
void deleteNode(Node **head_ref, int pos)
{
    Node * cur_node = *head_ref;
    Node * prev_node = NULL;
    int i = 0;
    if(*head_ref == NULL)
        return;
    if(pos == 0)
    {
        *head_ref = cur_node->next;
        free(cur_node);
        return;
    }
    while(cur_node != NULL)
    {
        if(pos == i)
        {
            prev_node->next = cur_node->next;
            free(cur_node);
            return;
        }
        prev_node = cur_node;
        cur_node = cur_node->next;
        i++;
    }
}

//delete entire LinkedList
void delete_list(Node **head_ref)
{
    Node * tmp = *head_ref;
    if(*head_ref == NULL)
        return;
    while(*head_ref)
    {
        tmp = *head_ref;
        *head_ref = (*head_ref)->next;
        free(tmp);
    }
}

// Length of the List - iterative
void list_len_iterative(Node * head)
{
    int count = 0;
    if(head == NULL)
        return;
    while(head != NULL)
    {
        count++;
        head = head->next;
    }
    printf("List Length : %d\n", count);
}

// Length of the list - recursive
int list_len_recursive(Node * head)
{
    if(head == NULL)
        return 0;
    return 1 + list_len_recursive(head->next);
}

//main program
int main()
{
    printf("LinkedList Problem\n");

    Node * head = NULL;
    Node * second = NULL;
    Node * third = NULL;
    int count = 0;

    head = (Node *)malloc(sizeof(Node));
    second = (Node *)malloc(sizeof(Node));
    third = (Node *)malloc(sizeof(Node));

    head->data = 1;
    head->next = second;
    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next = NULL;

    //printList(head);
    push(&head, 4);
    //printList(head);
    append(&head,5);
    //printList(head);
    insertAfter(head,6);
    printList(head);
    //delete_node(&head,1);
    //printList(head);
    //deleteNode(&head,0);
    //printList(head);
    //deleteNode(&head,1);
    //printList(head);
    //delete_list(&head);
    //printList(head);
    list_len_iterative(head);
    count = list_len_recursive(head);
    printf("List count recursive : %d", count);

    return 0;
}
