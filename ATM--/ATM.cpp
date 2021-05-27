#include<iostream>
#include<fstream>
#include<ctime>
#include"user.h"

using namespace std;

int w_money,d_money,number;//tienrut-tiengui-so.to.tiengui
int a[10];//mang.luu.gia.tien
long c_number,cc_number;//doi-mat-khau

class banking{
	public:
	int k10 ,k20 ,k50 ,k100,k200,k500;
	banking(){
		ifstream bb("baking.txt",ios::out|ios::app);
	    while(!bb.eof()){
	    	bb>>k10;
		    bb>>k20;
		    bb>>k50;
		    bb>>k100;
		    bb>>k200;
		    bb>>k500;
		}
	}
};
class History{
	public:
		virtual void t_time()=0;
};
class H_withdraw:public History{
	int Hwithdraw;
	int Hbalance;
	public:
		H_withdraw(int w, int b){
			Hwithdraw=w;
            Hbalance=b;
		}
	    void t_time(){
	    	fstream ofs("history.txt",ios_base::app| ios::out);
            time_t now = time(0);
            char* dt = ctime(&now);

            ofs<<endl<<endl;
            ofs<<"===============================Location: chinh's house "<<endl;
            ofs<<"==============================="<<"Time: "<<dt;
            ofs<<"Withdraw: "<<Hwithdraw<<" VND"<<endl;
            ofs<<"Balance: "<<Hbalance<<" VND"<<endl;
            ofs.close();
		}
};
class H_deposit:public History{
	int Hdeposit;
	int Hbalance;
	public:
		H_deposit(int d, int b){
			Hdeposit=d;
            Hbalance=b;
		}
	    void t_time(){
	    	fstream ofs("history.txt",ios_base::app| ios::out);
            time_t now = time(0);
            char* dt = ctime(&now);

            ofs<<endl<<endl;
            ofs<<"===============================Location: chinh's house "<<endl;
            ofs<<"==============================="<<"Time: "<<dt;
            ofs<<"Deposit: "<<Hdeposit<<" VND"<<endl;
            ofs<<"Balance: "<<Hbalance<<" VND"<<endl;
            ofs.close();
		}
};

void save_file_user();
void save_file_banking();
void menu();
void dangnhap();
void withdraw();
void deposit();
void history();
void account();
void type_of_account();
void tranfer();
void eject();

user vn;
banking b;

