#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int count = 1;


int rgb_formula(int R, int G, int B) {
    answer = ((299*R) + (587*G) + (114*B)) / 1000;
    return answer;
}







int convert_ppm_to_pgm() {
    int ch;
    ch = getchar();
    if(ch != 'P') {
        fprintf(stderr, "Input error!\n");
        return 1;
    }
    ch = getchar();
    if(ch != '3') {
        fprintf(stderr, "Input error!\n");
        return 1;
    }
    while(1) {
        ch = getchar();
        if(ch == '#') {
            while((ch = getchar()) != EOF && ch != '\n') continue;
        }
        else if(ch == '\r' || ch == '\t' || ch == ' ' || ch == '\n') continue;
        else break;
    }



    int width = 0;
    while(ch >= '0' && ch <= '9') {
        width = width*10 + (ch -'0');
        ch = getchar();
    }
    while(1) {
        if(ch == '#') {
            while((ch = getchar()) != EOF && ch != '\n') continue;
        }
        else if(ch == '\r' || ch == '\t' || ch == ' ' || ch == '\n')  {
            ch = getchar();
        }
        else break;
    }





    int height = 0;
    while(ch >= '0' && ch <= '9') {
        height = height*10 + (ch - '0')
        ch = getchar();
    }



    int max = 0;
    ch = getchar();
    while(ch >= '0' && ch <= '9') {
        max = max*10 + (ch - '0');
        ch = getchar();
    }

}


int main() {
    return 0;
}