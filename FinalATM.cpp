#include <iostream>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<conio.h>
#include<string>
#include<dos.h>
#include<windows.h>
using namespace std;
int count=2;
void showMenu();
int mainMenuSelection(int);
void welcomeScreen();
double enterAmountScreen(double);

int pin=0, accno;
void notes(int money)
{


    int newmoney=money;
    int r2000,r500,r100,r200;
    r2000=newmoney/2000;
    newmoney=newmoney%2000;
    r500=newmoney/500;
    newmoney=newmoney%500;
    r200=newmoney/200;
    newmoney=newmoney%200;
    r100=newmoney/100;
    newmoney=newmoney%100;
    cout<<"\nRs.2000 : "<<r2000<<"\nRs.500 : "<<r500<<"\nRs. 200 : "<<r200<<"\nRs.100 : "<<r100<<endl;



}
//else
//{
//    cout<<"Enter some Amount"<<endl;
//}



/*---------------------------------------------HASH DATA STRUCTURE--------------------------------------*/
class hashh
{
    static const int tablesize=10;
    struct item
    {
        int pin;
        int accno;
        int balance;
        int curbal;
        item* next;
    };
    item* hashtable[tablesize];
public:
    hashh()
    {
        for(int i=0; i<tablesize; i++)
        {
            hashtable[i]=new item;
            hashtable[i]->pin=0;
            hashtable[i]->accno=0;
            hashtable[i]->balance=0;
            hashtable[i]->curbal=0;
            hashtable[i]->next=NULL;
        }
    }
    int assignindex(int pin)
    {
        int index;
        index=pin%tablesize;
        return index;
    }
    void additem(int pin,int accno,int balance,int curbal)
    {
        int index=assignindex(pin);
        if(hashtable[index]->pin==0)
        {
            hashtable[index]->pin=pin;
            hashtable[index]->accno=accno;
            hashtable[index]->balance=balance;
            hashtable[index]->curbal=curbal;
        }
        else
        {
            item* ptr=hashtable[index];
            item* n=new item;
            n->pin=pin;
            n->accno=accno;
            n->balance=balance;
            n->curbal=curbal;
            n->next=NULL;
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            ptr->next=n;
        }
    }
    int itemsinindex(int index)
    {
        int count=0;
        if(hashtable[index]->pin==0)
        {
            return count;
        }
        else
        {
            count++;
            item* ptr=hashtable[index];
            while(ptr->next!=NULL)
            {
                count++;
                ptr=ptr->next;
            }
        }
        return count;
    }

    void printtable()
    {
        int number;
        for(int i=0; i<tablesize; i++)
        {
            number=itemsinindex(i);
            cout<<"----------------\n";
            cout<<"PIN is :\n"<<hashtable[i]->pin<<endl;
            cout<<"Account Number is :\n"<<hashtable[i]->accno<<endl;
            cout<<"Saving balance is :\n"<<hashtable[i]->balance<<endl;
            cout<<"Current balance is :\n"<<hashtable[i]->curbal<<endl;
            cout<<"Number of Items :"<<number<<endl;
        }
    }
    int finddata(int pin,int accno)
    {
        FILE *f;
        f=fopen("INFO.txt","rb");
        if(f==NULL)
        {
            printf("\nfile opening error in listing :");

            exit(1);
        }
        while(pin!=1)
        {


            int index=assignindex(pin);
            bool foundpin=false;
            int acccno;
            item* ptr=hashtable[index];
            while(ptr!=NULL)
            {
                if(ptr->pin==pin)
                {
                    foundpin=true;
                    acccno=ptr->accno;
                }
                ptr=ptr->next;
            }
            if(foundpin==true && acccno==accno)
            {
                return 1;
            }
            else
            {


                return 0;
            }
        }
    }
    /*-----------------------------------HASH ENDS---------------------------------------*/
    /*-----------------------------------WITHDRAWN----------------------------------------*/

    void netbalancewithdrawal(int pin,int accno,int money)          //SAVING ACCOUNT
    {
        system("cls");

        int index=assignindex(pin);
        bool foundpin=false;
        int acccno;
        int amount=0;
        item* ptr=hashtable[index];
        while(ptr!=NULL)
        {
            if(ptr->pin==pin)
            {
                foundpin=true;
                acccno=ptr->accno;
            }
            ptr=ptr->next;
        }
        if(acccno==accno)
        {
            amount=hashtable[index]->balance;
            if(amount>money)
            {


                amount= amount-money;
                hashtable[index]->balance=amount;
                cout<<"Net Balance for your Saving Account :\n"<<amount<<endl;
                cout<<"Amount of Notes is :\n"<<endl;
                notes(money);

            }
            else
            {
                cout<<"Not Enough Money :(  \n";
                cout<<"Saving A/c Balance is:"<<amount;
            }

        }
    }