void save_file_user(){
	ofstream file_ofs("file_luu_pass.txt",ios_base::app| ios::out);
	file_ofs<<vn.id_card<<" "<<vn.pass<<" "<<vn.acc_money<<" "<<vn.number_acc<<endl;
	file_ofs.close();
}
void save_file_banking(){
	ofstream file_ofs("baking.txt",ios_base::app);
	file_ofs<<b.k10<<" "<<b.k20<<" "<<b.k50<<" "<<b.k100<<" "<<b.k200<<" "<<b.k500<<endl;
	file_ofs.close();	
}
void menu(){
	int activity;
	do{
		system ("cls");
        cout<<"                                                           "<<endl;
        cout<<"           CUSTOMER MENU                         "<<endl;
        cout<<"                                                           "<<endl;
		cout<<"                                                           "<<endl;
        cout<<" 1. WITHDRAW CASH     : Press 1"<<endl;
        cout<<"                                                           "<<endl;
        cout<<"                                                           "<<endl;
        cout<<" 2. DEPOSIT CASH      : Press 2"<<endl;
        cout<<"                                                           "<<endl;
        cout<<"                                                           "<<endl;
        cout<<" 3. HISTORY           : Press 3"<<endl;
        cout<<"                                                           "<<endl;
		cout<<"                                                           "<<endl;
        cout<<" 4. CHECK BALANCE     : Press 4"<<endl;
        cout<<"                                                           "<<endl;
        cout<<endl;
        cout<<" 5. ACCUMULATED POINTS: Press 5"<<endl;
        cout<<"                                                           "<<endl;
        cout<<endl;
        cout<<" 6. CHANGE PIN CODE   : Press 6"<<endl;
        cout<<"                                                           "<<endl;
        cout<<endl;
        cout<<"Please select a banking activity: ";
        cin>>activity;
	}while(activity<1 || activity>6);
	switch(activity){
		case 1 :
			withdraw();
			break;
		case 2 :
			deposit();
			break;
		case 3 :
			history();
			break;
		case 4 :
			account();
			break;
		case 5 :
			type_of_account(vn);
			system("pause");
			menu();
			break;
		case 6:
			tranfer();
			break;
	}
}
void dangnhap(){
	long id,pin_code;
	system("cls");
	cout<<"***********************************************************"<<endl;
    cout<<"                   Welcomes you to ATM                     "<<endl;
    cout<<"***********************************************************"<<endl;
    cout<<"Processing..."<<endl;
    cout<<"Card detected! Enter your 8 ID card numbers(Press Enter when finish): ";
    cin>>id;
    cout<<"Enter your 6 pin code numbers(Press Enter when finish): ";
	cin>>pin_code;
    system("cls");
    cout<<"Processing..."<<endl;
    system("cls");
    int x=4;
    int check=1;
    while(pin_code!=vn.pass || id!=vn.id_card ){
    	if(x==0){
    		system("cls");
			cout<<"YOU HAVE TRIED MORE THAN FIVE TIMES AND HAVE BEEN FROZEN!!!"<<endl;
			exit (0);
		}
		cout<<endl;
    	cout<<"WRONG NUMBERS!!!"<<endl;
    	cout<<"YOU HAVE "<<x<<" TO RE-ENTER YOUR NUMBERS!!"<<endl;
		cout<<"PLEASE RE-ENTER YOUR ID CARD AND PIN CODE NUMBERS(PRESS ENTER WHEN FINISH):..."<<endl;
		cin>>id;
		cin>>pin_code;
		x--;
		check++;
	}
	if(check<=5){
	cout<<"WELCOMES! ACCOUNT:  "<<vn.id_card<<endl;
	system("pause");
	menu();
	}
}
void withdraw(){
	int choose_w;
	system ("cls");
	cout<<"***********************************************************"<<endl;
    cout<<"                       WITHDRAW CASH                        "<<endl;
    cout<<"***********************************************************"<<endl;
    cout<<endl;
    cout<<"ATTENTION!!THE WITHDRAWAL AMOUNT MUST BE A MULTIPLIER OF 10.000 VND AND ACCOUNT BALANCE MUST OVER 50000 VND!!"<<endl;
    cout<<"Enter the amount you want to withdraw: "<<endl;
    cin>>w_money;
    cout<<"Are you sure you want to withdraw this money? "<<endl;
    cout<<"YES(Press: 1) OR NO(Press: 2) ? "<<endl;
    cin>>choose_w;
    while(choose_w!=1){
        cout<<"Please enter the amount you want to withdraw:..."<<endl;
        cin>>w_money;
        cout<<"Are you sure you want to withdraw this money? "<<endl;
        cout<<"YES(Press: 1) OR NO(Press: 2) ? "<<endl;
        cin>>choose_w;
	}
	int k=w_money,c=1;
	//cout<<k<<endl;
	//cout<<w_money;
    if(w_money%10000!=0){
    	cout<<"INVALID WITHDRAWAL AMOUNT!!PLEASE TRY AGAIN!!";
    	cin>>w_money;
	}else if(vn.acc_money-w_money<50000){
		cout<<" INSUFFICENT BALANCE! PLEASE TRY AGAIN!!"<<endl;
		cin>>w_money;
	}else if(vn.acc_money-w_money>=50000){
		c--;
		if(w_money==10000){
			cout<<"10000 VND: "<<1<<endl;
		    b.k10--;
			cout<<"Total number of bills: "<<1<<endl;
			save_file_banking();
		}else if(w_money==20000){
			if(b.k20==0 && b.k10>=2){
			   cout<<"10000 VND: "<<2<<endl;
			   b.k10=b.k10-2;
			   save_file_banking();
			   cout<<"Total number of bills: "<<2<<endl;
			}else if(b.k10<2 && b.k20==0){
				cout<<"Sorry, we don't have money back!!"<<endl;
			}else if(b.k20!=0){
			    cout<<"20000 VND: "<<1<<endl;
				cout<<"Total number of bills: "<<1<<endl;
				b.k20--;
				save_file_banking();	
			}
		}else if(w_money>20000 && w_money <50000){
			int i=0,sum=0;
			int a[]={20000,10000};
			while(w_money!=0 ){
		    int num_m=w_money/a[i];
		    sum+=num_m;
		    if(num_m!=0){
		    	if(num_m==1){
		    		cout<<a[i]<<"VND"<<": "<<num_m<<" bill"<<endl;
				}else{
					cout<<a[i]<<"VND"<<": "<<num_m<<" bills"<<endl;
				}
			}
			w_money=w_money%a[i];
			if(num_m>b.k20 || num_m>b.k10){
				cout<<"Sorry, we don't have money back!!"<<endl;
			}else{
				if(a[i]==10000) b.k10=b.k10-num_m;
				if(a[i]==20000) b.k20=b.k20-num_m;
				save_file_banking();
			}
			i++;	
		}
		cout<<"Total number of bills: "<<sum<<endl;
		cout<<w_money;
		//vn.acc_money-=w_money;
		//save_file_user();
		}else if(w_money>=50000 &&w_money<100000){
			int i=0,sum=0,num_m;
			int a[]={50000,20000,10000};
			while(w_money!=0 ){
		    num_m=w_money/a[i];
		    sum+=num_m;
		    if(num_m!=0){
		    	if(num_m==1){
		    		cout<<a[i]<<"VND"<<": "<<num_m<<" bill"<<endl;
				}else{
					cout<<a[i]<<"VND"<<": "<<num_m<<" bills"<<endl;
				}
			}
			w_money=w_money%a[i];
			if(num_m>b.k50 ||num_m>b.k20 || num_m>b.k10){
				cout<<"Sorry, we don't have money back!!"<<endl;
			}else{
				if(a[i]==10000) b.k10=b.k10-num_m;
				if(a[i]==20000) b.k20=b.k20-num_m;
				if(a[i]==50000) b.k50=b.k50-num_m;
				save_file_banking();
			}
			i++;	
		}
		cout<<"Total number of bills: "<<sum<<endl;
		}else if(w_money>=100000 && w_money<200000){
			int i=0,sum=0,num_m;
			int a[]={100000,50000,20000,10000};
			while(w_money!=0 ){
		    num_m=w_money/a[i];
		    sum+=num_m;
		    if(num_m!=0){
		    	if(num_m==1){
		    		cout<<a[i]<<"VND"<<": "<<num_m<<" bill"<<endl;
				}else{
					cout<<a[i]<<"VND"<<": "<<num_m<<" bills"<<endl;
				}
			}
			w_money=w_money%a[i];
			if( num_m>b.k100 ||num_m>b.k50 ||num_m>b.k20 || num_m>b.k10){
				cout<<"Sorry, we don't have money back!!"<<endl;
			}else{
				if(a[i]==10000) b.k10=b.k10-num_m;
				if(a[i]==20000) b.k20=b.k20-num_m;
				if(a[i]==50000) b.k50=b.k50-num_m;
				if(a[i]==100000) b.k100=b.k100-num_m;
				save_file_banking();
			}
			i++;	
		}
		cout<<"Total number of bills: "<<sum<<endl;
		}else if(w_money>=200000 &&w_money<500000){
			int i=0,sum=0,num_m;
			int a[]={200000,100000,50000,20000,10000};
			while(w_money!=0 ){
		    num_m=w_money/a[i];
		    sum+=num_m;
		    if(num_m!=0){
		    	if(num_m==1){
		    		cout<<a[i]<<"VND"<<": "<<num_m<<" bill"<<endl;
				}else{
					cout<<a[i]<<"VND"<<": "<<num_m<<" bills"<<endl;
				}
			}
			w_money=w_money%a[i];
			if( num_m>b.k200 ||num_m>b.k100||num_m>b.k50 ||num_m>b.k20 || num_m>b.k10){
				cout<<"Sorry, we don't have money back!!"<<endl;
			}else{
				if(a[i]==10000) b.k10=b.k10-num_m;
				if(a[i]==20000) b.k20=b.k20-num_m;
				if(a[i]==50000) b.k50=b.k50-num_m;
				if(a[i]==100000) b.k100=b.k100-num_m;
				if(a[i]==200000)b.k200=b.k200-num_m;
				save_file_banking();
			}
			i++;	
		}
		cout<<"Total number of bills: "<<sum<<endl;	
		}else if(w_money>=500000){
			int i=0,sum=0,num_m;
			int a[]={500000,200000,100000,50000,20000,10000};
			while(w_money!=0 ){
		    num_m=w_money/a[i];
		    sum+=num_m;
		    if(num_m!=0){
		    	if(num_m==1){
		    		cout<<a[i]<<"VND"<<": "<<num_m<<" bill"<<endl;
				}else{
					cout<<a[i]<<"VND"<<": "<<num_m<<" bills"<<endl;
				}
			}
			w_money=w_money%a[i];
			if(num_m>b.k500|| num_m>b.k200 ||num_m>b.k100||num_m>b.k50 ||num_m>b.k20 || num_m>b.k10){
				cout<<"Sorry, we don't have money back!!"<<endl;
			}else{
				if(a[i]==10000) b.k10=b.k10-num_m;
				if(a[i]==20000) b.k20=b.k20-num_m;
				if(a[i]==50000) b.k50=b.k50-num_m;
				if(a[i]==100000)b.k100=b.k100-num_m;
				if(a[i]==200000)b.k200=b.k200-num_m;
				if(a[i]==500000)b.k500=b.k500-num_m;
				save_file_banking();
			}
			i++;	
		}
		cout<<"Total number of bills: "<<sum<<endl;
		}	
	}
	if(c==0){
		vn.acc_money=vn.acc_money-k;
		if(k>=10000 && k<10000000){
			vn.number_acc+=1;
		}
		if(k>=10000000 && k<100000000){
			vn.number_acc+=2;
		}
		if(k>=100000000 && k<1000000000){
			vn.number_acc+=3;
		}
		if(k>=1000000000 && k<5000000000){
			vn.number_acc+=5;
		}
		if(k>=5000000000){
			vn.number_acc+=10;
		}
	    save_file_user();
	    cout<<"\nNEW BALANCE: "<<vn.acc_money<<endl;
        cout<<endl;
        History*p=new H_withdraw(w_money,vn.acc_money);
        p->t_time();
        system("pause");
        eject();
	}

}
void deposit(){
	int choose_d,d_opt;
	system("cls");
	do{
		cout<<"***********************************************************"<<endl;
        cout<<"                       DEPOSIT CASH                        "<<endl;
        cout<<"***********************************************************"<<endl;
        cout<<endl;
        cout<<"NOTE THAT YOU CAN ONLY DEPOSIT AMOUNTS WITH BILLS OF THE SAME DENOMINATION!!!!"<<endl;
        cout<<"Please enter the amount you want to send:..."<<endl;
        cin>>d_money;
        cout<<"Are you sure you want to send this money? "<<endl;
        cout<<"YES(Press: 1) OR NO(Press: 2) ? "<<endl;
        cin>>choose_d;
        while(choose_d!=1){
        	cout<<"Please enter the amount you want to send:..."<<endl;
            cin>>d_money;
            cout<<"Are you sure you want to send this money? "<<endl;
            cout<<"YES(Press: 1) OR NO(Press: 2) ? "<<endl;
            cin>>choose_d;
		}
        system("cls");
        cout<<"            DEPOSIT OPTIONS                       "<<endl;
        cout<<"\n 1. 10.000 VND(Muoi Nghin Dong)             : Press 1"<<endl;
        cout<<"\n 2. 20.000 VND(Hai Muoi Nghin Dong)         : Press 2"<<endl;
        cout<<"\n 3. 50.000 VND(NAm Muoi Nghin Dong)         : Press 3"<<endl;
        cout<<"\n 4. 100.000 VND(Mot Tram Nghin Dong)        : Press 4"<<endl;
        cout<<"\n 5. 200.000 VND(Hai Tram Nghin Dong)        : Press 5"<<endl;
        cout<<"\n 6. 500.000 VND(Nam Tram Nghin Dong)        : Press 6"<<endl;
        cout<<"\n 7. CANCEL (Exit & Return to CUSTOMER MENU) : Press 7"<<endl;
        cout<<endl;
        cout<<"Please select amount you want to deposit from the listed options"<<endl;
        cin>>d_opt;
	}while(d_opt<1 || d_opt>7);
	 switch(d_opt){
		case 1:
		 cout<<"Enter the number of bills of 10000 VND denomination:... "<<endl;
		 cin>>number;
		 cout<<"Now put your money in..."<<endl;
		 system("pause");
		 cout<<"\n>> Please wait while funds are verified..."<<endl;
		 if(number*10000!=d_money){
		 	system("cls");
		 	cout<<"THE AMOUNT YOU SEND IS NOT TRUE. PLEASE CHECK IT AGAIN!!"<<endl;
		 }else{
		 	system("cls");
		 	vn.acc_money+=d_money;
		 	cout<<"\nNEW BALANCE: "<<vn.acc_money<<endl;
            cout<<"\nThank you!"<<endl;
            cout<<endl;
            History*p=new H_deposit(d_money,vn.acc_money);
            p->t_time();
            save_file_user();
            system("pause");  
		 }
		 b.k10=b.k10+number;
		 save_file_banking();
		 menu();
		break;
		case 2:
		 cout<<"Enter the number of bills of 20000 VND denomination:... "<<endl;
		 cin>>number;
		 cout<<"Now put your money in..."<<endl;
		 system("pause");
		 cout<<"\n>> Please wait while funds are verified..."<<endl;
		 if(number*20000!=d_money){
		 	system("cls");
		 	cout<<"THE AMOUNT YOU SEND IS NOT TRUE. PLEASE CHECK IT AGAIN!!"<<endl;
		 }else{
		 	system("cls");
		 	vn.acc_money+=d_money;
		 	cout<<"\nNEW BALANCE: "<<vn.acc_money<<endl;
            cout<<"\nThank you!"<<endl;
            cout<<endl;
            History*p=new H_deposit(d_money,vn.acc_money);
            p->t_time();
            save_file_user();
            system("pause");
		 }
		 b.k20=b.k20+number;
		 save_file_banking();
		 menu();
		 break;	
		case 3:
		 cout<<"Enter the number of bills of 50000 VND denomination:... "<<endl;
		 cin>>number;
		 cout<<"Now put your money in..."<<endl;
		 system("pause");
		 cout<<"\n>> Please wait while funds are verified..."<<endl;
		 if(number*50000!=d_money){
		 	system("cls");
		 	cout<<"THE AMOUNT YOU SEND IS NOT TRUE. PLEASE CHECK IT AGAIN!!"<<endl;
		 }else{
		 	system("cls");
		 	vn.acc_money+=d_money;
		 	cout<<"\nNEW BALANCE: "<<vn.acc_money<<endl;
            cout<<"\nThank you!"<<endl;
            cout<<endl;
            History*p=new H_deposit(d_money,vn.acc_money);
            p->t_time();
            save_file_user();
            system("pause");  
		 }
		 b.k50=b.k50+number;
		 save_file_banking();
		 menu();
		 break;
		case 4:
		 cout<<"Enter the number of bills of 100000 VND denomination:... "<<endl;
		 cin>>number;
		 cout<<"Now put your money in..."<<endl;
		 system("pause");
		 cout<<"\n>> Please wait while funds are verified..."<<endl;
		 if(number*100000!=d_money){
		 	system("cls");
		 	cout<<"THE AMOUNT YOU SEND IS NOT TRUE. PLEASE CHECK IT AGAIN!!"<<endl;
		 }else{
		 	system("cls");
		 	vn.acc_money+=d_money;
		 	cout<<"\nNEW BALANCE: "<<vn.acc_money<<endl;
            cout<<"\nThank you!"<<endl;
            cout<<endl;
            History*p=new H_deposit(d_money,vn.acc_money);
            p->t_time();
            save_file_user();
            system("pause");
		 }
		 b.k100=b.k100+number;
		 save_file_banking();
		 menu();
		 break;
		case 5:
		 cout<<"Enter the number of bills of 200000 VND denomination:... "<<endl;
		 cin>>number;
		 cout<<"Now put your money in..."<<endl;
		 system("pause");
		 cout<<"\n>> Please wait while funds are verified..."<<endl;
		 if(number*200000!=d_money){
		 	system("cls");
		 	cout<<"THE AMOUNT YOU SEND IS NOT TRUE. PLEASE CHECK IT AGAIN!!"<<endl;
		 }else{
		 	system("cls");
		 	vn.acc_money+=d_money;
		 	cout<<"\nNEW BALANCE: "<<vn.acc_money<<endl;
            cout<<"\nThank you!"<<endl;
            cout<<endl;
            History*p=new H_deposit(d_money,vn.acc_money);
            p->t_time();
            save_file_user();
            system("pause"); 
		 }
		 b.k200=b.k200+number;
		 save_file_banking();
		 menu();
		 break;
		case 6:
		 cout<<"Enter the number of bills of 500000 VND denomination:... "<<endl;
		 cin>>number;
		 cout<<"Now put your money in..."<<endl;
		 system("pause");
		 cout<<"\n>> Please wait while funds are verified..."<<endl;
		 if(number*500000!=d_money){
		 	system("cls");
		 	cout<<"THE AMOUNT YOU SEND IS NOT TRUE. PLEASE CHECK IT AGAIN!!"<<endl;
		 }else{
		 	system("cls");
		 	vn.acc_money+=d_money;
		 	cout<<"\nNEW BALANCE: "<<vn.acc_money<<endl;
            cout<<"\nThank you!"<<endl;
            cout<<endl;
            History*p=new H_deposit(d_money,vn.acc_money);
            p->t_time();
            save_file_user();
            system("pause");
		 }
		 b.k500=b.k500+number;
		 save_file_banking();
		 menu();
		 break;
		case 7:
			cout<<"\nEXITING DEPOSIT OPTIONS..."<<endl;
            cout<<"\nReturning to CUSTOMER MENU..."<<endl;
            cout<<"\nPlease wait..."<<endl;
            system("pause");
            system("cls");
            menu ();
            break;
			
	}
}
void history(){
	system("cls");
    cout<<"*************************************************************"<<endl;
    cout<<"                           HISTORY                           "<<endl;
    cout<<"*************************************************************"<<endl;
    cout<<endl;
    fstream ifs("history.txt");
    string s;
    while(!ifs.eof()){
    	getline(ifs,s);
        cout<<s<<endl;
	}
	ifs.close();
    system("pause");
    menu ();
}

