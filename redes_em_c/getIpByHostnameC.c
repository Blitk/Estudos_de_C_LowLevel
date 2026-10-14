#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main (int arg, char *args[]){
	
	struct hostent *h;
	
	if (arg != 2){
		printf ("\nUso: %s <HOSTNAME>\n", args[0]);
		exit (1);
	}

	if((h=gethostbyname(args[1])) == NULL){
		perror("Gethostbyname error: ");
		exit (1);
	}
	
	printf ("\nNome do Host: %s\n", h->h_name);
	printf ("Endereco IP : %s\n", inet_ntoa(*((struct in_addr *)h->h_addr)));
	
	return 0;
}
