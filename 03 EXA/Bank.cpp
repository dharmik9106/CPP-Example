#include<iostream>
#include<string>
using namespace std;

class BankAccount{
    private:
    string Accountholdername ;
    int accountnumber;
    double belance = 500000;

    public:
    void deposite(double amt){
        if(amt>0)
        {
            belance += amt;
            cout << "Deposited succesfully...!" << endl;
        }else{
            cout << "Invalid deposit amount!" << endl;
        }
    }
    double getBelance(){
        return belance;
    }
    void withdrawal(double amt){
        if(amt<=belance)
        {
            belance -= amt;
            cout << "withdrawal succesfully...!" << endl;
        }else{
            cout << "Insufficient Balance!" << endl;
        }
    }
    void Displayinfo(){
        cout << "*************Account Information*************" << endl;
        cout << "Account number: " << accountnumber << endl;
        cout << "Account Holder Name: " << Accountholdername << endl;
        cout << "Your Balance is: " << belance << endl;
    }
    void setAccountDetails(long long int acNo, string name ,double bal) {
        accountnumber = acNo;
        Accountholdername = name;
        belance = (bal >= 0)?bal : 0;
    }
    
};

class SavingsAccount : public BankAccount {
public:
    double Interestrate;

    void CalculateInterest() {
        double Interest = getBelance() * Interestrate / 100;
        cout << "Total simple Interest is : " << Interest << endl;
    }
};

class CheckingAccount : public BankAccount {
public:
    double OverdraftLimit;

    void checkOverdraft(double amount) {
        if (amount > getBelance() + OverdraftLimit)
            cout << "Amount exceeds overdraft limit....!!!" << endl;
        else
            cout << "Overdraft OK. Proceeding with withdrawal." << endl;
        }
};


class FixedDepositeAccount : public BankAccount{
    public:

    void calculateInterest(int time){
        float rate = 8.5;
        cout << "Fixed Deposite Interest: " << (getBelance()* rate * time) / (12 * 100) << endl;
    }
};

int main(){

     SavingsAccount san;
    san.setAccountDetails(9227101532, "aviraj", 5000);
    san.Interestrate = 9.53;

    CheckingAccount dha;
    dha.setAccountDetails(8508083535, "vivek", 200000);

    FixedDepositeAccount fda;
    fda.setAccountDetails(7984817007, "prince", 25000);


    int choice = -1, in = -1, amount;

    while (choice != 0) {
        cout << "************Bank System***************" << endl;
        cout << "Enter 1 to access Saving Account" << endl;
        cout << "Enter 2 to access Checking Account" << endl;
        cout << "Enter 3 to access Fixed Deposite Account" << endl;
        cout << "Enter 0 to exit" << endl;
        cout << "*****************************************" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if(choice == 1){

            while(in != 0){

                cout << "******************************" << endl;
                cout << "Enter 1 to check balance" << endl;
                cout << "Enter 2 to withdraw" << endl;
                cout << "Enter 3 to deposit" << endl;
                cout << "Enter 4 to calculate Fixed interest" << endl;
                cout << "Enter 5 to see profile" << endl;
                cout << "*****************************" << endl;
                cout << "Enter your choice: ";
                cin >> in;
                switch (in) {
                    case 1:
                        cout << "Your Balance: " << san.getBelance() << endl;
                        break;
                    case 2:
                        cout << "Enter Amount: ";
                        cin >> amount;
                        san.withdrawal(amount);
                        break;
                    case 3:
                        cout << "Enter Amount: ";
                        cin >> amount;
                        san.deposite(amount);
                        break;
                    case 4:
                        san.CalculateInterest();
                        break;
                    case 5:
                        san.Displayinfo();
                        break;
                    default:
                        cout << "Invalid choice...!" << endl;
                }
            }
            in = -1;
        }
        else if(choice == 2){

            while(in != 0){

                cout << "*********************" << endl;
                cout << endl;
                cout << "Enter 1 to check balance" << endl;
                cout << "Enter 2 to withdraw" << endl;
                cout << "Enter 3 to deposit" << endl;
                cout << "Enter 4 to see profile" << endl;
                cout << "************************" << endl;
                cout << "Enter your choice: ";
                cin >> in;
                
                switch (in) {
                    case 1:
                        cout << "Your Belance: " << dha.getBelance() << endl;
                        break;
                    case 2:
                        cout << "Enter Amount: ";
                        cin >> amount;
                        dha.checkOverdraft(amount);
                        break;
                    case 3:
                        cout << "Enter Amount: ";
                        cin >> amount;
                        dha.deposite(amount);
                        break;
                    case 4:
                        dha.Displayinfo();
                        break;
                    default:
                           cout << "Invalid choice...!" << endl;
                }
            }
            in = -1;
        }
        else if(choice == 3){

            while(in != 0){

                cout << "*****************************" << endl;
                cout << endl;
                cout << "Enter 1 to check balance" << endl;
                cout << "Enter 2 to withdraw" << endl;
                cout << "Enter 3 to deposit" << endl;
                cout << "Enter 4 to calculate interest" << endl;
                cout << "Enter 5 to see profile" << endl;
                cout << "***************************" << endl;
                cout << "Enter your choice: ";
                cin >> in;
                
                switch (in) {
                    case 1:
                        cout << "Your Belance: " << fda.getBelance() << endl;
                        break;
                    case 2:
                        cout << "Enter Amount: ";
                        cin >> amount;
                        fda.withdrawal(amount);
                        break;
                    case 3:
                        cout << "Enter Amount: ";
                        cin >> amount;
                        fda.deposite(amount);
                        break;
                    case 4:
                        int time;
                        cout << "Enter time (in months): ";
                        cin >> time;
                        fda.calculateInterest(time);
                        break;
                    case 5:
                        fda.Displayinfo();
                        break;
                    default:
                           cout << "Invalid choice...!" << endl;
                }
            }
            in = -1;
        }
        else{
            cout << "Not available...!";
        }
    }
    return 0;
}