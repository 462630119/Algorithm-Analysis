#include<iostream>
#include<string>
using namespace std;
int minValue(int i, int j, int k){
	return i < j ? (i < k ? i : k) : (j < k ? j : k);
}
int calculateStringDistance(string strA, string strB){
	int lenA = strA.length();
	int lenB =strB.length();
	int **dp = new int *[lenA];
	for (int i = 0; i <=lenA; i++){
		dp[i] = new int[lenB];
	}
	for (int i = 0; i <=lenA; i++){
		dp[i][0] = i;
	}
	for (int j = 1; j < lenB; j++){
		dp[0][j] = j;
	}
	for (int i = 1; i <=lenA; i++){
		for (int j = 1; j <=lenB; j++){
			if (strA[i-1] == strB[j-1]){
				dp[i][j] = dp[i - 1][j - 1];
			}
			else{
				dp[i][j] = minValue(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]) + 1;
			}
		}	
	}
	int result = dp[lenA-1][lenB-1];
	for (int i = 0; i <=lenA; i++){
		delete[]dp[i];
	}
	delete[]dp;
	return result;
}
int main(){
	string A,B;
	cout<<"请输入源字符串A"<<endl;
	cin>>A;
	cout<<"请输入目的字符串B"<<endl;
	cin>>B;
	cout<<"最小操作次数为："<< calculateStringDistance(A,B) << endl;
	return 0;
}
