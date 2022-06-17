#ifndef __FIRST__COME__FIRST__SERVED__
#define __FIRST__COME__FIRST__SERVED__


#include "./Process.h"
#include "./SortingFunction.h"
#include "./PrintTable.h"



void fcfs_print_gantt_chart(Process *p, int len)
{
	puts("                    FCFS");
    int i, j;
    printf("\t ");
    for (i = 0; i < len; i++)
    {
        for (j = 0; j < p[i].burst; j++)
            printf("--");

        printf(" ");
    }

    printf("\n\t|");


    for (i = 0; i < len; i++)
    {
        for (j = 0; j < p[i].burst - 1; j++)
            printf(" ");

        printf("%s", p[i].id);

        for (j = 0; j < p[i].burst - 1; j++)
            printf(" ");

        printf("|");
    }

    printf("\n\t ");

    for (i = 0; i < len; i++)
    {
        for (j = 0; j < p[i].burst; j++)
            printf("--");

        printf(" ");
    }

    printf("\n\t");


    printf("0");

    for (i = 0; i < len; i++)
    {
        for (j = 0; j < p[i].burst; j++)
            printf("  ");

        if (p[i].return_time > 9)
            printf("\b");

        printf("%d", p[i].return_time);

    }

    printf("\n");
}


void FCFS(Process *p, int len)
{
    merge_sort_by_arrive_time(p,0,len);
    int i,j;
    int cont_reponse, cont_bruts, total_waiting_time, total_turnaround_time,total_response_time;
    process_init(p,len);
    for (i=0;i<len;i++){
	
		for(j=0;j<=i;j++){
			
			cont_bruts+=p[j].burst;
		
		}
		p[i].return_time=cont_bruts;
		cont_bruts=0;
		if(i==0){
			
			p[i].turnaround_time=p[i].burst+p[i].waiting_time;
			p[i].response_time=0;
			p[i].waiting_time=0;
			
			
		}
		if(i!=0){
			
			p[i].waiting_time=p[i-1].return_time-p[i].arrive_time;
			p[i].response_time=p[i-1].return_time-p[i].arrive_time;
			p[i].turnaround_time=p[i].burst+p[i].waiting_time;
		}
	}
	 total_waiting_time =0;
	 total_turnaround_time=0;
	  total_response_time=0;
	for (i = 0; i < len; i++)
    {
        p[i].turnaround_time = p[i].return_time - p[i].arrive_time;
        total_waiting_time += p[i].waiting_time;
        total_turnaround_time += p[i].turnaround_time;
        total_response_time += p[i].response_time;
    }
    
    fcfs_print_gantt_chart(p, len);
    print_table(p,len);
	
    printf("\n\tAverage Waiting Time     : %-2.2lf\n", (double)total_waiting_time / (double)len);
    printf("\tAverage Turnaround Time  : %-2.2lf\n", (double)total_turnaround_time / (double)len);
    printf("\tAverage Response Time    : %-2.2lf\n\n", (double)total_response_time / (double)len);
    
    
}

#endif
