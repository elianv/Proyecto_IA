#include <iostream>
#include <fstream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>



using namespace std;

int main()
{
	//char variable[100];  
	char str1[20],str2[20];
	int dimension, capacidad, vehiculos, num;
	int x,y;
	int i = 1;
	float varx, vary;

	FILE *fp;
	fp = fopen("archivo.vrp","r");
	
	while(!feof(fp)){
		
		if(i < 4)
			fscanf(fp,"%s %s",str1,str2);	
		if(i == 4){
			fscanf(fp,"%s %d\n",str1,&dimension);
			int matriz_costos[dimension][dimension];
			int matriz_distancias[dimension][dimension];
			//int matriz[dimension][dimension][dimension];
		}
		if(i == 5)
			fscanf(fp,"%s %d\n",str1,&capacidad);
		if(i == 6)
			fscanf(fp,"%s %d\n",str1,&vehiculos);
		if(i >= 7 && i <=9)
			fscanf(fp,"%s %s",str1,str2);
		if (i == 10)
			fscanf(fp,"%s\n",str1);
		if ((i>10) && (i<dimension+10)){
			fscanf(fp,"%d %f %f\n",&num,&varx,&vary);
			x = (int)(varx);
			y = (int)(vary);
			matriz[x][y] = num;
			printf("i: %d nodo: %d varx: %f vary: %f\n",i,num,varx,vary);
		}
		if (i == (dimension+10))
			fscanf(fp,"%s\n",str1);
		if ((i>dimension+10) && (i<2*dimension+10)){	
			fscanf(fp,"%d %d\n",&x,&y);
			printf("i: %d nodo: %d demanda: %d\n",i,x,y);
		}
		if(i == 2*dimension+10)
			fscanf(fp,"%s\n",str1);
		if(i == 2*dimension+11){
			fscanf(fp,"%f %f\n",&varx,&vary);
			printf("i: %d deposito x:%f y:%f\n",i,varx,vary );
		}
		if(i>2*dimension+11)
			fscanf(fp,"%s\n",str1);

		i++;
		
	}
	fclose(fp);
	
	/* code 
	ifstream fp("archivo.vrp");
	
	while(!fp.eof()){
		fp.getline(variable,100);
		
		cout << "Variable leida: " << variable << endl;
		
		//char *ptr;
		//string variable;

		//split(campos,variable,is_any_of(" "));
		//cout <<"vector :" << campos << endl;
		
		ptr = strtok(variable," ");
		while(ptr != NULL){
			//variable = prt;
			//cout << ptr << endl;	
			ptr = strtok(NULL, " ");
    	}
		
		
	}
	*/

	return 0;
}