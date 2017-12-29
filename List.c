//Alina Thai	
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include <ctype.h>
#include <string.h>

struct node *create_node(char *, char *, int);
struct node *search_node(struct node *, int);
void print_node(struct node *, int);
void print_list(struct node *);
void delete_node(struct node *);
int insert_node(struct node *);
char search_id(struct node *ptr, int id);

//given structure
typedef struct node{
    char last[30];
    char first[20];
    unsigned int id;
    struct node *link;
}ListNode;

//initialize the first and last nodes to null because list is empty now
struct node *head = (struct node *) NULL;
struct node *end = (struct node *) NULL;

int main(){
    char *last, *first;
    char c[51];
    unsigned int id;
    int count = 0; 
    struct node *ptr;
    print_list(head);
	    
    //step 1	
    //open and get data from the file
    FILE *file;
    file = fopen("/usr/class/cis660/Cse2421.Lab4.Data", "r");
    if(file == NULL){
        printf("Open file failed\n");
        return -1;
    }

    char *search = ",";
    //separate the data from the file into last, first, and id and create nodes
    while(fscanf(file," %s", &c)> 0){
        last = strtok(c, search);
        first = strtok(NULL, search);
        fscanf(file, " %d", &id);
        ptr = create_node(last, first, id);
        if(insert_node(ptr) != 1)
        	count++;
    }

    char answer;
    char correct = 'y';
    int number = 0;
    char duplicate;
    //step 2
    //give the option to print, add, delete, or exit
    while(answer != 'e') {
        printf("Enter p to print list, a to add node, d to delete node, e to exit: ");
        scanf("%c", &answer );
        printf("You entered = %c\n", answer);
        switch(answer){    
	    //print content of all nodes in the list  
            case 'p': 
                print_list( head );
                break;
	    //add a new node to the list
	    case 'a':
                printf("Enter First, Last and id: ");
                scanf(" %s %s %d", last, first, &id );
                printf("You entered: %s %s %d \n", last, first, id);
                printf("Is it correct (y/n)? ");
                scanf(" %c", &correct);
		//exit switch and reask for a new task
		if(correct == 'n'){
			printf("You entered not correct.\n");
			break;
		}
		//check for duplicates
		duplicate = search_id(ptr,id);
		printf ("duplicate = %c\n", duplicate);
		if(duplicate == 'm'){
			printf("Input: %d %s,%s a node with its id= %d already exists;",count+1, last, first,id); 				
			printf("Not added to the list!\n");
			break;
		}
		//if no duplicates found create new node
                ptr = create_node(last, first, id);
                insert_node(ptr);
                count++;
                printf("Node added to the list; Number of nodes = %d\n", count);
                
                break;
	    //delete a new node from the list
            case 'd':
                printf("Enter Node number to delete: ");
                scanf("%d",&number);
                ptr = search_node( head, number );
		//search if the node exists
                if(ptr == NULL) {
                    printf("Illegal Node number!\n" );
                }
                else{
		    //exit switch and reask for a new task
		    printf("Is it correct (y/n)? ");
               	    scanf(" %c", &correct);
		    if(correct == 'n'){
			printf("You entered not correct.\n");
			break;
		    }
                    delete_node(ptr);
                    count--;
                    printf("Node deleted from the list; Number of nodes= %d\n", count);
                }
                break;     
        } 
	//go to next line, skips scanning extra characters,discard them
	while(getchar()!= '\n');
	printf("\n");
    }

    return 0;
}

struct node *create_node(char *last, char *first, int id)
{
    struct node *ptr;
    //allocates memory
    ptr = malloc(sizeof(ListNode));
    //creates the node with the new data and return pointer
    if(ptr != NULL){
       	strcpy( ptr->last, last );
        strcpy( ptr->first, first);
        ptr->id = id;
        return ptr;
    }else{
	//return NULL otherwise
       	 return (struct node *) NULL;
    }    
}


void print_node(struct node *ptr, int number){
    //print the same format: node number, last, first, and id
    printf("%d\t ", number);
    printf("%15s ", ptr->last );
    printf("%15s ", ptr->first);
    printf("%15d\n", ptr->id );
}

void print_list(struct node *ptr){
    //print the entire node list
    int number = 1;
    while(ptr != NULL){
        print_node(ptr, number);
        ptr = ptr->link;
        number++;
    }
}

int insert_node(struct node *new ){
    //insert new node
    struct node *insert; 
    
    //if the head is empty, make the head the first node and readjust and exit
    if(head == NULL){ 
        head = new;
        end = new;
        (head->link) = NULL; 
        return 1; 
    }
    insert = head; 

    //avoid id duplicates
    if((insert->id) == (new->id)){
	//free(insert);
	return 1;
    }


    //order the nodes based on their ids
    while((insert->id) < (new->id)) {
        insert = (insert->link); 
        if(insert == NULL) 
            break;
    } 
    struct node *previous;  
    //see if it is the first node to insert and the readjust 
    if(insert == head){
        (new->link) = head; 
        head = new; 
    }else { 
        //search where to insert and the readjust the nodes
        previous = head; 
        while((previous->link) != insert) {
            previous = (previous->link);
        }
        (previous->link) = new; 
        (new->link) = insert;
	//the inserted node is at the end of the list and readjust
        if(end == previous) 
            end = new; 
    }
   return 0;
}

void delete_node(struct node *ptr){
    //delete the node
    struct node *delete, *previous;
    delete = ptr; 
    previous = head; 
    //delete if it is the first node and then readjust the  nodes
    if(delete == previous){ 
        head = (head->link); 
        if(end == delete) 
            end = (end->link); 
	//empty the space of the deleted node
        free(delete); 
    }else { 
	//search for the node to be deleted and then readjust the nodes
        while((previous->link) != delete){ 
            previous = (previous->link); 
        }
        (previous->link) = (delete->link); 
        if(end == delete) 
            end = previous; 
	//empty the space of the deleted node
        free(delete); 
    }
}
struct node *search_node(struct node *ptr, int number){
    //search for the pointer corresponding the node number
    int i = 1;
    while(i != number) { 
        ptr = (ptr->link);                        
        if( ptr == NULL )                       
            break;
	i++;                                
    }
    return ptr;                               
}                                           

char search_id(struct node *ptr, int id){
    //search for the duplicates
  //  int duplicate = 0;
    struct node *new;
    new = head;
    while((new->id) <= (ptr->id))  {
        ptr = (ptr->link);
        if(ptr == NULL)
            break;
	if((new->id) == (ptr->id)){
	   return 'm';
	   break;
	}
    }
    return 'n';
}




