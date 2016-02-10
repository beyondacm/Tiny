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

void clienterror(int fd, char *cause, char *errnum,	char *shortmsg, char *longmsg)
{

	char buf[MAXLINE], body[MAXBUF];

	/* Build the HTTP response body */
	sprintf(body, "<html><title>Tiny Error</title>");
	sprintf(body, "%s<body bgcolor=""ffffff"">\r\n",body);
	sprintf(body, "%s%s: %s\r\n", body, errnum, shortmsg);
	sprintf(body, "%s<p>%s: %s\r\n",body, longmsg, cause);
	sprintf(body, "%s<hr><em>The Tiny Web Server</em>\r\n", body);

	/* Print the HTTP reponse */
	sprintf(buf, "HTTP/1.0 %s %s \r\n", errnum, shortmsg);
	Rio_writen(fd, buf, strlen(buf));
	sprintf(buf, "Content-type: text/html\r\n");
	Rio_writen(fd, buf, strlen(buf));
	sprintf(buf, "Content-length: %d\r\n\r\n", strlen(body));
	Rio_writen(fd, buf, strlen(buf));
	Rio_writen(fd, body, strlen(body));

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
