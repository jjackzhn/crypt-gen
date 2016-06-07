#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <time.h>

#include "ow_bcrypt/ow-crypt.h"

int main(int argc, char *argv[]){
	if(argc<3){
		printf("Usage: %s log_iter plain_text_file\n",argv[0]);
		exit(EXIT_FAILURE);
	}

	errno=0;
	FILE *in=fopen(argv[2],"r");

	if(in==NULL){
		printf("%s: Couldn't open file %s; %s\n",argv[0],argv[2],strerror(errno));
		exit(EXIT_FAILURE);
	}

	time_t t;
	time(&t);
	srand(t);
	int count=0;
	while(!feof(in)){
		char text[50];
		fscanf(in,"%s\n",text);
		
		char salt[50];
		strcpy(salt,crypt_gensalt("$2a$",atoi(argv[1]),"salt",22));

		printf("user%d:%s\n",count++,crypt(text,salt));
	}

	fclose(in);

	return 0;
}
