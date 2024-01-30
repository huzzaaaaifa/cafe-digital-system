#include "proj.h"
#include "Adm.h"
char adminUserName[20];
char adminPassword[20];



void admWelcome()
{

                    cout<<endl;
                    cout << "\t\t-------------------------------------------------------------" << endl;
                    cout << "\t\t|                                                           |" << endl;
                    cout << "\t\t|          [Welcome Admin Saab]  [KHUSH AMDEED]             |" << endl;
                    cout << "\t\t|                                                           |" << endl;
                    cout << "\t\t------------------------------------------------------------" << endl;
                    
                    cout<<endl;
  
  
}

void loginPageAdm()
{
                    
                    // login page
                    int ch,count;
                    cin.ignore();
                    cout<<"\n\t\t             [LOGIN PAGE] \n";
                    cout << "\t\t--------------------------------------------" << endl;
                    cout << "\t\t|                                          |" << endl;
                    cout << "\t\t|     Enter Credentials to Proceed         |" << endl;
                    cout << "\t\t|                                          |" << endl;
                    cout << "\t\t|      UserName : ";                   
                    cin.getline(adminUserName,20);
                    cout << "\t\t|      Password : ";
                    cin.getline(adminPassword,20);
                    cout << "\t\t|                                          |" << endl;
                    cout << "\t\t|                                          |" << endl;
                    cout << "\t\t--------------------------------------------" << endl;
                     
                     //passing to function to check if correct

                    count=adminLogin(adminUserName,adminPassword);
                    
                    if(count==2)  // agar 2 return ho to login hojae
                    {
                        waitSuccess();
                        return;
                    }
                    else
                    {                // agar kuch aur ho to login fail aur choice dede
                     
                         waitFail();
                       
                         ch=failChoice();
                          
                       // choice
                       if(ch>=1 && ch<=2)
                        {
                            // agar exit choose kia ho to exit hojae
                            if(ch==1)
                            {
                                   exitmsg();
                                   exit(0);

                            }


                            else
                            {     // agar dobara login choose kia ho
                                loginPageAdm();

                            }

             
                         }
                           // range k bahir kelye error
                     else if((ch<1 || ch>2) )
                     {
                   
                       cin.clear();
                       cin.ignore();
                       rangeerror();  
                
                     }
              
                 }
                    while(ch<1 || ch>10);
            
}

// admin k functions ka menu
int adminMenu()
{
    int ch;
     do
             {
    cout << "\t\t----------------------------------------------------------------------------------" << endl;
                    cout << "\t\t|                                                                                |" << endl;
                    cout << "\t\t|     You are Authorized to do Following Operations ::                           |" << endl;
                    cout << "\t\t|     Press 1 : See  cafe stock in hand                                          |" << endl;
                    cout << "\t\t|     Press 2 : Check If an Item is lower than a threshold value                 |" << endl;
                    cout << "\t\t|     Press 3 : See Sales                                                        |" << endl;
                    cout << "\t\t|     Press 4 : Search, add, remove, and update any item in the stock.           |" << endl;
                    cout << "\t\t|     Press 5 : Add remove credentials of employees and student/staff(if any)    |" << endl;
                    cout << "\t\t|     Press 6 : Display notifications                                            |" << endl;
                    cout << "\t\t|     Press 7 : See online/scheduled orders                                      |" << endl;
                    cout << "\t\t|     Press 8 : See complaints                                                   |" << endl;
                    cout << "\t\t|     Press 9 : See bestseller employee.                                         |" << endl;
                    cout << "\t\t|     Press 10 : Change Admin UserName or Password                               |" << endl;
                    cout << "\t\t|     Press 11 : See high and low sold items                                     |" << endl;
                    cout << "\t\t|     Press 12 : Return to CDS Menu                                              |" << endl;
                    cout << "\t\t|                                                                                |" << endl;
                    cout << "\t\t----------------------------------------------------------------------------------" << endl;
                    cin>>ch;

         
               
                     // agr 1 sa 12 k darmian enter karay to return kr dy
                    if(ch>=1 && ch<=12)
                   {
             
                      break;
             
                   }
                     // nahi to bar bar le jb tk sahi value na dale
                else if((ch<1 || ch>12) )
                   {
                   
                     cin.clear();
                     cin.ignore();
                     rangeerror();
                     continue;
                   }
              
                 }
                    while(ch<1 || ch>12);
         // choice return krde
         return ch;


}
  // high and low sold items dekhne kelye
void seehighlowSales()
{
   
     
    char HDR[100];
    int* item_ID;
    char** Names;
    int* Sales;
    double* Average;
    int tot_lines=0;
    char lines[100];

    fstream salesTrack;
     
    salesTrack.open("SalesRecord.txt",ios::in);     // file kholi reading mode me

    if(!salesTrack)   //check kr rha hu agr open ni hui to error de  de
    {
      fileError();
    }
    
    else
    {

         while(salesTrack.getline(lines,100))   // lines count krne kelye
         {
            tot_lines++;
         }

           salesTrack.clear();    // error flag ko clear krne kelye
           salesTrack.seekg(0,ios::beg);    // pointer ko wapis shuru me lanay kelye

         const int size = tot_lines-1;    // first line header ha to usko exclude krdia

         item_ID = new int[size];
         Names = new char*[size];
         Sales = new int[size];        // dynamically 2d aur 1d arrays initialize krte hue
         Average = new double[size];

         for(int i=0; i<size; i++)
         {
            Names[i]= new char[32];         
         }

         int j=0;

         salesTrack.getline(HDR,100,'\n');         // pehli line ko HDR me store krwa lia

         while(salesTrack>>item_ID[j])         // next line me sbse pehle id store krwai
         {
            salesTrack.ignore();                        
            salesTrack.getline(Names[j],32,',');    // phr , comma tk item ka name Names me store krwaya
            salesTrack>>Sales[j]>>Average[j];           // aur next spaces k bd sales aur average store krwa di
            j++;
         }

         salesTrack.close();     // file close krdi
  
          int max;
         
         max=Sales[0];      // let kia sales[0] pe jo value ha wo sb sa barhi ha aur max me store krdi
         int k;
         int p=0;
 
         for(k=1; k<size; k++)
         {
            if(Sales[k]>max)         // check kr rha hu konsi value max sa barhi ha
            {  
               max=Sales[k];   // jo barhi ha wo max me store krdi
               p=k;          // aur index record krdia
            }
            else
            {
               continue;
            }
         }
         char highitem[32];      
         int sold;

         for(int i=0; i<size; i++)
         {
            if(i==p)   // jis index pa max mili
            {
               strcpy(highitem,Names[i]);   // uska naam highitem me copy krdia
               sold=Sales[i];      // aur uski sales sold me store krdi
            }
         }
              // display krwa di high sold item
         cout<<"\n\n\t\tHigh Sold item is : "<<highitem<<endl;   
         cout<<"\n\t\t Number of items sold : "<<sold;

         int min;
         int pos=0;
         
         min=Sales[0];   // let kia sales[0] pe sb sy choti value ha aur usy min me store krwadia

         for(int k=1; k<size; k++)
         {
            if(Sales[k]<min)   // check kia k knsi choti ha min sa
            {
               min=Sales[k];    // agr ha koi to min me store krdia
               pos=k;        // aur index record krdia
            }
            else
            {
               continue;
            }
         }
         char lowitem[32];
         int soldlow;

         for(int i=0; i<size; i++)
         {
            if(i==pos)        // jis index pe minimum mili
            {
               strcpy(lowitem,Names[i]);     // uska name copy krdia lowitem me
               soldlow=Sales[i];   // aur sales store krdi soldlow me
            }
         }
               // display krwa di
         cout<<"\n\n\t\tLow Sold item is : "<<lowitem<<endl;
         cout<<"\n\t\t Number of items sold : "<<soldlow<<endl;

       // dynamic arrrays delete krty huye
         for(int i=0; i<size; i++)
         {
            delete[]Names[i];
         } 

 
         delete[]item_ID; 
         delete[]Names;
         delete[]Sales; 
         delete[]Average;

          

  

    }

    cin.ignore();
    cout<<"\n\n\t\tPress enter to continue ...";
    cin.get();

}

int checkThresholdNotif()
{
    int c;

    int totLines=0;

   char HDR[100];
   char** name;
   int* price;          // pointers declare kiye
   int* quantity;
   int* tot_price;
   int* item_ID;

   fstream stockRead;
    char lines[100];
    stockRead.open("Stocks.txt",ios::in);   // stocks ki file kholi reading mode me
   
    if (!stockRead) 
    {
        fileError();
    }
     else 
    {
        
        while(stockRead.getline(lines,100))   // lines count ki
      {
            totLines++;
        }
      
        stockRead.clear();   // error flag clear kia
        stockRead.seekg(0, ios::beg);  // pointer ko beginning me legaya

        const int size=totLines-1;   // pehli line header ha to usko exclude krdia

        
        name = new char*[size];
        price = new int[size];
        quantity = new int[size];    // dynamic arrrays initialization
        tot_price=new int[size];
        item_ID = new int[size];

        for (int l = 0; l < size; l++) 
        {
            name[l] = new char[32];
        }
   
    int i=0;
    stockRead.getline(HDR,100,'\n');   // header HDR me store krdia
    // file reading
    while(stockRead>>item_ID[i])
     {  
       stockRead.ignore();
       stockRead.getline(name[i],32,',');
       stockRead>>price[i]>>quantity[i]>>tot_price[i];
       stockRead.ignore();
       i++;
         
    } 

      // file close krdi
       stockRead.close();
      c=showThresholdNotif(HDR,item_ID,name,price,quantity,tot_price,size);

      // dynamic arrays delete krte huye
        for (int j = 0; j < size; j++)
         {
            delete[] name[j];
        }

        delete[] name;
        delete[] tot_price;    
        delete[] price;
        delete[] item_ID;
        delete[] quantity;

        name=NULL;
        tot_price=NULL;
        price=NULL;
        item_ID=NULL;
        quantity=NULL;

    }
    return c;
}

