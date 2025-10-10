// Round Robin Scheduling

#include<stdio.h>

typedef struct process {
	
	int pid;
	float at, bt, st, ft, wt, tat;
};

void display_qt(process p[], int n) {
	
	printf("\nPID\tAT\tBT \n\n");
	for(int i = 0; i < n; i++) {
		printf("%d\t%.1f\t%.1f\n", p[i].pid, p[i].at, p[i].bt);
	}
}

void rrs(process p[], int n, int q) {
	
	float time = 0;
	int flag = 1;
	float b_bt[10];
	
	for(int i = 0; i < n - 1; i++) {
		for(int j = i + 1; j < n; j++) {
			if(p[i].at > p[j].at) {
				process a = p[i];
				p[i] = p[j];
				p[j] = a;
			}
		}
	}
	
	for(int i = 0; i < n; i++) {
		p[i].st = -1;
		b_bt[i] = p[i].bt;
	}
	
	printf("Gantt Chart: \n0_");
	
	while(flag != 0) {
		flag = 0;
		
		for(int i = 0; i < n; i++) {
			
			if(b_bt[i] > 0) {
				
				flag++;
				
				if(time < p[i].at) {
					time = p[i].at;
					printf("||_%.1f_", time);
				}
				
				if(p[i].st == -1)
					p[i].st = time;
				
				if(b_bt[i] <= q) {
					time += b_bt[i];
					printf("P%d_%.1f_", p[i].pid, time);
					p[i].ft = time;
					b_bt[i] = 0;
				}
				
				else {
					b_bt[i] -= q;
					time += q;
					printf("P%d_%.1f_", p[i].pid, time);
				}
			}
		}
	}
	
	for(int i = 0; i < n; i++) {
		p[i].tat = p[i].ft - p[i].at;
		p[i].wt = p[i].tat - p[i].bt;
	}
}

void display(process p[], int n) {
	
	float a = 0, b = 0;
	printf("\n\nPID\tAT\tBT\tST\tFT\tWT\tTAT \n\n");
	for(int i = 0; i < n; i++) {
		printf("%d\t%.1f\t%.1f\t%.1f\t%.1f\t%.1f\t%.1f\n", p[i].pid, p[i].at, p[i].bt, p[i].st, p[i].ft, p[i].wt, p[i].tat);
		a += p[i].wt;
		b += p[i].tat;
	}
	
	a /= (float) n;
	b /= (float) n;
	
	printf("\nAverage Wait Time: %.1f \nAverage Turn Around Time: %.1f", a, b);
}

int main() {
	
	process p[10];
	int n;
	int q;
	
	printf("Enter Total Processes: ");
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++) {
		printf("Enter Process ID, Arrival Time, and Burst Time: ");
		scanf("%d%f%f", &p[i].pid, &p[i].at, &p[i].bt);
		p[i].bt = p[i].bt;
	}
	
	printf("Enter Time Quantum: ");
	scanf("%d", &q);
	
	display_qt(p, n);
	
	rrs(p, n, q);
	
	display(p, n);
	
	return 0;
}

