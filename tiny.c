/*
 *	tiny.c - A simple, iterative HTTP/1.0 Web server 
 *	that uses GET method serve static and dynamic content.
 */

#include "csapp.h"

void doit(int fd);
void read_requesthdrs(rio_t *rp);
int parse_uri(char *uri, char *filename, char *cgiargs);
void serve_static(int fd, char *filename, int fileszie);
void get_filetype(char *filename, char *filetype);
void clienterror(int fd, char *cause, char *errnum, 
				char *shortmsg, char *longmsg);

int main(int argc, char **argv)
{
	//TODO

}


void doit(int fd)
{
	//TODO
}

void clienterror(int fd, char *cause, char *errnum,
				char *shortmsg, char *longmsg)
{
	//TODO
}

void read_requesthdrs(rio_t *rp)
{
	//TODO
}

int parse_uri(char *uri, char *filename, char *cgiargs)
{
	//TODO
}

void serve_static(int fd, char *filename, int filesize)
{
	//TODO
}

void serve_dynamic(int fd, char *filename, char *cgiargs)
{
	//TODO
}