// threshold sa kam items dekhne aur purchase krne kelye
void checkThreshold()
{
   bool idnotfound;
   char choice;
   int n=0;

   do
    { 
      int totLines=0;

   char HDR[100];
   char** name;
   int* price;          // pointers declare kiye
   int* quantity;
   int* tot_price;
   int* item_ID;

   fstream stockRead;
    char lines[100];
    stockRead.open("Stocks.txt",ios::in);   // stocks ki file kholi reading mode me
   
    if (!stockRead) 
    {
        fileError();
    }
     else 
    {
        
        while(stockRead.getline(lines,100))   // lines count ki
      {
            totLines++;
        }
      
        stockRead.clear();   // error flag clear kia
        stockRead.seekg(0, ios::beg);  // pointer ko beginning me legaya

        const int size=totLines-1;   // pehli line header ha to usko exclude krdia

        
        name = new char*[size];
        price = new int[size];
        quantity = new int[size];    // dynamic arrrays initialization
        tot_price=new int[size];
        item_ID = new int[size];

        for (int l = 0; l < size; l++) 
        {
            name[l] = new char[32];
        }
   
    int i=0;
    stockRead.getline(HDR,100,'\n');   // header HDR me store krdia
    // file reading
    while(stockRead>>item_ID[i])
     {  
       stockRead.ignore();
       stockRead.getline(name[i],32,',');
       stockRead>>price[i]>>quantity[i]>>tot_price[i];
       stockRead.ignore();
       i++;
         
    } 

      // file close krdi
       stockRead.close();
     cout<<endl<<endl;
     // function me pass krdi sb arrays
     showThreshold(HDR,item_ID,name,price,quantity,tot_price,size);
   
   
     char ch;
            // ta k sirf ek baar ye puchy next time na puchy
             if(n==0)
             {
               do
                {                 // admin sa pucha k wo jo items kam han 15 sy khareedna chahta ha ya ni
                     cout<<"\n\n\t\tDo Want to Purchase Items Less than 15 Y/N : ";
                     cin >> ch;
                     
                    } while ((ch!= 'y' && ch!= 'Y') && (ch!= 'n' && ch!= 'N'));
             }
         n++;
         int newquant;
         int count;
         int id;
         id=0;
        if(ch=='y'||ch=='Y')   // agr yes kia to
         {
                    
                  idnotfound=false;
                  count=0;

                  cout<<"\n\n\t\tEnter ID of Item you want to Update Quantity   : ";   // item ka id number lelia
                  cin>>id;

                   for(int i=0; i<size; i++)
                     { 
                        if(id==item_ID[i])   // check krty huye k wo id number ha b ya ni
                         count++;
                        else
                        continue;
                      }

                    if(count==0)    // agr ni ha to error dikha de
                   {
                      cin.clear();
                      cin.ignore();
                      cout<<"\n\n\t\tItem with Such ID not found\n\n\t\tEnter Correct ID of item ";
                      idnotfound=true;
                       continue;
                    }  

                  // ni to idr ajae

                 for(int i=0; i<size; i++)
                  {
                     if(item_ID[i]==id)  // itemid ka index pe janay kelye
                     {
                        do{
                            cout<<"\n\n\t\tPrice Per Item is : "<<price[i];   // price show krwai admin ko
                            cout<<"\n\n\t\tEnter Updated Quantity : ";   //updated quantity lete huye
                            cin>>newquant;
                            if(newquant<1000 && newquant>0)   // agr 1000 sa kam aur 0 sa ziada ha to
                            {
                              quantity[i]=newquant;        // us index pe quantity update krdi
                              tot_price[i]=price[i]*quantity[i];   // aur price b new k hisab sa change krdi
                              break;
                            }
                            else
                            {
                              cout<<"\n\n\t\tQuantity must not exceed 1000";
                              continue;
                            }

                        }while(true); 
                     }
                     else
                     {
                        continue;
                     }
                  }
   
                   // wapsi stock write krne kelye stocks open ki
                fstream updateStock; 
                 
               updateStock.open("Stocks.txt",ios::out);

               if(!updateStock)
               {
                  fileError();
               }
               
               else
               {
              

            updateStock<<HDR<<endl;   // sbsy pehle header likha
            for (int k = 0; k < size; k++) 
          {   
            // aur phr baki cheeze likh di
            updateStock<<item_ID[k]<<" "<<name[k]<<", "<<price[k]<<" "<<quantity[k]<<" "<<tot_price[k]<<endl;

          }
       // file close ki
         updateStock.close();
         cout<<endl<<endl;                // updated stocks dikhaye user ko
         cout << endl << endl << "\t\t--------- Updated Stocks ---------" << endl << endl;
         showThreshold(HDR,item_ID,name,price,quantity,tot_price,size);
         

          // dynamic arrays delete krte huye
        for (int j = 0; j < size; j++)
         {
            delete[] name[j];
        }

        delete[] name;
        delete[] tot_price;    
        delete[] price;
        delete[] item_ID;
        delete[] quantity;

        name=NULL;
        tot_price=NULL;
        price=NULL;
        item_ID=NULL;
        quantity=NULL;
              
              
       }
                   // aur items update krne ka pucha
              do
                {    
                    cin.ignore(); 
                     cout << "\n\n\t\tDo you want to Purchase More Items? Y/N : ";
                     cin >> choice;

                    } while ((choice!= 'y' && choice!= 'Y') && (choice!= 'n' && choice!= 'N'));
          
       }
     // agr admin 15 sa kam items khareedna ni chahta to idr ajaega  
   else 
   {
      cin.ignore();
      cout<<"\n\n\t\tYou CHOSE NOT TO ADD MORE ITEMS \n\n";
      cout<<"\n\n\t\tPress enter to continue ...";
      cin.get();
      return;
   }
}
     // ye tb tk chalegi jb tk admin aur items purchase krne ka kehta rahega
    }while((choice== 'Y' || choice== 'y' || idnotfound)); 
 
    cin.ignore();
    cout<<"\n\n\t\tPress Enter to continue ... ";
    cin.get();


}
// stocks ko sort kr k show krne ka function
void showThreshold(char HDR[],int* item_ID,char** name, int* price, int* quantity, int* tot_price,const int size)
{
    
    char** tempName;
    int* tempPrice;
    int* tempQuantity;         // temporary dynamic arrays banai
    int* temptotPrice;
    int* tempID;
 
        tempName = new char*[size];
        tempPrice = new int[size];          // same size ki intialize kia
        tempQuantity = new int[size];
        temptotPrice=new int[size];
        tempID = new int[size];

        for (int l = 0; l < size; l++) 
        {
            tempName[l] = new char[32];
 
        }

      for (int i = 0; i < size; ++i) 
      {
            strcpy(tempName[i],name[i]);       // names copy krdiye aur isi trah baki b
            tempPrice[i] = price[i];
            tempQuantity[i]= quantity[i];
            temptotPrice[i]= tot_price[i];
            tempID[i]=item_ID[i];
        }
    

        // selection sort technique
       for(int i=0; i<size; i++)
       {
         for(int j=i+1; j<size; j++)        
         {
             if(tempQuantity[i]>tempQuantity[j])   // arrays ko quantity k lihaz sa sort krte huye
            {
               swapVal(tempQuantity[i],tempQuantity[j]);
               swapVal(tempPrice[i],tempPrice[j]);           
               swapVal(tempID[i],tempID[j]);
               swapVal(temptotPrice[i],temptotPrice[j]);
               swapChar(tempName[i],tempName[j],32);
            }
            
         }
       }

        
            // header
            cout<<HDR<<endl;
            for (int k = 0; k < size; k++) 
          {

             if(tempQuantity[k]<=0)      // agr quantity 0 ha to yellow ho k dikhe row
            {
               cout<<YELLOW_TEXT;
               cout<<tempID[k]<<setw(18)<<tempName[k]<<setw(10)<<tempPrice[k]<<setw(14)<<tempQuantity[k]<<setw(20)<<temptotPrice[k]<<endl;
               cout<<RESET_TEXT;
            }
            else if(tempQuantity[k]<=15)   // agr 15 sa kam ha to red ho k dikhe
            {
              
                cout<<RED_TEXT;
                cout<<tempID[k]<<setw(18)<<tempName[k]<<setw(10)<<tempPrice[k]<<setw(14)<<tempQuantity[k]<<setw(20)<<temptotPrice[k]<<endl;
                cout<<RESET_TEXT;
            }
           
            else  // ni to simple dikhe
            {
               cout<<tempID[k]<<setw(18)<<tempName[k]<<setw(10)<<tempPrice[k]<<setw(14)<<tempQuantity[k]<<setw(20)<<temptotPrice[k]<<endl;  
            }
          }

          // dynamic arrays delete krte huye
        for (int j = 0; j < size; j++)
         {
            delete[] tempName[j];
        }

        delete[] tempName;
        delete[] temptotPrice;    
        delete[] tempPrice;
        delete[] tempID;
        delete[] tempQuantity;

        tempName=NULL;
        temptotPrice=NULL;
        tempPrice=NULL;
        tempID=NULL;
        tempQuantity=NULL;
  
    }

int showThresholdNotif(char HDR[],int* item_ID,char** name, int* price, int* quantity, int* tot_price,const int size)
{
    
    char** tempName;
    int* tempPrice;
    int* tempQuantity;         // temporary dynamic arrays banai
    int* temptotPrice;
    int* tempID;
 
        tempName = new char*[size];
        tempPrice = new int[size];          // same size ki intialize kia
        tempQuantity = new int[size];
        temptotPrice=new int[size];
        tempID = new int[size];

        for (int l = 0; l < size; l++) 
        {
            tempName[l] = new char[32];
 
        }

      for (int i = 0; i < size; ++i) 
      {
            strcpy(tempName[i],name[i]);       // names copy krdiye aur isi trah baki b
            tempPrice[i] = price[i];
            tempQuantity[i]= quantity[i];
            temptotPrice[i]= tot_price[i];
            tempID[i]=item_ID[i];
        }
    

        // selection sort technique
       for(int i=0; i<size; i++)
       {
         for(int j=i+1; j<size; j++)        
         {
             if(tempQuantity[i]>tempQuantity[j])   // arrays ko quantity k lihaz sa sort krte huye
            {
               swapVal(tempQuantity[i],tempQuantity[j]);
               swapVal(tempPrice[i],tempPrice[j]);           
               swapVal(tempID[i],tempID[j]);
               swapVal(temptotPrice[i],temptotPrice[j]);
               swapChar(tempName[i],tempName[j],32);
            }
            
         }
       }

           int count=0;
   
            for (int k = 0; k < size; k++) 
          {
             if(tempQuantity[k]<=15)   // agr 15 sa kam ha to count me + krdy
            {
                count++;
            }
           
          }

          // dynamic arrays delete krte huye
        for (int j = 0; j < size; j++)
         {
            delete[] tempName[j];
        }

        delete[] tempName;
        delete[] temptotPrice;    
        delete[] tempPrice;
        delete[] tempID;
        delete[] tempQuantity;

        tempName=NULL;
        temptotPrice=NULL;
        tempPrice=NULL;
        tempID=NULL;
        tempQuantity=NULL;


        return count;
  
    }



