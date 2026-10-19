/*Testing the goldbach.c*/
// This is a test version !




#include <stdint.h>
#include <stdio.h>



int primes(int64_t num) {
   int64_t i, flag = 1; 
   for(i = 2 ; i < num ; i++) {
          if (num % i == 0) {
             flag = 0;
          }
    }
    return flag;
}




int main() {
    while (1) {
          int64_t userin, flag;
          printf("Enter your number: ");
          scanf("%llu", &userin);
          if (userin == 0 || userin == 1) {
             break;   
          }
          else if (userin < 2) {
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
}
