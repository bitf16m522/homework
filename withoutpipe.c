//this program is created to add the 10 child processes without pipes
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
int main(){
	int arr[1000];
	int status;
	int check[10];	
	int sum=0;	
	for(int i=0; i<1000; i++){
		arr[i]=i;	
	}
	//creating first child
	int cpid=fork();
	if(cpid==0){
		
		for(int i=0; i<100; i++){
			sum=sum+arr[i];			
		}
		exit(sum);
			
	}
	else{
		wait(&check[0]);
	//creating second child
		int cpid1=fork();
		if(cpid1==0){
		for(int i=100; i<200; i++){
		sum=sum+arr[i];	
		}
		exit(sum);
		}
		else{
		wait(&check[1]);
	//creating third child
		int cpid2=fork();
		if(cpid2==0){
		for(int i=200; i<300; i++){
		sum=sum+arr[i];		
		}
			exit(sum);
		}
		else{
		wait(&check[2]);
	//creating forth child			
		int cpid3=fork();
		if(cpid3==0){
		for(int i=300; i<400; i++){
		sum=sum+arr[i];	
		}
		exit(sum);
		}
		else{
		wait(&check[3]);
	//creating five child	
		int cpid4=fork();
		if(cpid4==0){
		for(int i=400; i<500; i++){
		sum=sum+arr[i];	
		}
		exit(sum);
		}
		else{
		wait(&check[4]);
	//creating sixth child	
		int cpid5=fork();
		if(cpid5==0){
		for(int i=500; i<600; i++){
		sum=sum+arr[i];	
		}
		exit(sum);
		}
		else{
		wait(&check[5]);
	//creating seventh child	
		int cpid6=fork();
		if(cpid6==0){
		for(int i=600; i<700; i++){
		sum=sum+arr[i];	
		}
		exit(sum);
		}		
		else{
		wait(&check[6]);
	//creating eigth child	
		int cpid7=fork();
		if(cpid7==0){
		for(int i=700; i<800; i++){
		sum=sum+arr[i];	
		}
		exit(sum);
		}	
		else{
		wait(&check[7]);
	//creating ninth child	
		int cpid8=fork();
		if(cpid8==0){
		for(int i=800; i<900; i++){
		sum=sum+arr[i];	
		}
		exit(sum);
		}
		else{
		wait(&check[8]);
	//creating tenth child	
		int cpid9=fork();
		if(cpid9==0){
		for(int i=900; i<1000; i++){
		sum=sum+arr[i];	
		}
		exit(sum);
		}
		else{
		wait(&check[9]);
		int sum1=0;
		int count=17066;
	//adding the child processes		
		for(int i=0; i<10; i++){
			check[i]=check[i]-count;
			count=count-5904;
			sum1=sum1+check[i];			
		}
		printf("sum %d\n",sum1);
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
	
return 0;
}
