// Longest Substring without repeating characters

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int lengthOfLongestSubstring(char* s) {
    // printf("%s",s);
    char str[10000];
    int i = 0,j,duplicate = 0,k=0,count=0;
    // Checking each character
    int n = strlen(s);
    // printf("%d",n);
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if(s[i]==s[j])
            {
                duplicate++;
                break;
            }
        }
        count++;
    }
    printf("%d",count);
}
int main()
{
    char str[10000];
    printf("Enter String : ");
    scanf(" %s",str);

    lengthOfLongestSubstring(str);
    return 0;
}