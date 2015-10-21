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
//for int bit array
#define SetBit(A,k) (A[(k/32)] |= (1<<(k%32)))
#define ClearBit(A,k) (A[(k/32)] &= ~(1 << (k%32)))
#define TestBit(A,k) (A[(k/32)] & (1 << (k%32)))
*/
//char bit array
#define SetBit(A,k) (A[(k/8)] |= (1<<(k%8)))
#define ClearBit(A,k) (A[(k/8)] &= ~(1 << (k%8)))
#define TestBit(A,k) (A[(k/8)] & (1 << (k%8)))

//sieve of erastosthenes function 
unsigned char * sieve_of_eratosthenes(long long size)
{
      long long length = size;
// stop if n<3 -> no need to calc
    if(size < 3){ 
        return((unsigned char *)-2);
	}

    //array filled with 0 or 1
	unsigned char* array_condition;
    //array to return
//	long long * send_array;
	long long i1, i2, result;
	double length1 = (double)length;
	long long sqrt_length = (long long)(sqrt(length1)+1);
    long long to_alloc = (length+1)/8;
    to_alloc = to_alloc + (8-(to_alloc%8)) + 2;
	if ( NULL == (array_condition = (unsigned char *)malloc(to_alloc * sizeof(unsigned char))) ) {
		printf("malloc failed2\n");
		return((unsigned char *)-1);
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
					//if(TestBit(array_condition, result)){
				    	//array_condition&=~(1<<result);
                        ClearBit(array_condition,result);
					//size=size-1;
					//}
				}
			}
		}
	}
    return(array_condition);
    /*
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
    */
}


long long number_of_prime(unsigned char * condition_array, long long size)
{
    long long nprimes = 0;
    long long i1;
	for(i1=2; i1<=size; ++i1)
    {
		if(TestBit(condition_array,i1))
        {
            nprimes++;
        }
	}

    return(nprimes);    
}

int array_to_file(unsigned char * condition_array, long long size)
{
    long long i;
    FILE* fp;
    fp = fopen(FILENAMEARRAY, "w");
    for(i=1; i<size; i++){
		if(TestBit(condition_array,i))
        {
            fprintf(fp, "1");
        }
        else
        {
            fprintf(fp, "0");
        }
    }
    return(0);
}

int primestofile(unsigned char * condition_array, long long size)
{
    long long i;
    FILE* fp;
    fp = fopen(FILENAME, "w");
    for(i=1; i<size; i++){
		if(TestBit(condition_array,i))
        {
            fprintf(fp, "%lld\n", i);
        }
    }
    return(0);
}

int printprimes(unsigned char * condition_array, long long size)
{
    long long i;
    for(i=1; i<size; i++){
		if(TestBit(condition_array,i))
        {
            printf("%lld\n", i);
        }
    }
    return(0);
}

long long * create_long_array(unsigned char * condition_array, long long size)
{
    long long i1, i2;
    long long * send_array;
    //add 1 for the array size in [0]
    long long nprimes = 1+number_of_prime(condition_array, size);
	if ( NULL == (send_array = (long long *)malloc((nprimes) * sizeof(long long))) ) {
		printf("malloc failed\n");
		return((long long *)-1);
	}
    send_array[0] = nprimes;
	i2 = 1;
	for(i1=2; i1<=size; ++i1){
		if(TestBit(condition_array,i1)){
			if(i2<size){
		    	send_array[i2] = i1;
			}
			++i2;
		}
	}

    return(send_array);    
}

int long_print_array(long long * myarray)
{
    long long i;
    long long size_array = myarray[0];
    for(i=1; i<size_array; i++){
    printf("%lld\n",myarray[i]);
    }
    return(0);
}


int long_primestofile(long long * myarray)
{
    int i;
    int size_array = myarray[0];
    FILE * fp;
    fp = fopen(FILENAME, "a");
    for( i=1; i<size_array; i++){
        fprintf(fp, "%lld\n", myarray[i]);
    }
    return(0);
}

