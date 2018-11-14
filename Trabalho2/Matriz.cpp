#include "Matriz.h"

#include <iostream>
#include <math.h>
#include <sstream>
#include <fstream>

using namespace std;

Matriz::Matriz(){
	this->altura = 0;
	this->largura = 0;
	this->matriz = new vector< vector<float> > ( 0 , vector<float> (0) );;
	
}

Matriz::Matriz(int altura , int largura){ 
	this->altura = altura;
	this->largura = largura;
	this->matriz = new vector< vector<float> > ( largura , vector<float> (altura) );
	
}

Matriz Matriz::Gerar_Copia(){
	Matriz resposta(this->getAltura() , this->getLargura());

	//copia para uma matriz auxiliar
	for(int y=0 ; y < this->getAltura() ; y++){
		for(int x=0 ; x< this->getLargura() ; x++){

			resposta.Elemento(x,y)=this->Elemento(x,y);
		
		}
	}

	return resposta;
}

string Matriz::toString(){
	
	string m;
	for(int y = 0 ; y < this->getAltura() ; y++){

		m = m + '|';
		for(int x=0 ; x<this->getLargura() ; x++){
			m = m + " " + to_string( this->Elemento(x ,y) ) + " ";
		}
		m = m + '|';
		m = m + "\n";
	}
	return m;
}

float& Matriz::Elemento(int x , int y){
	return (*this->matriz)[x][y];
}

int Matriz::getAltura(){
	return this->altura;
}

int Matriz::getLargura(){
	return this->largura;
}




void Matriz::operator=(Matriz m){
	//this->matriz.~vector< vector<float> >(this->getLargura() ,vector<float>(this->getAltura()) );

	delete this->matriz;
	this->matriz = new vector< vector<float> > ( m.getLargura() , vector<float> ( m.getAltura() ) );
	
	this->altura = m.getAltura();
	this->largura = m.getLargura();


	for(int y=0 ; y < this->getAltura() ; y++){
		for(int x=0 ; x< this->getLargura() ; x++){

			this->Elemento(x,y)=m.Elemento(x,y);
		
		}
	}

}

Matriz Matriz::operator+(Matriz m){
	if(this->getAltura() == m.getAltura() and this->getLargura() == m.getLargura() ){

		int alt = this->getAltura();
		int larg = this->getLargura();

		Matriz soma(larg , alt );


		for(int y=0 ; y < alt ; y++){
			for(int x=0 ; x < larg ; x++){
				soma.Elemento(x,y) = this->Elemento(x,y) + m.Elemento(x,y);
			}
		}

		return soma;
	
	}else{

		cout<<"SOMA INVALIDA: "<< endl << this->toString() << "+ \n" <<m.toString() <<endl;
	
		Matriz soma;

		return soma;
	}
}

Matriz Matriz::operator-(Matriz m){
	if(this->getAltura() == m.getAltura() and this->getLargura() == m.getLargura() ){

		int alt = this->getAltura();
		int larg = this->getLargura();

		Matriz subtracao(larg , alt );


		for(int y=0 ; y < alt ; y++){
			for(int x=0 ; x < larg ; x++){
				subtracao.Elemento(x,y) = this->Elemento(x,y) + m.Elemento(x,y);
			}
		}

		return subtracao;
	
	}else{

		cout<<"SUBTRACAO INVALIDA: "<< endl << this->toString() << "- \n" <<m.toString() <<endl;
	
		Matriz subtracao;

		return subtracao;
	}
}


Matriz Matriz::operator*(Matriz m){

	if(this->getLargura() != m.getAltura()){

		cout<<"MULTIPLICACAO INVALIDA: "<< endl << this->toString() << "* \n" <<m.toString() <<endl;
	
		Matriz multiplicacao;
	
		return multiplicacao;
	
	}else{

		Matriz multiplicacao(this->getAltura(), m.getLargura());

		for(int y = 0; y < multiplicacao.getAltura(); y++){

			for(int x = 0; x < multiplicacao.getLargura(); x++){

				for(int k = 0; k < m.getAltura(); k++){

					multiplicacao.Elemento(x,y) = multiplicacao.Elemento(x,y) + ( this->Elemento(k,y) * m.Elemento(x,k) );
				}			
			
			}
		
		}
		
		return multiplicacao;
		
	}

}

Matriz Matriz::operator*(float e){
	
	int alt = this->getAltura();
	int larg = this->getLargura();

	Matriz produto_por_escalar(larg , alt);
	
	for(int y=0 ; y < alt ; y++){
			for(int x=0 ; x < larg ; x++){
				produto_por_escalar.Elemento(x,y) = this->Elemento(x,y) * e;
			}
	}

	return produto_por_escalar;	

}

