#include<stdio.h>
#include<string.h>
#include<dirent.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<sys/resources.h>

/*
struct dirent {
	char d_name[];   // Name of the file or directory
	...
};
*/

int main() {
	
	DIR *dir;
	struct dirent *d;
	
	pid_t pid = fork();
	
	if(pid == 0) {
		while(1) {
			printf("\nmyshell$ ");
			fflush(stdout);
			
			char input[100];
			char a[4], b[1], c[100];
			
			fgets(input, sizeof(input), stdin);
			
			sscanf(input, "%s%s%s", a, b, c);
			
			dir = opendir(c);
			
			int count = 0;
			
			while((d = readdir(dir)) != NULL) {
				if(strcmp(b, "f") == 0)
					printf("%s\n", d->d_name);
				count++;
			}
			
			if(strcmp(b, "n") == 0)
				printf("\nTotal: %d", count);
		}
	}
	
	return 0;
}
