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
//include library
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <math.h>

#include "sieve_of_eratosthenes.h"
//define const
#define PROGRAM_NAME "sievee"

#define HELP "Use: sievee [number]\nwith number>2\n" 

int main( int argc, char **argv)
{
    if((argc == 2) && (atoi(argv[1]) > 2)){
	int number = atoi(argv[1]);
    	int * primes= 0;
	primes = sieve_of_eratosthenes(number);
	//can handle error
    }
    else{
	printf(HELP);
    }
    return(0);    
}
