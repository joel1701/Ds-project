
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class node{ //node class is used for storing transation history
    public:
            float ammount;
            string type;
            node* next;

            node(float ammount, string type){
                this->ammount=ammount; 
                this->type=type;
                next=NULL;
            }
};

class BankAcc{
    private:
            int accountNo; //account number of user
            string name; // name of the user
            float balance;
            node* head; //head of the linked list that we used to store transaction history
    public:
            BankAcc(){ //constructor for the class BankAcc
                balance=0; 
                head=NULL;

            }

            void MakeAnAccount(){
                cout<<"Enter Account Number"<<"\n";
                cin>>accountNo;
                cout<<"Enter Your Name"<<"\n";
                cin>>name;
                cout<<"Enter the ammount of money you want to deposit initially"<<"\n";
                cin>>balance;

            }

            void 

};
int main(){
  
    
}