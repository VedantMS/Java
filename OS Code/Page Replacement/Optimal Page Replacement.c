// Optimal Page Replacement

#include<stdio.h>

int main() {
	
	int n, s[15] = {7, 5, 4, 8, 5, 7, 2, 3, 1, 3, 5, 9, 4, 6, 2};
	int pf = 0;
	
	printf("Enter Total Frames: ");
	scanf("%d", &n);
	
	int frame[n], memory[n][15], page_fault[15] = {0};
	
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
				page_fault[i] = 1;
				pf++;
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
					int far = -1, index = -1;
					
					for(int j = 0; j < n; j++) {
						int k;
						for(k = i + 1; k < 15; k++) {
							if(frame[j] == s[k])
								break;
						}
							
						if(k == 15) {
							index = j;
							far = k;
							break;
						}
						
						else if(k > far) {
							far = k;
							index = j;
						}
					}
					
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
		
	printf("\n\nFrames\n");
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 15; j++) {
			if(memory[i][j] == -1)
				printf("-\t");
			else
				printf("%d\t", memory[i][j]);
		}
		printf("\n");
	}
	
	printf("\nPage Faults: \n");
	for(int i = 0; i < 15; i++) {
		if(page_fault[i] == 1)
			printf("F\t");
		else
			printf("-\t");
	}
	
	printf("\n\nTotal Page Faults: %d", pf);
	
	return 0;
}
