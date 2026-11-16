/*Filename: photoula.c | My approach to this problem ;) */

#include <stdio.h>
#include <string.h>

/* int convert_ppm() {

} */





int main(int argc, char * argv[]) {
    char * program_name = argv[0];
    argv++; argc--;
    while(argc > 0) {
        if(strcmp(*argv, "--to") == 0) {
            argv++; argc--;
            if(strcmp(*argv, "ppm") == 0) {
                printf("Portbale pixel map");
            }
            else if(strcmp(*argv, "pgm") == 0) {
                printf("Portable gray map");
            }
            else if(strcmp(*argv, "pbm") == 0) {
                printf("Portbal bit map");
            }
            else {
                fprintf(stderr, "Usage: ./photoula --to <ppm|pgm|pbm> [options]\n");
                return 1;
            }
        }
        else if(strcmp(*argv, "--encoding") == 0) {
            argv++; argc--;
            if(strcmp(*argv, "binary") == 0) {
                printf("Output is binary ");
            }
            else if(strcmp(*argv, "asci")) {                
                printf("Output is asci");
            }
            else {
                fprintf(stderr, "Usage: ./photoula --to <ppm|pgm|pbm> [options]\n");
                return 1;
            }
        }
        else {
            fprintf(stderr, "Usage: ./photoula --to <ppm|pgm|pbm> [options]\n");
            return 1;
        }
		argv++; argc++; 
    }
	if (argc == 0) {
		fprintf(stderr, "Usage: ./photoula --to <ppm|pgm|pbm> [options]\n");
	}
    return 0;
}
