#include<stdio.h>

int main() {
	
	int n;
	int s[15] = {3, 4, 5, 6, 3, 4, 7, 3, 4, 5, 6, 7, 2, 4, 6};
	int pf = 0, pfs[15] = {0};
	int index = 0;
	
	printf("Enter Total Frames: ");
	scanf("%d", &n);
	
	int frame[n];
	int memory[n][15];
	
	for(int i = 0; i < n; i++)
		frame[i] = -1;
	
	for(int i = 0; i < 15; i++) {
		int page = s[i];
		int flag = 0;
		
		for(int j = 0; j < n; j++)
			if(frame[j] == page) {
				flag = 1;
				break;
			}
			
		if(!flag) {
			frame[index] = page;
			index = (index + 1) % n;
			pfs[i] = 1;
			pf++;
		}
		
		for(int k = 0; k < n; k++)
			memory[k][i] = frame[k];
	}
	
	printf("\nReference String: \n");
	for(int i = 0; i < 15; i++)
		printf("%d\t", s[i]);
		
	printf("\n\nFrames: \n");
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 15; j++) {
			if(memory[i][j] == -1)
				printf("-\t");
			else
				printf("%d\t", memory[i][j]);
		}
		printf("\n");
	}
	
	printf("\n\nPage Faults: \n");
	for(int i = 0; i < 15; i++) {
		if(pfs[i] == 1)
			printf("F\t");
		else
			printf("-\t");
	}
		
	printf("\n\nTotal Page Faults: %d", pf);
	
	return 0;
}
