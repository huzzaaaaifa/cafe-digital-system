#include "proj.h"
#include "Stdnts.h"
int StdntID;
char Stdntusr[32];
char Stdntswd[32];


void loginPageStudent()
{

             int c;
                    
                    char crusr[32];
                    char crpswd[32];                  
                    char user[32];
                    char pass[32];
                    int IDint;
                    char IDchar[32];
                    char readUser[32];
                    char readPass[32];
                    int i=0;
                    int n=0;
                    fstream writeStdntCreds;
                    fstream readStdntCreds;
                   
                    do
                    {
                         
                          c=accountChoiceStdnt();  // account ki choice create ya sign in
                          cin.ignore();

                  if(c>=1 && c<=2)

                    {
                    
                    if(c==1)  // agr account create choose kre
                    {
                      
                       bool usernametaken;
                   do{
                            usernametaken=false;


                    cout<<"\n\t\t             [SIGN UP PAGE] \n";    
                    cout << "\t\t--------------------------------------------" << endl;
                    cout << "\t\t|                                          |" << endl;
                    cout << "\t\t|      [Create Account]                    |" << endl;
                    
                    cout << "\t\t|                                          |" << endl;
                    cout << "\t\t|      UserName : ";                   
                    cin.getline(crusr,32);
                    
                    cout << "\t\t|      Password : ";
                    cin.getline(crpswd,32);
                    cout << "\t\t|                                          |" << endl;
                    cout << "\t\t|                                          |" << endl;
                    cout << "\t\t--------------------------------------------" << endl;
                     
                     

                     readStdntCreds.open("StudentsCreds.txt",ios::in);  // credentials ki file open ki

                       if(!readStdntCreds)
                      {
                          fileError();
                      }
                      else
                      {
                        while (readStdntCreds >> IDchar >> IDint >> readUser >> readPass)  // file reading
                         {
                              i++;

                              if(strcmp(readUser,crusr)==0)  // agr pehle sa wo username kisi ka ha to taken ka message de aur dubara puche
                              {
                                   
                                   cout<<"\n\n\t\tUserName Taken!! Please Write Anyother"<<endl;
                                   usernametaken=true;
                                  
                              }
                                 
                            }
                        
                       
                       readStdntCreds.close();
                      }

                   }while(usernametaken); // tb tk jb tk correct username na likh ly

                       CreationSuccess();

                       writeStdntCreds.open("StudentsCreds.txt",ios::out | ios::app); // file open ki dubara

                     if(!writeStdntCreds)
                     {                       
                         fileError();
                     }
                    else
                    {
                        // automatically id assign kr k credentials write krdiye file me   
                        cout<<"\n\n\t\tOur esteemed Student You are assigned ID : "<<IDint+1<<" Please Don't Forget it\n\t\tUse it to Sign In "<<endl<<endl<<endl;
                      
                         writeStdntCreds<<"ID: "<<IDint+1<<endl<<crusr<<endl<<crpswd<<endl;

                         writeStdntCreds.close();
                    }

                    cout<<"\n\n\t\tNow Sign in to Continue To Use CDS \n";
                    
                    n++; // n me increment kia
                   }
                     
  
                    if(c==2 || n==1)  // agr sign choose kia ya account create krlia successfully
                    {
                       
                          
                         int count;

                    cout<<"\n\t\t             [SIGN IN PAGE] \n";
                    cout << "\t\t----------------------------------------------------------------" << endl;
                    cout << "\t\t|                                                              |" << endl;
                    cout << "\t\t|     [Sign In]                                                |" << endl;
                    cout << "\t\t|                                                              |" << endl;
                    cout << "\t\t|      ID : ";
                    cin>>StdntID;
                    cin.ignore();
                    cout << "\t\t|      UserName : ";                   
                    cin.getline(Stdntusr,32);
                    cout << "\t\t|      Password : ";
                    cin.getline(Stdntswd,32);
                    cout << "\t\t|                                                              |" << endl;
                    cout << "\t\t|                                                              |" << endl;
                    cout << "\t\t----------------------------------------------------------------" << endl;
   
                         // creds function me pass kiye check krny kelye
                          count=studentLogin(Stdntusr,Stdntswd,StdntID);
                           
                        
                           
                         if(count==3)  // agr 3 return hota ha to login success
                         {
                            loginSuccessStdnt();
                            return;
                          }
                        else
                          {
                              int ch;
                             loginFail();  // ni to 2 choices di student ko
                       
                            ch=failChoice();
                          
                       
                       if(ch>=1 && ch<=2)
                        {
             
                            if(ch==1)  // agr exit choose kiaa
                            {
                                   exitmsg();
                                   cout<<endl<<endl;
                                   exit(1);

                            }


                            else // agr dobara login krna hua
                            {
                                loginPageStudent();

                            }

             
                         }


                      }
                    
                }
            }
              else // range k bahir dene pr error
              {
                   cin.clear(); 
                   cin.ignore(); 
              
                   rangeerror();
                   continue;
              }

                    }while(c<1 || c>2);
}
 
// complains register krny ka function 
void giveComplaints()
{ 
     cin.ignore();

     fstream writeComplain;
     char comp[100];
     char name[32];
     
     writeComplain.open("Complains.txt",ios::out | ios::app); // complains ki file open ki

     cout<<"\n\n\t\tWrite Complain : "; //complain write krwai student sy
     cin.getline(comp,100);

     writeComplain<<currenttime()<<"StudentID: "<<StdntID<<endl<<"Complain : "<<comp<<endl; // file me write krwadi complain
      
     writeComplain.close();

     cout<<"\n\n\t\tComplain Sent to Admin";
     cout<<"\n\t\tWait for Response ...";

     cin.ignore();
     cout<<"\n\n\t\tPress enter to continue ...";
     cin.get();


}


