#include<stdio.h>
int main(){
	int rq[100],total_headmovement=0,initial,i,n;
	printf("enter the total no of requests");
	scanf("%d",&n);
	printf("enter the request sequence");
	for(i=0;i<n;i++){
		scanf("%d",&rq[i]);
	}
	printf("enter the inital position of head");
	scanf("%d",&initial);
	for(i=0;i<n;i++){
		total_headmovement+=abs(rq[i]-initial);
		initial=rq[i];
	}
	printf("total no of readwrite head pointer movement are=%d",total_headmovement);
	return 0;
}
