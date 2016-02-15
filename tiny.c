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
void serve_dynamic(int fd, char *filename, char *cgiargs);
void clienterror(int fd, char *cause, char *errnum, 
				char *shortmsg, char *longmsg);

int main(int argc, char **argv)
{
	//TODO

}


void doit(int fd)
{
	//TODO
	int is_static;
	struct stat sbuf;
	char buf[MAXLINE], method[MAXLINE], uri[MAXLINE], version[MAXLINE];
	char filename[MAXLINE], cgiargs[MAXLINE];
	rio_t rio;

	/* read request line and headers */
	Rio_readinitb(&rio, fd);
	Rio_readlineb(&rio, buf, MAXLINE);

	sscanf(buf, "%s %s %s", method, uri, version);
	if( strcasecmp(method, "GET") ) {
		clienterror(fd, method, "501", "Not Implemented",
				"Tiny does not implement this method");
		return ;
	}
	read_requesthdrs(&rio);

	/* Parse URI from GET request */

	is_static = parse_uri(uri, filename, cgiargs);
	if(stat(filename, &sbuf) < 0) {
		clienterror(fd, filename, "404", "Not found",
				"Tiny could't find this file");
		return;
	}
	
	if(is_static) {		/* Serve static content */
		if( !(S_ISREG(sbuf.st_mode)) || !(S_IRUSR & sbuf.st_mode)) {
			clienterror(fd, filename, "403", "Forbidden",
					"Tiny couldn't read the file");
			return;
		}
	} 
	else {	/* Serve dynamic content */
		if(!(S_ISREG(sbuf.st_mode)) || !(S_IXUSR & sbuf.st_mode)) {
			clienterror(fd, filename, "403", "Forbidden",
					"Tiny couldn't run the CGI program");
			return;
		}
		serve_dynamic(fd, filename, cgiargs);
	}

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
