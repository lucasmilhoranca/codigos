#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<conio2.h>

#define TF 10

struct tp_data
{
	int dia, mes, ano;
};

struct tp_prod
{
	int cod, estoque;
	char descr[20];
	float preco;
	struct tp_data dtval;
	
};

int main(void)
{
	struct tp_prod tabprod[TF], auxprod;
	int TL=0, auxcod, i=0, j=0;
	char opc, excl;
	
	do
	{
		clrscr();//system("cls") e include windows.h
		printf("\n * * * M E N U * * * \n");
		textcolor(15);
		printf(" [A] - Registrar Produto\n");
		printf(" [B] - Exibir Produtos\n");
		printf(" [C] - Ordenar Produtos pela Descricao\n");
		printf(" [D] - Excluir Produtos pelo Codigo\n");
		printf(" [ESC] - Sair\n");
		printf("\nOpcao:");
		opc = toupper(getche());
		
		switch(opc)
		{
			case 'A':
				clrscr();
				printf("\n# # # CADASTRO DE PRODUTOS # # #\n");
				textcolor(7);
				printf("\nCodigo do Produto:");
				fflush(stdin);
				scanf("%d",&auxcod);
				while(TL<TF && auxcod>0)
				{
					for(i=0 ; i<TL && auxcod!=tabprod[i].cod ; i++);//i=0; while(i<TL && auxcod!=tabprod[i].cod) i++;
					
					if(i<TL)
					{
						printf("\nProduto ja existe\n");
						printf("\nCOD:%d - Produto:%s - R$%.2f - Estoque:%d\n",tabprod[i].cod, tabprod[i].descr, tabprod[i].preco ,tabprod[i].estoque);
						getch();
					}
					else
					{
						tabprod[TL].cod=auxcod;
						printf("\nDescricao:");
						fflush(stdin);
						gets(tabprod[TL].descr);
						printf("\nQuantidade:");
						scanf("%d",&tabprod[TL].estoque);
						printf("\nPreco R$:");
						scanf("%f",&tabprod[TL].preco);
						printf("\nData de Validade [dd mm aaaa]: ");
						scanf("%d%d%d", &tabprod[TL].dtval.dia, &tabprod[TL].dtval.mes, &tabprod[TL].dtval.ano);
						TL++;
					}
					clrscr();
					printf("\n##CADASTRO DE PRODUTOS##\n");
					textcolor(7);
					printf("\nCodigo do Produto:");
					fflush(stdin);
					scanf("%d",&auxcod);
				}
			break;
			case 'B':
				clrscr();
				printf("\n# # # RELATORIO # # #\n");
				if(TL==0)
					printf("\nVAZIO!");
				else
					for(i=0 ; i<TL ; i++)
						printf("\n %d \t %s \t %d \t R$%.2f \t %d/%d/%d\n",tabprod[i].cod,tabprod[i].descr,tabprod[i].estoque,tabprod[i].preco,tabprod[i].dtval.dia,tabprod[i].dtval.mes,tabprod[i].dtval.ano);
				getch();	
			break;
			case 'C':
				clrscr();
				printf("# # # # # # # # # # # # # # # # # # # # # # \n");
				printf("#                                         # \n");
				printf("#     PRODUTOS ORDENADOS COM SUCESSO!     # \n");
				printf("#                                         # \n");
				printf("# # # # # # # # # # # # # # # # # # # # # # \n");
				for(i=0 ; i<TL-1 ; i++)
				{
					for(j=i+1 ; j<TL ; j++)
					{
						if(stricmp(tabprod[i].descr,tabprod[j].descr)>0)//troca
						{
							auxprod = tabprod[i];
							tabprod[i] = tabprod[j];
							tabprod[j] = auxprod;
						}
					}
				}
				getch();
			break;
			case 'D':
				clrscr();
				if(TL==0)
				{
					printf("\nVAZIO!\n");
					getch();
				}
				else
				{
					clrscr();
					printf("\n # # # EXCLUIR PRODUTO # # # \n");
					printf("\nCodigo do Produto: ");
					scanf("%d",&auxcod);
					while(auxcod>0)
					{
						for(i=0 ; i<TL && auxcod!=tabprod[i].cod ; i++);//i=0; while(i<TL && auxcod!=tabprod[i].cod) i++;
							
						if(i<TL)
						{
							printf("\nPRODUTO ENCONTRADO\n");
							printf("\nCOD:%d - Produto:%s - R$%.2f - Estoque:%d\n",tabprod[i].cod, tabprod[i].descr, tabprod[i].preco ,tabprod[i].estoque);
							printf("\nCONFIRMAR EXCLUSAO?: ");
							if(toupper(getche())=='S')
							{
								for( ; i<TL-1 ; i++)
									tabprod[i] = tabprod[i+1];
								TL--;
								printf("\nEXCLUSAO CONCLUIDA!");
							}
							else
								printf("\nOPERACAO CANCELADA!");
						}
						else
							printf("\nProduto nao encontrado!");
						getch();
						clrscr();
						printf("\n # # # EXCLUIR PRODUTO # # # \n");
						printf("\nCodigo do Produto: ");
						scanf("%d",&auxcod);
					}
				}	
			break;
		}
	}while(opc!=27);
	clrscr();
	printf("# # # # # # # # # # # # # # # # \n");
	printf("#                             # \n");
	printf("#     PROGRAMA ENCERRADO!     # \n");
	printf("#                             # \n");
	printf("# # # # # # # # # # # # # # # # \n");
	
	return 0;
}
