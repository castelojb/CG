/*
 * Main.cpp
 *
 *  Created on: 21 de set de 2018
 *      Author: joao
 */

//includes do c++
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <string>
#include <math.h>
#include <vector>

//include da imagem
#include "CImg.h"

//includes do GL
#include <GL/glew.h>
#include <GL/glut.h>
# include <GL/freeglut.h>

//arquivos usados
#include "Vector3.h"
#include "LightSource.h"
#include "Sphere.h"
#include "Iluminacao.h"
#include "Camera.h"
#include "Plano.h"
#include "Triangulo.h"
#include "Spot.h"
#include "Quadrilatero.h"
//#include "ImageClass.h"
//#include "SOIL.h"



using namespace std;

//foto de inicializacao
string nome="sandcastle_rt.tga";


//dimensoes da tela, adaptar com a quantidade de pixels da imagem usada
GLdouble windowWidth  = 512.0;
GLdouble windowHeight = 512.0;

int window;
Vector3 camera={0,0,-500};
Vector3 LoockAt={0.0f,-96.0f,300.0f};
Vector3 ViewUp= {0.0f,150.0f,300.0f};

//CImg fundo;

GLuint* vao;
GLuint* vbo;
GLuint* ibo;



void Desenho(void)
{

	cout<<"Fazendo imagem"<<endl;

	using namespace cimg_library;

	//limpando a tela
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	
	
	//pintando o fundo
	CImg<unsigned char> fundo(nome.data());

	for(int i = 0; i < windowWidth; ++i){
		for(int j = 0; j < windowHeight; ++j){
			
			//x e y
			double x = (i  - windowWidth/2);
			double y = (j - windowHeight/2);
			Vector3 Ipix;
			Ipix[0] = (double)fundo(i, windowHeight-j, 0, 0)/255;
			Ipix[1] = (double)fundo(i, windowHeight-j, 0, 1)/255;
			Ipix[2] = (double)fundo(i, windowHeight-j, 0, 2)/255;
			glColor3f(Ipix[0], Ipix[1], Ipix[2]);
			glVertex2f(x, y);
		}
	}
	

	//definindo o boneco
		//definindo o boneco
	Sphere Hulk [25];

		Sphere peitodir= Sphere({-90.0f,10.0f+444,300.0f}, 120.0f ,10, Texture({0.0f,0.38f,0.11f} , {0.0f,0.3f,0.1f} , {0.3f,0.3f,0.1f}));
		Sphere peitoesq= Sphere({90.0f,10.0f+444,300.0f}, 120.0f ,10, Texture({0.0f,0.38f,0.11f} , {0.0f,0.3f,0.1f} , {0.3f,0.3f,0.1f})); 
	
		Sphere cabeca=Sphere({0.0f,180.0f+444,300.0f}, 100.0f,10 ,Texture({0.0f,0.38f,0.11f} , {0.0f,0.3f,0.1f} , {0.3f,0.3f,0.1f}));

		Sphere ab1 = Sphere({-40.0f,-110.0f+444,300.0f}, 60.0f ,10,Texture({0.0f,0.38f,0.11f} , {0.0f,0.3f,0.1f} , {0.3f,0.3f,0.1f}));
		Sphere ab2 = Sphere({40.0f,-110.0f+444,300.0f}, 60.0f ,10,Texture({0.0f,0.38f,0.11f} , {0.0f,0.3f,0.1f} , {0.3f,0.3f,0.1f}));
		Sphere ab3 = Sphere({-40.0f,-200.0f+444,300.0f}, 60.0f ,10,Texture({0.0f,0.38f,0.11f} , {0.0f,0.3f,0.1f} , {0.3f,0.3f,0.1f}));
		Sphere ab4 = Sphere({40.0f,-200.0f+444,300.0f}, 60.0f ,10,Texture({0.0f,0.38f,0.11f} , {0.0f,0.3f,0.1f} , {0.3f,0.3f,0.1f}));
		Sphere ab5 = Sphere({-40.0f,-290.0f+444,300.0f}, 60.0f ,10,Texture({0.0f,0.38f,0.11f} , {0.0f,0.3f,0.1f} , {0.3f,0.3f,0.1f}));
		Sphere ab6 = Sphere({40.0f,-290.0f+444,300.0f}, 60.0f ,10,Texture({0.0f,0.38f,0.11f} , {0.0f,0.3f,0.1f} , {0.3f,0.3f,0.1f}));

		Sphere pants = Sphere({0.0f,-400.0f+444,300.0f}, 100.0f ,10,Texture({0.33f,0.10f,0.55f} , {0.3f,0.1f,0.5f} , {0.3f,0.1f,0.5f}));

		Sphere legdir1 = Sphere({-90.0f,-490.0f+444,300.0f}, 80.0f ,10,Texture({0.0f,0.38f,0.11f} , {0.0f,0.3f,0.1f} , {0.3f,0.3f,0.1f}));
		Sphere legdir2 = Sphere({-140.0f,-600.0f+444,300.0f}, 80.0f ,10,Texture({0.0f,0.38f,0.11f} , {0.0f,0.3f,0.1f} , {0.3f,0.3f,0.1f}));
		Sphere legdir3 = Sphere({-190.0f,-700.0f+444,300.0f}, 80.0f ,10,Texture({0.0f,0.38f,0.11f} , {0.0f,0.3f,0.1f} , {0.3f,0.3f,0.1f}));
		Sphere legesq1 = Sphere({90.0f,-490.0f+444,300.0f}, 80.0f ,10,Texture({0.0f,0.38f,0.11f} , {0.0f,0.3f,0.1f} , {0.3f,0.3f,0.1f}));
		Sphere legesq2 = Sphere({140.0f,-600.0f+444,300.0f}, 80.0f ,10,Texture({0.0f,0.38f,0.11f} , {0.0f,0.3f,0.1f} , {0.3f,0.3f,0.1f}));
		Sphere legesq3 = Sphere({190.0f,-700.0f+444,300.0f}, 80.0f ,10,Texture({0.0f,0.38f,0.11f} , {0.0f,0.3f,0.1f} , {0.3f,0.3f,0.1f}));

		Sphere armdir1 = Sphere({-210.0f,10.0f+444,300.0f}, 90.0f ,10,Texture({0.0f,0.38f,0.11f} , {0.0f,0.3f,0.1f} , {0.3f,0.3f,0.1f}));
		Sphere armdir2 = Sphere({-300.0f,-70.0f+444,250.0f}, 80.0f ,10,Texture({0.0f,0.38f,0.11f} , {0.0f,0.3f,0.1f} , {0.3f,0.3f,0.1f}));
		Sphere armdir3 = Sphere({-230.0f,-150.0f+444,200.0f}, 70.0f ,10,Texture({0.0f,0.38f,0.11f} , {0.0f,0.3f,0.1f} , {0.3f,0.3f,0.1f}));
		Sphere armesq1 = Sphere({210.0f,10.0f+444,300.0f}, 90.0f ,10,Texture({0.0f,0.38f,0.11f} , {0.0f,0.3f,0.1f} , {0.3f,0.3f,0.1f}));
		Sphere armesq2 = Sphere({300.0f,-70.0f+444,250.0f}, 80.0f ,10,Texture({0.0f,0.38f,0.11f} , {0.0f,0.3f,0.1f} , {0.3f,0.3f,0.1f}));
		Sphere armesq3 = Sphere({230.0f,-150.0f+444,200.0f}, 70.0f ,10,Texture({0.0f,0.38f,0.11f} , {0.0f,0.3f,0.1f} , {0.3f,0.3f,0.1f}));






		Sphere olho_direito=Sphere({-20.0f,180.0f+444,200.0f}, 8.0f ,10, Texture({0.2f,0.2f,0.2f} , {0.2f,0.2f,0.2f} , {0.2f,0.2f,0.2f}));
	
		Sphere olho_esquerdo=Sphere({20.0f,180.0f+444,200.0f}, 8.0f ,10, Texture({0.2f,0.2f,0.2f} , {0.2f,0.2f,0.2f} , {0.2f,0.2f,0.2f}));
	
		Sphere nariz=Sphere({0.0f,120.0f+444,200.0f}, 8.0f , 10,Texture({0.9f,0.2f,0.2f} , {0.9f,0.2f,0.2f} , {0.9f,0.2f,0.2f}));
	

		Hulk[0]=cabeca;
		Hulk[1]=peitodir;
		Hulk[2]=olho_direito;
		Hulk[3]=olho_esquerdo;
		Hulk[4]=nariz;
		Hulk[5]=peitoesq;
		Hulk[6]=ab1;
		Hulk[7]=ab2;
		Hulk[8]=ab3;
		Hulk[9]=ab4;
		Hulk[10]=ab5;
		Hulk[11]=ab6;
		Hulk[12]=legdir1;
		Hulk[13]=legdir2;
		Hulk[14]=legdir3;
		Hulk[15]=legesq1;
		Hulk[16]=legesq2;
		Hulk[17]=legesq3;
		Hulk[18]=armdir1;
		Hulk[19]=armdir2;
		Hulk[20]=armdir3;
		Hulk[21]=armesq1;
		Hulk[22]=armesq2;
		Hulk[23]=armesq3;
		Hulk[24]=pants;
	
	Sphere Snow_Man2[2];
		Sphere barriga2=Sphere({-300.0f,-96.0f,600.0f}, 160.0f,10 , Texture({0.48f,0.47f,0.13f} , {0.3f,0.3f,0.3f} , {0.3f,0.3f,0.3f}));
		Sphere cabeca2=Sphere({-300.0f,150.0f,600.0f}, 100.0f ,10, Texture({0.48f,0.47f,0.13f} , {0.3f,0.3f,0.3f} , {0.3f,0.3f,0.3f}));
		Snow_Man2[0] = barriga2;
		Snow_Man2[1] = cabeca2;
	
	Sphere Snow_Man3[2];
		Sphere barriga3=Sphere({300.0f,-96.0f,600.0f}, 160.0f,150 , Texture({0.98f,0.11f,0.18f} , {0.3f,0.3f,0.3f} , {0.3f,0.3f,0.3f}));
		Sphere cabeca3=Sphere({300.0f,150.0f,600.0f}, 100.0f,150 , Texture({0.98f,0.11f,0.18f} , {0.3f,0.3f,0.3f} , {0.3f,0.3f,0.3f}));
		Snow_Man3[0] = barriga3;
		Snow_Man3[1] = cabeca3;
	
	//Definindo o plano infinito
	Plano chao =Plano({0.0f,-256.0f,300.0f},{0,-256,400},{100,-256,300},Texture({0.50,0.16,0.16} , {0.3,0.3,0.3} , {0.3,0.3,0.3}),100);
	
	//Defindo o triangulo
	Triangulo lente_direita=Triangulo({-20,150,192},{-20,100,192},{30,125,192},Texture({0.9f,0.9f,0.2f} , {0.9f,0.9f,0.2f} , {0.9f,0.9f,0.2f}),7);
	Triangulo lente_esquerda=Triangulo({-20,150,192},{-20,100,192},{-70,125,192},Texture({0.9f,0.9f,0.2f} , {0.9f,0.9f,0.2f} , {0.9f,0.9f,0.2f}),7);
	
	Quadrilatero tv = Quadrilatero({-40,200,200},{-40,400,200},{360,400,300},{360,200,300} ,Texture({0.9f,0.9f,0.2f} , {0.9f,0.9f,0.2f} , {0.9f,0.9f,0.2f}),7);
	
	//vetor que guarda elementos do cenario
	vector<Objeto*> cenario;
	
	//Colocando os bonecos no cenario
	for(int k=0;k<25;k++){
		cenario.push_back(&Hulk[k]);
	}

	cenario.push_back(&Snow_Man2[0]);
	cenario.push_back(&Snow_Man2[1]);
	cenario.push_back(&Snow_Man3[0]);
	cenario.push_back(&Snow_Man3[1]);
	cenario.push_back(&chao);
	cenario.push_back(&tv);
	//cenario.push_back(&lente_direita);
	//cenario.push_back(&lente_esquerda);
	

	//luz ambiente	
    Light_Source sun=Light_Source({300000000000.0f,300000000000.0f,00000.0f},{0.9f,0.9f,0.9f});
    
    //luzes secundarias
    Light_Source post=Light_Source({0000.0f,300000000000.0f,300000000000.0f},{0.9f,0.9f,0.9f});
    Spot upper=Spot({0.0f,3000000.0f,300.0f},{0.9f,0.9f,0.9f});
	
	//vetor que guarda as fontes luminosas
	vector<Fonte_Luminosa*> luzes;

	luzes.push_back(&sun);
	//luzes.push_back(&post);
	luzes.push_back(&upper);



	//onde esta a camera , para onde olha e a orientaçao
	//Vector3 LoockAt={0.0f,-96.0f,300.0f};
	//Vector3 ViewUp= {0.0f,150.0f,300.0f};
	
	
	//levando o cenario para o mundo da camera
	for(int k=0; k<cenario.size();k++){
		cenario[k]->Transform_Mundo_Camera(camera , LoockAt , ViewUp);
	}

	//levando as luzes para o mundo da camera
	for(int k=0; k<luzes.size(); k++){
		luzes[k]->Transform_Mundo_Camera(camera , LoockAt , ViewUp);	
	}
	


	//levando a camera para o seu mundo
	Mundo_Camera(camera,LoockAt,ViewUp,camera);
	

	for(int i = 0; i < windowWidth; ++i)
	{
		for(int j = 0; j < windowHeight; ++j)
		{
			//x e y
			double x = (i  - windowWidth/2);
			double y = (j - windowHeight/2);
			
			//Vetor para armazenar objetos atingidos pelo raio
			vector<Objeto*> objetos_interceptados;

			//Vetor para armazenar as distancias registradas para um raio
			vector<float> distancias;
			
			//variavel que guarda a distancia do raio
			float t;
			
			//vetor de posicionamento da tela (x,y,d)		
			Vector3 point={x,y,150};

			//percorrendo o cenario para saber se o raio intercepta um ponto
			for(int k=0;k<cenario.size();k++){
				if(cenario[k]->RayIntersects( (point - camera),camera ,&t)){
					distancias.push_back(t);
					objetos_interceptados.push_back(cenario[k]);
				}
				
			}

			//se o tamanho do meu vetor eh diferente de 0, alguem foi interceptado
			if(distancias.size() != 0){

				//laco para descobrir a menor distancia para saber o que deve ser exibido
				int menor=0;
				for(int k=0 ; k< distancias.size() ; k++){
					if(distancias[menor]>distancias[k]){
						menor=k;
					}
				}

				//calculo de onde esta localizado o ponto que sera exibido (ponto_da_origem_do_raio + direcao_do_raio * distancia)
				Vector3 hitpoint = camera + (point - camera)*distancias[menor];

				
				//vetor que guarda as posicioes do meu vector luzes que estao obstruidos pelos objetos
				vector<int> tem_sombra;


				//laco que vai verificar se o raio que sai do hitpoint ate a fonte de luz eh obstruido por algum objeto
				for(int k=0;k<cenario.size();k++){

					for(int l=0; l<luzes.size(); l++){

						//condicional: "esse raio que liga o hitpoint ate a minha luzes[l] esta obstruido?"
						if(cenario[k]->RayIntersects((luzes[l]->getPosition() - hitpoint).Normalize(),hitpoint , &t)){
							
							//guardar o seu indice l no tem_sombra
							tem_sombra.push_back(l);

						}
					}
				}

				//vetor booleano que vai guiar o meu calculo
				vector<bool> sombra;
				for(int k=0 ; k<luzes.size() ; k++){
					sombra.push_back(false);
				}

				//adicionando true nas posicisoes guardadas no tem_sombra 
				for(int k=0 ; k<tem_sombra.size() ; k++){
					sombra[tem_sombra[k]]=true;
				}

				//inicializacao da cor
				Vector3 rgb={0,0,0};
				
				//pegando a normal que sera utilizada
				Vector3 normal=objetos_interceptados[menor]->getNormal(hitpoint);

				//somatorio para a cor
				for(int k=0 ; k<luzes.size() ; k++){
					if(sombra[k]==false){
					
	    				rgb= rgb+ luzes[k]->Iluminacao(camera , hitpoint , normal , objetos_interceptados[menor]->getTexture(),objetos_interceptados[menor]->getPolimento());	
					
					}
				}
				
				//adicionando a componente ambiente que foi armazenada na posicao luzes[0]
				rgb=rgb + luzes[0]->Iluminacao(objetos_interceptados[menor]->getTexture());
				
				//fator de correcao (em fase de teste) para diminuir a luminosidade excessiva
				//float maior=rgb[0];
	    				/*
	    				for(int k=0;k<3;k++){
	    					if(maior<rgb[k]){
	    						maior=rgb[k];
	    					}
	    				}

	    				if(maior>=1){
							for(int k=0;k<3;k++){
	    						rgb[k]=rgb[k]/maior;
	    					}	    					
	    				}
						*/	    				
				
				glColor3d(rgb[0],rgb[1],rgb[2]);
				
				glVertex2d(x,y);
			}



		}
	}
	cout<<"Fim"<<endl;

	glEnd();
	glFlush();
	


}


