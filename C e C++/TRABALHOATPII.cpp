#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio2.h>
#include<ctype.h>
#include<windows.h>

#define TF 5

//Estruturas
struct TpData
{
	int dia, mes, ano;
};

struct TpPessoas
{
	char nome[30], email[20], endereco[30], cidade[15], estado[2];
	char CPF[11];
};

struct TpPassagens
{
	int NRPASSAGEM, poltrona, CodVoo;
	char Cpf[11];
	TpData DataCompra; 
};

struct TpCidade
{
	int CODCIDADE;
	char NomeCidade[15], EstCidade[2];
};

struct TpVoo
{
	int CODVOO, NrLugares;
	int CodCidOri, CodCidDes;
	TpData DataVoo;
};


//DECLARAÇÃO FUNÇÕES
void Moldura(int CLI, int LNI, int CLF, int LNF, int corMold, int corFundo);
void MolduraPincipal(void);
char Menu(void);
int BuscaCpf(TpPessoas Pessoa[], int TL, char CPF[11]);
int BuscaCidade(TpCidade Cidade[], int TL, int CodCidade);
int BuscaEstado(char UF[2]);
int BuscaPassagem(TpPassagens Passagem[], int TL, int NrPassagem);
int BuscaVoo(TpVoo Voo[], int TL, int CodVoo);
int ValidaCPF(char CPF[11]);
int ValidaEmail(char EMAIL[]);
int ValidaData(TpData Data);
void OrdenaNome(TpPessoas Pessoa[], int TL);
void OrdenaCidade(TpCidade Cidade[], int TL);
void ExclPessoa(TpPessoas Pessoa[], int &TL);
void ExclCidade(TpCidade Cidade[], int &TL);
void CadPessoa(TpPessoas Pessoa[], int &TL);
void CadCidade(TpCidade Cidade[], int &TL);
void CadPassagem(TpPassagens Passagem[], TpVoo Voo[], int &TL);
void CadVoo(TpVoo Voos[], int &TL, TpCidade Cidades[], int TLC);

//MAIN
int main(void)
{
	struct TpPessoas Pessoas[TF];
	struct TpPassagens Passagens[TF];
	struct TpCidade Cidade[TF];
	struct TpVoo Voos[TF];
	
	return 0;
}

//MÓDULOS
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
	}
	
	for(i=LNI+1 ; i<LNF ; i++)
	{
		gotoxy(CLI,i);
		printf("%c",186);
		gotoxy(CLF,i);
		printf("%c",186);
	}
	textcolor(7);
	textbackground(0);
}

void MolduraPincipal(void)
{
	clrscr();
}

char Menu(void)
{
	clrscr();
	//MolduraPrincipal();
	gotoxy(1,1);
	printf("##########");
	
	return toupper(getch());
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
			return -1;
		return 0;
	}
	else
		return 0;
}

int ValidaEmail(char EMAIL[])
{
	int i;
}

int ValidaData(TpData Data)
{
	if((Data.dia>0 && Data.dia<32) && (Data.mes>0 && Data.mes<13) && (Data.ano>2020 && Data.ano<2030))
		return -1;
	return 0;
}

int BuscaCPF(TpPessoas Pessoa[], int TL, char CPF[11])
{
	int i;
	for(i=0 ; i<TL && strcmp(Pessoa[i].CPF,CPF)!=0 ; i++);
	
	if(i<TL)
		return i;
	return -1;
}

int BuscaCidade(TpCidade Cidade[], int TL, int CodCidade)
{
	int i;
	for(i=0 ; i<TL && Cidade[i].CODCIDADE!=CodCidade ; i++);
	
	if(i<TL)
		return i;
	return -1;
}

int BuscaEstado(char UF[2])
{
	char Estados[27][3]={"AC","AL","AP","AM","BA","CE","DF","ES","GO","MA","MT","MS","MG","PA","PB","PR","PE","PI","RJ","RN","RS","RO","RR","SC","SP","SE","TO"};
	int i;
	
	for(i=0 ; i<27 && stricmp(Estados[i],UF)!=0 ; i++);
	
	if(i<27)
		return i;
	return -1;
}