Matriz Matriz::operator/(float e){
	
	int alt = this->getAltura();
	int larg = this->getLargura();

	Matriz divisao_por_escalar(larg , alt);
	
	for(int y=0 ; y < alt ; y++){
			for(int x=0 ; x < larg ; x++){
				divisao_por_escalar.Elemento(x,y) = this->Elemento(x,y) / e;
			}
	}

	return divisao_por_escalar;	

}

Matriz Matriz::Gerar_Identidade(int t){
	
	Matriz id(t,t);

	for(int x=0 ; x<t ; x++){
		id.Elemento(x,x)=1;
	}

	return id;
}

Matriz Matriz::Gerar_Unitario(int y , int x){
	Matriz unitario(y,x);

	for(int yi=0 ;yi <y ; yi++){
		for(int xi=0 ; xi <x ; xi++){
			unitario.Elemento(xi,yi)=1;
		}
	}
	return unitario;
}

Matriz Matriz::Transposta(){
	Matriz transposta(this->getLargura() , this->getAltura());

	for(int y=0 ; y< transposta.getAltura() ; y++){
		for(int x=0 ; x < transposta.getLargura() ; x++){
			transposta.Elemento(x,y)= this->Elemento(y,x);
		}
	}

	return transposta;

}

Matriz Matriz::Divisao_da_Linha(int altura , float divisor){

	Matriz resposta = this->Gerar_Copia();

	//operacao propriamente dita
	for(int x=0 ; x< resposta.getLargura() ; x++){
		resposta.Elemento(x,altura) = resposta.Elemento(x,altura) / divisor;
	}

	return resposta;

}

Matriz Matriz::Subtracao_de_Linha(int y1 , int y2){

	Matriz resposta = this->Gerar_Copia();

	for(int x=0 ; x<resposta.getLargura() ; x++){

		resposta.Elemento(x,y2) = resposta.Elemento(x , y1) - resposta.Elemento(x , y2);
	
	}

	return resposta;

}

Matriz Matriz::Subtracao_de_Linha(int y1 , int y2 , float p){

	Matriz resposta = this->Gerar_Copia();

	for(int x=0 ; x<resposta.getLargura() ; x++){

		resposta.Elemento(x,y2) =  resposta.Elemento(x , y2) + - p*resposta.Elemento(x , y1);
	
	}

	return resposta;

}

Matriz Matriz::Troca_de_Linha(int y1 , int y2){

	Matriz resposta = this->Gerar_Copia();

	float troca=0;

	for(int x=0 ; x<resposta.getLargura() ; x++ ){
		troca=resposta.Elemento(x , y1);

		resposta.Elemento(x , y1) = resposta.Elemento(x , y2);

		resposta.Elemento(x,y2)=troca;
	}	

	return resposta;


}

float Matriz:: Maior_da_Diagnal_Principal(){

	float maior= this->Elemento(0,0);

	for(int x=0 ; x<this->getLargura() ; x++){
		if(maior< this->Elemento(x,x)){

			maior=this->Elemento(x,x);
		
		}
	}

	return maior;
}

int Matriz::Maior_da_Coluna_Pivotacao_Parcial(int xo , int yo){
	
	int cy = this->Elemento(xo , yo);
	
	for(int y=yo ; y<this->getAltura() ; y++){
		if(fabs(this->Elemento(xo , cy)) < fabs(this->Elemento(xo, y) ) ){
			cy=y;
		}
	}

	return cy;
}



Matriz Matriz::Gauss_Pivotacao_Parcial( Matriz &vetor_de_constantes ){

	Matriz resposta = this->Gerar_Copia();

	//etapa de pivoteacao parcial
	for(int x=0 ; x < resposta.getLargura() ; x++){
		int yp;

		yp=resposta.Maior_da_Coluna_Pivotacao_Parcial(x,x);

		if(resposta.Elemento(x , yp) == 0){

			cout<< "MATRIZ SINGULAR: "<< endl << resposta.toString() <<endl;

			Matriz vazio;
			return  vazio;
		
		}

		resposta=resposta.Troca_de_Linha(x ,yp);

		vetor_de_constantes= vetor_de_constantes.Troca_de_Linha(x,yp);

	}

	cout<<"PIVOTADA: "<< endl <<resposta.toString()<<endl;
	
	//gauss
	return resposta.Gauss(vetor_de_constantes);

}



