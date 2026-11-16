#include <stdio.h>
#include <string.h>

int main(int argc, char * argv[]) {
    char * program_name = argv[0];
    argv++; argc--;
    while(argc > 0) {
        if(strcmp(*argv, "--to") == 0) {
            argv++; argc--;
            if(strcmp(*argv, "ppm") == 0) {
                putchar('A');
                break;
            }
            else if(strcmp(*argv, "pgm") == 0) {
                putchar('B');
                break;
            }
            else if(strcmp(*argv, "pbm") == 0) {
                putchar('C');
                break;
            }
            else {
                fprintf(stderr, "Usage: ./photoula --to <ppm|pgm|pbm> [options]");
                return 1;
            }
        }
        else {
            fprintf(stderr, "Usage: ./photoula --to <ppm|pgm|pbm> [options]");
            return 1;
        }

    }



    return 0;
}