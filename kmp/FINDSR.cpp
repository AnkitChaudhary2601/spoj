#include<cstdio>
#include<cstring>
using namespace std;

int lps[100000];

void computeLPS(char* str, int lps[], int n){
	int i=1, j=0;
	lps[0]=0;
	while(i<n){
		if(str[i]==str[j]){
			lps[i]=j+1;
			i++;
			j++;
		} else if(j){
			j = lps[j-1];
		} else {
			lps[i]=0;
			i++;
		}
	}
}

int getLargestRoot(char* str){
	int n = strlen(str);
	computeLPS(str, lps, n);
	int i=n; // start with LPS of lenght n
	while(i>0){
		// i length LPS is stored at index (i-1)
		if(n%(n-lps[i-1])==0) 
			return n/(n-lps[i-1]);
		i = lps[i-1];
	}
	return 1;
}

int main(){
	char str[100001];
	scanf("%s", str);
	while(str[0]!='*'){
		printf("%d\n", getLargestRoot(str));
		scanf("%s", str);
	}
}