//2425
#include <iostream>
#include <windows.h>
#include <iomanip>
#include <conio.h>
#include <fstream>
#include <direct.h>
#include <ctime>
#include <conio.h>
#include <process.h>
#include <sstream>
#include <cstdio>
#include <string>
#include <stdlib.h>
using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_ENTER 13

enum eDerection {STOP = 0,UP,DOWN};  //status
eDerection dir;                      //keeping the direction

void MainMenuDisp();
void ThreeOutMenuLogic();
void TwoOutMenuLogic();
void FourOutMenuLogic();
void FiveOutMenuLogic();
void SixOutMenuLogic();
void Input();
void DataBaseBased();
void ItemCodeCheck();
void GoodsTransactions();
void Menu01Disp();
void Menu02Disp();
void Menu03Disp();
void Menu04Disp();
void DateAndTime();
void DueManually();
void TPriceTXT();
void TPriceDIS();
void PriceLinesTXT();
void PriceLinesDIS();
void AboutApp();
void Reports();
void UpdateDataBase();
void OtherTransactions();
void VeiwItems();
void SubmitToday();
void DPriceLinesTXT();
void DOPriceLinesTXT();
void DOPriceLinesTXTOut();
void StartCash();
void DailyReportCreation();

char billingSession;
char anotherBill;
char correct;
char terminateforN;
char terminateC;
char printX;
char dlog01;
int b = 3;
char backToMenu02;
char fName[] = "Bills\\CurrentBill.txt";
char HName[] = "GoodsTransactions\\GoodsTransactions.txt";
char XName[] = "OtherTransactions\\OtherTransactions.txt";
char viewLocation[] = "DailyReports\\view.txt";
char rName[115];


int contRep = 0;
int contRepOther = 0;
int c = 1; //item counter in bill
int itemCode; //primary key in GL
int id; //primary key in GL
int dlogQuantity;
int status;//dateAndTime return value holder
int y = 0; //menu position holder
int counterGT = 0;
int counterOT = 0;

bool x; //main menu Display controller
bool Mainmenu;
bool itemCont;
bool billCont;
bool one;
bool two;
bool goodsTrans;
bool terminateFN;
bool otherTrans;
bool veiw;
bool backToMain;
bool passWordRe;
bool report;
bool otherTransOut;



 ///File01 variables
double quantity; //no of units
double profit; //profit to shop owner
double mPrice; //unit price
double aPrice; //all price
double tPrice; //total price
double startCash;
double dlogPrice;
double dlogAPrice;
double dlogTPrice;
double priceOther;
//total
double gReceved;
double oPaid;
double grandTotal;

string headingInFile01[4];
string headingInBillMan[14];
string headingInBill[14];
string mName; //name of item
string today;
string day;
string month;
string year;
string timeNow;
string terminatePass = "1999power"; //terminate password in log
string terminateCode;
string dlogName;
string noteOther;
string headingInDailyLog[4];
string iName;
string iOName;
string GCopyTextHeader[22];

stringstream recordHolder;
stringstream totalHolder;
stringstream DrecordHolder;
stringstream DOrecordHolder;
stringstream DOrecordHolderOut;
stringstream StartCashHolder;
stringstream TotalPaidAmount;
stringstream TotalRecevedAmount;
stringstream CashHaveAtEndOfTheDay;



//void ProductPriceUpdateMenu();
//void Add New ProductsMenu();
//void WeeklySummery();

int main()
{


    Mainmenu = false;
    while (!Mainmenu){
        y = 0;

        MainMenuDisp();
        if (y == 0){
            Menu01Disp();

            if (y == 0){
                one = false;
                while (!one){
                    system("cls");
                    DueManually();
                    if (one == false){
                        cout << "Do you want to create another bill(Y/N) : ";
                        cin >> anotherBill;
                        if (anotherBill == 'N' || anotherBill == 'n'){
                        one = true;
                        }
                    }

                }
            }
            else if (y == 1){
                two = false;
                while (!two){
                    system("cls");
                    DataBaseBased();
                    if (two == false){
                        cout << "Do you want to create another bill(Y/N) : ";
                        cin >> anotherBill;
                        if (anotherBill == 'N'){
                            two = true;
                        }
                    }

                }
            }

        }
        else if (y == 1){
            backToMain = false;
            while(!backToMain){
                y = 0;
                Menu02Disp();
                if (y == 0){
                    goodsTrans = false;
                    while (!goodsTrans){
                        system("cls");
                        GoodsTransactions();
                    }
                }
                else if (y == 1){
                    otherTransOut = false;
                    otherTrans = false;
                    while (!otherTrans){
                        Menu04Disp();
                        if (y == 0){
                            //other trans
                            otherTrans = false;
                            while (!otherTrans){
                                system("cls");
                                OtherTransactions();
                            }
                        }
                        else if (y == 1){
                            otherTransOut = true;
                            while (!otherTrans){
                                system("cls");
                                OtherTransactions();
                            }


                        }
                    }


                }
                else if (y == 2){
                    veiw = false;
                    while (!veiw){
                        VeiwItems();
                    }
                }
                else if (y == 3){
                        if (counterGT > 0 || counterOT > 0){
                            passWordRe = false;
                            while(!passWordRe){
                                SubmitToday();
                            }
                        }
                        else {
                            system ("cls");
                            cout << "You did't enter any records or file already submitted!" << endl;
                            getch();
                        }

                }
                else if (y == 4){
                    backToMain = true;
                }
            }

        }
        else if (y == 2){
           UpdateDataBase();
        }
        else if (y == 3){
            report = false;
            while (!report){
                    Reports();
            }

        }
        else if (y == 4){

            AboutApp();
        }
        else if (y == 5){
            Mainmenu = true;
        }
    }

    return 0;
}

void MainMenuDisp(){
    x = false;
    while (!x){
        system("cls");
            cout << "<UP: arrow up>  <DOWN: arrow down>  <ENTER: enter key>" << endl;
            cout << endl << endl<< endl << endl;
            dir = STOP;
            Input();
            SixOutMenuLogic();

            if (y == 0){
                cout << "                1.Create a new bill <--"     << endl;
            }
            else{
                cout << "                1.Create a new bill    "     << endl;
            }

            if (y == 1){
                cout << "                2.Daily Log <--"             << endl;
            }
            else{
                cout << "                2.Daily Log    "             << endl;
            }

            if (y == 2){
                cout << "                3.Update Data Base <--"      << endl;
            }
            else{
                cout << "                3.Update Data Base    "      << endl;
            }

            if (y == 3){
                cout << "                4.Reports <--"               << endl;
            }
            else{
                cout << "                4.Reports    "               << endl;
            }

            if (y == 4){
                cout << "                5.About Application <--"     << endl;
            }
            else{
                cout << "                5.About Application    "     << endl;
            }

            if (y == 5){
                cout << "                6.Quit <--"                  << endl;
            }
            else{
                cout << "                6.Quit    "                  << endl;
            }
    }
}

void Menu01Disp(){
    x = false;
    while (!x){
        system("cls");
            cout << endl << endl<< endl << endl << endl <<  endl;
            dir = STOP;
            Input();
            TwoOutMenuLogic();

            if (y == 0){
                cout << "                  1.Due manually <--" << endl;
            }
            else{
                cout << "                  1.Due manually    " << endl;
            }


            if (y == 1){
                cout << "                  2.Data base based <--" << endl;
            }
            else{
                cout << "                  2.Data base based    "<< endl;
            }
    }
}
void Menu02Disp(){
 x = false;
    while (!x){
        system("cls");
            cout << endl << endl<< endl << endl << endl;
            dir = STOP;
            Input();
            FiveOutMenuLogic();

            if (y == 0){
                cout << "               1.Enter Goods Transactions <--" << endl;
            }
            else{
                cout << "               1.Enter Goods Transactions    " << endl;
            }


            if (y == 1){
                cout << "               2.Enter Other Transactions <--" << endl;
            }
            else{
                cout << "               2.Enter Other Transactions    "<< endl;
            }


            if (y == 2){
                cout << "               3.View all Transactions  <--" << endl;
            }
            else{
                cout << "               3.View all Transactions     " << endl;
            }
             if (y == 3){
                cout << "               4.Submit Today  <--" << endl;
            }
            else{
                cout << "               4.Submit Today     " << endl;
            }
            if (y == 4){
                cout << "               5.Back To MainMenu  <--" << endl;
            }
            else{
                cout << "               5.Back To MainMenu     " << endl;
            }
    }
 }
void Menu03Disp(){
    y = 0;
    x = false;
    while (!x){
        system("cls");
            cout << endl << endl<< endl << endl << endl <<  endl;
            dir = STOP;
            Input();
            TwoOutMenuLogic();

            if (y == 0){
                cout << "                  1.Daily Report <--" << endl;
            }
            else{
                cout << "                  1.Daily Report    " << endl;
            }


            if (y == 1){
                cout << "                  2.Weekly Report <--" << endl;
            }
            else{
                cout << "                  2.Weekly Report    "<< endl;
            }
    }


}
void Menu04Disp(){
    y = 0;
    x = false;
    while (!x){
        system("cls");
            cout << endl << endl<< endl << endl << endl <<  endl;
            dir = STOP;
            Input();
            TwoOutMenuLogic();

            if (y == 0){
                cout << "                  1.In <--" << endl;
            }
            else{
                cout << "                  1.In    " << endl;
            }


            if (y == 1){
                cout << "                  2.Out <--" << endl;
            }
            else{
                cout << "                  2.Out    "<< endl;
            }
    }

}

//START OF FUNCTION "INPUT"
void Input(){
	if (_kbhit())
	{
		switch (_getch())
		{
		case KEY_DOWN: dir = DOWN;
			break;
		case KEY_UP: dir = UP;
			break;
        case KEY_ENTER: x = true;
			break;

		}

    }

} //END OF FUNCTION "INPUT"

void TwoOutMenuLogic(){
    if (dir == DOWN){
            if (y != 1){
                y++;
                Beep (256,40);
            }
    }
    else if (dir == UP){
            if (y != 0){
                y--;
                Beep (256,40);
            }
    }
}
void ThreeOutMenuLogic(){
    if (dir == DOWN){
            if (y != 2){
                y++;
                Beep (256,40);
            }
    }
    else if (dir == UP){
            if (y != 0){
                y--;
                Beep (256,40);
            }
    }
}
void FourOutMenuLogic(){
    if (dir == DOWN){
            if (y != 3){
                y++;
                Beep (256,40);
            }
    }
    else if (dir == UP){
            if (y != 0){
                y--;
                Beep (256,40);
            }
    }
}
void FiveOutMenuLogic(){
    if (dir == DOWN){
            if (y != 4){
                y++;
                Beep (256,40);
            }
    }
    else if (dir == UP){
            if (y != 0){
                y--;
                Beep (256,40);
            }
    }
}
void SixOutMenuLogic(){
    if (dir == DOWN){
            if (y != 5){
                y++;
                Beep (256,40);
            }
    }
    else if (dir == UP){
            if (y != 0){
                y--;
                Beep (256,40);
            }
    }
}

