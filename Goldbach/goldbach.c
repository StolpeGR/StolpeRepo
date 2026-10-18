/*Filename: goldbach.c | My appoach to this problem*/

#include <stdio.h>

int prime(int num) {
    int i, flag = 1;
    for(i = 2 ; num > (i/2) ; i++) { // Goes through every possible divisor the given number 
            if (num % i == 0) {
                flag = 0;
            } 
    }
    return flag;
}   






int main() {
    int user_input, flag;
    while(1) {
        printf("Enter your number: ");
        scanf("%d", &user_input);
        if (user_input == 0) {
            break;
        }
        if (user_input < 2) {
            continue;
        }
        flag = prime(user_input); 
        if (flag == 1) { // 1 is the flag's value when the given number is prime
            printf("%d is prime\n", user_input);
        }
        else {
            printf("%d is not prime\n", user_input);
        }
    }
    return 0; 
}