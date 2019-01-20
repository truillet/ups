#include <stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include <string.h>

int isCharInteger(char);
int isStringInteger(char*);
int charToInteger(char);
int stringToInteger(char*);

/** 
 * int isCharInteger(char c)
 * @param c : char argument
 */
int isCharInteger(char c){
	switch (c){
		case '0':    
		case '1':    
		case '2':      
		case '3':
		case '4':
		case '5':
		case '6':       
		case '7':
		case '8':
		case '9':
			return(1);
			break;
		default:
			return -1; /** FALSE */
    }
}

/** 
 * int isCharInteger(char* s)
 * @param s : char* argument
 */
int isStringInteger(char* s){   
	int longueur = strlen(s);
	int isInteger = 1;
    int i =0;
	/** look at the first character */ 
	if ((!isCharInteger(s[0])) && (s[0] != '-'))
		isInteger = 0;
	i++;
	while((i<longueur) && isInteger){ /** */
		if (isCharInteger(s[i])==-1)
			isInteger=0;
		i++;
	}
	if (isInteger)
		return(1);
	else
		return(-1);
}

/** 
 * int charToInteger(char c)
 * @param c : char argument
 */
 int charToInteger(char c) {
	if (isCharInteger(c))
		return (c-48); /** 48 : code ASCII de '0' */
	else
		return -1;
}


/**
* int stringToInteger(char* s)
 * @param s : char* argument
 */
 int stringToInteger(char* s) {
	int res=0;	
	int signe = 1;
	if (isStringInteger(s)) {
		/** gestion du 1er caractère */
		int i=0;
		if (s[i] == '-')  
			signe=-1;
		else 
			res= charToInteger(s[i]);
		
		for (i=1;i<strlen(s);i++) {
			res= res*10;
			res= res + charToInteger(s[i]);
		}
		return (res*signe);
	}
	else
		return(-1);
}
 
 
/**
 * main entry point
 */
int main (int argc, char* argv[]){

    if(argc!=3){
        printf("Wrong usage, 2 parameters expected: ./sum param1 param2\n");
        return -1; /** ERROR */
    }
	
	int i=1;
	while(i<argc){
		if(isStringInteger(argv[i])==-1){
			printf("Wrong usage, parameters param1 and param2 should be integers when executing ./sum param1 param2 \n");           
			return -1;
		}
		i++;
	}
	printf("%d\n", stringToInteger(argv[1]) + stringToInteger(argv[2]));
	return 1;
}