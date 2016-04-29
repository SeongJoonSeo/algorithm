#include <stdio.h>

void find(int i,int j);

int grid[10][10] = { 
		1,1,1,1,1,1,1,1,1,1,
		1,0,0,0,0,0,0,1,0,1,
		1,0,1,1,1,1,1,0,1,1,
		1,0,1,1,0,1,1,0,1,1,
		1,0,1,1,0,0,0,0,0,1,
		1,0,1,1,0,1,1,1,0,1,
		1,0,0,0,0,1,1,1,0,1,
		1,0,1,1,0,1,1,1,0,1,
		1,0,0,1,0,1,1,1,0,1,
		1,1,1,1,1,1,1,1,1,1
		};

int f[10][10];

_Bool a=0;

void find(int i,int j){
	printf("%d,%d\n",i,j);
	if(i==8&&j==8){		
		printf("FINISHED!\n");
		a=1;
		return;
	}
	//if(grid[i][j]==1 || f[i][j]==1){//wall or already visited.
	//	return;
	//}
	f[i][j]=1;	
	
	//right
	if(j+1<9 && grid[i][j+1]!=1 && f[i][j+1]==0){
		find(i,j+1);
		if(a==0)
			printf("%d,%d\n",i,j);
	}
	
	//left
	if(j-1>=1 && grid[i][j-1]!=1 && f[i][j-1]==0){
		find(i,j-1);
		if(a==0)
			printf("%d,%d\n",i,j);
	}
	//up
	if(i+1<9 && grid[i+1][j]!=1 && f[i+1][j]==0){
		find(i+1,j);
		if(a==0)
			printf("%d,%d\n",i,j);
	}
	//down
	if(i-1>=1 && grid[i-1][j]!=1 && f[i-1][j]==0){
		find(i-1,j);		
		if(a==0)
			printf("%d,%d\n",i,j);
	}	
	return;
}

int main(){	
	find(1,1);	
	return 0;
}