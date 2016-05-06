#include<stdlib.h>
#include<string.h>
#include<stdio.h>
int main(){
	int i, k,c,j = 1;
	char file[914][481];
	char store[40][210];
        char* str = malloc(sizeof(char) * 10000);
	FILE* fp = fopen("SurveyOutputServlet", "r");
	for(i = 0; i < 914; i++){
		fgets(str, 10000, fp);
		for(k = 0; k < strlen(str); k++){
                	file[j][k] = str[k];
		}	
		j++;
	}
	
	fclose(fp);

	j = 689;
	c = 0;
	for(i = 0; i < 40; i++){
		c = 0;
		for(k = 0; k < 210; k++){
			store[i][k] = file[j][c];
			c++;
		}
		j = j + 3;
	}
	
	char setup[40][210];
	j = 0;
	c = 0;
	for(i = 0; i < 40; i++){
		c = 0;
		for(k = 0; k < 210; k++){
		
			if(store[i][k] < 46 || store[i][k] > 57 || store[i][k] == 47){
				store[i][k] = 32;
			}
			
			setup[j][c] = store[i][k];
			c++;	
		}
		j++;
	}

	FILE* txt = fopen("info", "w");	

	for(i = 0; i < 40; i++){
		for(k = 0; k < 210; k++){
			fprintf(txt,"%c",setup[i][k]);
		}
		fprintf(txt,"\n");
	}
	
	fclose(txt);

	FILE* read = fopen("info", "r");
	
	int year;
	float val1;
	float val2;
	float val3;
	float val4;
	float val5;
	float val6;
	float val7;
	float val8;
	float val9;
	float val10;
	float val11;
	float val12;
	int finalI[40];
	float final[40][12];

	for(i = 0; i < 40; i++){
		fscanf(read, " %d %f %f %f %f %f %f %f %f %f %f %f %f", &year, &val1, &val2, &val3, &val4, &val5, &val6, &val7, &val8, &val9, &val10, &val11, &val12);
		for(k = 0; k < 13; k++){
			if(k == 0){
				finalI[i] = year;
			}
			if(k == 1){
				final[i][k - 1] = val1;
			}
			if(k == 2){
				final[i][k - 1] = val2;
			}
			if(k == 3){
				final[i][k - 1] = val3;
			}
			if(k == 4){
				final[i][k - 1] = val4;
			}
			
			if(k == 5){
				final[i][k - 1] = val5;
			}
			if(k == 6){
				final[i][k - 1] = val6;
			}
			if(k == 7){
				final[i][k - 1] = val7;
			}
			if(k == 8){
				final[i][k - 1] = val8;
			}
			if(k == 9){
				final[i][k - 1] = val9;
			}
			if(k == 10){
				final[i][k - 1] = val10;
			}
			if(k == 11){
				final[i][k - 1] = val11;
			}
			if(k == 12){
				final[i][k - 1] = val12;
			}
		}
			
	}

	for(i = 0; i < 40; i++){
		printf("%d\n", finalI[i]);
		for(k = 0; k < 13; k++){
			printf("%.3f",final[i][k]);
		}
		printf("\n");
	}
	
	return(0);
}