// Callback do GLUT: Chamado na criação da janela e toda vez que ela for redimensionada
void _Redimensionar(int w, int h)
{
	windowWidth = w;
	windowHeight = h;

	// Redefinição do viewport e projeção
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-w/2, w/2, -h/2, h/2);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//glutPostRedisplay();
}

// Callback do GLUT: Eventos de teclado
void _Teclado(unsigned char key, int x, int y)
{
	switch((char)key)
	{
		// ESC
		case 27:
			glutDestroyWindow(window);
			exit(0);
			break;

		case 'w':
			camera={0,0,-250};
			nome="sandcastle_rt.tga";

			break;
		case 's':
			camera={0.0f,0.0f,1050.0f};
			nome="sandcastle_bk.tga";
			break;

		case 'a':
			camera={554,0,0};
			nome="sandcastle_lf.tga";
			break;
		case 'd':
			camera={-1054,0,0};
			nome="sandcastle_ft.tga";
			break;
		case 'q':
			camera={0,554,0};
			nome="sandcastle_dn.tga";
			break;
		case 'e':
			camera={0,-554,0};
			nome="sandcastle_up.tga";
			break;
	}

	glutPostRedisplay();
}

// Callback do GLUT: Eventos de mouse com algum botão pressionado
void MouseClick (int button, int state, int x, int y)
{
    switch (button)
    {
        case GLUT_LEFT_BUTTON: printf("Botao esquerdo.");
                               break;
        case GLUT_RIGHT_BUTTON: printf("Botao direito.");
                               break;
        case GLUT_MIDDLE_BUTTON: printf("Botao do meio.");
                               break;
    }
    if (state == GLUT_DOWN)
        printf("Pressionado na posição: ");
    if (state == GLUT_UP)
        printf("Liberado na posição: ");
    printf("(%d, %d)\n", x,y);
}
// **************************************************
// Função chamada quando o mouse anda sobre a janele
// e NÃO HÁ botão pressionado
// **************************************************
void MouseAndandoNaoPressionado (int x, int y)
{
    printf("Mouse ANDANDO solto na janela. Posição: (%d, %d)\n", x,y);

    double xo = (x  - windowWidth/2);
	double yo = (y - windowHeight/2);

    LoockAt={xo,yo,300};
    ViewUp= {xo,yo+10,300};
    glutPostRedisplay();
}
// **************************************************
// Função chamada quando o mouse anda sobre a janele
// e HÁ botão pressionado
// **************************************************
void MouseAndandoPressionado (int x, int y)
{
    printf("Mouse ANDANDO pressionado na janela. Posição: (%d, %d)\n", x,y);
}

int main(int argc, char *argv[])
{
	
	// Inicialização do GLUT e janela
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize((int) windowWidth, (int) windowHeight);
	glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)- windowWidth)/2, (glutGet(GLUT_SCREEN_HEIGHT)- windowHeight)/2);
	window = glutCreateWindow("Snow Man e o Plano infinito com Muitas Luzes");

	glewExperimental = GL_TRUE;

	//Definição de callbacks
	glutReshapeFunc(_Redimensionar);
	glutKeyboardFunc(_Teclado);
	//glutMotionFunc(_Mouse);
	glutDisplayFunc(Desenho);

	// Define as funções de MOUSE
 
    // movimento SEM botão pressionado
    glutPassiveMotionFunc(MouseAndandoNaoPressionado);

    // movimento COM botão pressionado
    glutMotionFunc(MouseAndandoPressionado);



    // Click em um botão
    glutMouseFunc(MouseClick);
	glutMainLoop();
	exit(0);

	
	return 0;
}
