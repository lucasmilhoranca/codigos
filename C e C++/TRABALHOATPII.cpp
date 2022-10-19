#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio2.h>
#include<ctype.h>
#include<windows.h>

#define TF 10
#define TFL 10
#define TFC 6

/*APERTAR ESPAÇO EM QUALQUER SEÇÂO PARA PREENCHIMENTO AUTOMATICO
	-SE APERTAR NO MENU PRINCIPAL IRA PREENCHER TODAS AS TABELAS COM 5 ELEMENTOS
	-SE APERTAR NO MENU SELECIONADO IRA PREENCHER APENAS A TABELA ESPECIFICA*/


//Estruturas
struct TpData
{
	int dia, mes, ano;
};

struct TpPessoas
{
	char nome[50], email[50], endereco[50], cidade[50], estado[3];
	char CPF[12];
};

struct TpPassagens
{
	int NRPASSAGEM, poltrona[TFL][TFC], CodVoo;
	char Cpf[12];
	TpData DataCompra; 
};

struct TpCidade
{
	int CODCIDADE;
	char NomeCidade[50], EstCidade[3];
};

struct TpVoo
{
	int CODVOO, NrLugares, NrLuDisp;
	int CodCidOri, CodCidDes;
	TpData DataVoo;
};


//DECLARAÇÃO FUNÇÕES
void PreencheGeral(TpPessoas Pessoa[], int &TLPE, TpCidade Cidade[], int &TLC, TpPassagens Passagem[], int &TLPA, TpVoo Voo[], int &TLV);
void PreenchePessoa(TpPessoas Pessoa[], int &TL);
void PreencheCidade(TpCidade Cidade[], int &TL);
void PreenchePassagem(TpPassagens Passagem[], int &TL);
void PreencheVoo(TpVoo Voos[], int &TL);
void Moldura(int CLI, int LNI, int CLF, int LNF, int corMold, int corFundo);
void MolduraPincipal(void);
char Menu(void);
void MenuModulos(void);
char MenuPe(void);
char MenuCid(void);
char MenuPa(void);
char MenuVoo(void);
void LimpaMenu(void);
void LimpaModulos(void);
void Limpa(void);
int BuscaCPF(TpPessoas Pessoa[], int TL, char CPF[11]);
int BuscaCidade(TpCidade Cidade[], int TL, int CodCidade);
int BuscaEstado(char UF[3]);
int BuscaPassagem(TpPassagens Passagem[], int TL, int NrPassagem);
int BuscaPoltrona(TpPassagens Passagem[], int TL, int Fila, int Colu);
int BuscaVoo(TpVoo Voo[], int TL, int CodVoo);
int ValidaCPF(char CPF[11]);
int ValidaEmail(char EMAIL[]);
int ValidaData(TpData Data);
void OrdenaNome(TpPessoas Pessoa[], int TL);
void OrdenaCidade(TpCidade Cidade[], int TL);
void ExclPessoa(TpPessoas Pessoa[], int &TL);
void ExclCidade(TpCidade Cidade[], int &TL);
void ExclPassagem(TpPassagens Passagem[], int &TL);
void ExclVoo(TpVoo Voo[], int &TLV, TpPassagens Passagens[], int &TLP);
void AlteraPessoa(TpPessoas Pessoa[], int TL);
void AlteraCidade(TpCidade Cidade[], int TL);
void AlteraVoo(TpVoo Voo[], int TLV, TpPassagens Passagem[], int TLPA, TpCidade Cidade[], int TLC);
void Pesquisa(TpPessoas Pessoa[], int TL);
void ExibeNumLu(TpVoo Voos[], int TL);
void CadPessoa(TpPessoas Pessoa[], int &TL);
void CadCidade(TpCidade Cidade[], int &TL);
void CadPassagem(TpPassagens Passagem[], TpVoo Voo[], int &TL);
void CadVoo(TpVoo Voos[], int &TL, TpCidade Cidades[], int TLC);
void Executa(void);

//MAIN
int main(void)
{
	
	Executa();
	
	return 0;
}

//MÓDULOS
void PreencheGeral(TpPessoas Pessoa[], int &TLPE, TpCidade Cidade[], int &TLC, TpPassagens Passagem[], int &TLPA, TpVoo Voo[], int &TLV)
{
	PreenchePessoa(Pessoa,TLPE);
	PreencheCidade(Cidade,TLC);
	PreenchePassagem(Passagem,TLPA);
	PreencheVoo(Voo,TLV);
	gotoxy(54,10);
}

void PreenchePessoa(TpPessoas Pessoa[], int &TL)
{
	strcpy(Pessoa[0].CPF,"47782936810");
	strcpy(Pessoa[0].nome,"Lucas Milhoranca");
	strcpy(Pessoa[0].endereco,"Rua das Dores");
	strcpy(Pessoa[0].cidade,"Presidente Bernardes");
	strcpy(Pessoa[0].estado,"SP");
	strcpy(Pessoa[0].email,"lucas@outlook.com");
	
	strcpy(Pessoa[1].CPF,"48466922806");
	strcpy(Pessoa[1].nome,"Lucas Sas Ortiz");
	strcpy(Pessoa[1].endereco,"Rua dos Magos");
	strcpy(Pessoa[1].cidade,"Santo Anastacio");
	strcpy(Pessoa[1].estado,"SP");
	strcpy(Pessoa[1].email,"lucascampos@gmail.com");
	
	strcpy(Pessoa[2].CPF,"34422141066");
	strcpy(Pessoa[2].nome,"Jubileu Monteiro");
	strcpy(Pessoa[2].endereco,"Rua do Agiota");
	strcpy(Pessoa[2].cidade,"Niteroi");
	strcpy(Pessoa[2].estado,"RJ");
	strcpy(Pessoa[2].email,"jubileu@gmail.com");
	
	strcpy(Pessoa[3].CPF,"79810258003");
	strcpy(Pessoa[3].nome,"Julieta Golcalves");
	strcpy(Pessoa[3].endereco,"Rua Amo Bolos");
	strcpy(Pessoa[3].cidade,"Rio de Janeiro");
	strcpy(Pessoa[3].estado,"RJ");
	strcpy(Pessoa[3].email,"julieta@gmail.com");
	
	strcpy(Pessoa[4].CPF,"11764011066");
	strcpy(Pessoa[4].nome,"Osvaldo Silva");
	strcpy(Pessoa[4].endereco,"Rua Presidente");
	strcpy(Pessoa[4].cidade,"Belo Horizonte");
	strcpy(Pessoa[4].estado,"MG");
	strcpy(Pessoa[4].email,"osvaldo@hotmail.com");
	
	TL+=5;
}