int BuscaVoo(TpVoo Voo[], int TL, int CodVoo)
{
	int i;
	
	for(i=0 ; i<TL && Voo[i].CODVOO!=CodVoo ; i++);
	
	if(i<TL)
		return i;
	return -1;
}

int BuscaPassagem(TpPassagens Passagem[], int TL, int NrPassagem)
{
	int i;
	for(i=0 ; i<TL && Passagem[i].NRPASSAGEM!=NrPassagem ; i++);
	
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
	char CpfExcl[11];
	
	printf("CPF P/ EXCL:");
	fflush(stdin);
	gets(CpfExcl);
	while(strcmp(CpfExcl,"\0")>0)
	{
		i = BuscaCPF(Pessoa, TL, CpfExcl);
		if(i>-1)
		{
			printf("%s \t %s \t %s \t %s \t %s ", Pessoa[i].CPF, Pessoa[i].nome, Pessoa[i].endereco, Pessoa[i].cidade, Pessoa[i].estado);
			printf("CONFIRMAR EXCLUSAO?(ACAO IRREVERSIVEL)");
			if(toupper(getch())=='S')
			{
				for(; i<TL-1 ; i++)
					Pessoa[i]=Pessoa[i+1];
				TL--;
			}
			else
				printf("Operacao cancelada!");
		}
		else
			printf("Pessoa nao encontrada!");
		printf("CPF P/ EXCL:");
		fflush(stdin);
		gets(CpfExcl); 
	}
}

void ExclCidade(TpCidade Cidade[], int &TL)
{
	int i;
	int CodCidExcl;
	
	printf("CODCID P/ EXCL:");
	scanf("%d", &CodCidExcl);
	while(CodCidExcl>0)
	{
			i = BuscaCidade(Cidade, TL, CodCidExcl);
		if(i>-1)
		{
			printf("%d \t %s \t %s", Cidade[i].CODCIDADE, Cidade[i].NomeCidade, Cidade[i].EstCidade);
			printf("CONFIRMAR EXCLUSAO?(ACAO IRREVERSIVEL)");
			if(toupper(getch())=='S')
			{
				for(; i<TL-1 ; i++)
					Cidade[i] = Cidade[i+1];
				TL--;
			}
			else
				printf("Operacao cancelada!");
		}
		else
			printf("Cidade nao encontrada!");
		printf("CODCID P/ EXCL:");
		scanf("%d", &CodCidExcl);
	}
}

void CadPessoa(TpPessoas Pessoa[], int &TL)
{
	char AuxCPF[11], AuxEMAIL[20], AuxEstado[2];
	int pos, CAD;
	clrscr();
	printf("# # # CADASTRO PESSOA # # #");
	printf("\nCPF:");
	fflush(stdin);
	gets(AuxCPF);
	while(TL<TF && strcmp(AuxCPF,"\0")!=0)
	{
		CAD=-1;
		if(ValidaCPF(AuxCPF)==1)
		{
			pos = BuscaCPF(Pessoa, TL, AuxCPF);
			if(pos == -1)
			{
				strcpy(Pessoa[TL].CPF,AuxCPF);
				printf("\nNome:");
				fflush(stdin);
				gets(Pessoa[TL].nome);
				printf("\nEndereco:");
				fflush(stdin);
				gets(Pessoa[TL].endereco);
				printf("\nCidade:");
				fflush(stdin);
				gets(Pessoa[TL].cidade);
				printf("\nEstado:");
				fflush(stdin);
				gets(AuxEstado);
				while((AuxEstado)!="\0" && BuscaEstado(AuxEstado)==0)
				{
					printf("\nEstado:");
					fflush(stdin);
					gets(AuxEstado);
				}
				strcpy(Pessoa[TL].estado,AuxEstado);
				printf("\nEmail:");
				fflush(stdin);
				gets(AuxEMAIL);
				while(strcmp(AuxEMAIL,"\0")!=0 && CAD<0)
				{
					if(ValidaEmail(AuxEMAIL)==1)
					{
						strcpy(Pessoa[TL].email, AuxEMAIL);
						printf("Cadastro Completo!");
						TL++;
						CAD++;
						OrdenaNome(Pessoa,TL);
					}
					else
					{
						printf("Email ivalido");
						printf("Email\n:");
						gets(AuxEMAIL);
					}		
				}
			}
			else
				printf("Pessoa ja cadastrada!");
		}
		else
			printf("CPF Invalido!");
		printf("\nCPF:");
		fflush(stdin);
		gets(AuxCPF);
	}
	
}

