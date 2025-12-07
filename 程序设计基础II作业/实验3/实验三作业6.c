#include <stdio.h>

int main() {
    double account=100.0;  
    int years=1;           
    double total_withdrawn=0.0; 
    while(account>0){
        if(years>=2){
            if(account>=10){
                account-=10;
                total_withdrawn+=10;
            }else{
                total_withdrawn+=account;
                account=0;
                break;
            }
        }
        if(account>0){
            account*=1.08;
        }
        years++;
    }
    printf("After %d years, Jack has no money!\n",years-1);
    printf("Jack took out %.2f $ altogether",total_withdrawn);
	return 0;
}

