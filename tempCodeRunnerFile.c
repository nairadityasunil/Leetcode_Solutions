int full_num = 0,i,new_arr_count=0,temp;

    for(i=0;i<digitsSize;i++)
    {
        full_num = (full_num *10) + digits[i];
    }
    full_num +=1;
    temp = full_num;
    i=0;
    while(temp!=0)
    {
        new_arr_count += 1;
    }
    
    int *new  = (int *)malloc(new_arr_count*sizeof(int));
    i=0;
    while(full_num!=0)
    {
        new[i] = full_num%10;
        full_num /= 10;
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
    return returnArr;