    void netbalancewithdrawalcurrent(int pin,int accno,int money)       //CURRENT ACCOUNT
    {
        system("cls");
        int index=assignindex(pin);
        bool foundpin=false;
        int acccno;
        int amount=0;
        item* ptr=hashtable[index];
        while(ptr!=NULL)
        {
            if(ptr->pin==pin)
            {
                foundpin=true;
                acccno=ptr->accno;
            }
            ptr=ptr->next;
        }
        if(acccno==accno)
        {
            amount=hashtable[index]->curbal;
            if(amount>money)
            {
                amount= amount-money;
                cout<<"Net Balance for your Current Account is :\n"<<amount<<endl;
                hashtable[index]->curbal=amount;
            }
            else
            {
                amount=amount-money;
                cout<<"Balance in your Current Account is in Negative"<<amount<<endl;
                hashtable[index]->curbal=amount;
            }
            cout<<endl<<endl;
            cout<<"Amount of Notes is :\n"<<endl;
            notes(money);
        }
    }

    /*--------------------------------------DEPOSIT------------------------------------------------*/

    void netbalancedeposit(int pin,int accno,int money)             //SAVING ACCOUNT
    {
        system("cls");
        int index=assignindex(pin);
        bool foundpin=false;
        int acccno;
        int amount=0;
        item* ptr=hashtable[index];
        while(ptr!=NULL)
        {
            if(ptr->pin==pin)
            {
                foundpin=true;
                acccno=ptr->accno;
            }
            ptr=ptr->next;
        }
        if(acccno==accno)
        {
            amount=hashtable[index]->balance;

            amount= amount+money;
            hashtable[index]->balance=amount;
            cout<<"Net Balance for your Saving Account is :\n"<<amount<<endl;
        }
    }


    void netbalancedepositcurrent(int pin,int accno,int money)          //CURRENT ACCOUNT
    {
        system("cls");
        int index=assignindex(pin);
        bool foundpin=false;
        int acccno;
        int amount=0;
        item* ptr=hashtable[index];
        while(ptr!=NULL)
        {
            if(ptr->pin==pin)
            {
                foundpin=true;
                acccno=ptr->accno;
            }
            ptr=ptr->next;
        }
        if(acccno==accno)
        {
            amount=hashtable[index]->curbal;
            if(1)
            {


                amount= amount+money;
                hashtable[index]->curbal=amount;
                cout<<"Net Balance for your Current Account is :\n"<<amount<<endl;

            }
        }
    }
    //check balance
    void checkbalance(int pin,int accno,int value)
    {
        system("cls");
        int index=assignindex(pin);
        bool foundpin=false;
        int acccno;
        int amount=0;
        item* ptr=hashtable[index];
        while(ptr!=NULL)
        {
            if(ptr->pin==pin)
            {
                foundpin=true;
                acccno=ptr->accno;
            }
            ptr=ptr->next;
        }
        if(acccno==accno)
        {
            if(value == 0)
                amount=hashtable[index]->balance;
            else if(value==1)
                amount=hashtable[index]->curbal;
            cout<<"Balance in your Account is: \n"<<amount<<endl;

        }
    }
    //---------------------------------------TRANSFER--------------------------------//
    void accountnumber(int value)
    {
        int number;
l:
        cout<<endl<<"Enter The Account Number To Transfer Into"<<endl;
        cin>>number;
        int acccno;
        bool foundaccno= false;
        item* ptr= hashtable[0];

        for(int i=0; i<10; i++)
        {
            ptr=hashtable[i];
            if(ptr->accno==number)
            {
                foundaccno=true;
                break;
            }
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
                if(ptr->accno==number)
                {
                    foundaccno=true;
                    acccno=ptr->accno;
                    break;
                }

            }

        }

