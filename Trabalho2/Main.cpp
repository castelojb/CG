
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <string>


#include "Matriz.h"

using namespace std;


int main(int argc, char *argv[]){



	Matriz q1(3,3);

	q1.Elemento(0,0)=20;
	q1.Elemento(1,0)=7;
	q1.Elemento(2,0)=9;

	q1.Elemento(0,1)=7;
	q1.Elemento(1,1)=30;
	q1.Elemento(2,1)=8;

	q1.Elemento(0,2)=9;
	q1.Elemento(1,2)=8;
	q1.Elemento(2,2)=30;

	Matriz vq1(3,1);

	vq1.Elemento(0,0)=16;
	vq1.Elemento(0,1)=38;
	vq1.Elemento(0,2)=38;

	cout<< endl <<"MATRIZ ORIGINAL: "<< endl <<q1.toString()<<endl;

	cout<< "VETOR DE CONSTANTES ORIGINAL: "<< endl << vq1.toString()<<endl;

	cout<< "------------------TRECHO DA QUESTAO 1-------------------------"<<endl;

	Matriz vetor_de_constantes1 = vq1.Gerar_Copia();

	Matriz vetor_x(3,1);

	Matriz g = q1.Gerar_Copia();

	Matriz gauss = g.Gauss(vetor_de_constantes1 , vetor_x );

	cout<< "MATRIZ APOS GAUSS: "<< endl << gauss.toString()<<endl;

	cout<< "VETOR DE CONSTANTES APOS GAUSS: "<< endl << vetor_de_constantes1.toString() <<endl;

	cout << "VETOR DE VALORES DE X ATRAVES DE GAUSS: "<< endl << vetor_x.toString() <<endl;

///////////////////////////////////////////////////////////////////////////////////////////////
	
	cout<< "AGORA COM PIVOTAMENTO: 	"<<endl<<endl;

	vetor_de_constantes1 = vq1.Gerar_Copia();

	Matriz gp = q1.Gerar_Copia();

	Matriz vetor_x2(3,1);

	Matriz gaussp = gp.Gauss_Pivotacao_Parcial( vetor_de_constantes1,vetor_x2 );
	
	cout<< "MATRIZ APOS GAUSS PIVOTADA: "<< endl << gaussp.toString()<<endl;

	cout<< "VETOR DE CONSTANTES APOS GAUSS PIVOTADA: "<< endl << vetor_de_constantes1.toString() <<endl;

	cout << "VETOR DE VALORES DE X ATRAVES DE GAUSS PIVOTADA: "<< endl << vetor_x2.toString() <<endl;
////////////////////////////////////////////////////////////////////////////////////////////

	cout<<"--------------------TRECHO DA QUESTAO 2--------------------------"<<endl;

////////////////////////////////////////////////////////////////////////////////////////////

	Matriz vetor_x3(3,1);
	vetor_de_constantes1 = vq1.Gerar_Copia();
	Matriz lu = q1.Gerar_Copia();

	Matriz L;
	Matriz U;

	Matriz LU= lu.Fatoracao_LU(vetor_de_constantes1 , vetor_x3 , L , U);

	cout<<"MATRIZ L: "<< endl << L.toString() <<endl;
	cout<<"MATRIZ U: "<< endl << U.toString() <<endl;
	cout<<"MATRIZ L*U"<< endl << LU.toString() <<endl;
	cout<<"VETOR X ATRAVES DA FATORACAO LU: "<< endl << vetor_x3.toString() <<endl;

//////////////////////////////////////////////////////////////////////////////////////////////

	cout<<"AGORA COM PIVOTEAMENTO: "<< endl << endl;

	Matriz vetor_x4(3,1);
	vetor_de_constantes1 = vq1.Gerar_Copia();
	Matriz lup = q1.Gerar_Copia();
	
	Matriz Lp;
	Matriz Up;


	lup= lup.Fatoracao_LU_Pivotamento_Parcial(vetor_de_constantes1 , vetor_x4 , Lp , Up);

	cout<<"MATRIZ L: "<< endl << Lp.toString() <<endl;
	cout<<"MATRIZ U: "<< endl << Up.toString() <<endl;
	cout<<"MATRIZ L*U"<< endl << lup.toString() <<endl;
	cout<<"VETOR X ATRAVES DA FATORACAO LU: "<< endl << vetor_x4.toString() <<endl;	

	
//////////////////////////////////////////////////////////////////////////////////////////////


	cout<<"___________________________QUESTAO 3_________________________________"<<endl<<endl;

	Matriz gj = q1.Gerar_Copia();

	cout<<"DETERMINANTE PELO METODO GAUSS: "<< gj.Determinante_Gauss() << endl<<endl;

	////////////////////////////////////////////////////////////////////////////////////////

	Matriz Inversa =Inversa.Gerar_Identidade(3);

	Matriz vetor_x5(3,1);

	Matriz gji = q1.Gerar_Copia();

	Matriz gauss_jordam = gji.Gauss_Jordam( Inversa , vetor_x5 );

	cout<<"MATRIZ INVERSA ACHADA: "<< endl << Inversa.toString()<<endl; 

	//Matriz teste = q1*Inversa;

	cout<<"INVERSA * ORIGINAL: "<< endl << (q1*Inversa).toString() <<endl;
	
	return 0;
}