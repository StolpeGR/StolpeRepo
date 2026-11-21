/*Filename: photoula.c | My approach to this problem ;)*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int rgb_formula(int R, int G, int B) {
	int answer = ((299*R) + (587*G) + (114*B)) / 1000;
	return answer;
}





void convert_ppm_to_pgm() {
	//int ch;
	//int width1;
	//int height1;
	//int R;
	//int G;
	//int B;
	// int max_num;
	int ch  = getchar();
	if(ch != 'P') fprintf(stderr, "Not a valid tpye");
	int ch = getchar();
	if(ch != '3') fprintf(stderr, "Wrong number type. Should be 3!");
	int ch;
	while((ch = getchar()) != EOF) {
		if(ch == '#') {
				while((ch = getchar()) != '\n' && ch != EOF); {
						continue;
				}
		}
	}
	int *witdh_array = malloc
	int width1;
	while((width1 = getchar()) != EOF) {
		while(width = get)
	}
	int width = width1 - '0';
	int ch = getchar(); // Πάντα ο χαρακτήρας που θα διαβάζει εδώ θα ειναι ο ' '.
	int height1 = getchar();
	int height = height1 - '0';
	int characters_ppm_rgb3 = (11*width) + 2*(width-1); // Βλέπε readme
	int characters_ppm_rgb2 = (8*width) + 2*(width-1); // Βλέπε readme
	int characters_ppm_rgb1 = (5*width) + 2*(width-1); // Βλέπε readme
	// int characters_pgm = (3*width) + 2*(width-1);  // Βλέπε readme
	int pgm_nums = (width + 2*(width -1));
	int max_array[3]; // Πίνακας που αποθηκεύονται τα ψηφία του μέγιστου αριθμού κωδικοποίησης για ppm και pgm.
	memset(max_array, 0, (width + 2*(width-1))*sizeof(int)); 
	int rgb3[height*characters_ppm_rgb3]; // Πίνακας που αποθηκεύονται αρχικά όλα τα στοιχεία των pixel, μέχρι και τα κενά που τα χωρίζουν. 
	memset(rgb3, 0, (height*characters_ppm_rgb3)*sizeof(int));
	int rgb2[height*characters_ppm_rgb2];
	memset(rgb2, 0, (height*characters_ppm_rgb2)*sizeof(int));
	int rgb1[height*characters_ppm_rgb1];
	memset(rgb1, 0, (height*characters_ppm_rgb1)*sizeof(int));
	/*Το μέγεθος του πίνακα εξηγείται απο την μεταβλητή characters_ppm. 
	Βλέπε αρχείο README.md για περισσότερη πληροφορία*/

	int rgb_calc1[3*width*height]; // Πίνακας που αποθηκεύονται αποκλειστικά μονο οι αριθμοί rgb των pixel. Είναι 3*width*height καθώς για max=1 δηλαδή μνοψήφιοι αριθμί κωδικοποίησης το άθροισμα των ψηφίων ειναι 3.
	memset(rgb_calc1, 0, (3*width*height)*sizeof(int));
	int rgb_calc2[6*width*height];
	memset(rgb_calc2, 0, (6*width*height)*sizeof(int));
	int rgb_calc3[9*width*height];
	memset(rgb_calc3, 0, (9*width*height)*sizeof(int));
	int gray_colors[width*height];
	memset(gray_colors, 0, height*width*sizeof(int));
