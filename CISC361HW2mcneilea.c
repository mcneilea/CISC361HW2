#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int AVG, MAX, MIN, NUMARGS;

void *average(void *param)
{
    int sum = 0;
    int *arr = (int *)param;

    for (int i = 0; i < NUMARGS; i++)
    {
        sum += arr[i];
    }

    AVG = sum / NUMARGS;
    pthread_exit(0);
}

void *maximum(void *param)
{
    int max = 0;
    int *arr = (int *)param;

    for (int i = 0; i < NUMARGS; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }

    MAX = max;
    pthread_exit(0);
}

void *minimum(void *param)
{
    int min = 0;
    int *arr = (int *)param;

    for (int i = 0; i < NUMARGS; i++)
    {
        if (min < arr[i])
        {
            min = arr[i];
        }
    }

    MIN = min;
    pthread_exit(0);
}

int main(int argc, char *argv[])
{

    pthread_t tidAVG;
    pthread_t tidMAX;
    pthread_t tidMIN;
    NUMARGS = argc - 1;

    if (NUMARGS < 1)
    {
        printf("No data provided. Exiting.");
        return 0;
    }

    int *array = malloc(NUMARGS * sizeof(int));

    pthread_create(&tidAVG, 0, average, array);
    pthread_create(&tidMAX, 0, maximum, array);
    pthread_create(&tidMIN, 0, minimum, array);

    printf("The average value is %f", AVG);
    printf("The average value is %f", MIN);
    printf("The average value is %f", MAX);

    free(array);
    return 0;
}