void PreencheCidade(TpCidade Cidade[], int &TL)
{
	Cidade[0].CODCIDADE=1;
	strcpy(Cidade[0].NomeCidade,"Presidente Bernardes");
	strcpy(Cidade[0].EstCidade,"SP");
	
	Cidade[1].CODCIDADE=2;
	strcpy(Cidade[1].NomeCidade,"Santo Anastacio");
	strcpy(Cidade[1].EstCidade,"SP");
	
	Cidade[2].CODCIDADE=3;
	strcpy(Cidade[2].NomeCidade,"Presidente Prudente");
	strcpy(Cidade[2].EstCidade,"SP");
	
	Cidade[3].CODCIDADE=4;
	strcpy(Cidade[3].NomeCidade,"Presidente Venceslau");
	strcpy(Cidade[3].EstCidade,"SP");
	
	Cidade[4].CODCIDADE=5;
	strcpy(Cidade[4].NomeCidade,"Santo Expedito");
	strcpy(Cidade[4].EstCidade,"SP");
	
	TL+=5;
}

void PreenchePassagem(TpPassagens Passagem[], int &TL)
{
	Passagem[0].CodVoo=1;
	strcpy(Passagem[0].Cpf,"47782936810");
	Passagem[0].DataCompra.dia=24;
	Passagem[0].DataCompra.mes=12;
	Passagem[0].DataCompra.ano=2022;
	Passagem[0].NRPASSAGEM=1000;
	Passagem[0].poltrona[0][0]=1;
	
	Passagem[1].CodVoo=2;
	strcpy(Passagem[1].Cpf,"48466922806");
	Passagem[1].DataCompra.dia=25;
	Passagem[1].DataCompra.mes=12;
	Passagem[1].DataCompra.ano=2022;
	Passagem[1].NRPASSAGEM=1001;
	Passagem[1].poltrona[0][1]=1;
	
	Passagem[2].CodVoo=3;
	strcpy(Passagem[2].Cpf,"47782936810");
	Passagem[2].DataCompra.dia=26;
	Passagem[2].DataCompra.mes=12;
	Passagem[2].DataCompra.ano=2022;
	Passagem[2].NRPASSAGEM=1002;
	Passagem[2].poltrona[0][2]=1;
	
	Passagem[3].CodVoo=4;
	strcpy(Passagem[3].Cpf,"48466922806");
	Passagem[3].DataCompra.dia=27;
	Passagem[3].DataCompra.mes=12;
	Passagem[3].DataCompra.ano=2022;
	Passagem[3].NRPASSAGEM=1003;
	Passagem[3].poltrona[0][3]=1;
	
	Passagem[4].CodVoo=5;
	strcpy(Passagem[4].Cpf,"47782936810");
	Passagem[4].DataCompra.dia=28;
	Passagem[4].DataCompra.mes=12;
	Passagem[4].DataCompra.ano=2022;
	Passagem[4].NRPASSAGEM=1004;
	Passagem[4].poltrona[0][4]=1;
	
	TL+=5;
}

void PreencheVoo(TpVoo Voo[], int &TL)
{
	Voo[0].CODVOO=1;
	Voo[0].NrLugares=50;
	Voo[0].NrLuDisp=49;
	Voo[0].CodCidOri=1;
	Voo[0].CodCidDes=2;
	Voo[0].DataVoo.dia=24;
	Voo[0].DataVoo.mes=12;
	Voo[0].DataVoo.ano=2022;
	
	Voo[1].CODVOO=2;
	Voo[1].NrLugares=50;
	Voo[1].NrLuDisp=49;
	Voo[1].CodCidOri=2;
	Voo[1].CodCidDes=1;
	Voo[1].DataVoo.dia=25;
	Voo[1].DataVoo.mes=12;
	Voo[1].DataVoo.ano=2022;
	
	Voo[2].CODVOO=3;
	Voo[2].NrLugares=50;
	Voo[2].NrLuDisp=49;
	Voo[2].CodCidOri=3;
	Voo[2].CodCidDes=4;
	Voo[2].DataVoo.dia=26;
	Voo[2].DataVoo.mes=12;
	Voo[2].DataVoo.ano=2022;
	
	Voo[3].CODVOO=4;
	Voo[3].NrLugares=50;
	Voo[3].NrLuDisp=49;
	Voo[3].CodCidOri=4;
	Voo[3].CodCidDes=3;
	Voo[3].DataVoo.dia=27;
	Voo[3].DataVoo.mes=12;
	Voo[3].DataVoo.ano=2022;
	
	Voo[4].CODVOO=5;
	Voo[4].NrLugares=50;
	Voo[4].NrLuDisp=49;
	Voo[4].CodCidOri=4;
	Voo[4].CodCidDes=5;
	Voo[4].DataVoo.dia=28;
	Voo[4].DataVoo.mes=12;
	Voo[4].DataVoo.ano=2022;
	
	TL+=5;
}

void Moldura(int CLI, int LNI, int CLF, int LNF, int corMold, int corFundo)
{
	int i;
	
	textcolor(corMold); //1..15
	textbackground(corFundo); //1..7
	gotoxy(CLI,LNI);
	printf("%c",201);
	gotoxy(CLI,LNF);
	printf("%c",200);
	gotoxy(CLF,LNI);
	printf("%c",187);
	gotoxy(CLF,LNF);
	printf("%c",188);
	
	for(i=CLI+1 ; i<CLF ; i++)
	{
		gotoxy(i,LNI);
		printf("%c",205);
		gotoxy(i,LNF);
		printf("%c",205);
		//Sleep(1);
	}
	
	for(i=LNI+1 ; i<LNF ; i++)
	{
		gotoxy(CLI,i);
		printf("%c",186);
		gotoxy(CLF,i);
		printf("%c",186);
		//Sleep(1);
	}
	textcolor(7);
	textbackground(0);
}

