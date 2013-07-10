#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include "lo/lo.h"

//tb/130427/130701/130710

/*
* dump string received as OSC message to terminal
* terminal 1: osctermd 9999
* terminal 2: oscsend localhost 9999 /display s "`shout 1234 1 1`"
*
* compile:
* $ gcc -o osctermd osctermd.c `pkg-config --cflags --libs liblo`
*/

lo_server_thread st;

void error(int num, const char *m, const char *path);
int string_handler(const char *path, const char *types, lo_arg **argv, int argc, void *data, void *user_data);
static void signal_handler(int sig);

int main (int argc, char *argv[])
{
	const char *listenPort;

	if (argc >= 2 && ( 
		strcmp(argv[1],"-h")==0 
		|| strcmp(argv[1],"--help")==0 
	))
	{
		printf("syntax: osctermd (<osc listen port>)\n\n");
		printf("default listening on port 7770\n\n");
		printf("messages with pattern '/display' sent to listen port are displayed in terminal\n\n");
		printf("example: in terminal 1: osctermd 8899\n");
		printf("         in terminal 2: oscsend localhost 8899 /display s 'abc'\n\n");
		return(0);
	}

	//listen port
	if (argc >= 2) 
	{
		listenPort=argv[1];
	}
	else
	{
		listenPort="7770";
	}

	st = lo_server_thread_new(listenPort, error);
	lo_server_thread_add_method(st, "/display", "s", string_handler, NULL);
	lo_server_thread_add_method(st, "/display", "si", string_handler, NULL);
	lo_server_thread_start(st);

	signal(SIGQUIT, signal_handler);
	signal(SIGTERM, signal_handler);
	signal(SIGHUP, signal_handler);
	signal(SIGINT, signal_handler);

	//run forever (ctrl+c to stop)
	while (1) 
	{
		sleep (1);
	}
} //end main

void error(int num, const char *msg, const char *path)
{
	printf("liblo server error %d in path %s: %s\n", num, path, msg);
}

int string_handler(const char *path, const char *types, lo_arg **argv, int argc, void *dat, void *user_data)
{
	//dump the recieved string with or without newline
	if(argc==2 && argv[1]->i==0)
	{
		printf("%s",&argv[0]->s);
	}
	else
	{
		printf("%s\n",&argv[0]->s);
	}

	fflush(stdout);
	return 0;
}

static void signal_handler(int sig)
{
	//reset terminal / screen
	printf("\ec");
	fflush(stdout);
	exit(0);
}
