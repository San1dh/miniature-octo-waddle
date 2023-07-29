// program by AK Bharath to simulate Round Robin process scheduling algorithm in OS

#include<stdio.h> 
#include<stdlib.h> 

 typedef struct process { 
 	char name[5]; 
 	int bt; 
 	int at; 
 	int prt; 
 	int wt, ta; 
 	int flag; 
 } 
 processes; 

 void bubble_sort(processes proc[], int n) { 
 	processes t; 
 	int i, j; 
 	for (i = 1; i < n; i++) 
 		for (j = 0; j < n - i; j++) { 
 			if (proc[j].at > proc[j + 1].at) { 
 				t = proc[j]; 
 				proc[j] = proc[j + 1]; 
 				proc[j + 1] = t; 
 			} 
 		} 
 } 

int get_Processes(processes P[]) { 
 	int i, n; 
 	printf("\n Enter total no. of processes : "); 
 	scanf("%d", & n); 
 	for (i = 0; i < n; i++) { 
 		printf("\n PROCESS [%d]", i + 1); 
 		printf(" Enter burst time : "); 
 		scanf("%d", & P[i].bt); 
 		printf(" Enter arrival time : "); 
 		scanf("%d", & P[i].at); 
 	
 	} 
 	printf("\n B.T.\tA.T.\t"); 
 	for (i = 0; i < n; i++) 
 		printf("\n%d\t%d\t", P[i].bt, P[i].at ); 
 	return n; 
 } 

 void RR(processes P[], int n) { 
 	int pflag = 0, t, tcurr = 0, k, i, Q = 0; 
 	int sumw = 0, sumt = 0; 
 	float avgwt = 0.0, avgta = 0.0; 
 	processes proc1[10], proc2[10]; 
  
 	for (i = 0; i < n; i++) 
 		proc1[i] = P[i];  

 	bubble_sort(proc1, n); 
  
 	for (i = 0; i < n; i++) 
 		proc2[i] = proc1[i]; 
  
 	printf("\n Enter quantum time : "); 
 	scanf("%d", & Q); 
  
 	for (k = 0; ;k++) { 
 		if (k > n - 1) 
 			k = 0; 
 		if (proc1[k].bt > 0) 
 			printf("  %d  %s", tcurr, proc1[k].name); 
 		t = 0; 
 		while (t < Q && proc1[k].bt > 0) { 
 			t++; 
 			tcurr++; 
 			proc1[k].bt--; 
 		} 
 		if (proc1[k].bt <= 0 && proc1[k].flag != 1) { 
 			proc1[k].wt = tcurr - proc2[k].bt - proc1[k].at; 
 			proc1[k].ta = tcurr - proc1[k].at; 
 			pflag++; 
 			proc1[k].flag = 1; 
 			sumw += proc1[k].wt; 
 			sumt += proc1[k].ta; 
 		} 
 		if (pflag == n) 
 			break; 
 	} 
 	printf("  %d", tcurr); 
 	avgwt = (float) sumw / n; 
 	avgta = (float) sumt / n; 
 	printf("\n\n Average waiting time = %0.2f\n Average turn-around = %0.2f.", avgwt, avgta); 
 } 

int main() { 
 	processes P[10]; 
 	int ch, n; 
 	do { 
 		printf("\n\n SIMULATION OF CPU SCHEDULING ALGORITHMS by ak\n"); 
 		printf("\n Options:"); 
 		printf("\n 0. Enter process data."); 
 		printf("\n 1. Round Robin"); 
 		printf("\n 2. Exit\n Select : "); 
 		scanf("%d", & ch); 
 		switch (ch) { 
 			case 0: 
 				n = get_Processes(P); 
 				break; 
 			case 1: 
 				RR(P, n); 
 				break; 
 			case 2: 
 				exit(0); 
 		} 
 	} while (ch != 5); 
 	return 0; 
}
