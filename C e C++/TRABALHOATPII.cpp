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
	char nome[30], email[20], endereco[30], cidade[15], estado[3];
	char CPF[12];
};

struct TpPassagens
{
	int NRPASSAGEM, poltrona, CodVoo;
	char Cpf[12];
	TpData DataCompra; 
};

struct TpCidade
{
	int CODCIDADE;
	char NomeCidade[15], EstCidade[3];
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
int BuscaCPF(TpPessoas Pessoa[], int TL, char CPF[11]);
int BuscaCidade(TpCidade Cidade[], int TL, int CodCidade);
int BuscaEstado(char UF[3]);
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
void Executa(void);

//MAIN
int main(void)
{
	Executa();
	
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

void MolduraPrincipal(void)
{
	//Moldura();
}

char Menu(void)
{
	//MolduraPrincipal();
	//gotoxy(1,1);
	printf("[A]-CAD PESSOA\n");
	printf("[B]-CAD CIDADE\n");
	printf("[C]-CAD VOO\n");
	printf("[D]-CAD PASSAGEM\n");
	
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

int BuscaPoltrona(TpPassagens Passagem[], int TL, int NPOL)
{
		
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
		printf("VAZIO!zn");
		getch();
	}
	else
	{
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
}

void ExclCidade(TpCidade Cidade[], int &TL)
{
	int i;
	int CodCidExcl;
	
	if(TL==0)
	{
		printf("VAZIO!\n");
		getch();
	}
	else
	{
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
}

void ExclVoo(TpVoo Voo[], int &TLV, TpPassagens Passagens[], int &TLP)
{
	int i, j, CodVooExcl;
	
	if(TLV==0)
	{
		printf("VAZIO!\n");
		getch();
	}
	else
	{
		printf("COD VOO P/ EXCL:");
		scanf("%d", &CodVooExcl);
		while(CodVooExcl>0)
		{
			i = BuscaVoo(Voo,TLV,CodVooExcl);
			if(i>-1)
			{
				printf("%d \t %d/%d/%d \t Ori:%d /t Des:%d", Voo[i].CODVOO, Voo[i].DataVoo.dia, Voo[i].DataVoo.mes, Voo[i].DataVoo.ano, Voo[i].CodCidOri, Voo[i].CodCidDes);
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
					printf("Operacao cancelada!");
			}
			else
				printf("Voo nao encontrado!\n");
			printf("COD VOO P/ EXCL:");
			scanf("%d", &CodVooExcl);
		}
	}
}

void ExclPassagem(TpPassagens Passagens[], int &TL)
{
	int i, CodPassagem;
	
	if(TL==0)
	{
		printf("VAZIO!");
		getch();
	}
	else
	{
		printf("COD PASSAGEM P/ EXCL:");
		scanf("%d", &CodPassagem);
		while(CodPassagem>999)
		{
			i=BuscaPassagem(Passagens,TL,CodPassagem);
			if(i>-1)
			{
				printf("%d \t %d \t %d \t %d/%d/%d \t %d", Passagens[i].NRPASSAGEM, Passagens[i].CodVoo, Passagens[i].Cpf, Passagens[i].DataCompra.dia, Passagens[i].DataCompra.mes, Passagens[i].DataCompra.ano, Passagens[i].poltrona);
				printf("CONFIRMAR EXCLUSAO?(ACAO IRREVERSIVEL)");
				if(toupper(getch())=='S')
				{
					for(; i<TL-1 ; i++)
						Passagens[i] = Passagens[i+1];
					TL--;
				}
			}
		}
	}
}

void CadPessoa(TpPessoas Pessoa[], int &TL)
{
	char AuxCPF[12], AuxEMAIL[20], AuxEstado[3];
	int pos, CAD;
	clrscr();
	printf("# # # CADASTRO PESSOA # # #");
	printf("\nCPF:");
	fflush(stdin);
	gets(AuxCPF);
	int aux;
	while(TL<TF && strcmp(AuxCPF,"\0")!=0)
	{
		CAD=-1;
		if(ValidaCPF(AuxCPF))
		{
			if(BuscaCPF(Pessoa, TL, AuxCPF)==-1)
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
				while(!BuscaEstado(AuxEstado))
				{
					printf("\nEstado:");
					fflush(stdin);
					gets(AuxEstado);
				}
				strcpy(Pessoa[TL].estado,AuxEstado);				
				printf("\nEmail:");
				fflush(stdin);
				gets(AuxEMAIL);
				while(!ValidaEmail(AuxEMAIL))
				{
					printf("Email invalido\n");
					printf("Email:");
					gets(AuxEMAIL);
				}
				strcpy(Pessoa[TL].email, AuxEMAIL);
				printf("Cadastro Completo!");
				TL++;
				OrdenaNome(Pessoa,TL);		
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
	char AuxEstado[3];
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
			fflush(stdin);
			gets(Cidade[TL].NomeCidade);
			printf("\nEstado(Sigla):");
			fflush(stdin);
			gets(AuxEstado);
			while(!BuscaEstado(AuxEstado))
			{
				printf("\nEstado(Sigla):");
				fflush(stdin);
				gets(AuxEstado);
			}
			Cidade[TL].CODCIDADE = AuxCod;
			strcpy(Cidade[TL].EstCidade,AuxEstado);
			TL++;
		}
		else
			printf("Cidade ja existe!");
		printf("\nCod:");
		scanf("%d",&AuxCod);
	}
}

void CadPassagem(TpPassagens Passagem[], int &TL, TpVoo Voo[], int TLV, TpPessoas Pessoa[], int TLP)
{
	struct TpData AuxDATA;
	char AuxCPF[11];
	int auxNrPa=1000, AuxCODVOO, pos=0;
	
	clrscr();
	printf("### CADASTRO DE PASSAGEM ####");
	printf("\n\nCPF:");
	fflush(stdin);
	gets(AuxCPF);
	while(TL<TF && strcmp(AuxCPF,"\0")!=0)
	{
		if(BuscaCPF(Pessoa, TLP, AuxCPF)>-1)
		{
			printf("Cod. VOO:");
			scanf("%d", &AuxCODVOO);
			while(AuxCODVOO==0 || BuscaVoo(Voo, TLV, AuxCODVOO)>-1)
			{
				printf("Voo nao encontrado");
				printf("\nCod. VOO:");
				scanf("%d", &AuxCODVOO);
			}
			printf("Data Compra:");
			scanf("%d %d %d", &AuxDATA.dia, &AuxDATA.mes, &AuxDATA.ano);
			while(AuxDATA.dia<=0 || !ValidaData(AuxDATA))
			{
				printf("Data invalida!");
				printf("Data Compra:");
				scanf("%d %d %d", &AuxDATA.dia, &AuxDATA.mes, &AuxDATA.ano);
			}	
		}
		else
			printf("CPF nao encontrado!");
		printf("\n\nCPF:");
		gets(AuxCPF);
	}
}

void CadVoo(TpVoo Voos[], int &TL, TpCidade Cidades[], int TLC)
{
	int CAD=-1, AuxCodVoo, AuxCodCidO, AuxCodCidD, AuxNL;
	TpData AuxData;
	
	clrscr();
	printf("# # # CADASTRO VOO # # #");
	printf("\nCod.Voo:");
	scanf("%d",&AuxCodVoo);
	
	while(TL<TF && AuxCodVoo>0)
	{
		CAD=-1;
		if(BuscaVoo(Voos,TL,AuxCodVoo)==-1)
		{
			printf("Data do Voo:");
			scanf("%d %d %d", &AuxData.dia, &AuxData.mes, &AuxData.ano);
			while(AuxData.dia>0 && CAD<0)
			{
				if(ValidaData(AuxData))
				{
					printf("Cod Cidade de Ori:");
					scanf("%d", &AuxCodCidO);
					while(BuscaCidade(Cidades,TLC,AuxCodCidO)==-1)
					{
						printf("Cidade n existe!\n");
						printf("Cod Cidade de Ori:");
						scanf("%d", &AuxCodCidO);
					}
					printf("Cod Cidade de Des:");
					scanf("%d", &AuxCodCidD);
					while(BuscaCidade(Cidades,TLC,AuxCodCidD)==-1)
					{
						printf("Cidade n existe!\n");
						printf("Cod Cidade de Des:");
						scanf("%d", &AuxCodCidD);
					}
					printf("Num de Lugares:");
					scanf("%d",&AuxNL);
					while(AuxNL>50 || AuxNL<0)
					{
						printf("N de Lugares invalido!\n");
						printf("Num de Lugares:");
						scanf("%d",&AuxNL);
					}
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

void Executa(void)
{
	struct TpPessoas Pessoas[TF]; int TLPE=0;
	struct TpPassagens Passagens[TF]; int TLPA=0;
	struct TpCidade Cidade[TF]; int TLC=0;
	struct TpVoo Voos[TF]; int TLV=0;
	
	char opc;
	
	Passagens[0].NRPASSAGEM=1000;
	
	do
	{
		opc = Menu();
		
		switch(opc)
		{
			case 'A':
				CadPessoa(Pessoas, TLPE);
			break;
			case 'B':
				CadCidade(Cidade, TLC);
			break;
			case 'C':
				CadVoo(Voos, TLV, Cidade, TLC);
			break;
			case 'D':
				CadPassagem(Passagens, TLPA, Voos, TLV, Pessoas, TLPE);
			break;				
		}
			
	}while(opc!=27);
}
