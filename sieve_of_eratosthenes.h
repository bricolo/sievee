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
//  header of sieve_of_eratosthenes.c
#ifndef SIEVE_OF_ERATOSTHENES_H
#define SIEVE_OF_ERATOSTHENES_H

#define FILENAME "prime.txt"
#define FILENAMEARRAY "prime_array.txt"
//each array of long use his [0] as a counter -> use it as for( ; <array[0];)

extern unsigned char * sieve_of_eratosthenes(long long size);
//create a array of unsigned char, each bit turned 1 at a position flag this
//position as prime

extern long long number_of_prime(unsigned char * condition_array, long long size);
//return the number of prime numbers found in condition_array

extern int array_to_file(unsigned char * condition_array, long long size);
//print the bit array in file

extern int primestofile(unsigned char * condition_array, long long size);
//print primes in a file

extern int printprimes(unsigned char * condition_array, long long size);
//display primes


//DEPRECATED

extern long long * create_long_array(unsigned char * condition_array, long long size);
//create table of long that contain each number mark as prime in
//condition_array
//!!!!can lead to "segmentation fault" -> asking for to much ram

extern int long_print_array(long long * myarray);
//print the long long array 

extern int long_primestofile(long long * myarray);
//print in file an array of long
#endif