void MolduraPrincipal(void)
{
	Moldura(1,1,168,43,3,0);
	Moldura(2,2,41,4,3,0);
	Moldura(43,2,84,4,3,0);
	Moldura(86,2,127,4,3,0);
	Moldura(129,2,167,4,3,0);
}

char Menu(void)
{
	MolduraPrincipal();
	gotoxy(19,3);
	printf("PESSOA");
	gotoxy(62,3);;
	printf("CIDADE");
	gotoxy(105,3);
	printf("VOO");
	gotoxy(145,3);
	printf("PASSAGEM");
	
	return toupper(getch());
}

char MenuPe(void)
{
	Moldura(2,5,41,42,3,0);
	gotoxy(15,7);
	printf("[A]-CADASTRO");
	gotoxy(15,9);
	printf("[B]-ALTERACAO");
	gotoxy(15,11);
	printf("[C]-EXCLUSAO");
	gotoxy(15,13);
	printf("[D]-EXIBIR");
	gotoxy(15,15);
	printf("[E]-PESQUISA");
	
	return toupper(getch());
}

char MenuCid(void)
{
	Moldura(2,5,41,42,3,0);
	gotoxy(15,7);
	printf("[A]-CADASTRO");
	gotoxy(15,9);
	printf("[B]-ALTERACAO");
	gotoxy(15,11);
	printf("[C]-EXCLUSAO");
	gotoxy(15,13);
	printf("[D]-EXIBIR");
	
	return toupper(getch());
}

char MenuVoo(void)
{
	Moldura(2,5,41,42,3,0);
	gotoxy(15,7);
	printf("[A]-CADASTRO");
	gotoxy(15,9);
	printf("[B]-EXCLUSAO");
	gotoxy(15,11);
	printf("[C]-EXIBIR");
	gotoxy(15,13);
	printf("[D]-LUGARES DISP");
//	gotoxy(15,17);
//	printf("[F]-POLTRONAS DISP");
	
	return toupper(getch());
}

char MenuPa(void)
{
	Moldura(2,5,41,42,3,0);
	gotoxy(15,7);
	printf("[A]-CADASTRO");
	gotoxy(15,9);
	printf("[B]-EXCLUIR");
	gotoxy(15,11);
	printf("[C]-EXIBIR");
	
	return toupper(getch());
}

void MenuModulos(void)
{
	Moldura(43,5,167,42,3,0);
}

void LimpaMenu(void)
{
	for(int i=2 ; i<168 ; i++)
	{
		for(int j=5 ; j<43 ; j++)
		{
			gotoxy(i,j);
			printf(" ");
		}	
	}	
}

void LimpaModulos(void)
{
	for(int i=42 ; i<168 ; i++)
	{
		for(int j=5 ; j<43 ; j++)
		{
			gotoxy(i,j);
			printf(" ");
		}
	}
}

void Limpa(void)
{
	for(int i=79 ; i<167 ; i++)
	{
		for(int j=11 ; j<42 ; j++)
		{
			gotoxy(i,j);
			printf(" ");
		}
	}
}

int ValidaCPF(char CPF[11])
{
	int vcpf[11], dig1, dig2, i, mult, soma=0, resto;
	
	for(i=0 ; i<11 ; i++)
		vcpf[i] = (CPF[i]-48);
	
	for(i=0, mult=10 ; i<9 ; i++, mult--)
		soma+=vcpf[i]*mult;
		
	resto=soma%11;
	dig1 = 11-resto;
	if(dig1==11 || dig1==10)
		dig1=0;
	if(dig1==vcpf[9])
	{
		soma=0;
		for(i=0, mult=11 ; i<10 ; i++, mult--)
			soma+=vcpf[i]*mult;
		resto=soma%11;
		dig2=11-resto;
		if(dig2==11 || dig2==10)
			dig2=0;
		if(dig2==vcpf[10])
			return 1;
		return 0;
	}
	else
		return 0;
}

int ValidaEmail(char EMAIL[])
{
	int i, j, contArroba=0, contPonto=0, marcaArroba, marcaPonto;
	
	if(strlen(EMAIL)==0 || (EMAIL[0]=='@' && EMAIL[0]=='.'))
		return 0;
	for(i=0 ; i<strlen(EMAIL) ; i++)
	{
		if(EMAIL[i]=='@')
		{
			contArroba++;
			marcaArroba=i;
		}
		if(EMAIL[i]=='.')
		{
			contPonto++;
			marcaPonto=i;
		}
	}
	if((contArroba==1 && contPonto>0) && marcaArroba<marcaPonto)
		return 1;
	return 0;
}

int ValidaData(TpData Data)
{
	if((Data.dia>0 && Data.dia<32) && (Data.mes>0 && Data.mes<13) && (Data.ano>2020 && Data.ano<2030))
		return 1;
	return 0;
}

int BuscaCPF(TpPessoas Pessoa[], int TL, char CPF[11])
{
	int i=0;
	
	while(i<TL && strcmp(Pessoa[i].CPF,CPF)!=0)
		i++;
	if(i<TL)
		return i;
	return -1;	
		
}

int BuscaCidade(TpCidade Cidade[], int TL, int CodCidade)
{
	int i=0;
	
	while(i<TL && Cidade[i].CODCIDADE!=CodCidade)
		i++;
	
	if(i<TL)
		return i;
	return -1;
}

int BuscaEstado(char UF[3])
{
	char Estados[27][3]={"AC","AL","AP","AM","BA","CE","DF","ES","GO","MA","MT","MS","MG","PA","PB","PR","PE","PI","RJ","RN","RS","RO","RR","SC","SP","SE","TO"};
	int i=0;
	
	while(i<27 && stricmp(Estados[i],UF)!=0)
		i++;
	
	if(i<27)
		return 1;
	return 0;
}

int BuscaVoo(TpVoo Voo[], int TL, int CodVoo)
{
	int i=0;
	
	while(i<TL && Voo[i].CODVOO!=CodVoo)
		i++;
	
	if(i<TL)
		return i;
	return -1;
}