// scheduled orders dene ka function
void scheduleOrders()
{

     cin.ignore();    
     char timee[32];
     cout<<"\n\n\t\tEnter Time for order [Hours : Minutes AM/PM] : "; // user sa time pucha
     cin.getline(timee,32,'\n');

     fstream schedule;
     string filename = "ScheduleOrderID"+to_string(StdntID)+".txt";  // uski id k name sa file banai
 
     schedule.open(filename,ios::out);

    if(!schedule)
    {
      fileError();
    }
    else
    {
       char ch;
       int n=0;
       int quant;
       int itemprice;
       int id;
       int sum=0;
       char** name;
        int* price;
        int* quantity;
         int* tot_price;
         int* item_ID;
         char HDR[100];

do
{

 

   int totLines=0;
   cout<<endl<<endl;
   cout<<"-------------- MENU --------------"<<endl<<endl;

    fstream stockReadStdnts;
    char lines[100];
    stockReadStdnts.open("Stocks.txt",ios::in);  // user ko menu show krwany kelye stocks ki file open ki
   
    if (!stockReadStdnts) 
    {
        fileError();
    }
     else 
    {
        
        while(stockReadStdnts.getline(lines,100)) 
      {
            totLines++;  // lines count ki
        }
       
        stockReadStdnts.clear();
        stockReadStdnts.seekg(0, ios::beg); // pointer start me legaya

        
        name = new char*[totLines];
        price = new int[totLines];
        quantity = new int[totLines];  // dynamic arrays initialize ki
        tot_price=new int[totLines];
        item_ID = new int[totLines];

        for (int l = 0; l < totLines; l++) 
        {
            name[l] = new char[32];
        }
   
   int i=0;
   stockReadStdnts.getline(HDR,100,'\n');  // header read kia

   while(stockReadStdnts>>item_ID[i]) // baki file read krdi
     {  
       stockReadStdnts.ignore();
       stockReadStdnts.getline(name[i],32,',');
       stockReadStdnts>>price[i]>>quantity[i]>>tot_price[i];
       stockReadStdnts.ignore();
       i++;
         
    } 

   
       stockReadStdnts.close();
 
          // user ko menu display krwadia
            cout<<"Item_ID"<<"       Name"<<"       PRICEperITEM"<<endl;
            for (int k = 0; k < totLines-1; k++) 
          {
            cout<<item_ID[k]<<setw(18)<<name[k]<<setw(10)<<price[k]<<endl;  
          }
       
   }
   
   bool idnotfound;
   int posi;
   bool ordersuccess;

do
{

   idnotfound=false;

   cout<<"\n\n\t\tEnter ItemID : ";  // user sa item ki id puchi jo khareedna
   cin>>id;

   int count=0;

   for(int i=0; i<totLines-1; i++)
   {
      if(id==item_ID[i])  // check kia wo id ha b ya ni
      {
         count++;
         posi=i;

      }
      else
      {
       continue;  
      }
   }

   if(count==0)  // agr ni ha to bar bar puchy
   {
      idnotfound=true;
      cout<<"\n\n\t\tNo Item Found With Such ID\n\n";
      continue;
   }

}while(idnotfound);

bool quantitynotfound;

do
{
    char ch;
   quantitynotfound=false;

   cout<<"\n\n\t\tEnter Quantity : ";  // quantity puchi user sy
   cin>>quant;

   if(quantity[posi]<quant)  // agr stocks me mojud quantity sa ziada mangi ho user ny
   {  
      quantitynotfound=true;

    do
      {    
        cout<<"\n\n\t\tQuantity is less than your demand. Do you want to enter again [Y] or cancel order [N] ? ";  // cancel order ya dobara puchny ki choice
        cin>>ch;
      } while ((ch!= 'y' && ch!= 'Y') && (ch!= 'n' && ch!= 'N'));
        
        if(ch=='Y'||ch=='y') // agr yes kre to dobara quantity puchy
        {
            continue;
        }
        else
        {
         ordersuccess=false;  // agr no kry to order cancel krde
         break;
        }

       
      
   }
   else
   {
     ordersuccess=true;
     break;
   }
}while(quantitynotfound);

if(ordersuccess) // agr order cancel ni hua to
{
   
     itemprice=quant*price[posi];  // price nikal li 
     sum=sum+itemprice;  // sath sath total price kelye sum krdia

  if(n==0)  
  { 
     // aur file me write krta gya order
     schedule<<"Order Scheduled by StudentID: "<<StdntID<<" for time : "<<timee<<endl;
     schedule<<"Item_ID       Name       Quantity       Total Price PER Item"<<endl; 
     schedule<<id<<" "<<name[posi]<<", "<<quant<<" "<<itemprice<<endl;
  }
  else
  {
   schedule<<id<<" "<<name[posi]<<", "<<quant<<" "<<itemprice<<endl;
  }
   
   n++;

   
                 // choice puchi k aur add krna chahta ha ya ni
           do
                {    
                     cin.ignore(); 
                     cout << "\n\n\t\tDo you want to Add More Items to Order ? Y/N : ";
                     cin >> ch;
                     

                    } while ((ch!= 'y' && ch!= 'Y') && (ch!= 'n' && ch!= 'N'));

      // agr krna hua to continue hojaega  
    if(ch=='y'||ch=='Y')
    {                  
           continue;
    }
    // ni to bill total ho k  ajaega
    else
    {
         char lines[100];
         char HDR[100],HDR1[100];
         fstream orderConfirm;

         string filename = "ScheduleOrderID"+to_string(StdntID)+".txt";

         orderConfirm.open(filename,ios::in);  // wapis file open ki 

         if(!orderConfirm)
         {
          fileError();
         }
         else
        { 
             cout<<endl<<endl<<endl;
             cout<<"\n\n\t------------ BILL ----------------"<<endl<<endl;  // bill display krwa dia
              orderConfirm.getline(HDR,100,'\n');
              orderConfirm.getline(HDR1,100,'\n');
              cout<<HDR1<<endl;
              int i=0;
            
                while(orderConfirm.getline(lines,100,' '))  // sath sath store kia aur cout krdia
                {
                    cout<<lines<<setw(15);
                    i++;
                }

                orderConfirm.close();

                 
                cout<<endl;

                for(int k=0; k<i; k++)
                {
                  cout<<lines;
                }
                cout<<setw(30)<<"Total Price : "<<sum;  // akhir me total price b dikhai user ko


       cout<<"\n\n\t\tPress Enter to continue ...";
       cin.get();

           
                   
      fstream orderWrite;
      orderWrite.open("ScheduledOrdersStudentID.txt",ios::out | ios::app);  // user ka order file me note krlia

      if(!orderWrite)
      {
         fileError();
      }
      else
      {
               orderWrite<<"Scheduled Order Placed By Student ID: "<<StdntID<<endl;

               orderWrite.close();


       cin.ignore();
       cout<<"\n\n\t\tOrder Completed and Sent to Employees....";
       cout<<"\n\n\t\tWait for Response \n";
       cout<<"\n\n\t\tPress Enter to continue ...";
       cin.get();
       return;
    }
  
  }
 }
}
else
{
     cin.ignore();
     cout<<"\n\n\t\tOrder Cancelled Successfully";
     cout<<"\n\n\t\tPress Enter to continue ...";
     cin.get();
    
}

   // memory deleting
   for (int j = 0; j < totLines-1; j++)
         {
            delete[] name[j];
        }

        delete[] name;
        delete[] tot_price;    
        delete[] item_ID;
        delete[] quantity;
        delete[] price;
   

    }while(ch=='y'||ch=='Y');

      schedule.close();  
   }
  
}

