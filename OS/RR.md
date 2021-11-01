  ## Implementation of Round Robin Scheduling Algorithm in C

    #include<bits/stdc++.h>
    int main()
    {
      int n,bt[100],qt,count,i,wait[100];
      printf("\nEnter the number of processes:");
      scanf("%d",&n);
      printf("\n Enter the burst times:");
      for(i=0;i<n;i++){
      scanf("%d",&bt[i]);
      wait[i]=0;
      }
      printf("\nEnter the quantum time:");
      scanf("%d",&qt);

      int rembt[100],a[100];
      for(i=0;i<n;i++)
      {
      rembt[i]=bt[i];
      a[i]=0;
      }
      while(1)
      {
        for(i=1;i<=n;i++)
        {

          if(rembt[i-1]==0)
          {
          count++;
          continue;
          }
          else if(rembt[i-1]<=qt)
          {
            wait[i]=wait[i-1]+rembt[i];
            rembt[i-1]=0;
            count++;
            a[i]++;
            printf("\n%d",wait[i]);
          }
          else
          {
          rembt[i-1]-=qt;
          wait[i]=wait[i-1]+rembt[i];
          printf("\n%d",wait[i]);
          a[i]++;
          }
        }
        if(count == n)
        break;
      }
      int avg=0;
      for(i=0;i<n;i++)
      {
        avg+=wait[i]-(qt*a[i]);
        printf("**\t%d",avg);
      }
      printf("\nAverage waiting time:%d",avg/n);
      return 0;
    }
