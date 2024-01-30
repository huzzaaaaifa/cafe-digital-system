#include "proj.h"
#include "filehandling.h"


int studentLogin(char stdntusername[20] , char stdntpassword[20], int ID)
{
	fstream readstudent;
	char IDchar[10];
	int IDint;
	char readUser[32];
	char readPass[32];
	int count=0;
	readstudent.open("StudentCreds.txt",ios::in);
	
	while (readstudent >> IDchar >> IDint >> readUser >> readPass)  // file reading
                         {
                              
                              if(ID==IDint)
                            {
                            	count++;
                            		break;
							  }  

                            
                            }
                            
                            if(strcmp(readUser,stdntusername)==0)
                            {
                            	count++;
                            	
                            	if(strcmp(readPass,stdntpassword)==0)
                            	count++;
							}
				readstudent.close();
	return count;
}

int employeeLogin(char empusr[32], char emppass[32], int ID)
{
	
	fstream read;
	char IDchar[10];
	int IDint;
	char readUser[32];
	char readPass[32];
	int count=0;
	read.open("EmployeeCreds.txt",ios::in);
	
	while (read >> IDchar >> IDint >> readUser >> readPass)  // file reading
                         {
                              
                              if(ID==IDint)
                             {
                             	count++;
                             	break;
							  } 

                            
                            }
                            
                            if(strcmp(readUser,empusr)==0)
                            {
                            	count++;
                            	
                            	if(strcmp(readPass,emppass)==0)
                            	count++;
							}
				read.close();
	return count;
	
	
	
}

int adminLogin(char adminusr [20], char adminpass[20])
{
	 
	 fstream read;
	 char user[32];
	 char pass[32];
	 int count=0;
	 
	 read.open("AdminCreds.txt",ios::in);
	 
	 read.getline(user,32,'\n');
	 read.getline(pass,32,'\n');
	 
	 if(strcmp(user,adminusr)==0)
	 {
	 	count++;
	 	
	 	if(strcmp(pass,adminpass)==0)
	 	{
	 		count++;
		 }
	 }
	 
	read.close();
	
	return count;
	
	
}

void notificationsWriteDEL()
{
	 cin.ignore();
	 char notif[100];
		 fstream write;
	 
	 write.open("Notifications.txt",ios::out);
	 
	 cout<<"Write Notification : ";
	 cin.getline(notif,100);
	 
	 write<<currenttime()<<endl<<notif<<endl;
	 
	 write.close();
	
	
}

void changeAdminPass()
{
	cin.ignore();
	char newpass[32];
	fstream change;
	char user[32];
	char pass[32];
	
	change.open("AdminCreds.txt",ios::in);
	
	change.getline(user,32,'\n');
	change.getline(pass,32,'\n');
	
	change.close();
	
	cout<<"\n\n\t\tEnter new password ";
	cin.getline(newpass,32);
	
	fstream write;
	
	write.open("AdminCreds.txt",ios::out);
	
	write<<user<<endl<<newpass;
	
	write.close();	
	
	
	
}
void changeAdminUser()
{
	cin.ignore();
	char newuser[32];
	fstream change;
	char user[32];
	char pass[32];
	
	change.open("AdminCreds.txt",ios::in);
	
	change.getline(user,32,'\n');
	change.getline(pass,32,'\n');
	
	change.close();
	
	cout<<"\n\n\t\tEnter new username ";
	cin.getline(newuser,32);
	
	fstream write;
	
	write.open("AdminCreds.txt",ios::out);
	
	write<<newuser<<endl<<pass;
	
	write.close();	
	
	
	
}

void notificationsWriteAPP()
{
	 cin.ignore();
	 char notif[100];
		 fstream write;
	 
	 write.open("Notifications.txt",ios::out | ios::app);
	 
	 cout<<"Write Notification : ";
	 cin.getline(notif,100);
	 
	 write<<currenttime()<<endl<<notif<<endl<<endl;
	 
	 write.close();
	
}
