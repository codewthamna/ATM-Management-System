#include<iostream>
#include<cstdlib>
using namespace std;
class ATM{
    private:
    int balance;
    int pinCode;
    int success;
    public:
    ATM(int bal ,int pin){
        balance=bal;
        pinCode=pin;
    }

    int getBalance(){
        return balance;
    }
    int withDraw(int amount,int pin){
        if(pin!=pinCode){
            return false;
        }
        if(amount > balance){
            return false;
        }
balance=balance-amount;
return true;
    }

    void deposit(int amount){
        balance=balance+amount;
    }
    int transfer(int amount,ATM &receiver,int pin){
        if(pin!=pinCode){
            return false;
        }
success=withDraw(amount,pin);
if(success){
    receiver.deposit(amount);
    return true;
} else{
    return false;
}
    }
  };
int main(){
    int choice;
    int amount;
    int success;
    char op;
    int pin;
 ATM a1(100000,3333);
 do{
    system("CLS");
 cout<<"\t\tPRESS 1 TO VIEW BALANCE"<<endl;
 cout<<"\t\tPRESS 2 FOR CASH WITHDRAWL"<<endl;
 cout<<"\t\tPRESS 3 FOR CASH DEPOSIT"<<endl;
 cout<<"\t\tPRESS 4 TO TRANSFER MONEY "<<endl;
 cout<<"\t\tPRESS 5 TO EXIT ......"<<endl;
cout<<" \t\tENTER YOU'RE CHOICE"<<endl;
cin>>choice;

switch(choice){
    case 1:
    cout<<"\t\tYOUR BALANCE IS ..."<<a1.getBalance();
    break;

case 2:
cout<<"\t\tYOUE CURRENT  BALANCE IS ..."<<a1.getBalance();
cout<<"\t\tENTER AMOUNT TO WITHDRAW"<<endl;
cin>>amount;
success=a1.withDraw(amount,pin);
if(success){
    cout<<"\t\tSUCCESSFULLY WITHDRAW"<<endl;
} else{
    cout<<"\t\tINSUFFICIANT AMOUNT"<<endl;
} 
break;
case 3:
cout<<"\t\tENTER AMOUNT TO DEPOSIT"<<endl;
cin>>amount;
a1.deposit(amount);
cout<<"\t\tDEPOSIT SUCCESSFULL ........"<<endl;
break;

case 4:
cout<<"\t\t\nEnter amount to transfer..."<<endl;
cin>>amount;
cout<<"\t\t\nEnter PIN"<<endl;
cin>>pin;
success=a1.transfer(amount,a1,3333);
if(success){
    cout<<"\t\t\nTRANSFERED SUCCESSFULLY........"<<endl;
}
else{
    cout<<"\t\t\nINVALID PIN ..."<<endl;
}
case 5:
cout<<"\t\t\n    THANKS FOR USING ATM...."<<endl;
exit(1);
break;
default:
cout<<"\t\t\a  INVALID !!!!!!!!"<<endl;
}
cout<<"\t\t\n Do You Want To Do Another Transaction [Yes/No] :"<<endl;
cin>>op;

} while(op=='y'||op=='Y');
    return 0;
}