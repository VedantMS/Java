#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/resources.h>
#include<sys/types.h>

int main() {
	
	char input[100];
	char a[6], b[1], c[10], d[10];
	
	pid_t pid = fork();
	
	if(pid == 0) {
		while(1) {
			printf("\nmyshell$ ");
			fflush(stdout);
			fgets(input, sizeof(input), stdin);
			
			sscanf(input, "%s%s%s%s", a, b, c, d);
			
			FILE *f = fopen(c, "r");
			
			char line[200];
			
			if(strcmp(b, "a") == 0) {
				int count = 1;
				while(fgets(line, sizeof(line), f)) {
					char *p = line;
					if(strstr(p, d) != NULL) {
						printf("Pattern found at line %d: %s", count, line);
					}
					count++;
				}
			}
			
			if(strcmp(b, "c") == 0) {
				int count = 0;
				while(fgets(line, sizeof(line), f) != NULL) {
					char *p = line;
					while((p = strstr(p, d)) != NULL) {
						p += strlen(d);
						count++;
					}
				}
				printf("Total Occurences: %d", count);
			}
		}
	}
	
	else {
		wait(NULL);
	}
	
	return 0;
}
