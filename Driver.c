//Brendan O'Dowd CS282
//Version 1.0 3/30/15

#include <stdio.h>
#include <stdlib.h>

char string[80]; //to hold each line entered in the person file
const char delim[2] = ","; //the separator for strtok()
char* token; //to hold the tokens generated from person file
int i = 0; //loop index
int temp; //to hold the int found by fscanf()

int main() {

	//file pointers for person, date, and output files
	FILE *per_fp, *dob_fp, *ofp;

	//open person file for reading
	per_fp = fopen("/home/hanasu/Desktop/person.txt", "r");

	//check that the file exists and can be opened
	if(per_fp == NULL) {
		printf("Cannot open file person.txt.");
		exit(1);
	}

	//open date file for reading
	dob_fp = fopen("/home/hanasu/Desktop/dob.txt", "r");

	//check that the file exists and can be opened
	if (dob_fp == NULL) {
		printf("Can't open file dob.txt.");
		exit(1);
	}

	//while we haven't reached the end of the file
	while(fgets(string,80,per_fp)!=NULL) {
		token = strtok(string,delim);
		puts(token);

		//read the rest of the line, there are 4 entries per line after the name
		for(i = 0; i < 4; i++) {
			token = strtok(NULL,delim);
			puts(token);
		}
	}

	//while we haven't reached the end of the file
	while(fscanf(dob_fp, "%d,", &temp) > 0) {
		printf("%d\n",temp);
	}

	return 0;
}