void swapVal(int& i, int& j)   // swapping kelye banaya gya function
{
   int temp;
   temp=i;
   i=j;
   j=temp;
}

void swapChar(char* i, char *j,int size)        // char arrays ki swapping kelye
{
   char* temp= new char[size];
   strcpy(temp,i);
   strcpy(i,j);
   strcpy(j,temp);

   delete[]temp;
}
// employees aur students k credentials change krne kelye
void handleCreds()
{
    int choice;

    choice=credsChoice();   // admin sa pucha k kiske manage krna chahta ha

   if(choice==1)   // agr employee chose kia
   {  

       fstream readEmpCreds;
   int* ID;
   char** empUser;
   char** empPass;      
   char charID[10];
   char lines[100];
   
   int totLines=0;

   readEmpCreds.open("EmployeesCreds.txt",ios::in);   // employees ki file kholi

                     
    if (!readEmpCreds) 
    {
        fileError();
    }
     else 
    {
        
        while(readEmpCreds.getline(lines,100))   // lines count ki
      {
            totLines++;
        }
            

         readEmpCreds.clear();             // error flag clear kia
         readEmpCreds.seekg(0, ios::beg);   // pointer shuru me legya

        
        empUser= new char*[totLines/3];      // lines ko divide by 3 kia q k file me data 3 k pair me ha
        empPass = new char*[totLines/3];
        ID = new int[totLines/3];

        for (int l = 0; l <totLines/3; l++) 
        {
            empUser[l] = new char[32];
            empPass[l]= new char[32];
        }
            int i=0;           
            // file reading
            while(readEmpCreds>>charID>>ID[i])
             {  
                   readEmpCreds.ignore();
                  
                   readEmpCreds.getline(empUser[i],32);
                   readEmpCreds.getline(empPass[i],32);
                   i++;     
             } 
                 // file closed
              readEmpCreds.close();

      //  employees k credentials show krwaye admin ko
          cout << endl << endl << "\t\t--------- Employees Creds ---------" << endl << endl;

            for (int k = 0; k < totLines/3; k++) 
          {
            cout<<charID<<" "<<ID[k]<<endl<<empUser[k]<<endl<<empPass[k]<<endl;  
          }

          int ch;
         // puch rha hu k add krna chahta ha ya remove
          ch=manageCredsChoice();

          if(ch==1)
          {      // agar remove choose kia
              removeEmp();
          }

          else if(ch==2)
          {
            // agr add choose kia
            int lastID=ID[totLines/3-1];   // ID k last index ko last id me store krdia 
            addEmp(charID,ID,lastID,empUser,empPass,totLines/3);
          }
                           
     }
      // dynamic arrays deletion
     for (int j = 0; j < totLines/3; j++)
         {
            delete[] empPass[j];
            delete[] empUser[j];
        }

        delete[] empUser;
        delete[] empPass;
        delete[] ID;       

       empUser=NULL;
       empPass=NULL;
       ID=NULL;
   }
     // agr admin ne students k credentials manage krne 
   else if(choice==2)
   {
   
       fstream readStdntCreds;
       int* stdntID;
       char** stdntUser;
       char** stdntPass;
       char charID[10];
       char lines[100];
   
        int totLines=0;

         readStdntCreds.open("StudentsCreds.txt",ios::in);   // students ki credentials file open ki

                     
         if (!readStdntCreds) 
         {
           fileError();
         }
         else 
        {
        
        while(readStdntCreds.getline(lines,100))  
        {
            totLines++;    // lines count ki
        }
        

         readStdntCreds.clear();
         readStdntCreds.seekg(0, ios::beg);  // pointer ko shuru me legaya

        
        stdntUser= new char*[totLines/3];    // totlines divide kia 3 me q k file me data 3 k pair me ha
        stdntPass = new char*[totLines/3];
        stdntID = new int[totLines/3];

        for (int l = 0; l < totLines/3; l++) 
        {
            stdntUser[l] = new char[32];
            stdntPass[l]= new char[32];
        }
            int i=0;  

            // file reading         
            while(readStdntCreds>>charID>>stdntID[i])
             {  
                   readStdntCreds.ignore();
                  
                   readStdntCreds.getline(stdntUser[i],32);
                   readStdntCreds.getline(stdntPass[i],32);
                   i++;     
             } 

              readStdntCreds.close();

           // admin ko students ka data display krwadia
          cout << endl << endl << "\t\t---------- Students Creds ----------" << endl << endl;

            for (int k = 0; k < totLines/3; k++) 
          {
            cout<<charID<<" "<<stdntID[k]<<endl<<stdntUser[k]<<endl<<stdntPass[k]<<endl;  
          }

          int ch;

          ch=manageCredsChoice();   // choice li add krne han ya remove

          if(ch==1)
          {
              removeStdnt(charID,stdntID,stdntUser,stdntPass,totLines/3);  // agr remove choose kia
          }

          else if(ch==2)
          {
            int lastID=stdntID[totLines/3-1];  
            addStdnt(charID,stdntID,lastID,stdntUser,stdntPass,totLines/3);  // agr add krne
          }
                       

        
     }
       // delete krdi memory
      for (int j = 0; j < totLines/3 ; j++)
         {
            delete[] stdntUser[j];
            delete[] stdntPass[j];
        }

        delete[] stdntUser;
        delete[] stdntPass;
        delete[] stdntID;       

       stdntUser=NULL;
       stdntPass=NULL;
       stdntID=NULL;

   }
}
// credentials ki choice
int manageCredsChoice()
{
       int ch;
      cout<<endl<<endl;
      do
      {
    
      
                    cout << "\t\t----------------------------------------------------------------------------------" << endl;
                    cout << "\t\t|                                                                                |" << endl;
                    cout << "\t\t|     Choose From Following ::                                                   |" << endl;
                    cout << "\t\t|     Press 1 : Remove Credentials                                               |" << endl;
                    cout << "\t\t|     Press 2 : Add  Credentials                                                 |" << endl;
                    cout << "\t\t|                                                                                |" << endl;
                    cout << "\t\t----------------------------------------------------------------------------------" << endl;
                    cin>>ch;
                  
              if(ch>=1 && ch<=2)
                   {
                     
                      break;
             
                   }
             
                else if(ch<1 || ch>2)
                   {
                      
                      cin.clear(); 
                      cin.ignore(); 
                      rangeerror();
                      continue;
                   }
                    
               }while(ch<1 || ch>2);
      
        return ch;


}

// student ka account remove krne ka function
void removeStdnt(char charID[], int *ID, char **stdntUser, char **stdntPass, int size)
{


char ch;

bool idnotfound;
do{
    

    idnotfound=false;
    fstream removeStdntCreds;
    int id;

    removeStdntCreds.open("StudentsCreds.txt",ios::out);   // write mode me file kholi

                     
    if (!removeStdntCreds) 
    {
        fileError();
    }
   else 
    {
          
          int n=1;
          int count=0;
          cout<<"\n\n\t\tEnter ID of Students whose Credentials you want to remove :";  // admin sa id puchi student ki
          cin>>id;
        
                      for(int i=0; i<size; i++)
                     { 
                        if(id==ID[i])
                         count++;           // check kr rha hu k wo id ha b file me ya ni
                        else
                        continue;
                      }

                    if(count==0)   // agr ni ha to error de k dobara puchyga
                   {
                      cin.clear();
                      cin.ignore();
                      cout<<"\n\n\t\tStudent with Such ID not found\n\n\t\tEnter Correct ID of Employee ";
                      idnotfound=true;
                       continue;
                    }  

                    else   // agr id ha to idr ajae
                    {
                         int posi=0;

                   for(int i=0; i<size; i++)
                    {
                     
                     if(ID[i]==id)   // index record kia id ka
                     {
                            break;
                     }
                     else
                     {
                        posi++;
                       continue;
                     }
                  }
                  
                     wait("Removing Student ...",0);
                       wait("Removed Succcessfully ...",3);

            for (int k = 0; k < size-n; k++) 
            {
               if(k==posi)   // aur us index pe mojud data ko chorh k baki sb write krlia
               continue;
               removeStdntCreds<<charID<<" "<<ID[k]<<endl<<stdntUser[k]<<endl<<stdntPass[k]<<endl;
            }


            n=n+1;  // ta k jitni dafa remove kry utny index aur kam hon loop kelye

         removeStdntCreds.close();
       }
                     
        }       
                
                // pucha k aur b remove krne han ya ni
             do
                {     
                   cout << "\n\n\t\tDo you want to Remove More Credentials? Y/N : ";
                     cin >> ch;
                     
                    } while ((ch!= 'y' && ch!= 'Y') && (ch!= 'n' && ch!= 'N'));


  }while(ch== 'Y' || ch== 'y' || idnotfound);
 
  
}

