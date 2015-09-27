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
//sieve of erastosthenes function 
int * sieve_of_eratosthenes(int size)
{
      int length = size;
// stop if n<3 -> no need to calc
    if(size < 3){ 
        return((int *)-2);
	}

    int i;
    //array filled with 0 or 1
	char* array_condition;
    //array to return
	int* send_array;
	int i1, i2, result;
	double length1 = (double)length;
	int sqrt_length = (int)(sqrt(length1)+1);
	if ( NULL == (array_condition = (char *)malloc((length+1) * sizeof(char))) ) {
		printf("malloc failed2\n");
		return((int *)-1);
	}

    //init whole array to 1
	for(i1=0; i1<=length; i1++){
		array_condition[i1] = 1;
	}
    //eliminate 1 from the list
	array_condition[0] = 0;
	for(i1=2; i1<sqrt_length; i1++){
        //if i1 is a prime number
		if(array_condition[i1] == 1){
            //for each i from 2 to length
			for(i2=2; i2<length; ++i2){
                //calc i1*i2 and pass th cel of the array to 0 (not a prime)
				result = (i1)*i2;
				if(result<=length){
					if(array_condition[result] == 1){
				    	array_condition[result] = 0;
					size=size-1;
					}
				}
			}
		}
	}
    //add 1 to size [0] get errors or length of the table
    size = size+1;
	if ( NULL == (send_array = (int *)malloc((size) * sizeof(int))) ) {
		printf("malloc failed\n");
		return((int *)-1);
	}
    send_array[0] = size;
	i2 = 1;
	for(i1=0; i1<=length; ++i1){
		if(array_condition[i1] == 1){
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

int print_array(int * myarray)
{
    int i;
    int size_array = myarray[0];
    for(i=1; i<size_array; i++){
    printf("%d\n",myarray[i]);
    }
    return(0);
}
