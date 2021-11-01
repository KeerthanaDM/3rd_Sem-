# IMPLEMENTATION OF SMALLEST JOB FIRST

     #include<bits/stdc++.h>
    int main()
    {
      int bt[100],b[100],i,j;
      printf("Enter the number of processes:\n");
      int n;
      scanf("%d",&n);
      printf("Enter the burst times");
      for(i=0;i<n;i++)
      {
        scanf("%d",&bt[i]);
        b[i]=i+1;
      }
      int t,k;
      for(i=0;i<n-1;i++)
      {
        for(j=0;j<n-i-1;j++)
        {
          if(bt[j]>bt[j+1])
          {
            t=bt[j];
            bt[j]=bt[j+1];
            bt[j+1]=t;

            k=b[j];
            b[j]=b[j+1];
            b[j+1]=k;
          }

        }
      }
      int sum=0;
      float avg=0;
      int wait[100];
      wait[0]=0;
      for(i=1;i<=n;i++)
      {
        wait[i]=wait[i-1]+bt[i-1];
        printf("Waiting time for %d process is %d\n",b[i-1],wait[i-1]);
        sum+=wait[i-1];
        printf("Turnaround time :%d\n",wait[i-1]+bt[i-1]);
      }
      avg=sum/n;
      printf("The average waiting time is:%f",avg);

      return 0;
    }
