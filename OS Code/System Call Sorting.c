#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<sys/resource.h>

void i_sort(int a[], int n) {
    for(int i = 1; i < n; i++) {
            int t = a[i];
            int j;
            for(j = i - 1; j >= 0 && a[j] > t; j--) {
                a[j + 1] = a[j];
            }
            a[j + 1] = t;
        }

        printf("\n\nInsertion Sorted Array: ");
        for(int i = 0; i < n; i++) {
                printf("%d\t", a[i]);
        }
}


void b_sort(int a[], int n) {
    int flag = 1;
        while(flag != 0) {
            flag = 0;
            for(int i = 0; i < n - 1; i++) {
                if(a[i] < a[i + 1]) {
                    int t = a[i];
                    a[i] = a[i + 1];
                    a[i + 1] = t;
                    flag++;
                }
            }
        }

        printf("\n\nBubble Sorted Array: ");
        for(int i = 0; i < n; i++) {
            printf("%d\t", a[i]);
        }
}

int main() {
	
	int n;
    printf("Enter Total Elements: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter Elements: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    pid_t pid = fork();
    
    if(pid == 0) {
		b_sort(a, n);
	}
	
	if(pid > 0) {
        wait(NULL);
	    i_sort(a, n);
	}
	
	return 0;
}
