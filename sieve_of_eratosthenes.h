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

extern int * sieve_of_eratosthenes(int size);
//return[0]= length of the array = success
//return[0]=-1 = memory allocation failled
//return[0]=-2 = bad number given

extern int print_array(int * myarray);
#endif