Matriz Matriz::Gauss( Matriz &vetor_de_constantes ){
	
	Matriz resposta = this->Gerar_Copia();

	for(int x=0 ; x < resposta.getLargura() ; x++){

		vetor_de_constantes = vetor_de_constantes.Divisao_da_Linha( x , resposta.Elemento(x,x) );
 		
		resposta= resposta.Divisao_da_Linha(x , resposta.Elemento(x,x));


		for(int y=x+1 ; y < resposta.getAltura() ; y++){
			
			vetor_de_constantes = vetor_de_constantes.Subtracao_de_Linha( x , y , resposta.Elemento(x,y) );
			resposta = resposta.Subtracao_de_Linha(x , y , resposta.Elemento(x,y) );

			
		}

	}
	
	return resposta;

}

Matriz Matriz::Gauss( Matriz &vetor_de_constantes,Matriz &vetor_x ){
	
	if( vetor_x.getLargura()==1 and vetor_x.getAltura()==vetor_de_constantes.getAltura() ){


		Matriz A= this->Gauss(vetor_de_constantes);

		int n=vetor_de_constantes.getAltura();

		float X[n];

		X[n-1]= vetor_de_constantes.Elemento(0 , vetor_de_constantes.getAltura()-1 );


		for(int y = n-1 ; y>=0 ; y--){

			float soma=0;

			for(int x= y+1 ; x<A.getLargura() ; x++){
			
				soma=soma + ( A.Elemento( x , y ) * X[x] );
				
			}

			X[y]= vetor_de_constantes.Elemento(0,y)-soma;

		}


		for(int k=0 ; k<n ; k++){
			
			vetor_x.Elemento(0,k)=X[k];

		}

		return A;
	}else{
		cout<< "PARAMETRO INVALIDO: MEDIDAS FORA DO NORMAL"<<endl;
		Matriz erro;
		return erro;
	}
}

Matriz Matriz::Gauss_Pivotacao_Parcial( Matriz &vetor_de_constantes,Matriz &vetor_x ){
	
	if( vetor_x.getLargura()==1 and vetor_x.getAltura()==vetor_de_constantes.getAltura() ){

		

		Matriz A= this->Gauss_Pivotacao_Parcial(vetor_de_constantes);


		int n=vetor_de_constantes.getAltura();

		float X[n];

		X[n-1]= vetor_de_constantes.Elemento(0 , vetor_de_constantes.getAltura()-1 );


		for(int y = n-1 ; y>=0 ; y--){

			float soma=0;

			for(int x= y+1 ; x<A.getLargura() ; x++){
			
				soma=soma + ( A.Elemento( x , y ) * X[x] );
				
			}

			X[y]= vetor_de_constantes.Elemento(0,y)-soma;

		}


		for(int k=0 ; k<n ; k++){
			
			vetor_x.Elemento(0,k)=X[k];

		}

		return A;
	}else{
		cout<< "PARAMETRO INVALIDO: MEDIDAS FORA DO NORMAL"<<endl;
		Matriz erro;
		return erro;
	}	
}

Matriz Matriz::Fatoracao_LU( Matriz &vetor_de_constantes , Matriz &vetor_x , Matriz &Lo , Matriz &Uo){
	
	Matriz U = this->Gerar_Copia();

	Matriz L = this->Gerar_Identidade( this->getAltura() ); 

	for(int x=0 ; x < U.getLargura() ; x++){

		for(int y=x+1 ; y < U.getAltura() ; y++){
			
			//vetor_de_constantes = vetor_de_constantes.Subtracao_de_Linha( x , y , U.Elemento(x,y)/U.Elemento(x,x) );
			
			L.Elemento(x,y)= U.Elemento(x,y)/U.Elemento(x,x);

			U = U.Subtracao_de_Linha(x , y , U.Elemento(x,y)/U.Elemento(x,x) );

			
		}

	}
	

	int n=vetor_de_constantes.getAltura();

	float X[n];

	X[0]= vetor_de_constantes.Elemento(0 ,0)/L.Elemento(0,0);


	for(int y = 0 ; y<n ; y++){

		float soma=0;

		for(int x= y-1 ; x>=0 ; x--){
		
			soma=soma + ( L.Elemento( x , y ) * X[x] );
			
		}

		X[y]= vetor_de_constantes.Elemento(0,y)-soma;

	}

	//Matriz vetor_x(n, 1);

	for(int k=0 ; k<n ; k++){
		
		vetor_x.Elemento(0,k)=X[k];

	}

	
	
	X[n-1]= vetor_x.Elemento(0 , vetor_x.getAltura()-1 ) / U.Elemento( U.getLargura()-1 , U.getLargura()-1 );

	

	for(int y = n-1 ; y>=0 ; y--){

		float soma=0;

		for(int x= y+1 ; x<U.getLargura() ; x++){
		
			soma=soma + ( U.Elemento( x , y ) * X[x] );
			
		}

		X[y]= (vetor_x.Elemento(0,y)-soma) / U.Elemento(y,y);

	}


	for(int k=0 ; k<n ; k++){
		
		vetor_x.Elemento(0,k)=X[k];

	}	

	//cout<<vetor_x.toString()<<endl;

	Lo=L;
	Uo=U;


	return L*U ;	
}


