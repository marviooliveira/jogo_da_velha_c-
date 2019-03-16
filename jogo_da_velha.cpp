  #include <stdio.h>
  #include <stdlib.h>
  #include <string>
  #include <iostream>
  #include <stdbool.h>
  #include <time.h>
  using namespace std;
  ////declaracao de funcoes/////
  void decoracao();
  void menuInicial();
  void sobreGame();
  void limpaTela();
  void iniciaTabuleiro();
  void desenhaTabuleiro();
  void jogo();
  void escolhaJogador();
  void mapaPosicoes();
  int confereEmpate(char tabuleiro[3][3]);
  int confereTabuleiro(char tabuleiro[3][3]);
  ///////criacao da minha funcao ma/n
  int main(){
    menuInicial(); ///desenha menu inicial


    system("pause");
  }


  //////funcao decora game//////
  void decoracao(){
      cout<<"\n******************************";
  }
  /////////funcao menu incial//////
  void menuInicial(){
    ///enquanto opcao n for valida mostra menu
    int opcao=0;
    ///string nomeJogador1;
    while(opcao<1 || opcao>3){
      limpaTela();
      decoracao();


      cout<<"\n********* BEM VINDO **********";
      cout<<"\n************* AO *************";
      cout<<"\n********JOGO DA VELHA*********";


      decoracao();

      cout<<"\n1-Jogar.";
      cout<<"\n2-Sobre o game.";
      cout<<"\n3-Sair.";
      cout<<"\nSua opcao: ";
      cin>>opcao;
      switch (opcao){
        case 1:
            limpaTela();
            ///cout<<"Digite o nome do jogador 1:\n";
            ///cin>>nomeJogador1;
            jogo();///chama o jogo principal, obs: aqui que eu digitaria caso botasse nome do jogador
          break;
        case 2:
        ///informacoes sobre o game
            sobreGame();
          break;
        case 3:
        ///fim de jogo
          cout<<"\nTchau!";
          break;
        default:
          cout<<"\nOpcao invalida!";
          break;
      }
    }
  }
  //////funcao que reinicia ou inicia o meu tabuleiro(---)
  void iniciaTabuleiro(char tabuleiro[3][3]){
    ///tabuleiro de matriz 3x3
    int i,j;
    ////imprimindo tabuleiro
    for (i=0;i<3;i++){
      for (j=0;j<3;j++){
        tabuleiro[i][j]='-';
      }
    }
  }
  ///funcao que exibe na tela o tabuleiro
  void desenhaTabuleiro(char tabuleiro[3][3]){
    int i,j;
    ///desenhando meu tabuleiro//
    //cout<<"\nQue venca o melhor!\n";
    for (i=0;i<3;i++){
      for (j=0;j<3;j++){
        cout<<tabuleiro[i][j];
      }
      cout<<"\n";
    }
  }
  ////funcao que inicializa o game (press 1)
  void jogo(){
    char tabuleiro[3][3];
    string jogadorRodada; ///declara o nome do jogador da rodada, o atual no caso
    int i,j;
    int linhaJogada, colunaJogada,posicaoJogada;
    int estadoJogo=1;  ///0=nao jogo. 1=jogo
    int escolha; ///variavel que define com qual cada um comeca, x ou o
    //int playerInicial;
    int rodada=0;///calcula o numero de rodadas
    int reiniciar; ///opcao de reinico
    bool posicionouJogada=false; ///verifica se o usuario jogou
    char usuario,maquina; ///
    int turnoJogo;
    srand((unsigned)time(NULL));///aleatorio
    int nivelMedio=rand()%9; ////aleatorio para nivel medio
    int nivelDificil;
    int empate=0;
    iniciaTabuleiro(tabuleiro); ///desenha reinicia meu tabuleiro ou incia(--)
    ///parte de qual ele vai escolher x ou o
    cout<<"\n Para jogar com 'X'(tecle 1), 'O'(tecle 0):\n";
    cin>>escolha;
    if (escolha==1){
      usuario='X';
      maquina='O';
    }else if(escolha==0){
      usuario='O';
      maquina='X';
    }
    ///fim da parte de receber x ou o do usuario
    ///tentando a parada de quem deve comecar
    cout<<"\nQuem deve comecar o jogo?\n"<<"Usuario(tecle 1)\n"<<"Maquina(tecle 0)\n";
    cin>>turnoJogo;

    ///funcao que printa e defne a dificuldade
    int dificuldade;
    cout<<"\nDefina a dificuldade da maquina:\n";
    cout<<"1-Facil\n"<<"2-Medio\n"<<"3-Dificil\n";
    cin>>dificuldade;
    ///loop que repete preenchendo sempre a matriz do jogo
    while(rodada<=9 && estadoJogo==1){
      limpaTela();
      cout <<"\nRodada:" << rodada << "\n";
    // cout <<"Pontuacao:" << nomeJogador1 << " " << pontuacaoJogador1 << "x" << pontuacaoJogador2 << " ";

      desenhaTabuleiro(tabuleiro);
      mapaPosicoes(); ///desneho as posicoes
      //Atualiza o nome do jogador atual
      /*
        if(escolha == 1){
          jogadorRodada = nomeJogador1;
        }else{
          nomeDoJogadorAtual = nomeDoJogadorDois;
        }
      */
      ///posicionouJogada=false; //verifica que ate agr n foi marcado nada
      ///isso serve para que cada posucao no mapa tenha um par ordenado
      int posicoes[9][2] = {{2,0},{2,1},{2,2},{1,0},{1,1},{1,2},{0,0},{0,1},{0,2}}; //1,2,3,4....

 /// POSSIBLIDADE 1 (VEZ DO USUARIO QUANDO MAQUINA FOR FACIL E USUARIO COMECA)
     if (turnoJogo==1 && dificuldade==1){
           ///usuario comeca e maquina facil
          cout<<"\nDigite uma posicao: \n";
          cin>>posicaoJogada;
          linhaJogada = posicoes[posicaoJogada-1][0]; ///linha e coluna de acordo com a posicao jogada
          colunaJogada = posicoes[posicaoJogada-1][1];
          ////verifica se o espaco esta vazio
          if(tabuleiro[linhaJogada][colunaJogada] == '-'){
            ///jogada do usuario
            tabuleiro[linhaJogada][colunaJogada]=usuario; //n importa quem eh x ou bola, ele preenche
            turnoJogo=0;
            limpaTela();
            cout <<"\nRodada:" << rodada << "\n";
            desenhaTabuleiro(tabuleiro);
            mapaPosicoes(); ///desneho as posicoes

          }
          rodada++;
      } ///FIM DAS POSSIBILIDADES UM
      ///COMECO POSSIBILIDADE 2 (VEZ DA MAQUINA QUANDO MAQUINA FOR FACIL E COMECA))
      if (turnoJogo==0 && dificuldade==1){
         ///maquina joga
        //posicionouJogada=true;
          for (i=0;i<3;i++){
              for (j=0;j<3;j++){
                if(tabuleiro[i][j]=='-' && turnoJogo==0){
                   tabuleiro[i][j]=maquina;
                  turnoJogo=1;
                  limpaTela();
          cout <<"\nRodada:" << rodada << "\n";
          desenhaTabuleiro(tabuleiro);
          mapaPosicoes(); ///desneho as posicoes
                }
              }
            }
          rodada++;
      } ///fim Usuario joga e possibilidade 2

///aqui comeco a possibilidade 3(VEZ DO USUARIO,usuario comeca e maquina nivel medio)
      if (turnoJogo==1 && dificuldade==2){
          //posicionouJogada=true
          cout<<"\nDigite uma posicao: \n";
          cin>>posicaoJogada;
          linhaJogada = posicoes[posicaoJogada-1][0]; ///linha e coluna de acordo com a posicao jogada
          colunaJogada = posicoes[posicaoJogada-1][1];
          ////verifica se o espaco esta vazio
          if(tabuleiro[linhaJogada][colunaJogada] == '-' || tabuleiro[linhaJogada][colunaJogada] == maquina ){
            ///jogada do usuario
            tabuleiro[linhaJogada][colunaJogada]=usuario; //n importa quem eh x ou bola, ele preenche
            turnoJogo=0;
            cout <<"\nRodada:" << rodada << "\n";
            desenhaTabuleiro(tabuleiro);
            mapaPosicoes(); ///desenho as posicoes
          }
          rodada++;
      }
      ///POSSIBILIDADE 4 :VEZ DA MAQUINA, comeca e a difucldade eh media
      if (turnoJogo==0 && dificuldade==2){
        while (tabuleiro[posicoes[nivelMedio-1][0]][posicoes[nivelMedio-1][1]] != '-'){
          nivelMedio=rand()%9 + 1;
        }
        linhaJogada = posicoes[nivelMedio-1][0]; ///linha e coluna de acordo com a posicao jogada
        colunaJogada = posicoes[nivelMedio-1][1];
        tabuleiro[linhaJogada][colunaJogada]=maquina;
        cout <<"\n"<<linhaJogada <<colunaJogada;
        turnoJogo=1;
        limpaTela();
        cout <<"\nRodada:" << rodada << "\n";
        desenhaTabuleiro(tabuleiro);
        mapaPosicoes(); ///desenho as posicoes
        rodada++;
      }
    ///fim possibilidade 4
    //POSSOBILIDADE 5: VEZ DO USUARIO E NIVEL DIFICIL
      if (turnoJogo==1 && dificuldade==3){
        cout<<"\nDigite uma posicao: \n";
        cin>>posicaoJogada;
        linhaJogada = posicoes[posicaoJogada-1][0]; ///linha e coluna de acordo com a posicao jogada
        colunaJogada = posicoes[posicaoJogada-1][1];
        ////verifica se o espaco esta vazio
        if(tabuleiro[linhaJogada][colunaJogada] == '-' || tabuleiro[linhaJogada][colunaJogada] == maquina ){
          ///jogada do usuario
          tabuleiro[linhaJogada][colunaJogada]=usuario; //n importa quem eh x ou bola, ele preenche
          turnoJogo=0;
          cout <<"\nRodada:" << rodada << "\n";
          desenhaTabuleiro(tabuleiro);
          mapaPosicoes(); ///desenho as posicoes
          //teste
          posicionouJogada=true;
        }
        rodada++;
      }
    ///possibilidade 6 e ultima: VEZ DA MAQUINA, NO DIFICIL
      if (turnoJogo==0 && dificuldade==3){

        if (posicionouJogada==false){
          nivelDificil=rand()%9+1;
          linhaJogada = posicoes[nivelDificil-1][0]; ///linha e coluna de acordo com a posicao jogada
          colunaJogada = posicoes[nivelDificil-1][1];
          tabuleiro[linhaJogada][colunaJogada]=maquina;
          cout <<"\n"<<linhaJogada <<colunaJogada;
          turnoJogo=1;
          posicionouJogada=true;
        continue;
        }

        ///aqui comeco o teste da possibilidade 1 de maquina dificil
        if (posicaoJogada==1){
          nivelDificil=rand()%5;
          while (tabuleiro[posicoes[nivelDificil-1][0]][posicoes[nivelDificil-1][1]] != '-'|| nivelDificil==3){
            nivelDificil=rand()%5 + 1;
          }
          linhaJogada = posicoes[nivelDificil-1][0]; ///linha e coluna de acordo com a posicao jogada
          colunaJogada = posicoes[nivelDificil-1][1];
          tabuleiro[linhaJogada][colunaJogada]=maquina;
          cout <<"\n"<<linhaJogada <<colunaJogada;
          turnoJogo=1;
          limpaTela();
          cout <<"\nRodada:" << rodada << "\n";
          desenhaTabuleiro(tabuleiro);
          mapaPosicoes(); ///desenho as posicoes
        }else if(posicaoJogada==2){
           nivelDificil=rand()%5;
          while (tabuleiro[posicoes[nivelDificil-1][0]][posicoes[nivelDificil-1][1]] != '-' || nivelDificil==4){
            nivelDificil=rand()%6 + 1;
          }
          linhaJogada = posicoes[nivelDificil-1][0]; ///linha e coluna de acordo com a posicao jogada
          colunaJogada = posicoes[nivelDificil-1][1];
          tabuleiro[linhaJogada][colunaJogada]=maquina;
          cout <<"\n"<<linhaJogada <<colunaJogada;
          turnoJogo=1;
          limpaTela();
          cout <<"\nRodada:" << rodada << "\n";
          desenhaTabuleiro(tabuleiro);
          mapaPosicoes(); ///desenho as posicoes
        }else if(posicaoJogada==3){
          nivelDificil=rand()%6;
          while (tabuleiro[posicoes[nivelDificil-1][0]][posicoes[nivelDificil-1][1]] != '-' || nivelDificil==1 || nivelDificil==4){
            nivelDificil=rand()%6 + 1;
          }
          linhaJogada = posicoes[nivelDificil-1][0]; ///linha e coluna de acordo com a posicao jogada
          colunaJogada = posicoes[nivelDificil-1][1];
          tabuleiro[linhaJogada][colunaJogada]=maquina;
          cout <<"\n"<<linhaJogada <<colunaJogada;
          turnoJogo=1;
          limpaTela();
          cout <<"\nRodada:" << rodada << "\n";
          desenhaTabuleiro(tabuleiro);
          mapaPosicoes(); ///desenho as posicoes
        }else if(posicaoJogada==4){
          nivelDificil=rand()%7;
          while (tabuleiro[posicoes[nivelDificil-1][0]][posicoes[nivelDificil-1][1]] != '-' || nivelDificil==2 || nivelDificil==6||nivelDificil==3){
            nivelDificil=rand()%7 + 1;
          }
          linhaJogada = posicoes[nivelDificil-1][0]; ///linha e coluna de acordo com a posicao jogada
          colunaJogada = posicoes[nivelDificil-1][1];
          tabuleiro[linhaJogada][colunaJogada]=maquina;
          cout <<"\n"<<linhaJogada <<colunaJogada;
          turnoJogo=1;
          limpaTela();
          cout <<"\nRodada:" << rodada << "\n";
          desenhaTabuleiro(tabuleiro);
          mapaPosicoes(); ///desenho as posicoes
        }else if(posicaoJogada==5){
          nivelDificil=rand()%9;
          while (tabuleiro[posicoes[nivelDificil-1][0]][posicoes[nivelDificil-1][1]] != '-'){
            nivelDificil=rand()%9 + 1;
          }
          linhaJogada = posicoes[nivelDificil-1][0]; ///linha e coluna de acordo com a posicao jogada
          colunaJogada = posicoes[nivelDificil-1][1];
          tabuleiro[linhaJogada][colunaJogada]=maquina;
          cout <<"\n"<<linhaJogada <<colunaJogada;
          turnoJogo=1;
          limpaTela();
          cout <<"\nRodada:" << rodada << "\n";
          desenhaTabuleiro(tabuleiro);
          mapaPosicoes(); ///desenho as posicoes
        }else if(posicaoJogada==6){
          nivelDificil=rand()%9;
          while (tabuleiro[posicoes[nivelDificil-1][0]][posicoes[nivelDificil-1][1]] != '-'||nivelDificil==7||nivelDificil==2||nivelDificil==8||nivelDificil==4||nivelDificil==1){
            nivelDificil=rand()%9 + 1;
          }
          linhaJogada = posicoes[nivelDificil-1][0]; ///linha e coluna de acordo com a posicao jogada
          colunaJogada = posicoes[nivelDificil-1][1];
          tabuleiro[linhaJogada][colunaJogada]=maquina;
          cout <<"\n"<<linhaJogada <<colunaJogada;
          turnoJogo=1;
          limpaTela();
          cout <<"\nRodada:" << rodada << "\n";
          desenhaTabuleiro(tabuleiro);
          mapaPosicoes(); ///desenho as posicoes
        }else if(posicaoJogada==7){
          nivelDificil=rand()%8;
          while (tabuleiro[posicoes[nivelDificil-1][0]][posicoes[nivelDificil-1][1]] != '-'||nivelDificil==1||nivelDificil==2||nivelDificil==3||nivelDificil==6){
            nivelDificil=rand()%8 + 1;
          }
          linhaJogada = posicoes[nivelDificil-1][0]; ///linha e coluna de acordo com a posicao jogada
          colunaJogada = posicoes[nivelDificil-1][1];
          tabuleiro[linhaJogada][colunaJogada]=maquina;
          cout <<"\n"<<linhaJogada <<colunaJogada;
          turnoJogo=1;
          limpaTela();
          cout <<"\nRodada:" << rodada << "\n";
          desenhaTabuleiro(tabuleiro);
          mapaPosicoes(); ///desenho as posicoes
        }else if(posicaoJogada==8){
          nivelDificil=rand()%9;
          while (tabuleiro[posicoes[nivelDificil-1][0]][posicoes[nivelDificil-1][1]] != '-'||nivelDificil==4||nivelDificil==6||nivelDificil==1||nivelDificil==2||nivelDificil==3){
            nivelDificil=rand()%9 + 1;
          }
          linhaJogada = posicoes[nivelDificil-1][0]; ///linha e coluna de acordo com a posicao jogada
          colunaJogada = posicoes[nivelDificil-1][1];
          tabuleiro[linhaJogada][colunaJogada]=maquina;
          cout <<"\n"<<linhaJogada <<colunaJogada;
          turnoJogo=1;
          limpaTela();
          cout <<"\nRodada:" << rodada << "\n";
          desenhaTabuleiro(tabuleiro);
          mapaPosicoes(); ///desenho as posicoes
        }else if(posicaoJogada==9){
          nivelDificil=rand()%8;
          while (tabuleiro[posicoes[nivelDificil-1][0]][posicoes[nivelDificil-1][1]] != '-'||nivelDificil==7||nivelDificil==4||nivelDificil==1||nivelDificil==2||nivelDificil==3){
            nivelDificil=rand()%8 + 1;
          }
          linhaJogada = posicoes[nivelDificil-1][0]; ///linha e coluna de acordo com a posicao jogada
          colunaJogada = posicoes[nivelDificil-1][1];
          tabuleiro[linhaJogada][colunaJogada]=maquina;
          cout <<"\n"<<linhaJogada <<colunaJogada;
          turnoJogo=1;
          limpaTela();
          cout <<"\nRodada:" << rodada << "\n";
          desenhaTabuleiro(tabuleiro);
          mapaPosicoes(); ///desenho as posicoes
        }
        rodada++;
      }//fecha a parte do dificil

        if (confereTabuleiro((tabuleiro))==1){
            cout <<"\n" <<"O jogador X venceu"<<"\n";
            estadoJogo = 0;
        }else if(confereTabuleiro(tabuleiro) == 2){
            cout <<"\n"<< "O jogador O venceu"<<"\n";
            estadoJogo = 0;
        }
        confereEmpate(tabuleiro);

    if (estadoJogo==0) {
      desenhaTabuleiro(tabuleiro);
      cout << "Fim de jogo";
      cout << "\nO que deseja fazer?";
      cout << "\n1-Continuar Jogando";
      cout << "\n2-Menu Inicial";
      cout << "\n3-Sair\n";
      cin >> reiniciar;
      if(reiniciar == 1){
          jogo();
      }else if(reiniciar == 2){
          menuInicial();
      }
    }
  } ///fecha while
}//fehca funcao


  /////funcao informacoes sobre o jogo/////
  void sobreGame(){
    decoracao();
    cout<<"\nJogo desenvolvido por:\n"<<"Marvel.";
    cout<<"\nJogo da velha edicao 2018.";
    decoracao();
  }
  ////funcao que limpa tela e sera muito util////
  void limpaTela(){
    system("CLS");
  }
  ///funcao que define as posicoes do tabuleiro
  void mapaPosicoes(){
    cout << "\nMapa de Posicoes:";
    cout << "\n 7 | 8 | 9";
    cout << "\n 4 | 5 | 6";
    cout << "\n 1 | 2 | 3";
  }
 ///1 = X venceu, 2 = O venceu, 0 = Nada Aconteceu
  int confereTabuleiro(char tabuleiro[3][3]){

      int i, j;
        //Confere linhas
        for(i = 0; i < 3; i++){
          if(tabuleiro[i][0] == 'X' && tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2]){
            return 1;
          }else if(tabuleiro[i][0] == 'O' && tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2]){
             return 2;
          }

        }
        //Confere colua
        for(j = 0; j < 3; j++){
          if(tabuleiro[0][j] == 'X' && tabuleiro[0][j] == tabuleiro[1][j] && tabuleiro[1][j] == tabuleiro[2][j]){
            return 1;
          }else if(tabuleiro[0][j] == 'O' && tabuleiro[0][j] == tabuleiro[1][j] && tabuleiro[1][j] == tabuleiro[2][j]){
            return 2;
          }
        }
        //Diagonal Principal
        if(tabuleiro[0][0] != '-' && tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2]){
          if(tabuleiro[0][0] == 'X'){
            return 1;
          }else{
            return 2;
          }
        }
        //Diagonal Secund�ria
        if(tabuleiro[0][2] != '-' && tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0]){
          if(tabuleiro[0][2] == 'X'){
            return 1;
          }else{
            return 2;
          }
        }


  }
  int confereEmpate(char tabuleiro[3][3]){
      int empate=0;
        ///empate
        //linha 1
        if(((tabuleiro[0][0] && tabuleiro[0][1] && tabuleiro[0][2]) == 'X') || ((tabuleiro[0][0] && tabuleiro[0][1] && tabuleiro[0][2]) == 'O') ){
          empate+=1;
        }
        ///linha 2
        if(((tabuleiro[1][0] && tabuleiro[1][1] && tabuleiro[1][2]) == 'X') || ((tabuleiro[1][0] && tabuleiro[1][1] && tabuleiro[1][2]) == 'O') ){
         empate+=1;
        }
        ///linha 3
        if(((tabuleiro[2][0] && tabuleiro[2][1] && tabuleiro[2][2]) == 'X') || ((tabuleiro[2][0] && tabuleiro[2][1] && tabuleiro[2][2]) == 'O') ){
          empate+=1;
        }
        ///coluna 1
        if(((tabuleiro[0][0] && tabuleiro[1][0] && tabuleiro[2][0]) == 'X') || ((tabuleiro[0][0] && tabuleiro[1][0] && tabuleiro[2][0]) == 'O') ){
          empate+=1;
        }
        ///coluna 2
        if(((tabuleiro[0][1] && tabuleiro[1][1] && tabuleiro[2][1]) == 'X') || ((tabuleiro[0][1] && tabuleiro[1][1] && tabuleiro[2][1]) == 'O') ){
          empate+=1;
        }
        ///coluna 3
        if(((tabuleiro[0][2] && tabuleiro[1][2] && tabuleiro[2][2]) == 'X') || ((tabuleiro[0][2] && tabuleiro[1][2] && tabuleiro[2][2]) == 'O') ){
          empate+=1;
        }
        ///diagonal principal
        if(((tabuleiro[0][0] && tabuleiro[1][1] && tabuleiro[2][2]) == 'X') || ((tabuleiro[0][0] && tabuleiro[1][1] && tabuleiro[2][2]) == 'O') ){
        empate+=1;
        }
        ///diagonal secundaria
         if(((tabuleiro[2][0] && tabuleiro[1][1] && tabuleiro[0][2]) == 'X') || ((tabuleiro[2][0] && tabuleiro[1][1] && tabuleiro[0][2]) == 'O') ){
          empate+=1;
        }
        if (empate=0){
          cout<<"\n"<<"EMPATE";
        }
        //return 0;

  }
