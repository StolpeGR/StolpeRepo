#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int rgb_formula(int R, int G, int B) {
    int answer = (((299*R) + (587*G) + (114*B)) / 1000);
    return answer;
}


int thresholdT(int max_decoding) {
	int T = (max_decoding + 1) / 2;
	return T;
} 










void unsupported_conversion_error() {  // Για την ppm μόνο αφού όταν βάζω όρισμα --to ppm και μετά βάλω αρχεία .pgm ή .pbm θα έχω θέμα. Δε μπορεί να συμβεί αντίστροφη μετατροπή;
	int ch;
	ch = getchar();
	if(ch != 'P') {
		fprintf(stderr, "Input error!\n");
		exit(1);
	}
	ch = getchar();
	if(ch == '2' || ch == '5' || ch == '1' || ch == '4') {
		fprintf(stderr, "Unsupported conversion\n");
		exit(1);
	}
}




















void convert_ppm_to_pgm() {
	int ch;
	ch = getchar();
	if(ch != 'P') {
		fprintf(stderr, "Input error!\n");
		exit(1);
	}
	ch = getchar();
	if(ch == '1' || ch == '4') { // Αν πάει και βάλει ο χρήστης εικόνα pbm ενώ έβαλε πριν όρισμα --to pgm τότε είναι λάθος για τον λόγο που αναφλεραμε στο πάνω σχόλιο
		fprintf(stderr ,"Unsupported conversion\n");
		exit(1);
	}
	if(ch != '3' && ch != '6') {
		fprintf(stderr, "Input error!\n");
		exit(1);
	}
	int magic_digit = ch;
	while(1) {
		ch = getchar();
		if(ch == '#') {
			while((ch = getchar()) != EOF && ch != '\n') continue;
		}
		else if(ch == '\n' || ch == '\t' || ch == ' ' || ch == '\r') continue;
		else break;
	}




	int count = 0;
	int width = 0;
	while(ch >= '0' && ch <= '9') {
		width = width*10 + (ch - '0');
		count++;
		ch = getchar();
	}
	if(count == 0) {
		fprintf(stderr, "Input error!\n");
		exit(1);
	}
	count = 0;







	while(1) {
		if(ch == '#') {
			while((ch = getchar()) != EOF && ch != '\n') continue;
		}
		else if(ch == '\n' || ch == '\t' || ch == ' ' || ch == '\r') ch = getchar();
		else break;
	}








	int height = 0;
	while(ch >= '0' && ch <= '9') {
		height = height*10 + (ch - '0');
		count++;
		ch = getchar();
	}	
	if(count == 0) {
		fprintf(stderr, "Input error!\n");
		exit(1);
	}
	count = 0;




	
	while(1) {
		if(ch == '#') {
			while((ch = getchar()) != EOF && ch != '\n') continue;
		}
		else if(ch == '\n' || ch == '\t' || ch == ' ' || ch == '\r') ch = getchar();
		else break;
	}





	int max = 0;
	while(ch >= '0' && ch <= '9') {
		max = max*10 + (ch - '0');
		count++;
		ch = getchar();
	}
	if(count == 0) {
		fprintf(stderr, "Input error!\n");
		exit(1);
	}
	count = 0;
	if(max > 255 || max == 0) {
		fprintf(stderr, "Input error!\n");
		exit(1);
	}


	int gray_colors = 0;
	if(magic_digit == '6') {
		if(ch != '\r' && ch != '\t' && ch != ' ' && ch != '\n') {
			fprintf(stderr, "Input error!\n");
			exit(1);
		}
		printf("P5\n");
		printf("%d %d\n", width, height);
		printf("%d\n", max);
		for(int i = 1 ; i <= height*width ; i++) {
			int R = getchar();
			int G = getchar();
			int B = getchar();
			if(R == EOF || G == EOF || B == EOF || R > max || G > max || B > max ) {
				fprintf(stderr, "Input error!\n");
				exit(1);
			}
			else {
				gray_colors = rgb_formula(R, G, B);
				putchar(gray_colors); 
			}
		}




	}






	/*while(1) {
		if(ch == '#') {
			while((ch = getchar()) != EOF && ch != '\n') continue;
		}
		else if(ch == '\n' || ch == '\t' || ch == ' ' || ch == '\r') ch = getchar();
		else break;
	}*/









}












