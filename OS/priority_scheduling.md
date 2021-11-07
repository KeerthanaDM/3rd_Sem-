  ## Implementation of Non-preemptive priority scheduling in C

    #include<bits/stdc++.h>

    int main()
    {
      int bt[100],pri[100],b[100],wait[100],tat[100],i,j,temp;
      printf("\nEnter the number of processes:");
      int n;
      scanf("%d",&n);
      printf("\nEnter the burst times:");
      for(i=0;i<n;i++)
      {
      scanf("%d",&bt[i]);
      b[i]=i+1;
      }
      printf("\nEnter the priorities of the given processes(greater number less priority):");
      for(i=0;i<n;i++)
      scanf("%d",&pri[i]);

      for(i=0;i<n-1;i++)
      {
        for(j=0;j<n-i-1;j++)
        {
          if(pri[j]>pri[j+1])
          {
            temp=pri[j];
            pri[j]=pri[j+1];
            pri[j+1]=temp;

            temp=b[j];
            b[j]=b[j+1];
            b[j+1]=temp;

            temp=bt[j];
            bt[j]=bt[j+1];
            bt[j+1]=temp;
          }
          else if(pri[j]==pri[j+1])
          {
            if(bt[j]>bt[j+1])
            {
              temp=bt[j];
              bt[j]=bt[j+1];
              bt[j+1]=temp;

              temp=b[j];
              b[j]=b[j+1];
              b[j+1]=temp;
            }
          }
        }
      }

    int sum=0;
    float avg=0;
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
