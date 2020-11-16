#include<iostream>
#include<windows.h> //funções de Sleep() e System()
#include<time.h> //aletorio

using namespace std;

int main(){
	int l=6, c=6, b=6;
	int contJ, contB, i, j, lin, col; // quantidade de jogadas, bombas, linhas e colunas
	bool gameover, numINV, jogINV; //fim de jogo, número invalido e jogada iinvalida
	char mA[l][c], mC[l][c]; // matriz apresentada e controladora
	contJ =0;
	contB=0;
	gameover=false;
	numINV=false;
	jogINV = false;
	
	cout<<"Jogo CAMPO MINADO!!"<<endl;
	Sleep(1000); //pausa na tela antes de apagar
	system("cls"); //limpar tela
	
	srand(time(NULL));

	if(jogINV==false)
	{
		for(i=0;i<l;i++){
			for(j=0;j<c;j++){
				mA[i][j]= ' '; //irá aparecer na casa jogada, na matriz, apresentada.
				mC[i][j]= '0'; //A matriz controladora irá simular que a casa jogada ja está ocupada
			}
		}
		srand(time(NULL));
		
		for(contB=0;contB<b;contB++){
			do{
				i=rand()%l;
				j=rand()%c;
				cout<<"i:"<<i<<endl;
				cout<<"j:"<<j<<endl;
			}while(mC[i][j]=='x'); 
			mC[i][j]='x';
		}
		
		for(i=0;i<l;i++){
			for(j=0;j<c;j++){
				if(mC[i][j]=='x'){ //checar cada posição se tem uma bomba
					if(i-1>=0){//relaciona a posição a linha de cima
						if(mC[i-1][j]!='x')//verifica se nessa posição tem bombas
							mC[i-1][j]++;//se não tem bomba soma um numero
					}
					if(i+1<l){ //linha abaixo
						if(mC[i+1][j] !='x')
							mC[i+1][j]++;
					}
					if(j-1>=0){ //coluna esquerda
						if(mC[i][j-1]!='x')
							mC[i][j-1]++;
					}
					if(j+1<c){ //coluna direita
						if(mC[i][j+1] !='x')
							mC[i][j+1]++;
					}
					if(i-1>=0&&j-1>=0){ //diagonais, diagonal esquerda acima
						if(mC[i-1][j-1] !='x')
							mC[i-1][j-1]++;
					}
					if(i-1>=0&&j+1<c){ //diagonal direita acima
						if(mC[i-l][j+1]!='x')
							mC[i-1][j+1]++;
					}
					
					if(i+1<l&&j+1<c){ //diagonal direta baixo
						if(mC[i+1][j+1]!='x')
							mC[i+1][j+1]++;
					}
					if(i+1<=l&&j-1>=0){ //diagonal esquerda baixo
						if(mC[i+l][j-1]!='x')
							mC[i+1][j-1]++;
					}	
				}
			}
		}
		
		while(!gameover)
		{
			system("cls");
			cout<<"  ";
			for(j=0;j<c;j++){
				cout<<" "<<j;
			}
			for(i=0;i<l;i++){
				cout<<"\n"<<i<<"-";
				for(j=0;j<c;j++){
					if(j==c-1){
						cout<< "|"<<mA[i][j]<<"|";
					}
					else{
						cout<<"|"<< mA[i][j];
					}	
				}
			}
		
		cout << endl;
		do{
			numINV=false;
			cout<<"Informe um numero correspondente a linha: ";
			cin>>lin;
			cout<<"Informe um numero correspondente a coluna: ";
			cin>>col;
			if(lin>=l||lin<0||col>=c||col<0){
				cout<<"Invalido"<<endl;
				cout<<"Digite outro";
				numINV=true;
			}
			if(mA[lin][col]==mC[lin][col]){
				cout<<"Invalido";
				numINV = true;
			}
		}while(numINV==true);
		mA[lin][col]=mC[lin][col]; // nn muda nada e o jogo continua
		
		if(mA[lin][col]=='x'){//bomba
		cout<<"  ";
			for(j=0;j<c;j++){
				cout<< " "<<j;
			}
			for(i=0;i<l;i++){
				cout<<"\n"<<i<<"-";
			for(j=0;j<c;j++){
				if(j==c-1){
					cout<< "|"<<mC[i][j]<<"|";
				}else{
				
					cout<<"|"<< mC[i][j];
				}
			}
		}
			
		cout<<endl;
		gameover=true;
		contJ++;
		cout<<"Voce foi explodido!"<<endl;
		cout<<"Jogadas: "<<contJ;
				
		}else{
		contJ++;
		}
			if((l*c)-b==contJ && gameover==false)
			{
				cout << "\n";
				for(j=0;j<c;j++){
					cout<<" "<<j<<"\n";
				}
				for(i=0; i<l; i++){
					cout<<" "<<i<<"\n";
				}
				gameover=true;
				cout<<"Parabens, voce ganhou!"<<endl;
				cout<<"Numero de jogadas: "<<contJ;
			}
		}
	} return 0;	
}