int BuscaPoltrona(TpPassagens Passagem[], int TL, int Fila, int Colu)
{
 	if(Passagem[TL].poltrona[Fila][Colu])
 		return 1;
 	return 0;
}

int BuscaPassagem(TpPassagens Passagem[], int TL, int NrPassagem)
{
	int i=0;
	
	while(i<TL && Passagem[i].NRPASSAGEM!=NrPassagem)
		i++;
	
	if(i<TL)
		return i;
	return -1;
}

void OrdenaNome(TpPessoas Pessoa[], int TL)
{
	int i,j;
	struct TpPessoas AuxPessoa;
	
	for(i=0 ; i<TL-1 ; i++)
	{
		for(j=i+1 ; j<TL ; j++)
		{
			if(stricmp(Pessoa[i].nome,Pessoa[j].nome)>0)
			{
				AuxPessoa = Pessoa[i];
				Pessoa[i] = Pessoa[j];
				Pessoa[j] = AuxPessoa;
			}
		}
	}
}

void OrdenaCidade(TpCidade Cidade[], int TL)
{
	int i,j;
	TpCidade AuxCidade;
	
	for(i=0 ; i<TL-1 ; i++)
	{
		for(j=0 ; j<TL ; j++)
		{
			if(stricmp(Cidade[i].NomeCidade,Cidade[j].NomeCidade)>0)
			{
				AuxCidade = Cidade[i];
				Cidade[i] = Cidade[j];
				Cidade[j] = AuxCidade;
			}
		}
	}
}

void ExclPessoa(TpPessoas Pessoa[], int &TL)
{
	int i;
	char CpfExcl[12];
	
	if(TL==0)
	{
		gotoxy(70,11);
		printf("VAZIO!");
		getch();
	}
	else
	{
		gotoxy(70,11);
		printf("CPF P/ EXCL:");
		fflush(stdin);
		gets(CpfExcl);
		while(strcmp(CpfExcl,"\0")>0)
		{
			i = BuscaCPF(Pessoa, TL, CpfExcl);
			if(i>-1)
			{
				gotoxy(70,13);
				printf("%s  %s  %s  %s  %s ", Pessoa[i].CPF, Pessoa[i].nome, Pessoa[i].endereco, Pessoa[i].cidade, Pessoa[i].estado);
				gotoxy(70,15);
				printf("CONFIRMAR EXCLUSAO?(ACAO IRREVERSIVEL)");
				if(toupper(getch())=='S')
				{
					for(; i<TL-1 ; i++)
						Pessoa[i]=Pessoa[i+1];
					TL--;
				}
				else
				{
					Moldura(92,39,120,41,3,0);
					gotoxy(98,40);
					printf("OPERACAO CANCELADA!");
				}
			}
			else
			{
				Moldura(92,39,120,41,3,0);
				gotoxy(98,40);
				printf("PESSOA NAO ENCONTRADA!");
			}
			
			getch();
			Limpa();
			gotoxy(70,11);
			printf("CPF P/ EXCL:");
			fflush(stdin);
			gets(CpfExcl); 
		}
	}	
}

void ExclCidade(TpCidade Cidade[], int &TL)
{
	int i;
	int CodCidExcl;
	
	if(TL==0)
	{
		gotoxy(70,11);
		printf("VAZIO!");
	}
	else
	{
		gotoxy(70,11);
		printf("CODCID P/ EXCL:");
		scanf("%d", &CodCidExcl);
		while(CodCidExcl>0)
		{
			i = BuscaCidade(Cidade, TL, CodCidExcl);
			if(i>-1)
			{
				gotoxy(70,13);
				printf("%d  %s  %s", Cidade[i].CODCIDADE, Cidade[i].NomeCidade, Cidade[i].EstCidade);
				gotoxy(70,15);
				printf("CONFIRMAR EXCLUSAO?(ACAO IRREVERSIVEL)");
				if(toupper(getch())=='S')
				{
					for(; i<TL-1 ; i++)
						Cidade[i] = Cidade[i+1];
					TL--;
				}
				else
				{
					Moldura(92,39,120,41,3,0);
					gotoxy(98,40);
					printf("OPERACAO CANCELADA!");
				}				
			}
			else
			{
				Moldura(92,39,120,41,3,0);
				gotoxy(98,40);
				printf("Cidade nao encontrada!");
			}
			getch();
			Limpa();
			gotoxy(70,11);
			printf("CODCID P/ EXCL:");
			scanf("%d", &CodCidExcl);
		}
	}
	getch();
}

void ExclVoo(TpVoo Voo[], int &TLV, TpPassagens Passagens[], int &TLP)
{
	int i, j, CodVooExcl;
	
	if(TLV==0)
	{
		gotoxy(70,11);
		printf("VAZIO!");
	}
	else
	{
		gotoxy(70,11);
		printf("COD VOO P/ EXCL:");
		scanf("%d", &CodVooExcl);
		while(CodVooExcl>0)
		{
			i = BuscaVoo(Voo,TLV,CodVooExcl);
			if(i>-1)
			{
				gotoxy(70,13);
				printf("%d  %d/%d/%d  Ori:%d  Des:%d", Voo[i].CODVOO, Voo[i].DataVoo.dia, Voo[i].DataVoo.mes, Voo[i].DataVoo.ano, Voo[i].CodCidOri, Voo[i].CodCidDes);
				gotoxy(70,15);
				printf("CONFIRMAR EXCLUSAO?(ACAO IRREVERSIVEL)");
				if(toupper(getch())=='S')
				{
					j = Voo[i].CODVOO;
					for(; i<TLV-1 ; i++)
						Voo[i] = Voo[i+1];
					TLV--;
					for(int k=0 ; k<TLP ; k++)
					{
						if(Passagens[k].CodVoo == j)//procura se a passagem corresponde ao voo excluido
						{
							for(int l=k ; l<TLP-1 ; l++)//exclui a passagem e remaneja as passagens
								Passagens[l] = Passagens[l+1];
							TLP--;
						}
					}			
				}
				else
				{
					Moldura(92,39,120,41,3,0);
					gotoxy(98,40);
					printf("OPERACAO CANCELADA!");
				}
			}
			else
			{
				Moldura(92,39,120,41,3,0);
				gotoxy(98,40);
				printf("VOO NAO ENCONTRADO!");
			}
			getch();
			Limpa();
			gotoxy(70,11);
			printf("COD VOO P/ EXCL:");
			scanf("%d", &CodVooExcl);
		}
	}
	getch();
}