// simple order kelye
void order()
{
  
    cout<<"\n\n\t\tWelcome!! Enter your order ";


    char ch;
    int n=0;
    int id;
    int quant;
    int itemprice;
    
  
    int sum=0;
    char** name;
   int* price;
   int* quantity;
   int* tot_price;
   int* item_ID;
   char HDR[100];
   fstream bill;
   string filename = "BillID"+to_string(StdntID)+".txt";   // user ki id wali file banai
   bill.open(filename,ios::out);

do
{

 

   int totLines=0;
   cout<<endl<<endl;
   cout<<"-------------- MENU --------------"<<endl<<endl;  // user ko menu show krwaya
    fstream stockReadStdnts;
    char lines[100];
    stockReadStdnts.open("Stocks.txt",ios::in);  // stocks ki file open ki
   
    if (!stockReadStdnts) 
    {
        fileError();
    }
     else 
    {
        
        while(stockReadStdnts.getline(lines,100)) 
      { 
            totLines++;   // lines count ki
        }
       
        stockReadStdnts.clear(); 
        stockReadStdnts.seekg(0, ios::beg);  // pointer start me laya
          
          const int size = totLines-1;
        
        name = new char*[size];
        price = new int[size];
        quantity = new int[size];    // dynamic arrays initialize ki
        tot_price=new int[size];
        item_ID = new int[size];
         

        for (int l = 0; l < size; l++) 
        {
            name[l] = new char[32];
        }
   
   int i=0;
   stockReadStdnts.getline(HDR,100,'\n');    // header read krdia

   while(stockReadStdnts>>item_ID[i])   // baki file b read ki
     {  
       stockReadStdnts.ignore();
       stockReadStdnts.getline(name[i],32,',');
       stockReadStdnts>>price[i]>>quantity[i]>>tot_price[i];
       stockReadStdnts.ignore();
       i++;
         
    } 

   
       stockReadStdnts.close();

           // user ko menu display krwadia
            cout<<"Item_ID"<<"       Name"<<"       PRICEperITEM"<<endl;
            for (int k = 0; k < size; k++) 
          {
            cout<<item_ID[k]<<setw(18)<<name[k]<<setw(10)<<price[k]<<endl;  
          }
       
   
   bool idnotfound;
   int pos;
   bool ordersuccess;

do
{

   idnotfound=false;

   cout<<"\n\n\t\t Enter ItemID : ";   // user sa item ki id puchi
   cin>>id;
   int count=0;
   
   for(int i=0; i<size; i++)
   {
      if(id==item_ID[i])  // check kia wo id ha b ya ni
      {
         count++;
         pos=i;

      }
      else
      {
       continue;
      }
   }

   if(count==0)  // agr id ni mili to dobara puchega
   { 
      idnotfound=true;
      cout<<"\n\n\t\t No Item Found With Such ID\n\n";
      continue;
   }

}while(idnotfound);

bool quantitynotfound;

do
{
    char ch;
   quantitynotfound=false;
  
    
        cout<<"\n\n\t\t Enter Quantity : ";  // quantity puchi user sy
         cin>>quant;
      

   if(quantity[pos]<quant)  // check kia demanded quantity stocks me parhi quantity sa ziada to ni
   {  
      quantitynotfound=true;
     
    do  // agr ha to choice di cancel order ya enter again
      {
        cout<<"\n\n\t\t Quantity is less than your demand. Do you want to enter again [Y] or cancel order [N] ? ";
        cin>>ch;

        } while ((ch!= 'y' && ch!= 'Y') && (ch!= 'n' && ch!= 'N'));
        

        if(ch=='Y'||ch=='y')  // agr dobara quantity enter krna hua
        {
            continue;
        }
        else  // ni to order cancel
        {
         ordersuccess=false;
         break;
        }
 
   }
   else
   {
     ordersuccess=true;
     break;
   }
}while(quantitynotfound);

// agr ordersuccess true hua to 
if(ordersuccess)
{    
       
     itemprice=quant*price[pos];  // items ki price calculate ki
     sum=sum+itemprice;          // sath sath sum b calculate kia


  if(n==0)  // bill wali file  order write krwadia
  {
     bill<<"Item_ID       Name       Quantity       Total Price PER Item"<<endl; 
     bill<<id<<" "<<name[pos]<<", "<<quant<<" "<<itemprice<<endl;
  }
  else
  {
   bill<<id<<" "<<name[pos]<<", "<<quant<<" "<<itemprice<<endl;
  }
   
  
   n++;
            // user sa pucha k aur items b order krne han ya ni
           do
                {    
                     cin.ignore(); 
                     cout << "\n\n\t\tDo you want to Add More Items to Order ? Y/N : ";
                     cin >> ch;
                     

                    } while ((ch!= 'y' && ch!= 'Y') && (ch!= 'n' && ch!= 'N'));


if(ch=='y'|| ch=='Y')  // agr karne huye to continue hojae
{
   continue;
}
else  // ni to bill generate krdy
{
     bill.close();
    
          showBill(sum,item_ID,price,quantity,tot_price,name,HDR);  // bill dikhane ka function

         
         cout<<"\n\n\t\t Thanks for choosing us!! Come Again\n\n";

         fstream orderWrite;
      orderWrite.open("OrdersStudentID.txt",ios::out | ios::app);  // orders ki file open kr k orders note krlie

      if(!orderWrite)
      {
         fileError();
      }
      else
      {
               orderWrite<<" Order Placed By Student ID: "<<StdntID<<endl;

               orderWrite.close();

      }
}
    
} 
else // agr ordersuccess false hua to order cancel
{
     cin.ignore();
     cout<<"\n\n\t\tOrder Cancelled Successfully";
     cout<<"\n\n\t\tPress Enter to continue ...";
     cin.get();
}
  // memory deletion
  for (int j = 0; j < size; j++)
         {
            delete[] name[j];
        }

        delete[] name;
        delete[] tot_price;   
        delete[] quantity;
        delete[] price;
        delete[] item_ID;
        name=NULL;
        tot_price=NULL;
        price=NULL;
        item_ID=NULL;
        quantity=NULL;  


      }
    }while(ch=='y'|| ch=='Y');

  } 

