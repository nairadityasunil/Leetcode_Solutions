// Check if palindrome
#include <stdio.h>
#include <stdbool.h>
bool isPalindrome(int x)
{
    if (x > 0 || x==0)
    {
        int or = x;
        int rem = 0, rev = 0;
        while (x != 0)
        {
            rem = x % 10;
            rev = rev * 10 + rem;
            x = x / 10;
        }

        if (or == rev)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}
int main()
{
    int n;
    scanf("%d", &n);

    if (isPalindrome(n))
    {
        printf("Palindrome");
    }
    else
    {
        printf("Not Palindrome");
    }
    return 0;
}