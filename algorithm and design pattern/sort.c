//
//  sort.c
//  test-c
//
//  Created by o8q on 2017/09/12.
//  Copyright © 2017年 o8q. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

// can't compute the length of array. . . [sizeof(array) / sizeof(array[0])]
int insertSort(int data[], int length){
    int ins, tmp, n;
    n = 0;
    for (int pos = 1; pos < length; pos++){
        ins = pos;
        while(ins >= 1 && data[ins - 1] > data[ins]){
            tmp = data[ins - 1];
            data[ins - 1] = data[ins];
            data[ins] = tmp;
            ins--;
            n++;
        }
    }
    return n;
}

int insSort(int data[], int length){
    int cmp;
    int tmp;
    int n = 0;
    
    for (int pos = 1; pos < length; pos++){
        for (cmp = pos - 1; cmp >= 0; cmp--){
            n++;
            if(data[cmp] > data[cmp + 1]){
                tmp = data[cmp];
                data[cmp] = data[cmp + 1];
                data[cmp + 1] = tmp;
                continue;
            }
            // Array has been already sorted.
            break;
        }
    }
    return n;
}

// not bad.
int insSortGap(int data[], int length, int gap){
    int cmp;
    int tmp;
    int n = 0;
    
    for (int pos = gap; pos < length; pos++){
        for (cmp = pos - gap; cmp >= 0; cmp -= gap){
            n++;
            if(data[cmp] > data[cmp + gap]){
                tmp = data[cmp];
                data[cmp] = data[cmp + gap];
                data[cmp + gap] = tmp;
                continue;
            }
            // Array has been already sorted.
            break;
        }
    }
    return n;
}

// finally gap is going to be one.
// take care of gap number when gap is smaller than base number.
int shellSort(int data[], int length, int base){
    int n = 0;
    
    for (int gap = length / base; gap > 0; gap /= base) {
        printf("gap is [%d].\n",gap);
        n += insSortGap(data, length, gap);
        if(gap > 1 && gap < base)
            gap = base;
    }
    return n;
}

int baseValue(int data[], int first, int last, int mid){
    return (data[first] + data[last] + data[mid]) / 3;
}

void swap(int data[], int x, int y) {
    int tmp = data[x];
    data[x] = data[y];
    data[y] = tmp;
}

void quickSort(int data[], int first, int last){
    int mid = first + (last - first) / 2;
    int pivot = data[mid];
    int iFirst = first;
    int iLast = last;
    
    if(first >= last)
        return;

    while (1) {
        while (pivot > data[iFirst])
            iFirst++;
        while(pivot < data[iLast])
            iLast--;
        if (iFirst >= iLast)
            break;
        swap(data, iFirst, iLast);
        iFirst++;
        iLast--;
    }
    printf("quick sort first[%d], last[%d], iFirst[%d], iLast[%d], mid[%d].\n", first, last, iFirst, iLast, mid);
    quickSort(data, first, iFirst - 1);
    quickSort(data, iLast + 1, last);
}
