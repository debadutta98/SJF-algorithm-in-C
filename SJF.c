 #include<stdio.h>
 #include<conio.h>
 #include<stdlib.h>
struct Node
{
	int d;
	int d1;
	struct Node *next;
}*start=NULL,*tail=NULL;
struct Node1
{
	struct Node1 *prev;
	int d;
	int d1;
	struct Node1 *next;
}*start1=NULL,*tail1=NULL;
void add_to_doubleLinklist(int,int);
void delete_first()
{
	struct Node1 *ptr;  
    if(start1 == NULL)  
    {  
        return;  
    }  
    else if(start1->next == NULL)  
    {  
        start1 = NULL;   
        free(start1);  
       return; 
    }  
    else  
    {  
        ptr = start1;  
        start1 = start1 -> next;  
        start1 -> prev = NULL;  
        free(ptr);  
        return; 
    }  
}
void deleteNode(struct Node *temp1) 
{ 
   struct Node *temp=NULL;
   struct Node *temp2=NULL;
   if(start==NULL)
   {
   	return;
   }
   else
   {
   	temp=start;
   	while(temp!=NULL)
   	{
   	if(temp==temp1)
	   {
	   	if(temp==start)
	   	{
	   		start=start->next;
	   		temp=NULL;
	   		return;
		}
		else
		{
		temp2->next=temp->next;
		temp=NULL;
		return;	
		}
		}
		else
		{
			temp2=temp;
			temp=temp->next;
		}	
	}
   }
} 
void welcome_arrival_process(int *p)
{
	if(start==NULL)
	{
		return;
	}
	else
	{
		struct Node *temp=start;
		while(temp!=NULL)
		{
		if(temp->d<*p)
		{
		add_to_doubleLinklist(temp->d,temp->d1);
		deleteNode(temp);
		temp=start;
		}	
		else
		{
			temp=temp->next;
		}
		}
	}
}
void add_to_doubleLinklist(int a,int b)
{
	struct Node1 *ptr=(struct Node1 *)malloc(sizeof(struct Node1));
	ptr->prev=NULL;
	ptr->next=NULL;
	ptr->d=a;
	ptr->d1=b; 
    if((start1)==NULL) 
    { 
        (start1) = ptr; 
        (tail1) = ptr; 
        (start1)->prev = NULL; 
        return; 
    } 
    if (ptr->d1 < start1->d1) 
    { 
        ptr->prev = NULL; 
        start1->prev = ptr; 
        ptr->next=start1; 
        start1=ptr; 
        return;
    } 
    if ((ptr->d1) > ((tail1)->d1)) 
    { 
        ptr->prev = (tail1); 
        (tail1)->next = ptr; 
        (tail1) = ptr; 
        return; 
    } 
    struct Node1 *temp = (start1)->next; 
    while ((temp->d1) < (ptr->d1)) 
        temp = temp->next; 
    (temp->prev)->next = ptr; 
    ptr->prev = temp->prev; 
    temp->prev = ptr; 
    ptr->next = temp; 
}
void search_small(int init[],int com[],int n,int c)
{
	int r=0;
if(start1==NULL)
{
	return;
}
else
{
	struct Node1 * temp=start1;
	int i=1;
	while(temp!=NULL)
	{
		if(i<n && start1!=NULL && temp!=NULL){
		init[i]=com[i-1];
		com[i]=init[i]+temp->d1;
		r=com[i];
		if(c==1)
		welcome_arrival_process(&r);
		delete_first();
		if(c==0)
		welcome_arrival_process(&r);
		if(start1!=NULL)
		temp=start1;
		else
		temp=NULL;
		}
		i++;
	}
}
}
 void completion_time(int init[],int com[],int n)
 {
 	int i=0;
 	int r=0;
 	int c=0;
if(start==NULL)
{
	return;
}
else
{
struct Node * temp=start->next;
struct Node  *temp1=NULL;
int small=start->d1;
while(temp!=NULL)
{
	if(temp->d1<small && start->d==temp->d)
	{
		temp1=temp;
		small=temp->d1;
	}
	temp=temp->next;
}
if(temp1!=NULL){
if(start->d==temp1->d)
{
if(start->d1>temp1->d1)	
{
init[0]=temp1->d;
com[0]=temp1->d+temp1->d1;
r=com[0];
deleteNode(temp1);
c=1;
}
else
{
init[0]=start->d;
com[0]=start->d+start->d1;
r=com[0];
deleteNode(start);
}
}
}
else
{
init[0]=start->d;
com[0]=start->d+start->d1;
r=com[0];
deleteNode(start);
}
welcome_arrival_process(&r);
search_small(init,com,n,c);
}
 }
 void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
}   
void selectionSort(int arri[],int pro[],int bur[], int n) 
{ 
    int i, j, min_idx; 
    for (i = 0; i < n-1; i++) 
    { 
        min_idx = i; 
        for (j = i+1; j < n; j++) 
          if (arri[j] < arri[min_idx]) 
            min_idx = j; 
        swap(&arri[min_idx], &arri[i]); 
        swap(&pro[min_idx],&pro[i]);
        swap(&bur[min_idx],&bur[i]);
    } 
} 
int tat_find(int tat[],int comp[],int arr[],int d)
 {
 	int i;
 	double sum=0.0;
 	for(i=0;i<d;i++)
 	{
 		tat[i]=comp[i]-arr[i];
 		sum=sum+(double)(comp[i]-arr[i]);
	 }

	 return sum;
 }
 int rt_find(int rt[],int arr[],int init[],int d)
 {
 	int i=0;
 	double sum=0.0;
 	for(i=0;i<d;i++)
 	{
 		rt[i]=init[i]-arr[i];
 		sum=sum+(double)rt[i];
	 }

	 return sum;
 }
 void display(int pro[],int arr[],int bur[],int comp[],int tat[],int wt[],int rt[],int d,double avg_wt,double avg_tat){
 	int i;
 	printf("\nprocess no\tArrival time\tBurst time\tcompletion time\ttat\twt\trt\n");
 	for(i=0;i<d;i++)
 	{
 		printf("p%d\t\t%d\t\t%d\t\t%d\t\t%d\t%d\t%d\n",pro[i],arr[i],bur[i],comp[i],tat[i],wt[i],rt[i]);
	 }
	 printf("\naverage wating time =%lf",avg_wt);
	 printf("\nturn around time=%lf",avg_tat);
 }
 void main()
 {
 	int n;
 	int a,b;
 	printf("Enter the number of process\n");
 	scanf("%d",&n);
 	int pro[n],com[n],init[n],bur[n],wt[n],arri[n],tat[n],rt[n];
 	int arr[n];
 	int i;
 	for(i=0;i<n;i++)
 	{
 		pro[i]=i+1;
 		printf("enter the arrival time of the process %d\n",i+1);
 		scanf("%d",&b);
 		arr[i]=arri[i]=b;
 		printf("enter the burst time of the process %d\n",i+1);
 		scanf("%d",&a);
 		bur[i]=a;
	}
	selectionSort(arri,pro,bur,n);
	for(i=0;i<n;i++)
	{
		struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
		ptr->d=arri[i];
		ptr->d1=bur[i];
		ptr->next=NULL;
		if(start==NULL)
		{
			start=ptr;
			tail=start;
		}
		else
		{
			tail->next=ptr;
			tail=tail->next;
		}
	}
 	completion_time(init,com,n);
double avg_tat=tat_find(tat,com,arri,n);
double response_time=rt_find(rt,arri,init,n);
for(i=0;i<n;i++)
{
	wt[i]=rt[i];
}
double avg_w=(response_time/(double)n);
double avg_t=(avg_tat/(double)n);
display(pro,arri,bur,com,tat,wt,rt,n,avg_w,avg_t);
	getch();
 }