// student add krne kelye
void addStdnt(char charID[], int *ID,int lastID, char **stdntUser, char **stdntPass, int size)
{
   char ch;
   int n=0;
bool usernametaken;
do{
     n++;
     char newusername[32];
     char newpass[32];

 
    fstream addStdntCreds;
    int id;

    addStdntCreds.open("StudentsCreds.txt",ios::out | ios::app);  // append mode me file kholi

                     
    if (!addStdntCreds) 
    {
        fileError();
    }
   else 
    {
           cin.ignore();
         do{   
                  usernametaken=false;
                       
                        cout<<"\n\n\t\tEnter New Username : ";    // admin sa username pucha
                        cin.getline(newusername,32);
                 
               for(int i=0; i<size; i++)
               {
                   if(strcmp(stdntUser[i],newusername)==0)   // check kr rha hu k kisi aur na to same username ni rakha hua
                              {
                                  // agr true to message dikha k dobara puchy    
                                   cout<<"\n\n\t\tUserName Taken!! Please Write Anyother"<<endl;
                                   usernametaken=true;
                                   continue;
                              }
                         
               }
            }while(usernametaken);
                  // admin sa password pucha
                        cout<<"\n\n\t\tEnter New Password : ";
                        cin.getline(newpass,32);

                        wait("Adding Student ...",0);
                       wait("Added Succcessfully ...",3);

                        cout<<"\n\n\t\tID Assigned : "<<lastID+n;  // aur id assign krdi last id ma 1 add kr k
               
           // file k end me likh dia data    
         addStdntCreds<<charID<<" "<<lastID+n<<endl<<newusername<<endl<<newpass<<endl;
                                 
         addStdntCreds.close();  // aur file close krdi
       
                     
                      do
                  {     
                     // aur add krny ki choice
                     cout << "\n\n\t\tDo  you want to ADD More Credentials? Y/N : ";
                     cin >> ch;
                     
                    } while ((ch!= 'y' && ch!= 'Y') && (ch!= 'n' && ch!= 'N'));

    }        
  }while(ch== 'Y' || ch== 'y');
 
  
}

// employees ka data add krne ka function
void addEmp(char charID[], int *ID,int lastID, char **empUser, char **empPass, int size)
{
   char ch;
   int n=0;

bool usernametaken;
do{
     n++;
     char newusername[32];
     char newpass[32];

 
    fstream addEmpCreds;
    int id;

    addEmpCreds.open("EmployeesCreds.txt",ios::out | ios::app);   // append mode me file kholi

                     
    if (!addEmpCreds) 
    {
        fileError();    // file error agr open na ho
    }
   else 
    {
           cin.ignore();
         do{
                  usernametaken=false;
                       
                        cout<<"\n\n\t\tEnter New Username : ";    // username pucha admin sy
                        cin.getline(newusername,32);
                 
               for(int i=0; i<size; i++)
               {
                   if(strcmp(empUser[i],newusername)==0)   // check kia agr same username to ni ha kisi ka
                              {
                                    // agr ha to dobara puchy admin sy
                                   cout<<"\n\n\t\tUserName Taken!! Please Write Anyother"<<endl;
                                   usernametaken=true;
                                   continue;
                              }
                         
               }
            }while(usernametaken);

                        cout<<"\n\n\t\tEnter New Password : ";   // password pucha admin sy
                        cin.getline(newpass,32);

                        wait("Adding Employee ...",0);
                       wait("Added Succcessfully ...",3);

                        cout<<"\n\n\t\tID Assigned : "<<lastID+n;  // aur last id me 1 add kr k assign krdi id
               
         addEmpCreds<<charID<<" "<<lastID+n<<endl<<newusername<<endl<<newpass<<endl;  // write krdia data file me
                                 
         addEmpCreds.close();

              
                 fstream writeSales;

                        writeSales.open("EmployeesSales.txt",ios::out | ios::app);  // sales ki file kholi

                      if(!writeSales)
                      {
                         fileError();
                       }
                        else
                          {    // aur usme new employee ka record add krdia
                               writeSales<<"ID: "<<lastID+n<<" Sales: 0"<<endl;
                           }

                    writeSales.close();
       
                     
                      do
                   {     
                    
                     cout << "\n\n\t\tDo you want to ADD More Credentials? Y/N : ";
                     cin >> ch;
                     
                    } while ((ch!= 'y' && ch!= 'Y') && (ch!= 'n' && ch!= 'N'));

    }        
  }while(ch== 'Y' || ch== 'y');
 
  

}

// employee remove krne kelye
void removeEmp()
{


char ch;
bool idnotfound;

do{
     
     fstream readEmpCreds;
   int* ID;
   char** empUser;
   char** empPass;
   char charID[10];
   char lines[100];
   
   int totLines=0;

   readEmpCreds.open("EmployeesCreds.txt",ios::in);    // reading mode me file open ki

                     
    if (!readEmpCreds) 
    {
        fileError();
    }
     else 
    {
        
        while(readEmpCreds.getline(lines,100)) 
      {
            totLines++;   // lines count ki
        }

         const int size=totLines/3;              // 3 pe divide kr k size me store krdi  

         readEmpCreds.clear();
         readEmpCreds.seekg(0, ios::beg);   // pointer ko shuru me laeaya

        
        empUser= new char*[size];
        empPass = new char*[size];
        ID = new int[size];

        for (int l = 0; l < size; l++) 
        {
            empUser[l] = new char[32];
            empPass[l]= new char[32];
        }
            int i=0;          
            // file reading 
            while(readEmpCreds>>charID>>ID[i])
             {  
                   readEmpCreds.ignore();
                  
                   readEmpCreds.getline(empUser[i],32);
                   readEmpCreds.getline(empPass[i],32);
                   i++;     
             } 

              readEmpCreds.close();    // file close
    

    idnotfound=false;
    fstream removeEmpCreds;
    int id;

    removeEmpCreds.open("EmployeesCreds.txt",ios::out);   // write mode me open ki file dobara

                     
    if (!removeEmpCreds) 
    {
        fileError();
    }
   else 
    {
   
          int count=0;          // admin sa id puchi remove krne kelye
          cout<<"\n\n\t\tEnter ID of Employee whose Credentials you want to remove :";
          cin>>id;
        
                      for(int i=0; i<size; i++)
                     { 
                        if(id==ID[i])   //  check kia k wo id ha b ya ni
                         count++;
                        else
                        continue;
                      }
 
                    if(count==0)     // agr ni ha to dobara puchi
                   {
                      cin.clear();
                      cin.ignore();
                      cout<<"\n\n\t\tEmployee with Such ID not found\n\n\t\tEnter Correct ID of Employee ";
                      idnotfound=true;
                       continue;
                    }  

                    else  // agr ha to idr ajaega
                    {

                         int posi=0;

                   for(int i=0; i<size; i++)
                    {
                     
                     if(ID[i]==id)   // jis index pe id milegi wo posi me store krdia
                     {
                            break;
                     }
                     else
                     {
                        posi++;
                       continue;
                     }
                  }
                  
                  wait("Removing Employee ...",0);
                  wait("Removed Succcessfully ...",3);

            for (int k = 0; k < size; k++) 
            {
               if(k==posi)    // jb posi wala index ayega to write back ni krega aur baki krdega
               continue;
               else
               {
                removeEmpCreds<<charID<<" "<<ID[k]<<endl<<empUser[k]<<endl<<empPass[k]<<endl;
               }
            }

               removeEmpCreds.close();   // file close ki

               int* SALES;   
               int* ID;
                 char charid[10];
                 char charsales[10];
                 char lines[50];

                  int totLines=0;

                fstream readSales;

                readSales.open("EmployeesSales.txt",ios::in);   // sales wali file khol k udr sa b record remove krne kelye

                 if(!readSales)
                 {
                    fileError();
                   }
                   else
                    {
                       
                       while(readSales.getline(lines,50,'\n'))
                       {
                         totLines++;  // lines count ki
                       }
       
                       readSales.clear();
                       readSales.seekg(0,ios::beg);   // pointer wapis shuru me laya
            
                        SALES = new int[totLines];
                          ID = new int[totLines];
          
                     int i=0;   // file reading
                       while(readSales.getline(charid,10,':'))
                         {
                           readSales>>ID[i];
                           readSales.ignore();
                           readSales.getline(charsales,10,':');
                           readSales>>SALES[i];
                           readSales.ignore();
                              i++;
                         }

         readSales.close();  // file close
        
         cout<<endl<<endl;

              int pos=0;

                   for(int i=0; i<totLines; i++)
                    {
                     
                     if(ID[i]==id)   // jis index pe id milegi wo posi me store krdia
                     {
                            break;
                     }
                     else
                     {
                        pos++;
                       continue;
                     }
                  }

            fstream removeSales;

                     removeSales.open("EmployeesSales.txt",ios::out);   // wapis kholi writing kelye

                      if(!removeSales)
                      {
                         fileError();
                       }
                        else
                          {
                               for (int k = 0; k < totLines; k++) 
                               {
                                 if(k==pos)   // jis index pe id thi wo write na kry baki krdy
                                 continue;
                                 removeSales<<"ID: "<<ID[k]<<" Sales: "<<SALES[k]<<endl;
                                }

                     removeSales.close();

                      delete[] SALES;  // memory delete krdi
                      delete[] ID; 

                      SALES=NULL;
                      ID=NULL;
           
                   

         }

         }
       }
    }
       // memory delete krdi
       for (int j = 0; j < size; j++)
         {
            delete[] empPass[j];
            delete[] empUser[j];
        }

        delete[] empUser;
        delete[] empPass;
        delete[] ID;       

       empUser=NULL;
       empPass=NULL;
       ID=NULL;
   
   }

  }while(idnotfound);


  


}

// admin ko stock dikhane ka function
void seeStock()
{
     
   char HDR[100];
   char** name;
   int* price;
   int* quantity;
   int* tot_price;
   int* item_ID;

   int totLines=0; 


   cin.ignore();
   cout << endl << endl << "\t\t--------- Stock Available Now ---------" << endl << endl;
   showStock(HDR,item_ID,name,price,quantity,tot_price,totLines);   // arrays pass krdi function me



   cout<<"\n\n\t\tPress any key to continue...";
   cin.get();


}

