#include<stdio.h>
unsigned long long factorial(int n){
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        return n * factorial(n-1);
    }
}
int main(int argc, char const *argv[])
{
    int num;
    printf("Masukkan bilangan untuk menghitung faktorial: ");
    scanf("%d\n", &num);
    unsigned long long result = factorial(num);
    printf("Faktorial dari %d adalah: %llu\n", num, result);
    return 0;
}