//	int rgb_max_2digits[9*width/2];
	putchar('\r');
	int end = 0;
	int max_ch = 0;
	for(int l = 0 ; l < 3 ; l++) {
		if((max_ch = getchar()) != ' ') {
			max_array[end] = max_ch - '0'; // Διβάζουμε τη μέγιστη τιμή max που μπορεί να έχει ένας ακέραιος που κωδικοποιεί ένα χρώμα
			end++;
		}
		else {
			break;
		}
	}
	int max_rgb = 0;
	for(int i = 0 ; i < end ; i++) {
		max_rgb = 10*max_rgb + max_array[i];
	}
	putchar('\r');
	/*Χρησιμοποιηούμε nested loop προκειμένου να διατρέξομε όλα τα pixels, 
	height φορές, ανά γραμμή (οριζόντια).*/
	
	/*for(int i = 1 ; i <= height ; i++) {
		for(int j = 0 ; j < characters_ppm ; j++) { // Αν μετρήσουμε τους χαρακτήρες που έχει κάθε γραμμή που αποτελείται από ενα pixel, είναι ακριβώς 11, και κάθε μία από αυτές χωρίζεται απο δύο κενά ' '.
			ch = getchar();
			if(ch != 32) {
				rgb[j] = ch - '0'; 
			}
			else {
				rgb[j] = 32; // Ο ASCI χαρακτήρας του ' ' ειναι 30. Τον αγνούμε.
			}
		}
		putchar('\r');
		
	} */
	/* int count = 0;
	for(int i = 0; i< height*characters_ppm ; i++) {  // Επιθυμούμε να διώξουμε ολά τα νούμερα με τιμή 30.{
		if(rgb[i] != 30) {
			rgb_calc[count] = rgb[i];
			count++;
		}
		else {
			continue;
		}
	}*/
	// Υπάρχουν διαφορετικές περιπτώσεις ανάλογα με τον αριθμό κωδικοποίησης των pixel.
	if(max_rgb > 0 || max_rgb <= 9) {
		int first_count = 0;
		for(int i = 1 ; i <= height ; i++) {
			for(int j = 0 ; j < characters_ppm_rgb1 ; j++) {
				ch = getchar();
				if(ch != ' ' ) {
					rgb1[first_count] = ch -'0';
				}
				else {
					rgb1[first_count] = ' ';
				}
				first_count++;
			}
		}
		int count = 0;
		for(int i = 0 ; i < first_count ; i++) {
			if(rgb1[i] != ' ') {
				rgb_calc1[count] = rgb1[i];
				count++;
			}
			else {
				continue;
			}
		}
		for(int j = 0 ; j < count ; j ++) {
			gray_colors[j] = rgb_formula(rgb_calc1[j], rgb_calc1[j+1], rgb_calc1[j+2]);
		}
		printf("P2");
		putchar('\r');
		printf("%d", width);
		putchar(' ');
		printf("%d", height);
		putchar('\r');
		printf("%d", max_rgb);
		putchar('\r');
		int new_count = 0;
		for(int i = 0 ; i < height ; i++) {
			for(int j = 0 ; j < pgm_nums ; j++) {
				if((j+1)% 2 == 0 && j >= 1) {
					putchar(' ');
					putchar(' ');
				}
				if(gray_colors[new_count] >= 0 || gray_colors[new_count] <= 9) {
					printf(" %d", gray_colors[new_count]);
				}
				else {
					printf("%d", gray_colors[new_count]);
				}
				new_count++;
			}
			putchar('\r');
			
		}
	}
	else if(max_rgb >= 10 || max_rgb <= 99) {
		int first_count = 0;
		for(int i = 0 ; i < height ; i++) {
			for(int j = 0 ; j < characters_ppm_rgb2 ; j++) {
				ch = getchar();	
				if(ch != ' ') {
					rgb2[first_count] = ch -'0';
				}
				else {
					rgb2[first_count] = ' ';
				}
				first_count++;
			}
		}
		int count = 0;
		for(int i = 0; i < first_count ; i+=10) {
			for(int j = 0 ; j <= 6 ; j+=3) { // Ανά 2 βήματα έχουμε σίγουρα κενό χαρακτήρα. Επομένως πάμε άνα 3 και μετά βλέπουμε αν υπάρχει και κενός χαρακτήρας μετά.
				if(rgb2[j] == ' ') {
					rgb_calc2[count] = rgb2[j+i+1];
					count++;
				}
				else {
					int get_num = 0;
					for(int k = 0 ; k <= 1; k++) {
						get_num = 10*get_num + rgb2[i+j+k];
						count++;
					} 
					rgb_calc2[count] = get_num;
				}
			}
		}
		for(int i = 0 ; i < count ; i++) {
			gray_colors[i] = rgb_formula(rgb_calc2[i], rgb_calc2[i+1], rgb_calc2[i+2]);
		}
		printf("P2");
		putchar('\r');
		printf("%d", width);
		putchar(' ');
		printf("%d", height);
		putchar('\r');
		printf("%d", max_rgb);
		putchar('\r');
		int new_count = 0;
		for(int i = 0 ; i < height ; i++) {
			for(int j = 0 ; j < pgm_nums ; j++) {
				if((j+1)% 2 == 0 && j >= 1) {
					putchar(' ');
					putchar(' ');
				}
				if(gray_colors[new_count] >= 0 || gray_colors[new_count] <= 9) {
					printf(" %d", gray_colors[new_count]);
				}
				else {
					printf("%d", gray_colors[new_count]);
				}
				new_count++;
			}
			putchar('\r');	
		}
	}
	else {
		int first_count;
		for(int i = 0 ; i < first_count ; i++) {
			for(int j = 0 ; j < characters_ppm_rgb3 ; j++) {
				ch = getchar();
				if(ch != ' ') {
					rgb3[first_count]= ch - '0';
				}
				else {
					rgb3[first_count] = ' ';
				}
				first_count++;
			}
		}	
		int count = 0;
		for(int i = 0 ; i < first_count ; i += 13 ) {
			for(int j = 0 ; j < 13 ; j += 4) {
				if(rgb3[count + 1] == ' ') {
					rgb_calc3[count] = rgb3[i+j+2];
				}
				else if(rgb3[count] == ' ') {
					int get_num = 0;
					for(int k = 0 ; k <= 1 ; k++) {
						get_num = 10*get_num + rgb3[i+j+k];
					}
					rgb_calc3[count] = get_num;
				}
				else {
					int get_num = 0;
					for(int k = 0 ; k <= 2 ; k++) {
						get_num = 10*get_num + rgb3[i+k+k];
					}
					rgb_calc3[count] = get_num;
				}
				count++;
			}
		}
		for(int i = 0 ; i < count ; i++) {
			gray_colors[count] = rgb_formula(rgb_calc3[i], rgb_calc3[i+1], rgb_calc3[i+2]);
		}
		printf("P2");
		putchar('\r');
		printf("%d", width);
		putchar(' ');
		printf("%d", height);
		putchar('\r');
		printf("%d", max_rgb);
		putchar('\r');
		int new_count = 0;
		for(int i = 0 ; i < height ; i++) {
			for(int j = 0 ; j < pgm_nums ; j++) {
				if((j+1)% 2 == 0 && j >= 1) {
					putchar(' ');
					putchar(' ');
				}
				if(gray_colors[new_count] >= 0 || gray_colors[new_count] <= 9) {
					printf(" %d", gray_colors[new_count]);
				}
				else {
					printf("%d", gray_colors[new_count]);
				}
				new_count++;
			}
			putchar('\r');
			
		}
	}
}	
    /*	for(int i = 1 ; i <= height ; i++) { // Διατρέχομυε όλες τι γραμμές
		for(int j = 1 ; j <= 4; j++) { // Διατρέχομυε όλα τα περιεχόμενα των γραμμών.
			if(ch == ' ') { // Μεταξύ των κωδικών RGB ενδέχεται να υπάρχει κενό, επομένως εκτπώνουμε όπου χρειάζεται κενό για να συνεχίσουμε την αναζήτηση.
				putchar(' ');
			}
			ch = getchar();
			else {
				if(j == 2) { // Πάντα για j = 2 ή j = 4 υπάρχει κωδικός G ή B αντίστοιχα.
					G = ch;
				}
				else if(j == 4) {
					B  = ch;
				}
			}
		R = getchar(); // Όταν τελείωσουμε με την πρώτη στήλη, ξανά ο πρώτος χαρακτήρας θα είναι κωδικός R.
		}
	}
} */







