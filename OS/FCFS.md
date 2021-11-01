# FIRST COME FIRST SERVE IMPLEMENTATION
Code includes the implementation of FCFS with arrival time in C.

    #include<bits/stdc++.h>
    int main()
    {
      int bt[100],i,sum=0,arrtime[100];
      float avg=0;
      printf("Enter the number of processes:\n");
      int n;
      scanf("%d",&n);
      printf("Enter the burst times:");
      for(i=0;i<n;i++)
        scanf("%d",&bt[i]);
      printf("\nEnter the arrival times:");
      for(i=0;i<n;i++)
        scanf("%d",&arrtime[i]);
      int j;
      float s;
      int wait[100];
      wait[0]=0;
      for(i=0;i<n;i++)
      {
        for(j=0;j<n-i-1;j++)
        {
          if(arrtime[j+1]<arrtime[j])
          {
          int t=arrtime[j];
          arrtime[j]=arrtime[j+1];
          arrtime[j+1]=t;

          int k=bt[j];
          bt[j]=bt[j+1];
          bt[j+1]=k;
          }
        }
      }

      for(j=1;j<=n;j++)
      {

        wait[j]=wait[j-1]+bt[j-1]-arrtime[j ];
        printf("Waiting time for %d process is %d\n",j,wait[j-1]);
        sum+=wait[j-1];
            printf("Turnaround time :%d\n",wait[j-1]+bt[j-1]);
            s+=wait[j-1]+bt[j-1] ;
      }

      avg=sum/n;
      float a=s/n;
      printf("The average of wait times is %fms\n",avg);
      printf("Average turnover time is %fms",a);
      return 0;

    }