void DueManually(){


    string lName = "Bills\\"; //diadomaxx
    char aName[24];
    aPrice = 0;
    quantity = 0;
    tPrice = 0;
        cout << "Do you want to create new billing session(Y/N): ";
        cin >> billingSession;

        if (billingSession == 'Y' || billingSession == 'y'){
            system("cls");
            totalHolder.str("");
            DateAndTime();
            ofstream FileBill("Bills\\CurrentBill.txt");
            cout << "Date :" << year << "/" << month << "/" << day << " (" << today << ")" << endl;
            cout << "Time :" << timeNow << endl;
            FileBill << "Date :" << year << "/" << month << "/" << day << "            " << "Time :" << timeNow << endl;
            FileBill << endl;
            FileBill << "            Randina  Hardware,"   << endl;
            FileBill << "            No.21,Temple Road,"   << endl;
            FileBill << "               Moratumulla,"      << endl;
            FileBill << "                Moratuwa."        << endl;
            FileBill << endl;
            FileBill << "ItemName          " << "UPrice   "<< "Quantity   " << "Price" << endl;
            FileBill << endl;
            billCont = false;
            c = 1;
            while (!billCont){
                recordHolder.str("");
                cout << "Enter item name of item " << c << ": ";
                cin >> mName;

                if (mName != "-1"){
                    int z = 16 - mName.length();
                    for (int x = 0; x < z; x++){
                        mName.append("-");
                    }
                }


                if (mName == "-1"){
                    billCont = true;
                }
                else{

                    cout << "Enter price of item " << c << ": ";
                    while(!((cin >> mPrice)&&(mPrice >= 0 && mPrice < 100000))){
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "Data invalid!" << endl;

                        cout << "Enter price of item " << c << ": ";

                    }

                    cout << "Enter Quantity of item " << c << ": ";
                    while(!((cin >> quantity)&&(quantity >= 0 && quantity < 1000))){
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "Data invalid!" << endl;

                        cout << "Enter Quantity of item " << c << ": ";

                    }

                    aPrice = quantity * mPrice;
                    tPrice = tPrice + aPrice;


                    PriceLinesTXT();///-----------------------------------------------------------------------
                    string R = recordHolder.str();
                    FileBill << R << endl;

                    cout << "Item added succesfully !" << endl;
                    c++;
                }

            }//end of billCont while
            TPriceTXT();
            string T = totalHolder.str();
            FileBill << T << endl;

            system("cls");
            cout << "Items added succesfully !" << endl;
            FileBill.close();

            ///display bill
            ifstream FileBill2("Bills\\CurrentBill.txt");
            cout << endl;
            cout << "bill preview --" << endl;
            DateAndTime();
            cout << "Date :" << year << "/" << month << "/" << day << "            " << "Time :" << timeNow << endl;
            cout << endl;
            cout << "            Randina  Hardware,"   << endl;
            cout << "            No.21,Temple Road,"   << endl;
            cout << "               Moratumulla,"      << endl;
            cout << "                Moratuwa."        << endl;
            cout << endl;

            FileBill2 >> headingInBillMan[0] >> headingInBillMan[1] >> headingInBillMan[2] >> headingInBillMan[3] >> headingInBillMan[4] >> headingInBillMan[5] >> headingInBillMan[6] >> headingInBillMan[7] >> headingInBillMan[8] >> headingInBillMan[9] >> headingInBillMan[10] >> headingInBillMan[11] >> headingInBillMan[12] >> headingInBillMan[13];
            cout << headingInBillMan[10] << "          "<< headingInBillMan[11] << "   " << headingInBillMan[12] << "   " << headingInBillMan[13] << endl;


            while (FileBill2 >> mName >> mPrice >> quantity >> aPrice ){
                PriceLinesDIS();///----------------------------------------------------------------------------
            }

            TPriceDIS();
            FileBill2.close();

            cout << "Do you Want to Print(Y/N): ";
            cin >> printX;

            if ( printX == 'Y' || printX == 'y'){
                system("notepad /p Bills\\CurrentBill.txt");

            }
            cout << "Enter a name to the file: ";
            cin >> iName;

            int q = 13 - iName.length();
            for (int x = 0; x < q; x++){
                iName.append("-");
            }
            iName.append(".txt");

            lName.append(iName);


            for (unsigned int i=0; i < lName.length(); ++i){
                aName[i] = lName.at(i);
            }

            rename(fName,aName);

        }//end of billing session if
        else if (billingSession == 'N' || billingSession == 'n'){
            one = true;
        }

}

void DataBaseBased(){
    string lName = "Bills\\";
    char aName[24];
    aPrice = 0;
    quantity = 0;
    tPrice = 0;
    mPrice = 0;
    mName = "";
        cout << "Do you want to create new billing session(Y/N): ";
        cin >> billingSession;

        if (billingSession == 'Y'|| billingSession == 'y'){
                totalHolder.str("");

            DateAndTime();
            ofstream FileBill("Bills\\CurrentBill.txt");

            FileBill << "Date :" << year << "/" << month << "/" << day << "            " << "Time :" << timeNow << endl;
            FileBill << endl;
            FileBill << "            Randina  Hardware,"   << endl;
            FileBill << "            No.21,Temple Road,"   << endl;
            FileBill << "               Moratumulla,"      << endl;
            FileBill << "                Moratuwa."        << endl;
            FileBill << endl;
            FileBill << "ItemName          " << "UPrice   "<< "Quantity   " << "Price" << endl;
            FileBill << endl;
            billCont = false;
            c = 1;
            while (!billCont){
                recordHolder.str(""); // remove data in string stream variable------------------------------------------------------------
                itemCont = false;
                while (!itemCont){
                    system("cls");
                    cout << "Enter item code of item " << c << ": ";

                    while(!((cin >> itemCode)&&(itemCode >= -1 && itemCode <= 10)&&(itemCode != 0))){
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "Data invalid!" << endl;

                        cout << "Enter item code of item " << c << ": ";

                    }

                    if (itemCode == -1){
                        billCont = true;
                        itemCont = true;
                    }
                    if (itemCode != -1){
                        ItemCodeCheck();

                        cout << "Correct(Y/N) ?: ";
                        cin >> correct;

                        if (correct == 'Y'){
                            itemCont = true;
                        }
                    }


                }//end of itemCont while
                if (itemCode != -1){
                    cout << "Enter Quantity of item " << ": ";
                    //
                    while(!((cin >> quantity)&&(quantity > 0 && quantity < 1000))){
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "Data invalid!" << endl;

                        cout << "Enter Quantity of item " << ": ";

                    }


                    system("cls");
                    aPrice = quantity * mPrice;
                    tPrice = tPrice + aPrice;
                    PriceLinesTXT();//-------------------------------------------------------------------------------------
                    string r = recordHolder.str();
                    FileBill << r << endl;


                    cout << "Item added successfully !" << endl;
                    c++;
                }//end of if
            }//end of billCont while
            TPriceTXT();
            string t = totalHolder.str();
            FileBill << t << endl;
            system("cls");
            FileBill.close();
            cout << "Items added successfully !" << endl;

            ///display bill
            cout << endl;
            cout << "bill preview --" << endl;
            DateAndTime();
            cout << "Date :" << year << "/" << month << "/" << day << "            " << "Time :" << timeNow << endl;
            cout << endl;
            cout << "            Randina  Hardware,"   << endl;
            cout << "            No.21,Temple Road,"   << endl;
            cout << "               Moratumulla,"      << endl;
            cout << "                Moratuwa."        << endl;
            cout << endl;

            ifstream FileBill2("Bills\\CurrentBill.txt");

            FileBill2 >> headingInBill[0] >> headingInBill[1] >> headingInBill[2] >> headingInBill[3] >> headingInBill[4] >> headingInBill[5] >> headingInBill[6] >> headingInBill[7] >> headingInBill[8] >> headingInBill[9] >> headingInBill[10] >> headingInBill[11] >> headingInBill[12] >> headingInBill[13];
            cout << headingInBill[10] << "          "<< headingInBill[11] << "   " << headingInBill[12] << "   " << headingInBill[13] << endl;


            while (FileBill2 >> mName >> mPrice >> quantity >> aPrice ){
                PriceLinesDIS();///----------------------------------------------------------------------------
            }

            TPriceDIS();
            FileBill2.close();

            cout << "Do you Want to Print(Y/N): ";
            cin >> printX;

            if ( printX == 'Y' || printX == 'y'){
                system("notepad /p Bills\\CurrentBill.txt");

            }


            cout << "Enter a name to the file: ";
            cin >> iName;
            int q = 13 - iName.length();
            for (int x = 0; x < q; x++){
                iName.append("-");
            }
            iName.append(".txt");


            lName.append(iName);

            for (unsigned int i=0; i < lName.length(); ++i){
                aName[i] = lName.at(i);
            }

            rename(fName,aName);

        }//end of billing session if
        else{
            two = true;
        }

}//end of function "Bills"

void ItemCodeCheck(){

    if (itemCode >= 0 && itemCode < 1000){
        ifstream File01("Item List.txt");

        File01 >> headingInFile01[0] >> headingInFile01[1] >> headingInFile01[2] >> headingInFile01[3];

        while (File01 >> id >> mName >> mPrice >> profit){
                if (id == itemCode){
                    cout << headingInFile01[0] << "   " << headingInFile01[1] << "     " << headingInFile01[2] << endl;
                    cout <<" "<< id <<"    "<< mName << "         " << mPrice << endl;
                    return;
                }
        }

    }
    else if (itemCode >= 1000 && itemCode < 2000){
        ///another file
    }

 }

void GoodsTransactions(){

    //goods & other menu
    DrecordHolder.str("");
    StartCashHolder.str("");

    DateAndTime();
    cout << "Date :" << year << "/" << month << "/" << day << endl;

    ofstream GoodsTransFile("GoodsTransactions\\GoodsTransactions.txt",ios::app);
    ofstream viewFile ("DailyReports\\view.txt", ios::app);
    if (contRep != 1){
        GoodsTransFile << "Today is: " << today << endl;
        GoodsTransFile << "Date :" << year << "/" << month << "/" << day << endl;
        GoodsTransFile << "First Transaction Time :" << timeNow << endl << endl;
        viewFile << "Today is: " << today << endl;
        viewFile << "Date :" << year << "/" << month << "/" << day << endl;
        viewFile << "First Transaction Time :" << timeNow << endl << endl;

        cout << "Cash have at start of the day:";
        //
        while(!((cin >> startCash)&&(startCash >= 0 && startCash < 100000))){
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Data invalid!" << endl;

            cout << "Cash have at start of the day:";

        }
        //
        ///---------------------------------------------------
        StartCash();
        string r = StartCashHolder.str();
        GoodsTransFile << r << endl << endl << endl;
        viewFile << r << endl << endl << endl;


        GoodsTransFile << "  Time         " << "ItemName        " << "UPrice   " << "Quantity  " << "TPrice" << endl << endl;
        viewFile << "  Time         " << "ItemName        " << "UPrice   " << "Quantity  " << "TPrice" << endl << endl;

        contRep = 1;



    }

    terminateFN = false;
    while (!terminateFN){
        system("cls");
        DateAndTime();
        cout << "Date :" << year << "/" << month << "/" << day << "            " << "Time :" << timeNow << endl;


        cout << "Enter item name : ";
        cin >> dlogName;
        int z = 16 - dlogName.length();
        for (int x = 0; x < z; x++){
            dlogName.append("-");
        }

        cout << "Enter item price of one: Rs.";
        //
        while(!((cin >> dlogPrice)&&(dlogPrice >= 0 && dlogPrice < 100000))){
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Data invalid!" << endl;

            cout << "Enter item price of one: Rs.";

        }


        cout << "Enter item quantity : ";
        //
        while(!((cin >> dlogQuantity)&&(dlogQuantity >= 0 && dlogQuantity < 1000))){
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Data invalid!" << endl;

            cout << "Enter item quantity : ";

        }


        dlog01 = 'A';
        cout << "Is it correct?(Y/N) :" ;
        cin >> dlog01;

        if (dlog01 == 'Y' || dlog01 == 'y'){
            dlogAPrice = dlogQuantity * dlogPrice;
            gReceved = gReceved + dlogAPrice;
            ///-----------------------------------------------
            DPriceLinesTXT();
            string R = DrecordHolder.str();
            GoodsTransFile << R << endl;
            viewFile << R << endl;

            counterGT++;

            terminateFN = true;

        }

    }
    GoodsTransFile.close();
    viewFile.close();
    goodsTrans = true;
    cout << "Item added successfully!" << endl;

    getch();



 }

