#include<stdio.h>
int main()
{
    int p[20],at[20],pr[20],bt[20],tat,wt,t,i,n,x=0,temp,cpu=0;
    float stat=0,swt=0;
     printf("\n enter the number of processes: ");
     scanf("%d",&n);
     printf("\n enter the pno :");
     for(i=0;i<n;i++)
     {
     scanf("%d",&p[i]);
     }
     printf("\n enter the at :");
     for(i=0;i<n;i++)
     {
     scanf("%d",&at[i]);
     }
     printf("\n enter the bt :");
     for(i=0;i<n;i++)
     {
     scanf("%d",&bt[i]);
     }
     printf("\n enter the pr :");
     for(i=0;i<n;i++)
     {
     scanf("%d",&pr[i]);
     }
     printf("\np\tbt\tat\twt\ttat");
     while(x<n)
     {
       temp=1000;
       for(i=0;i<n;i++)
       {
           if(at[i]<=cpu&&p[i]!=0)
           {
               if(pr[i]<temp)
               {
                   temp=pr[i];
                   t=i;
               }
           }
       }
       cpu=cpu+bt[t];
       tat=cpu-at[t];
       wt=tat-bt[t];
       stat+=tat;
       swt+=wt;
       printf("\n%d\t%d\t%d\t%d\t%d",p[t],bt[t],at[t],wt,tat);
       p[t]=0;
       x++;
     }
  stat=stat/n;
  swt=swt/n;
  printf("\n avgwt:%f avgtat:%f",swt,stat);
}