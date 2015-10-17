/************************************************************************************
*************************************************************************************
**    This file is a part of "sievee", a simple sieve of eratosthenes implementation
**    Contact: bricolo.code@gmail.com
**
*************************************************************************************
*************************************************************************************
**
**    Copyright (C) 2015 bricolo
**    This program is free software: you can redistribute it and/or modify
**    it under the terms of the GNU General Public License as published by
**    the Free Software Foundation, either version 3 of the License, or
**    (at your option) any later version.
**
**    This program is distributed in the hope that it will be useful,
**    but WITHOUT ANY WARRANTY; without even the implied warranty of
**    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**    GNU General Public License for more details.
**
**    You should have received a copy of the GNU General Public License
**    along with this program.  If not, see <http://www.gnu.org/licenses/>.
**
***********************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include <math.h>

#include "sieve_of_eratosthenes.h"

//define bit manipulation macro (thanks to
//http://mathcs.emory.edu/~cheung/Courses/255/Syllabus/1-C-intro/bit-array.html
//)
/*
#define SetBit(A,k) (A[(k/32)] |= (1<<(k%32)))
#define ClearBit(A,k) (A[(k/32)] &= ~(1 << (k%32)))
#define TestBit(A,k) (A[(k/32)] & (1 << (k%32)))
*/
//char array
#define SetBit(A,k) (A[(k/8)] |= (1<<(k%8)))
#define ClearBit(A,k) (A[(k/8)] &= ~(1 << (k%8)))
#define TestBit(A,k) (A[(k/8)] & (1 << (k%8)))

//sieve of erastosthenes function 
long long * sieve_of_eratosthenes(long long size)
{
      long long length = size;
// stop if n<3 -> no need to calc
    if(size < 3){ 
        return((long long *)-2);
	}

    //array filled with 0 or 1
	unsigned char* array_condition;
    //array to return
	long long * send_array;
	long long i1, i2, result;
	double length1 = (double)length;
	long long sqrt_length = (long long)(sqrt(length1)+1);
    long long to_alloc = (length+1)/8;
    to_alloc = to_alloc + (8-(to_alloc%8)) + 2;
	if ( NULL == (array_condition = (unsigned char *)malloc(to_alloc * sizeof(unsigned char))) ) {
		printf("malloc failed2\n");
		return((long long *)-1);
	}

    //init whole array to 1
	for(i1=0; i1<=length; i1++){
		//array_condition(char *)|=(1<<i1);
        SetBit(array_condition, i1);
	}
    //while i<sqrt(n)
	for(i1=2; i1<sqrt_length; i1++){
        //if i1 is a prime number
		if(TestBit(array_condition,i1)){
            //for each i from 2 to length
			for(i2=2; i2<length; ++i2){
                //calc i1*i2 and pass th cel of the array to 0 (not a prime)
				result = (i1)*i2;
				if(result<=length){
					if(TestBit(array_condition, result)){
				    	//array_condition&=~(1<<result);
                        ClearBit(array_condition,result);
					size=size-1;
					}
				}
			}
		}
	}
    //add 1 to size [0] get errors or length of the table
	if ( NULL == (send_array = (long long *)malloc((size) * sizeof(long long))) ) {
		printf("malloc failed\n");
		return((long long *)-1);
	}
    send_array[0] = size;
	i2 = 1;
	for(i1=2; i1<=length; ++i1){
		if(TestBit(array_condition,i1)){
			if(i2<size){
		    	send_array[i2] = i1;
			}
			++i2;
		}
	}
	free(array_condition);
        
//      free(send_array);
    return(send_array);    
}

int print_array(long long * myarray)
{
    long long i;
    long long size_array = myarray[0];
    for(i=1; i<size_array; i++){
    printf("%lld\n",myarray[i]);
    }
    return(0);
}

int primestofile(long long * myarray)
{
    int i;
    int size_array = myarray[0];
    FILE * fp;
    fp = fopen("primes1.txt", "a");
    for( i=1; i<size_array; i++){
        fprintf(fp, "%lld\n", myarray[i]);
    }
    return(0);
}
