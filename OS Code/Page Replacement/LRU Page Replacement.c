// LRU Page Replacement

#include<stdio.h>

int lru(int s[], int frame[], int n, int i) {
	
	int temp[n];
	
	for(int j = 0; j < n; j++)
		temp[j] = -1;
		
	for(int j = 0; j < n; j++) {
		for(int k = i - 1; k >= 0; k--) {
			if(frame[j] == s[k]) {
				temp[j] = k;
				break;
			}
		}
	}
	
	int min = temp[0], pos = 0;
	for(int j = 1; j < n; j++) {
		if(min > temp[j]) {
			min = temp[j];
			pos = j;
		}
	}
	
	return pos;
}

int main() {
	
	int s[15] = {3, 5, 7, 2, 5, 1, 2, 3, 1, 3, 5, 3, 1, 6, 2};
	int pf = 0, n;
	int pfs[15] = {0};
	
	printf("Enter Total Frames: ");
	scanf("%d", &n);
	
	int frame[n], memory[n][15];
	
	for(int i = 0; i < n; i++)
		frame[i] = -1;
		
	for(int i = 0; i < 15; i++) {
		int page = s[i];
		int flag = 0;
		
		for(int j = 0; j < n; j++) {
			if(frame[j] == page) {
				flag = 1;
				break;
			}
		}
		
		if(!flag) {
			pf++;
			pfs[i] = 1;
			
			int empty = -1;
			for(int j = 0; j < n; j++) {
				if(frame[j] == empty) {
					empty = j;
					break;
				}
			}
			
			if(empty != -1) {
				frame[empty] = page;
			}
			
			else {
				int index = lru(s, frame, n, i);
				frame[index] = page;
			}
		}
		
		for(int j = 0; j < n; j++) {
			memory[j][i] = frame[j];
		}
	}
	
	printf("\n\nReference String: \n");
	for(int i = 0; i < 15; i++)
		printf("%d\t", s[i]);
		
	printf("\n\nFrames: \n");
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 15; j++) {
			printf("%d\t", memory[i][j]);
		}
		printf("\n");
	}
	
	printf("\nPage Faults: \n");
	for(int i = 0; i < 15; i++)
		printf("%d\t", pfs[i]);
		
	printf("\n\nPage Faults: %d", pf);
	
	return 0;
}
