#include "proj.h"

// DOUBLE Simple Calculation FUNCTIONS IMPLEMENTATION
double sum(double x, double y)
{
    return x + y;
}

double diff(double x, double y)
{
    return x - y;
}

double prod(double x, double y)
{
    return x * y;
}

double divi(double x, double y)
{
    return x / y;
}

double powr(double x, int b)
{
    if (b >= 0)
    {
        int i;
        double prod = 1;

        for (i = 1; i <= b; i++)
        {
            prod = prod * x;
        }
        return prod;
    }
    else
    {
        int i;
        double prod = 1;

        for (i = b; i <= -1; i++)
        {
            prod = prod / x;
        }
        return prod;
    }
}

// output formatting
void CreationSuccess()
{

    cout << "\t\t--------------------------------------------" << endl;
                    cout<<endl;
                    
                   
                    wait("\t\tWait ... Creating Acount .... ",0);
                    wait("\n\n\t\tAccount Created Successfully ...",3);
                    wait(" ",2);
                    
                    cout << "\t\t--------------------------------------------" << endl;

}

void loginFail()
{
   
    
    
                    cout << "\t\t--------------------------------------------" << endl;
                    cout<<endl;
                    
                   
                    wait("\t\tWait ... Verifying Credentials .... ",0);
                    wait("\n\n\t\tLogin Failed ...",3);
                    wait("\n\n\t\tID User Name or Password is incorrect ... Please Review it",1);
                    wait(" ",2);
                    
                    cout << "\t\t--------------------------------------------" << endl;
                    
 

}

int failChoice()
{
     int ch;
     do{
     cout<<"\n\n\t\tPress 1 to Exit Program";
     cout<<"\n\n\t\tPress 2 to Go To Login Page ";
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

void fileError()
{
  
   cout<<"\n\n\t\tError! Can't Open File"<<endl<<endl;
  exitmsg();
    exit(0);

  

}

void welcomeCDS()
{

     cout<<endl<<endl;
      
       cout << "\t\t---------------------------------------" << endl;
       cout << "\t\t|                                     |" << endl;
       cout << "\t\t|          [Welcome to CDS]           |" << endl;
       cout << "\t\t|                                     |" << endl;
       cout << "\t\t---------------------------------------" << endl;
       
       cout<<"\n\n\t\tPress Enter to Start ";
       cin.get();
     


}

void rangeerror()
{
   
                    cout << "\n\n\t\t";
                    cout << "***************************************" << endl;
                    cout << "\t\t*                                     *" << endl;
                    cout << "\t\t*   !!ERROR: Input out of range !!    *" << endl;
                    cout << "\t\t*                                     *" << endl;
                    cout << "\t\t*            Enter Again              *" << endl;
                    cout << "\t\t*                                     *" << endl;
                    cout << "\t\t***************************************" << endl;


}


// screen pausing function  Source internet
void wait(string print, int secs)
{
     
     this_thread::sleep_for(chrono::seconds(secs));
     cout<<print<<endl;

}

int cdsMenu()
{
    int ch;
    do
           {
             
             cout << "\t\t--------------------------------------------" << endl;
             cout << "\t\t|                                          |" << endl;
             cout << "\t\t|     Make Choice of Following :           |" << endl;
             cout << "\t\t|     Press 1 if you are Admin             |" << endl;
             cout << "\t\t|     Press 2 if you are Employee          |" << endl;
             cout << "\t\t|     Press 3 if you are Student or Staff  |" << endl;
             cout << "\t\t|     Press 4 to Quit CDS                  |" << endl;
             cout << "\t\t|                                          |" << endl;
             cout << "\t\t--------------------------------------------" << endl;
             cin>>ch;
             
           
             if(ch>1 && ch<4)
             {
             
                 break;
             
             }
             
             else if((ch<1 || ch>4) )
               {
                   cin.clear();
                   cin.ignore();
                  rangeerror();
                
               }
              
            }
            while(ch<1 || ch>4);
                       
                cout<<endl<<endl;
      return ch;

}

// current time function Source internet
string currenttime()
{
   
    auto currentTimePoint = chrono::system_clock::now();

    
    time_t currentTime = chrono::system_clock::to_time_t(currentTimePoint);

    
    string currentTimeStr = ctime(&currentTime);

    
    return currentTimeStr;

    
}

void exitmsg()
{
  
   cout<<"\n\n\t\tExited the CDS Successfully .... ";

}

