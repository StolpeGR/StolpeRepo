/*Filename: goldbach.c | My appoach to this problem*/


#include <stdio.h>
#include <inttypes.h> // Χργσιμοποιούμε αυτή τη βιβλιοθήκη γιατί έχουμε δηλώσει μεταβλητές των 64bit


int primes(int64_t num) {  // Συνάρτηση primes που υπολογίζει πρώτους  
   int64_t i = 1;
   int flag = 1;
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
   int flag = 1;
   if (num == 4) {
      flag == 2;   
   }
   return flag;
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
         if (userin1 % 2 != 0) {
            printf("Goldbach's conjecture is applicable only to even numbers greater than 2!");
         }
         if (userin1 < 2) {
            continue;
         }
         flag = gold(userin1);
         if (flag == 2) {
            printf("%llu can be written as 2 + 2\n", userin1);
         }
      }
   }
   return 0;
}
                           
         


















/* int main() {
    while (1) { 
          int64_t userin, flag; 
          scanf("%llu", &userin);
          if (userin == 0) {
             break;
          }
          if(userin < 2) {
               continue;
          }
          flag = primes(userin);
         if (flag == 1) {
            printf("%llu is prime\n", userin);
         }
          else {
               printf("%llu is not prime\n", userin);
          }
    }
    return 0;
}*/
