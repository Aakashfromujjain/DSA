#include<stdio.h>

int main()
{
    int i, j, count;

    for (j = 1; j <= 300; j++)
    {
        count = 0; // Reset count at the start of each j loop
        for (i = 1; i <= 300; i++)
        {
            if (j % i == 0)
            {
                count++;
            }
        }

        if (count == 2)
        {
            printf("%d\t", j);
        }
    }
    return 0;
}

