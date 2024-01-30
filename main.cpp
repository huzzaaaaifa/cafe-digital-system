#include "proj.h"


int main()
{
   
     int ch,ch1,y;
     char c;
     char chh;
  
     
    // welcome function
    welcomeCDS();
     
    
       cout<<endl;
       int n=0;
       int x=0;
       int t=0;
       int z=0;
       int c1,c2;

       
     do{
            // role choice function
          ch=cdsMenu();
          int c=0;
          int b=0;
          
          
           switch(ch)
           {
           
               case 1:
                     
                     // login page admin
                    loginPageAdm();
                   
                    cout<<endl;
                    
                     // admin welcome
                    admWelcome();
                       
                    
                    
                 do{    // admin functions repeat loop
                     
                       // popup notification if any item is less than threshold value
                        c1=checkThresholdNotif();

                        if(c1>0 && b==0)
                        {
                            wait("\t\tWait ... Checking if any item is less than threshold ...",0);
                            wait("\n\n\t\tItems found less than 15 in quantity ...",3);
                           wait(" ",2);
                            cout<<"\n\n\t\tWarning !! Some Items are less than Threshold Value \n\n";
                            checkThreshold();

                        }
                        else if (b==0 && c1==0)
                        {
                           wait("\t\tWait ... Checking if any item is less than threshold ...",0);
                            wait("\n\n\t\tIt's All Good You Can proceed ...",3);
                           wait(" ",2);
                        }
                   
                       
                        ch1=adminMenu();

                        b++;
                    
                        
                         switch(ch1)   // admin operations 
                         {
                         
                             case 1:
                                // stock dekhne ka function
                                  seeStock();
                              
                             break;
                             
                             case 2:
                                 // threshold sa kam items dekhne aur khareedne ka function
                                checkThreshold();
                             
                             break;
                             
                             
                             case 3:
                                      // har item ki sale dekhne kelye
                                 seeSales();
                             
                             break;
                             
                             
                             case 4:
                                  // stock ko manage krne ka function
                                 stockManage();
                             
                             break;
                             
                             case 5:
                                  // employees aur students k credentials manage krne ka function
                                handleCreds();
                             
                             break;
                             
                             
                             case 6:
                                     // notifications generate krne ka function
                                 displayNotifications();
                                 
                             break;
                             
                             case 7:
                                      // students k orders ka response krne kelye
                                 seeScheduledOrdersAdmin();
                             
                             break;
                             
                             case 8:
                                     // students ki complains dekhne kelye
                                 seeComplaints();
                             
                             break;
                             
                             
                             case 9:
                                     // best employee dekhne kelye
                                seeBestEmployees();

                             break;

                             case 10:
                                    // admin apny credentials change krne kelye
                                 changeCreds();
     
                             break;

                             case 11:
                                        // high aur low sold items dekhne kelye
                                 seehighlowSales();

                               break;

                             default:

                                  n=1;
                               
                               break;
                          
                         }
                       
                   
                  }while(n==0);  // admin function repeat condition  
                    
               break;
               
               
               case 2:
                         // employee ka login page
                      loginPageEmp();
                      
                do{    // employee functions repeat loop
                    
                        
                        c2=orderNotif();

                        if(c2>0 && c==0)
                        {
                            wait("\t\tWait ... Checking for Any Orders ...",0);
                            wait("\n\n\t\tIncoming Orders From Students ... \n!! Respond as early as possible",3);
                           wait(" ",2);
                            takeOrders();
                        }
                         else if (c2==0 && c==0)
                         {
                           wait("\t\tWait ... Checking for Any Orders ...",0);
                            wait("\n\n\t\tNo Incoming Orders From Students ...",3);
                           wait(" ",2);
                         } 

                        ch1=empFuns();
                        c++;
                    
                     
                         switch(ch1)   // employee operations 
                         {
                         
                             case 1:
                              x=0;
                              takeOrders();
                               
                             break;
                             
                             case 2:
                                   x=0;  // employee kelye search ka function
                                searchITEMSemp();
                             
                             
                             break;
                             
                             
                             case 3:
                                   x=0; // employee ka scheduled orders ko deliver krne kelye
                                seeScheduledOrders();
                             
                             break;
                             
                             
                             case 4:
                                 x=0;   // employee apny credentials change krne kelye
                                 changeEmpCreds();
                               
                              break;

                              default:

                               x=1;
                               break;
          
                         }
        
        
                   
                  }while(x==0);  
                      

                      
                 
               break;
               
               
               
               case 3:
                          // student ka login choice 
                    y=loginChoiceStdnt();
                  
                     switch(y)
                     {

                          case 1:
                                  // agr CDS choose kia to login page
                              loginPageStudent();
 
                               do{
                                       //students k functions menu
                                   ch1=studentsCDSFuns();


                                    switch(ch1)   // employee operations 
                                  {
                         
                             case 1:
                                 t=0;
                                order();
                             
                             break;
                             
                             case 2:
                                      t=0;// complains dene kelye
                                giveComplaints();
                             
                             break;
                             
                             
                             case 3:
                                   t=0;  // items search krne kelye
                               searchITEMS();
                               
                             break;
                             
                             
                             case 4:
                                 t=0;   // scheduled orders dene kelye
                                 scheduleOrders();

                              break;

                             case 5:
                                 t=0;   // admin k notifications dekhne kelye
                                 seeNotifications();   
                     

                             break;

                             case 6:
                                  t=0;   // complain ka response dekhne kelye
                                 seeResponse();

                              break;

                              case 7:
                                   t=0;  // order ka response dekhne kelye
                                seeOrderRes();

                              break;

                              case 8:
                                   t=0; // student apna credentials change krne kelye
                                  changeStdntCreds();

                                  break;
                              
                              default:
                                  
                                  t=1;
                                break;

                            }        
                               
                    } while(t==0); 
                     

                          
                             
                        break;

                        case 2:

                         do{
                             // agr student without cds choose kre
                            ch1=studentsNoAccFuns();

                               switch(ch1)
                               {

                                  case 1:
                                       z=0;
                                       noAccOrder();

                                  break;


                                  default:

                                    z=1;
                                     
                                     break;

                               }
                                
                         }while(z==0);
                
                             
                                 
            
                   }
            
        

               break;
               
                            
               default:
                  
                   exitmsg();
                   cout<<endl<<endl;
                   exit(1);
                 
               break;
               
           }
     
              do
                {     
                    
                     cout << "\n\n\t\tDo you want to Go to CDS Menu Page Y/N : ";
                     cin >> chh;
                     
                    } while ((chh!= 'y' && chh!= 'Y') && (chh!= 'n' && chh!= 'N'));
                  
}while(chh=='y' || chh=='Y');
            

  exitmsg();
  cout<<endl<<endl;
  

}
