//
//  main.c
//  algorithm and design pattern
//
//  Created by o8q on 2017/09/19.
//  Copyright © 2017年 o8q. All rights reserved.
//

#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"
#include "search.h"


void showArray(int data[], int length){
    printf("------------------------------------------------------------------------\n");
    for (int i = 0; i < length; i++){
        printf("array's value is [%d][%d].\n", i, data[i]);
    }
    printf("------------------------------------------------------------------------\n");
}

void createSample(int data[], int length){
    srand((unsigned int)time(NULL));
    for(int i = 0; i < length; i++){
        data[i] = rand() % length;
    }
}

int main(int argc, const char * argv[]) {

    // insertSearch, shellSort, quickSort
    int length = 100;
    int data[length];
    int count;
    createSample(data,length);
    showArray(data, length);
    //count = shellSort(data, length, 3);
    quickSort(data, 0, length - 1);
    printf("execution count [%d].\n", count);
    showArray(data, length);
    
    // binSearch
    //    int data[10] = {13,27,33,39,48,52,61,65,74,86};
    //    int val = 61;
    //    printf("binSearch result[%d].\n",binSearch(data, 10, val));
    
    
    // interSearch
    //    int length = 100;
    //    int data[length];
    //    int count;
    //    createSample(data,length);
    //    count = insertSort(data,length);
    //    showArray(data, length);
    //    int val = 61;
    //    printf("intSearch result[%d].\n",interSearch(data, 100, val));
    
    return 0;
}