void showStock(char HDR[],int* item_ID,char** name, int*price, int*quantity, int* tot_price,int& totLines)
{
    fstream stockRead;
    char lines[100];
    stockRead.open("Stocks.txt",ios::in);   // reading mode me stocks open kiye
   
    if (!stockRead) 
    {
        fileError();
    }
     else 
    {
        
        while(stockRead.getline(lines,100)) 
      {
            totLines++;    // lines count ki
        }
      
        stockRead.clear();
        stockRead.seekg(0, ios::beg);  // pointer ko shuru me laya

        
        name = new char*[totLines-1];
        price = new int[totLines-1];
        quantity = new int[totLines-1];    // initialization ki dynamic arrays ki
        tot_price=new int[totLines-1];
        item_ID = new int[totLines-1];

        for (int l = 0; l < totLines-1; l++) 
        {
            name[l] = new char[32];
        }
   
    int i=0;
    stockRead.getline(HDR,100,'\n');   // first line ko read kr k HDR me store krdia
   while(stockRead>>item_ID[i])   // baki file reading kelye
     {  
       stockRead.ignore();
       stockRead.getline(name[i],32,',');
       stockRead>>price[i]>>quantity[i]>>tot_price[i];
       stockRead.ignore();
       i++;
         
    } 

   
       stockRead.close();   // close krdi

         // admin ko stock display krwadia
            cout<<HDR<<endl;
            for (int k = 0; k < totLines-1; k++) 
          {
            cout<<item_ID[k]<<setw(18)<<name[k]<<setw(10)<<price[k]<<setw(14)<<quantity[k]<<setw(20)<<tot_price[k]<<endl;  
          }

        // memory delete krdi
         for(int i=0; i<totLines-1; i++)
          {
            delete[]name[i];
          }

          delete[]name;
          delete[]price;
          delete[]quantity; 
          delete[]tot_price;
          delete[]item_ID;

          name=NULL;
          price=NULL;
          quantity=NULL;
          tot_price=NULL;
          item_ID=NULL;


       
   }
}

// stock management ka function
void stockManage()
{ 

   char HDR[100];
   char** name;
   int* price;
   int* quantity;
   int* tot_price;
   int* item_ID;

   int totLines=0;

    fstream stockRead;
    char lines[100];
    stockRead.open("Stocks.txt",ios::in);     // stocks pehle read kiye
   
    if (!stockRead) 
    {
        fileError();
    }
     else 
    {
        
        while(stockRead.getline(lines,100)) 
      {
            totLines++;   // lines count ki
        }
      
        stockRead.clear();
        stockRead.seekg(0, ios::beg);   // pointer shuru me laya

        
        name = new char*[totLines-1];
        price = new int[totLines-1];        // dynamic arrays initialize kie
        quantity = new int[totLines-1];
        tot_price=new int[totLines-1];
        item_ID = new int[totLines-1];

        for (int l = 0; l < totLines-1; l++) 
        {
            name[l] = new char[32];
        }
   
    int i=0;
    stockRead.getline(HDR,100,'\n');    // first line hdr me store ki
   while(stockRead>>item_ID[i])   // aur baki file b
     {  
       stockRead.ignore();
       stockRead.getline(name[i],32,',');
       stockRead>>price[i]>>quantity[i]>>tot_price[i];
       stockRead.ignore();
       i++;
         
    } 

   
       stockRead.close();  // file close krdi

           // admin ko stock dikhaya pehle
            cout<<HDR<<endl;
            for (int k = 0; k < totLines-1; k++) 
          {
            cout<<item_ID[k]<<setw(18)<<name[k]<<setw(10)<<price[k]<<setw(14)<<quantity[k]<<setw(20)<<tot_price[k]<<endl;  
          }

          // last id record kr k ek add krdia
        int id=item_ID[totLines-2]+1;
        int size=totLines-1;
        int ch;
       
         ch=stockChoice();   // admin ko choice di stocks management ki

        if(ch==1)
        {
            stockAdd(id);   // agr add krna choose kia to ye function chalega
            totLines=0;

            cout << endl << endl << "\t\t--------- Updated Stock  ---------" << endl << endl;
            stockManage();

        }

        else if(ch==2)   // agr koi item delete krna hua to idr ajaega
        {
           stockDEL(HDR,item_ID,size,name,price,quantity,tot_price,totLines);
           totLines=0;
           cout << endl << endl << "\t\t--------- Updated Stock  ---------" << endl << endl;
           stockManage();
        }

        else if(ch==3)  // agr koi item update krna ho to idr ajaega
        {
           stockUpdate(HDR,item_ID,size,name,price,quantity,tot_price);
           totLines=0;
           cout << endl << endl << "\t\t--------- Updated Stock  ---------" << endl << endl;
           stockManage();
        }
        else if(ch==4)  // agr stock me kuch search krna hua to
        {
           stockSearch(HDR,item_ID,size,name,price,quantity,tot_price);
        }
        else{}
        
          
      
     // aur akhr me memory delete krdi
        for (int j = 0; j < totLines-1; j++)
         {
            delete[] name[j];
        }

        delete[] name;
        delete[] tot_price;    
        delete[] price;
        delete[] item_ID;
        delete[] quantity;

        name=nullptr;
        tot_price=nullptr;
        price=nullptr;
        item_ID=nullptr;
        quantity=nullptr;
    }

}
void stockSearch(char HDR[],int* item_ID, const int size,char** name, int* price, int* quantity, int* tot_price)
{
      char ch;
      int choice;
  do{
      choice=stockSearchChoice();   // stock search me aa k dobara pucha kis ki base pe search krna chahta ha

      if(choice==1)  // agr by name krna hua
      {
         searchbyName(size,name,HDR,item_ID,price,quantity,tot_price);
      }

      else if(choice==2)  // agr by id krna hua
      {
          searchbyID(size,name,HDR,item_ID,price,quantity,tot_price);
      }

      else if(choice==3)   // agr by price krna hua
      {
         searchbyPrice(size,name,HDR,item_ID,price,quantity,tot_price);
      }
      
      else    // agr return krna hua
      return;
          
         
              do    // agr aur search krne huye
                {     
                    
                     cout << "\n\n\t\tDo you want to Search More Items? Y/N : ";
                     cin >> ch;
                     } while ((ch!= 'y' && ch!= 'Y') && (ch!= 'n' && ch!= 'N'));
    
    
               

  }while(ch== 'Y' || ch== 'y');
  
  


}


// name sa search krne kelye function
void searchbyName(const int size,char** name,char HDR[],int* item_ID,int* price,int* quantity, int* tot_price)
{
   int count=0;
   fstream searchName;
   char nameSearch[32];

   cin.ignore();
   cout<<"\n\n\t\tEnter Name of Item to be Searched : ";  // admin sa name pucha
   cin.getline(nameSearch,32);
   cout<<endl<<endl;
   cout<<HDR<<endl;     // header print kia
   for(int i=0; i<size; i++) 
   {
      if(strcmp(name[i],nameSearch)==0)    // agr name mil jata ha to print krwa dy wo index pe name
      {
         count++;
         cout<<item_ID[i]<<setw(18)<<name[i]<<setw(10)<<price[i]<<setw(14)<<quantity[i]<<setw(20)<<tot_price[i]<<endl;
         break;
      }
      else
      {
       continue;
      }
   }

   if(count==0)        // agr ni milega name to ye display krwadega
   {
      cout<<"\n\n\t\tNo Item with such Name Found\n\n";
   }

  cout<<"\n\n\t\tPress any key to continue...";
  cin.get();
}

// search by ID kelye function
void searchbyID(const int size, char **name, char HDR[], int *item_ID, int *price, int *quantity, int *tot_price)
{
   int count=0;
   fstream searchID;
   int idSearch;

   cin.ignore();
   cout<<"\n\n\t\tEnter ID of Item to be Searched : ";   // admin sa id puchi
   cin>>idSearch;
   cout<<endl<<endl;
   cout<<HDR<<endl;
   for(int i=0; i<size; i++)  
   {
      if(idSearch==item_ID[i])      // jis index pe id mili us index ka data print krdia
      {
         count++; 
         cout<<item_ID[i]<<setw(18)<<name[i]<<setw(10)<<price[i]<<setw(14)<<quantity[i]<<setw(20)<<tot_price[i]<<endl;
      }
      else
      {
       continue;
      }
   }

   if(count==0)   // agr id ni mili to idr ayega
   {
      cin.clear();
      cin.ignore();
      cout<<"\n\n\t\tNo Item Found With Such ID\n\n";
   }


  cout<<"\n\n\t\tPress any key to continue...";
   cin.get();


}

// search by price ka function
void searchbyPrice(const int size, char **name, char HDR[], int *item_ID, int *price, int *quantity, int *tot_price)
{
   int count=0;
   fstream searchPrice;
   int priceSearch;

   cin.ignore();
   cout<<"\n\n\t\tEnter Price of Item to be Searched : ";  // admin sa price puchi
   cin>>priceSearch;
   cout<<endl<<endl;
   cout<<HDR<<endl;
   for(int i=0; i<size; i++)
   {
      if(priceSearch==price[i])   // index uthaya jidr wo price milegi aur us index pe mojud data display krwadia
      {
         count++; 
         cout<<item_ID[i]<<setw(18)<<name[i]<<setw(10)<<price[i]<<setw(14)<<quantity[i]<<setw(20)<<tot_price[i]<<endl;
      }
      else
      {
       continue;
      }
   }

   if(count==0)   // agr us price ka koi item na mila to
   {
      cin.clear();
      cin.ignore();
      cout<<"\n\n\t\tNo Item Found With Such Price\n\n";
   }


  cout<<"\n\n\t\tPress any key to continue...";
   cin.get();


}