// bill function
void showBill(int sum, int* item_ID, int* price, int* quantity, int* tot_price, char** name,char HDR[])
{

    int* itemID;
     char** itemname;
     int* orderitemprice;
     int* orderquantity;
     char lines[100];
     char liness[150];

     fstream readbill;
     int totLines=0;
     string filename = "BillID"+to_string(StdntID)+".txt"; // id wali file 

         readbill.open(filename,ios::in);  // bill file open kia

         if(!readbill)
         {
          fileError();
         }
         else
        { 

              while(readbill.getline(lines,100))
              {
                 totLines++;  // lines count ki
              }
               
                 readbill.clear();
                 readbill.seekg(0,ios::beg);  // pointer ko wapis startme laya
                
                 int size = totLines-1;
             
               itemID = new int [size];
               itemname = new char*[size];
               orderitemprice = new int[size];  // dynamic arrays initialize ki
               orderquantity = new int [size];


                for(int i=0; i<size; i++)
                {
                  itemname[i] = new char[32];
                }
                
                
                  readbill.getline(liness,150,'\n');  // header read kia
                   
                   int j=0; 

                while(readbill>>itemID[j]) // aur baki file
                {
                   readbill.ignore();
                  readbill.getline(itemname[j],32,',');
                  readbill>>orderquantity[j]>>orderitemprice[j];
                  j++;

                }

                readbill.close();

            // bill display krwadia user ko
                cout<<endl<<endl;
                cout<<" -------------- BILL ----------------"<<endl;
                cout<<liness<<endl;

                for(int k=0; k<size; k++)
                {
                  cout<<itemID[k]<<setw(18)<<itemname[k]<<setw(8)<<orderquantity[k]<<setw(15)<<orderitemprice[k]<<endl;
                }
                cout<<setw(35)<<"Total Price : "<<sum;

     
       cin.ignore();
       cout<<"\n\n\t\tPress Enter to Confirm Order ...";
       cin.get();
       

       cout<<"\n\n\t\tOrder Booked "<<endl;

        // memory deletion
     for (int j = 0; j < size; j++)
         {
            delete[] itemname[j];
        }

        
        delete[] itemID;
        delete[] orderitemprice;
        delete[] orderquantity;

        
        itemID=NULL;
        orderitemprice=NULL;
        orderquantity=NULL;

  
   }


}

// stock update function
void stockUpdate(int sum, int* item_ID, int* price, int* quantity, int* tot_price, char** name,char HDR[], const int size1)
{
     int* itemID;
     char** itemname;
     int* orderitemprice;
     int* orderquantity;
     char lines[100];
     char liness[150];

     fstream readbill;
     int totLines=0;
         readbill.open("Bill.txt",ios::in);  // bill file open ki

         if(!readbill)
         {
          fileError();
         }
         else
        { 

              while(readbill.getline(lines,100))
              {
                 totLines++;  // lines count ki
              }
               
                 readbill.clear();
                 readbill.seekg(0,ios::beg);
                
                 int size = totLines-1;
             
               itemID = new int [size];
               itemname = new char*[size];        // dynamic arrays initialize ki
               orderitemprice = new int[size];
               orderquantity = new int [size];


                for(int i=0; i<size; i++)
                {
                  itemname[i] = new char[32];
                }
                
                
                  readbill.getline(liness,150,'\n');   // header read kia
                   
                   int j=0; 

                while(readbill>>itemID[j])
                {
                   readbill.ignore();
                  readbill.getline(itemname[j],32,',');
                  readbill>>orderquantity[j]>>orderitemprice[j];
                  j++;

                }

                readbill.close();

                cout<<endl<<endl;

                // bill display krwaya user ko
                cout<<" -------------- BILL ----------------"<<endl;
                cout<<liness<<endl;

                for(int k=0; k<size; k++)
                {
                  cout<<itemID[k]<<setw(18)<<itemname[k]<<setw(8)<<orderquantity[k]<<setw(15)<<orderitemprice[k]<<endl;
                }
                cout<<setw(35)<<"Total Price : "<<sum;

     
       cin.ignore();
       cout<<"\n\n\t\tPress Enter to Confirm Order ...";
       cin.get();
     
       
          
       fstream writeStock;

       writeStock.open("Stocks.txt",ios::out);  
      // stocks update krne kelye

         writeStock<<HDR<<endl;
            for (int k = 0; k < size1; k++) 
          {
             for(int j=0; j<size; j++)
             {
               if(item_ID[k]==itemID[j])  // jahan id match hogi
                { 
                  // wahan pe changes ajaengy
                  quantity[k]-=orderquantity[j];
                  tot_price[k]-=orderitemprice[j];
                }
                else
                {
                  continue;
                }
             }
              
          }
           // changes k bad wapis file write krdi
           for (int k = 0; k < size1; k++) 
          {
            writeStock<<item_ID[k]<<" "<<name[k]<<", "<<price[k]<<" "<<quantity[k]<<" "<<tot_price[k]<<endl;
          }
     
                    
         writeStock.close();
        
         // sales record wali file b update ki
        salesRecord(itemID,orderquantity,size);

       

        // memory delete krdi
     for (int j = 0; j < size; j++)
         {
            delete[] itemname[j];
        }

        
        delete[] itemID;
        delete[] orderitemprice;
        delete[] orderquantity;

        
        itemID=NULL;
        orderitemprice=NULL;
        orderquantity=NULL;

     }
   } 

