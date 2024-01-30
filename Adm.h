void checkThreshold();
int checkThresholdNotif();
int showThresholdNotif(char[],int*,char**, int*, int*, int*,const int);
void showThreshold(char[],int*,char**, int*, int*, int*,const int);
void swapVal(int&,int&);
void swapChar(char*,char*,int);


void seeBestEmployees();



void admWelcome();
void loginPageAdm();
int adminFuns();
void displayNotifications();
void waitSuccess();
void waitFail();
void changeCreds();

void seeStock();
void stockManage();
int stockChoice();
int stockUpdateChoice();
void showStock(char[],int*,char**, int*, int*, int*,int&);
void stockUpdate(char[],int*,const int,char**, int*, int*, int*);
void stockDEL(char[],int*,const int,char**, int*, int*, int*, int);
void stockSearch(char[],int*,const int,char**, int*, int*, int*);
void searchbyName(const int,char**,char[],int*, int*, int*, int*);
void searchbyPrice(const int,char**,char[],int*, int*, int*, int*);
void searchbyID(const int,char**,char[],int*, int*, int*, int*);
int stockSearchChoice();
void stockAdding();
void stockRemoving();
void stockAdd(int);

int manageCredsChoice();
void addEmp(char[], int*,int, char**, char**,int);
void removeEmp();
void removeStdnt(char[], int*, char**, char**,int);
void addStdnt(char[], int*,int, char**, char**,int);
int credsManageChoice();
void handleCreds();

void seehighlowSales();
void seeScheduledOrdersAdmin();
void seeSales();

int adminMenu();

void seeComplaints();

int notificationMenu();
int notificationChoice();

int responseID(int [],int);