        if(foundaccno==false)
        {
            cout<<"Account Number not found \n";
            getch();
            goto l;

        }
        if(foundaccno==true)
        {
            int money;
            cout<<"ACCOUNT FOUND ENTER AMOUNT"<<endl;
            cin>>money;
            if(value==1)
            {

                balancewithdrawal( pin, accno,money,1,ptr);
            }

            if(value==0)
            {
                ptr->curbal=ptr->curbal+money;
                cout<<"TRANSACTION SUCCESSFULL";
                balancewithdrawal( pin, accno,money,0,ptr);
            }
        }
    }


    //---------------------------------------TRANSFER FUNCTION-------------------------------------
    void balancewithdrawal(int pin,int accno,int money,int value,item * pt)
    {


        int index=assignindex(pin);
        bool foundpin=false;
        int acccno;
        int amount=0;
        item* ptr=hashtable[index];
        while(ptr!=NULL)
        {
            if(ptr->pin==pin)
            {
                foundpin=true;
                acccno=ptr->accno;
            }
            ptr=ptr->next;
        }
        if(acccno==accno)
        {
            if(value==1)
                amount=hashtable[index]->balance;
            if(value==0)
                amount=hashtable[index]->curbal;
            if(amount>money)
            {
                pt->balance=pt->balance+money;
                cout<<"TRANSACTION SUCCESSFULL";


                if(value==1)
                {
                    cout<<endl<<"BALANCE BEFORE TRANS.:"<<amount<<endl;
                    amount= amount-money;

                    cout<<"Net Balance for your Saving Account :\n"<<amount<<endl;
                    hashtable[index]->balance=amount;
                }

            }
            else
            {
                cout<<"NOT ENOUGHT MONEY"<<endl;
            }
            if(value==0)
            {
                cout<<"BALANCE BEFORE TRANS.:"<<amount<<endl;
                amount= amount-money;
                cout<<"Net Balance for your Current Account :\n"<<amount<<endl;
                hashtable[index]->curbal=amount;
            }

        }
    }
//=================================================================================================================================
};
/*------------------------------------CLASS ENDS-------------------------------------*/
hashh hashy;
int main ()
{
    welcomeScreen();
    system("cls");
    system("color B");

    FILE *f;
    f=fopen("INFO.txt","ab+");
    hashy.additem(1111,1111,25252,1234);
    hashy.additem(1232,22222222,252252,11111);
    hashy.additem(1236,33333333,252552,1111111);
    hashy.additem(1235,44444444,2552,435353);
    hashy.additem(2239,55555555,252,3345435);
    hashy.additem(1238,66666666,2525252,3453443);
    hashy.additem(1237,77777777,52,345544);
    hashy.additem(1230,88888888,2520052,356453);
    hashy.additem(1239,99999999,252052,346346346);
    hashy.additem(1231,12,5252,4363234);
    fwrite(&hashy,sizeof(hashy),1,f);
    fflush(stdin);
    fclose(f);


    int check;
    int choice;
    cout<<endl<<endl;
    cout<<"\t\t\t\t\t**********WELCOME TO ATM*************"<<endl;
passpin:
    cout<<"Enter PIN"<<endl;
    char pass[4];
    for(int i=0; i<4; i++)
    {
        pass[i]=getch();
        cout<<"*";
    }
    getch();
    cout<<endl<<"Enter Account Number:"<<endl;
    cin>>accno;


    pin=atoi(pass);
    check=hashy.finddata(pin,accno);
    if(check!=0)
    {
        showMenu();

    }
    else
    {
        if(count==0)
        {
            system("cls");
            cout<<"CARD BLOCKED!!!TRY AFTER SOMETIME";
            getch();
            exit(0);
        }

        else
        {
            system("cls");
            cout<<"INVALID PIN :: ENTER AGAIN"<<endl;
            count--;
            goto passpin;

        }
    }
    return 0;

}


