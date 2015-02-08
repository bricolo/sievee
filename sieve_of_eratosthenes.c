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
int sieve_of_eratosthenes(int size)
{
      int length = size;
      if(size < 3){ 
	return(-2);
	}
      int i;
	int* array_condition;
	int* send_array;
	int i1, i2, result;
	double length1 = (double)length;
	int sqrt_length = (int)(sqrt(length1)+1);
	if ( NULL == (array_condition = (int *)malloc((length+1) * sizeof(int))) ) {
		printf("malloc failed2\n");
		return(-1);
	}
	
	for(i1=0; i1<=length; i1++){
		array_condition[i1] = 1;
	}
	array_condition[0] = 0;
	for(i1=2; i1<sqrt_length; i1++){
		if(array_condition[i1] == 1){
			for(i2=2; i2<length; ++i2){
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
	if ( NULL == (send_array = (int *)malloc(size * sizeof(int))) ) {
		printf("malloc failed\n");
		return(-1);
	}
	i2 = 0;
	for(i1=0; i1<=length; ++i1){
		if(array_condition[i1] == 1){
			if(i2<size){
		    	send_array[i2] = i1;
			}
			++i2;
		}
	}
	free(array_condition);
        
      for(i=0; i<size; i++){
    	printf("%d\n",send_array[i]);
      }
      free(send_array);
    return(0);    
}
