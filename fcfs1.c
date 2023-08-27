//--------------------with arival time------------------------//

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

struct fcfs {
  int pid, tt, bt, wt, at, ct;

} p[10];
int main() {
  int n, i, sum;
  float totaltt = 0, totalwt = 0;
  printf("enter the number of process:");
  scanf("%d", &n);
  printf("P#\t at\t bt\t ct\t tt\t wt\t\n");
  for (i = 0; i < n; i++) {
    p[i].pid=1;
    printf("\n arival time for process:P%d", i + 1);
    scanf("%d", &p[i].at);
    printf("\n Burst time for process:P%d", i + 1);
    scanf("%d", &p[i].bt);
  }

  sum = p[0].at;
  for (i = 0; i < n; i++) {
    sum = sum + p[i].bt;
    p[i].ct = sum;

    p[i].tt = p[i].ct - p[i].at;
    p[i].wt = p[i].tt - p[i].bt;

    totaltt += p[i].tt;
    totalwt += p[i].wt;
  }

  for (i = 0; i < n; i++) {
    printf("P%d\t %d\t %d\t %d\t %d\t %d\n", i + 1, p[i].at, p[i].bt, p[i].ct,
           p[i].tt, p[i].wt);
  }

  printf("\n toatl waiting time: %f", totalwt);
  printf("\n avg wt: %f", totalwt / n);
  printf("\n total tat: %f", totaltt);
  printf("\n avg tat: %f", totaltt / n);
  return 0;
}