void account(){
	int choose_acc;
	system("cls");
    cout<<"ACCOUNT: "<<vn.id_card<<endl;
    cout<<"Your balance is: "<<vn.acc_money<<" VND"<<endl;
    cout<<"Your accumulated points are: "<<vn.number_acc<<endl;
    cout<<"Thank you!"<<endl;
    system("pause");
    cout<<"Do you want exit CHECK BALANCE ?"<<endl;
    cout<<"YES( Press: 1) OR NO(Press: 2) ? "<<endl;
    cin>>choose_acc;
    if(choose_acc==1){
    cout<<"\nEXITING CHECK BALANCE..."<<endl;
    cout<<"\nReturning to CUSTOMER MENU..."<<endl;
    cout<<"\nPlease wait..."<<endl;
    system("pause");
    system("cls");
    menu ();   	
	}else{
		system("cls");
		cout<<"Thank you!"<<endl;
	}
}

void tranfer(){
	system("cls");
	long o_number;
	cout<<"Enter old pin code numbers: ";
	cin>>o_number;
	int x=0;
	while(o_number!=vn.pass){
		cout<<"WRONG PIN CODE NUMBERS!PLEASE TRY AGAIN!"<<endl;
		cin>>o_number;
		x++;
		if(x>=4){
			cout<<"Entering the wrong PIN code numbers too many times!"<<endl;
			cout<<" YOUR ACCOUNT HAVE BEEN FROZEN!"<<endl;
			exit(0);
		}
	}
	cout<<"Enter the pin code numbers you want to change: "<<endl;
	cin>>c_number;
	system("cls");
	cout<<"Confirm new pin code: ";
	cin>>cc_number;
	while(c_number!=cc_number){
		cout<<"WRONG PIN CODE NUMBERS!PLEASE TRY AGAIN!"<<endl;
		cin>>cc_number;
	}
	vn.pass=cc_number;
	save_file_user();
	cout<<"CHANGE PIN CODE NUMBERS SUCCESSFULLY!!"<<endl;
	cout<<"WITHDRAW YOUR CARD TO LOG IN AGAIN!!"<<endl;
	cout<<"THANK YOU!"<<endl;
}
void eject(){
	system("cls");
	cout<<"***********************************************************"<<endl;
    cout<<"                       ATM SERVICE                         "<<endl;
    cout<<"***********************************************************"<<endl;
    cout<<"\nCard ejecting..."<<endl;
    cout<<"\nPlease wait..."<<endl;
    cout<<"\nCard ejected!"<<endl;
    cout<<"\nYOU HAVE TO WITHDRAW THE CARD FIRST BEFORE GET THE MONEY!"<<endl;
    cout<<"\nThank you for using ATM!!!"<<endl;
    cout<<endl;
    system("pause");
    system("cls");
}
int main(){
	cout<<"***********************************************************"<<endl;
    cout<<"                   Welcomes you to ATM                     "<<endl;
    cout<<"***********************************************************"<<endl;
    cout<<endl;
    cout<<"--INSERT CARD--"<<endl;
    system("pause");
    dangnhap();
}


