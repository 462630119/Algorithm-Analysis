#include <stdio.h>
#include <stdlib.h>
int main(){
	int findByHalf(int arr[], int len, int key);
	int len=100;   //����n��ֵ�����������С
	int i,j,key,arr[10000];
	for(i=0;i<len;i++){
		arr[i]=i;
	}
	for(j=0;j<len;j++) printf("%d\n",arr[j]);
	printf("which number:\n");
	scanf("%d",&key);
	if key > len{
		printf("overflow");
	}
	else{
		int index = findByHalf(arr,len,key);
		printf("%d",index);
	}
}

int findByHalf(int arr[], int len, int key){
	int low = 0;
 	int high = len - 1;
 	int mid ;
 	while(low <= high){
  		mid = (low + high) / 2;
  		//�ұ߲���
  		if (key > arr[mid]) {
   			low = mid + 1;
  		//��߲���
  		}
		else if (key < arr[mid]) {
 	  		high = mid - 1;
  		}
		else{
   			return mid;
  		}
  	}
}
