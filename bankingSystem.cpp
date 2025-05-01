#include<iostream>
#include<vector>
#include<string>
using namespace std;

class node{ //node class is used for storing transation history
    public:
            float amount;
            string type;
            node* next;

            node(float amount, string type){
                this->amount=amount; 
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
                cin.ignore();
                getline(cin, name); //used for full name 
                cout<<"Enter the amount of money you want to deposit initially"<<"\n";
                cin>>balance;

            }
          

            void depositMoney(float amount){
                balance=balance+amount;
                node* newNode=new node(amount, "deposit");
                if(head==NULL){
                    head=newNode;
                }
                else{
                    newNode->next=head;
                    head=newNode;
                }

                cout<<"you have deposited"<<amount<<"rupees\n";
            }
            
            void withdrawMoney(float amount){
                if(balance<amount){
                    cout<<"not enough balance"<<"\n";
                    return;
                }
                balance=balance-amount;
                node* newNode=new node(amount, "withdraw");
                if(head==NULL){
                    head=newNode;
                }
                else{
                    newNode->next=head;
                    head=newNode;
                }
                cout<<"you have withdrawn "<<amount<<"rupees\n";
                cout<<"\n";
            }
            void transactionHistory(){
                cout<<"Your transation history is : \n";
                node* temp=head;
                if(temp==NULL){
                    cout<<"you have made no transations"<<"\n"; // list is empty
                }
                while(temp!=NULL){
                    cout<<temp->type<<temp->amount<<"rupees\n";
                    temp=temp->next;
                }
            }
            void displayAccountDetails(){
                cout<<"Your account details are \n";
                cout<<"\nAccount Number :"<<accountNo<<"\n";
                cout<<"Name :"<<name<<"\n";
                cout<<"Balance :"<<balance<<"\n";
            }
           
            int getAccNo(){
                return accountNo;
            }
            void deleteAccount(){
                accountNo=-1;
                name="";
                balance=0;

                while(head!=NULL){ //deleting transaction history
                    node* temp=head;
                    head=head->next;
                    delete temp;
                }
                cout<<"Account has been deleted";
                

            }

};
int main(){
    BankAccount acc;

    int option=0;
    
    char choice;
    
    do{
    
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
            case 6:
                cout<<"Enter Account Number:";
                cin>>accNo;
                if(accNo==acc.getAccNo()){
                    acc.deleteAccount();
                }
                else{
                    cout<<"invalid account details";
                }
                break;
            case 7:
                cout<<"EXITING BANKING SYSTEM\n";
                cout<<"Thank you!";
                break;
            default: 
            cout<<"invalid choice";
            } 
            
            cout << "Do you want to perform another operation? (y/n): ";
        cin >> choice;
    }while (choice=='y' || choice =='Y');

    
   
   return 0; 
}