#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int AVG, MAX, MIN, NUMARGS;

void *average(void *param);
void *maximum(void *param);
void *minimum(void *param);

int main(int argc, char *argv[])
{

    pthread_t tidAVG;
    pthread_t tidMAX;
    pthread_t tidMIN;
    NUMARGS = argc - 1;

    if (NUMARGS < 1)
    {
        printf("No data provided. Exiting. \n");
        return 0;
    }

    int *array = malloc(NUMARGS * sizeof(int));

    for(int i = 0; i < NUMARGS; i++){
      array[i] = atoi(argv[i+1]);
  //    printf("Loading array: %d\n", array[i]);
    }

    pthread_create(&tidAVG, 0, average, array);
    pthread_create(&tidMAX, 0, maximum, array);
    pthread_create(&tidMIN, 0, minimum, array);

    pthread_join(tidAVG, NULL);
    pthread_join(tidMAX, NULL);
    pthread_join(tidMIN, NULL);

    printf("The average value is %d \n", AVG);
    printf("The minimum value is %d \n", MIN);
    printf("The maximum value is %d \n", MAX);

    free(array);
    return 0;
}


void *average(void *param)
{
    int sum = 0;
    int *arr = (int *)param;
//    printf("\nConfirming NUMARGS: %d\n", NUMARGS);
    for (int i = 0; i < NUMARGS; i++)
    {
        sum += arr[i];
  //      printf("Summing array: +%d ", arr[i]);
    }

    AVG = sum / NUMARGS;
    pthread_exit(0);
}

void *maximum(void *param)
{
    int *arr = (int *)param;
    int max = arr[0];

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
    int *arr = (int *)param;
    int min = arr[0];

    for (int i = 0; i < NUMARGS; i++)
    {
        if (min > arr[i])
        {
            min = arr[i];
        }
    }

    MIN = min;
    pthread_exit(0);
}
