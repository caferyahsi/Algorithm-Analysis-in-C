
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



struct item {
    char key[50];
    char value[50];
};


struct item **hash_table;

char* cevir(char string[50]){
	
		int fark='a'-'A';
		char a;
	for(int i=0;i<strlen(string);i++){
		a=string[i];
		if(a <65) continue;
		if(a<97){
		
		a=a+32;
		string[i]=a;
		
		}
		
		
	}
	return string;
}
int get_hash1(const char* s, const int n) {
    const int p = 31, m = 1e9 + 7;
    int hash = 0;
    long p_pow = 1;
    for(int i = 0; i < n; i++) {
        hash = (hash + (s[i] - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    if(hash>0) return hash %m;
    else{
    	return -(hash%m);
	}
}

int get_hash(const char* s, int m){
	int p=37;
	int hashvalue=0;
	for (int i = strlen(s); i >= 0; i--) { 
	hashvalue = p * hashvalue + s[i];
	}
	if(hashvalue>0) return hashvalue %m;
    else{
    	return -(hashvalue%m);
	}

}

void insert(int m){
	
	char string[50],sabit[50];
	int probe,i=0;
    FILE *fp;
    fp=fopen("sample.txt","r");
    
    
   while(! feof(fp) ){
    
    	fgets(sabit,50,fp);
    	
    	
   		fgets(string,50,fp);
   		strcpy(sabit,cevir(sabit));
   		strcpy(string,cevir(string));
   		
   		
   		
		const char *delp;
		delp = strtok (string," ");
	
		while (delp != NULL)  {
			  struct item * item1 =(struct item*)malloc(sizeof(struct item));
			  strcpy(item1->value,sabit);
		      strcpy(item1->key,delp);
		      if(item1->key[strlen(item1->key)-1]==10)item1->key[strlen(item1->key)-1]=NULL;
		      delp = strtok (NULL," ");
		      probe=get_hash(item1->key,m);
		      
    		  while(hash_table[probe]->key!=NULL)
    		{
        		probe=(probe+1)%m;
				
    		}
    		
    		  hash_table[probe]=item1;
		      
    	}	
   			
	
    	
    		
    }
    		
}




int say(){
	
	FILE *fp;
    fp=fopen("sample.txt","r");
    int satir=0;
    char a[100];
    char *delp;
    
    
     while(! feof(fp) ){
     	
     		fgets(a,100,fp);
     		fgets(a,100,fp);
     		delp = strtok (a, " ");
    		while (delp != NULL)  {
     		satir++;
     		delp = strtok (NULL, " ");
     		}
     	
     }
     return satir;
     
	
	
}

int ara(char str1[50],char str2[50]){
	int i=0;
	while(str1[i]!=NULL && str2[i]!=NULL){
		if(str1[i]!=str2[i])return 0;
		i++;
		if(i==50)break;
	}
	return 1;
}

int * Search(char aranan[50],int m)
{
	
     int *dizi = (int*)calloc(10, sizeof(int));
    
    int probe=get_hash(aranan,m),var=0;
    

    while(hash_table[probe]!=NULL)
    {
    	
        if(ara(hash_table[probe]->key,aranan)==1){
        	
        	dizi[var]=probe;
        	var++;
        	printf("index:%d->%s\n",probe,hash_table[probe]->key);
		}
        
       
            
        probe=(probe+1)%m;
    }
    
    return dizi;
    
    
}

bool asal_mi(int sayi){
	
    

    for (int i = 2; i < sayi; i++)
    {
        if (sayi % i == 0)
        {
        
            return false;
        }
    }
    
    return true;
}

int asal_bul(float load_factor,int satir){
	int m=satir/load_factor;
	
	if(asal_mi(m))return m;
	
	
	while(m>satir){
		if(asal_mi(m)){
			return m;
		}
		m--;
	}
	
	if(asal_mi(m)){
		return m;
	}
	return 0;

}


int main() {
	
	char aranan[50],baglac[50];
	int satir=say(),m,*dizi1,*dizi2;
	float load_factor;


	printf("LOAD FACTOR:");
	 scanf("%f",&load_factor);
	 	
		
	
	 
	 m=asal_bul(load_factor,satir);
	hash_table=(struct item **)calloc(m,sizeof(struct item));
	 	
     insert(m);
     
 
   for(int i =0;i<m;i++){
   	if(hash_table[i]==NULL)continue;
   	printf("%d-------%s--------%s\n",i,hash_table[i]->key,hash_table[i]->value);
   	
   }
   getchar(); 
   printf("Aranacak kelimeyi giriniz:");
    gets(aranan);
    strcpy(aranan,cevir(aranan));
    
   for(int i=strlen(aranan);i<50;i++)aranan[i]=NULL;
   
   
   
	char *delp;
	int i=0;
 
   delp = strtok (aranan, " ");
    while (delp != NULL)  {
    
      dizi1=Search(delp,m);
      
      if(dizi1[0]==NULL){
      	printf("ARANAN DEGER BULUNAMADI:::::::::");
      	break;
	  }
      delp = strtok (NULL, " ");
      if(delp==NULL){
      	while(dizi1[i]!=NULL){
	  		printf("site:%s",hash_table[dizi1[i]]->value);
	  		i++;
		  }
		  break;
	  }
      strcpy(baglac,delp);
      delp = strtok (NULL, " ");
      dizi2=Search(delp,m);
      i=0;
      int j=0;
      if(strcmp(baglac,"ve")==0){
      	while(dizi1[i]!=NULL){
      		while(dizi2[j]!=NULL){
      			
      			if(strcmp(hash_table[dizi1[i]]->value,hash_table[dizi2[j]]->value)==0){
      					printf("site:%s",hash_table[dizi1[i]]->value);
      				
				  }
				  j++;
				 // printf("1---%s-------%s",hash_table[dizi1[i]]->value,hash_table[dizi2[j]]->value);
			  }
			  j=0;
			  i++;
		  }
      	
	  }else if(strcmp(baglac,"veya")==0){
	  	i=0;
	  	while(dizi1[i]!=NULL){
	  		printf("%s",hash_table[dizi1[i]]->value);
	  		i++;
		  }
		  i=0;
		  while(dizi2[i]!=NULL){
	  		printf("%s",hash_table[dizi2[i]]->value);
	  		i++;
		  }
	  	
	  }else{
	  	printf("Hatali baglac girdiniz.");
	  }
      
      return 0;
    }
   
   
    
}
