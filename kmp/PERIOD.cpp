#include<cstdio>
#include<cstring>
using namespace std;

int lps[1000000];

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

int getLargestRoot(char* str, int n){
	int i=n; // start with LPS of lenght n
	while(i>0){
		// i length LPS is stored at index (i-1)
		if(n%(n-lps[i-1])==0) 
			return n/(n-lps[i-1]);
		i = lps[i-1];
	}
	return 1;
}

void findPeriod(char* str, int n){
	computeLPS(str, lps, n);
	for(int i=1; i<n; i++){
		int len = i+1;
		if(len%(len-lps[i])==0){
			int root = len/(len-lps[i]);
			if(root>1){
				printf("%d %d\n", i+1, root);
			}
		}
	}
}

int main(){
	int n, len;
	char str[1000001];
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		printf("Test case #%d\n", i);
		scanf("%d", &len);
		scanf("%s", str);
		findPeriod(str, len);
		printf("\n");
	}
}