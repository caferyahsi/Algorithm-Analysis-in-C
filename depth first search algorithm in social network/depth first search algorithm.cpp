#include <stdio.h>
#define V 99
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Initialize the matrix to zero
struct queue
{
    int size;
    int f;
    int r;
    int* arr;
};
int kisi_sayisi; 


int isEmpty(struct queue *q){
    if(q->r==q->f){
        return 1;
    }
    return 0;
}
 
int isFull(struct queue *q){
    if(q->r==q->size-1){
        return 1;
    }
    return 0;
}
 
void enqueue(struct queue *q, int val){
    if(isFull(q)){
        printf("This Queue is full\n");
    }
    else{
        q->r++;
        q->arr[q->r] = val;
        // printf("Enqued element: %d\n", val);
    }
}
 
int dequeue(struct queue *q){
    int a = -1;
    if(isEmpty(q)){
        printf("This Queue is empty\n");
    }
    else{
        q->f++;
        a = q->arr[q->f]; 
    }
    return a;
}
void init(int arr[][V]) {
  int i, j;
  for (i = 1; i < V; i++)
    for (j = 1; j < V; j++)
      arr[i][j] = 0;
}
int adjMatrix[V][V],adjMatrix2[V][V],adjMatrix1[V][V],adjMatrix3[V][V];
// Add edges
void addEdge(int arr[][V], int i, int j) {
  arr[i][j] = 1;
 
}

// Print the matrix
void printAdjMatrix(int arr[][V],int kisi_sayisi) {
  int i, j;

  for (i = 1; i < kisi_sayisi; i++) {
    printf("\n%d: ", i);
    for (j = 1; j < kisi_sayisi; j++) {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
}
int follower_count(int v,int kisi_sayisi){
	int counter=0;
	for(int i=1;i<kisi_sayisi;i++){
		if(adjMatrix[v][i]==1){
			counter++;
		}	
	}
	return counter;
}


int follower_count2(int v,int kisi_sayisi){
	int counter=0;
	for(int i=1;i<kisi_sayisi;i++){
		if(adjMatrix2[v][i]==1){
			counter++;
		}	
	}
	return counter;
}
void del_follower(int v,int kisi_sayisi){
	
	for(int i=1;i<kisi_sayisi;i++){
		if(adjMatrix[v][i]==1){
			adjMatrix[i][v]=0;
			adjMatrix[v][i]=0;
	}
}
for(int i=1;i<kisi_sayisi;i++){

			adjMatrix[i][v]=0;
	}
}

int find_influncer(int m,int kisi_sayisi){
	int a=0;
	for(int i=1;i<kisi_sayisi;i++){
		
			if((follower_count(i,kisi_sayisi)<m)){
			if(follower_count(i,kisi_sayisi)!=0)a++;	
			del_follower(i,kisi_sayisi);
			
			
		}
	}
	
	printAdjMatrix(adjMatrix,kisi_sayisi);
	
	if(a==0)return 0;
}


int indirect(int k,int kisi_sayisi){
	int counter=0;
	struct queue q;
    q.size = 400;
    q.f = q.r = 0;
    q.arr = (int*) malloc(q.size*sizeof(int));
	int visited[kisi_sayisi];
	for (int i =0;i<kisi_sayisi;i++){
		visited[i]=0;
	}
	 visited[k] = 1;
    enqueue(&q, k); // Enqueue i for exploration
    
    while (!isEmpty(&q))
    {
        int node = dequeue(&q);
        for (int j = 1; j < kisi_sayisi; j++)
        {
            if(adjMatrix[node][j] ==1 && visited[j] == 0){
                //printf("%d", j);
                visited[j] = 1;
                enqueue(&q, j);
            }
        }
    }
    for (int i=1;i<kisi_sayisi;i++) {
    	if(visited[i]==1){
    		counter++;
		}
	}
	return counter-1;
}
int* count_direct(int m,int kisi_sayisi){
	int *dizi =(int*) malloc(kisi_sayisi * sizeof(int));
	int a=1;
for(int i=1;i<kisi_sayisi;i++){
		
			if((follower_count(i,kisi_sayisi)>=m)){
			
			dizi[a]=i;
			a++;
		}
	}
	if(a==1)return NULL;
	dizi[0]=a;
	return dizi;
}

int main() {
	int X,Y,M;
  printf("Fluncer bulma programina hosgeldiniz!!\n");
  printf("M degeri giriniz:");
  scanf("%d",&M);
  printf("X degeri giriniz:");
  scanf("%d",&X);
  printf("Y degeri giriniz:");
  scanf("%d",&Y);
	
  init(adjMatrix);
  
  FILE *fp;
  char string[50],sabit[50];
  fp=fopen("socialNET.txt","r");
  int i =1,a,k,*ip;
  char arr[99][50];
  const char *delp;
  while(! feof(fp) ){
    
    	fgets(sabit,50,fp);
    	strcpy(arr[i],sabit);
   		fgets(string,50,fp);
   		delp = strtok (string,",");
   		while (delp != NULL)  {
   		a= atoi(delp);	
   		if (a==0) {
   			delp = strtok (NULL,",");
   			continue;
		   }
   		//printf("%d--->%d///",i,a);
   		addEdge(adjMatrix1, i, a);
   		addEdge(adjMatrix3, i, a);
   		delp = strtok (NULL,",");
   		
   		}
   		i++;
   }
    kisi_sayisi=i;
  
   for (int i = 1; i < kisi_sayisi; ++i)
  for (int j = 1; j <kisi_sayisi; ++j) {
    adjMatrix[j][i] = adjMatrix1[i][j];
    adjMatrix2[j][i] = adjMatrix3[i][j];
  }

 // printAdjMatrix(adjMatrix2);
 
  for(int j=1;j<kisi_sayisi;j++){
  	printf("%s isimli kisinin in-degree degeri:%d\n",arr[j],follower_count(j,kisi_sayisi));
  }
  printf("-----------------------------------------------------------------------");
  while(true){
  	k=find_influncer(M,kisi_sayisi);
  	if(k==0)break;
  }
 
ip=count_direct(M,kisi_sayisi);
int o=1;
while(ip[0]>o){
	
printf("\n%s isimli kisi M degeri icin elenmedi takipcisi:%d\n",arr[ip[o]],follower_count(ip[o],kisi_sayisi));
o++;
	
}
 printf("-----------------------------------------------------------------------");
o=1;
int r=0;
while(ip[0]>o){
	int c=indirect(ip[o],kisi_sayisi);
	if(follower_count(ip[o],kisi_sayisi)>=X){
	
	if(c>=Y){
		printf("\n%sisimli kisi influncer!!!\nfollower=%d\nindirect_follower=%d\n",arr[ip[o]],follower_count2(ip[o],kisi_sayisi),c);
		r++;
	}
	
	}
	o++;
	
}

if(r==0)printf("\n!!!!!!!!!!!!!!!!!influncer yok!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
  return 0;

}
