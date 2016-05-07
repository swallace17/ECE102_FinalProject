#include<stdlib.h>
#include<string.h>
#include<stdio.h>

int main()
{
	/**************************************************************************/
	/*PART ONE- Read from original file and format relevent data into 2D Array*/
	/**************************************************************************/

	//Initialize arrays and variables
		/*Arrays*/
			//Working Arrays
				//each row stores a line of source file as string
				char file[914][481]={{0}}; 
				//same as file, but only necessary lines
				char store[40][210]={{0}};
				//same as store, but only relevent data + white space 
				char setup[40][210]={{0}};
			//Final Arrays
				//stores years 
				int finalI[40]={0};
				//stores price for each of 12 months
				float final[40][12]={{0}};
		/*Variables*/
			//used as tmp when reading from original file
	    		char* str = malloc(sizeof(char) * 10000); 
	    	//used as temp when writing to final arrays
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
	    
    //Use fget through each line of source file creating string written to 
	//file array
    int i, k,c,j = 1;
	FILE* fp = fopen("SurveyOutputServlet", "r");
	for(i = 0; i < 914; i++){
		fgets(str, 10000, fp);
		for(k = 0; k < strlen(str); k++){
                	file[j][k] = str[k];
		}	
		j++;
	}
	fclose(fp);

	//Removes unnecesary lines, leaving only lines containing relevent data
	//and copies these lines to new array 'store.'
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
	
	//Use ASCII values to clean up strings in file array leaving only relevent
	//data and white space inside a new array- 'setup.'
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

	//Write contents of store array to text file
	FILE* txt = fopen("info", "w");	
	for(i = 0; i < 40; i++){
		for(k = 0; k < 210; k++){
			fprintf(txt,"%c",setup[i][k]);
		}
		fprintf(txt,"\n");
	}
	fclose(txt);

	//Open text file and use fscanf to read each data point in, ignoring
	//white space
	FILE* read = fopen("info", "r");
	for(i = 0; i < 40; i++){
		fscanf(read, " %d %f %f %f %f %f %f %f %f %f %f %f %f", &year, &val1, &val2, &val3, &val4, &val5, &val6, &val7, &val8, &val9, &val10, &val11, &val12);
		for(k = 0; k < 12; k++){
			
			finalI[i] = year;
			if(k == 0){ //Jan
				final[i][k] = val1;
			}
			if(k == 1){ //Feb
				final[i][k] = val2;
			}
			if(k == 2){ //Mar
				final[i][k] = val3;
			}
			if(k == 3){ //April
				final[i][k] = val4;
			}
			if(k == 4){ //May
				final[i][k] = val5;
			}
			if(k == 5){ //June
				final[i][k] = val6;
			}
			if(k == 6){ //July
				final[i][k] = val7;
			}
			if(k == 7){ //Aug
				final[i][k] = val8;
			}
			if(k == 8){ //Sep
				final[i][k] = val9;
			}
			if(k == 9){ //Oct
				final[i][k] = val10;
			}
			if(k == 10){ //Nov
				final[i][k] = val11;
			}
			if(k == 11){ //Dec
				final[i][k] = val12;
			}
		}		
	}

	//Print final results for testing
	printf("Year\t Jan\t Feb\t Mar\t April\t May\t June\t July\t Aug\t Sep\t Oct\t Nov\t Dec\t\n");
	printf("*****************************************************************************************************\n");
	for(i = 0; i < 40; i++){
		printf("%4d\t", finalI[i]);
		for(k = 0; k < 12; k++){
			printf("%.3f\t",final[i][k]);
		}
		printf("\n");
	}

	/*******************************************************************/
	/*PART TWO- Use final arrays to create an XML form for Excel import*/
	/*******************************************************************/



	return(0);
}
