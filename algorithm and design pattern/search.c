//
//  search.c
//  test-c
//
//  Created by o8q on 2017/09/17.
//  Copyright © 2017年 o8q. All rights reserved.
//

#include "search.h"


int compare(int x, int y) {
    return x - y;
}

// data has been already sorted.
// if data is not sorted, it's doesn't work as you expected.
int binSearch(int data[], int length, int val){
    int first = 0;
    int last = length - 1;
    int mid, result;
    int n = 0;
    
    while(first <= last){
        n++;
        mid = (first + last) / 2;
        printf("it's a [%d] times. first[%d], last[%d], mid[%d].\n", n, first, last, mid );
        if(0 == (result = compare(val, data[mid])))
            return mid;
        if(0 < result) {
            first = mid + 1;
            continue;
        }
        last = mid - 1;
    }
    return -1;
}

// attention! take care of 0 divide,
// and return smaller element's number.
int guessPosition(int data[], int first, int last, int val){
    if (data[first] == data[last])
        return first;
    return (val - data[first]) * (last - first)  / (data[last] - data[first]) + first;
}

// not very god... It could be better.
// I'm not good at math.
int interSearch(int data[], int length, int val){
    int first = 0;
    int last = length - 1;
    int place, result;
    int n = 0;
    
    while(first <= last){
        // out of bounds. in case data[first] and data[last] has same value.
        if (val < data[first] || val > data[last])
            return -1;
        n++;
        place = guessPosition(data, first, last, val);
        printf("it's a [%d] times. first[%d], last[%d], place[%d].\n", n, first, last, place );
        if(0 == (result = compare(val, data[place])))
            return place;
        if(0 < result) {
            first = place + 1;
            continue;
        }
        last = place -1;
    }
    return -1;
}