void ExclPassagem(TpPassagens Passagens[], int &TL)
{
	int i, CodPassagem;
	
	if(TL==0)
	{
		gotoxy(70,11);
		printf("VAZIO!");
	}
	else
	{
		gotoxy(70,11);
		printf("COD PASSAGEM P/ EXCL:");
		scanf("%d", &CodPassagem);
		while(CodPassagem>999)
		{
			i=BuscaPassagem(Passagens,TL,CodPassagem);
			if(i>-1)
			{
				gotoxy(70,13);
				printf("%d  %d  %d  %d/%d/%d  %d", Passagens[i].NRPASSAGEM, Passagens[i].CodVoo, Passagens[i].Cpf, Passagens[i].DataCompra.dia, Passagens[i].DataCompra.mes, Passagens[i].DataCompra.ano, Passagens[i].poltrona);
				gotoxy(70,15);
				printf("CONFIRMAR EXCLUSAO?(ACAO IRREVERSIVEL)");
				if(toupper(getch())=='S')
				{
					for(; i<TL-1 ; i++)
						Passagens[i] = Passagens[i+1];
					TL--;
				}
			}
			else
			{
				Moldura(92,39,120,41,3,0);
				gotoxy(98,40);
				printf("PASSAGEM N ENCONTRADA!");
			}
		}
	}
	getch();
}

void AlteraPessoa(TpPessoas Pessoa[], int TL)
{
	int pos;
	char cpf[12], AuxEstado[3], AuxEMAIL[20];
	TpPessoas AuxPessoa;
	
	if(TL==0)
	{
		gotoxy(70,11);
		printf("VAZIO!");
	}
	else
	{
		Moldura(92,7,120,9,3,0);
		gotoxy(93,8);
		printf("### ALTERA CLIENTE ###");
		gotoxy(70,11);
		printf("CPF:");
		fflush(stdin);
		gets(cpf);
		pos = BuscaCPF(Pessoa,TL,cpf);
		if(pos>-1)
		{
			gotoxy(70,13);
			printf("Novo CPF:");
			fflush(stdin);
			gets(AuxPessoa.CPF);
			gotoxy(70,15);
			printf("Novo Nome:");
			fflush(stdin);
			gets(AuxPessoa.nome);
			gotoxy(70,17);
			printf("Novo Endereco:");
			fflush(stdin);
			gets(AuxPessoa.endereco);
			gotoxy(70,19);
			printf("Cidade:");
			fflush(stdin);
			gets(AuxPessoa.cidade);
			gotoxy(70,21);
			printf("Estado:");
			fflush(stdin);
			gets(AuxEstado);
			while(!BuscaEstado(AuxEstado))
			{
				gotoxy(70,21);
				printf("Estado:");
				fflush(stdin);
				gets(AuxEstado);
			}
			strcpy(AuxPessoa.estado,AuxEstado);
			gotoxy(70,23);			
			printf("\nEmail:");
			fflush(stdin);
			gets(AuxEMAIL);
			while(!ValidaEmail(AuxEMAIL))
			{
				gotoxy(70,23);
				printf("Email invalido\n");
				printf("Email:");
				gets(AuxEMAIL);
			}
			strcpy(AuxPessoa.email, AuxEMAIL);
			gotoxy(70,25);
			printf("CONFIRMAR ALTERACAO?(ACAO IRREVERSIVEL)");
			if(toupper(getch())=='S')
				Pessoa[pos] = AuxPessoa;
			else
			{
				Moldura(92,39,120,41,3,0);
				gotoxy(98,40);
				printf("Operacao cancelada!");
			}
		}
		else
		{
			Moldura(92,39,120,41,3,0);
			gotoxy(98,40);
			printf("Cliente nao encontrado!");
		}
	}
	getch();
	Limpa();
}

void AlteraCidade(TpCidade Cidade[], int TL)
{
	int pos, AuxCod;
	char AuxEstado[3];
	TpCidade AuxCidade;
	
	if(TL==0)
	{
		gotoxy(70,11);
		printf("VAZIO!");
	}
	else
	{
		Moldura(92,7,120,9,3,0);
		gotoxy(93,8);
		printf("### ALTERA CLIENTE ###");
		gotoxy(70,11);
		printf("\n\nCOD CID:");
		scanf("%d", &AuxCod);
		pos = BuscaCidade(Cidade,TL,AuxCod);
		if(pos>-1)
		{
			AuxCidade.CODCIDADE = AuxCod;
			gotoxy(70,11);
			printf("Novo Nome:");
			fflush(stdin);
			gets(AuxCidade.NomeCidade);
			gotoxy(70,11);
			printf("Novo Estado:");
			fflush(stdin);
			gets(AuxEstado);
			while(!BuscaEstado(AuxEstado))
			{
				gotoxy(70,11);
				printf("\nEstado(Sigla):");
				fflush(stdin);
				gets(AuxEstado);
			}
			strcpy(AuxCidade.EstCidade,AuxEstado);
			gotoxy(70,11);
			printf("CONFIRMAR ALTERACAO?(ACAO IRREVERSIVEL)");
			if(toupper(getch())=='S')
				Cidade[pos] = AuxCidade;
			else
			{
				Moldura(92,39,120,41,3,0);
				gotoxy(98,40);
				printf("CONFIRMAR ALTERACAO?(ACAO IRREVERSIVEL)");
			}
		}
		else
		{
			Moldura(92,39,120,41,3,0);
			gotoxy(98,40);
			printf("Cidade nao encontrada!");
		}
			
	}
	getch();
	Limpa();
}

//void AlteraVoo(TpVoo Voo[], int TLV, TpPassagens Passagem[], int TLPA, TpCidade Cidade[], int TLC)
//{
//	int AuxCodVoo, pos, i;
//	
//	Moldura(92,7,120,9,3,0);
//	gotoxy(93,8);
//}

