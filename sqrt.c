#include<stdio.h>
int mySqrt(int x) {
    int start =0,end = x,mid;
    while(start <= end)
    {
        mid = (start+end)/2;
        if (mid * mid == x) {
            // Perfect Square
            return mid;
        } else if (mid * mid < x) {
            start = mid +1 ;
            printf("\n%d\n",start);
        } else {
            end = mid-1 ;
        }
    }
    return end;
}
int main()
{
    int num =8;
    printf("%d",mySqrt(num));
    return 0;
}