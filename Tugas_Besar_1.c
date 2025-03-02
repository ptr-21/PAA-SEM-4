#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

void penukaranUang()
{
    int n, i, j, amount, choice;
    printf("Enter the number of coins: ");
    scanf("%d", &n);
    int val[n];
    printf("Enter the values of coins: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &val[i]);
    }
    printf("Enter the amount to exchange: ");
    scanf("%d", &amount);
    printf("\nChoose method:\n");
    printf("1. Brute Force\n");
    printf("2. Greedy\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        int dp[amount + 1];
        int coin[amount + 1];
        int count[n];

        for (i = 0; i < n; i++)
        {
            count[i] = 0;
        }
        
        for (i = 0; i <= amount; i++)
        {
            dp[i] = INT_MAX;
            coin[i] = -1; // Inisialisasi agar tidak ada akses array kosong
        }
        dp[0] = 0;

        for (i = 1; i <= amount; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (i >= val[j] && dp[i - val[j]] != INT_MAX && dp[i - val[j]] + 1 < dp[i])
                {
                    dp[i] = dp[i - val[j]] + 1;
                    coin[i] = j;
                }
            }
        }

        if (dp[amount] == INT_MAX)
        {
            printf("Mohon Maaf, tidak ada kombinasi koin yang bisa mencapai jumlah uang yang diminta.\n");
            return;
        }

        printf("Minimum coins required: %d\n", dp[amount]);
        printf("Koin yang digunakan:\n");
        
        int temp_amount = amount;
        while (temp_amount > 0 && coin[temp_amount] != -1)
        {
            count[coin[temp_amount]]++;
            temp_amount -= val[coin[temp_amount]];
        }

        for (i = 0; i < n; i++)
        {
            if (count[i] > 0)
            {
                printf("Koin %d sebanyak %d kali\n", val[i], count[i]);
            }
        }
    }
    else if (choice == 2)
    {
        // Implementasi algoritma greedy
        int count[n];
        for (i = 0; i < n; i++)
        {
            count[i] = 0;
        }

        int remainingAmount = amount;
        for (i = n - 1; i >= 0; i--) // Mulai dari koin terbesar
        {
            while (remainingAmount >= val[i])
            {
                remainingAmount -= val[i];
                count[i]++;
            }
        }

        if (remainingAmount > 0)
        {
            printf("Greedy method gagal menemukan solusi yang optimal.\n");
        }
        else
        {
            printf("Koin yang digunakan:\n");
            for (i = 0; i < n; i++)
            {
                if (count[i] > 0)
                {
                    printf("Koin %d sebanyak %d kali\n", val[i], count[i]);
                }
            }
        }
    }
    else
    {
        printf("Pilihan tidak valid.\n");
    }
}

void penjadwalan() 
{
    printf("Fitur penjadwalan belum diimplementasikan.\n");
}

void knapsackProblem()
{
    int capacity, item, i;
    printf("Enter the capacity of knapsack: ");
    scanf("%d", &capacity);
    printf("Enter the number of items: ");
    scanf("%d", &item);
    
    int weight[item], value[item];

    printf("Enter the values and weights of items:\n");
    for (i = 0; i < item; i++)
    {
        printf("Item %d - Value: ", i + 1);
        scanf("%d", &value[i]);
        printf("Item %d - Weight: ", i + 1);
        scanf("%d", &weight[i]);
    }

    printf("Fitur Knapsack Problem belum selesai diimplementasikan.\n");
}

int main()
{
    printf("Menu\n");
    printf("1. Exchange coins\n");
    printf("2. Job Scheduling\n");
    printf("3. Knapsack Problem\n");
    printf("Enter your choice: ");
    
    int pilihan;
    scanf("%d", &pilihan);

    switch (pilihan)
    {
    case 1:
        penukaranUang();
        break;
    case 2:
        penjadwalan();
        break;
    case 3:
        knapsackProblem();
        break;
    default:
        printf("Pilihan tidak valid.\n");
        break;
    }

    return 0;
}