// without account order kelye
void noAccOrder()
{

    cout<<"\n\n\t\tWelcome!! Enter your order ";


    char ch;
    int n=0;
    int id;
    int quant;
    int itemprice;
    
  
    int sum=0;
    char** name;
   int* price;
   int* quantity;
   int* tot_price;
   int* item_ID;
   char HDR[100];
   fstream bill;

   bill.open("Bill.txt",ios::out);

do
{

 

   int totLines=0;
   cout<<endl<<endl;

   //  menu display krwaya

   cout<<"-------------- MENU --------------"<<endl<<endl;
    fstream stockReadStdnts;
    char lines[100];
    stockReadStdnts.open("Stocks.txt",ios::in);
   
    if (!stockReadStdnts) 
    {
        fileError();
    }
     else 
    {
        
        while(stockReadStdnts.getline(lines,100)) 
      {
            totLines++;   // lines count ki
        }
       
        stockReadStdnts.clear();
        stockReadStdnts.seekg(0, ios::beg);
          
          const int size = totLines-1;
        
        name = new char*[size];
        price = new int[size];
        quantity = new int[size];   // dynamic arrays initialization
        tot_price=new int[size];
        item_ID = new int[size];
         

        for (int l = 0; l < size; l++) 
        {
            name[l] = new char[32];
        }
   
   int i=0; 
   stockReadStdnts.getline(HDR,100,'\n');   // header read krwaya

   while(stockReadStdnts>>item_ID[i])   // baki file read ki
     {  
       stockReadStdnts.ignore();
       stockReadStdnts.getline(name[i],32,',');
       stockReadStdnts>>price[i]>>quantity[i]>>tot_price[i];
       stockReadStdnts.ignore();
       i++;
         
    } 

   
       stockReadStdnts.close();

             // menu show kia
            cout<<"Item_ID"<<"       Name"<<"       PRICEperITEM"<<endl;
            for (int k = 0; k < totLines-1; k++) 
          {
            cout<<item_ID[k]<<setw(18)<<name[k]<<setw(10)<<price[k]<<endl;  
          }
       
   
   bool idnotfound;
   int pos;
   bool ordersuccess;

do
{

   idnotfound=false;

   cout<<"\n\n\t\t Enter ItemID : ";   // id puchi user sy
   cin>>id;
   int count=0;
   
   for(int i=0; i<size; i++)
   {
      if(id==item_ID[i])   // check kia id ha b ya ni
      {
         count++;
         pos=i;

      }
      else
      {
       continue;
      }
   }

   if(count==0)   // agr ni ha to dobara puchi
   {
      idnotfound=true;
      cout<<"\n\n\t\t No Item Found With Such ID\n\n";
      continue;
   }

}while(idnotfound);   // tb tk jb tk sahi id na likh de

bool quantitynotfound;

do
{
    char ch;
   quantitynotfound=false;

   cout<<"\n\n\t\t Enter Quantity : ";   // quantity puchi
   cin>>quant;

   if(quantity[pos]<quant)  //yg agr demanded quantity stocks me mojud quantity sa ziada ha to
   {  
      quantitynotfound=true;

   do{   // choice li agr dobara quantity enter krni ya order cancel krna ha 
      cout<<"\n\n\t\t Quantity is less than your demand. Do you want to enter again [Y] or cancel order [N] ? ";
      cin>>ch;
    }while ((ch!= 'y' && ch!= 'Y') && (ch!= 'n' && ch!= 'N'));
        
        if(ch=='Y'||ch=='y')  // agr dobara enter krna hua
        {
            continue;
        } 
        else  // ni to ordersuccess false
        {
         ordersuccess=false;
         break;
        }
 
   }
   else
   {
     ordersuccess=true;
     break;
   }
}while(quantitynotfound);

// agr order success true hota ha to
if(ordersuccess)
{    
       
     itemprice=quant*price[pos];  // item prce find krli
     sum=sum+itemprice;           // aur sath sath sum b find kia

  if(n==0)
  {
     // bill wali file me write krta gya
     bill<<"Item_ID       Name       Quantity       Total Price PER Item"<<endl; 
     bill<<id<<" "<<name[pos]<<", "<<quant<<" "<<itemprice<<endl;
  }
  else
  {
   bill<<id<<" "<<name[pos]<<", "<<quant<<" "<<itemprice<<endl;
  }
   
  
   n++;


           do
                {    
                     cin.ignore(); 
                     cout << "\n\n\t\tDo you want to Add More Items to Order ? Y/N : ";
                     cin >> ch;

                    } while ((ch!= 'y' && ch!= 'Y') && (ch!= 'n' && ch!= 'N'));

if(ch=='y'|| ch=='Y')
{
   continue;
}
else // agr items add krna band krdie to 
{
     bill.close();
      // bill show krnwana ka aur stocks update krne ka function
      stockUpdate(sum, item_ID,price,quantity,tot_price,name,HDR,size);
          
      cout<<"\n\t\tOrder Booked\n\n";

}
    
} 
else // agr ordersucces false
{
     cin.ignore();
     cout<<"\n\n\t\tOrder Cancelled Successfully";
     cout<<"\n\n\t\tPress Enter to continue ...";
     cin.get();
}
  // memory delete krdi
  for (int j = 0; j < totLines-1; j++)
         {
            delete[] name[j];
        }

        delete[] name;
        delete[] tot_price;   
        delete[] quantity;
        delete[] price;
        delete[] item_ID;
        name=NULL;
        tot_price=NULL;
        price=NULL;
        item_ID=NULL;
        quantity=NULL;  


      }
    }while(ch=='y'|| ch=='Y');

}