void ExibePessoa(TpPessoas Pessoas[],int TL)
{
	for(int i=0, l=11 ; i<TL ; i++,l+=2)
	{
		gotoxy(65,l);
		printf("%s  %s  %s  %s  %s  %s", Pessoas[i].CPF, Pessoas[i].nome, Pessoas[i].endereco, Pessoas[i].cidade, Pessoas[i].estado, Pessoas[i].email);
	}
	getch();
}

void ExibeCidade(TpCidade Cidade[], int TL)
{
	for(int i=0, l=11 ; i<TL ; i++, l+=2)
	{
		gotoxy(65,l);
		printf("%d %s %s", Cidade[i].CODCIDADE, Cidade[i].EstCidade, Cidade[i].NomeCidade);
	}
	getch();
}

void ExibePassagem(TpPassagens Passagem[], int TL)
{
	gotoxy(65,10);
	printf("NUm PASS  CPF  COD VOO  DATA COMPRA");
	for(int i=0, l=11 ; i<TL ; i++, l+=2)
	{
		gotoxy(65,l);
		printf("%d  %s  %d  %d/%d/%d ", Passagem[i].NRPASSAGEM, Passagem[i].Cpf, Passagem[i].CodVoo, Passagem[i].DataCompra.dia, Passagem[i].DataCompra.mes, Passagem[i].DataCompra.ano);	
	}
	getch();
}

void ExibeVoo(TpVoo Voos[], int TL)
{
	for(int i=0, l=11 ; i<TL ; i++, l+=2)
	{
		gotoxy(65,l);
		printf("%d  %d  %d  %d/%d/%d %d %d", Voos[i].CODVOO, Voos[i].CodCidOri, Voos[i].CodCidDes, Voos[i].DataVoo.dia, Voos[i].DataVoo.mes, Voos[i].DataVoo.ano, Voos[i].NrLuDisp, Voos[i].NrLugares);
	}
	getch();
}

void Pesquisa(TpPessoas Pessoa[], int TL)
{
	int i=0,l;
	char pesq[30];
	
	if(TL==0)
	{
		gotoxy(70,11);
		printf("VAZIO!");
	}
	else
	{
		gotoxy(70,11);
		printf("Nome para pesquisa:");
		gets(pesq);
		if(strlen(pesq)>0)
		{
			l=11;
			while(i<TL)
			{
				if(strstr(Pessoa[i].nome,pesq))
				{
					gotoxy(65,l);
					printf("%s  %s  %s  %s  %s  %s", Pessoa[i].CPF, Pessoa[i].nome, Pessoa[i].endereco, Pessoa[i].cidade, Pessoa[i].estado, Pessoa[i].email);
				}
				l+=2;
				i++;
			}
		}
		else
		{
			Moldura(92,39,120,41,3,0);
			gotoxy(98,40);
			printf("OPERACAO CANCELADA!");
		}
	}
	getch();
}

void ExibeNumLu(TpVoo Voos[], int TL)
{
	int AuxCodVoo;
	
	gotoxy(70,11);
	printf("COD VOO:");
	scanf("%d", &AuxCodVoo);
	for(int i=0, l=13 ; i<TL ; i++)
	{
		if(BuscaVoo(Voos,TL,AuxCodVoo)>-1)
		{
			gotoxy(70,l);
			printf("%d / %d", Voos[i].NrLuDisp, Voos[i].NrLugares);
			l+=2;
		}
	}
	getch();
}

//void MapaPoltrona(TpVoo Voos[], int TL)
//{
//	int AuxCodVoo;
//	
//	gotoxy(70,11);
//	printf("COD VOO:");
//	scanf("%d", &AuxCodVoo);
//	pos = BuscaVoo(Voos,TL,AuxCodVoo);
//	if(pos>-1)
//	{
//		for(int i=0 ,l=13 ; i<TFL ; i++)
//		{
//			for(int j=0, c=70 ; i<TFC ; j++, c+=2)
//			{
//				gotoxy(c,l);
//				printf("%d",);
//			}
//		}
//	}
//	
//}

//void ExibePessCid(TpPassagens Passagem[], int TLP)
//{
//	int AuxCodOri, AuxCodDes;
//	
//}

void CadPessoa(TpPessoas Pessoa[], int &TL)
{
	char AuxCPF[12], AuxEMAIL[20], AuxEstado[3];
	int pos, CAD;
	//clrscr();
	Moldura(92,7,120,9,3,0);
	gotoxy(93,8);
	printf("# # # CADASTRO PESSOA # # #");
	gotoxy(70,11);
	printf("CPF.....:");
	fflush(stdin);
	gets(AuxCPF);
	while(TL<TF && strcmp(AuxCPF,"\0")!=0)
	{
		CAD=-1;
		if(ValidaCPF(AuxCPF))
		{
			if(BuscaCPF(Pessoa, TL, AuxCPF)==-1)
			{
				strcpy(Pessoa[TL].CPF,AuxCPF);
				gotoxy(70,13);
				printf("Nome....:");
				fflush(stdin);
				gets(Pessoa[TL].nome);
				while(strlen(Pessoa[TL].nome)==0)
				{
					gotoxy(79,13);
					printf("                               ");
					gotoxy(70,13);
					printf("Nome....:");
					fflush(stdin);
					gets(Pessoa[TL].nome);
				}
				gotoxy(70,15);
				printf("Endereco:");
				fflush(stdin);
				gets(Pessoa[TL].endereco);
				while(strlen(Pessoa[TL].endereco)==0)
				{
					gotoxy(79,15);
					printf("                               ");
					gotoxy(70,15);
					printf("Endereco:");
					fflush(stdin);
					gets(Pessoa[TL].endereco);
				}
				gotoxy(70,17);
				printf("Cidade..:");
				fflush(stdin);
				gets(Pessoa[TL].cidade);
				while(strlen(Pessoa[TL].cidade)==0)
				{
					gotoxy(79,17);
					printf("                               ");
					gotoxy(70,17);
					printf("Cidade..:");
					fflush(stdin);
					gets(Pessoa[TL].cidade);
				}
				gotoxy(70,19);
				printf("Estado..:");
				fflush(stdin);
				gets(AuxEstado);
				while(!BuscaEstado(AuxEstado))
				{
					gotoxy(79,19);
					printf("         ");
					gotoxy(70,19);
					printf("Estado..:");
					fflush(stdin);
					gets(AuxEstado);
				}
				strcpy(Pessoa[TL].estado,AuxEstado);
				gotoxy(70,21);				
				printf("Email...:");
				fflush(stdin);
				gets(AuxEMAIL);
				while(!ValidaEmail(AuxEMAIL))
				{
					gotoxy(79,21);
					printf("                     ");
					gotoxy(70,21);
					printf("Email...:");
					gets(AuxEMAIL);
				}
				strcpy(Pessoa[TL].email, AuxEMAIL);
				Moldura(92,39,120,41,3,0);
				gotoxy(98,40);
				printf("CADASTRO COMPLETO!");
				TL++;
				OrdenaNome(Pessoa,TL);		
			}
			else
			{
				Moldura(92,39,120,41,3,0);
				gotoxy(96,40);
				printf("PESSOA JA CADASTRADA!");
			}
				
		}
		else
		{
			Moldura(92,39,120,41,3,0);
			gotoxy(101,40);
			printf("CPF INVALIDO!");
		}
		getch();
		Limpa();	
		gotoxy(70,11);
		printf("CPF.....:");
		fflush(stdin);
		gets(AuxCPF);
	}
}