void showMenu()
{
    system("color D");
    int choice;
m:
    system("cls");
    cout << "\t\t\t\t\t***************  Main Menu Screen  *******************" <<endl;
    cout<<"SELECT YOUR OPTION"<<endl;
    cout << "1) Withdrawal" << endl;
    cout << "2) Deposit" << endl;
    cout << "3) Check Balance" << endl;
    cout << "4) Funds Transfer" << endl;
    cout << "5) Exit ATM" << endl;
    cout << "Enter your choice: ";
    choice=getch();
    choice=int(choice-48);

    if(choice >= 1 && choice <= 5)
    {
        mainMenuSelection(choice);

    }
    else
    {
        cout << endl<<"INVALID INPUT!! ENTER AGAIN";
        getch();
        goto m;
    }



}
mainMenuSelection(int choice)
{
    system("cls");
    int withdraw,
        deposit,
        checkBalance,
        fundsTransfer,
        number;
    double money = 0.0;

    switch (choice)
    {
    case 1:

        cout <<"Withdrawal Screen"<< endl;
        cout << "1) From Current" << endl;
        cout << "2) From Savings" << endl;
        cout << "3) Back to Main Menu" << endl;

        cout << "Enter your withdraw choice: ";
r:
        system("color D");
        withdraw=getch();
        withdraw=int(withdraw-48);


        if (withdraw < 1 || withdraw > 3)
        {
            cout << "INVALID INPUT!! ENTER AGAIN"<<endl;

            goto r;
        }

        switch(withdraw)
        {
        case 1:
            cout<<endl<<"Enter Amount"<<endl;
            cin>>money;
            hashy.netbalancewithdrawalcurrent( pin, accno,money);
            getch();
            system("cls");
            system("cls");
            cout<<"LOADING......................";
            Sleep(2000);
            showMenu();
            break;
        case 2:
            cout<<endl<<"Enter Amount";
            cin>>money;
            hashy.netbalancewithdrawal(pin,accno,money);
            getch();
            system("cls");
            system("cls");
            cout<<"LOADING......................";
            Sleep(2000);
            showMenu();
            break;
        case 3:
            system("cls");
            cout<<"LOADING......................";
            Sleep(2000);
            showMenu();
        default:
            cout << "INVALID INPUT!! ENTER AGAIN"<<endl;
            cin >> withdraw;
            goto r;
            break;

        }
        break;
    case 2:
        system("color 9B");
        cout <<"Deposit Screen"<< endl;
        cout << "1) To Current " << endl;
        cout << "2) To Savings" << endl;
        cout << "3) Back to Main Menu" << endl;
        cout << "Enter your deposit choice: ";
o:
        deposit=getch();
        deposit=int(deposit-48);


        if(deposit < 1 || deposit > 3)
        {
            cout << "INVALID INPUT!! ENTER AGAIN"<<endl;

            goto o;
        }

        switch(deposit)
        {
        case 1:
            cout<<endl<<"Enter Amount";
            cin>>money;
            hashy.netbalancedepositcurrent( pin, accno,money);
            getch();
            system("cls");
            system("cls");
            cout<<"LOADING......................";
            Sleep(2000);
            showMenu();
            break;
        case 2:
            cout<<endl<<"Enter Amount";
            cin>>money;
            hashy.netbalancedeposit(pin,accno,money);
            getch();
            system("cls");
            system("cls");
            cout<<"LOADING......................";
            Sleep(2000);
            showMenu();
            break;
        case 3:
            system("cls");
            cout<<"LOADING......................";
            Sleep(2000);
            showMenu();
            break;
        default:
            cout << "INVALID INPUT!! ENTER AGAIN"<<endl;
            cin >> deposit;
            goto o;
            break;

        }
        break;



    case 3:
        system("color 2B");
z:
        cout << "Check Balance Screen"<< endl;
        cout << "1) From Current" << endl;
        cout << "2) From Savings" << endl;
        cout << "3) Back to Main Menu" << endl;
        cout << "Enter Your Check Balance Choice: ";
        checkBalance=getch();
        checkBalance=int(checkBalance-48);


        switch(checkBalance)
        {
        case 1:
            hashy.checkbalance(pin,accno,1);
            getch();
            system("cls");
            system("cls");
            cout<<"LOADING......................";
            Sleep(2000);
            showMenu();
            break;
        case 2:
            hashy.checkbalance(pin,accno,0);
            getch();
            system("cls");
            system("cls");
            cout<<"LOADING......................";
            Sleep(2000);
            showMenu();
            break;
        case 3:
            system("cls");
            cout<<"LOADING......................";
            Sleep(2000);
            showMenu();
            break;
        default:
            cout << "INVALID INPUT!! ENTER AGAIN"<<endl;
            cin >> checkBalance;
            goto z;

        }
        break;

    case 4:
        cout << "Funds Transfer Screen"<< endl;
        cout << "1) From Current" << endl;
        cout << "2) From Saving" << endl;
        cout << "3) Back to Main Menu" << endl;
        cout << "Enter Your Funds Transfer Choice: ";
        fundsTransfer=getch();
        fundsTransfer=int(fundsTransfer-48);

        if(fundsTransfer < 1 || fundsTransfer > 3)
        {
            cout << "INVALID INPUT!! ENTER AGAIN"<<endl;
            cin >> fundsTransfer;

        }
        switch(fundsTransfer)
        {
        case 1:
            hashy.accountnumber(0);
            getch();
            system("cls");
            system("cls");
            cout<<"LOADING......................";
            Sleep(2000);
            showMenu();
            break;
        case 2:
            hashy.accountnumber(1);
            getch();
            system("cls");
            system("cls");
            cout<<"LOADING......................";
            Sleep(2000);
            showMenu();
            break;
        }



        if (choice == 3)
        {
            system("cls");
            cout<<"LOADING......................";
            Sleep(2000);
            showMenu();
        }
        break;

    case 5:
        system("cls");
        system("cls");
    cout<<"............SIGNING OFF............";
    Sleep(3000);
        cout<<endl<<"\t\t\t  *********************\n\n\n\n\t\t    ************THANK YOU*************\n\n\n\n\t\t\t  *********************";
        getch();
        system("cls");
        exit(1);
    }
    return choice;
}


void welcomeScreen()
{
    cout << "                                  Hit enter to simulate inserting card"<<endl;
    cout<<"_______________________________________________________________________________________________________________________";
    getch();
    system("cls");

    cout<<"LOADING......................";

    Sleep(2000);
}
