//create a linked list
#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<malloc.h>
#define LEN sizeof(struct number) //define the length of memeory location used in malloc() function

//define a struct
struct number
{
    int num;
    struct number*next;

};

int n;
//create a linked list function
struct number*creat()  
{
    int set;	//ask user to define the group(s) of integers
	printf("Please enter the set of integer you want to input:");
  	scanf("%d", &set);
	struct number*head; // create a head node pointer
    struct number *p1, *p2; //p1 points the final node, p2 points the former node
    n = 0;
    p1 = p2 = (struct number*)malloc(LEN); //for the first data
    scanf_s("%d", &p1->num);
    head = NULL;
    set=set-1;
    int i; //input the following data
    for (i=0; i<set; i++){
	if (p1->num != 0)
    {
        n = n + 1;
        if (n == 1)
        {
            head = p1;
        }
        else
        {
            p2->next = p1;//next of p2 point p1
        }
        p2 = p1; //p2 point p1
        p1 = (struct number*)malloc(LEN); //create new p1
        scanf_s("%d", &p1->num);  //input data to p1
    }  
}	
	p2->next = p1; //give terminator the linked list 
    p2 = p1;
    p1 = (struct number*)malloc(LEN);
    p1->num=0; 
	p2->next = NULL;
    return(head);//return head value 

}

void print(struct number *head)   //output the linked list
{
    struct number* p; //creat a new list
    printf("\nThese %d records you input are:\n", n+1);
    p = head; //p point head
   if (head != NULL)
    {
        do
        {
            printf("%d\n", p->num);
            p = p->next;

        } while (p != NULL); //print list till NULL
    }
}
 
void freelist(struct number *head) {
   printf("\ncleaning memory......");
   struct number *q, *p; //create 2 linked list
   q = p = head; //initially point to head
    
    while(p) {
        q = p; //q point p
        p = q->next; //p point to next of q
        free(q); //free q
    }
    head = NULL; //free head
    
    printf("\ndone\n");
}


int main()
{
    struct number *list;
    list = creat();//create a list
    print(list);   //display a list
    freelist(list);//free a list
    system("pause");
    return 0;
}