// stock serch kelye choice
int stockSearchCh()
{
      int ch;
      cout<<endl<<endl;
      do
      {
    
      
                    cout << "\t\t----------------------------------------------------------------------------------" << endl;
                    cout << "\t\t|                                                                                |" << endl;
                    cout << "\t\t|     Choose From Following ::                                                   |" << endl;
                    cout << "\t\t|     Press 1 : Search By Name                                                   |" << endl;
                    cout << "\t\t|     Press 2 : Search By Price                                                  |" << endl;
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

// items search krny ka functon
void searchITEMS()
{

      char HDR[100];
   char** name;
   int* price;
   int* quantity;
   int* tot_price;
   int* item_ID;

   int totLines=0;

 fstream stockReadStdnts;
    char lines[100];
    stockReadStdnts.open("Stocks.txt",ios::in);  // stocks ki file reading kelye open ki
   
    if (!stockReadStdnts) 
    {
        fileError();
    }
     else 
    {
        
        while(stockReadStdnts.getline(lines,100)) 
      {
            totLines++;   // lines count ki
        }
       
        stockReadStdnts.clear();
        stockReadStdnts.seekg(0, ios::beg);

        
        name = new char*[totLines-1];
        price = new int[totLines-1];
        quantity = new int[totLines-1];   // dynamic arrays initialize ki
        tot_price=new int[totLines-1];
        item_ID = new int[totLines-1];

        for (int l = 0; l < totLines-1; l++) 
        {
            name[l] = new char[32];
        }
   
   int i=0;
   stockReadStdnts.getline(HDR,100,'\n');    // header read kia

   while(stockReadStdnts>>item_ID[i])  // file reading ki
     {  
       stockReadStdnts.ignore();
       stockReadStdnts.getline(name[i],32,',');
       stockReadStdnts>>price[i]>>quantity[i]>>tot_price[i];
       stockReadStdnts.ignore();
       i++;
         
    } 

   
       stockReadStdnts.close();
       
   
      char ch;
      int choice;
  do{
      choice=stockSearchCh();  // stock search kelye choice li

      if(choice==1)  // agr by name search krna hua
      {
         searchbyNameStdnt(totLines-1,name,item_ID,price,quantity,tot_price);
      }

      else if(choice==2)  // agr by price search krna hua
      {
         searchbyPriceStdnt(totLines-1,name,item_ID,price,quantity,tot_price);
      }
      
      else
      {}
          
         
              do  // dobara search krne kelye choice li
                {     
                    
                     cout << "\n\n\t\tDo you want to Search More Items? Y/N : ";
                     cin >> ch;
                     
                    } while ((ch!= 'y' && ch!= 'Y') && (ch!= 'n' && ch!= 'N'));

   }while(ch== 'Y' || ch== 'y');
  
    

              // memory delete krdi
        for (int j = 0; j < totLines-1; j++)
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


}

// by name search krne kelye function
void searchbyNameStdnt(const int size, char **name, int *item_ID, int *price, int *quantity, int *tot_price)
{
   int count=0;

   char nameSearch[32];

   cin.ignore();
   cout<<"\n\n\t\tEnter Name of Item to be Searched : ";   // name pucha user sy
   cin.getline(nameSearch,32);
   cout<<endl<<endl;
   cout<<"Item_ID"<<"       Name"<<"       PRICEperITEM"<<endl;
   for(int i=0; i<size; i++)
   {
      if(strcmp(name[i],nameSearch)==0)   // jaha name mila us index ka sara data show krwadia
      {
         count++;
         cout<<item_ID[i]<<setw(18)<<name[i]<<setw(10)<<price[i]<<setw(14)<<endl;
         break;
      }
      else
      {
       continue;
      }
   }

   if(count==0)
   {
      cout<<"\n\n\t\tNo Item with such Name Found\n\n";   // agr us name ka koi item mila hi ni
   }



  cout<<"\n\n\t\tPress any key to continue...";
  cin.get();
}

// by price search krne kelye function
void searchbyPriceStdnt(const int size, char **name, int *item_ID, int *price, int *quantity, int *tot_price)
{
   int count=0;

   int priceSearch;

   cin.ignore();
   cout<<"\n\n\t\tEnter Price of Item to be Searched : ";  // price puchi user sy
   cin>>priceSearch;
   cout<<endl<<endl;
   cout<<"Item_ID"<<"       Name"<<"       PRICEperITEM"<<endl;
   for(int i=0; i<size; i++)
   {
      if(priceSearch==price[i])   // index find kia price ka aur data display krwadia
      {
         count++; 
         cout<<item_ID[i]<<setw(18)<<name[i]<<setw(10)<<price[i]<<endl;
      }
      else
      {
       continue;
      }
   }

   if(count==0)
   {
     cin.clear();
      cin.ignore();
      cout<<"\n\n\t\tNo Item Found With Such Price\n\n";
   }

 
  cin.ignore();

  cout<<"\n\n\t\tPress any key to continue...";
   cin.get();


}

// account ki choice ka function
int accountChoiceStdnt()
{
    int c;
  
                    do{
                      
                         cout<<"\n\t\t                 [LOGIN PAGE] \n";
                    
                    cout << "\t\t----------------------------------------------------" << endl;
                    cout << "\t\t|                                                  |" << endl;
                    cout << "\t\t|   Press 1 :  Sign Up [New Account]               |" << endl;
                    cout << "\t\t|                                                  |" << endl;
                    cout << "\t\t|   Press 2 :  Sign In [Already have account]      |"<<endl;           
                    cout << "\t\t|                                                  |"<<endl;
                    cout << "\t\t--------------------------------------------------- " << endl;
                    cin>>c;

                  
                    
                   
                    if(c>=1 && c<=2)
                   {
             
                      break;
             
                   }
             
                else if(c<1 || c>2)
                   {
                      
                      cin.clear(); 
                      cin.ignore(); 
                      rangeerror();
                      continue;
                   }
                    
               }while(c<1 || c>2);
                    
             return c;
                    
 

}

// output formatting kelye function
void loginSuccessStdnt()
{
   
    
    
                    cout << "\t\t--------------------------------------------" << endl;
                    cout<<endl;
                    
                   
                    wait("\t\tWait ... Verifying Credentials .... ",0);
                    wait("\n\n\t\tLogin Successful ...",3);
                    wait("\n\n\t\tOpening Student Account ...",0);
                    wait(" ",2);
                    
                    cout << "\t\t--------------------------------------------" << endl;
                    
 

}

// login ki choice ka function
int loginChoiceStdnt()
{
   
   int ch;
      do
      {
    
      
                    cout << "\t\t----------------------------------------------------------------------------------" << endl;
                    cout << "\t\t|                                                                                |" << endl;
                    cout << "\t\t|     Choose From Following ::                                                   |" << endl;
                    cout << "\t\t|     Press 1 : Create Account or Sign In into CDS                               |" << endl;
                    cout << "\t\t|     Press 2 : Continue without Signing into CDS                                |" << endl;
                    cout << "\t\t|     Press 3 : EXIT                                                             |" << endl;
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

// notifications dekhne kelye function
void seeNotifications()
{
    char seeNot[100];
    fstream see;
    int totlines;
    char Lin[200];

    see.open("Notifications.txt",ios::in);  // file open ki reading kelye
    

    if (!see) 
    {
        fileError();
    }
    else
    {
        while (see.getline(Lin,200,'\n'))
        {
          totlines++;  // lines count ki
        }
        
        
   if(totlines>0)  // agr greater than 0 han
   {
      see.clear();
        see.seekg(0, ios::beg);
    cout<<endl<<endl;
    while(see.getline(seeNot,1000,'\n'))  // to print krde sary notifcations
    {
        
         cout<<seeNot<<endl;

    }

    see.close();

   }

   else  // agr 0 hn to mtlb koi notification ni ha
   cout<<"\n\n\t\tNo Notifications\n\n";

    } 

    cin.ignore();
    cout<<"\n\t\tPress Enter to continue ...";
    cin.get();

}

// complain ka response dekhne kelye 
void seeResponse()
{
   
    fstream seeResponse;
    char readResponse[100];
    char lines[200];
    int totlines=0;
    cout<<endl<<endl;
    string filename= "ResponseTOStudentID"+to_string(StdntID)+".txt";   // id wali file 
    seeResponse.open(filename,ios::in);  // open ki

    if(!seeResponse)
    {
      fileError();
    }
    else
    {

        while (seeResponse.getline(lines,200,'\n'))
        {
         totlines++;
        }
        
      if(totlines>0)
      {
         seeResponse.clear();            
        seeResponse.seekg(0, ios::beg); 
        while(seeResponse.getline(readResponse,100,'\n'))
        {
         cout<<readResponse<<endl;
        }
         cout<<endl<<endl;
        seeResponse.close();
    }
    else
    cout<<"\n\n\t\tNo Response from Admin";
     }

     cin.ignore();
     cout<<"\n\n\t\tPress enter to continue ...";
     cin.get();

}

// scheduled orders ka admin sa response dekhne kelye
void seeOrderRes()
{
    fstream seeResponse;
    char lines[200];
    int totlines=0;
    char readResponse[100];
    cout<<endl<<endl;
    string filename= "OrderResponseID"+to_string(StdntID)+".txt";
    seeResponse.open(filename,ios::in);

    if(!seeResponse)
    {
      fileError();
    }
    else
    {
          while (seeResponse.getline(lines,200,'\n'))
          {
            totlines++;
          }
          
          if(totlines>0)
          {

              seeResponse.clear();         
           seeResponse.seekg(0, ios::beg);
        while(seeResponse.getline(readResponse,100,'\n'))
        {
           cout<<readResponse<<endl;
        }

    }
    else
   cout<<"\n\n\t\tNo Response from Admin\n";
   
    cin.ignore();
    cout<<"\n\n\t\tPress Enter to continue ...\n";
    cin.get();
   
    seeResponse.close();
    
    }

}

// student apny credentials change krne ka function
void changeStdntCreds()
{
   
     fstream changeCreds;
     char lines[100];
     int totLines=0;

     changeCreds.open("StudentsCreds.txt",ios::in);  // credentials ki file open ki
     
     if(!changeCreds)
     {
      fileError();
     }
     else
     {
          
            while(changeCreds.getline(lines,100))
            {
               totLines++;   // lines count ki
            }

             changeCreds.clear();
             changeCreds.seekg(0, ios::beg);

            const int size=totLines/3;   // 3 sa divide kia q k data 3 k pair me ha

            char chID[10];
            char** user;
            char** pass;
            int* stdntID;

            user = new char*[size];
            pass  = new char*[size];   // dynamic arrays initialize ki
            stdntID = new int[size];

            for(int i=0; i<size; i++)
            {
               user[i]= new char[32];
               pass[i] = new char[32];
            }  

            int j=0;
            
            while(changeCreds>>chID>>stdntID[j])   // file read ki credentials wali aur store krdi
            {

               changeCreds.ignore();
               changeCreds.getline(user[j],32,'\n');
               changeCreds.getline(pass[j],32,'\n');

               j++;
            }
  
           changeCreds.close();


              int ch;
              ch=empCredsChoice();  // choice li k password change krna ya username

              if(ch==1)  // agr username change krna hua
              {
                  fstream changeUser;
                  char newuser[32];

                  changeUser.open("StudentsCreds.txt",ios::out);

                  if(!changeUser)
                  {
                     fileError();
                  }
                  else
                  {
                     cin.ignore();
                     cout<<"\n\n\t\tEnter New UserName : ";  // newusername pucha
                     cin.getline(newuser,32);

                     for(int i=0; i<size; i++)
                     {
                        if(stdntID[i]==StdntID)  // jahan id mile wahan copy krdia new username aur write back krdia
                        {
                           strcpy(user[i],newuser);
                           changeUser<<chID<<" "<<stdntID[i]<<endl<<user[i]<<endl<<pass[i]<<endl;
                        }
                        else
                        {
                           changeUser<<chID<<" "<<stdntID[i]<<endl<<user[i]<<endl<<pass[i]<<endl;
                        }
                     }
                     changeUser.close();
                  }
                   
                   cout<<"\n\n\t\tUsername changed successfully ...";

              }
              else if(ch==2)  // agr password change krna hua
              {
                
                 fstream changePass;
                  char newpass[32];

                  changePass.open("StudentsCreds.txt",ios::out);

                  if(!changePass)
                  {
                     fileError();
                  }
                  else
                  { 
                     cin.ignore();
                     cout<<"\n\n\t\tEnter New Password : ";  // new password pucha user sy
                     cin.getline(newpass,32);

                     for(int i=0; i<size; i++)
                     {
                        if(stdntID[i]==StdntID)  // jahan id milega waha password change krdega
                        {
                           strcpy(pass[i],newpass);
                           changePass<<chID<<" "<<stdntID[i]<<endl<<user[i]<<endl<<pass[i]<<endl;
                        }
                        else
                        {
                           changePass<<chID<<" "<<stdntID[i]<<endl<<user[i]<<endl<<pass[i]<<endl;
                        }
                     }
                     changePass.close();
                  }

                       cout<<"\n\n\t\tPassword Changed Successfully ";
                     

              }
              
             
            // memory delete krdi
            for(int i=0; i<size; i++)
            {
               delete[]user[i];
               delete[]pass[i];
            } 
            
            delete[]user;
             delete[]pass;
              delete[]stdntID;


     }

   cin.ignore();
   cout<<"\n\n\t\tPress enter to continue ...";
   cin.get();

}

// students k functions ki choice
int studentsCDSFuns()
{
   
    int ch;
         
          do{
                    
                    cout << "\t\t----------------------------------------------------------------------------------" << endl;
                    cout << "\t\t|                                                                                |" << endl;
                    cout << "\t\t|     You are Authorized to do Following Operations ::                           |" << endl;
                    cout << "\t\t|     Press 1 : Order Food                                                       |" << endl;
                    cout << "\t\t|     Press 2 : Give Complaints                                                  |" << endl;
                    cout << "\t\t|     Press 3 : Search Items                                                     |" << endl;
                    cout << "\t\t|     Press 4 : Give and schedule orders                                         |" << endl;
                    cout << "\t\t|     Press 5 : See Notifications                                                |" << endl;
                    cout << "\t\t|     Press 6 : See Complaints Response                                          |" << endl;
                    cout << "\t\t|     Press 7 : See Order Response                                               |" << endl;
                    cout << "\t\t|     Press 8 : Change your Credentials                                          |" << endl;
                    cout << "\t\t|     Press 9 : Return to CDS Menu                                                             |" << endl;
                    cout << "\t\t|                                                                                |" << endl;
                    cout << "\t\t----------------------------------------------------------------------------------" << endl;
                    cin>>ch;
                    
                    
                   
                    if(ch>=1 && ch<=9)
                   {
             
                      break;
             
                   }
             
                else if(ch<1 || ch>9)
                   {
                      
                      cin.clear(); 
                      cin.ignore(); 
                      rangeerror();
                      continue;
                   }
                    
               }while(ch<1 || ch>9);
                    
             return ch;
   


}

// without account functions ki choice
int studentsNoAccFuns()
{
   
    int ch;
         
          do{
                    
                    cout << "\t\t----------------------------------------------------------------------------------" << endl;
                    cout << "\t\t|                                                                                |" << endl;
                    cout << "\t\t|     You are Authorized to do Following Operations ::                           |" << endl;
                    cout << "\t\t|     Press 1 :  Search and Order Food                                           |" << endl;
                    cout << "\t\t|     Give Complaints [SIGN UP TO CDS FOR THIS FEAUTURE]                         |" << endl;
                    cout << "\t\t|     Search Items Through CDS [SIGN UP TO CDS FOR THIS FEAUTURE]                |" << endl;
                    cout << "\t\t|     Give and schedule orders  [SIGN UP TO CDS FOR THIS FEAUTURE]               |" << endl;
                    cout << "\t\t|     See Notifications [SIGN UP TO CDS FOR THIS FEAUTURE]                       |" << endl;
                    cout << "\t\t|     See Complaints Response [SIGN IN TO CDS FOR THIS FEAUTURE]                 |" << endl;
                    cout << "\t\t|     Press 2 : Return to CDS Menu                                                             |" << endl;
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

