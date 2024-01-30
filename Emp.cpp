#include "proj.h"
int EmpID;
char Empusr[32];
char Emppswd[32];

void loginPageEmp()  // login page
{
                    int c;
                    int n=0;
                    char crusr[32];
                    char crpswd[32];                  
                    char user[32];
                    char pass[32];
                    int IDint;
                    char IDchar[32];
                    char readUser[32];
                    char readPass[32];
                    int i=0;
                    fstream writeEmpCreds;
                    fstream readEmpCreds;
                   
                    do
                    {
                         
                          c=loginchoiceEmp();  // choice li new account banana ya sign in krna
                          cin.ignore();

                  if(c>=1 && c<=2)  
                    {
                    
                    if(c==1)  // agr create account krna hua
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
                     
                     

                     readEmpCreds.open("EmployeesCreds.txt",ios::in);  // credentials wali file open ki

                       if(!readEmpCreds)
                      {

                          fileError();
                      }
                      else
                      {
                        while (readEmpCreds >> IDchar >> IDint >> readUser >> readPass)  // data read kia
                         {
                              i++;

                              if(strcmp(readUser,crusr)==0)  // agr same username mile kisika to error de k dobara puchy
                              {
                                   
                                   cout<<"\n\n\t\tUserName Taken!! Please Write Anyother"<<endl;
                                   usernametaken=true;
                              }
                                 
                            }
                        
                       
                       readEmpCreds.close();
                      }

                   }while(usernametaken);

                       CreationSuccess();

                      
                       writeEmpCreds.open("EmployeesCreds.txt",ios::out | ios::app);  // file me credentials add krne kelye
                       writeEmpCreds.seekp(0,ios::end);

                     if(!writeEmpCreds)
                     {
                        
                         fileError();

                     }
                    else
                    {
                        // automatically id generate kr k data add krdia
                        cout<<"\n\n\t\tOur esteemed Employee You are assigned ID : "<<IDint+1<<" Please Don't Forget it "<<endl<<endl<<endl;
                      
                         writeEmpCreds<<"ID: "<<IDint+1<<endl<<crusr<<endl<<crpswd<<endl;

                         writeEmpCreds.close();

                          fstream writeSales;

                        writeSales.open("EmployeesSales.txt",ios::out | ios::app);  // sales wali file open ki

                      if(!writeSales)
                      {
                         fileError();
                       }
                        else
                          {   // sales wali file me b data add krdia
                               writeSales<<"ID: "<<IDint+1<<" Sales: 0"<<endl;
                           }

                    }

                    cout<<"\n\n\t\tNow Sign in to Continue To Use CDS \n";
                    
                    n++;  // create account k bad sign in pe janay kelye
                   }
                      
  
                    if(c==2 || n==1)
                    {
                       
                         
                         int count;

                    cout<<"\n\t\t             [SIGN IN PAGE] \n";
                    cout << "\t\t----------------------------------------------------------------" << endl;
                    cout << "\t\t|                                                              |" << endl;
                    cout << "\t\t|     [Sign In]                                                |" << endl;
                    cout << "\t\t|                                                              |" << endl;
                    cout << "\t\t|      ID : ";
                    cin>>EmpID;
                     cin.ignore();
                    cout << "\t\t|      UserName : ";                   
                    cin.getline(Empusr,32);
                    cout << "\t\t|      Password : ";
                    cin.getline(Emppswd,32);
                    cout << "\t\t|                                                              |" << endl;
                    cout << "\t\t|                                                              |" << endl;
                    cout << "\t\t----------------------------------------------------------------" << endl;
                          
                          count=employeeLogin(Empusr,Emppswd,EmpID);  // credentials check krny ka function
                       

                           
                         if(count==3)  // agr 3 return hua mtlb credentials correct enter kiye
                         {
                            loginSuccessEmp();
                            return;
                          }
                        else  // ni to login fail
                          {
                              int ch;
                             loginFail();
                       
                            ch=failChoice();  // dobara choice li agr exit krna ya login page pe jana
                          
                       
                       if(ch>=1 && ch<=2)
                        {
             
                            if(ch==1)  //agr exit choose kia
                            {
                                   exitmsg();
                                   exit(0);

                            }


                            else  // ya login page pe jana chaha
                            {
                                loginPageEmp();

                            }

             
                         }


                      }
                    
                }
            }
              else
              {
                   cin.clear(); 
                   cin.ignore(); 
              
                   rangeerror();
                   continue;
              }

                    }while(c<1 || c>2);
}

