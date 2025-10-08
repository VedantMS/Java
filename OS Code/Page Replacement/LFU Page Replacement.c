// LFU Page Replacement

#include<stdio.h>

int lfu(int s[], int frame[], int i, int n) {
	
	int temp[n] = {0};
	
	for(int j = 0; j < n; j++) {
		for(int k = 0; k < i; k++) {
			if(frame[j] == s[k])
				temp[j]++;
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
	
	int s[15] = {3, 4, 5, 4, 3, 4, 7, 2, 4, 5, 6, 7, 2, 4, 6};
	int n, pf, pfs[15] = {0};
	
	printf("Enter Total Frames: ");
	scanf("%d", &n);
	
	int frame[n], memory[n][15];
	
	for(int i = 0; i < n; i++) {
		frame[i] = -1;
	}
		
	for(int i = 0; i < 15; i++) {
		int flag = 0;
		int page = s[i];
		
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
				if(frame[j] == -1) {
					empty = j;
					break;
				}
			}
			
			if(empty != -1) {
				frame[empty] = page;
			}
			
			else {
				int index;
				index = lfu(s, frame, i, n);
				frame[index] = page;
			}
		}
		
		for(int j = 0; j < n; j++) {
			memory[j][i] = frame[j];
		}
	}
	
	printf("\nReference String: \n");
	for(int i = 0; i < 15; i++) {
		printf("%d\t", s[i]);
	}
	
	printf("\n\nFrames: \n");
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 15; j++) {
			printf("%d\t", memory[i][j]);
		}
		printf("\n");
	}
	
	printf("\nPage Faults: \n");
	for(int i = 0; i < 15; i++) {
		printf("%d\t", pfs[i]);
	}
	
	printf("\n\n Total Page Faults: %d", pf);
	
	return 0;
}
