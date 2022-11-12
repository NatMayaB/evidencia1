#include <stdlib.h>
#include <stdio.h>


struct Node
    {
        struct Node *previous;
        int data;
        struct Node *next;
    };

struct Node * AddForEmpty(int data)
    {
        struct Node * newNode = malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->previous = newNode;
        newNode->next = newNode;
        return newNode;
    }

struct Node * AddAtStart(struct Node * tail, int data)
    {
        struct Node * node = AddForEmpty(data);
        if (tail == NULL)
        {
            return node;
        }
        else
        {
            struct Node * newNode = tail->next;

            node->previous = tail;
            node->next = newNode;
            newNode->previous = node;
            tail->next = node;
            return tail;
        }
    }

struct Node * AddAtEnd(struct Node * tail, int data)
    {
        struct Node * node = AddForEmpty(data);
        if (tail == NULL)
        {
            return node;
        }
        else
        {
            struct Node * newNode = tail->next;
            node->next = newNode;
            node->previous = tail;
            tail->next = node;
            newNode->previous = node;
            tail = node;
            return tail;
        }
    }

void ConsecutiveAdd(struct Node * tail,int numbers)
{
    int i=0;
    int Add;
    while (i <= numbers)
    {
        printf("Enter a number to add to the list: ");
        scanf("%d", &Add);
        tail = AddAtStart(tail, Add);
        i+=1;
    }
}

struct Node * DeleteFirst(struct Node * tail)
{
    if(tail == NULL)
    {
        printf("List is empty!");
        return tail;
    }
    struct Node * newNode = tail->next;
    if (newNode == tail)
    {
        free(tail);
        tail = NULL;
        return tail;
    }
    tail->next = newNode->next;
    newNode->next->previous = tail;
    free(newNode);
    return tail;
}

struct Node * DeleteLast(struct Node * tail)
{
    struct Node * newNode;
    if(tail == NULL)
        return tail;

    if(newNode == tail)
    {
        free(tail);
        tail = NULL;
        return tail;
    }
    newNode = tail->previous;
    newNode->next = tail->next;
    tail->next->previous = newNode;
    free(tail);
    tail=newNode;
    return tail;
}

struct Node * DeleteMiddle(struct Node * tail, int position)
{
    struct Node * newNode = tail->next;
    while(position > 1)
    {
        newNode = newNode->next;
        position--;
    }
    struct Node * newNode2 = newNode->previous;
    newNode2->next = newNode->next;
    newNode->next->previous =newNode2;
    free(newNode);
    if(newNode == tail)
        tail = newNode2;
    return tail;
}

void Search(struct Node * tail, int number)
    {
        if (tail->next == NULL)
        {
        	printf("List is empty");
        }
        else
        {
            struct Node * node = tail->next;
            do
            {
                if(number == node->data)
                    printf("Found instance of: %d \n", node->data);
                node = node->next;
            } while (node != tail->next);
        }
    }

void SearchDelete(struct Node * tail, int number)
    {
        if (tail == NULL)
        {
            printf("List is empty");
        }
        else
        {
            struct Node * node = tail->next;
            do
            {
                if(number == node->data)
                {
                    printf("Deleting instance of: %d ", node->data);
                    DeleteMiddle(tail, number);
                }

                node = node->next;
            } while (node != tail->next);
        }
    }

int Length(struct Node * tail)
    {
        int length=0;
        if (tail == NULL)
        {
            printf("List is empty");
        }
        else
        {
            struct Node * node = tail->next;
            do
            {
                length+=1;
                node = node->next;
            } while (node != tail->next);
        }
        printf("The length is: %d", length);
        return length;
    }

void DeleteAll(struct Node * tail)
    {
        int attempts = Length(tail);

        if (tail == NULL)
        {
            printf("List is empty");
        }
        else
        {
            struct Node * node = tail->next;
            do
            {
                for(int i; i<attempts; i++)
                {
                    DeleteFirst(tail);
                }

                node = node->next;
            } while (node != tail->next);
        }
        printf("\n The list has been deleted\n");
    }

void Print(struct Node * tail)
    {
    printf("\n");
        if (tail == NULL)
        {
            printf("List is empty");
        }
        else
        {
            struct Node * node = tail->next;
            do
            {
                printf("%d ", node->data);
                node = node->next;
            } while (node != tail->next);
        }
    printf("\n");
    }

int main()
{
    struct Node * LinkedList = NULL;
    LinkedList = AddForEmpty(30);
    LinkedList = AddAtStart(LinkedList, 20);
    LinkedList = AddAtEnd(LinkedList, 90);
    Print(LinkedList);
    printf("Enter a number of elements to add to the list: ");
    int times = scanf("%d", &times);
    ConsecutiveAdd(LinkedList, times);
    Print(LinkedList);
    Length(LinkedList);
    DeleteFirst(LinkedList);
    Search(LinkedList, 9);
    Print(LinkedList);
    DeleteLast(LinkedList);
    Print(LinkedList);
    DeleteMiddle(LinkedList, 3);
    Print(LinkedList);
    Search(LinkedList, 30);
    SearchDelete(LinkedList, 20);
    Print(LinkedList);
    DeleteAll(LinkedList);
    printf("\nIf 0 list is empty: ");
    Print(LinkedList);

    return 0;
}
