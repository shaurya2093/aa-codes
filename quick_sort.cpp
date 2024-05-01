#include <stdio.h>
#define MAX 20
int partition(int arr[],int low, int high){
	int pivot=arr[high],i,j,temp;
	i=low-1;
	for (j=low;j<high;j++){
		if (arr[j]<=pivot){
			i++;
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}	
	}
	temp=arr[i+1];
	arr[i+1]=arr[high];
	arr[high]=temp;
	return(i+1);
}
void quicksort(int arr[],int low, int high){
	int pi;
	if(low<high){
		pi=partition(arr,low,high);
		quicksort(arr,low,pi-1);
		quicksort(arr,pi+1,high);
	}
}
void display(int arr[], int size) {
  for (int i=0;i<size;i++) {
    printf("%d\t", arr[i]);
  }
}
int main(){
	int arr[MAX],n,i;
	printf("Enter no. of elements: ");
	scanf("%d",&n);
	for (i=0;i<n;i++){
		printf("enter element %d: ",i+1);
		scanf("%d",&arr[i]);
	}
	printf("your array:\n");
	display(arr,n);
	quicksort(arr,0,n-1);
	printf("\nYour sorted array:\n");
	display(arr,n);
	return 0;
}