int orderNotif()
{
     int totLines2=0;
     char liness[100];
    fstream seeOrders;

    seeOrders.open("OrdersStudentID.txt",ios::in);    // orders ki file open ki

    if(!seeOrders)  // check kia file open hui ya ni 
    {
      fileError();
    }
    else
    { 
         cout<<endl<<endl;

         while(seeOrders.getline(liness,100,'\n'))
         {
            totLines2++;                // lines count ki
         }
    }
    seeOrders.close();

    return totLines2;
}  


void seeScheduledOrders()
{

    char HDR1[50],HDR2[50],HDR3[100];

    int* itemID;
    char** itemname;
    int* orderitemprice;
    int* orderquantity;
    int* ID;
    char liness[100];
    char lines[100];           // variables jo kaam arhy han
    char** lines1;
    char charOrder[100];
    int totLines=0;
    int totLines2=0;
    int orderID;
   
    int id;
    bool idnotfound;
    int size;

    fstream seeOrders;

    seeOrders.open("ScheduledOrdersStudentID.txt",ios::in);  // orders note krne kelye file open ki

    if(!seeOrders)
    {
      fileError();
    }
    else
    { 
         cout<<endl<<endl;

         while(seeOrders.getline(liness,100))  
         {
            totLines2++;                 // lines count ki
         }

          if(totLines2>0)  // agr 0 sa ziada hn to mtlb order aya hua
          {
               

         seeOrders.clear();
         seeOrders.seekg(0,ios::beg);

         ID = new int[totLines2];  // intialize kia
         lines1 = new char*[totLines2];

             for(int j=0; j<totLines2; j++)
             {
               lines1[j] = new char[150];
             }

         int i=0;
          while(i<totLines2)   // file read ki
         {
            seeOrders.getline(lines1[i],150,':');
            seeOrders>>ID[i];
            seeOrders.ignore();
            i++;
         }

         seeOrders.close();

         for(int k=0; k<totLines2; k++)
         {
            cout<<lines1[k]<<" "<<ID[k]<<endl;   // aur employee ko display krwa di orders ki list
         }
  

             
  do
  {
   idnotfound=false;

   cout<<"\n\n\t\tEnter Student ID for Delivering Order : ";  // jisko order deliver krna uski id puchi employee sy
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

   if(count==0)  // agr ni ha to dobara puchi
   {
      cin.clear();
      cin.ignore();
      idnotfound=true;
      cout<<"\n\n\t\tNo Student Found With Such ID\n\n";
      continue;
   }

}while(idnotfound);

       // file sa order delete krdia
     fstream deleteOrder;
     deleteOrder.open("ScheduledOrdersStudentID.txt",ios::out);

     for(int i=0; i<totLines2; i++)
   {
      if(id==ID[i])
      {
         continue;
      }
      else
      {
        deleteOrder<<lines1[i]<<": "<<ID[i]<<endl;
      }
   }

     deleteOrder.close();
         
         fstream respondOrder;
         
         string filename = "ScheduleOrderID"+to_string(id)+".txt";   // id wali file declare ki

         respondOrder.open(filename,ios::in);  // wo file open ki

         if(!respondOrder)
         {
          fileError();
         }
         else
        { 

              while(respondOrder.getline(lines,100))
              {
                 totLines++;  // lines count ki
              }
               
                 respondOrder.clear();
                 respondOrder.seekg(0,ios::beg);
                
                 size = totLines-2;   
             
               itemID = new int [size];
               itemname = new char*[size];        // dynamic arrays initialize ki
               orderitemprice = new int[size];
               orderquantity = new int [size];


                for(int i=0; i<size; i++)
                {
                  itemname[i] = new char[32];
                }
                
                  // headers read kiye
                  respondOrder.getline(HDR1,50,':');
                  respondOrder>>orderID;             
                  respondOrder.ignore();
                  respondOrder.getline(HDR2,50,'\n');
                  respondOrder.getline(HDR3,100,'\n');
                   
                   int j=0; 

                while(respondOrder>>itemID[j])  // phr order read kia
                {
                   respondOrder.ignore();
                  respondOrder.getline(itemname[j],32,',');
                  respondOrder>>orderquantity[j]>>orderitemprice[j];
                  j++;

                }

                respondOrder.close();

               int totalPrice[199];
               int sum=0;

                cout<<endl<<endl;

                // transaction generate krwai

                cout<<HDR1<<" "<<orderID<<" "<<HDR2<<endl;
                cout<<HDR3<<endl;

                for(int k=0; k<size; k++)
                {
                  sum=sum+orderitemprice[k];
                  cout<<itemID[k]<<setw(18)<<itemname[k]<<setw(8)<<orderquantity[k]<<setw(15)<<orderitemprice[k]<<endl;
                }
                cout<<setw(35)<<"Total Price : "<<sum;

     

             
     cin.ignore();

     cout<<"\n\n\t\tPress Enter to Deliver Order ";
     cin.get();

     
     // stocks update krne kelye
     fstream updateStock;

     updateStock.open("Stocks.txt",ios::in);  // file open ki

     if(!updateStock)
     {
      fileError();
     }
     else
     {
          
          char HDR[100];
          char** name;
          int* price;
          int* quantity;
          int* tot_price;
          int* item_ID;
          char lines[100];

          int totLines=0; 
              
                 
        while(updateStock.getline(lines,100)) 
      {
            totLines++;   // lines count ki
        }
       
        updateStock.clear();
        updateStock.seekg(0, ios::beg);

        
        name = new char*[totLines-1];
        price = new int[totLines-1];
        quantity = new int[totLines-1];  // dynamic arrays initialize ki
        tot_price=new int[totLines-1];
        item_ID = new int[totLines-1];

        for (int l = 0; l < totLines-1; l++) 
        {
            name[l] = new char[32];
        }
   
   int i=0;
   updateStock.getline(HDR,100,'\n');   // header read kia
    
   while(updateStock>>item_ID[i])  // baki stocks read kia
     {  
       updateStock.ignore();
       updateStock.getline(name[i],32,',');
       updateStock>>price[i]>>quantity[i]>>tot_price[i];
       updateStock.ignore();
       i++;
         
    } 

        updateStock.close();
       
       fstream writeStock;   

       writeStock.open("Stocks.txt",ios::out);    // wapis write krne kelye open ki

        writeStock<<HDR<<endl;

            for (int k = 0; k < totLines-1; k++) 
          {
             for(int j=0; j<size; j++)
             {
               if(item_ID[k]==itemID[j])    // jahan item mile us index pe baki changes b ajae
                {
                  quantity[k]-=orderquantity[j];
                  tot_price[k]-=orderitemprice[j];
                }
                else
                {
                  continue;
                }
             }
              
          }
            // updated stock write back krdia
           for (int k = 0; k < totLines-1; k++) 
          {
            writeStock<<item_ID[k]<<" "<<name[k]<<", "<<price[k]<<" "<<quantity[k]<<" "<<tot_price[k]<<endl;
          }
     
                    
         writeStock.close();
        
        addSALES();  // employee ki sale me +1 krne ka function

        salesRecord(itemID,orderquantity,size);  // item ki sales increment krne ka function

        fstream deleteorder;
        string filename1 = "ScheduleOrderID"+to_string(id)+".txt";       // order delete krne kelye

        deleteorder.open(filename1,ios::out);


        deleteorder.close();

      // memory delete krdi
      for (int j = 0; j < totLines-1; j++)
         {
            delete[] name[j];
        }

        delete[] name;
        delete[] tot_price;   
        delete[] quantity;
        name=NULL;
        tot_price=NULL;
        price=NULL;
        item_ID=NULL;
        quantity=NULL;

        
     }
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
  else
  {
     cin.ignore();
     cout<<"\n\n\t\tNo Scheduled Orders Placed ";
     cout<<"\n\n\t\tPress enter to continue ...";
     cin.get();

  }

    }
}    

// order lene kelye
void takeOrders()
{
    char HDR1[150];

    int* itemID;
    char** itemname;
    int* orderitemprice;
    int* orderquantity;
    int* ID;                     // variables aur pointers
    char liness[100];
    char lines[100];
    char** lines1;
    char charOrder[100];
    int totLines=0;
    int totLines2=0;
    int orderID;
   
    int id;
    bool idnotfound;
    int size;

    fstream seeOrders;

    seeOrders.open("OrdersStudentID.txt",ios::in);   // file open ki id choose krne kelye

    if(!seeOrders)
    {
      fileError();
    }
    else
    { 
         cout<<endl<<endl;

         while(seeOrders.getline(liness,100))
         {
            totLines2++;        // lines count ki        
         }

          if(totLines2>0)  // agr lines 0 sa ziada han
          {
               

         seeOrders.clear();
         seeOrders.seekg(0,ios::beg);

         ID = new int[totLines2];
         lines1 = new char*[totLines2];

             for(int j=0; j<totLines2; j++)
             {
               lines1[j] = new char[150];
             }
    

         int i=0;
          while(i<totLines2)
         {
            seeOrders.getline(lines1[i],150,':');    // file read krdi
            seeOrders>>ID[i];
            seeOrders.ignore();
            i++;
         }

         seeOrders.close();

         for(int k=0; k<totLines2; k++)  // employee ko display krwai
         {
            cout<<lines1[k]<<" "<<ID[k]<<endl;
         }
  

             
  do
  {
   idnotfound=false;

   cout<<"\n\n\t\tEnter Student ID for Taking Order : ";   // student id puchi employee sa jiska order lena chahta ha
   cin>>id;

   int count=0;

   for(int i=0; i<totLines2; i++)
   {
      if(id==ID[i])   // check kia id ha b ya ni
      {
         count++;

      }
      else
      {
       continue;
      }
   }

   if(count==0)  // agr id ni mili
   {
      cin.clear();
      cin.ignore();
      idnotfound=true;
      cout<<"\n\n\t\tNo Student Found With Such ID\n\n";
      continue;
   }

}while(idnotfound);

     // order delete kia
     fstream deleteOrder;
     deleteOrder.open("OrdersStudentID.txt",ios::out);

     for(int i=0; i<totLines2; i++)
   {
      if(id==ID[i])
      {
         continue;
      }
      else
      {
        deleteOrder<<lines1[i]<<": "<<ID[i]<<endl;
      }
   }

     deleteOrder.close();
         

         fstream respondOrder;
         string filename = "BillID"+to_string(id)+".txt";

         respondOrder.open(filename,ios::in);  // bill write krne kelye file banai

         if(!respondOrder)
         {
          fileError();
         }
         else
        { 

              while(respondOrder.getline(lines,100))
              {
                 totLines++;  // lines count ki
              }
               
                 respondOrder.clear();
                 respondOrder.seekg(0,ios::beg);
                
                 size = totLines-1;
             
               itemID = new int [size];
               itemname = new char*[size];            // dynamic arrays initialize ki
               orderitemprice = new int[size];
               orderquantity = new int [size];


                for(int i=0; i<size; i++)
                {
                  itemname[i] = new char[32];
                }
                
                
                  respondOrder.getline(HDR1,150,'\n');   // header read kia
                   
                   int j=0; 

                while(respondOrder>>itemID[j])   // baki orders read kiye
                {
                   respondOrder.ignore();
                  respondOrder.getline(itemname[j],32,',');
                  respondOrder>>orderquantity[j]>>orderitemprice[j];
                  j++;

                }

                respondOrder.close();

               int sum=0;

                cout<<endl<<endl;

                // employee ko show krwaye
                cout<<HDR1<<endl;
                for(int k=0; k<size; k++)
                {
                  sum=sum+orderitemprice[k];
                  cout<<itemID[k]<<setw(18)<<itemname[k]<<setw(8)<<orderquantity[k]<<setw(15)<<orderitemprice[k]<<endl;
                }
                cout<<setw(35)<<"Total Price : "<<sum;

     

             
     cin.ignore();

     cout<<"\n\n\t\tPress Enter to Deliver Order ";
     cin.get();

   // stock updating kelye

       fstream updateStock;

     updateStock.open("Stocks.txt",ios::in);

     if(!updateStock)
     {
      fileError();
     }
     else
     {
          
          char HDR[100];
          char** name;
          int* price;
          int* quantity;
          int* tot_price;
          int* item_ID;
          char lines[100];

          int totLines=0; 
              
                 
        while(updateStock.getline(lines,100)) 
      {
            totLines++;
        }
       
        updateStock.clear();
        updateStock.seekg(0, ios::beg);

        
        name = new char*[totLines-1];
        price = new int[totLines-1];
        quantity = new int[totLines-1];
        tot_price=new int[totLines-1];
        item_ID = new int[totLines-1];

        for (int l = 0; l < totLines-1; l++) 
        {
            name[l] = new char[32];
        }
   
   int i=0;
   updateStock.getline(HDR,100,'\n');
   while(updateStock>>item_ID[i])
     {  
       updateStock.ignore();
       updateStock.getline(name[i],32,',');
       updateStock>>price[i]>>quantity[i]>>tot_price[i];
       updateStock.ignore();
       i++;
         
    } 

        updateStock.close();
       
       fstream writeStock;

       writeStock.open("Stocks.txt",ios::out);

        writeStock<<HDR<<endl;
            for (int k = 0; k < totLines-1; k++) 
          {
             for(int j=0; j<size; j++)
             {
               if(item_ID[k]==itemID[j])              // quantity aur total price update krdi
                {
                  quantity[k]-=orderquantity[j];
                  tot_price[k]-=orderitemprice[j];
                }
                else
                {
                  continue;
                }
             }
              
          }
               // wapis write krdia updated stock
           for (int k = 0; k < totLines-1; k++) 
          {
            writeStock<<item_ID[k]<<" "<<name[k]<<", "<<price[k]<<" "<<quantity[k]<<" "<<tot_price[k]<<endl;
          }
     
                    
         writeStock.close();
        
        addSALES();  // employee ki sale me add krdia
        salesRecord(itemID,orderquantity,size);  // items ki sales me b increment krdia

        // order delete krdia
        fstream deleteorder;
        string filename1 = "BillID"+to_string(id)+".txt";

        deleteorder.open(filename1,ios::out);


        deleteorder.close();

     
    
      // memory delete

      for (int j = 0; j < totLines-1; j++)
         {
            delete[] name[j];
        }

        delete[] name;
        delete[] tot_price;   
        delete[] quantity;
        name=NULL;
        tot_price=NULL;
        price=NULL;
        item_ID=NULL;
        quantity=NULL;

        
     }
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
  else
  {
     cin.ignore();
     cout<<"\n\n\t\tNo Orders Placed ";
     cout<<"\n\n\t\tPress enter to continue ...";
     cin.get();

  }

 }

}

// sales record update krne ka function
void salesRecord(int* itemID,int* orderquantity,int totalLines)
{
   
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

         for(int k=0; k<size; k++)
         {
            for(int j=0; j<totalLines; j++)
            {
            if(item_ID[k]==itemID[j])             // jis index pe id milegi wahan jitni quantity sell hoi hogi add krdega
            {
               Sales[k]+=orderquantity[j];
               Average[k]=Sales[k]/2.0;
            }
            else
            continue;
            }
         }

         fstream writeSales;

         writeSales.open("SalesRecord.txt",ios::out);     // wapis updated sales write krne kelye    

         if(!writeSales)
         {
            fileError();
         }
         else
         {
            writeSales<<HDR<<endl;
            for(int k=0; k<size; k++)  
            {
               writeSales<<item_ID[k]<<" "<<Names[k]<<", "<<Sales[k]<<" "<<Average[k]<<endl;
            }

            writeSales.close();
         }
 
     
        for(int j=0; j<size; j++)
        {
          delete[]Names[j];
        }

        delete[]Names;
        delete[]item_ID;
        delete[]Sales;
        delete[]Average;


    }

}

// employee ki sales increment krne kelye
void addSALES()
{
              char** charID;
              int* ID;
              char** chsales;
              int* SALES;
              char lines[1000];
              int totLines=0; 
              
         fstream readSales;

         readSales.open("EmployeesSales.txt",ios::in);  

         if(!readSales)
         {
            fileError();
         }        
         else
         {
              
                
        while(readSales.getline(lines,1000)) 
      {
            totLines++;  // lines count ki
        }
       
        readSales.clear();
        readSales.seekg(0, ios::beg);

        
        charID = new char*[totLines];
        ID = new int[totLines];
        SALES = new int[totLines];
        chsales= new char*[totLines];

        for (int l = 0; l < totLines; l++) 
        {
            charID[l] = new char[32];
            chsales[l] = new char[32];
        }
   
   int i=0;
   while(i<totLines)
     {  
       readSales.getline(charID[i],32,':');
       readSales.ignore();
       readSales>>ID[i];
      readSales.ignore();
       readSales.getline(chsales[i],32,':');
       readSales>>SALES[i];
       readSales.ignore();
       i++;
         
    } 
    


         fstream writeSales;

         writeSales.open("EmployeesSales.txt",ios::out);

         if(!writeSales)
         {
            fileError();
         }
         else
         {
            
            for(int i=0; i<totLines; i++)
            {
               if(EmpID==ID[i])   // jis index pe employee ki id milegi udr +1 hojaega
               {
                 writeSales<<"ID: "<<ID[i]<<" Sales: "<<SALES[i]+1<<endl;
               }
               else
               {
                  writeSales<<"ID: "<<ID[i]<<" Sales: "<<SALES[i]<<endl;
               }
            }

         }


        for (int l = 0; l < totLines; l++) 
        {
            delete[] charID[l];
            delete[] chsales[l];
        }

        delete[]charID;
        delete[]ID;
        delete[]SALES;
        delete[]chsales;
   }  
}

// employee k functions ki choice
int empFuns()
{

         int ch;
         char tmp;
          do{
                    
                    cout << "\t\t----------------------------------------------------------------------------------" << endl;
                    cout << "\t\t|                                                                                |" << endl;
                    cout << "\t\t|     You are Authorized to do Following Operations ::                           |" << endl;
                    cout << "\t\t|     Press 1 : Take appropriate orders from students/staff                      |" << endl;
                    cout << "\t\t|     Press 2 : Search Items                                                     |" << endl;
                    cout << "\t\t|     Press 3 : See online/scheduled orders                                      |" << endl;
                    cout << "\t\t|     Press 4 : Change Your Credentials                                          |" << endl;
                    cout << "\t\t|     Press 5 :  Return to CDS Menu                                                             |" << endl;
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

// credentials change krny ki choice
int empCredsChoice()
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

// stock search krne kelye choice
int stockSearchChemp()
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


// items search krny ka function
void searchITEMSemp()
{

   char HDR[100];
   char** name;
   int* price;
   int* quantity;
   int* tot_price;
   int* item_ID;

   int totLines=0;

 fstream stockReadEmps;
    char lines[100];
    stockReadEmps.open("Stocks.txt",ios::in);
   
    if (!stockReadEmps) 
    {
        fileError();
    }
     else 
    {
        
        while(stockReadEmps.getline(lines,100)) 
      {
            totLines++;
        }
       
        stockReadEmps.clear();
        stockReadEmps.seekg(0, ios::beg);

        
        name = new char*[totLines-1];
        price = new int[totLines-1];
        quantity = new int[totLines-1];
        tot_price=new int[totLines-1];
        item_ID = new int[totLines-1];

        for (int l = 0; l < totLines-1; l++) 
        {
            name[l] = new char[32];
        }
   
   int i=0;
   stockReadEmps.getline(HDR,100,'\n');
   while(stockReadEmps>>item_ID[i])
     {  
       stockReadEmps.ignore();
       stockReadEmps.getline(name[i],32,',');
       stockReadEmps>>price[i]>>quantity[i]>>tot_price[i];
       stockReadEmps.ignore();
       i++;
         
    } 

   
       stockReadEmps.close();
       
   
      char ch;
      int choice;
  do{
      choice=stockSearchCh();  // choice li searching ki

      if(choice==1)  // agr by name krna hua to
      {
         searchbyNameEmp(totLines-1,name,item_ID,price,quantity,tot_price);
      }

      else if(choice==2)  // agr by price krna hua
      {
         searchbyPriceEmp(totLines-1,name,item_ID,price,quantity,tot_price);
      }
      
      else
      {}
          
         
              do
                {     
                    
                     cout << "\n\n\t\tDo you want to Search More Items? Y/N : ";
                     cin >> ch;
                     
                    } while ((ch!= 'y' && ch!= 'Y') && (ch!= 'n' && ch!= 'N'));

  }while(ch== 'Y' || ch== 'y');
  
    }

             // memory delete
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

// by name searching ka function
void searchbyNameEmp(const int size, char **name, int *item_ID, int *price, int *quantity, int *tot_price)
{
   int count=0;

   char nameSearch[32];

   cin.ignore();
   cout<<"\n\n\t\tEnter Name of Item to be Searched : ";    // name pucha employee sy
   cin.getline(nameSearch,32);
   cout<<endl<<endl;
   cout<<"Item_ID"<<"       Name"<<"       PRICEperITEM"<<endl;
   for(int i=0; i<size; i++)
   {
      if(strcmp(name[i],nameSearch)==0)   // jahan name mila wahan ka data show kia
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

   if(count==0) // agr us name ka koi item na mila
   {
      cout<<"\n\n\t\tNo Item with such Name Found\n\n";
   }


  
  cout<<"\n\n\t\tPress any key to continue...";
  cin.get();
}

// search by price ka function
void searchbyPriceEmp(const int size, char **name, int *item_ID, int *price, int *quantity, int *tot_price)
{
   int count=0;

   int priceSearch;

   cin.ignore();
   cout<<"\n\n\t\tEnter Price of Item to be Searched : ";   // price puchi employee sy
   cin>>priceSearch;
   cout<<endl<<endl;
   cout<<"Item_ID"<<"       Name"<<"       PRICEperITEM"<<endl;
   for(int i=0; i<size; i++)
   {
      if(priceSearch==price[i])   // jahan wo price mili us index ka data display krwaya
      {
         count++; 
         cout<<item_ID[i]<<setw(18)<<name[i]<<setw(10)<<price[i]<<endl;
      }
      else
      {
       continue;
      }
   }

   if(count==0)   // agr us price ka koi item na hua
   {
      cin.clear();
      cin.ignore();
      cout<<"\n\n\t\tNo Item Found With Such Price\n\n";
   }


  
  cin.ignore();
  cout<<"\n\n\t\tPress any key to continue...";
   cin.get();


}

// credentials change krne ka function
void changeEmpCreds()
{
   
     fstream changeCreds;
     char lines[100];
     int totLines=0;

     changeCreds.open("EmployeesCreds.txt",ios::in);
     
     if(!changeCreds)
     {
      fileError();
     }
     else
     {
          
            while(changeCreds.getline(lines,100))
            {
               totLines++;
            }

             changeCreds.clear();
             changeCreds.seekg(0, ios::beg);

            const int size=totLines/3;

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
            
            while(changeCreds>>chID>>empID[j])
            {

               changeCreds.ignore();
               changeCreds.getline(user[j],32,'\n');
               changeCreds.getline(pass[j],32,'\n');

               j++;
            }
  
           changeCreds.close();


              int ch;
              ch=empCredsChoice();

              if(ch==1)
              {
                  fstream changeUser;
                  char newuser[32];

                  changeUser.open("EmployeesCreds.txt",ios::out);

                  if(!changeUser)
                  {
                     fileError();
                  }
                  else
                  {
                     cin.ignore();
                     cout<<"\n\n\t\tEnter New UserName : ";
                     cin.getline(newuser,32);

                     for(int i=0; i<size; i++)
                     {
                        if(empID[i]==EmpID)
                        {
                           strcpy(user[i],newuser);
                           changeUser<<chID<<" "<<empID[i]<<endl<<user[i]<<endl<<pass[i]<<endl;
                        }
                        else
                        {
                           changeUser<<chID<<" "<<empID[i]<<endl<<user[i]<<endl<<pass[i]<<endl;
                        }
                     }
                     changeUser.close();
                  }

                 cout<<"\n\n\t\tUsername changed successfully";

              }
              else if(ch==2)
              {
                
                 fstream changePass;
                  char newpass[32];

                  changePass.open("EmployeesCreds.txt",ios::out);

                  if(!changePass)
                  {
                     fileError();
                  }
                  else
                  { 
                     cin.ignore();
                     cout<<"\n\n\t\tEnter New Password : ";
                     cin.getline(newpass,32);

                     for(int i=0; i<size; i++)
                     {
                        if(empID[i]==EmpID)
                        {
                           strcpy(pass[i],newpass);
                           changePass<<chID<<" "<<empID[i]<<endl<<user[i]<<endl<<pass[i]<<endl;
                        }
                        else
                        {
                           changePass<<chID<<" "<<empID[i]<<endl<<user[i]<<endl<<pass[i]<<endl;
                        }
                     }
                     changePass.close();
                  }
                  
                  cout<<"\n\n\t\tPassword changed successfully";

              }
              
             

            for(int i=0; i<size; i++)
            {
               delete[]user[i];
               delete[]pass[i];
            } 
            
            delete[]user;
             delete[]pass;
              delete[]empID;

     }

cin.ignore();
   cout<<"\n\n\t\tPress enter to continue ...";
   cin.get();
}

void loginSuccessEmp()
{
   
    
    
                    cout << "\t\t--------------------------------------------" << endl;
                    cout<<endl;
                    
                   
                    wait("\t\tWait ... Verifying Credentials .... ",0);
                    wait("\n\n\t\tLogin Successful ...",3);
                    wait("\n\n\t\tOpening Employee Account ...",0);
                    wait(" ",2);
                    
                    cout << "\t\t--------------------------------------------" << endl;
                    
 

}





int loginchoiceEmp()
{
    int c;
  
                    do{
                      
                         cout<<"\n\t\t                 [LOGIN PAGE] \n";
                    
                    cout << "\t\t----------------------------------------------------" << endl;
                    cout << "\t\t|                                                  |" << endl;
                    cout << "\t\t|   Press 1 :  Sign Up [New Employee]              |" << endl;
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