int main(int argc, char *argv[]) {
	//char *programname = argv[0]; 
	int flag = 0;
	/*Επειδή αποθηκεύσαμε στον pointer programnmer το όνομα του προγράμματος που βρίσκεται στο argv[0], 
	μπορούμε να μειώσουμε τον αριθμό των arguments κατά 1 και να α"υξήσουμε" το argv κατά 1.*/
	argc--; 
	argv++;
	while(argc > 0) {
		for(int i = 0 ; i < argc ; i++) { // Είναι αναγκαστικό στα ορίσματά μας να υπάρχει το "--to". Για αυτό υλοποιούμε τον παραπάνω βρόχο.
			if(strcmp(argv[i], "--to") == 0) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			fprintf(stderr,"Usage");
			return 1;
		}
		/* Ακολουθεί έλεγχος για τα ορίσματα που δίνει ο χρήστης. Συχνή είναι η χρήση της συνάρτησης strcmp(). 
		Εκμεταλλευόμαστε το γεγονός ότι η τιμή που επιστρέφει ότσν τα string ταυτίζονται, είναι 0- */ 
		if(strcmp(*argv, "--to") == 0) {
			argc--;
			argv++;
			if(strcmp(*argv, "ppm") == 0) {
				convert_ppm_to_pgm();	
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
