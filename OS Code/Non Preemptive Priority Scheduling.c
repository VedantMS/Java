// Non Preemptive Priority Scheduling

#include<stdio.h>

typedef struct process {
	
	int pid, priority;
	float at, bt, st, ft, wt, tat;
};

void display_qt(process p[], int n) {
	
	printf("\nPID\tAT\tBT\tP \n\n");
	for(int i = 0; i < n; i++) {
		printf("%d\t%.1f\t%.1f\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].priority);
	}
}

void npps(process p[], int n) {
	
	float time = 0;
	
	for(int i = 0; i < n - 1; i++) {
		for(int j = i + 1; j < n; j++) {
			if(p[i].at > p[j].at) {
				process a = p[i];
				p[i] = p[j];
				p[j] = a;
			}
		}
	}
	
	for(int i = 1; i < n - 1; i++) {
		for(int j = i + 1; j < n; j++) {
				if(p[i].priority > p[j].priority) {
					process a = p[i];
					p[i] = p[j];
					p[j] = a;
			}
		}
	}
	
	printf("Gantt Chart: \n0_");
	
	for(int i = 0; i < n; i++) {
		if(time < p[i].at) {
			time = p[i].at;
			printf("||_%.1f_", time);
		}
		
		p[i].st = time;
		p[i].ft = p[i].st + p[i].bt;
		p[i].tat = p[i].ft - p[i].at;
		p[i].wt = p[i].tat - p[i].bt;
		
		printf("P%d_%.1f_", p[i].pid, p[i].ft);
		time += p[i].bt;
	}
}

void display(process p[], int n) {
	
	float a = 0, b = 0;
	printf("\n\nPID\tAT\tBT\tP\tST\tFT\tWT\tTAT \n\n");
	for(int i = 0; i < n; i++) {
		printf("%d\t%.1f\t%.1f\t%d\t%.1f\t%.1f\t%.1f\t%.1f\n", p[i].pid, p[i].at, p[i].bt, p[i].priority, p[i].st, p[i].ft, p[i].wt, p[i].tat);
		a += p[i].wt;
		b += p[i].tat;
	}
	
	a /= n;
	b /= n;
	
	printf("\nAverage Wait Time: %.1f \nAverage Turn Around Time: %.1f", a, b);
}

int main() {
	
	process p[10];
	int n;
	
	printf("Enter Total Processes: ");
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++) {
		printf("Enter Process ID, Arrival Time, Burst Time, and Priority: ");
		scanf("%d%f%f%d", &p[i].pid, &p[i].at, &p[i].bt, &p[i].priority);
	}
	
	display_qt(p, n);
	
	npps(p, n);
	
	display(p, n);
	
	return 0;
}
