#ifndef MATRIZ_H_
#define MATRIZ_H_
#include <vector>
#include <string>

using namespace std;
class Matriz{

private:
	
	int altura;
	
	int largura;

	vector<vector<float>> *matriz;
	
public:

	//construtores
	Matriz();
	Matriz(int altura , int largura);

	//consultas
	float& Elemento(int x , int y);
	int getAltura();
	int getLargura();
	void Limpar();
	//cout do objeto
	string toString();
	
	//operadores do objeto
	void operator=(Matriz m);

	Matriz operator+(Matriz m);
	
	Matriz operator-(Matriz m);
	
	Matriz operator*(Matriz m);
	Matriz operator*(float e);

	Matriz operator/(float e);

	//geradores de matrizes uteis
	Matriz Gerar_Identidade(int x);
	Matriz Gerar_Unitario(int y , int x);
	Matriz Gerar_Copia();
	Matriz Transposta();

	//manipuladores de matriz
	Matriz Divisao_da_Linha(int y ,float divisor);
	Matriz Subtracao_de_Linha(int y1 , int y2);
	Matriz Subtracao_de_Linha(int y1 , int y2 , float p);
	Matriz Troca_de_Linha(int y1 , int y2);
	float Maior_da_Diagnal_Principal();
	int Maior_da_Coluna_Pivotacao_Parcial(int xo , int yo);

	//metodos uteis
	Matriz Gauss( Matriz &vetor_de_constantes );//ok
	Matriz Gauss_Pivotacao_Parcial( Matriz &vetor_de_constantes );//ok
	
	Matriz Gauss( Matriz &vetor_de_constantes,Matriz &vetor_x );//ok
	Matriz Gauss_Pivotacao_Parcial( Matriz &vetor_de_constantes,Matriz &vetor_x );//ok

	Matriz Fatoracao_LU( Matriz &vetor_de_constantes , Matriz &vetor_x , Matriz &Lo , Matriz &Uo);//ok
	Matriz Fatoracao_LU_Pivotamento_Parcial( Matriz &vetor_de_constantes , Matriz &vetor_x , Matriz &Lo , Matriz &Uo);//ok

	float Determinante_Gauss();

	Matriz Gauss_Jordam(Matriz &vetor_de_constantes);
	Matriz Gauss_Jordam( Matriz &vetor_de_constantes,Matriz &vetor_x );


};

#endif /* MATRIZ_H_ */