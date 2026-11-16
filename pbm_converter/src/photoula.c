/*Filename: photoula.c | My approach to this problem ;)*/

#include <stdio.h>
#include <string.h>

int convert_ppm_to_pgm() {
	int ch;
	int width;
	int height;
	int R;
	int G;
	int B;
	ch  = getchar();
	if(ch != 'P') fprintf(stderr, "Not a valid tpye");
	ch = getchar();
	if(ch != '3') fprintf(stderr, "Wrong number type. Should be 3!");
	putchar('\r');
	ch = getchar();
	if(ch == '#') putchar('\r');
	width = getchar();
	ch = getchar();
	height = getchar();
	putchar('\r');
	putchar('\r');
	//Ακουλουθεί αλγόριθμος για τα πρώτα πέντε pixel
	R = getchar(); // Ο πρώτος χαρακτήρας σίγουρα είναι ο δείκτης R (Red)
	ch = getchar(); // Ο δεύτερος χαρακτήρας σίγουρα ειναι το κενό ' '
	
	/*Χρησιμοποιηούμε nested loop προκειμένου να διατρέξομε όλα τα pixels, 
	πέντε φορές την κάθε φορά, ανά στήλες (κάθετα).*/
	
	
	
	
	for(int i = 1 ; i <= height ; i++) { // Διατρέχομυε όλες τι γραμμές
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
}







int main(int argc, char *argv[]) {
	char *programname = argv[0]; 
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
