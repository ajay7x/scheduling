//------------with arival time----------//

#include <stdio.h>
#include <stdlib.h>
struct sjf {
  int pid, bt, at, wt, tt;
} p[10];
int main() {
  int i, j, n;
  struct sjf temp;
  float totaltt = 0, totalwt = 0;

  printf("enter the no. of process:");
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    printf("\n enter the process id :P");
    scanf("%d", &p[i].pid);
    printf("\n enter the at of P%d: ", i + 1);
    scanf("%d", &p[i].at);
    printf("\n enter the bt of P%d: ", i + 1);
    scanf("%d", &p[i].bt);
  }

  //----------sorting-----------
  for (i = 0; i < n - 1; i++) {
    for (j = i + 1; j < n; j++) {
      if (p[i].at > p[j].at) {
        temp = p[i];
        p[i] = p[j];
        p[j] = temp;
      }
    }
  }

  int ct = 0;
  for (i = 0; i < n; i++) {
    int sht = i;
    for (j = i + 1; j < n; j++) {
      if (p[j].at <= ct && p[j].bt < p[sht].bt) {
        sht = j;
      }
    }
    temp = p[i];
    p[i] = p[sht];
    p[sht] = temp;

    p[i].wt = ct - p[i].at;
    if (p[i].wt < 0) {
      ct = p[i].at;
      p[i].wt = 0;
    }
    ct += p[i].bt;
    p[i].tt = p[i].wt + p[i].bt;
    totaltt += p[i].tt;
    totalwt += p[i].wt;
  }
  printf("\np#\t at\t bt\t tt\t wt\n");
  for (i = 0; i < n; i++)
    printf("P%d\t %d\t %d\t %d\t %d\n", p[i].pid, p[i].at, p[i].bt, p[i].tt,
           p[i].wt);

  printf("\n total tt: %f", totaltt);

  printf("\n avg tt:%f", totaltt / n);
  printf("\n total wt: %f", totalwt);
  printf("\n avg tt:%f", totalwt / n);

  return 0;
}
