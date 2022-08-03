#include<stdio.h>
#include<string.h>
#define TF 10

int main()
{
	int vCod[TF], vCod_mat[TF], TLA=0, TLD=0, cont=0, auxCod, i, j, k;
	char vAluno[TF][20], vRA[TF][10], auxRA[20], vDisciplina[TF][20],vRA_mat[TF][10];
	float vNota1[TF], vNota2[TF], media;
	//aluno e ra
	printf("\nDigite o RA do aluno:");
	fflush(stdin);
	gets(auxRA);
	while(TLA<TF && strlen(auxRA)>0)
	{
		
		cont=0;
		for( i=0 ; i<TLA && cont==0 ; i++)
		{
			if(strcmp(vRA[i],auxRA)==0)
				cont++;
		}
		if(cont==0)
		{
			strcpy(vRA[TLA],auxRA);
			printf("\nDigite o nome do aluno:");
			fflush(stdin);
			gets(vAluno[TLA]);
			TLA++;
		}
		else
			printf("RA ja cadastrado.\n");
		printf("\nDigite o RA do aluno:");
		fflush(stdin);
		gets(auxRA);
	}
	//disciplina e cod
	printf("\nDigite o codigo da disciplina:");
	fflush(stdin);
	scanf("%d",&auxCod);
	while(TLD<TF && auxCod!=0)
	{
		cont=0;
		for( i=0 ; i<TLD && cont==0 ; i++)
			{	
				if(vCod[i]==auxCod)
					cont++;
			}
		if(cont==0)
		{
			vCod[TLD]=auxCod;
			printf("\nDigite o nome da disciplina:");
			fflush(stdin);
			gets(vDisciplina[TLD]);
			TLD++;
		}
		else
			printf("Disciplina ja cadastrada.\n");
		printf("\nDigite o codigo da disciplina:");
		fflush(stdin);
		scanf("%d",&auxCod);
	}
//	//lançar notas
//	printf("\nDigite o RA para lançar as notas:");
//	fflush(stdin);
//	gets(auxRA);
//	while()
//	{
//		for( i=0,cont=0 ; i<TLA && cont==0 ; i++)
//		{
//			if(strcmp(vRA[i],auxRA)==0)
//					cont++;
//		}
//		if(cont!=0)
//		{
//			printf("\nAluno encontrado:");
//			printf("\nDigite a disciplina:");
//			fflush(stdin);
//			scanf("%d",&auxCod);
//			while ()
//			{
//				for(j=0,cont=0 ; j<TLD && cont==0 ; j++)
//				{
//					if(vCod[i]==auxCod)
//						cont++;
//				}
//				if(cont!=0)
//				{

//				}
//			}
//			
//		}
//	}
	return 0;
}