// stock update krny ka function
void stockUpdate(char HDR[], int *item_ID, const int size, char **name, int *price, int *quantity, int *tot_price)
{
    bool idnotfound;
    char ch;
    int count;
        do{
            idnotfound=false;
            fstream updateStock;
            
            int choice;
            int id;
            int newprice;
            int newquant;
            char newname[32];

            updateStock.open("Stocks.txt",ios::out);          // stocks file write mode me open ki
            
            if(!updateStock)  // agr open na hui to error dega
            {
               fileError();
            }
            
            else   // open hogai to
            {
             
                  count=0;

                  cout<<"\n\n\t\tEnter ID of Item you want to Update Something   : ";  // jo item update krna ha uski id li admin sa
                  cin>>id;

                   for(int i=0; i<size; i++)
                     { 
                        if(id==item_ID[i])   // check kia k wo id ka item ha b ya ni
                         count++;
                        else
                        continue;
                      }

                    if(count==0)     // agr ni ha to dobara pucha
                   {
                      cin.clear();
                      cin.ignore();
                      cout<<"\n\n\t\tItem with Such ID not found\n\n\t\tEnter Correct ID of item ";
                      idnotfound=true;
                       continue;
                    }  
                   
                   else
                   {

                   choice=stockUpdateChoice();   // pucha k kia update krna chahta ha admin

                    cin.ignore();
                  for(int i=0; i<size; i++)
                  {
                     if(item_ID[i]==id)   // id wala index pick kia
                     {
                     
                         if(choice==1) // agr name update krna hua
                         {
                             cout<<"\n\n\t\tEnter New Name : ";    // new name lia admin sa
                             cin.getline(newname,32);
                             strcpy(name[i],newname);   // name k us index pe copy krdia newname
                             break;
                         }
                         else if(choice==2) // agr price update krni hui
                         {
                           cout<<"\n\n\t\tEnter Updated Price : ";   // new price li admin sy
                           cin>>newprice;
                           price[i]=newprice;   // us index pe prhi price change ki
                           tot_price[i]=price[i]*quantity[i];   // aur total price b update krdi
                           break;
                         }
                         else if(choice==3) // agr quantity update krni hui
                         {
                            cout<<"\n\n\t\tEnter Updated Quantity : ";  // updated quantity li admin sy
                            cin>>newquant;
                            quantity[i]=newquant;           // quantity replace ki
                            tot_price[i]=price[i]*quantity[i];  // aur total price b update krdi
                            break;
                         }
                         else  // agr sab kuch change krna hua
                         {
                             cout<<"\n\n\t\tEnter New Name : ";
                             cin.getline(newname,32);
                             strcpy(name[i],newname);
                             cout<<"\n\n\t\tEnter Updated Price : ";
                             cin>>newprice;
                             price[i]=newprice;
                             cout<<"\n\n\t\tEnter Updated Quantity : ";
                             cin>>newquant;
                             quantity[i]=newquant;
                             tot_price[i]=price[i]*quantity[i];
                             break;

                         }

                     }
                     else
                     continue;

                  }

            updateStock<<HDR<<endl;   // wapis file me header write kia aur baki data b
            for (int k = 0; k < size; k++) 
          {
               updateStock<<item_ID[k]<<" "<<name[k]<<", "<<price[k]<<" "<<quantity[k]<<" "<<tot_price[k]<<endl;

          }
       
                stockAdding();

                updateStock.close();
            
                do
                {    cin.ignore(); 
                     cout << "\n\n\t\tDo you want to Update More Items? Y/N : ";
                     cin >> ch;

                    } while ((ch!= 'y' && ch!= 'Y') && (ch!= 'n' && ch!= 'N'));
            
            
            }
         }
        } while((ch== 'Y' || ch== 'y' || idnotfound));

}

// stock me add krne ka function
void stockAdd(int ID)
{ 
   char ch;
   int n=1;
  do{
            fstream addStock;
            
            char item_name[32];
            int item_price;
            int item_quantity;
            int totalpr;

            addStock.open("Stocks.txt",ios::out | ios::app);  // append mode me open ki file
            
            if(!addStock)   // agr open na hui to error
            {
               fileError();
            }
            
            else
            {
              
              cin.ignore();
            
             addStock.seekp(0,ios::end);  // pointer ko end me legya

            cout<<"\n\n\t\tEnter Name of Item : ";       //item ka name lia admin sy
            cin.getline(item_name,32);
            cout<<"\n\n\t\tEnter Price of Item : ";    // price li admin sy
            cin>>item_price;
            cout<<"\n\n\t\tEnter Its Quantity : ";   // aur us item ki quantity
            cin>>item_quantity;

            totalpr=item_price*item_quantity;   // total price calculate krdi

          // automatically id assign kr k write krdia data file me
            addStock<<ID<<" "<<item_name<<", "<<item_price<<" "<<item_quantity<<" "<<totalpr<<endl;

             stockAdding();

             addStock.close();  // file close krdi

             fstream writeSales;

               writeSales.open("SalesRecord.txt",ios::out | ios::app);

                 writeSales<<ID<<" "<<item_name<<", "<<"0 0"<<endl;

                 writeSales.close();
               
               ID=ID+n;  // jitne items add krega admin utni id increment hogi

               
              
                do
                {        
                     cout << "\n\n\t\tDo you want to Add More Items? Y/N : ";
                     cin >> ch;

                    } while ((ch!= 'y' && ch!= 'Y') && (ch!= 'n' && ch!= 'N'));


            
       
              
         }
      }while((ch== 'Y' || ch== 'y'));  
 

}

// stock mese item delete krne kelye
void stockDEL(char HDR[],int* item_ID,const int size, char** name, int* price, int* quantity, int* tot_price, int totLines)
{
        char ch;
        bool idnotfound;
        
        do{
            idnotfound=false;
            fstream removeStock;
            
            int id;
            int posi=0;
            int n=1;
            n++;
            removeStock.open("Stocks.txt",ios::out);   // write mode me open ki
            
            if(!removeStock)  // check kia open hui ya ni
            {
               fileError();
            }
            
            else
            {
             
                  int count=0;
                  cout<<"\n\n\t\tEnter Item ID which you want to delete  : ";   // admin sa item ki id li jisko remove krna chahta ha
                  cin>>id;
                  int n=1;
                  n++;
                  for(int i=0; i<size; i++)
                  {
                     if(item_ID[i]==id)   // check kia k id mojud b ha ya ni
                     {
                       count++;
                       break;
                     }
                     else
                     posi++;  // index record krne kelye

                  }

               if(count==0)   // agr ni ha to dobara puche
               {
                  cout<<"\n\n\t\tSUCH ID NOT FOUND\n\n\t\tEnter ID Again!!!";
                  idnotfound=true;
                  continue;
               }
               else // agr id milgai
               {


            removeStock<<HDR<<endl;
            for (int k = 0; k < totLines-n; k++) 
          {
               if(k==posi)   // is index wala data chorh k baki write back krdy
               continue;
               removeStock<<item_ID[k]<<" "<<name[k]<<", "<<price[k]<<" "<<quantity[k]<<" "<<tot_price[k]<<endl;

          }
       
            removeStock.close();

            fstream delSales;
              int Lines;
            char lines[100];

            delSales.open("SalesRecord.txt",ios::in);

            if(!delSales)
            {
               fileError();
            }
            else
            {
                  while(delSales.getline(lines,100))   // lines count krne kelye
              {
                 Lines++;
              }

           delSales.clear();    // error flag ko clear krne kelye
           delSales.seekg(0,ios::beg);    // pointer ko wapis shuru me lanay kelye

         const int size = Lines-1;    // first line header ha to usko exclude krdia
         
           int* itemID;
           char** Names;
           int* Sales;
           double* Average;

         itemID = new int[size];
         Names = new char*[size];
         Sales = new int[size];        // dynamically 2d aur 1d arrays initialize krte hue
         Average = new double[size];

         for(int i=0; i<size; i++)
         {
            Names[i]= new char[32];         
         }

         int j=0;

         delSales.getline(HDR,100,'\n');         // pehli line ko HDR me store krwa lia

         while(delSales>>item_ID[j])         // next line me sbse pehle id store krwai
         {
            delSales.ignore();                        
            delSales.getline(Names[j],32,',');    // phr , comma tk item ka name Names me store krwaya
            delSales>>Sales[j]>>Average[j];           // aur next spaces k bd sales aur average store krwa di
            j++;
         }

         delSales.close();  
            
            fstream wSales;

            wSales.open("SalesRecord.txt",ios::out);

            if(!wSales)
            {
               fileError();
            }
            else
            {  
                 wSales<<HDR<<endl;
                for(int k=0; k<size; k++)
                {
                  if(id==item_ID[k])
                  {
                     continue;
                  }
                  else
                  wSales<<item_ID[k]<<" "<<Names[k]<<", "<<Sales[k]<<" "<<Average[k]<<endl;
                }
            } 
             
             wSales.close();

             stockRemoving();


            
                do
                {        
                     cout << "\n\n\t\tDo you want to Delete More Items? Y/N : ";
                     cin >> ch;

                    } while ((ch!= 'y' && ch!= 'Y') && (ch!= 'n' && ch!= 'N'));
            
            
               }  
         }
        } 
 
      }while((ch== 'Y' || ch== 'y' || idnotfound));

}

// screen output formatting kelye function
void stockAdding()
{

    cout << "\t\t--------------------------------------------" << endl;
                    cout<<endl;
                    
                   
                    wait("\t\tWait ... Adding Stock .... ",0);
                    wait("\n\n\t\tStock Updated Successfully ...",3);
                    wait(" ",2);
                    
                    cout << "\t\t--------------------------------------------" << endl;

}

// screen output formatting kelye function
void stockRemoving()
{

    cout << "\t\t--------------------------------------------" << endl;
                    cout<<endl;
                    
                   
                    wait("\t\tWait ... Removing Stock .... ",0);
                    wait("\n\n\t\tStock Removed Successfully ...",3);
                    wait(" ",2);
                    
                    cout << "\t\t--------------------------------------------" << endl;

}

// stock management kelye choice ka function
int stockChoice()
{
      int ch;
      cout<<endl<<endl;
      do
      {
    
      
                    cout << "\t\t----------------------------------------------------------------------------------" << endl;
                    cout << "\t\t|                                                                                |" << endl;
                    cout << "\t\t|     Choose From Following ::                                                   |" << endl;
                    cout << "\t\t|     Press 1 : Add Item to Stock                                                |" << endl;
                    cout << "\t\t|     Press 2 : Remove Item from Stock                                           |" << endl;
                    cout << "\t\t|     Press 3 : Update Any Item                                                  |" << endl;
                    cout << "\t\t|     Press 4 : Search Item                                                      |" << endl;
                    cout << "\t\t|     Press 5 : Return                                                           |" << endl;
                    cout << "\t\t|                                                                                |" << endl;
                    cout << "\t\t----------------------------------------------------------------------------------" << endl;
                    cin>>ch;

              if(ch>=1 && ch<=5)
                   {
             
                      break;
             
                   }
             
                else if(ch<1 || ch>5)
                   {
                      
                      cin.clear(); 
                      cin.ignore(); 
                      rangeerror();
                      continue;
                   }
                    
               }while(ch<1 || ch>5);
      
        return ch;


}

