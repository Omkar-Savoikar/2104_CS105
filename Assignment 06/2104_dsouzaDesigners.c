/*
    AUTHOR: MCA.2104
    PROGRAM: QUEUE APPLICATION 1 - D'SOUZA DESIGNERS
    DATE CREATED: 29 SEPT 2021
    DATE MODIFIED: 29 SEPT 2021
*/
//APPLICATION DEVELOPER
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<malloc.h>
#include"2104_queue.h"

int profitcalc(queueType hc, queueType sc){
    int profit;
    node *temp;
    profit = 0;
    if(queueIsEmpty(hc) == false){
        temp = hc.start;
        while(temp != NULL){
            profit += (temp->data.fees - temp->data.amount);
            temp = temp->next;
        }
    }
    if(queueIsEmpty(sc) == false){
        temp = sc.start;
        while(temp != NULL){
            profit += (temp->data.fees - temp->data.amount);
            temp = temp->next;
        }
    }
    return profit;
}

void main(){
    queueType home_completed, home_progress, shop_completed, shop_progress;
    EleType element;
    int option;
    bool ret;
    option = 1;
    home_completed = queueCreate();
    home_progress = queueCreate();
    shop_completed = queueCreate();
    shop_progress = queueCreate();
    printf("\nQUEUE USING LINKEDLIST");
    do{
        printf("\nPress 1 to create new database");
        printf("\nPress 2 to add new job in the home department");
        printf("\nPress 3 to add new job in the shop department");
        printf("\nPress 4 to mark a job as completed in home department");
        printf("\nPress 5 to mark a job as completed in shop department");
        printf("\nPress 6 to display the in-progress jobs");
        printf("\nPress 7 to display the completed jobs");
        printf("\nPress 8 to display the profit margin on completed jobs");
        printf("\nPress 0 to exit");
        printf("\nEnter your choice: ");
        scanf("%d",&option);
        switch(option){
            case 1: {
                //New database
                home_completed = queueCreate();
                home_progress = queueCreate();
                shop_completed = queueCreate();
                shop_progress = queueCreate();
                printf("\nDatabase Created");
                break;
            }
            case 2: {
                //New job in home department
                if(queueIsFull(home_progress) == false){
                    printf("\nEnter jobid: ");
                    scanf("%d",&element.jobid);
                    printf("\nEnter job fees: ");
                    scanf("%d",&element.fees);
                    element.amount = 0;
                    if(enqueue(element, &home_progress) == true)
                        printf("\nEnqueue Successful. Job added to the queue");
                    else
                        printf("Memory full. Cannot add more data.");
                }
                else
                    printf("\nQueue overflow. Cannot add more data.");
                break;
            }
            case 3: {
                //New job in shop department
                //jobid, fees, amount, category, progress
                if(queueIsFull(shop_progress) == false){
                    printf("\nEnter jobid: ");
                    scanf("%d",&element.jobid);
                    printf("\nEnter job fees: ");
                    scanf("%d",&element.fees);
                    element.amount = 0;
                    if(enqueue(element, &shop_progress) == true)
                        printf("\nEnqueue Successful. Job added to the queue");
                    else
                        printf("Memory full. Cannot add more data.");
                }
                else
                    printf("\nQueue overflow. Cannot add more data.");
                break;
            }
            case 4:{
                //mark job completed in home department
                if(queueIsEmpty(home_progress) == false){
                    element = dequeue(&home_progress);
                    printf("\nJob to be marked completed:");
                    printf("\nJobID : %d",element.jobid);
                    printf("\nJob Fee : %d",element.fees);
                    printf("\nEnter amout spent on the job: ");
                    scanf("%d",&element.amount);
                    if(enqueue(element, &home_completed) == false){
                        printf("\nError");
                        exit(1);
                    }
                }
                else
                    printf("\nNo jobs in progress in home department.");
                break;
            }
            case 5:{
                //mark job completed in shop department
                if(queueIsEmpty(shop_progress) == false){
                    element = dequeue(&shop_progress);
                    printf("\nJob to be marked completed:");
                    printf("\nJobID : %d",element.jobid);
                    printf("\nJob Fee : %d",element.fees);
                    printf("\nEnter amout spent on the job: ");
                    scanf("%d",&element.amount);
                    if(enqueue(element, &shop_completed) == false){
                        printf("\nError");
                        exit(1);
                    }
                }
                else
                    printf("\nNo jobs in progress in shop department.");
                break;
            }
            case 6:{
                //display in progress jobs
                if((queueIsEmpty(home_progress) == false) || (queueIsEmpty(shop_progress) == false)){
                    if(queueIsEmpty(home_progress) == false){
                        printf("\nHome Department jobs in queue");
                        queueDisplay(home_progress);
                    }
                    if(queueIsEmpty(shop_progress) == false){
                        printf("\nShop Department jobs in queue");
                        queueDisplay(shop_progress);
                    }
                }
                else
                    printf("\nNo jobs in progress.");
                break;
            }
            case 7:{
                //display completed jobs
                if((queueIsEmpty(home_completed) == false) || (queueIsEmpty(shop_completed) == false)){
                    if(queueIsEmpty(home_completed) == false){
                        printf("\nCompleted home Department jobs");
                        queueDisplay(home_completed);
                    }
                    if(queueIsEmpty(shop_completed) == false){
                        printf("\nCompleted shop Department jobs");
                        queueDisplay(shop_completed);
                    }
                }
                else
                    printf("\nNo jobs completed.");
                break;
            }
            case 8:{
                //display the profit margin on completed jobs
                if((queueIsEmpty(home_completed) == false) || (queueIsEmpty(shop_completed) == false))
                    element.amount = profitcalc(home_completed,shop_completed);
                else
                    printf("\nNo job completed. Profit margin is 0.");
                printf("\nTotal profit margin earned from jobs completed is %d.", element.amount);
                break;
            }
            case 0: break;
            default: printf("\nInvalid input. Enter proper input (0 to 8).");
        }
    }while(option != 0);
    queueDelete(&home_completed);
    queueDelete(&home_progress);
    queueDelete(&shop_completed);
    queueDelete(&shop_progress);
}