#include <stdio.h>

void bubbleSort(int array[], int len)
{
    int i, j, temp;
    for (i = 0; i < len - 1; i++)
    {
        for (j = 0; j < len - 1 - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void printArray(int array[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    printf("Sort Algorithm end!\n");
}

int main()
{
    printf("this is BubbleSort!\n");
    int array[] = { 3, 5, 1, 34, 65, 3, 7, 8, 5, 4, 23 };
    int len = sizeof(array) / sizeof(array[0]);
    bubbleSort(array, len);
    printArray(array, len);
    return 0;
}
