// Non Preemptive SJF

#include<stdio.h>

typedef struct process {
	int pid;
	float at, bt, st, wt, ft, tat;
};

void display_qt(process p[], int n) {
	
	printf("\nPID\tAT\tBT \n\n");
	
	for(int i = 0; i < n; i++) {
		printf("%d\t%.1f\t%.1f \n", p[i].pid, p[i].at, p[i].bt);
	}
}

void sort(process p[], int n) {
	
	for(int i = 1; i < n; i++) {
		if(p[0].at > p[i].at) {
			process a = p[0];
			p[0] = p[i];
			p[i] = a;
		}
	}
	
	for(int i = 1; i < n - 1; i++) {
		for(int j = i + 1; j < n; j++) {
			if(p[i].bt > p[j].bt) {
				process a = p[i];
				p[i] = p[j];
				p[j] = a;
			}
		}
	}
}

void npsjf(process p[], int n) {
	
	float time = 0;
	
	printf("\nGantt Chart: \n0_");
	
	for(int i = 0; i < n; i++) {
		if(p[i].at > time) {
			printf("||_%.1f_", time);
			time = p[i].at;
		}
		
		p[i].st = time;
		p[i].ft = p[i].st + p[i].bt;
		p[i].tat = p[i].ft - p[i].at;
		p[i].wt = p[i].tat - p[i].bt;
		
		time += p[i].bt;
		printf("P%d_%.1f_", p[i].pid, p[i].ft);
	}
}

void display(process p[], int n) {
	
	float a = 0, b = 0;
	
	printf("\nPID\tAT\tBT\tST\tFT\tWT\tTAT \n\n");
	
	for(int i = 0; i < n; i++) {
		printf("%d\t%.1f\t%.1f\t%.1f\t%.1f\t%.1f\t%.1f \n", p[i].pid, p[i].at, p[i].bt, p[i].st, p[i].ft, p[i].wt, p[i].tat);
		a += p[i].wt;
		b += p[i].tat;
	}
	a /= n;
	b /= n;
	
	printf("\nAverage Wait Time: %.1f \nAverage Turn Around Time: %.1f", a , b);
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
	
	npsjf(p, n);
	
	display(p, n);
	
	return 0;
	
}