void OtherTransactions(){



    system("cls");
    DateAndTime();
    cout << "Date :" << year << "/" << month << "/" << day << endl;

    ofstream OtherTransactionsFile("OtherTransactions\\OtherTransactions.txt",ios::app);
    ofstream viewFile ("DailyReports\\view.txt", ios::app);

    if (contRepOther != 1){
        OtherTransactionsFile << "Today is: " << today << endl;
        OtherTransactionsFile << "Date :" << year << "/" << month << "/" << day << endl << endl;

        contRepOther = 1;

    }

    if (counterGT == 0){
        ofstream GoodsTransFile("GoodsTransactions\\GoodsTransactions.txt",ios::app);
        GoodsTransFile << "Today is: " << today << endl;
        GoodsTransFile << "Date :" << year << "/" << month << "/" << day << endl;
        GoodsTransFile << "First Transaction Time :" << timeNow << endl << endl;
        viewFile << "Today is: " << today << endl;
        viewFile << "Date :" << year << "/" << month << "/" << day << endl;
        viewFile << "First Transaction Time :" << timeNow << endl << endl;

        cout << "Cash have at start of the day:";
        //
        while(!((cin >> startCash)&&(startCash >= 0 && startCash < 100000))){
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Data invalid!" << endl;

            cout << "Cash have at start of the day:";

        }

        StartCash();
        string r = StartCashHolder.str();
        GoodsTransFile << r << endl << endl << endl;
        viewFile << r << endl << endl << endl;


        GoodsTransFile << "  Time         " << "ItemName        " << "UPrice   " << "Quantity  " << "TPrice" << endl << endl;
        viewFile << "  Time         " << "ItemName        " << "UPrice   " << "Quantity  " << "TPrice" << endl << endl;

        contRep = 1;
        GoodsTransFile.close();
    }

    if (otherTransOut == true){
        terminateFN = false;
        while (!terminateFN){
            DOrecordHolderOut.str("");
            system("cls");
            DateAndTime();
            cout << "Date :" << year << "/" << month << "/" << day << "            " << "Time :" << timeNow << endl;

            cout << "Enter Note : ";
            cin >> noteOther;
            noteOther.append("(out)");
            //
            cout << "Enter price: Rs.";
            while(!((cin >> priceOther)&&(priceOther >= 0 && priceOther < 100000))){
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Data invalid!" << endl;

                cout << "Enter price: Rs.";

            }
            dlog01 = 'A';
            cout << "Is it correct?(Y/N) :" ;
            cin >> dlog01;

            if (dlog01 == 'Y' || dlog01 == 'Y'){
                counterOT++;
                DOPriceLinesTXTOut();
                string R = DOrecordHolderOut.str();
                OtherTransactionsFile << R << endl;
                viewFile << R << endl;

                oPaid = oPaid + priceOther;
                terminateFN = true;
            }

        }
    }
    else{
        terminateFN = false;
        while (!terminateFN){
            DOrecordHolder.str("");
            system("cls");
            DateAndTime();
            cout << "Date :" << year << "/" << month << "/" << day << "            " << "Time :" << timeNow << endl;

            cout << "Enter Note : ";
            cin >> noteOther;
            noteOther.append("(in)");
            cout << "Enter price: Rs.";

            while(!((cin >> priceOther)&&(priceOther >= 0 && priceOther < 100000))){
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Data invalid!" << endl;

                cout << "Enter price: Rs.";

            }

            dlog01 = 'A';
            cout << "Is it correct?(Y/N) :" ;
            cin >> dlog01;

            if (dlog01 == 'Y' || dlog01 == 'Y'){
                counterOT++;
                DOPriceLinesTXT();
                string R = DOrecordHolder.str();
                OtherTransactionsFile << R << endl;
                viewFile << R << endl;

                gReceved = gReceved + priceOther;
                terminateFN = true;
            }

        }
    }

    OtherTransactionsFile.close();
    viewFile.close();

    otherTrans = true;
    cout << "Item added successfully!" << endl;
    getch();


}

void DateAndTime(){
    ofstream tempDTwrite("tempDate&Time.txt");
    time_t now = time(0);
    char* dt = ctime(&now);
    tempDTwrite << dt;
    tempDTwrite.close();

    ifstream tempDTread("tempDate&Time.txt");
    tempDTread >> today >> month >> day >> timeNow >> year ;
    tempDTread.close();

    status = remove("tempDate&Time.txt");
 }

void AboutApp(){
    system("cls");
    cout << "    This is a shop transactions management software" << endl;
    cout << "    that created without classes and any interface design using c++ " << endl;
    cout << "    This will help you to manage your shop easily" << endl;
    cout << "    **Some parts are not created yet!!" << endl<< endl;
    cout << "    CONTROLS:" << endl;
    cout << "              arrow up --- move up" << endl;
    cout << "              arrow down --- move down" << endl;
    cout << "              enter key  --- interact" << endl<< endl;

    cout << "   Created by -- Thisura Rabel" << endl;
    getch();
}

void Reports(){
     system("cls");
     Menu03Disp();

     if (y == 0){
        //daily report
        system("cls");
        if (terminateCode != terminatePass){
            cout << "Please Submit Day's work to view daily report" << endl << endl;
            cout << "Submission method--" << endl;
            cout << "#Go to (Daily Log -> Submit Today)." << endl;
            cout << "#Enter the password. " << endl;
            cout << "#Give file names for gt & ot. " << endl;

        }
        else {
            //view file
            ifstream DailyReportView (rName, ios::app);
            string getContent;

            while (! DailyReportView.eof()){
                getline(DailyReportView,getContent);
                cout << getContent << endl;
            }
            DailyReportView.close();

        }
        getch();
        report = true;
     }
     else if (y == 1){
        //weekly report
        system("cls");
        cout << "Still not created this part of the program!!!" << endl;
        getch();
        report = true;
     }

}

void UpdateDataBase(){
     system("cls");
     cout << "    still not created this part of the program !!!" << endl;
     getch();
}

void VeiwItems(){
    system("cls");

    if (counterGT > 0 || counterOT > 0 ){
       ///display view file
        ifstream viewFileRead ("DailyReports\\view.txt", ios::app);
        string getContent;

        while (! viewFileRead.eof()){
            getline(viewFileRead,getContent);
            cout << getContent << endl;
        }

        viewFileRead.close();
        getch();
        veiw = true;
    }
    else{
        cout << endl;
        cout << "You didn't enter records yet or file already submitted!" << endl << endl;
        cout << "#go to 'Reports' section to view the report" << endl;
        getch();
        veiw = true;
    }


}

void SubmitToday(){
    string GName = "GoodsTransactions\\";
    char aName[38];

    string OName = "OtherTransactions\\";
    char aOName[38];

    system("cls");
    cout << "Enter Termination Password:";
    cin >> terminateCode;

    if (terminateCode == terminatePass){
        ///Please do storing values reset part---------------------------------------------------------------------------------------------------------------------------

        counterGT = 0;
        counterOT = 0;
        ///modify  reportFile--------------------------------------------------------------------------------------------------------
        TotalPaidAmount.str("");
        TotalRecevedAmount.str("");
        CashHaveAtEndOfTheDay.str("");

        grandTotal = gReceved - oPaid; //get grand total
        grandTotal = grandTotal + startCash;
        ofstream viewFileCon ("DailyReports\\view.txt", ios::app);
        viewFileCon << endl;
        viewFileCon << "........................................................" << endl;
        DailyReportCreation();

        string R1 = TotalPaidAmount.str();
        viewFileCon << R1 << endl;

        string R2 = TotalRecevedAmount.str();
        viewFileCon << R2 << endl;

        string R3 = CashHaveAtEndOfTheDay.str();
        viewFileCon << R3 << endl;
        viewFileCon << "........................................................" << endl;
        viewFileCon.close();
        ///end of modify


        string RName = "DailyReports\\(";

        DateAndTime();
        RName.append(year);
        RName.append(".");
        RName.append(month);
        RName.append(".");
        RName.append(day);
        RName.append(")DailyReport.txt");

        for (unsigned int i=0; i < RName.length(); ++i){
            rName[i] = RName.at(i);
        }

        rename(viewLocation,rName);
        cout << rName << endl;



        // rename goods transactions
        cout << "Enter a name to the Goods Transaction file: ";
        cin >> iName;

        int z = 15 - iName.length();
        for (int x = 0; x < z; x++){
            iName.append("-");
        }
        iName.append(".txt");

            GName.append(iName);

            for (unsigned int i=0; i < GName.length(); ++i){
                aName[i] = GName.at(i);
            }

            rename(HName,aName);

            cout << aName << endl;

        // rename other transactions
        cout << "Enter a name to the Other Transaction file: ";
        cin >> iOName;

        int zz = 15 - iOName.length();
        for (int x = 0; x < zz; x++){
            iOName.append("-");
        }
        iOName.append(".txt");



            OName.append(iOName);

            for (unsigned int i=0; i < OName.length(); ++i){
                aOName[i] = OName.at(i);
            }

            rename(XName,aOName);
            cout << aOName << endl;

            getch();


        system("cls");
        cout << "    Files submitted successfully !!!" << endl << endl;
        cout << "    #Go to Daily report section to view daily " << endl;
        cout << "    transaction report " << endl;
        getch();
        passWordRe = true;

    }
    else{
        system("cls");
        cout << "PassWord is incorrect!!!" << endl;
        cout << "Back To Menu? (Y/N): ";
        cin >> backToMenu02;

        if (backToMenu02 == 'Y'){
            passWordRe = true;

        }

    }
}



