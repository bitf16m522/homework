#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void * TestThread(void *arg){
	int sum=0;
	int start = (int)arg;
	int end = start+100;
	int arr[100];
	for(int i=0; i<100; i++,start++){
		arr[i]=start;	
	}
	for(int i=0; i<100; i++){
		sum=sum+arr[i];
	}
	return ((void*)sum);
}
int main(){
	int total;
	int status_t[10];
	pthread_t thread_t[10];
	int count=0;
	for(int i=0; i<10; i++){
	pthread_create(&thread_t[i],NULL, TestThread, (void*)(count));
	count=count+100;
}
for(int i=0; i<10; i++){
	pthread_join(thread_t[i], (void **)&status_t[i]);
	total=total+status_t[i];
}
	printf("total: %d\n",total);
return 0;
}
/*
void *TestThread(void *arg){
int start = (int)arg;
start = start+10;
return ((void*)start);
}
int main(){
	int status_t1;
	pthread_t thread_t1;
	pthread_create(&thread_t1, NULL, TestThread, (void*)(50));
pthread_join(thread_t1, (void **)&status_t1);
printf("%d\n",status_t1);
return 0;
}*/
