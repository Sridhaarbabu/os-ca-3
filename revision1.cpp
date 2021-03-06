#include<stdio.h>
int main()
{
  printf("Shortest job first Scheduling \n");
  int n,i=0,j=0;
  printf("Enter Number of Processes : ");
  scanf("%d",&n ); 
  int bt[n],at[n],wt[n],tat[n];
  float priority[n],process[n],temp,ct[n],min,sum=0,sum2=0;
  float wait_final,turnaround_final,wait_avg,turnaround_avg;
  for(i=0;i<n;i++)
  {
    printf("Enter Burst Time for Process [%d] : ", i+1 );
    scanf("%d", &bt[i]);
    process[i]=i+1;
  }
  
  for(i=0;i<n;i++)
  {
  	printf("Enter Arrival Time for Process [%d] : ", i+1 );
    scanf("%d", &at[i] );
    process[i]=i+1;
  }

  printf("\n Entered Values are \n");
  printf(" Process | Arrival Time | Burst Time |\n");
  for(i=0;i<n;i++)
  {
    printf(" P[%0.0lf]   |       %d      |     %d      |\n",process[i],at[i],bt[i]);
  }
  printf("\n Sorting Processes by Arrivaltime using selection sort \n");
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      if(at[i]<at[j])
      {
        
        temp = bt[j];
        bt[j] = bt[i];
        bt [i] = temp;
	
	    temp = process[j];
        process[j] = process[i];
        process[i] = temp;

	    temp = at[j];
        at[j] = at[i];
        at[i] = temp;
      
      }
    }
  }
   printf("\n Now Values are \n");
  printf(" Process | Arrival Time | Burst Time |\n");
  for(i=0;i<n;i++)
  {
    printf(" P[%0.0lf]   |       %d      |     %d      |\n",process[i],at[i],bt[i]);
  }

  int k = 1;
  float b_time = 0;
  for(j=0;j<n;j++)
  {
    b_time = b_time + bt[j];
    min = bt[k];

    for(i=k;i<n;i++)
    {
      if((b_time >= at[i])&&(bt[i]<min))
      {
        temp = bt[k];
        bt[k] = bt[i];
        bt[i] = temp;

        temp = at[k];
        at[k] = at[i];
        at[i] = temp;

        temp = process[k];
        process[k] = process[i];
        process[i] = temp;
      }
    }
    k++;
  }
  wt[0] = 0;
  for(i=1;i<n;i++)
  {
    sum += bt[i-1];
    wt[i] = sum - at[i];
    wait_final = wait_final + wt[i]; 
  }
  wait_avg = wait_final/n;
  for(i=0;i<n;i++)
  {
    sum2 = sum2 + bt[i];
    tat[i] = sum2 - at[i];
    turnaround_final = turnaround_final + tat[i];
  }
  turnaround_avg=turnaround_final/n;
printf("\n Now Values are \n");
  printf(" Process | Arrival Time | Burst Time |  Waiting Time  |  Turn Around Time  |\n");
  for(i=0;i<n;i++)
  {
    printf("  P[%0.0lf]   |       %d      |     %d      |        %d       |         %d          |\n",process[i],at[i],bt[i],wt[i],tat[i]);
  } 

  /* formulae
    Priority = 1+ Waiting time / Estimated run time
  */ 
  ct[0] = bt[0];
  for(i=1;i<n;i++)
  {
    ct[i] = ct[i-1] + bt[i];
    printf("completion time is %f\n",ct[i]);
  }

  for(i=0;i<n;i++)
  {
    priority[i] = 1+wt[i]/ct[i];
    printf("priority is %f\n",priority[i]);
  }
  printf("\n Final Values are \n");
  printf(" Process | Arrival Time | Burst Time |  Waiting Time  |  Turn Around Time  |\n");
  printf("  P[%0.0lf]   |       %d      |     %d      |        %d       |         %d          |\n",process[0],at[0],bt[0],wt[0],tat[0]);
  for(i=n-1;i>0;i--)
  {
    printf("  P[%0.0lf]   |       %d      |     %d      |        %d       |         %d          |\n",process[i],at[i],bt[i],wt[i],tat[i]);
  }

  printf("\n Average Turn Around Time : %f",turnaround_avg);
  printf("\n Average Waiting Time     : %f\n",wait_avg);
  return 0;
}
