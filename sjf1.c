//--------------without arival time------------

#include <stdio.h>
#include <stdlib.h>

struct sjf {
  int pid, bt, wt, tt;
} p[10];

int main() {
  int i, j, n;
  int totalwt = 0, totaltt = 0;
  struct sjf tmp;

  printf("enter the no. of process: ");
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    printf("\n enter the process id: P");
    scanf("%d", &p[i].pid);
    printf("\n enter the burst time of P%d:", i + 1);
    scanf("%d", &p[i].bt);
  }
  p[0].wt = 0;
  p[0].tt = p[0].bt;

  //....sorting.......
  for (i = 0; i < n - 1; i++) {
    for (j = i + 1; j < n; j++) {
      if (p[i].bt > p[j].bt) {
        tmp = p[i];
        p[i] = p[j];
        p[j] = tmp;
      }
    }
  }

  for (i = 0; i < n; i++) {
    p[i].wt = p[i - 1].wt + p[i - 1].bt;
    p[i].tt = p[i].wt + p[i].bt;
    totalwt += p[i].wt;
    totaltt += p[i].tt;
  }
  printf("pid\t bt\t wt\t tt\n");
  for (i = 0; i < n; i++) {
    printf("P%d\t %d\t %d\t %d\n", p[i].pid, p[i].bt, p[i].wt, p[i].tt);
  }
  printf("\n totat turn around time: %d", totaltt);
  printf("\n avg turn around time: %d", totaltt / n);
  printf("\n totat waiting time: %d", totalwt);
  printf("\n avg waiting time: %d", totalwt / n);
  return 0;
}