// credentials manage krne kelye choice ka function
int credsChoice()
{
      int ch;
      cout<<endl<<endl;
      do
      {
    
      
                    cout << "\t\t----------------------------------------------------------------------------------" << endl;
                    cout << "\t\t|                                                                                |" << endl;
                    cout << "\t\t|     Choose From Following ::                                                   |" << endl;
                    cout << "\t\t|     Press 1 : Manage Employees Credentials                                     |" << endl;
                    cout << "\t\t|     Press 2 : Manage Students/Staff Credentials                                |" << endl;
                    cout << "\t\t|     Press 3 : Return                                                           |" << endl;
                    cout << "\t\t|                                                                                |" << endl;
                    cout << "\t\t----------------------------------------------------------------------------------" << endl;
                    cin>>ch;

              if(ch>=1 && ch<=3)
                   {
             
                      break;
             
                   }
             
                else if(ch<1 || ch>3)
                   {
                      
                      cin.clear(); 
                      cin.ignore(); 
                      rangeerror();
                      continue;
                   }
                    
               }while(ch<1 || ch>3);
      
        return ch;


}

// stock search krne kelye choice ka function
int stockSearchChoice()
{
      int ch;
      cout<<endl<<endl;
      do
      {
    
      
                    cout << "\t\t----------------------------------------------------------------------------------" << endl;
                    cout << "\t\t|                                                                                |" << endl;
                    cout << "\t\t|     Choose From Following ::                                                   |" << endl;
                    cout << "\t\t|     Press 1 : Search By Name                                                   |" << endl;
                    cout << "\t\t|     Press 2 : Search By Item ID                                                |" << endl;
                    cout << "\t\t|     Press 3 : Search By Price                                                  |" << endl;
                    cout << "\t\t|     Press 4 : Return                                                           |" << endl;
                    cout << "\t\t|                                                                                |" << endl;
                    cout << "\t\t----------------------------------------------------------------------------------" << endl;
                    cin>>ch;

              if(ch>=1 && ch<=4)
                   {
             
                      break;
             
                   }
             
                else if(ch<1 || ch>4)
                   {
                      
                      cin.clear(); 
                      cin.ignore(); 
                      rangeerror();
                      continue;
                   }
                    
               }while(ch<1 || ch>4);
      
        return ch;


}



// scheduled orders ka response krne kelye function
void seeScheduledOrdersAdmin()
{
   
    char HDR1[50],HDR2[50],HDR3[100];

    int* itemID;
    char** itemname;
    int* orderitemprice;
    int* orderquantity;
    int* ID;
    char lines[100];
    char** lines1;
    char liness[100];
    int orderID;
    int totLines2=0;
   
    int id;
    bool idnotfound;


    int totLines=0;



    fstream seeOrders;

    seeOrders.open("ScheduledOrdersStudentID.txt",ios::in);    // orders ki file open ki

    if(!seeOrders)  // check kia file open hui ya ni 
    {
      fileError();
    }
    else
    { 
         cout<<endl<<endl;

         while(seeOrders.getline(liness,100))
         {
            totLines2++;                // lines count ki
         }

          if(totLines2>0)  // agr lines 0 sa ziada hn to
          {
               

             seeOrders.clear();
             seeOrders.seekg(0,ios::beg);  // pointer ko shuru me laya

             ID = new int[totLines2];
             lines1 = new char*[totLines2];

             for(int j=0; j<totLines2; j++)
             {
               lines1[j] = new char[150];
             }
    

             int i=0;
              while(i<totLines2)  // file read kr k store ki
             {
               seeOrders.getline(lines1[i],150,':');
               seeOrders>>ID[i];
               seeOrders.ignore();
               i++;
             }

         seeOrders.close();
         
         // admin ko display krwadia data
         for(int k=0; k<totLines2; k++)
         {
            cout<<lines1[k]<<" "<<ID[k]<<endl;
         }
  

             
  do
  {
   idnotfound=false;

   cout<<"\n\n\t\tEnter Student ID for Responding : ";   // admin sa pucha kis student ko response krna chahta ha
   cin>>id;

   int count=0;

   for(int i=0; i<totLines2; i++)
   {
      if(id==ID[i])   // check kia wo id ha b ya ni
      {
         count++;

      }
      else
      {
       continue;
      }
   }

   if(count==0)    // agr id na mojud hoi to dobara pucha
   {
      idnotfound=true;
      cout<<"\n\n\t\tNo Student Found With Such ID\n\n";
      continue;
   }

}while(idnotfound);  // tb tk chale jb tk id sahi wali na enter krdy admin



   fstream respondOrder;
         
         string filename = "ScheduleOrderID"+to_string(id)+".txt";   // scheduled orders ki file id 

         respondOrder.open(filename,ios::in);

         if(!respondOrder)
         {
          fileError();
         }
         else
        { 

              while(respondOrder.getline(lines,100))
              {
                 totLines++;   // lines count ki
              }
               
                 respondOrder.clear();
                 respondOrder.seekg(0,ios::beg);   // pointer shuru me laya
                
                const int size = totLines-2;   // lines mese 2 minus kia q k pehli 2 lines header hn 
             
               itemID = new int [size];
               itemname = new char*[size];         // initialize ki dynamic arrays
               orderitemprice = new int[size];
               orderquantity = new int [size];


                for(int i=0; i<size; i++)
                {
                  itemname[i] = new char[32];
                }
                
                
                  respondOrder.getline(HDR1,50,':');
                  respondOrder>>orderID;
                  respondOrder.ignore();                     // headers read kiye
                  respondOrder.getline(HDR2,50,'\n');
                  respondOrder.getline(HDR3,100,'\n');
                   
                   int j=0; 

                while(respondOrder>>itemID[j])   // aur phr baki order
                {
                   respondOrder.ignore();
                  respondOrder.getline(itemname[j],32,',');
                  respondOrder>>orderquantity[j]>>orderitemprice[j];
                  j++;

                }

                respondOrder.close();

               int orderID;       
               int sum=0;

                cout<<endl<<endl;

             // admin ko headers display krwae
                cout<<HDR1<<" "<<orderID<<" "<<HDR2<<endl;
                cout<<HDR3<<endl;

                for(int k=0; k<size; k++)  // aur ab baki orders
                {
                  sum=sum+orderitemprice[k];
                  cout<<itemID[k]<<setw(18)<<itemname[k]<<setw(8)<<orderquantity[k]<<setw(15)<<orderitemprice[k]<<endl;
                }
                cout<<setw(35)<<"Total Price : "<<sum;   // sary orders ka  sum b


         string filename1 = "OrderResponseID"+to_string(orderID)+".txt";   // response kelye filename kia
         
         fstream orderesponse;
         
         orderesponse.open(filename1,ios::out);   // file open ki

         if(!orderesponse)
         {
            fileError();
         }
          
         else
         {  
             // aur automatic response krdia student ko
             orderesponse<<"Your Order has been forwarded "<<endl;
             orderesponse<<"Order will be ready "<<HDR2<<" Please arrive at time "<<endl;

             orderesponse.close();


              // memory delete krdi
          for (int j = 0; j < size; j++)
         {
            delete[] itemname[j];
        }

        
        delete[] itemID;
        delete[] orderitemprice;
        delete[] orderquantity;
        delete[] ID;

        
        itemID=NULL;
        orderitemprice=NULL;
        orderquantity=NULL;
        ID=NULL;
         
           }
         }

      }
      // agr lines 0 thi to mtlb koi order ni aya
      else
      {
         cout<<"\n\n\t\tNo Scheduled Orders Placed\n\n";
      }
    } 
    
    cin.ignore();
    cout<<"\n\n\t\tPress Enter to Continue ";
    cin.get();
}

// stock update krne kelye choice
int stockUpdateChoice()
{
      int ch;
      cout<<endl<<endl;
      do
      {
    
      
                    cout << "\t\t----------------------------------------------------------------------------------" << endl;
                    cout << "\t\t|                                                                                |" << endl;
                    cout << "\t\t|     Choose From Following You Want to Update ::                                |" << endl;
                    cout << "\t\t|     Press 1 : Name                                                             |" << endl;
                    cout << "\t\t|     Press 2 : Price                                                            |" << endl;
                    cout << "\t\t|     Press 3 : Quantity                                                         |" << endl;
                    cout << "\t\t|     Press 4 : Everyting                                                        |" << endl;
                    cout << "\t\t|                                                                                |" << endl;
                    cout << "\t\t----------------------------------------------------------------------------------" << endl;
                    cin>>ch;

              if(ch>=1 && ch<=4)
                   {
             
                      break;
             
                   }
             
                else if(ch<1 || ch>4)
                   {
                      
                      cin.clear(); 
                      cin.ignore(); 
                      rangeerror();
                      continue;
                   }
                    
               }while(ch<1 || ch>4);
      
        return ch;


}

// admin apny credentials change krne kelye function
void  changeCreds()
{
     int c;
     char ch;

  do
  {
      // pucha k username ya password change krna ha
     c=credsManageChoice();

     if(c==1)
     {
        changeAdminUser();   // agr username change krna hua
       
     }

     else
     {
        changeAdminPass();  // agr password change krna hua
     }

      do
             {            
                     cout << "\n\n\t\tDo you want to Change Again? Y/N : ";
                     cin >> ch;

                    } while ((ch!= 'y' && ch!= 'Y') && (ch!= 'n' && ch!= 'N'));

       
      }while((ch== 'Y' || ch== 'y'));  

     
}   

// sales ki file dekhne kelye
void seeSales()
{
    int sum=0;
    char HDR[100];
    int* item_ID;
    char** Names;
    int* Sales;
    double* Average;
    int tot_lines=0;
    char lines[100];

    fstream salesTrack;

    salesTrack.open("SalesRecord.txt",ios::in);

    if(!salesTrack)
    {
      fileError();
    }
    
    else
    {

         while(salesTrack.getline(lines,100))
         {
            tot_lines++;
         }

           salesTrack.clear();
           salesTrack.seekg(0,ios::beg);

         const int size = tot_lines-1;

         item_ID = new int[size];
         Names = new char*[size];
         Sales = new int[size];
         Average = new double[size];

         for(int i=0; i<size; i++)
         {
            Names[i]= new char[32];
         }

         int j=0;

         salesTrack.getline(HDR,100,'\n');

         while(salesTrack>>item_ID[j])
         {
            salesTrack.ignore();
            salesTrack.getline(Names[j],32,',');
            salesTrack>>Sales[j]>>Average[j];
            j++;
         }

         salesTrack.close();

         cout<<endl<<endl;

         cout<<HDR<<endl;
         for(int k=0; k<size; k++)
         {
            sum=sum+Sales[k];
            cout<<item_ID[k]<<setw(18)<<Names[k]<<setw(8)<<Sales[k]<<setw(8)<<Average[k]<<endl;
         }
            
         cout<<"\n\n\t\t\tTotal Sales : "<<sum<<endl;

         for(int j=0; j<size; j++)
        {
          delete[]Names[j];
        }

        delete[]Names;
        delete[]item_ID;
        delete[]Sales;
        delete[]Average;


    }

    cin.ignore();
    cout<<"\n\n\t\tPress enter to continue ...";
    cin.get();

}

