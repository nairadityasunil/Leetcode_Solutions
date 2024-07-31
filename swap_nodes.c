#include<stdio.h>
#include<stdlib.h>
struct ListNode {
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

struct ListNode* swapPairs(struct ListNode* head) {
    if(head == NULL)
    {
        return head;
    }
     struct ListNode *prev = NULL, *temp = head;
    head = head->next; 
    while(temp != NULL)
    {
        struct ListNode *temp2 = temp;
        struct ListNode *temp3 = temp->next;
        temp2->next = temp3->next;
        temp3->next = temp2;
        if (prev != NULL) {
            prev->next = temp3;
        }
        prev = temp2;
        temp = temp2->next;
    }
    return head;
}

int main()
{
    struct ListNode *head1,*head3;
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

    head3 = swapPairs(head1);
    display(head3);
}