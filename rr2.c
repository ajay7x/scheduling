//--------with arrival time---------

#include <stdio.h>
#include <stdlib.h>
struct rr {
  int pid, at, bt, tbt, tt, wt;
} p[20];

int main() {
  int i, n, x, y, tq;
  float totaltt = 0, totalwt = 0;

  printf("enter the no. of process: ");
  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    printf("\n enter the process id:");
    scanf("%d", &p[i].pid);
    printf("\n enter the arrival time of process:P%d:", i + 1);
    scanf("%d", &p[i].at);
    printf("\n enter the burst time of process:P%d:", i + 1);
    scanf("%d", &p[i].bt);
    p[i].tbt = p[i].bt;
  }

  printf("enter time quandam:");
  scanf("%d", &tq);

  x = 0; // to increase the tq
  y = 0; // how many process completed
  i = 0; // at precent which process is executing

  while (1) {
    if (p[i].bt > 0) {
      if (p[i].bt > tq) {
        p[i].bt = p[i].bt - tq;
        x = x + tq;
      } else {
        x = x + p[i].bt;
        p[i].bt = 0;

        p[i].tt = x - p[i].at;
        p[i].wt = p[i].tt - p[i].tbt;

        y++;
        if (y == n)
          break;
      }
    }

    if (i == n - 1)
      i = 0;

    else if (p[i + 1].at <= x)
      i = i + 1;

    else

      i = 0;
  }

  printf("P#\t bt\t tt\t wt\n");
  for (i = 0; i < n; i++) {
    totaltt += p[i].tt;
    totalwt += p[i].wt;
    printf("P%d\t %d\t %d\t %d\n", p[i].pid, p[i].tbt, p[i].tt, p[i].wt);
  }

  printf("\n total turn around time:%f", totaltt);
  printf("\n avg turn around time:%f", totaltt / n);
  printf("\n total waiting time:%f", totalwt);
  printf("\n avg waiting time:%f", totalwt / n);

  return 0;
}