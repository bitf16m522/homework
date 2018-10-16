//this prgramme add the child processes with the help of pipe
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<sys/wait.h>
int main(){
	int fd1[2];
	int arr[1000];
	int arr2[10];
	for(int i=0; i<1000; i++){
		arr[i]=i;	
	}
	if(pipe(fd1)==-1){
		printf("pipe failed");
		return 1;	
	}
	//child one created
	int cpid = fork();
	if(cpid<0){
		printf("child process is failed");	
	}
	if(cpid==0){
		for(int i=0; i<100; i++){
			arr2[0]=arr2[0]+arr[i];	
		}		
		write(fd1[1],&arr2[0],sizeof(int));
		exit(0);
	}
	else{
		wait(NULL);
		read(fd1[0],&arr2[0],sizeof(int));
		printf("\nsum 0-99: %d\n",arr2[0]);
	//child two created		
		int cpid1=fork();
		if(cpid1==0){
		for(int i=100; i<200; i++){
		arr2[1]=arr2[1]+arr[i];
		}		
		write(fd1[1],&arr2[1],sizeof(int));
		exit(0);
		}
		else{
		wait(NULL);
		read(fd1[0],&arr2[1],sizeof(int));
		printf("\nsum 100-199: %d\n",arr2[1]);		
	//child three created	
		int cpid2=fork();
		if(cpid2==0){
		for(int i=200; i<300; i++){
		arr2[2]=arr2[2]+arr[i];
		}		
		write(fd1[1],&arr2[2],sizeof(int));
		exit(0);
		}
		else{
		wait(NULL);
		read(fd1[0],&arr2[2],sizeof(int));
		printf("\nsum 200-299: %d\n",arr2[2]);			
	//child forth created 		
		int cpid3=fork();
		if(cpid3==0){
		for(int i=300; i<400; i++){
		arr2[3]=arr2[3]+arr[i];
		}		
		write(fd1[1],&arr2[3],sizeof(int));
		exit(0);
		}
		else{
		wait(NULL);
		read(fd1[0],&arr2[3],sizeof(int));
		printf("\nsum 300-399: %d\n",arr2[3]);		
	//child five created	
		int cpid4=fork();
		if(cpid4==0){
		for(int i=400; i<500; i++){
		arr2[4]=arr2[4]+arr[i];
		}		
		write(fd1[1],&arr2[4],sizeof(int));
		exit(0);
		}
		else{
		wait(NULL);
		read(fd1[0],&arr2[4],sizeof(int));
		printf("\nsum 400-499: %d\n",arr2[4]);		
	//child six created	
		int cpid5=fork();
		if(cpid5==0){
		for(int i=500; i<600; i++){
		arr2[5]=arr2[5]+arr[i];
		}		
		write(fd1[1],&arr2[5],sizeof(int));
		exit(0);
		}
		else{
		wait(NULL);
		read(fd1[0],&arr2[5],sizeof(int));
		printf("\nsum 500-599: %d\n",arr2[5]);		
	//child seven created	
		int cpid6=fork();
		if(cpid6==0){
		for(int i=600; i<700; i++){
		arr2[6]=arr2[6]+arr[i];
		}		
		write(fd1[1],&arr2[6],sizeof(int));
		exit(0);
		}
		else{
		wait(NULL);
		read(fd1[0],&arr2[6],sizeof(int));
		printf("\nsum 600-699: %d\n",arr2[6]);		
	//child eight created		
		int cpid7=fork();
		if(cpid7==0){
		for(int i=700; i<800; i++){
		arr2[7]=arr2[7]+arr[i];
		}		
		write(fd1[1],&arr2[7],sizeof(int));
		exit(0);
		}
		else{
		wait(NULL);
		read(fd1[0],&arr2[7],sizeof(int));
		printf("\nsum 700-799: %d\n",arr2[7]);		
	//child nine created		
		int cpid8=fork();
		if(cpid8==0){
		for(int i=800; i<900; i++){
		arr2[8]=arr2[8]+arr[i];
		}		
		write(fd1[1],&arr2[8],sizeof(int));
		exit(0);
		}
		else{
		wait(NULL);
		read(fd1[0],&arr2[8],sizeof(int));
		printf("\nsum 800-899: %d\n",arr2[8]);		
	//child ten created		
		int cpid9=fork();
		if(cpid9==0){
		for(int i=900; i<1000; i++){
		arr2[9]=arr2[9]+arr[i];
		}		
		write(fd1[1],&arr2[9],sizeof(int));
		close(fd1[1]);
		exit(0);
		}
		else{
		wait(NULL);
		read(fd1[0],&arr2[9],sizeof(int));
		printf("\nsum 900-999: %d\n",arr2[9]);		
		close(fd1[0]);
		int total=0;
	// sum up the child processes			
		for(int i=0; i<10; i++){
			total=total+arr2[i];
		}
		printf("\ntotal sum is: %d\n",total);
		}
		}
		}
		}
		}
		}
		}
		}
		}
	}
}
