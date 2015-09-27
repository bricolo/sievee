#***********************************************************************************
#************************************************************************************
#*    This file is a part of "sievee", a simple sieve of eratosthenes implementation
#*    Contact: bricolo.code@gmail.com
#*
#************************************************************************************
#************************************************************************************
#*
#*    Copyright (C) 2015 bricolo
#*    This program is free software: you can redistribute it and/or modify
#*    it under the terms of the GNU General Public License as published by
#*    the Free Software Foundation, either version 3 of the License, or
#*    (at your option) any later version.
#*
#*    This program is distributed in the hope that it will be useful,
#*    but WITHOUT ANY WARRANTY; without even the implied warranty of
#*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#*    GNU General Public License for more details.
#*
#*    You should have received a copy of the GNU General Public License
#*    along with this program.  If not, see <http://www.gnu.org/licenses/>.
#*
#**********************************************************************************/
#
#Makefile of sievee
sievee: sieve_of_eratosthenes.o main.o
	        gcc -o sievee sieve_of_eratosthenes.o main.o -lm

all: sievee sievee-w64.exe sievee-w32.exe

main.o: main.c sieve_of_eratosthenes.h
	        gcc -c -O3 main.c 
sieve_of_eratosthenes.o: sieve_of_eratosthenes.c sieve_of_eratosthenes.h
	        gcc -c -O3 sieve_of_eratosthenes.c
sievee.db: sieve_of_eratosthenes.c main.c sieve_of_eratosthenes.h
	        gcc -o sievee.db sieve_of_eratosthenes.do main.do -lm
main.do: main.c sieve_of_eratosthenes.h
	                gcc -o main.do -c -g -O3 main.c
sieve_of_eratosthenes.do: sieve_of_eratosthenes.c sieve_of_eratosthenes.h
	                gcc -o main.do -c -g -O3 sieve_of_eratosthenes.c

#cross compile for windows 32
sievee-w32.exe: sieve_of_eratosthenes.w32.o main.w32.o
	        i586-mingw32msvc-gcc -o sievee-w32.exe sieve_of_eratosthenes.w32.o main.w32.o -lm
main.w32.o: main.c sieve_of_eratosthenes.h
	        i586-mingw32msvc-gcc -o main.w32.o -c -O3 main.c 
sieve_of_eratosthenes.w32.o: sieve_of_eratosthenes.c sieve_of_eratosthenes.h
	        i586-mingw32msvc-gcc -o sieve_of_eratosthenes.w32.o -c -O3 sieve_of_eratosthenes.c

#cross compile for w64
sievee-w64.exe: sieve_of_eratosthenes.w64.o main.w64.o
	        x86_64-w64-mingw32-gcc -o sievee-w64.exe sieve_of_eratosthenes.w64.o main.w64.o -lm
main.w64.o: main.c sieve_of_eratosthenes.h
	        x86_64-w64-mingw32-gcc -o main.w64.o -c -O3 main.c 
sieve_of_eratosthenes.w64.o: sieve_of_eratosthenes.c sieve_of_eratosthenes.h
	        x86_64-w64-mingw32-gcc -o sieve_of_eratosthenes.w64.o -c -O3 sieve_of_eratosthenes.c

.PHONY: clean

clean:
	rm -f sievee sievee.db *.o *.do sievee-w*

