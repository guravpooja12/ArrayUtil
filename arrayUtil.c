#include <stdio.h>
#include "arrayUtil.h"
#include <stdlib.h>
#include <string.h>


struct ArrayUtil create(int size,int length){
	struct ArrayUtil newArray;
	newArray.size = size;
	newArray.length = length;
    newArray.basePtr =calloc(length, size);
	return newArray;
}

int areEqual(struct ArrayUtil a1,struct ArrayUtil a2){
	int i,flag = 0;
	if(a1.size == a2.size && a1.length == a2.length){
		flag = 1;
		for(i=0;i<(a1.size * a1.length);i++){
			if(((char *)a1.basePtr)[i] !=((char *)a2.basePtr)[i])
				flag = 0;
				break;
		}
	}
	return flag;

}

struct ArrayUtil resize(struct ArrayUtil a1,int newlength){
	void *arr1;
	int i;
	int lengthDiff = newlength - a1.length;
	int newSize = a1.size * newlength;
	a1.basePtr = realloc(a1.basePtr,newSize);
	arr1 = a1.basePtr;
	if(lengthDiff > 0){
		for (i = a1.length; i < newlength; i++)
		{
			((int *)(arr1))[i] = 0;
		}
		a1.length = newlength;
	}
	a1.length = newlength;
	return a1;
}