void CadCidade(TpCidade Cidade[], int &TL)
{
	int AuxCod,i, CAD;
	char AuxEstado[3];
	//clrscr();
	Moldura(92,7,120,9,3,0);
	gotoxy(93,8);
	printf("# # # CADASTRO CIDADE # # #");
	gotoxy(70,11);
	printf("Cod.....:");
	scanf("%d",&AuxCod);
	while(TL<TF && AuxCod>0)
	{
		CAD=0;
		if(BuscaCidade(Cidade,TL,AuxCod)==-1)
		{
			gotoxy(70,13);
			printf("Nome Cid:");
			fflush(stdin);
			gets(Cidade[TL].NomeCidade);
			while(strlen(Cidade[TL].NomeCidade)==0)
			{
				gotoxy(79,13);
				printf("                                   ");
				gotoxy(70,13);
				printf("Nome Cid:");
				fflush(stdin);
				gets(Cidade[TL].NomeCidade);
			}
			gotoxy(70,15);
			printf("Estado..:");
			fflush(stdin);
			gets(AuxEstado);
			while(!BuscaEstado(AuxEstado))
			{
				gotoxy(79,15);
				printf("          ");
				gotoxy(70,15);
				printf("Estado..:");
				fflush(stdin);
				gets(AuxEstado);
			}
			Cidade[TL].CODCIDADE = AuxCod;
			strcpy(Cidade[TL].EstCidade,AuxEstado);
			TL++;
			Moldura(92,39,120,41,3,0);
			gotoxy(98,40);
			printf("CADASTRO COMPLETO!");
			OrdenaCidade(Cidade,TL);
		}
		else
		{
			Moldura(92,39,120,41,3,0);
			gotoxy(98,40);
			printf("CIDADE JA EXISTE!");
		}
		getch();
		Limpa();	
		gotoxy(70,11);
		printf("COD.....:");
		scanf("%d",&AuxCod);
	}
}

void CadPassagem(TpPassagens Passagem[], int &TL, TpVoo Voo[], int TLV, TpPessoas Pessoa[], int TLP)
{
	struct TpData AuxDATA;
	char AuxCPF[11];
	int auxNrPa=1000, AuxCODVOO, pos, F, C;
	
	//clrscr();
	Moldura(92,7,120,9,3,0);
	gotoxy(94,8);
	printf("## CADASTRO DE PASSAGEM ##");
	gotoxy(70,11);
	printf("CPF.....:");
	fflush(stdin);
	gets(AuxCPF);
	while(TL<TF && strcmp(AuxCPF,"\0")!=0)
	{
		if(BuscaCPF(Pessoa, TLP, AuxCPF)>-1)
		{
			gotoxy(70,13);
			printf("COD VOO.:");
			scanf("%d", &AuxCODVOO);
			pos=BuscaVoo(Voo, TLV, AuxCODVOO);
			if(Voo[pos].NrLuDisp<Voo[pos].NrLugares)
			{
				while(AuxCODVOO==0 || pos==-1)
				{
					gotoxy(70,13);
					printf("COD VOO.:");
					scanf("%d", &AuxCODVOO);
				}
				gotoxy(70,15);
				printf("Data Compra:");
				scanf("%d %d %d", &AuxDATA.dia, &AuxDATA.mes, &AuxDATA.ano);
				while(!ValidaData(AuxDATA))
				{
					gotoxy(81,15);
					printf("                  ");
					gotoxy(70,15);
					printf("Data Compra:");
					scanf("%d %d %d", &AuxDATA.dia, &AuxDATA.mes, &AuxDATA.ano);
				}
				gotoxy(70,17);
				printf("Poltrona(Fila/Corredor):");
				scanf("%d %d", &F, &C);
				while(!BuscaPoltrona(Passagem,TL,F,C))
				{
					gotoxy(85,15);
					printf("           ");
					gotoxy(70,17);
					printf("Poltrona(Fila/Corredor):");
					scanf("%d %d", &F, &C);
				}
				Passagem[TL].CodVoo=AuxCODVOO;
				strcpy(Passagem[TL].Cpf,AuxCPF);
				Passagem[TL].DataCompra = AuxDATA;
				Passagem[TL].poltrona[F][C]=1;
				Passagem[TL].NRPASSAGEM=auxNrPa++;
				Voo[pos].NrLuDisp--;
				TL++;
				Moldura(92,39,120,41,3,0);
				gotoxy(98,40);
				printf("CADASTRO COMPLETO!");
			}
			else
			{
				Moldura(92,39,120,41,3,0);
				gotoxy(98,40);
				printf("VOO LOTADO!");	
			}
		}
		else
		{
			Moldura(92,39,120,41,3,0);
			gotoxy(98,40);
			printf("CPF NAO ENCONTRADO!");
		}
		getch();
		Limpa();
		gotoxy(70,11);
		printf("CPF.....:");
		gets(AuxCPF);
	}
}

