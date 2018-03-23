#include <stdio.h>      /* for printf() and fprintf() */
#include <sys/socket.h> /* for socket(), bind(), and connect() */
#include <arpa/inet.h>  /* for sockaddr_in and inet_ntoa() */
#include <stdlib.h>     /* for atoi() */
#include <string.h>     /* for memset() */
#include <unistd.h>     /* for close() */
#include <netdb.h>
#include <cctype>
#include <errno.h>
#include <signal.h>

#include "DieWithError.c"
//#include "CatchAlarm.c"

//#define SERVER_HOST "141.166.207.144"  /* wallis IP address //MathCS01 */
//#define SERVER_HOST "141.166.207.143"  /* wallis IP address //MathCS02 */
#define SERVER_HOST "141.166.207.147"  /* wallis IP address //MathCS04 */
//#define SERVER_HOST "172.29.170.209"  /* wallis IP address //MyComputer */
#define SERVER_PORT "31201"

#define SA struct sockaddr

/* Miscellaneous constants */
#define	MAXLINE		4096	/* max text line length */
#define	MAXSOCKADDR  128	/* max socket address structure size */
#define	BUFFSIZE	8192	/* buffer size for reads and writes */
#define	LISTENQ		1024	/* 2nd argument to listen() */
#define SHORT_BUFFSIZE  100     /* For messages I know are short */
void DieWithError(char *errorMessage); /*Error handling function */
void HandleProj1Client(int cliSock, char *randString);
