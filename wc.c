/*
 ============================================================================
 Name        : wc.c
 Author      : 805257
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

static int total_lines=0;
static int total_words=0;
static int total_chars=0;

void wc(FILE *infile, char *inname);

int
main (int argc, char*argv[]){

	if( argc >1){
		char *inname=NULL;
		while( *++argv != NULL){
			FILE *infile =fopen(*argv,"r");
			if( infile ==NULL){
				perror(*argv);
				exit( EXIT_FAILURE );
			}
			inname = *argv;

			wc( infile ,inname);
			if( fclose(infile) !=0 ){
				perror("fclose");
				exit(EXIT_FAILURE);
			}
		}
		if( argc > 2)
			printf("%7d %7d %7d  %s\n" , total_lines, total_words , total_chars, "total");
	}
	else
		wc(stdin , "");

	return 0;
}
void
wc( FILE *infile ,char *inname){
	int lines= 0;
	int words=0;
	int chars= 0;
	int c= fgetc(infile);
	bool space =false;
	while ( c != EOF){
		if( c == '\n' ){
			++ lines;
			++ total_lines;
		}

		if( isspace(c) && !space){
			++ words;
			++ total_words;
			space =true;
		}
		if(!isspace(c) && space)
		space = false;
		++ chars;
		++ total_chars;
	}
	printf("%7d %7d %7d %s\n", lines , words ,chars, inname);
}


