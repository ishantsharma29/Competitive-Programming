#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>
#include <pthread.h>
#define MYPORT 8081    
#define BACKLOG 10     
#define MAXDATASIZE 1000

void sigchld_handler(int s)
{
    while(wait(NULL) > 0);
}

void* httpRequest(void* data)
{
    int me = *((int*)data);
        char buf[MAXDATASIZE],requestLine[100],tmp[20];
        int a=0,k=0,b=0,received=-1;

        if ((received = recv(me, buf, 100, 0)) < 0)
        {
                perror("Failed to receive initial bytes from client");
        }
        buf[received-1]='\0';

        while(buf[a]!= '\n')
        requestLine[a]=buf[a++];
        while(requestLine[b] != ' ')
        tmp[b]= requestLine[b++];
        if (strcmp(tmp,"GET")==0)
        {

               char *fileName,*fl1,*fl2;
               fl1=strpbrk(requestLine,"/");
               fl2=strtok(fl1," ");
               fileName=strpbrk(fl2,"/");
              char document_root[10]="./html";
      if(strcmp(fileName,"/")==0)
        strcpy(fileName,strcat(document_root,"/index.html"));
    else
        strcpy(fileName,strcat(document_root,fileName));
         FILE *fp;
    int file_exist=1;
    fp=fopen(fileName, "r");       
    if (fp==NULL)   
             file_exist=0;

    char *filetype;
    char *type;
        int s='.';
    filetype=strrchr(fileName,s);
            if((strcmp(filetype,".htm"))==0 || (strcmp(filetype,".html"))==0)
            type="text/html";
        else if((strcmp(filetype,".jpg"))==0)
            type="image/jpeg";
        else if(strcmp(filetype,".gif")==0)
            type="image/gif";
        else if(strcmp(filetype,".txt")==0)
            type="text/plain";
        else if((strcmp(filetype,".ram")==0) || (strcmp(filetype,".ra")==0))
            type="audio/x-pn-realaudio";
        else
            type="application/octet-stream";
            char statusLine[100]="HTTP/1.0";
        char contentTypeLine[100]="Content-type: ";
        char entityBody[100]="<html>";
        if(file_exist==1)
        {
      
            strcpy(statusLine,strcat(statusLine,"200 OK"));
            strcpy(statusLine,strcat(statusLine,"\r\n"));
            strcpy(contentTypeLine,strcat(contentTypeLine,type));
            strcpy(contentTypeLine,strcat(contentTypeLine,"\r\n"));
        }
        else
        {
            strcpy(statusLine,strcat(statusLine,"404 Not Found"));
            strcpy(statusLine,strcat(statusLine,"\r\n"));
     
            strcpy(contentTypeLine,strcat(contentTypeLine,"NONE"));
            strcpy(contentTypeLine,strcat(contentTypeLine,"\r\n"));   
  
            strcpy(entityBody,strcat(entityBody,"<HEAD><TITLE>404 Not Found</TITLE></HEAD>"));
            strcpy(entityBody,strcat(entityBody,"<BODY>Not Found</BODY></html>"));
            strcpy(entityBody,strcat(entityBody,"\r\n"));   
        }
      if ((send(me, statusLine,strlen(statusLine), 0) == -1) ||
                (send(me, contentTypeLine, strlen(contentTypeLine),0) == -1) ||
            (send(me,"\r\n", strlen("\r\n"), 0) == -1))
                        perror("Failed to send bytes to client");
          if (file_exist)
        {
            wchar_t read_char[1];
            while((read_char[0]=fgetc(fp))!=EOF)
            {    
                if(send(me,read_char,sizeof(char),0) == -1)
                    perror("Failed to send bytes to client");       
            }
        }
        else
        {
            if (send(me, entityBody, 100, 0) == -1)
                        perror("Failed to send bytes to client");          
               }
        close(me);       
        pthread_exit(NULL);
    }
    else
        printf("Warning message\n");
}

int main (void)
{
    int sockfd, new_fd;  
    struct sockaddr_in my_addr;    
    struct sockaddr_in their_addr; 
    int sin_size;
    struct sigaction sa;
    int yes=1;
    pthread_t p_thread[3000];
    int thr_id,i=0;     
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    if (setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR,&yes,sizeof(int)) == -1) {
        perror("setsockopt");
        exit(1);
    }

    my_addr.sin_family = AF_INET;         
    my_addr.sin_port = htons(MYPORT);     
    my_addr.sin_addr.s_addr = INADDR_ANY; 
    memset(&(my_addr.sin_zero), '\0', 8); 

    if (bind(sockfd, (struct sockaddr *)&my_addr, sizeof(struct sockaddr))== -1) {
        perror("bind");
        exit(1);
    }
    
    if (listen(sockfd, BACKLOG) == -1) {
        perror("listen");
        exit(1);
    }
    sa.sa_handler = sigchld_handler; 
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;
    if (sigaction(SIGCHLD, &sa, NULL) == -1) {
        perror("sigaction");
        exit(1);
    }
    while(1)
   {  
        sin_size = sizeof(struct sockaddr_in);
        if ((new_fd = accept(sockfd, (struct sockaddr *)&their_addr,&sin_size)) == -1) {
            perror("accept");
            continue;
        }
   
    thr_id = pthread_create(&p_thread[i++],NULL,httpRequest,(void*)&new_fd);
   }
    return 0;
}
