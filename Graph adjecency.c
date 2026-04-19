//GraphAdjacencyListDirectedGraph.c

struct node {
	struct node *next;
	int vertex;
};
typedef struct node *GNODE;
GNODE graph[20];

void print(int * N) {
	int empty = 1;
	for(int i=1;i<=*N;i++){
		if(graph[i] != NULL){
			empty = 0;
			printf("%d=>",i);
		
		GNODE p = graph[i];
		while(p != NULL){
			printf("%d\t",p->vertex);
			p = p->next;
		}
		printf("\n");
	}
}
}
void insertVertex(int * N) {
	int edges, v;
	(*N)++;
	graph[*N] = NULL;
	scanf("%d",&edges);
	for(int i=0; i<edges; i++){
		scanf("%d",&v);
		if(v<1 || v> *N){
			printf("Invalid vertex.\n");
			continue;
		}
		GNODE newNode = (GNODE)malloc(sizeof(struct node));
		newNode->vertex = *N;
		newNode->next = NULL;

		if(graph[v] == NULL){
			graph[v] = newNode;
		}else{
			GNODE temp = graph[v];
			while(temp->next != NULL){
				temp = temp->next;
			}
			temp->next = newNode;
		}
	}
	scanf("%d",&edges);
	for(int i=0; i<edges; i++){
		scanf("%d",&v);
		if(v<1 || v>*N){
			printf("Invalid vertex.\n");
			continue;
		}
		GNODE newNode = (GNODE)malloc(sizeof(struct node));
		newNode->vertex = v;
		newNode->next = NULL;
		if(graph[*N] == NULL){
			graph[*N] = newNode;
		}else{
			GNODE temp = graph[*N];
			while(temp->next != NULL){
				temp = temp->next;
			}
			temp->next = newNode;
		}
	}
	printf("After inserting vertex the adjacency list is : \n");
	print(N);
}

void insertEdge(int *N) {
	int src , dest;
	printf("Enter the source vertex of the edge : ");
	scanf("%d",&src);

	printf("Enter the destination vertex of the edge : ");
	scanf("%d",&dest);

	if(src<1 || src>*N || dest<1 || dest>*N){
		printf("Invalid vertex.\n");
		return;
	}
	GNODE newNode = (GNODE)malloc(sizeof(struct node));
	newNode->vertex = dest;
	newNode->next = NULL;

	if(graph[src] == NULL){
		graph[src] = newNode;
		
	}else{
		GNODE temp = graph[src];
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = newNode;
	}
	printf("After inserting edge the adjacency list is : \n");
	print(N);
}

void deleteVertex(int *N) {
	int v;
	if(*N == 0){
		printf("Graph is empty.\n");
		return;
	}
	printf("Enter the vertex to be deleted : ");
	scanf("%d",&v);

	if(v<1 || v>*N){
		printf("Invalid vertex.\n");
		return;
	}
	GNODE temp = graph[v];
	while(temp!=NULL){
		GNODE t = temp;
		temp = temp->next;
		free(t);
	}
	graph[v]= NULL;

	for(int i=1;i<*N;i++){
		GNODE curr = graph[i];
		GNODE prev = NULL;
		while(curr != NULL){
			if(curr->vertex == v){
				if(prev == NULL){
					graph[i] = curr->next;
				}else{
					prev->next = curr->next;
				}
				GNODE t = curr;
				curr = curr->next;
				free(t);
			}else{
				prev = curr;
				curr = curr->next;
			}
		}
	}

	for(int i = v;i<*N;i++){
		graph[i]=graph[i+1];
	}
	graph[*N] = NULL;
	(*N)--;

	for(int i = 1;i<=*N;i++){
		GNODE temp = graph[i];
		while(temp!=NULL){
			if(temp->vertex > v){
				(temp->vertex)--;
			}
			temp = temp->next;
		}
	}
	printf("After deleting vertex the adjacency list is : \n");
	print(N);
}

void deleteEdge(int *N) {
	int src , dest;
	printf("Enter the source vertex of the edge : ");
	scanf("%d",&src);
	printf("Enter the destination vertex of the edge : ");
	scanf("%d",&dest);

	if(src<1 || src>*N || dest<1 || dest>*N){
		printf("Invalid vertex.\n");
		return;
	}
	GNODE curr = graph[src];
	GNODE prev = NULL;

	while(curr!=NULL){
		if(curr->vertex == dest){
			if(prev == NULL){
				graph[src] = curr->next;
			}else{
				prev->next = curr->next;
			}
			free(curr);
			break;
		}
		prev = curr;
		curr = curr->next;
	}
	printf("After deleting edge the adjacency list is : \n");
	print(N);
}

//GraphMain3.c

#include<stdio.h>
#include<stdlib.h>
#include "GraphsAdjacencyListDirectedGraph.c" 

void main() {
	int x, op;
	int N,E,s,d,i,j;
	GNODE p,q;
	printf("Enter the number of vertices : ");
	scanf("%d",&N);
	printf("Enter the number of edges : ");
	scanf("%d",&E);
	for(i=1;i<=E;i++) {
		printf("Enter source : ");
		scanf("%d",&s);
		printf("Enter destination : ");
		scanf("%d",&d);
		q=(GNODE)malloc(sizeof(struct node));
		q->vertex=d;
		q->next=NULL;
		if(graph[s]==NULL)
			graph[s]=q;
		else {
			p=graph[s];
			while(p->next!=NULL)
				p=p->next;
			p->next=q;
		}
	}
	while(1) {
		printf("1.Insert vertex 2.Insert edge 3.Delete vertex 4.Delete edge 5.Print adjacency list 6.Exit\n");
		printf("Enter your option : ");
		scanf("%d", &op);
		switch(op) {
			case 1:	
					insertVertex(&N);
					break;
			case 2:
					insertEdge(&N);
					break;
			case 3: 
					deleteVertex(&N);
					break;
			case 4:
					deleteEdge(&N);
					break;
			case 5:
					print(&N);
					break;
			case 6:
					exit(0);
		}
	}
}
