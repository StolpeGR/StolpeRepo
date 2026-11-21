#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int count = 1;


int rgb_formula(int R, int G, int B) {
    answer = ((299*R) + (587*G) + (114*B)) / 1000;
    return answer;
}








void convert_ppm_to_pgm() {
    int ch;
    ch = getchar();
    if(ch != 'P') fprintf(stderr, "Wrong!\n");
    ch = getchar();
    if(ch != '3') fprintf(stderr, "Wronf number!\n");
    while(1) {
        ch = getchar();
        if(ch == '#') {
            while((ch = getchar()) != EOF && ch != '\n') continue;
        }
        else if(ch == '\r' || ch == '\t' || ch == '\r' || ch == '\n') continue;
        else break;
    }



    int width = 0;
    ch = getchar();
    while(ch >= '0' && ch <= '9') {
        width = width*10 + (ch -'0');
        ch = getchar();
    }


    int height = 0;
    ch = getchar();
    while(ch >= '0' && ch <= '9') {
        height = width*10 + (ch - '0')
        ch = getchar();
    }



    int max = 0;
    ch = getchar();
    while(ch >= '0' && ch <= '9') {
        max = max*10 + (ch - '0');
        ch = getchar();
    }

int *rgb = malloc(3*sizeof(int));

    if(max >= 0 && max <= 9) {
        for(int i = 0 ; i < height*((5*width) + 2*(width-1)) ; i++) {
            ch = getchar();
            if(ch != '\r' || ch != '\t' || ch != '\n' || ch != ' ')
            /*for(int j = 0 ; j < ((5*width) + 2*(width-1)) ; j++) {
                ch = getchar()
                if(ch != '\r' || ch != '\t' || ch != '\n' || ch != ' ') {

                }
            }*/
        }
    }


    


}


int main() {
    return 0;
}