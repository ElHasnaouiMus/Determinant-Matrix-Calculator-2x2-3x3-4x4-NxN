#include <stdio.h>
#include <stdlib.h>
#include<math.h>
//déclaration des fonctions  :
int det2(int **d);
int **Matrice(int **t,int y,int n);
int det(int **m,int n);
//fonction principal  :
int main()
{	int n,i,j;
	do{
		printf("saisir l'ordre de n>=2  :  ");
		scanf("%d",&n);
	}while(n<2);
	int **t;
	t=malloc(n*sizeof(int));
	for( i=0;i<n;i++){
	t[i]=malloc(n*sizeof(int));}
	printf("saisir la matrice ligne par ligne  : \n");
	for( i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("saisir t[%d][%d] : ",i,j);
			scanf("%d",&t[i][j]);
		}}
	printf("la matrice est : \n\n");
	for( i=0;i<n;i++){
		printf("\t|");
		for(j=0;j<n;j++){
			printf("  %3d  ",t[i][j]);
		}
		printf("|\n");
	}
	printf("\n\tle determinant est :  %d",det(t,n));
return 0;}
//définitions des fonctions  :
int det2(int **d){
	return((d[0][0]*d[1][1])-(d[0][1]*d[1][0]));
}
int **Matrice(int **t,int y,int n){
	int **s,i,j;
	s=malloc((n-1)*sizeof(int));
	for( i=0;i<n;i++){
	s[i]=malloc((n-1)*sizeof(int));}
					for( j=0;j<n-1;j++){
						if(j>=y){
							for( i=0;i<n-1;i++){
					s[i][j]=t[i][j+1];
							}}else {
						for( i=0;i<n-1;i++){
							s[i][j]=t[i][j];	
					
							}}}
return (s);}
int det(int **m,int n){
	int l,j,s[n];
	if(n==2){
	return det2(m);}
	else{
		for( j=0;j<n;j++){
		s[j]=m[n-1][j]*det(Matrice(m, j, n),n-1);}
		l=0;
		for( j=0;j<n;j++){
		l=l+pow((-1),(n+j+1))*s[j];}
		return l;
	}}