#include<stdio.h>
int main(){
	int days,coin,day,turn;
	days=1;
	coin=0;
	turn=2;
	scanf("%d",&day);
	while(days<=day){
		if((days+turn)>=day){
			coin=coin+turn*(day-days);
			break;
		}else{
			coin=coin+turn*turn;
	    }
		days=days+turn;
		turn++;
	}
	printf("%d天共发%d枚金币",day,coin+1); 
	return 0;
}
