/*Filename: goldbach.c | My appoach to this problem*/


#include <stdio.h>
#include <inttypes.h> // Χργσιμοποιούμε αυτή τη βιβλιοθήκη γιατί έχουμε δηλώσει μεταβλητές των 64bit


int primes(int64_t num) {  // Συνάρτηση primes που υπολογίζει πρώτους  
	int64_t i, flag = 1;
   	if (num == 2) {
      		flag == 1;
   	}
   	if (num == 3) {
      		flag == 1;
   	}
   	if (num % 2 == 0) {
      		flag == 0;
   	}
   	if (num % 3 == 0) {
      		flag == 0;
   	}
   	for(i = 3 ; i*i <= num ; i++) { // Βρόχος που ελέγχει αν υπάρχει διαιρέτης του num 
       		if (num % i == 0) {
             	flag = 0;
         	}
    	}
	return flag;
}



int gold(int64_t num) {
	int64_t p1;
	int64_t p2 = 3;
	for( p2 = 3 ; p2 < (num - 3) ; p2 += 2) {
		if (primes(p2) == 0) {
			continue;
		}
		else {
			if(primes(num - p2) == 0) {
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
	while(1) {   
      		int64_t userin1;  // Χρησιμοποιούμε int64_t για αριθμούς που δεν χωράνε σε 32 bit στο δυαδικό
      		int flag;
      		char userin2;
      		printf("Enter your number: ");
      		scanf("%" SCNd64, &userin1); // Χρησιμοποιούμε το SDNd64 για να δείξοθμε στην scanf ότι διαβάζομυε μόνο αριθμούς των 64 bit  
      		printf("Enter your option ('p' for primes or 'g' for goldbach): " );
      		scanf(" %c", &userin2);
      		if (userin2 == 'p') {
         		if (userin1 == 0) {
            			break;
         		}
         		if (userin1 < 2) {
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
			int64_t p1;
			int64_t p2;
			if (userin1 == 4) {
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

