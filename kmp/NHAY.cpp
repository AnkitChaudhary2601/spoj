#include<cstdio>
#include<cstdlib>
using namespace std;

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

bool kmp(char* pattern, int n){
	int lps[n];
	computeLPS(pattern, lps, n);

	int i=0, j=0;
	char ch;
	while((ch = getchar())=='\n');
	while(ch!='\n' && ch!=EOF){
		if(pattern[j]==ch){
			i++; j++;
			if(j==n){
				printf("%d\n", i-n);
				j = lps[j-1];
			}
			ch = getchar();
		} else if(j){
			j = lps[j-1];
		} else {
			ch = getchar();
			i++;
		}
	}

	printf("\n");
	return ch!=EOF;
}

int main(){
	while(true){
		int n;
		scanf("%d", &n);
		char str[n+1];
		scanf("%s", str);
		// printf("MyString : %s\n", str);
		if(!kmp(str, n))
			break;
	}
}