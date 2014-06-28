#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;

int main()
{
	char variable[100];  
	/* code */
	ifstream fp("archivo.vrp");
	//FILE *fp;
	//fp = fopen("archivo.vrp","r");
	//while(fp.eof()){
		//fscanf(fp,"%s",variable);
		fp.getline(variable);
		cout << "Variable leida: " << variable << endl;
	//}
	
	return 0;
}