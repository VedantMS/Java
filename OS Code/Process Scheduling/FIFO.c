// FIFO

#include<stdio.h>

typedef struct process{
	int pid;
	float at, bt, st, ft, wt, tat;
};

void display_qt(process p[], int n) {
	printf("\nPID\tST\tBT \n\n");
	for(int i = 0; i < n; i++) {
		printf("%d\t%.1f\t%.1f \n", p[i].pid, p[i].at, p[i].bt);
	}
}

void sort(process p[], int n) {
	for(int i = 0; i < n - 1; i++) {
		for(int j = i + 1; j < n; j++) {
			if(p[i].at > p[j].at) {
				process a = p[i];
				p[i] = p[j];
				p[j] = a;
			}
		}
	}
}

void fcfs(process p[], int n){
	float time = 0;
	
	printf("\nGantt Chart: \n0_");
	
	for(int i = 0; i < n; ) {
		
		if(p[i].at > time) {
			printf("|%d|_%f_", i, time);
			time = p[i].at;
		}
		
		p[i].st = time;
		p[i].ft = p[i].st + p[i].bt;
		p[i].tat = p[i].ft - p[i].at;
		p[i].wt = p[i].tat - p[i].bt;
		
		time += p[i].bt;
		printf("P%d_%.1f_", p[i].pid, p[i].ft);
		i++;
	}
}

void display(process p[], int n) {
	float a = 0, b = 0;
	
	printf("\n\nPID\tAT\tBT\tST\tWT\tFT\tTAT \n\n");
	
	for(int i = 0; i < n; i++) {
		printf("%d\t%.1f\t%.1f\t%.1f\t%.1f\t%.1f\t%.1f \n", p[i].pid, p[i].at, p[i].bt, p[i].st, p[i].wt, p[i].ft, p[i].tat);
		a += p[i].wt;
		b += p[i].tat;
	}
	
	printf("\nAverage Wait Time: %.1f Unit \nAverage Turn Around Time: %.1f Unit", a/n, b/n);
	
}

int main() {
	
	process p[10];
	int n;
	
	printf("Enter Total Processes: ");
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++) {
		printf("Enter Process ID, Arrival Time, and Burst Time: ");
		scanf("%d%f%f", &p[i].pid, &p[i].at, &p[i].bt);
	}
	
	display_qt(p, n);
	
	sort(p, n);
	
	display_qt(p, n);
	
	fcfs(p, n);
	
	display(p, n);
	
	return 0;
}
