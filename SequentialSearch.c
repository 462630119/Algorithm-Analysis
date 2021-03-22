#include <stdio.h>
#include <stdlib.h>
int main(){
	int SeqSearch(int arr[],int len,int key);
	int len=100;   //设置len的值，调整数组大小
	int i,j,key,arr[10000];
	for(i=0;i<len;i++){
		arr[i]=i;
	}
//	for(j=0;j<len;j++) printf("%d\n",arr[j]);
	printf("which number:\n");
	scanf("%d",&key);
	int index = SeqSearch(arr,len,key);
	printf("%d",index);

}
int SeqSearch(int s[],int n,int key)
{
    int i;
    for(i=0;i<n&&s[i]!=key;i++);						//将i<n去掉，在优化可以改进算法
    if(i<n)
        return i;
    else
        return -1;
}

