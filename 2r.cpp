#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shell(int* items, int count)
{
    int i, j, gap, k;
    int x, a[5];

    a[0] = 9; a[1] = 5; a[2] = 3; a[3] = 2; a[4] = 1;

    for (k = 0; k < 5; k++) {
        gap = a[k];
        for (i = gap; i < count; ++i) {
            x = items[i];
            for (j = i - gap; (x < items[j]) && (j >= 0); j = j - gap)
                items[j + gap] = items[j];
            items[j + gap] = x;
        }
    }
}

void qs(int* items, int left, int right) //вызов функции: qs(items, 0, count-1);
{
    int i, j;
    int x, y;

    i = left; j = right;

    /* выбор компаранда */
    x = items[(left + right) / 2];

    do {
        while ((items[i] < x) && (i < right)) i++;
        while ((x < items[j]) && (j > left)) j--;

        if (i <= j) {
            y = items[i];
            items[i] = items[j];
            items[j] = y;
            i++; j--;
        }
    } while (i <= j);

    if (left < j) qs(items, left, j);
    if (i < right) qs(items, i, right);
}

void main()
{
    clock_t start, end;
    int i = 0, j = 0, r, min = -100, max = 100, c = 6000;
    int mas1[6000], mas2[6000], mas3[6000], mas4[6000];
    for (int i = 0; i < c; i++)
    {
        mas1[i] = min + rand() % (max - min + 1);
        mas2[i] = i;
        mas3[i] = c - i;

        if (i <= c / 2)
        {
            mas4[i] = i;
        }
        else
        {
            mas4[i] = c - i;
        }
    }

    clock_t starttime, endtime;

    starttime = clock();
    shell(mas1, c);
    endtime = clock();
    float t = (float)(endtime - starttime) / (float)CLOCKS_PER_SEC;
    printf("shell1: %f\n", t);

    for (int i = 0; i < c; i++)
    {
        mas1[i] = min + rand() % (max - min + 1);
    }

    starttime = clock();
    qs(mas1, 0, c - 1);
    endtime = clock();
    t = (float)(endtime - starttime) / (float)CLOCKS_PER_SEC;
    printf("qs1: %f\n", t);

    starttime = clock();
    shell(mas2, c);
    endtime = clock();
    t = (float)(endtime - starttime) / (float)CLOCKS_PER_SEC;
    printf("shell2: %f\n", t);

    for (int i = 0; i < c; i++)
    {
        mas2[i] = i;
    }

    starttime = clock();
    qs(mas2, 0, c - 1);
    endtime = clock();
    t = (float)(endtime - starttime) / (float)CLOCKS_PER_SEC;
    printf("qs2: %f\n", t);

    starttime = clock();
    shell(mas3, c);
    endtime = clock();
    t = (float)(endtime - starttime) / (float)CLOCKS_PER_SEC;
    printf("shell3: %f\n", t);

    for (int i = 0; i < c; i++)
    {
        mas3[i] = c - i;
    }

    starttime = clock();
    qs(mas3, 0, c - 1);
    endtime = clock();
    t = (float)(endtime - starttime) / (float)CLOCKS_PER_SEC;
    printf("qs3: %f\n", t);

    starttime = clock();
    shell(mas4, c);
    endtime = clock();
    t = (float)(endtime - starttime) / (float)CLOCKS_PER_SEC;
    printf("shell4: %f\n", t);

    for (int i = 0; i < c; i++)
    {
        if (i <= c / 2)
        {
            mas4[i] = i;
        }
        else
        {
            mas4[i] = c - i;
        }
    }

    starttime = clock();
    qs(mas4, 0, c - 1);
    endtime = clock();
    t = (float)(endtime - starttime) / (float)CLOCKS_PER_SEC;
    printf("qs4: %f\n", t);
}