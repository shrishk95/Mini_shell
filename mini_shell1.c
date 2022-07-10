#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

void myCatFun(char fname[])
{	
	int fd;
	fd = open(fname,O_RDONLY);
	if (fd == -1)
		printf("%s No such file or directory\n",fname);
	else
		{
			char ch;
			int k;
			while(1)
			{

				k=read(fd,&ch,1);
				if (k == 0)
					break;
				else
					printf("%c",ch);

			}
			close(fd);
		}

}

void myHeadFun(char fname[])
{
	
	int fd;
	int l=0;
	fd = open(fname,O_RDONLY);
	if (fd == -1)
		printf("%s No such file or directory\n",fname);
	else
		{
			char ch;
			int k;
			while(1)
			{

				k=read(fd,&ch,1);
				if (k == 0)
					break;
				
				else if(ch =='\n')
				{
					printf("\n");
					l = l+1;
			
				}
				else if(l == 10)
				{
					break;
				}
				else
					printf("%c",ch);
				

			}
			close(fd);
		}
	
}

void myTailFun(char fname[])
{
	
	int fd;
	int l=0;
	int total_line =0;
	fd = open(fname,O_RDONLY);
	if (fd == -1)
		printf("%s No such file or directory\n",fname);
	else
		{
			char ch;
			int k,k1,k2;
			while(1)
			{
				k=read(fd,&ch,1);
				if (k== 0)
					break;
				else if(ch =='\n')
					total_line = total_line + 1;
			}
			lseek(fd,0,SEEK_SET);
		
			while(1)
			{
				
				if (total_line <=10 )
				{
					
					k1=read(fd,&ch,1);
					if (k1 == 0)
						break;
					else
						printf("%c",ch);
				}
				else
				{
					k2=read(fd,&ch,1);
					if (k2 == 0)
						break;
				
					else if(ch =='\n')
					{
						//printf("\n");
						l = l+1;
						if (l>total_line - 10)
							printf("\n");
			
					}

					else if(l>=total_line - 10)
						printf("%c",ch);
				}

			}
			close(fd);
		}
	
}


void myCpFun(char fname[],char fdest[])
{
	
	char ch;
	int k,fd1,fd2;

	fd1=open(fname,O_RDONLY);
	if(fd1==-1)
	{
		printf("Source file not found, copy not possible\n");
		exit(0);
	}
	else
	{
		fd2=open(fdest,O_WRONLY|O_CREAT,0666);
		while(1)
		{
			k=read(fd1,&ch,1);
			if(k==0)
				break;
			else
				write(fd2,&ch,1);
		}
		close(fd1);
		close(fd2);
		
	}
}

int myRmFun(char fname[])
{
	remove(fname);
}

void myMvFun(char fname[],char fdest[])
{
	
	char ch;
	int k,fd1,fd2;

	fd1=open(fname,O_RDONLY);
	if(fd1==-1)
	{
		printf("Source file not found, copy not possible\n");
		exit(0);
	}
	else
	{
		fd2=open(fdest,O_WRONLY|O_CREAT,0666);
		while(1)
		{
			k=read(fd1,&ch,1);
			if(k==0)
				break;
			else
				write(fd2,&ch,1);
		}
		close(fd1);
		close(fd2);
	}
	remove(fname);
}

void myHistory(char fname[])
{
	
	int fd;
	int l=0;
	int total_line =0;
	fd = open(fname,O_RDONLY);
	if (fd == -1)
		printf("%s No such file or directory\n",fname);
	else
		{
			char ch;
			int k,k1,k2;
			while(1)
			{
				k=read(fd,&ch,1);
				if (k== 0)
					break;
				else if(ch =='\n')
					total_line = total_line + 1;
			}
			lseek(fd,0,SEEK_SET);
		
			while(1)
			{
				
				if (total_line <=50 )
				{
					
					k1=read(fd,&ch,1);
					if (k1 == 0)
						break;
					else
						printf("%c",ch);
				}
				else
				{
					k2=read(fd,&ch,1);
					if (k2 == 0)
						break;
				
					else if(ch =='\n')
					{
						//printf("\n");
						l = l+1;
						if (l>total_line - 50)
							printf("\n");
			
					}

					else if(l>=total_line - 50)
						printf("%c",ch);
				}

			}
			close(fd);

		}

}


int main()
{	
	char cmd[20],fname[20],fdest[20];
	system("clear");

	while(1)
	{
	printf("Mini_Shell$");
	scanf("%s",cmd);
	//scanf("%s",fdest);

	int i;
	i=open("history",O_WRONLY|O_APPEND);
	write(i,cmd,strlen(cmd));
	write(i,"\n",strlen("\n"));

	if(strcmp(cmd,"mycat") == 0)
	{
		scanf("%s",fname);
		myCatFun(fname);
	}

        else if(strcmp(cmd,"myhead") == 0)
	{
		scanf("%s",fname);
		myHeadFun(fname);
	}

	else if(strcmp(cmd,"mytail") == 0)
	{
		scanf("%s",fname);
		myTailFun(fname);
	}
	else if(strcmp(cmd,"show") == 0)
	{
		scanf("%s",fname);
		myHistory(fname);
	}
	else if(strcmp(cmd,"mycp") == 0)
	{	
		scanf("%s",fname);
		scanf("%s",fdest);
		myCpFun(fname,fdest);
	}
	else if(strcmp(cmd,"myrm") == 0)
	{
		scanf("%s",fname);
		myRmFun(fname);
	}
	else if(strcmp(cmd,"mymv") == 0)
	{	
		scanf("%s",fname);
		scanf("%s",fdest);
		myMvFun(fname,fdest);
	}
	else if(strcmp(cmd,"exit") == 0)
	{
		break;
	}	
	else 
	{
		printf("Invalid command\n");
	}
	}
}