void convert_pgm_to_pbm(int T) {
	int ch;
	ch = getchar();
	if(ch != 'P') {
		fprintf(stderr, "Input error!\n");
		exit(1);
	}
	ch = getchar();
	if(ch != '2' && ch != '3') {
		fprintf(stderr, "Input error!\n");
		exit(1);
	}



	while(1) {
        ch = getchar();
        if(ch == '#') {
            while((ch = getchar()) != EOF && ch != '\n') continue;
        }
        else if(ch == '\r' || ch == '\t' || ch == ' ' || ch == '\n') continue;
        else break;
    }


	int count = 0;	
	int width = 0;
	while(ch >='0' && ch <= '9') {
		width = width*10 + (ch - '0');
		count++;
		ch = getchar();
	}
	if(count == 0) {
		fprintf(stderr, "Input error!\n");
		exit(1);
	}
	count = 0;


	while(1) {
	    if(ch == '#') {
            while((ch = getchar()) != EOF && ch != '\n') continue;
        }
        else if(ch == '\r' || ch == '\t' || ch == ' ' || ch == '\n') ch = getchar();
        else break;    
	}









	int height = 0;
    while(ch >= '0' && ch <= '9') {
        height = height*10 + (ch - '0');
		count++;
        ch = getchar();
    }
	if(count == 0) {
		fprintf(stderr, "Input error!\n");
		exit(1);
	}
	count = 0;


	while(1) {
        if(ch == '#') {
            while((ch = getchar()) != EOF && ch != '\n') continue;
        }
        else if(ch == '\r' || ch == '\t' || ch == ' ' || ch == '\n') ch = getchar();
        else break;
    }







	int max = 0;
	while(ch >= '0' && ch <= '9') {
		max= max*10 + (ch - '0');
		count++;
		ch = getchar();
	}
	if (count == 0 ) {
		fprintf(stderr, "Input error!\n");
		exit(1);
	}
	count = 0;



	if(T > max) {
		fprintf(stderr, "Input error!\n");
		exit(1);
	}





}






















int main(int argc, char *argv[]) {
	//char *programname = argv[0]; 
	int flag = 0;
	/*Επειδή αποθηκεύσαμε στον pointer programnmer το όνομα του προγράμματος που βρίσκεται στο argv[0], 
	μπορούμε να μειώσουμε τον αριθμό των arguments κατά 1 και να α"υξήσουμε" το argv κατά 1.*/
	argc--; 
	argv++;
	if(argc == 0) {
		fprintf(stderr, "Usage: ./photoula --to <ppm|pgm|pbm> [options]\n");
		return 1;
	}
	while(argc > 0) {
		for(int i = 0 ; i < argc ; i++) { // Είναι αναγκαστικό στα ορίσματά μας να υπάρχει το "--to". Για αυτό υλοποιούμε τον παραπάνω βρόχο.
			if(strcmp(argv[i], "--to") == 0) {
				flag = 1;
			}
			if(strcmp(argv[i], "--help") == 0) {
				printf("Usage: Welcome to photoula. This is a short manual of the program's functionality");
				return 0;
			}
		}
		if (flag == 0) {
			fprintf(stderr,"Usage: ./photoula --to <ppm|pgm|pbm> [options]\n");
			return 1;
		}
		/* Ακολουθεί έλεγχος για τα ορίσματα που δίνει ο χρήστης. Συχνή είναι η χρήση της συνάρτησης strcmp(). 
		Εκμεταλλευόμαστε το γεγονός ότι η τιμή που επιστρέφει ότσν τα string ταυτίζονται, είναι 0- */ 
		if(strcmp(*argv, "--to") == 0) {
			argc--;
			argv++;
			if(argc == 0) {
				fprintf(stderr, "Usage: ./photoula --to <ppm|pgm|pbm> [options]\n");
				return 1;
			}
			if(strcmp(*argv, "ppm") == 0) {
				unsupported_conversion_error();
			}
			else if(strcmp(*argv, "pgm") == 0) {
				if(argc > 2 && (strcmp(argv[1], "--to") == 0) && (strcmp(argv[2], "pgm") == 0)) {
						fprintf(stderr, "Usage: ./photoula --to <ppm|pgm|pbm> [options]\n");
						return 1;
				}
				if(argc > 1 && (strcmp(argv[1], "--encoding") != 0)) {
					fprintf(stderr, "Usage: ./photoula --to <ppm|pgm|pbm> [options]\n");
					return 1;
				}
				convert_ppm_to_pgm();
			}
			else if(strcmp(*argv, "pbm") == 0) {
				if((argc > 2) && (strcmp(argv[1], "--threshold") == 0)) {
					int user_input = atoi(argv[2]);
					if(argc > 3 && strcmp(argv[3] ,"--threshold") == 0) {
						fprintf(stderr, "Usage: ./photoula --to <ppm|pgm|pbm> [options]\n");
						return 1;
					}
					if(user_input < 0) {
						fprintf(stderr, "Usage: ./photoula --to <ppm|pgm|pbm> [options]\n");
						return 1;
					}
					if(user_input == 0) {
						fprintf(stderr, "Usage: ./photoula --to <ppm|pgm|pbm> [options]\n");
						return 1;
					}
					if(user_input > 0) convert_pgm_to_pbm(user_input);
				}
				if(argc == 1) {
					fprintf(stderr, "Input error!\n");
					return 1;
				}
			}
			else {
				fprintf(stderr, "Usage: ./photoula --to <ppm|pgm|pbm> [options]\n");
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
				fprintf(stderr, "Usage: ./photoula --to <ppm|pgm|pbm> [options]\n");
				return 1;
			}
		}
		else {
			fprintf(stderr, "Usage: ./photoula --to <ppm|pgm|pbm> [options]\n");
			return 1;
		}
		argc--;
		argv++;
	}
	return 0;
}