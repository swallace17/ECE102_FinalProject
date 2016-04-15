#include<stdlib.h>
#include<string.h>
#include<stdio.h>
int main(){
	FILE* fp;
	int i = 913;
        char* str = malloc(sizeof(char) * 10000);
	fp = fopen("SurveyOutputServlet", "r");
	for(i = 913; i > 0; i--){
		fgets(str,10000, fp);
		printf("%s", str);
	}
	return(0);
}
