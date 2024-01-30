#include<iostream>
#include<ctime>
#include<iomanip>
#include<chrono> 
#include<thread>
#include<cstring>
#include<fstream>


#include "Adm.h"
#include "Emp.h"
#include "filehandling.h"
#include "Stdnts.h"

#define YELLOW_TEXT "\033[1;33m"
#define RED_TEXT "\033[1;31m"
#define RESET_TEXT "\033[0m"

using namespace std;



// DOUBLE FUNCTIONS
double sum(double, double);
double diff(double, double);
double prod(double, double);
double divi(double, double);
double powr(double, int);

void rangeerror();
void wait(string,int);
int cdsMenu();
void welcomeCDS();
string currenttime();
void exitmsg();
int credsChoice();
void fileError();
void CreationSuccess();
int failChoice();
void loginFail();
void checkReq();




