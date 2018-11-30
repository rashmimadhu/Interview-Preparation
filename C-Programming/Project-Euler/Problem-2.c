#include<stdio.h>

void fib()
{
    int num1 = 0, num2 = 1, sum = 0, num = 0;

    while(num < 4000000)
    {
        num = num1 + num2;
        num1 = num2;
        num2 = num;
        if(num % 2 == 0)
            sum += num;
    }
    printf("%d\n", sum);
}

int main()
{
    fib();
    return 0;
}
