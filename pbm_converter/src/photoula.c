/*Filename: photoula.c | My approach to this problem ;)*/

#include <stdio.h>
#include <string.h>









int main(int argc, char *argv[]) {
	char *programname = argv[0];
	int flag = 0;
	argc--;
	argv++;
	while(argc > 0) {
		for(int i = 0 ; i < argc ; i++) {
			if(strcmp(argv[i], "--to") == 0) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			fprintf(stderr,"Usage");
			return 1;
		}
		if(strcmp(*argv, "--to") == 0) {
			argc--;
			argv++;
			if(strcmp(*argv, "ppm") == 0) {
				printf("PPM!\n");	
			}
			else if(strcmp(*argv, "pgm") == 0) {
				printf("PGM!\n");
			}
			else if(strcmp(*argv, "pbm") == 0) {
				printf("PBM!\n");
			}
			else {
				fprintf(stderr, "Usage:\n");
				return 1;
			}
		}
		else if(strcmp(*argv, "--encoding") == 0) {
			argc--;
			argv++;
			if(strcmp(*argv,"binary") == 0) {
				printf("binary!\n");
			}
			else if(strcmp(*argv, "asci") == 0) {
				printf("assci!!\n");
			}
			else {
				fprintf(stderr, "Usage:\n");
				return 1;
			}
		}
		else {
			fprintf(stderr, "Usage:\n");
		}
		argc--;
		argv++;
	}


	return 0;
}