Matriz Matriz::Fatoracao_LU_Pivotamento_Parcial( Matriz &vetor_de_constantes , Matriz &vetor_x , Matriz &Lo , Matriz &Uo){

	Matriz resposta= this->Gerar_Copia();

	//etapa de pivoteacao parcial
	for(int x=0 ; x < resposta.getLargura() ; x++){
		
		int yp=0;

		yp=resposta.Maior_da_Coluna_Pivotacao_Parcial(x,x);
		
		if(resposta.Elemento(x , yp) == 0){

			cout<< "MATRIZ SINGULAR: "<< endl << resposta.toString() <<endl;

			Matriz vazio;
			return  vazio;
		
		}

		resposta=resposta.Troca_de_Linha(x ,yp);
	}

	cout<<"PIVOTADA: "<< endl <<resposta.toString()<<endl;
	
	return resposta.Fatoracao_LU(vetor_de_constantes , vetor_x , Lo , Uo);	
}

float Matriz::Determinante_Gauss(){
	Matriz resposta = this->Gerar_Copia();

	for(int x=0 ; x < resposta.getLargura() ; x++){

		for(int y=x+1 ; y < resposta.getAltura() ; y++){
			
			//vetor_de_constantes = vetor_de_constantes.Subtracao_de_Linha( x , y , U.Elemento(x,y)/U.Elemento(x,x) );

			resposta = resposta.Subtracao_de_Linha(x , y , resposta.Elemento(x,y)/resposta.Elemento(x,x) );

			
		}
	}

	float produtorio =1;

	for(int x=0 ; x<resposta.getLargura() ; x++){
		produtorio = produtorio * resposta.Elemento(x,x);
	}

	return produtorio;
}

Matriz Matriz::Gauss_Jordam(Matriz &vetor_de_constantes){
	Matriz resposta = this->Gerar_Copia();

	resposta = resposta.Gauss(vetor_de_constantes);

	for(int x=resposta.getLargura()-1 ; x >=0 ; x--){

		vetor_de_constantes = vetor_de_constantes.Divisao_da_Linha( x , resposta.Elemento(x,x) );
 		
		resposta= resposta.Divisao_da_Linha(x , resposta.Elemento(x,x));


		for(int y=x-1 ; y >=0 ; y--){
			
			vetor_de_constantes = vetor_de_constantes.Subtracao_de_Linha( x , y , resposta.Elemento(x,y) );
			resposta = resposta.Subtracao_de_Linha(x , y , resposta.Elemento(x,y) );

			
		}

	}

	//cout<<resposta.toString()<<endl;
	//cout<<vetor_de_constantes.toString()<<endl;

	return resposta;
}

Matriz Matriz::Gauss_Jordam( Matriz &vetor_de_constantes,Matriz &vetor_x ){
	Matriz A= this->Gauss_Jordam(vetor_de_constantes);

	int n=vetor_de_constantes.getAltura();

	float X[n];

	X[n-1]= vetor_de_constantes.Elemento(0 , vetor_de_constantes.getAltura()-1 );


	for(int y = n-1 ; y>=0 ; y--){

		float soma=0;

		for(int x= y+1 ; x<A.getLargura() ; x++){
		
			soma=soma + ( A.Elemento( x , y ) * X[x] );
			
		}

		X[y]= vetor_de_constantes.Elemento(0,y)-soma;

	}


	for(int k=0 ; k<n ; k++){
		
		vetor_x.Elemento(0,k)=X[k];

	}

	return A;
}

void Matriz::Limpar(){

	for(int y=0 ; y< this->getAltura() ; y++){
		for(int x=0 ; x< this->getLargura() ; x++){
			this->Elemento(x,y)=0;
		}
	}

}