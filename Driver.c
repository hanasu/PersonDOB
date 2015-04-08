//Brendan O'Dowd CS282
//Version 1.0 3/30/15

#include <stdio.h>
#include <stdlib.h>

char string[80]; //to hold each line entered in the person file
const char delim[2] = ","; //the separator for strtok()
char string_store[80];
char* token;
int i = 0, j = 0; //loop indexes
int temp; //to hold the int found by fscanf()
int pcount = 0, dcount = 0; //array indexes for person/date arrays
int num_read = 1; //counter for date reading

//holds date of birth data for PERSONs
typedef struct {
	int month;
	int day;
	int year;
} DATE;

typedef struct {
	char* lname; //last name
	DATE* dob; //date of birth
	int ssn;
	char* address;
	char* city;
	int age;
} PERSON;

DATE dates[17];
PERSON people[17];

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
	while(fscanf(dob_fp, "%d,", &temp) > 0) {
		if(num_read % 3 == 1) {
			dates[dcount].month = temp;	
		}
		if(num_read % 3 == 2) {
			dates[dcount].day = temp;
		}
		if(num_read % 3 == 0) {
			dates[dcount].year = temp;
			dcount++;
		}
		num_read++;
	}

	//while we haven't reached the end of the file
	while(fgets(string,80,per_fp)!=NULL) {
		for(i = 0; i < 5; i++) {			
			if(i == 0) {
				people[pcount].lname = strdup(strtok(string,delim));
				printf("%s",people[pcount].lname);
			}			
			if(i == 1) {
				token = strtok(NULL,delim);
				puts(token);				
				people[pcount].ssn = atoi(token);
			}
			if(i == 2) {
				token = strtok(NULL,delim);
				puts(token);
				people[pcount].address = token;
			}
			if(i == 3) {
				token = strtok(NULL,delim);
				puts(token);
				people[pcount].city = token;
			}
			if(i == 4) {
				token = strtok(NULL,delim);
				puts(token);
				people[pcount].age = atoi(token);
			}
		}

		//people[pcount].dob.month = dates[pcount].month;
		//people[pcount].dob.day = dates[pcount].day;
		//people[pcount].dob.year = dates[pcount].year;
		pcount++; //increment person array index
	}

	return 0;
}
