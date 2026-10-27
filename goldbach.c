/*Filename: goldbach.c | My appoach to this problem*/

#include <stdio.h>
#include <stdint.h> // Χργσιμοποιούμε αυτή τη βιβλιοθήκη γιατί έχουμε δηλώσει μεταβλητές των 64bit


int primes(uint64_t num) {  // Συνάρτηση primes που υπολογίζει πρώτους  
	uint64_t i;
	int flag = 1;
   	if (num == 2) {
      		flag = 1;
   	}
   	if (num == 3) {
      		flag = 1;
   	}
   	if (num % 2 == 0) {
      		flag = 0;
   	}
   	if (num % 3 == 0) {
      		flag = 0;
   	}
   	for(i = 3 ; i*i <= num ; i++) { // Βρόχος που ελέγχει αν υπάρχει διαιρέτης του num 
       		if (num % i == 0) {
             	flag = 0;
         	}
    	}
	return flag;
}



int gold(uint64_t num) {
	uint64_t p1;  // Ένας απο τους δύο πρώτους, το άθροισμα των οποιών μας δίνει το num
	uint64_t p2 = 3;  // Ο άλλος πρώτος αριθμός αρχικοποιείται με την τιμή 3, καθώς ο 2 ειναι άρτιος και θα εμποδίσει την πρώτη συνθήκη if
	for( p2 = 3 ; p2 < num ; p2 += 2) { // Το βήμα του βρόχου ειναι 2 και όχι 1 καθώς έτσι αποφελυγουμε τελείως την πιθανότητα να τύχουμε άρτιο αριθμό
		if (primes(p2) == 0) {
			continue;
		}
		else {
			if(primes(num - p2) == 0) {   // Χρήση της προηγούμενηγς συνάρτησης primes για να ελέγξουμε αν οι δύο αριθμοί p1, p2 είναι πρώτοι
				continue;
			}
			else {
				p1 = num - p2;
				break;
			}
		}
	}
	return p1;
}





int main () {
	uint64_t end_i = EOF;
	char end_c = EOF;
	while(1) {
      		uint64_t userin1;  // Χρησιμοποιούμε uint64_t για αριθμούς που δεν χωράνε σε 32 bit στο δυαδικό
      		int flag;
      		char userin2;
      		printf("Enter your number: ");
      		uint64_t scanner1 = scanf("%llu", &userin1);
		if (scanner1 == end_i) {
			printf("EOF detected, exiting\n");
			return 0;
			break;
                }
		else if (scanner1 != 1) {
			printf("Invalid input: expected an integer\n");
			return 1;
			break;
		}
      		printf("Enter your option ('p' for primes or 'g' for goldbach): " );
      		char scanner2 = scanf(" %c", &userin2);
		if (scanner2 == end_c) {
			printf("EOF detected, exiting\n");
		}
		if (userin2 == 'p') {
         		if (userin1 == 0) {
            			break;
         		}
         		if (userin1 < 2) {  // Για τιμές μικρότερες του δύο ο βρόχος εξετάζει νέες τιμές
            			continue;
         		}
         		flag = primes(userin1);
         		if (flag == 1) {
            			printf("%llu is prime\n", userin1);
         		}
         		else {
            			printf("%llu is not prime\n", userin1);
         		}
      		}
		if (userin2 == 'g') {
			uint64_t p1;  // Ορίζουμε όπως και στην συνάρτηηση gold τις μεταβλητές p1, p2 , το άθροισμα των οποιλων ειναι ο userin1
			uint64_t p2;
			if (userin1 == 4) { // Έχομυε ξεχωριστή περίπτωση για το 4 καθώς ο μικρότερος συνδυασμός πρώτων είναι μόνο το 2 όπου δημιουργελι θέμα στην συναρτησλη μας gold όπως αναφέραμε
				printf("4 = 2 + 2");
			}
			if (userin1 <= 2 || userin1 % 2 != 0) {
				printf("Goldbach's conjecture is applicableonly to even numbers greater than 2!\n");
			}
			else {
				p1 = gold(userin1);
				p2 = userin1 - p1;
				printf("%llu = %llu + %llu\n", userin1, p1, p2);
			}
		}
   	}
	return 0;
}