void TPriceTXT(){
            if (tPrice >= 10 && tPrice < 100){
                totalHolder << " Total" << "                                   " << tPrice << endl;
            }
            else if (tPrice >= 100 && tPrice < 1000){
                totalHolder << " Total" << "                                  " << tPrice << endl;
            }
            else if (tPrice >= 1000 && tPrice < 10000){
                totalHolder << " Total" << "                                 " << tPrice << endl;
            }
            else if (tPrice >= 10000 && tPrice < 100000){
                totalHolder << " Total" << "                                " << tPrice << endl;
            }
             else if (tPrice >= 100000 && tPrice < 1000000){
                totalHolder << " Total" << "                               " << tPrice << endl;
            }
            else{
                totalHolder << " Total" << "                                    " << tPrice << endl;
            }
}
void TPriceDIS(){
          if (tPrice >= 10 && tPrice < 100){
                cout << " Total" << "                                   " << tPrice << endl;
            }
            else if (tPrice >= 100 && tPrice < 1000){
                cout << " Total" << "                                  " << tPrice << endl;
            }
            else if (tPrice >= 1000 && tPrice < 10000){
                cout << " Total" << "                                 " << tPrice << endl;
            }
            else if (tPrice >= 10000 && tPrice < 100000){
                cout << " Total" << "                                " << tPrice << endl;
            }
             else if (tPrice >= 100000 && tPrice < 1000000){
                cout << " Total" << "                               " << tPrice << endl;
            }
            else{
                cout << " Total" << "                                    " << tPrice << endl;
            }
}
void PriceLinesTXT(){


    if (quantity >= 10 && quantity < 100){
        if (mPrice >= 10 && mPrice < 100){
            if (aPrice >= 10 && aPrice < 100){
                recordHolder << " " << mName << "    " << mPrice << "       " << quantity << "         " << aPrice ;
            }
            else if (aPrice >= 100 && aPrice < 1000){
                recordHolder << " " << mName << "    " << mPrice << "       " << quantity << "        " << aPrice ;
            }
            else if (aPrice >= 1000 && aPrice < 10000){
                recordHolder << " " << mName << "    " << mPrice << "       " << quantity << "       " << aPrice ;
            }
            else if (aPrice >= 10000 && aPrice < 100000){
                recordHolder << " " << mName << "    " << mPrice << "       " << quantity << "      " << aPrice ;
            }
            else if (aPrice >= 100000 && aPrice < 1000000){
                recordHolder << " " << mName << "    " << mPrice << "       " << quantity << "     " << aPrice ;
            }
            else{
                recordHolder << " " << mName << "    " << mPrice << "       " << quantity << "          " << aPrice ;
            }

        }
        else if (mPrice >= 100 && mPrice < 1000){
            if (aPrice >= 10 && aPrice < 100){
                recordHolder << " " << mName << "   " << mPrice << "       " << quantity << "         " << aPrice ;
            }
            else if (aPrice >= 100 && aPrice < 1000){
                recordHolder << " " << mName << "   " << mPrice << "       " << quantity << "        " << aPrice ;
            }
            else if (aPrice >= 1000 && aPrice < 10000){
                recordHolder << " " << mName << "   " << mPrice << "       " << quantity << "       " << aPrice ;
            }
            else if (aPrice >= 10000 && aPrice < 100000){
                recordHolder << " " << mName << "   " << mPrice << "       " << quantity << "      " << aPrice ;
            }
            else if (aPrice >= 100000 && aPrice < 1000000){
                recordHolder << " " << mName << "   " << mPrice << "       " << quantity << "     " << aPrice ;
            }
            else{
                recordHolder << " " << mName << "   " << mPrice << "       " << quantity << "          " << aPrice ;
            }
        }
        else if (mPrice >= 1000 && mPrice < 10000){
            if (aPrice >= 10 && aPrice < 100){
                recordHolder << " " << mName << "  " << mPrice << "       " << quantity << "         " << aPrice;
            }
            else if (aPrice >= 100 && aPrice < 1000){
                recordHolder << " " << mName << "  " << mPrice << "       " << quantity << "        " << aPrice;
            }
            else if (aPrice >= 1000 && aPrice < 10000){
                recordHolder << " " << mName << "  " << mPrice << "       " << quantity << "       " << aPrice ;
            }
            else if (aPrice >= 10000 && aPrice < 100000){
                recordHolder << " " << mName << "  " << mPrice << "       " << quantity << "      " << aPrice;
            }
            else if (aPrice >= 100000 && aPrice < 1000000){
                recordHolder << " " << mName << "  " << mPrice << "       " << quantity << "     " << aPrice ;
            }
            else{
                recordHolder << " " << mName << "  " << mPrice << "       " << quantity << "          " << aPrice;
            }
        }
        else if (mPrice >= 10000 && mPrice < 100000){
            if (aPrice >= 10 && aPrice < 100){
                recordHolder << " " << mName << " " << mPrice << "       " << quantity << "         " << aPrice ;
            }
            else if (aPrice >= 100 && aPrice < 1000){
                recordHolder << " " << mName << " " << mPrice << "       " << quantity << "        " << aPrice ;
            }
            else if (aPrice >= 1000 && aPrice < 10000){
                recordHolder << " " << mName << " " << mPrice << "       " << quantity << "       " << aPrice ;
            }
            else if (aPrice >= 10000 && aPrice < 100000){
                recordHolder << " " << mName << " " << mPrice << "       " << quantity << "      " << aPrice ;
            }
            else if (aPrice >= 100000 && aPrice < 1000000){
                recordHolder << " " << mName << " " << mPrice << "       " << quantity << "     " << aPrice ;
            }
            else{
                recordHolder << " " << mName << " " << mPrice << "       " << quantity << "          " << aPrice;
            }
        }
        else{
            if (aPrice >= 10 && aPrice < 100){
                recordHolder << " " << mName << "     " << mPrice << "       " << quantity << "         " << aPrice ;
            }
            else if (aPrice >= 100 && aPrice < 1000){
                recordHolder << " " << mName << "     " << mPrice << "       " << quantity << "        " << aPrice ;
            }
            else if (aPrice >= 1000 && aPrice < 10000){
                recordHolder << " " << mName << "     " << mPrice << "       " << quantity << "       " << aPrice ;
            }
            else if (aPrice >= 10000 && aPrice < 100000){
                recordHolder << " " << mName << "     " << mPrice << "       " << quantity << "      " << aPrice ;
            }
            else if (aPrice >= 100000 && aPrice < 1000000){
                recordHolder << " " << mName << "     " << mPrice << "       " << quantity << "     " << aPrice ;
            }
            else{
                recordHolder << " " << mName << "     " << mPrice << "       " << quantity << "          " << aPrice ;
            }
        }
    }
    else if (quantity >= 100 && quantity < 1000){
        if (mPrice >= 10 && mPrice < 100){
            if (aPrice >= 10 && aPrice < 100){
                recordHolder << " " << mName << "    " << mPrice << "      " << quantity << "         " << aPrice ;
            }
            else if (aPrice >= 100 && aPrice < 1000){
                recordHolder << " " << mName << "    " << mPrice << "      " << quantity << "        " << aPrice ;
            }
            else if (aPrice >= 1000 && aPrice < 10000){
                recordHolder << " " << mName << "    " << mPrice << "      " << quantity << "       " << aPrice ;
            }
            else if (aPrice >= 10000 && aPrice < 100000){
                recordHolder << " " << mName << "    " << mPrice << "      " << quantity << "      " << aPrice ;
            }
            else if (aPrice >= 100000 && aPrice < 1000000){
                recordHolder << " " << mName << "    " << mPrice << "      " << quantity << "     " << aPrice ;
            }
            else{
                recordHolder << " " << mName << "    " << mPrice << "      " << quantity << "          " << aPrice ;
            }

        }
        else if (mPrice >= 100 && mPrice < 1000){
            if (aPrice >= 10 && aPrice < 100){
                recordHolder << " " << mName << "   " << mPrice << "      " << quantity << "         " << aPrice ;
            }
            else if (aPrice >= 100 && aPrice < 1000){
                recordHolder << " " << mName << "   " << mPrice << "      " << quantity << "        " << aPrice ;
            }
            else if (aPrice >= 1000 && aPrice < 10000){
                recordHolder << " " << mName << "   " << mPrice << "      " << quantity << "       " << aPrice ;
            }
            else if (aPrice >= 10000 && aPrice < 100000){
                recordHolder << " " << mName << "   " << mPrice << "      " << quantity << "      " << aPrice ;
            }
            else if (aPrice >= 100000 && aPrice < 1000000){
                recordHolder << " " << mName << "   " << mPrice << "      " << quantity << "     " << aPrice ;
            }
            else{
                recordHolder << " " << mName << "   " << mPrice << "      " << quantity << "          " << aPrice;
            }
        }
        else if (mPrice >= 1000 && mPrice < 10000){
            if (aPrice >= 10 && aPrice < 100){
                recordHolder << " " << mName << "  " << mPrice << "      " << quantity << "         " << aPrice ;
            }
            else if (aPrice >= 100 && aPrice < 1000){
                recordHolder << " " << mName << "  " << mPrice << "      " << quantity << "        " << aPrice ;
            }
            else if (aPrice >= 1000 && aPrice < 10000){
                recordHolder << " " << mName << "  " << mPrice << "      " << quantity << "       " << aPrice ;
            }
            else if (aPrice >= 10000 && aPrice < 100000){
                recordHolder << " " << mName << "  " << mPrice << "      " << quantity << "      " << aPrice ;
            }
            else if (aPrice >= 100000 && aPrice < 1000000){
                recordHolder << " " << mName << "  " << mPrice << "      " << quantity << "     " << aPrice ;
            }
            else{
                recordHolder << " " << mName << "  " << mPrice << "      " << quantity << "          " << aPrice ;
            }
        }
        else if (mPrice >= 10000 && mPrice < 100000){
            if (aPrice >= 10 && aPrice < 100){
                recordHolder << " " << mName << " " << mPrice << "      " << quantity << "         " << aPrice ;
            }
            else if (aPrice >= 100 && aPrice < 1000){
                recordHolder << " " << mName << " " << mPrice << "      " << quantity << "        " << aPrice ;
            }
            else if (aPrice >= 1000 && aPrice < 10000){
                recordHolder << " " << mName << " " << mPrice << "      " << quantity << "       " << aPrice ;
            }
            else if (aPrice >= 10000 && aPrice < 100000){
                recordHolder << " " << mName << " " << mPrice << "      " << quantity << "      " << aPrice ;
            }
            else if (aPrice >= 100000 && aPrice < 1000000){
                recordHolder << " " << mName << " " << mPrice << "      " << quantity << "     " << aPrice ;
            }
            else{
                recordHolder << " " << mName << " " << mPrice << "      " << quantity << "          " << aPrice ;
            }
        }
        else{
            if (aPrice >= 10 && aPrice < 100){
                recordHolder << " " << mName << "     " << mPrice << "      " << quantity << "         " << aPrice ;
            }
            else if (aPrice >= 100 && aPrice < 1000){
                recordHolder << " " << mName << "     " << mPrice << "      " << quantity << "        " << aPrice ;
            }
            else if (aPrice >= 1000 && aPrice < 10000){
                recordHolder << " " << mName << "     " << mPrice << "      " << quantity << "       " << aPrice ;
            }
            else if (aPrice >= 10000 && aPrice < 100000){
                recordHolder << " " << mName << "     " << mPrice << "      " << quantity << "      " << aPrice ;
            }
            else if (aPrice >= 100000 && aPrice < 1000000){
                recordHolder << " " << mName << "     " << mPrice << "      " << quantity << "     " << aPrice ;
            }
            else{
                recordHolder << " " << mName << "     " << mPrice << "      " << quantity << "          " << aPrice ;
            }
        }
    }
    else{
        if (mPrice >= 10 && mPrice < 100){
            if (aPrice >= 10 && aPrice < 100){
                recordHolder << " " << mName << "    " << mPrice << "        " << quantity << "         " << aPrice ;
            }
            else if (aPrice >= 100 && aPrice < 1000){
                recordHolder << " " << mName << "    " << mPrice << "        " << quantity << "        " << aPrice ;
            }
            else if (aPrice >= 1000 && aPrice < 10000){
                recordHolder << " " << mName << "    " << mPrice << "        " << quantity << "       " << aPrice ;
            }
            else if (aPrice >= 10000 && aPrice < 100000){
                recordHolder << " " << mName << "    " << mPrice << "        " << quantity << "      " << aPrice ;
            }
            else if (aPrice >= 100000 && aPrice < 1000000){
                recordHolder << " " << mName << "    " << mPrice << "        " << quantity << "     " << aPrice;
            }
            else{
                recordHolder << " " << mName << "    " << mPrice << "        " << quantity << "          " << aPrice ;
            }

        }
        else if (mPrice >= 100 && mPrice < 1000){
            if (aPrice >= 10 && aPrice < 100){
                recordHolder << " " << mName << "   " << mPrice << "        " << quantity << "         " << aPrice ;
            }
            else if (aPrice >= 100 && aPrice < 1000){
                recordHolder << " " << mName << "   " << mPrice << "        " << quantity << "        " << aPrice ;
            }
            else if (aPrice >= 1000 && aPrice < 10000){
                recordHolder << " " << mName << "   " << mPrice << "        " << quantity << "       " << aPrice ;
            }
            else if (aPrice >= 10000 && aPrice < 100000){
                recordHolder << " " << mName << "   " << mPrice << "        " << quantity << "      " << aPrice ;
            }
            else if (aPrice >= 100000 && aPrice < 1000000){
                recordHolder << " " << mName << "   " << mPrice << "        " << quantity << "     " << aPrice ;
            }
            else{
                recordHolder << " " << mName << "   " << mPrice << "        " << quantity << "          " << aPrice ;
            }
        }
        else if (mPrice >= 1000 && mPrice < 10000){
            if (aPrice >= 10 && aPrice < 100){
                recordHolder << " " << mName << "  " << mPrice << "        " << quantity << "         " << aPrice ;
            }
            else if (aPrice >= 100 && aPrice < 1000){
                recordHolder << " " << mName << "  " << mPrice << "        " << quantity << "        " << aPrice ;
            }
            else if (aPrice >= 1000 && aPrice < 10000){
                recordHolder << " " << mName << "  " << mPrice << "        " << quantity << "       " << aPrice ;
            }
            else if (aPrice >= 10000 && aPrice < 100000){
                recordHolder << " " << mName << "  " << mPrice << "        " << quantity << "      " << aPrice ;
            }
            else if (aPrice >= 100000 && aPrice < 1000000){
                recordHolder << " " << mName << "  " << mPrice << "        " << quantity << "     " << aPrice ;
            }
            else{
                recordHolder << " " << mName << "  " << mPrice << "        " << quantity << "          " << aPrice ;
            }
        }
        else if (mPrice >= 10000 && mPrice < 100000){
            if (aPrice >= 10 && aPrice < 100){
                recordHolder << " " << mName << " " << mPrice << "        " << quantity << "         " << aPrice ;
            }
            else if (aPrice >= 100 && aPrice < 1000){
                recordHolder << " " << mName << " " << mPrice << "        " << quantity << "        " << aPrice ;
            }
            else if (aPrice >= 1000 && aPrice < 10000){
                recordHolder << " " << mName << " " << mPrice << "        " << quantity << "       " << aPrice ;
            }
            else if (aPrice >= 10000 && aPrice < 100000){
                recordHolder << " " << mName << " " << mPrice << "        " << quantity << "      " << aPrice ;
            }
            else if (aPrice >= 100000 && aPrice < 1000000){
                recordHolder << " " << mName << " " << mPrice << "        " << quantity << "     " << aPrice ;
            }
            else{
                recordHolder << " " << mName << " " << mPrice << "        " << quantity << "          " << aPrice ;
            }
        }
        else{
            if (aPrice >= 10 && aPrice < 100){
                recordHolder << " " << mName << "     " << mPrice << "        " << quantity << "         " << aPrice ;
            }
            else if (aPrice >= 100 && aPrice < 1000){
                recordHolder << " " << mName << "     " << mPrice << "        " << quantity << "        " << aPrice ;
            }
            else if (aPrice >= 1000 && aPrice < 10000){
                recordHolder << " " << mName << "     " << mPrice << "        " << quantity << "       " << aPrice ;
            }
            else if (aPrice >= 10000 && aPrice < 100000){
                recordHolder << " " << mName << "     " << mPrice << "        " << quantity << "      " << aPrice ;
            }
            else if (aPrice >= 100000 && aPrice < 1000000){
                recordHolder << " " << mName << "     " << mPrice << "        " << quantity << "     " << aPrice ;
            }
            else{
                recordHolder << " " << mName << "     " << mPrice << "        " << quantity << "          " << aPrice ;
            }
        }
    }
}
void PriceLinesDIS(){

    if (quantity >= 10 && quantity < 100){
        if (mPrice >= 10 && mPrice < 100){
            if (aPrice >= 10 && aPrice < 100){
                cout << " " << mName << "    " << mPrice << "       " << quantity << "         " << aPrice << endl;
            }
            else if (aPrice >= 100 && aPrice < 1000){
                cout << " " << mName << "    " << mPrice << "       " << quantity << "        " << aPrice << endl;
            }
            else if (aPrice >= 1000 && aPrice < 10000){
                cout << " " << mName << "    " << mPrice << "       " << quantity << "       " << aPrice << endl;
            }
            else if (aPrice >= 10000 && aPrice < 100000){
                cout << " " << mName << "    " << mPrice << "       " << quantity << "      " << aPrice << endl;
            }
            else if (aPrice >= 100000 && aPrice < 1000000){
                cout << " " << mName << "    " << mPrice << "       " << quantity << "     " << aPrice << endl;
            }
            else{
                cout << " " << mName << "    " << mPrice << "       " << quantity << "          " << aPrice << endl;
            }

        }
        else if (mPrice >= 100 && mPrice < 1000){
            if (aPrice >= 10 && aPrice < 100){
                cout << " " << mName << "   " << mPrice << "       " << quantity << "         " << aPrice << endl;
            }
            else if (aPrice >= 100 && aPrice < 1000){
                cout << " " << mName << "   " << mPrice << "       " << quantity << "        " << aPrice << endl;
            }
            else if (aPrice >= 1000 && aPrice < 10000){
                cout << " " << mName << "   " << mPrice << "       " << quantity << "       " << aPrice << endl;
            }
            else if (aPrice >= 10000 && aPrice < 100000){
                cout << " " << mName << "   " << mPrice << "       " << quantity << "      " << aPrice << endl;
            }
            else if (aPrice >= 100000 && aPrice < 1000000){
                cout << " " << mName << "   " << mPrice << "       " << quantity << "     " << aPrice << endl;
            }
            else{
                cout << " " << mName << "   " << mPrice << "       " << quantity << "          " << aPrice << endl;
            }
        }
        else if (mPrice >= 1000 && mPrice < 10000){
            if (aPrice >= 10 && aPrice < 100){
                cout << " " << mName << "  " << mPrice << "       " << quantity << "         " << aPrice << endl;
            }
            else if (aPrice >= 100 && aPrice < 1000){
                cout << " " << mName << "  " << mPrice << "       " << quantity << "        " << aPrice << endl;
            }
            else if (aPrice >= 1000 && aPrice < 10000){
                cout << " " << mName << "  " << mPrice << "       " << quantity << "       " << aPrice << endl;
            }
            else if (aPrice >= 10000 && aPrice < 100000){
                cout << " " << mName << "  " << mPrice << "       " << quantity << "      " << aPrice << endl;
            }
            else if (aPrice >= 100000 && aPrice < 1000000){
                cout << " " << mName << "  " << mPrice << "       " << quantity << "     " << aPrice << endl;
            }
            else{
                cout << " " << mName << "  " << mPrice << "       " << quantity << "          " << aPrice << endl;
            }
        }
        else if (mPrice >= 10000 && mPrice < 100000){
            if (aPrice >= 10 && aPrice < 100){
                cout << " " << mName << " " << mPrice << "       " << quantity << "         " << aPrice << endl;
            }
            else if (aPrice >= 100 && aPrice < 1000){
                cout << " " << mName << " " << mPrice << "       " << quantity << "        " << aPrice << endl;
            }
            else if (aPrice >= 1000 && aPrice < 10000){
                cout << " " << mName << " " << mPrice << "       " << quantity << "       " << aPrice << endl;
            }
            else if (aPrice >= 10000 && aPrice < 100000){
                cout << " " << mName << " " << mPrice << "       " << quantity << "      " << aPrice << endl;
            }
            else if (aPrice >= 100000 && aPrice < 1000000){
                cout << " " << mName << " " << mPrice << "       " << quantity << "     " << aPrice << endl;
            }
            else{
                cout << " " << mName << " " << mPrice << "       " << quantity << "          " << aPrice << endl;
            }
        }
        else{
            if (aPrice >= 10 && aPrice < 100){
                cout << " " << mName << "     " << mPrice << "       " << quantity << "         " << aPrice << endl;
            }
            else if (aPrice >= 100 && aPrice < 1000){
                cout << " " << mName << "     " << mPrice << "       " << quantity << "        " << aPrice << endl;
            }
            else if (aPrice >= 1000 && aPrice < 10000){
                cout << " " << mName << "     " << mPrice << "       " << quantity << "       " << aPrice << endl;
            }
            else if (aPrice >= 10000 && aPrice < 100000){
                cout << " " << mName << "     " << mPrice << "       " << quantity << "      " << aPrice << endl;
            }
            else if (aPrice >= 100000 && aPrice < 1000000){
                cout << " " << mName << "     " << mPrice << "       " << quantity << "     " << aPrice << endl;
            }
            else{
                cout << " " << mName << "     " << mPrice << "       " << quantity << "          " << aPrice << endl;
            }
        }
    }
    else if (quantity >= 100 && quantity < 1000){
        if (mPrice >= 10 && mPrice < 100){
            if (aPrice >= 10 && aPrice < 100){
                cout << " " << mName << "    " << mPrice << "      " << quantity << "         " << aPrice << endl;
            }
            else if (aPrice >= 100 && aPrice < 1000){
                cout << " " << mName << "    " << mPrice << "      " << quantity << "        " << aPrice << endl;
            }
            else if (aPrice >= 1000 && aPrice < 10000){
                cout << " " << mName << "    " << mPrice << "      " << quantity << "       " << aPrice << endl;
            }
            else if (aPrice >= 10000 && aPrice < 100000){
                cout << " " << mName << "    " << mPrice << "      " << quantity << "      " << aPrice << endl;
            }
            else if (aPrice >= 100000 && aPrice < 1000000){
                cout << " " << mName << "    " << mPrice << "      " << quantity << "     " << aPrice << endl;
            }
            else{
                cout << " " << mName << "    " << mPrice << "      " << quantity << "          " << aPrice << endl;
            }

        }
        else if (mPrice >= 100 && mPrice < 1000){
            if (aPrice >= 10 && aPrice < 100){
                cout << " " << mName << "   " << mPrice << "      " << quantity << "         " << aPrice << endl;
            }
            else if (aPrice >= 100 && aPrice < 1000){
                cout << " " << mName << "   " << mPrice << "      " << quantity << "        " << aPrice << endl;
            }
            else if (aPrice >= 1000 && aPrice < 10000){
                cout << " " << mName << "   " << mPrice << "      " << quantity << "       " << aPrice << endl;
            }
            else if (aPrice >= 10000 && aPrice < 100000){
                cout << " " << mName << "   " << mPrice << "      " << quantity << "      " << aPrice << endl;
            }
            else if (aPrice >= 100000 && aPrice < 1000000){
                cout << " " << mName << "   " << mPrice << "      " << quantity << "     " << aPrice << endl;
            }
            else{
                cout << " " << mName << "   " << mPrice << "      " << quantity << "          " << aPrice << endl;
            }
        }
        else if (mPrice >= 1000 && mPrice < 10000){
            if (aPrice >= 10 && aPrice < 100){
                cout << " " << mName << "  " << mPrice << "      " << quantity << "         " << aPrice << endl;
            }
            else if (aPrice >= 100 && aPrice < 1000){
                cout << " " << mName << "  " << mPrice << "      " << quantity << "        " << aPrice << endl;
            }
            else if (aPrice >= 1000 && aPrice < 10000){
                cout << " " << mName << "  " << mPrice << "      " << quantity << "       " << aPrice << endl;
            }
            else if (aPrice >= 10000 && aPrice < 100000){
                cout << " " << mName << "  " << mPrice << "      " << quantity << "      " << aPrice << endl;
            }
            else if (aPrice >= 100000 && aPrice < 1000000){
                cout << " " << mName << "  " << mPrice << "      " << quantity << "     " << aPrice << endl;
            }
            else{
                cout << " " << mName << "  " << mPrice << "      " << quantity << "          " << aPrice << endl;
            }
        }
        else if (mPrice >= 10000 && mPrice < 100000){
            if (aPrice >= 10 && aPrice < 100){
                cout << " " << mName << " " << mPrice << "      " << quantity << "         " << aPrice << endl;
            }
            else if (aPrice >= 100 && aPrice < 1000){
                cout << " " << mName << " " << mPrice << "      " << quantity << "        " << aPrice << endl;
            }
            else if (aPrice >= 1000 && aPrice < 10000){
                cout << " " << mName << " " << mPrice << "      " << quantity << "       " << aPrice << endl;
            }
            else if (aPrice >= 10000 && aPrice < 100000){
                cout << " " << mName << " " << mPrice << "      " << quantity << "      " << aPrice << endl;
            }
            else if (aPrice >= 100000 && aPrice < 1000000){
                cout << " " << mName << " " << mPrice << "      " << quantity << "     " << aPrice << endl;
            }
            else{
                cout << " " << mName << " " << mPrice << "      " << quantity << "          " << aPrice << endl;
            }
        }
        else{
            if (aPrice >= 10 && aPrice < 100){
                cout << " " << mName << "     " << mPrice << "      " << quantity << "         " << aPrice << endl;
            }
            else if (aPrice >= 100 && aPrice < 1000){
                cout << " " << mName << "     " << mPrice << "      " << quantity << "        " << aPrice << endl;
            }
            else if (aPrice >= 1000 && aPrice < 10000){
                cout << " " << mName << "     " << mPrice << "      " << quantity << "       " << aPrice << endl;
            }
            else if (aPrice >= 10000 && aPrice < 100000){
                cout << " " << mName << "     " << mPrice << "      " << quantity << "      " << aPrice << endl;
            }
            else if (aPrice >= 100000 && aPrice < 1000000){
                cout << " " << mName << "     " << mPrice << "      " << quantity << "     " << aPrice << endl;
            }
            else{
                cout << " " << mName << "     " << mPrice << "      " << quantity << "          " << aPrice << endl;
            }
        }
    }
    else{
        if (mPrice >= 10 && mPrice < 100){
            if (aPrice >= 10 && aPrice < 100){
                cout << " " << mName << "    " << mPrice << "        " << quantity << "         " << aPrice << endl;
            }
            else if (aPrice >= 100 && aPrice < 1000){
                cout << " " << mName << "    " << mPrice << "        " << quantity << "        " << aPrice << endl;
            }
            else if (aPrice >= 1000 && aPrice < 10000){
                cout << " " << mName << "    " << mPrice << "        " << quantity << "       " << aPrice << endl;
            }
            else if (aPrice >= 10000 && aPrice < 100000){
                cout << " " << mName << "    " << mPrice << "        " << quantity << "      " << aPrice << endl;
            }
            else if (aPrice >= 100000 && aPrice < 1000000){
                cout << " " << mName << "    " << mPrice << "        " << quantity << "     " << aPrice << endl;
            }
            else{
                cout << " " << mName << "    " << mPrice << "        " << quantity << "          " << aPrice << endl;
            }

        }
        else if (mPrice >= 100 && mPrice < 1000){
            if (aPrice >= 10 && aPrice < 100){
                cout << " " << mName << "   " << mPrice << "        " << quantity << "         " << aPrice << endl;
            }
            else if (aPrice >= 100 && aPrice < 1000){
                cout << " " << mName << "   " << mPrice << "        " << quantity << "        " << aPrice << endl;
            }
            else if (aPrice >= 1000 && aPrice < 10000){
                cout << " " << mName << "   " << mPrice << "        " << quantity << "       " << aPrice << endl;
            }
            else if (aPrice >= 10000 && aPrice < 100000){
                cout << " " << mName << "   " << mPrice << "        " << quantity << "      " << aPrice << endl;
            }
            else if (aPrice >= 100000 && aPrice < 1000000){
                cout << " " << mName << "   " << mPrice << "        " << quantity << "     " << aPrice << endl;
            }
            else{
                cout << " " << mName << "   " << mPrice << "        " << quantity << "          " << aPrice << endl;
            }
        }
        else if (mPrice >= 1000 && mPrice < 10000){
            if (aPrice >= 10 && aPrice < 100){
                cout << " " << mName << "  " << mPrice << "        " << quantity << "         " << aPrice << endl;
            }
            else if (aPrice >= 100 && aPrice < 1000){
                cout << " " << mName << "  " << mPrice << "        " << quantity << "        " << aPrice << endl;
            }
            else if (aPrice >= 1000 && aPrice < 10000){
                cout << " " << mName << "  " << mPrice << "        " << quantity << "       " << aPrice << endl;
            }
            else if (aPrice >= 10000 && aPrice < 100000){
                cout << " " << mName << "  " << mPrice << "        " << quantity << "      " << aPrice << endl;
            }
            else if (aPrice >= 100000 && aPrice < 1000000){
                cout << " " << mName << "  " << mPrice << "        " << quantity << "     " << aPrice << endl;
            }
            else{
                cout << " " << mName << "  " << mPrice << "        " << quantity << "          " << aPrice << endl;
            }
        }
        else if (mPrice >= 10000 && mPrice < 100000){
            if (aPrice >= 10 && aPrice < 100){
                cout << " " << mName << " " << mPrice << "        " << quantity << "         " << aPrice << endl;
            }
            else if (aPrice >= 100 && aPrice < 1000){
                cout << " " << mName << " " << mPrice << "        " << quantity << "        " << aPrice << endl;
            }
            else if (aPrice >= 1000 && aPrice < 10000){
                cout << " " << mName << " " << mPrice << "        " << quantity << "       " << aPrice << endl;
            }
            else if (aPrice >= 10000 && aPrice < 100000){
                cout << " " << mName << " " << mPrice << "        " << quantity << "      " << aPrice << endl;
            }
            else if (aPrice >= 100000 && aPrice < 1000000){
                cout << " " << mName << " " << mPrice << "        " << quantity << "     " << aPrice << endl;
            }
            else{
                cout << " " << mName << " " << mPrice << "        " << quantity << "          " << aPrice << endl;
            }
        }
        else{
            if (aPrice >= 10 && aPrice < 100){
                cout << " " << mName << "     " << mPrice << "        " << quantity << "         " << aPrice << endl;
            }
            else if (aPrice >= 100 && aPrice < 1000){
                cout << " " << mName << "     " << mPrice << "        " << quantity << "        " << aPrice << endl;
            }
            else if (aPrice >= 1000 && aPrice < 10000){
                cout << " " << mName << "     " << mPrice << "        " << quantity << "       " << aPrice << endl;
            }
            else if (aPrice >= 10000 && aPrice < 100000){
                cout << " " << mName << "     " << mPrice << "        " << quantity << "      " << aPrice << endl;
            }
            else if (aPrice >= 100000 && aPrice < 1000000){
                cout << " " << mName << "     " << mPrice << "        " << quantity << "     " << aPrice << endl;
            }
            else{
                cout << " " << mName << "     " << mPrice << "        " << quantity << "          " << aPrice << endl;
            }
        }
    }
}
void DPriceLinesTXT(){

    if (dlogQuantity >= 10 && dlogQuantity < 100){
        if (dlogPrice >= 10 && dlogPrice < 100){
            if (dlogAPrice >= 10 && dlogAPrice < 100){
                DrecordHolder << timeNow<< "    " << dlogName << "      " << dlogPrice << "       " << dlogQuantity << "         " << dlogAPrice ;
            }
            else if (dlogAPrice >= 100 && dlogAPrice < 1000){
                DrecordHolder << timeNow<< "    " << dlogName << "      " << dlogPrice << "       " << dlogQuantity << "        " << dlogAPrice ;
            }
            else if (dlogAPrice >= 1000 && dlogAPrice < 10000){
                DrecordHolder << timeNow<< "    " << dlogName << "      " << dlogPrice << "       " << dlogQuantity << "       " << dlogAPrice ;
            }
            else if (dlogAPrice >= 10000 && dlogAPrice < 100000){
                DrecordHolder << timeNow<< "    " << dlogName << "      " << dlogPrice << "       " << dlogQuantity << "      " << dlogAPrice ;
            }
            else if (dlogAPrice >= 100000 && dlogAPrice < 1000000){
                DrecordHolder << timeNow<< "    " << dlogName << "      " << dlogPrice << "       " << dlogQuantity << "     " << dlogAPrice ;
            }
            else{
                DrecordHolder << timeNow<< "    " << dlogName << "      " << dlogPrice << "       " << dlogQuantity << "          " << dlogAPrice ;
            }

        }
        else if (dlogPrice >= 100 && dlogPrice < 1000){
            if (dlogAPrice >= 10 && dlogAPrice < 100){
                DrecordHolder << timeNow<< "    " << dlogName << "     " << dlogPrice << "       " << dlogQuantity << "         " << dlogAPrice ;
            }
            else if (dlogAPrice >= 100 && dlogAPrice < 1000){
                DrecordHolder << timeNow<< "    " << dlogName << "     " << dlogPrice << "       " << dlogQuantity << "        " << dlogAPrice ;
            }
            else if (dlogAPrice >= 1000 && dlogAPrice < 10000){
                DrecordHolder << timeNow<< "    " << dlogName << "     " << dlogPrice << "       " << dlogQuantity << "       " << dlogAPrice ;
            }
            else if (dlogAPrice >= 10000 && dlogAPrice < 100000){
                DrecordHolder << timeNow<< "    " << dlogName << "     " << dlogPrice << "       " << dlogQuantity << "      " << dlogAPrice ;
            }
            else if (dlogAPrice >= 100000 && dlogAPrice < 1000000){
                DrecordHolder << timeNow<< "    " << dlogName << "     " << dlogPrice << "       " << dlogQuantity << "     " << dlogAPrice ;
            }
            else{
                DrecordHolder << timeNow<< "    " << dlogName << "     " << dlogPrice << "       " << dlogQuantity << "          " << dlogAPrice ;
            }
        }
        else if (dlogPrice >= 1000 && dlogPrice < 10000){
            if (dlogAPrice >= 10 && dlogAPrice < 100){
                DrecordHolder << timeNow<< "    " << dlogName << "    " << dlogPrice << "       " << dlogQuantity << "         " << dlogAPrice;
            }
            else if (dlogAPrice >= 100 && dlogAPrice < 1000){
                DrecordHolder << timeNow<< "    " << dlogName << "    " << dlogPrice << "       " << dlogQuantity << "        " << dlogAPrice;
            }
            else if (dlogAPrice >= 1000 && dlogAPrice < 10000){
                DrecordHolder << timeNow<< "    " << dlogName << "    " << dlogPrice << "       " << dlogQuantity << "       " << dlogAPrice ;
            }
            else if (dlogAPrice >= 10000 && dlogAPrice < 100000){
                DrecordHolder << timeNow<< "    " << dlogName << "    " << dlogPrice << "       " << dlogQuantity << "      " << dlogAPrice;
            }
            else if (dlogAPrice >= 100000 && dlogAPrice < 1000000){
                DrecordHolder << timeNow<< "    " << dlogName << "    " << dlogPrice  << "       " << dlogQuantity << "     " << dlogAPrice ;
            }
            else{
                DrecordHolder << timeNow<< "    " << dlogName << "    " << dlogPrice  << "       " << dlogQuantity << "          " << dlogAPrice;
            }
        }
        else if (dlogPrice  >= 10000 && dlogPrice  < 100000){
            if (dlogAPrice >= 10 && dlogAPrice < 100){
                DrecordHolder << timeNow<< "    " << dlogName << "   " << dlogPrice  << "       " << dlogQuantity << "         " << dlogAPrice ;
            }
            else if (dlogAPrice >= 100 && dlogAPrice < 1000){
                DrecordHolder << timeNow<< "    " << dlogName << "   " << dlogPrice  << "       " << dlogQuantity << "        " << dlogAPrice ;
            }
            else if (dlogAPrice >= 1000 && dlogAPrice < 10000){
                DrecordHolder << timeNow<< "    " << dlogName << "   " << dlogPrice  << "       " << dlogQuantity << "       " << dlogAPrice ;
            }
            else if (dlogAPrice >= 10000 && dlogAPrice < 100000){
                DrecordHolder << timeNow<< "    " << dlogName << "   " << dlogPrice  << "       " << dlogQuantity << "      " << dlogAPrice ;
            }
            else if (dlogAPrice >= 100000 && dlogAPrice < 1000000){
                DrecordHolder << timeNow<< "    " << dlogName << "   " << dlogPrice  << "       " << dlogQuantity << "     " << dlogAPrice ;
            }
            else{
                DrecordHolder << timeNow<< "    " << dlogName << "   " << dlogPrice  << "       " << dlogQuantity << "          " << dlogAPrice;
            }
        }
        else{
            if (dlogAPrice >= 10 && dlogAPrice < 100){
                DrecordHolder << timeNow<< "    " << dlogName << "       " << dlogPrice  << "       " << dlogQuantity << "         " << dlogAPrice ;
            }
            else if (dlogAPrice >= 100 && dlogAPrice < 1000){
                DrecordHolder << timeNow<< "    " << dlogName << "       " << dlogPrice  << "       " << dlogQuantity << "        " << dlogAPrice ;
            }
            else if (dlogAPrice >= 1000 && dlogAPrice < 10000){
                DrecordHolder << timeNow<< "    " << dlogName << "       " << dlogPrice  << "       " << dlogQuantity << "       " << dlogAPrice ;
            }
            else if (dlogAPrice >= 10000 && dlogAPrice < 100000){
                DrecordHolder << timeNow<< "    " << dlogName << "       " << dlogPrice  << "       " << dlogQuantity << "      " << dlogAPrice ;
            }
            else if (dlogAPrice >= 100000 && dlogAPrice < 1000000){
                DrecordHolder << timeNow<< "    " << dlogName << "       " << dlogPrice  << "       " << dlogQuantity << "     " << dlogAPrice ;
            }
            else{
                DrecordHolder << timeNow<< "    " << dlogName << "       " << dlogPrice  << "       " << dlogQuantity << "          " << dlogAPrice ;
            }
        }
    }
    else if (dlogQuantity >= 100 && dlogQuantity < 1000){
        if (dlogPrice  >= 10 && dlogPrice  < 100){
            if (dlogAPrice >= 10 && dlogAPrice < 100){
                DrecordHolder << timeNow<< "    " << dlogName << "      " << dlogPrice  << "      " << dlogQuantity << "         " << dlogAPrice ;
            }
            else if (dlogAPrice >= 100 && dlogAPrice < 1000){
                DrecordHolder << timeNow<< "    " << dlogName << "      " << dlogPrice  << "      " << dlogQuantity << "        " << dlogAPrice ;
            }
            else if (dlogAPrice >= 1000 && dlogAPrice < 10000){
                DrecordHolder << timeNow<< "    " << dlogName << "      " << dlogPrice  << "      " << dlogQuantity << "       " << dlogAPrice ;
            }
            else if (dlogAPrice >= 10000 && dlogAPrice < 100000){
                DrecordHolder << timeNow<< "    " << dlogName << "      " << dlogPrice  << "      " << dlogQuantity << "      " << dlogAPrice ;
            }
            else if (dlogAPrice >= 100000 && dlogAPrice < 1000000){
                DrecordHolder << timeNow<< "    " << dlogName << "      " << dlogPrice  << "      " << dlogQuantity << "     " << dlogAPrice ;
            }
            else{
                DrecordHolder << timeNow<< "    " << dlogName << "      " << dlogPrice  << "      " << dlogQuantity << "          " << dlogAPrice ;
            }

        }
        else if (dlogPrice  >= 100 && dlogPrice  < 1000){
            if (dlogAPrice >= 10 && dlogAPrice < 100){
                DrecordHolder << timeNow<< "    " << dlogName << "     " << dlogPrice  << "      " << dlogQuantity << "         " << dlogAPrice ;
            }
            else if (dlogAPrice >= 100 && dlogAPrice < 1000){
                DrecordHolder << timeNow<< "    " << dlogName << "     " << dlogPrice  << "      " << dlogQuantity << "        " << dlogAPrice ;
            }
            else if (dlogAPrice >= 1000 && dlogAPrice < 10000){
                DrecordHolder << timeNow<< "    " << dlogName << "     " << dlogPrice  << "      " << dlogQuantity << "       " << dlogAPrice ;
            }
            else if (dlogAPrice >= 10000 && dlogAPrice < 100000){
                DrecordHolder << timeNow<< "    " << dlogName << "     " << dlogPrice  << "      " << dlogQuantity << "      " << dlogAPrice ;
            }
            else if (dlogAPrice >= 100000 && dlogAPrice < 1000000){
                DrecordHolder << timeNow<< "    " << dlogName << "     " << dlogPrice  << "      " << dlogQuantity << "     " << dlogAPrice ;
            }
            else{
                DrecordHolder << timeNow<< "    " << dlogName << "     " << dlogPrice  << "      " << dlogQuantity << "          " << dlogAPrice;
            }
        }
        else if (dlogPrice  >= 1000 && dlogPrice  < 10000){
            if (dlogAPrice >= 10 && dlogAPrice < 100){
                DrecordHolder << timeNow<< "    " << dlogName << "    " << dlogPrice  << "      " << dlogQuantity << "         " << dlogAPrice ;
            }
            else if (dlogAPrice >= 100 && dlogAPrice < 1000){
                DrecordHolder << timeNow<< "    " << dlogName << "    " << dlogPrice  << "      " << dlogQuantity << "        " << dlogAPrice ;
            }
            else if (dlogAPrice >= 1000 && dlogAPrice < 10000){
                DrecordHolder << timeNow<< "    " << dlogName << "    " << dlogPrice  << "      " << dlogQuantity << "       " << dlogAPrice ;
            }
            else if (dlogAPrice >= 10000 && dlogAPrice < 100000){
                DrecordHolder << timeNow<< "    " << dlogName << "    " << dlogPrice  << "      " << dlogQuantity << "      " << dlogAPrice ;
            }
            else if (dlogAPrice >= 100000 && dlogAPrice < 1000000){
                DrecordHolder << timeNow<< "    " << dlogName << "    " << dlogPrice  << "      " << dlogQuantity << "     " << dlogAPrice ;
            }
            else{
                DrecordHolder << timeNow<< "    " << dlogName << "    " << dlogPrice  << "      " << dlogQuantity << "          " << dlogAPrice ;
            }
        }
        else if (dlogPrice  >= 10000 && dlogPrice  < 100000){
            if (dlogAPrice >= 10 && dlogAPrice < 100){
                DrecordHolder << timeNow<< "    " << dlogName << "   " << dlogPrice  << "      " << dlogQuantity << "         " << dlogAPrice ;
            }
            else if (dlogAPrice >= 100 && dlogAPrice < 1000){
                DrecordHolder << timeNow<< "    " << dlogName << "   " << dlogPrice  << "      " << dlogQuantity << "        " << dlogAPrice ;
            }
            else if (dlogAPrice >= 1000 && dlogAPrice < 10000){
                DrecordHolder << timeNow<< "    " << dlogName << "   " << dlogPrice  << "      " << dlogQuantity << "       " << dlogAPrice ;
            }
            else if (dlogAPrice >= 10000 && dlogAPrice < 100000){
                DrecordHolder << timeNow<< "    " << dlogName << "   " << dlogPrice  << "      " << dlogQuantity << "      " << dlogAPrice ;
            }
            else if (dlogAPrice >= 100000 && dlogAPrice < 1000000){
                DrecordHolder << timeNow<< "    " << dlogName << "   " << dlogPrice  << "      " << dlogQuantity << "     " << dlogAPrice ;
            }
            else{
                DrecordHolder << timeNow<< "    " << dlogName << "   " << dlogPrice  << "      " << dlogQuantity << "          " << dlogAPrice ;
            }
        }
        else{
            if (dlogAPrice >= 10 && dlogAPrice < 100){
                DrecordHolder << timeNow<< "    " << dlogName << "       " << dlogPrice  << "      " << dlogQuantity << "         " << dlogAPrice ;
            }
            else if (dlogAPrice >= 100 && dlogAPrice < 1000){
                DrecordHolder << timeNow<< "    " << dlogName << "       " << dlogPrice  << "      " << dlogQuantity << "        " << dlogAPrice ;
            }
            else if (dlogAPrice >= 1000 && dlogAPrice < 10000){
                DrecordHolder << timeNow<< "    " << dlogName << "       " << dlogPrice  << "      " << dlogQuantity << "       " << dlogAPrice ;
            }
            else if (dlogAPrice >= 10000 && dlogAPrice < 100000){
                DrecordHolder << timeNow<< "    " << dlogName << "       " << dlogPrice  << "      " << dlogQuantity << "      " << dlogAPrice ;
            }
            else if (dlogAPrice >= 100000 && dlogAPrice < 1000000){
                DrecordHolder << timeNow<< "    " << dlogName << "       " << dlogPrice  << "      " << dlogQuantity << "     " << dlogAPrice ;
            }
            else{
                DrecordHolder << timeNow<< "    " << dlogName << "       " << dlogPrice  << "      " << dlogQuantity << "          " << dlogAPrice ;
            }
        }
    }
    else{
        if (dlogPrice  >= 10 && dlogPrice  < 100){
            if (dlogAPrice >= 10 && dlogAPrice < 100){
                DrecordHolder << timeNow<< "    " << dlogName << "      " << dlogPrice  << "        " << dlogQuantity << "         " << dlogAPrice ;
            }
            else if (dlogAPrice >= 100 && dlogAPrice < 1000){
                DrecordHolder << timeNow<< "    " << dlogName << "      " << dlogPrice  << "        " << dlogQuantity << "        " << dlogAPrice ;
            }
            else if (dlogAPrice >= 1000 && dlogAPrice < 10000){
                DrecordHolder << timeNow<< "    " << dlogName << "      " << dlogPrice  << "        " << dlogQuantity << "       " << dlogAPrice ;
            }
            else if (dlogAPrice >= 10000 && dlogAPrice < 100000){
                DrecordHolder << timeNow<< "    " << dlogName << "      " << dlogPrice  << "        " << dlogQuantity << "      " << dlogAPrice ;
            }
            else if (dlogAPrice >= 100000 && dlogAPrice < 1000000){
                DrecordHolder << timeNow<< "    " << dlogName << "      " << dlogPrice  << "        " << dlogQuantity << "     " << dlogAPrice;
            }
            else{
                DrecordHolder << timeNow<< "    " << dlogName << "      " << dlogPrice  << "        " << dlogQuantity << "          " << dlogAPrice ;
            }

        }
        else if (dlogPrice  >= 100 && dlogPrice  < 1000){
            if (dlogAPrice >= 10 && dlogAPrice < 100){
                DrecordHolder << timeNow<< "    " << dlogName << "     " << dlogPrice  << "        " << dlogQuantity << "         " << dlogAPrice ;
            }
            else if (dlogAPrice >= 100 && dlogAPrice < 1000){
                DrecordHolder << timeNow<< "    " << dlogName << "     " << dlogPrice  << "        " << dlogQuantity << "        " << dlogAPrice ;
            }
            else if (dlogAPrice >= 1000 && dlogAPrice < 10000){
                DrecordHolder << timeNow<< "    " << dlogName << "     " << dlogPrice  << "        " << dlogQuantity << "       " << dlogAPrice ;
            }
            else if (dlogAPrice >= 10000 && dlogAPrice < 100000){
                DrecordHolder << timeNow<< "    " << dlogName << "     " << dlogPrice  << "        " << dlogQuantity << "      " << dlogAPrice ;
            }
            else if (dlogAPrice >= 100000 && dlogAPrice < 1000000){
                DrecordHolder << timeNow<< "    " << dlogName << "     " << dlogPrice  << "        " << dlogQuantity << "     " << dlogAPrice ;
            }
            else{
                DrecordHolder << timeNow<< "    " << dlogName << "     " << dlogPrice  << "        " << dlogQuantity << "          " << dlogAPrice ;
            }
        }
        else if (dlogPrice  >= 1000 && dlogPrice  < 10000){
            if (dlogAPrice >= 10 && dlogAPrice < 100){
                DrecordHolder << timeNow<< "    " << dlogName << "    " << dlogPrice  << "        " << dlogQuantity << "         " << dlogAPrice ;
            }
            else if (dlogAPrice >= 100 && dlogAPrice < 1000){
                DrecordHolder << timeNow<< "    " << dlogName << "    " << dlogPrice  << "        " << dlogQuantity << "        " << dlogAPrice ;
            }
            else if (dlogAPrice >= 1000 && dlogAPrice < 10000){
                DrecordHolder << timeNow<< "    " << dlogName << "    " << dlogPrice  << "        " << dlogQuantity << "       " << dlogAPrice ;
            }
            else if (dlogAPrice >= 10000 && dlogAPrice < 100000){
                DrecordHolder << timeNow<< "    " << dlogName << "    " << dlogPrice  << "        " << dlogQuantity << "      " << dlogAPrice ;
            }
            else if (dlogAPrice >= 100000 && dlogAPrice < 1000000){
                DrecordHolder << timeNow<< "    " << dlogName << "    " << dlogPrice  << "        " << dlogQuantity << "     " << dlogAPrice ;
            }
            else{
                DrecordHolder << timeNow<< "    " << dlogName << "    " << dlogPrice  << "        " << dlogQuantity << "          " << dlogAPrice ;
            }
        }
        else if (dlogPrice  >= 10000 && dlogPrice  < 100000){
            if (dlogAPrice >= 10 && dlogAPrice < 100){
                DrecordHolder << timeNow<< "    " << dlogName << "   " << dlogPrice  << "        " << dlogQuantity << "         " << dlogAPrice ;
            }
            else if (dlogAPrice >= 100 && dlogAPrice < 1000){
                DrecordHolder << timeNow<< "    " << dlogName << "   " << dlogPrice  << "        " << dlogQuantity << "        " << dlogAPrice ;
            }
            else if (dlogAPrice >= 1000 && dlogAPrice < 10000){
                DrecordHolder << timeNow<< "    " << dlogName << "   " << dlogPrice  << "        " << dlogQuantity << "       " << dlogAPrice ;
            }
            else if (dlogAPrice >= 10000 && dlogAPrice < 100000){
                DrecordHolder << timeNow<< "    " << dlogName << "   " << dlogPrice  << "        " << dlogQuantity << "      " << dlogAPrice ;
            }
            else if (dlogAPrice >= 100000 && dlogAPrice < 1000000){
                DrecordHolder << timeNow<< "    " << dlogName << "   " << dlogPrice  << "        " << dlogQuantity << "     " << dlogAPrice ;
            }
            else{
                DrecordHolder << timeNow<< "    " << dlogName << "   " << dlogPrice  << "        " << dlogQuantity << "          " << dlogAPrice ;
            }
        }
        else{
            if (dlogAPrice >= 10 && dlogAPrice < 100){
                DrecordHolder << timeNow<< "    " << dlogName << "       " << dlogPrice  << "        " << dlogQuantity << "         " << dlogAPrice ;
            }
            else if (dlogAPrice >= 100 && dlogAPrice < 1000){
                DrecordHolder << timeNow<< "    " << dlogName << "       " << dlogPrice  << "        " << dlogQuantity << "        " << dlogAPrice ;
            }
            else if (dlogAPrice >= 1000 && dlogAPrice < 10000){
                DrecordHolder << timeNow<< "    " << dlogName << "       " << dlogPrice  << "        " << dlogQuantity << "       " << dlogAPrice ;
            }
            else if (dlogAPrice >= 10000 && dlogAPrice < 100000){
                DrecordHolder << timeNow<< "    " << dlogName << "       " << dlogPrice  << "        " << dlogQuantity << "      " << dlogAPrice ;
            }
            else if (dlogAPrice >= 100000 && dlogAPrice < 1000000){
                DrecordHolder << timeNow<< "    " << dlogName << "       " << dlogPrice  << "        " << dlogQuantity << "     " << dlogAPrice ;
            }
            else{
                DrecordHolder << timeNow<< "    " << mName << "       " << dlogPrice  << "        " << dlogQuantity << "          " << dlogAPrice ;
            }
        }
    }
}
void DOPriceLinesTXT(){

    if (priceOther >= 0 && priceOther < 10){

        int zz = 36 - noteOther.length();
        for (int x = 0; x < zz; x++){
            noteOther.append("-");
        }
        DOrecordHolder << timeNow << "    " << noteOther <<  "       " << priceOther ;
    }
    else if (priceOther >= 10 && priceOther < 100){
        int zz = 36 - noteOther.length();
        for (int x = 0; x < zz; x++){
            noteOther.append("-");
        }
        DOrecordHolder << timeNow << "    " << noteOther <<  "      " << priceOther ;
    }
    else if (priceOther >= 100 && priceOther < 1000){
        int zz = 36 - noteOther.length();
        for (int x = 0; x < zz; x++){
            noteOther.append("-");
        }
        DOrecordHolder << timeNow << "    " << noteOther <<  "     " << priceOther ;
    }
    else if (priceOther >= 1000 && priceOther < 10000){
        int zz = 36 - noteOther.length();
        for (int x = 0; x < zz; x++){
            noteOther.append("-");
        }
        DOrecordHolder << timeNow << "    " << noteOther <<  "    " << priceOther ;
    }
    else if (priceOther >= 10000 && priceOther < 100000){
        int zz = 36 - noteOther.length();
        for (int x = 0; x < zz; x++){
            noteOther.append("-");
        }
        DOrecordHolder << timeNow << "    " << noteOther <<  "   " << priceOther ;
    }
    else {
        int zz = 36 - noteOther.length();
        for (int x = 0; x < zz; x++){
            noteOther.append("-");
        }
        DOrecordHolder << timeNow << "    " << noteOther <<  "  " << priceOther ;
    }

}
void DOPriceLinesTXTOut(){
    if (priceOther >= 0 && priceOther < 10){

        int zz = 36 - noteOther.length();
        for (int x = 0; x < zz; x++){
            noteOther.append("-");
        }
        DOrecordHolderOut << timeNow << "    " << noteOther <<  "      -" << priceOther ;
    }
    else if (priceOther >= 10 && priceOther < 100){
        int zz = 36 - noteOther.length();
        for (int x = 0; x < zz; x++){
            noteOther.append("-");
        }
        DOrecordHolderOut << timeNow << "    " << noteOther <<  "     -" << priceOther ;
    }
    else if (priceOther >= 100 && priceOther < 1000){
        int zz = 36 - noteOther.length();
        for (int x = 0; x < zz; x++){
            noteOther.append("-");
        }
        DOrecordHolderOut << timeNow << "    " << noteOther <<  "    -" << priceOther ;
    }
    else if (priceOther >= 1000 && priceOther < 10000){
        int zz = 36 - noteOther.length();
        for (int x = 0; x < zz; x++){
            noteOther.append("-");
        }
        DOrecordHolderOut << timeNow << "    " << noteOther <<  "   -" << priceOther ;
    }
    else if (priceOther >= 10000 && priceOther < 100000){
        int zz = 36 - noteOther.length();
        for (int x = 0; x < zz; x++){
            noteOther.append("-");
        }
        DOrecordHolderOut << timeNow << "    " << noteOther <<  "  -" << priceOther ;
    }
    else {
        int zz = 36 - noteOther.length();
        for (int x = 0; x < zz; x++){
            noteOther.append("-");
        }
        DOrecordHolderOut << timeNow << "    " << noteOther <<  " -" << priceOther ;
    }


}
void StartCash(){
    if (startCash >= 0 && startCash < 10){
        StartCashHolder <<  "Cash have at start of the day:" << "                  "  <<  "       " << startCash ;
    }
    else if (startCash >= 10 && startCash < 100){
        StartCashHolder <<  "Cash have at start of the day:" << "                  "  <<  "      " << startCash ;
    }
    else if (startCash >= 100 && startCash < 1000){
        StartCashHolder <<  "Cash have at start of the day:" << "                  "  <<  "     " << startCash ;
    }
    else if (startCash >= 1000 && startCash < 10000){
        StartCashHolder <<  "Cash have at start of the day:" << "                  "  <<  "    " << startCash ;
    }
    else if (startCash >= 10000 && startCash < 100000){
        StartCashHolder <<  "Cash have at start of the day:" << "                  "  <<  "   " << startCash ;
    }
    else {
        StartCashHolder <<  "Cash have at start of the day:" << "                  "  <<  "  " << startCash ;
    }
}
void DailyReportCreation(){

    if (oPaid >= 0 && oPaid < 10){
        TotalPaidAmount <<  "Total Paid Amount:" << "                              "  <<  "       " << oPaid ; //30,27,20
    }
    else if (oPaid >= 10 && oPaid < 100){
        TotalPaidAmount <<  "Total Paid Amount:" << "                              "  <<  "      " << oPaid ;
    }
    else if (oPaid >= 100 && oPaid < 1000){
        TotalPaidAmount <<  "Total Paid Amount:" << "                              "  <<  "     " << oPaid ;
    }
    else if (oPaid >= 1000 && oPaid < 10000){
        TotalPaidAmount <<  "Total Paid Amount:" << "                              "  <<  "    " << oPaid ;
    }
    else if (oPaid >= 10000 && oPaid < 100000){
        TotalPaidAmount <<  "Total Paid Amount:" << "                              "  <<  "   " << oPaid ;
    }
    else {
        TotalPaidAmount <<  "Total Paid Amount:" << "                              "  <<  "  " << oPaid ;
    }


    if (gReceved >= 0 && gReceved < 10){
        TotalRecevedAmount <<  "Total Receved Amount:" << "                           "  <<  "       " << gReceved ; //27,20
    }
    else if (gReceved >= 10 && gReceved < 100){
        TotalRecevedAmount <<  "Total Receved Amount:" << "                           "  <<  "      " << gReceved ;
    }
    else if (gReceved >= 100 && gReceved < 1000){
        TotalRecevedAmount <<  "Total Receved Amount:" << "                           "  <<  "     " << gReceved ;
    }
    else if (gReceved >= 1000 && gReceved < 10000){
        TotalRecevedAmount <<  "Total Receved Amount:" << "                           "  <<  "    " << gReceved ;
    }
    else if (gReceved >= 10000 && gReceved < 100000){
        TotalRecevedAmount <<  "Total Receved Amount:" << "                           "  <<  "   " << gReceved ;
    }
    else {
        TotalRecevedAmount <<  "Total Receved Amount:" << "                           "  <<  "  " << gReceved ;
    }


    if (grandTotal >= 0 && grandTotal < 10){
        CashHaveAtEndOfTheDay <<  "Cash Have At End Of The Day:" << "                    "  <<  "       " << grandTotal ; //20
    }
    else if (grandTotal >= 10 && grandTotal < 100){
        CashHaveAtEndOfTheDay <<  "Cash Have At End Of The Day:" << "                    "  <<  "      " << grandTotal ;
    }
    else if (grandTotal >= 100 && grandTotal < 1000){
        CashHaveAtEndOfTheDay <<  "Cash Have At End Of The Day:" << "                    "  <<  "     " << grandTotal ;
    }
    else if (grandTotal >= 1000 && grandTotal < 10000){
        CashHaveAtEndOfTheDay <<  "Cash Have At End Of The Day:" << "                    "  <<  "    " << grandTotal ;
    }
    else if (grandTotal >= 10000 && grandTotal < 100000){
        CashHaveAtEndOfTheDay <<  "Cash Have At End Of The Day:" << "                    "  <<  "   " << grandTotal ;
    }
    else {
        CashHaveAtEndOfTheDay <<  "Cash Have At End Of The Day:" << "                    "  <<  "  " << grandTotal ;
    }

}
