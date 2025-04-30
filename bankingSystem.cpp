
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class node{ //node class is used for storing transation history
    public:
    cout<<"hi im krishna";
            float ammount;
            string type;
            node* next;

            node(float ammount, string type){
                this->ammount=ammount; 
                this->type=type;
                next=NULL;
            }
};

class BankAccount{
    private:
            int accountNo; //account number of user
            string name; // name of the user
            float balance;
            node* head; //head of the linked list that we used to store transaction history
    public:
            BankAccount(){ //constructor for the class BankAcc
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
            void deleteAccount(){

                
            }
            void getAccNo{
                return accountNo;
            }

};
int main(){
    BankAccount acc;

    int option;
    
    while(option !=8){
        cout<<"MENU"<<"\n"<<"Choose the operation you want to perform\n";
        cout<<"1. Create a new account\n";
        cout<<"2. Deposit money\n";
        cout<<"3. Withdraw money\n";
        cout<<"4. Display account details\n";
        cout<<"5. Show transation history\n";
        cout<<"6. Delete account\n";
        cout<<"7 . EXIT\n";
        
        cin>>option;

        int accNo;
        int amount;

        switch(option){
            case 1:
                acc.MakeAnAccount();
                break;
        }
            case 2:
                cout<<"Enter Account number:";
                cin>>accNo;
                if(accNo==acc.getAccNo()){
                    cout<<"Enter Amount to deposit: ";
                    cin>>amount;
                    acc.depositMoney(amount);
                }
                else{
                    cout<<"invalid account number \n";
                }
                break;
            case 3:
                cout<<"Enter Account Number:";
                cin>>accNo;
                if(accNo==acc.getAccNo()){
                    cout<<"Enter Amount to withdraw:";
                    cin>>amount;
                    acc.withdrawMoney(amount);
                }
                else{
                    cout<<"invalid account number";
                }
                break;
            case 4:
                cout<<"Enter Account Number:";
                cin>>accNo;
                if(accNo==acc.getAccNo()){
                    acc.displayAccountDetails();
                }
                else{
                    cout<<"invalid account number";
                }
                break;
            case 5:
                cout<<"Enter Account Number:";
                cin>>accNo;
                if(accNo==acc.getAccNo()){
                    acc.transactionHistory();
                }
                else{
                    cout<<"invalid account number";
                }
                break;

            
                
    }

    
}