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

// Add elements of 2 lists
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *temp1,*temp2,*temp3;
    int list1_count,list2_count,l1_val=0,l2_val=0,rev=0,rem,add,leading1=0,leading2=0;
    temp1 = l1;
    temp2 = l2;


    // Merging all elements of list1
    while(temp1!=NULL)
    {

        l1_val = (l1_val*10) + temp1->val;
        temp1 = temp1->next;
    }

    while(temp2!=NULL)
    {
        l2_val = (l2_val*10) + temp2->val;
        temp2 = temp2->next;
    }

    // Reversing the elements of list1
    while(l1_val != 0)
    {
        rem = l1_val%10;
        rev = (rev*10)+rem;
        l1_val /= 10;
    }

    l1_val = rev;
    rev =0;

    // Reversing the elements of l2
    while(l2_val != 0)
    {
        rem = l2_val%10;
        rev = (rev*10)+rem;
        l2_val /= 10;
    }
    l2_val = rev;

    printf("\n\n%d\n%d\n\n",l1_val,l2_val);
    add = l1_val+l2_val;
    rem = add%10;
    add = add/10;
    struct ListNode *result = create(rem);
    while(add!=0)
    {
        rem = add%10;
        ins_last(result,rem);
        add = add/10;
    }

    return result;
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

    head3 = addTwoNumbers(head1,head2);
    display(head3);
}