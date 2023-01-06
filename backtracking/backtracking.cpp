#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void turn_line(int **dizi,int satir,int n){
	int k,sayi=n-1;
	k=dizi[satir][sayi];
	sayi--;
	for (int i=sayi;i>=0;i--){
		
		dizi[satir][i+1]=dizi[satir][i];
		sayi--;
	}
	
	dizi[satir][0]=k;
	
}
bool satir_compare(int **dizi,int sutun1,int sutun2,int n){
	for(int i=0;i<n;i++){
		if(dizi[sutun1][i]==dizi[sutun2][i]){
			return false;
		}
	}
	
	return true;
}

bool all_satir_compare(int **dizi,int sutun,int n){
	for ( int i = 0;i < sutun;i++){
		if(!satir_compare(dizi,i,sutun,n)){
			return false;
		}
		
	}
	return true;
}

void print_matris(int **dizi,int n){
	
char colors[8][20] = {"Sari", "Kirmizi", "Yesil", "Turuncu", "Mavi", "Mor", "Lacivert", "Lila"};	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%s-",colors[dizi[i][j]]);
		}
		printf("\n");
	}
	
}



int main(){
	
	
	int n,r=1,f=1;
	while(r){
		r=0;
	printf("Satir ve sutun sayisi icin N sayisini giriniz\nN sayisi 3 <= N <= 8 olmak zorundadir!!!!!!!!!\nN:");
	scanf("%d",&n);	
	if(n>8 || n<3){
		printf("\n%d sayisi 3 ile 8 arasinda degil lutfen 3 <= N <= 8 sartini saglayin... \n",n);
		r=1;
	}
		
	}
	int **dizi ;
	dizi= (int**)calloc(n,sizeof(int*)); // the matrix
  	for(int i=0; i<n; i++){
    dizi[i] = (int*)calloc(n,sizeof(int));
  	}
        
	
	
	
	printf("Satir Sutun verileri icin girmek istediginiz renkleri giriniz!");
	printf("0:Sari\n1:Kirmizi\n2:Yesil\n3:Turuncu\n4:Mavi\n5:Mor\n6:Lacivert\n7:Lila");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			f=1;
			while(f){
			printf("\nsatir:%d  sutun:%d renk numarasini girin:",i,j);
			scanf("%d",&dizi[i][j]);
			f=0;
			if(dizi[i][j]>7 ||dizi[i][j]<0)	{
				printf("\nLutfen 0 ila 7 arasinda veri giriniz!! \n");
				f=1;
			}
			}
			
		}
		
	}
                   
    
   print_matris(dizi,n);     
   
   
	int k=0,a,c=0;              
	for(int i=1;i<n;i++){
		a=0;
		while(!all_satir_compare(dizi,i,n) && a<n+1){
			
			turn_line(dizi,i,n);
			printf("\n");
			print_matris(dizi,n);
			a++;
		}
		if(a==n+1){
			printf("Cozum yok malesef!!!!!!!!!!!!!!");
			c=1;
			break;
		}
		
		
		}
		if(c==0){
			printf("Cozum var!!!!!!!!!!!!!!");
	}
	
}
