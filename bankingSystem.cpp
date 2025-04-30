
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

            void depositMoney(float ammount){
                balance=balance+ammount;
                node* newNode=new node(ammount, "deposit");
                if(head==NULL){
                    head=newNode;
                }
                else{
                    newNode->next=head;
                    head=newNode;
                }

                cout<<"you have deposited"<<ammount<<"rupees\n";
            }
            
            void withdrawMoney(float ammount){
                if(balance<ammount){
                    cout<<"not enough balance"<<"\n";
                    return;
                }
                balance=balance-ammount;
                node* newNode=new node(ammount, "withdraw");
                if(head==NULL){
                    head=newNode;
                }
                else{
                    newNode->next=head;
                    head=newNode;
                }
                cout<<"you have withdrawn"<<ammount<<"rupees\n";
            }
            void transactionHistory(){
                node* temp=head;
                if(temp==NULL){
                    cout<<"you have made no transations"<<"\n"; // list is empty
                }
                while(temp!=NULL){
                    cout<<temp->type<<temp->ammount<<"rupees\n";
                    temp=temp->next;
                }
            }
            void displayAccountDetails(){
                cout<<"\nAccount Number :"<<accountNo<<"\n";
                cout<<"Name :"<<name<<"\n";
                cout<<"Balance :"<<balance<<"\n";
            }


};
int main(){
  
    
}