// best employee dekhne kelye
void seeBestEmployees()
{

    int* SALES;
    int* ID;
    char charid[10];
    char charsales[10];
    char lines[50];

    int totLines=0;

    fstream readSales;

    readSales.open("EmployeesSales.txt",ios::in);  // sales ki file open ki

    if(!readSales)
    {
      fileError();
    }
    else
    {
        while(readSales.getline(lines,50,'\n'))
        { 
         totLines++;   // lines count ki
        }
       
          readSales.clear();
          readSales.seekg(0,ios::beg);   // pointer ko shuru me layaa
            
         SALES = new int[totLines];
         ID = new int[totLines];
          
          int i=0;
          // file reading
         while(readSales.getline(charid,10,':'))
         {
            readSales>>ID[i];
            readSales.ignore();
            readSales.getline(charsales,10,':');
            readSales>>SALES[i];
            readSales.ignore();
            i++;
         }

         readSales.close();   // file close
              
           int max;         
 
           max=SALES[0];    // let kia sales[0] sb sa barha ha

          int p=0;
         for(int i=1; i<totLines; i++)
         {
              if(SALES[i]>max)   // agr koi aur barha ho max sy to
              {
                p=i;   // index record krly
              }
              else
              continue;
         }

      fstream bestemployee;
     char lines[100];
     int totLines=0;

     bestemployee.open("EmployeesCreds.txt",ios::in);    // file reading kelye
     
     if(!bestemployee)
     {
      fileError();
     }
     else
     {
            
            while(bestemployee.getline(lines,100))
            {
               totLines++;   // lines count ki
            }

             bestemployee.clear();
              bestemployee.seekg(0, ios::beg);   // pointer shuru me laya

            const int size=totLines/3;   // lines ko divide by 3 kia q k data 3 k pair me ha

            char chID[10];
            char** user;
            char** pass;
            int* empID;

            user = new char*[size];
            pass  = new char*[size];
            empID = new int[size];

            for(int i=0; i<size; i++)
            {
               user[i]= new char[32];
               pass[i] = new char[32];
            }  

            int j=0;
            
            while(bestemployee>>chID>>empID[j])  // file reading
            {

               bestemployee.ignore();
               bestemployee.getline(user[j],32,'\n');
               bestemployee.getline(pass[j],32,'\n');

               j++;
            }
  
           bestemployee.close();  // file close

           for(int k=0; k<size; k++)
           {
              if(k==p)   // us index pe jo user hoga wo print krwa dega aur uski sales b
              {
                 cout<<endl<<endl;
                 cout<<"\n\n\t\tBest Employee is : "<<user[k]<<endl<<"\n\n\t\tID : "<<empID[k]<<endl;
                 cout<<"\n\n\t\tHis Total Sales are : "<<SALES[k]<<endl;
              }
              else
              continue;
           }

           // deleting memory
         for(int i=0; i<size; i++)
            {
               delete[]user[i];
               delete[]pass[i];
            } 
            
            delete[]user;
             delete[]pass;
              delete[]empID;
         
       
    }

           delete[] SALES;
           delete[] ID;

          SALES=NULL;
          ID=NULL;


}
    cin.ignore();
    cout<<"\n\n\t\tPress enter to continue ...";
    cin.get();

}

// notifications show krwany ka function
void displayNotifications()
{
     
       int ch;
        
      int c;
    
       ch=notificationMenu();  // notifications ki choice

     if(ch==1)
     {
          notificationsWriteDEL();  // agr admin delete krna chahe sary notifications to
          c=notificationChoice();
    
    
     }
     else
     {
         notificationsWriteAPP();  // aur agr udr hi add krna chahe
         c=notificationChoice();
    
     }


      if(c==1)
      {    
             displayNotifications();
      }

      else 
      {
           return ;
      }

 
    
}

// notifications choice lene ka function
int notificationChoice()
{

        int ch;
          
          do
        {  
          cout<<"\n\n\t\tPress 1: Add More Notifications ";
          cout<<"\n\n\t\tPress 2: Return ";
          cin>>ch;
                    
                 if(ch>=1 && ch<=2)
                   {
             
                      break;
             
                   }
             
                else if((ch<1 || ch>2) )
                   {
                   
                     cin.clear();
                     cin.ignore();
                     rangeerror();
                
                   }
              
                 }
                    while(ch<1 || ch>2);
      
      return ch;
      


   
}

// notifications ka menu
int notificationMenu()
{
    
      int ch;
      do
        {
               cout<<"\n\n\t\tPress 1: Add Notifications and Delete Previous ";
               cout<<"\n\n\t\tPress 2: Add Notifications and Join to Previous ";
               cin>>ch;
 
                    
                 if(ch>=1 && ch<=2)
                   {
             
                      break;
             
                   }
             
                else if((ch<1 || ch>2) )
                   {
                   
                     cin.clear();
                     cin.ignore();
                     rangeerror();
                
                   }
              
                 }
                    while(ch<1 || ch>2);
      
      return ch;
      
}

// students ki complains dekhne ka function
void seeComplaints()
{
 char ch;

    fstream readComp; 
    readComp.open("Complains.txt",ios::in);  // file open ki
    char**time;
    char**IDchar;
    int *ID;
    char**Comp;
    int totLines = 0;
    int i = 0;
    char lines[100];

    if (!readComp)    // checking agr open ni hui
    {
        fileError();
    }
     else 
    {
        
        while(readComp.getline(lines,100)) 
      {
            totLines++;  // lines count ki
        }
      
        readComp.clear();
        readComp.seekg(0, ios::beg);  // pointer ko shuru me legaya

        if(totLines>0)
        {

        time = new char*[totLines];
        IDchar = new char*[totLines];
        Comp = new char*[totLines];
        ID = new int [totLines];

        for (int l = 0; l < totLines; l++) 
        {
            time[l] = new char[32];
            IDchar[l] = new char[32];
            Comp[l] = new char[1000];
        }

// complains read kr rha hu
 while(readComp.getline(time[i],30,'\n'),readComp.getline(IDchar[i],32,' '),readComp>>ID[i])
     {  
       readComp.ignore();
       readComp.getline(Comp[i],1000,'\n'); 
       i++;    
    } 
           
           // complains print krwa di admin ko
        cout << endl << endl << "\t\t --------- Complains ------------ " << endl << endl;

        for (int k = 0; k < i; k++) 
        {
            cout << time[k] << endl << IDchar[k] << " " << ID[k] << endl  << Comp[k] << endl << endl;
        }
       


     int id;
     id=responseID(ID,totLines);  // response kelye id puchny ka function
 

   cin.ignore();
   fstream respondComp;
   string filename="ResponseTOStudentID"+to_string(id)+".txt";      // wo file banai

   respondComp.open(filename,ios::out);  // file open ki

   if(!respondComp)  // check kiaa open hui ya ni
   {
      fileError();
   }
   else
   { 

        char response[100];

       cout<<"\n\n\t\tWrite Response : ";  // response likha admin
       cin.getline(response,100);

       // wo response ID k sath write hojae file pe
       respondComp<<currenttime()<<endl<<"Dear Costumer, ID No "<<id<<","<<endl<<response<<"\nThanks for reaching out us";

       respondComp.close();

       
 
        
    
   
    // memory delete ki
        for (int j = 0; j < totLines; j++) 
        {
            delete[] time[j];
            delete[] IDchar[j];
            delete[] Comp[j];
        }

        delete[] time;
        delete[] IDchar;    
        delete[] Comp;

        time=NULL;
        Comp=NULL;
        IDchar=NULL;

        readComp.close();
   }
        }
        else
        cout<<"\n\n\t\tNo Complains\n\n";
   
   cout<<"\n\n\t\tPress any key to continue...";
   cin.get();
          
   }   
}
// credentials change kelye choice ka function
int credsManageChoice()
{
    
    int ch;
    
          do
        {  
             cout<<"\n\n\t\tPress 1: Change UserName ";
             cout<<"\n\n\t\tPress 2: Change Password ";
             cin>>ch;
                    
                 if(ch>=1 && ch<=2)
                   {
             
                      break;
             
                   }
             
                else if((ch<1 || ch>2) )
                   {
                   
                     cin.clear();
                     cin.ignore();
                     rangeerror();
                
                   }
              
                 }
                    while(ch<1 || ch>2);
      
      return ch;
   


}

// complain ka response dene kelye admin sa id lene ka function
int responseID(int ID[], int totLines)
{


   int count;
   int id;
    do{
     cout<<"\n\n\t\tEnter Student ID of Costumer you want to respond Complain : ";  // id likhega admin
     cin>>id;
     count=0;


   for(int i=0; i<totLines/3; i++)
   { 
        if(id==ID[i])   // check kia wo id ha b ya ni
        {
          count++;
          break;
        }
        else
        continue;
   }
       

   if(count==0)  // agr ni ha to dobara puchega
   {
         cin.clear();
         cin.ignore();
         continue;
   }
   else 
   {
      break;
   }

}while(count==0);

return id;

}

void waitSuccess()
{
   
                   cout << "\t\t--------------------------------------------" << endl;
                    cout<<endl;
                    
                   
                    wait("\t\tWait ... Verifying Credentials .... ",0);
                    wait("\n\n\t\tLogin Successful ...",3);
                    wait("\n\n\t\tOpening Admin Account ...",0);
                    wait(" ",2);
                    
                    cout << "\t\t--------------------------------------------" << endl;


}

void waitFail()
{

               cout << "\t\t--------------------------------------------" << endl;
                    cout<<endl;
                    
                   
                    wait("\t\tWait ... Verifying Credentials .... ",0);
                    wait("\n\n\t\tLogin Failed ...",3);
                    cout<<"\n\n\t\tInvalid Username or Password \n";
                    
                    cout << "\t\t--------------------------------------------" << endl;


}