void CadVoo(TpVoo Voos[], int &TL, TpCidade Cidades[], int TLC)
{
	int CAD=-1, AuxCodVoo, AuxCodCidO, AuxCodCidD, AuxNL;
	TpData AuxData;
	
	//clrscr();
	Moldura(92,7,120,9,3,0);
	gotoxy(94,8);
	printf("# # # CADASTRO VOO # # #");
	gotoxy(70,11);
	printf("COD VOO.:");
	scanf("%d",&AuxCodVoo);
	
	while(TL<TF && AuxCodVoo>0)
	{
		CAD=-1;
		if(BuscaVoo(Voos,TL,AuxCodVoo)==-1)
		{
			gotoxy(70,13);
			printf("Data Voo:");
			scanf("%d %d %d", &AuxData.dia, &AuxData.mes, &AuxData.ano);
			while(AuxData.dia>0 && CAD<0)
			{
				if(ValidaData(AuxData))
				{
					gotoxy(70,15);
					printf("Cod Cid Ori:");
					scanf("%d", &AuxCodCidO);
					while(BuscaCidade(Cidades,TLC,AuxCodCidO)==-1)
					{
						gotoxy(82,15);
						printf("                         ");
						gotoxy(70,15);
						printf("Cod Cid Ori:");
						scanf("%d", &AuxCodCidO);
					}
					gotoxy(70,17);
					printf("Cod Cid Des:");
					scanf("%d", &AuxCodCidD);
					while(BuscaCidade(Cidades,TLC,AuxCodCidD)==-1)
					{
						gotoxy(82,17);
						printf("                         ");
						gotoxy(70,17);
						printf("Cod Cid Des:");
						scanf("%d", &AuxCodCidD);
					}
					gotoxy(70,19);
					printf("Num Lugares:");
					scanf("%d",&AuxNL);
					while(AuxNL>50 || AuxNL<0)
					{
						gotoxy(82,19);
						printf("                         ");
						gotoxy(70,19);
						printf("Num Lugares:");
						scanf("%d",&AuxNL);
					}
					Voos[TL].CODVOO = AuxCodVoo;
					Voos[TL].DataVoo = AuxData;
					Voos[TL].NrLugares = AuxNL;
					Voos[TL].CodCidOri = AuxCodCidO;
					Voos[TL].CodCidDes = AuxCodCidD;
					Voos[TL].NrLuDisp = AuxNL;
					TL++;
					CAD++;
					Moldura(92,39,120,41,3,0);
					gotoxy(96,40);
					printf("CADASTRO CONCLUIDO!");
				}
				else
				{
					gotoxy(79,13);
					printf("                  ");
					gotoxy(70,13);
					printf("Data Voo:");
					scanf("%d %d %d", &AuxData.dia, &AuxData.mes, &AuxData.ano);					
				}
			}	
		}
		else
		{
			Moldura(92,39,120,41,3,0);
			gotoxy(96,40);
			printf("VOO JA EXISTE!");
		}
		getch();
		Limpa();
		gotoxy(70,11);
		printf("COD VOO:");
		scanf("%d",&AuxCodVoo);
	}
}

void Executa(void)
{
	Sleep(2000);
	struct TpPessoas Pessoas[TF]; int TLPE=0;
	struct TpPassagens Passagens[TF]; int TLPA=0;
	struct TpCidade Cidade[TF]; int TLC=0;
	struct TpVoo Voos[TF]; int TLV=0;
	
	char opc, menu;
	
	for(int TL2=0 ; TL2<TF ; TL2++)
		for(int i=0 ; i<TFL ; i++)
			for(int j=0 ; j<TFC ; j++)
				Passagens[TL2].poltrona[i][j]=0;
	
	do
	{
		opc = Menu();
		
		switch(opc)
		{
			case 'A':
				do
				{
					menu=MenuPe();
					MenuModulos();
					switch(menu)
					{
						case 'A':
							CadPessoa(Pessoas, TLPE);
						break;
						case 'B':
							AlteraPessoa(Pessoas,TLPE);
						break;
						case 'C':
							ExclPessoa(Pessoas,TLPE);
						break;
						case 'D':
							ExibePessoa(Pessoas,TLPE);
						break;
						case 'E':
							Pesquisa(Pessoas,TLPE);
						break;
						case 32:
							PreenchePessoa(Pessoas,TLPE);
						break;
					}
					LimpaModulos();
				}while(menu!=27);
			break;
			case 'B':
				do
				{
					menu=MenuCid();
					MenuModulos();
					switch(menu)
					{
						case 'A':
							CadCidade(Cidade, TLC);
						break;
						case 'B':
							AlteraCidade(Cidade,TLC);
						break;
						case 'C':
							ExclCidade(Cidade,TLC);
						break;
						case 'D':
							ExibeCidade(Cidade,TLC);
						break;
					}
					LimpaModulos();
				}while(menu!=27);
			break;
			case 'C':
				do
				{
					menu=MenuVoo();
					MenuModulos();
					switch(menu)
					{
						case 'A':
							CadVoo(Voos, TLV, Cidade, TLC);
						break;
						case 'B':
							ExclVoo(Voos,TLV,Passagens,TLPA);
						break;
						case 'C':
							ExibeVoo(Voos,TLV);
						break;
						case 'D':
							ExibeNumLu(Voos,TLV);
						break;
					}
					LimpaModulos();
				}while(menu!=27);
			break;
			case 'D':
				do
				{
					menu=MenuPa();
					MenuModulos();
					switch(menu)
					{
						case 'A':
							CadPassagem(Passagens, TLPA, Voos, TLV, Pessoas, TLPE);
						break;
						case 'B':
							ExclPassagem(Passagens,TLPA);
						break;
						case 'C':
							ExibePassagem(Passagens,TLPA);
						break;
					}
					LimpaModulos();
				}while(menu!=27);
			break;
			case 32:
				PreencheGeral(Pessoas,TLPE,Cidade,TLC,Passagens,TLPA,Voos,TLV);
			break;		
		}
		LimpaMenu();
	}while(opc!=27);
}
