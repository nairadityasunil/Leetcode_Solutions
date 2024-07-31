#include <stdio.h>
#include <stdlib.h>

// Structure for linked list
struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *create(int data)
{
    struct ListNode *new = (struct ListNode *)malloc(sizeof(struct ListNode));
    if (new == NULL)
    {
        printf("Memory allocation falied");
        return NULL;
    }
    new->val = data;
    new->next = NULL;
    return new;
}

void ins_last(struct ListNode *head, int data)
{
    struct ListNode *temp = head;
    // Traverse to last element
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    // Create new node at the end
    temp->next = create(data);
}

void display(struct ListNode *head)
{
    struct ListNode *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->val);
        temp= temp->next;
    }
}

// Merging two sorted lists
// Merging two sorted lists
struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2)
{
    // Create a dummy node to act as the starting point of the merged list
    struct ListNode dummy;
    dummy.next = NULL;
    struct ListNode *tail = &dummy;

    while (list1 != NULL && list2 != NULL)
    {
        if (list1->val < list2->val)
        {
            tail->next = list1;
            list1 = list1->next;
        }
        else
        {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    // If there are remaining nodes in either list, append them
    if (list1 != NULL)
    {
        tail->next = list1;
    }
    else
    {
        tail->next = list2;
    }

    return dummy.next;
}
    

int main()
{
    struct ListNode *head1,*head2,*head3;
    int n, element;

    // Creating list 1
    printf("Enter Value For Head Pointer of list1 : ");
    scanf("%d", &element);

    head1 = create(element);

    printf("Enter remaining number of elements in list 1 :");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter data for node : %d : ", i + 2);
        scanf("%d", &element);
        ins_last(head1, element);
    }

    // Creating list 2
    printf("\n\nEnter Value For Head Pointer of list2 : ");
    scanf("%d", &element);

    head2 = create(element);

    printf("Enter remaining number of elements in list 2 :");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter data for node : %d : ", i + 2);
        scanf("%d", &element);
        ins_last(head2, element);
    }

    head3 = mergeTwoLists(head1,head2);
    display(head3);
}