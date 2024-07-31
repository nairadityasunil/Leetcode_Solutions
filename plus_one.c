#include<stdio.h>
#include<stdlib.h>

// Will return 1d array
// *digits is the input array
// digitsize is the size of the input array
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    long int full_num = 0,i,new_arr_count=0,temp;

    for(i=0;i<digitsSize;i++)
    {
        full_num = (full_num *10) + digits[i];
    }
    full_num +=1;
    temp = full_num;

    while(temp!=0)
    {
        new_arr_count += 1;
        temp/=10;
    }
    
    int *new  = (int *)malloc(new_arr_count*sizeof(int));
    i=0;
    while(full_num!=0)
    {
        new[i] = full_num%10;
        full_num /= 10;
        i+=1;
    }
    
    
    int j =0;
    int *returnArr = (int *)malloc(new_arr_count * sizeof(int));
    for(i=new_arr_count-1;i>=0;i--)
    {
        returnArr[j] = new[i];
        j++;
    }
    
    for(int i=0;i<new_arr_count;i++)
    {
        printf("%d\t",returnArr[i]);
    }

    *returnSize = new_arr_count;
    return returnArr;
}

int main()
{
    int digits[] = {1,2,3};
    int digitsSize = sizeof(digits)/sizeof(int);
    int returnSize = 0;
    int *arr = plusOne(digits,digitsSize,&returnSize);
}