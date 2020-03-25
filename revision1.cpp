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
  return 0;
}
