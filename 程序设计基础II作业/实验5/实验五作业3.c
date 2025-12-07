#include<stdio.h>
int main(){
	int i,num=0;
	int ten(int);
	int sixteen(int);
	int twelve(int);
	for(i=1000;i<=9999;i++){
		if(sixteen(i)==twelve(i)&&twelve(i)==ten(i)){
			printf("%d ",i);
			num++;
		}
	}
	printf("\n¹²ÓÐ%d¸ö",num);
	return 0;
}
int sixteen(int a){
	int sum=0;
	int one,ten,hun,tho;
	one=a%16;
	ten=((a-one)/16)%16;
	hun=((a-one-ten*16)/16/16)%16;
	if(a<4096){
		tho=0;
	}else{
		tho=(a-one-ten*16-hun*16*16)/16/16/16;
	}
	sum=one+ten+hun+tho;
	return sum;
}
int twelve(int a){
	int sum=0;
	int one,ten,hun,tho;
	one=a%12;
	ten=((a-one)/12)%12;
	hun=((a-one-ten*12)/12/12)%12;
	if(a<1728){
		tho=0;
	}else{
		tho=(a-one-ten*12-hun*12*12)/12/12/12;
	}
	sum=one+ten+hun+tho;
	return sum;
}
int ten(int a){
	int sum=0;
	int one,ten,hun,tho;
	one=a%10;
	ten=((a-one)/10)%10;
	hun=((a-one-ten*10)/10/10)%10;
	tho=(a-one-ten*10-hun*100)/1000;
	sum=one+ten+hun+tho;
	return sum;
}
