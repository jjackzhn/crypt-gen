#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <crypt.h>
#include <errno.h>
#include <string.h>

#define SALT_LEN 8

int main(int argc, char *argv[]){
	if(argc<2){
		printf("Usage: %s plain_text_file\n",argv[0]);
		exit(EXIT_FAILURE);
	}

	errno=0;
	FILE *in=fopen(argv[1],"r");

	if(in==NULL){
		printf("%s: Couldn't open file %s; %s\n",argv[0],argv[1],strerror(errno));
		exit(EXIT_FAILURE);
	}

	int count=0;
	while(!feof(in)){
		char text[50];
		fscanf(in,"%s\n",text);
		
		char salt[20];
		sprintf(salt,"$1$");
		char dict[]="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789./";
		int i=0;
		for(i=3;i<SALT_LEN+3;i++)
			salt[i]=dict[rand()%64];
		salt[i]='$';
		salt[i+1]='\0';

		printf("user%d:%s\n",count++,crypt(text,salt));
	}

	fclose(in);

	return 0;
}
