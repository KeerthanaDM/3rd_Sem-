   ## Implementation of Round Robin Scheduling Algorithm in C

    #include <stdio.h>
    void main()
    {
     int n, i,qt, count = 0, temp, sq = 0, bt[10], wt[10], tat[10], rem_bt[10];
     float awt = 0, atat = 0;
     printf("enter no of process\n");
     scanf("%d", &n);
     printf("enter burst time of process\n");
     for (i = 0; i < n; i++)
     {
      scanf("%d", &bt[i]);
      rem_bt[i] = bt[i];
     }
     printf("Enter quantum time\n");
     scanf("%d", &qt);
     while (1)
     {
      for (i = 0, count = 0; i < n; i++)
      {
       temp = qt;
       if (rem_bt[i] == 0)
       {
        count++;
        continue;
       }
       if (rem_bt[i] > qt)
       {
        rem_bt[i] = rem_bt[i] - qt;
       }
       else
       {
        if (rem_bt[i] >= 0)
        {
         temp = rem_bt[i];
         rem_bt[i] = 0;
        }
       }
       sq = sq + temp;
       tat[i] = sq;
      }
      if (n == count)
       break;
     }
     printf("\n process\t burst time\t turnaround time\t waiting time\n");
     for (i = 0; i < n; i++)
     {
      wt[i] = tat[i] - bt[i];
      awt = awt + wt[i];
      atat = atat + tat[i];
      printf("\n%d\t%d\t\t%d\t\t%d\n", i + 1, bt[i], tat[i], wt[i]);
     }
     awt = awt / n;
     atat = atat / n;
     printf("average waiting time is %f\n", awt);
     printf("average turnaround time is %f\n", atat);
    }

