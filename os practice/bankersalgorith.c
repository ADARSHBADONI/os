#include <stdio.h>
#include <stdbool.h>

struct process_info
{
    int max[10];
    int allocated[10];
    int need[10];
};

int no_of_process,no_of_resources;


void input(struct process_info process[no_of_process],int available[no_of_resources])
{
	int i,j;
    for(i=0;i<no_of_process;i++)
    {
      printf("Enter process[%d] info\n",i);
     printf("Enter Maximum Need: ");
      for(j=0;j<no_of_resources;j++)
        scanf("%d",&process[i].max[j]);
     printf("Enter No. of Allocated Resources for this process: ");
      for(j=0;j<no_of_resources;j++)
      {
        scanf("%d",&process[i].allocated[j]); 

        process[i].need[j]= process[i].max[j] - process[i].allocated[j];
      }
    }
   printf("Enter Available Resources: ");
    for(i=0;i<no_of_resources;i++)
    {
      scanf("%d",&available[i]);
    }
}


void showTheInfo(struct process_info process[no_of_process])
{   int i,j;
    printf("\nPID\tMaximum\t\tAllocated\tNeed\n");
    for(i=0;i<no_of_process;i++)
    {
        printf("P[%d]\t",i);
        for(j=0;j<no_of_resources;j++)
           printf("%d ",process[i].max[j]);
        printf("\t\t");
        for(j=0;j<no_of_resources;j++)
           printf("%d ",process[i].allocated[j]); 
        printf("\t\t");
        for(j=0;j<no_of_resources;j++)
           printf("%d ",process[i].need[j]);
        printf("\n");

    }
}


bool applySafetyAlgo(struct process_info process[no_of_process],int available[no_of_resources],int safeSequence[no_of_process])
{  
   int i,j;
   bool finish[no_of_process];
   int work[no_of_resources];  
   for(i=0;i<no_of_resources;i++)
   {
      work[i]=available[i];      
   }
   for(i=0;i<no_of_process;i++)
     finish[i]=false;    
   bool proceed=true;
   int k=0;
   while(proceed)
   {
     proceed=false;
     for(i=0;i<no_of_process;i++)
     {    
         bool flag=true;
         
         if(finish[i]==false)
         {
           
           for(j=0;j<no_of_resources;j++)
           {
             
             if(process[i].need[j] <= work[j])
             {
               continue;
             }
             else
             {
               flag=false;  
               break;
             }
           }
           if(flag==false)
             continue;    
          
 
          for(j=0;j<no_of_resources;j++)   
            work[j]=work[j]+ process[i].allocated[j];
          finish[i]=true;
          safeSequence[k++]=i;
          proceed=true;   
          
         }
       }

     } 
     for( i=0;i<no_of_process&&finish[i]==true;i++)
     {
       continue;
     }
     if(i==no_of_process)
      return true;
     else
      return false;
}


bool isSafeState(struct process_info process[no_of_process],int available[no_of_resources],int safeSequence[no_of_process])
{
     
    if(applySafetyAlgo(process,available,safeSequence)==true)
      return true;
    return false;
   
}


int main()
{
   printf("Enter No of Process\n");
    scanf("%d",&no_of_process);
   printf("Enter No of Resource Instances in system\n");
    scanf("%d",&no_of_resources);
    int available[no_of_resources];
    int safeSequence[no_of_process];

    struct process_info process[no_of_process];
   
   printf("**********Enter details of processes************\n");

    input(process,available);


   showTheInfo(process);
    if(isSafeState(process,available,safeSequence))
    {
     int i;
     printf("\nSystem is in SAFE State\n");
     printf("Safe Sequence is: ");
     for(i=0;i<no_of_process;i++)
       printf("P[%d] ",safeSequence[i]);
  printf("1");
    }
    else{
      printf("0");
      }
   return 0;
}
