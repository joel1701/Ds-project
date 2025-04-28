
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
            string name; //

}
int main(){
  
    
}