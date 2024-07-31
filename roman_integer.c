// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000


#include<stdio.h>
#include<string.h>

int get_val(char ch)
{
    if(ch == 'I')
        return 1;
    else if(ch == 'V')
        return 5;
    else if(ch == 'X')
        return 10;
    else if(ch == 'L')
        return 50;
    else if(ch == 'C')
        return 100;
    else if(ch == 'D')
        return 500;
    else if(ch == 'M')
        return 1000;

}

int main()
{
    char ch[15]="LVIII";
    int res=0, val1,val2;
    for(int i=0;i<strlen(ch);i++)
    {
        val1 = get_val(ch[i]);
        val2 = get_val(ch[i+1]);

        if(val2>val1)
        {
            res = res +(val2-val1);
            i++;
        }
        else
        {
            res = res+val1;
        }
    }
    printf("%d",res);
    return 0;
}