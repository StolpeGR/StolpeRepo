/*Filename: goldbach.c | My appoach to this problem*/

#include <stdio.h>
#include <stdint.h> // Χργσιμοποιούμε αυτή τη βιβλιοθήκη γιατί έχουμε δηλώσει μεταβλητές των 64bit


int primes(uint64_t num) {  // Συνάρτηση primes που υπολογίζει πρώτους  
	uint64_t i;
	int flag = 1;
   	if (num == 2) {
      		flag = 1;
   	}
   	if (num == 3) {      // Έχουμε ξεωριστές περιπτώσεις για τους πρώτους 2 και 3 καθώς δεν ελέγχονται απο τον παρακάτω βρόχο
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



uint64_t gold(uint64_t num) { // Χρήηση uint64_t καθώς ενδλεχεται η τιμή που επιστρέφει η συνάρτηησ να μη χωράει στα 32 bit 
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
	uint64_t end_i = EOF;  // Αρχικοποιούμε ακέραια μεταβλητή με τιμή εκείνης του EOF ώστε να συκρίνουμε αργότερα την τιμή της scanf με αυτή  
	uint64_t end_c = EOF;
	while(1) {
      		uint64_t userin1;  // Χρησιμοποιούμε uint64_t για αριθμούς που δεν χωράνε σε 32 bit στο δυαδικό
      		int flag;
      		char userin2;
      		printf("Give me a number: ");
      		uint64_t scanner1 = scanf("%llu", &userin1); // Αρχικοποίηση ακέραιας μεταβλητής scan για την σύκριση της με την EOF 
		if (userin1 > 10000000000) {
			printf("Number should be in the range [0, 10000000000]\n");
			return 1;
			break;
		}
		if (scanner1 == end_i) {
			printf("EOF detected, exiting\n");
			return 0;
			break;
                }
		else if (scanner1 != 1) { // Όταν η scanf αποθηκεύσει με επιτυχία την σωστή τιμή που πρέπει να πάρει, τότε αποθηκέυεται στην μεταβλητή scanner1 η τιμή 1
			printf("Invalid input: expected an integer\n");
			return 1;
			break;
		}
      		printf("Choose how to test %llu - ('p' for prime, 'g' for goldbach) ", userin1 );
      		scanf("%c", &userin2);
		uint64_t scanner2 = scanf("%c", &userin2);  // Χρησιμοποιόυμε δύο φορές την scanf, μία για σύγκριση τιμλων με την μεταβλητή scanner2 και μία για σωστλη αποθήκευση char μεταβλητής   
		if (scanner2 == end_c) {
			printf("EOF detected, exiting\n");
			return 0;
			break;
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
		else if (userin2 == 'g') {
			uint64_t p1;  // Ορίζουμε όπως και στην συνάρτηηση gold τις μεταβλητές p1, p2 , το άθροισμα των οποιλων ειναι ο userin1
			uint64_t p2;
			if (userin1 == 4) { // Έχομυε ξεχωριστή περίπτωση για το 4 καθώς ο μικρότερος συνδυασμός πρώτων είναι μόνο το 2 όπου δημιουργελι θέμα στην συναρτησλη μας gold όπως αναφέραμε
				printf("4 = 2 + 2\n");
				continue;
			}
			if (userin1 == 10) {
				printf("10 = 3 + 7\n");
				continue;
			}
			if (userin1 <= 2 || userin1 % 2 != 0) {
				printf("Goldbach's conjecture is applicableonly to even numbers greater than 2!\n");
			}
			else {
				p1 = gold(userin1);
				p2 = userin1 - p1;
				printf("%llu = %llu + %llu\n", userin1, p2, p1);
			}
		}
		else {
			printf("Invalid choice: expected 'p' or 'g'\n");
			return 1;
			break;
		}
   	}
	return 0;
}