void CadCidade(TpCidade Cidade[], int &TL)
{
	int AuxCod,i, CAD;
	char AuxEstado[2];
	clrscr();
	printf("# # # CADASTRO CIDADE # # #");
	printf("\nCod:");
	scanf("%d",&AuxCod);
	while(TL<TF && AuxCod>0)
	{
		CAD=0;
		if(BuscaCidade(Cidade,TL,AuxCod)==-1)
		{
			printf("\nNome Cid:");
			gets(Cidade[TL].NomeCidade);
			printf("\nEstado(Sigla):");
			gets(AuxEstado);
			while(strcmp(AuxEstado,"\0")!=0 && CAD==0)
			{
				if(BuscaEstado(AuxEstado)>0)
				{
					strcpy(Cidade[TL].EstCidade,AuxEstado);
					TL++;
					CAD++;
				}
				else
				{
					printf("Estado invalido!");
					printf("\nEstado(Sigla):");
					gets(AuxEstado);
				}
			}
		}
		else
			printf("Cidade ja existe!");
		printf("\nCod:");
		scanf("%d",&AuxCod);
	}
}

void CadPassagem(TpPassagens Passagem[], int &TL, TpVoo Voo[], int TLV, TpPessoas Pessoa[], int TLP)
{
	char AuxCPF[11];
}

void CadVoo(TpVoo Voos[], int &TL, TpCidade Cidades[], int TLC)
{
	int CAD, AuxCodVoo, AuxCodCidO, AuxCodCidD, AuxNL;
	TpData AuxData;
	
	clrscr();
	printf("# # # CADASTRO VOO # # #");
	printf("\nCod.Voo:");
	scanf("%d",&AuxCodVoo);
	
	while(TL<TF && AuxCodVoo>0)
	{
		CAD=0;
		if(BuscaVoo(Voos,TL,AuxCodVoo)==-1)
		{
			printf("Data do Voo:");
			scanf("%d %d %d", &AuxData.dia, &AuxData.mes, &AuxData.ano);
			while(AuxData.dia>0 && CAD==0)
			{
				if(ValidaData(AuxData)==-1)
				{
					printf("Cod Cidade de Ori:");
					scanf("%d", &AuxCodCidO);
					while(AuxCodCidO>0 && CAD==0)
					{
						if(BuscaCidade(Cidades,TLC,AuxCodCidO)==-1)
						{
							printf("Cod Cidade de Des:");
							scanf("%d", &AuxCodCidD);
							while(AuxCodCidD>0 && CAD==0)
							{
								if(BuscaCidade(Cidades,TLC,AuxCodCidD)==-1)
								{
									printf("Num de Lugares:");
									scanf("%d",&AuxNL);
									while(AuxNL>0 && CAD==0)
									{
										if(AuxNL<=50)
										{
											Voos[TL].CODVOO = AuxCodVoo;
											Voos[TL].DataVoo = AuxData;
											Voos[TL].NrLugares = AuxNL;
											Voos[TL].CodCidOri = AuxCodCidO;
											Voos[TL].CodCidDes = AuxCodCidD;
											TL++;
											CAD++;
										}
										else
										{
											printf("N de Lugares invalido!\n");
											printf("Num de Lugares:");
											scanf("%d",&AuxNL);
										}
									}
								}
								else
								{
									printf("Cidade n existe!\n");
									printf("Cod Cidade de Des:");
									scanf("%d", &AuxCodCidD);
								}
							}
						}
						else
						{
							printf("Cidade nao existe!\n");
							printf("Cod Cidade de Ori:");
							scanf("%d", &AuxCodCidO);
						}
					}
				}
				else
				{
					printf("Data invalida!\n");
					printf("Data do Voo:");
					scanf("%d %d %d", &AuxData.dia, &AuxData.mes, &AuxData.ano);					
				}
			}	
		}
		else
			printf("Voo ja existe!\n");
		printf("\nCod.Voo:");
		scanf("%d",&AuxCodVoo);
	}
}
