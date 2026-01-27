#include<stdio.h>

int main()
{
    int i, n, a[10], temp;

    printf("Enter the sequence length (<10): ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter the value for index %d: ", i);
        scanf("%d", &a[i]);
    }

    // Reverse the array
    for(i = 0; i < n / 2; i++)
    {
        temp = a[i];
        a[i] = a[n - i - 1];
        a[n - i - 1] = temp;
    }

    // Print reversed array
    printf("\nReversed Array:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }

    return 0;
}

