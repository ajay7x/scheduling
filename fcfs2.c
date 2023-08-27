//-------------without arival---------------//

#include <stdio.h>
#include <stdlib.h>

struct fcfs {
  int pid, bt, tt, wt, ct;
} p[10];

int main() {
  int n, i, totalwt = 0, totaltt = 0;

  printf("enter the no. process: ");
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    p[i].pid = 1;
    printf("\n enter the  bt:P%d:", i + 1);
    scanf("%d", &p[i].bt);
  }
  p[0].wt = 0;
  p[0].tt = p[0].bt;
  for (i = 0; i < n; i++) {
    p[i].wt = p[i - 1].wt + p[i - 1].bt;
    p[i].tt = p[i].wt + p[i].bt;

    totaltt += p[i].tt;
    totalwt += p[i].wt;

    p[i].ct = p[i].tt;
  }
  printf("P#\t bt\t ct\t wt\t tt\n");
  for (i = 0; i < n; i++) {
    printf("P%d\t %d\t %d\t %d\t %d\n", i + 1, p[i].bt, p[i].ct, p[i].wt,
           p[i].tt);
  }
  printf("\n total wt=%d", totalwt);
  printf("\n avg wt=%d", totalwt / n);
  printf("\n");
  printf("\n total tt=%d", totaltt);
  printf("\n avg tt=%d", totaltt / n);
  return 0;
}