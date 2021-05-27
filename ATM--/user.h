#ifndef user_h
#define user_h
#include<iostream>

using namespace std;

struct user{
	long id_card;
	long pass;
	long long int acc_money;
	int number_acc;
	user(){
	ifstream file("file_luu_pass.txt",ios::in|ios::app);
	while(!file.eof()){
	    file>>id_card;
	    file>>pass;
	    file>>acc_money;
	    file>>number_acc;
	}
    }
};

void type_of_account(user &vn){
	system("cls");
	if(vn.acc_money<1000000000 && vn.number_acc<100){
		cout<<"Your account is a SPENDING account!"<<endl;
		cout<<"Accumulated points: "<<vn.number_acc<<endl;
		cout<<"Privileges for standard members: "<<endl;
		cout<<"*Free money transfer."<<endl;
		cout<<"*Offer to experience promotions."<<endl;
		cout<<"Details of privileges when becoming a SPENDING account please see our website for more details!"<<endl;
		cout<<"Thank you!"<<endl;
	}
	if(vn.acc_money>=1000000000&&vn.acc_money<10000000000 && vn.number_acc>=100 && vn.number_acc<500){
		cout<<"Your account is a GOLD account!"<<endl;
		cout<<"Accumulated points: "<<vn.number_acc<<endl;
		cout<<"*Free money transfer."<<endl;
		cout<<"*Offer to experience promotions."<<endl;
		cout<<"*You will have your own service specialist, have your own line to transact, and especially serve immediately without waiting.";
		cout<<"*You will have your own transaction room, luxuriously designed and comfortable";
		cout<<"Details of privileges when becoming a GOLD account please see our website for more details!"<<endl;
		cout<<"Thank you!"<<endl;
	}
	if(vn.acc_money>=10000000000&&vn.acc_money<20000000000 && vn.number_acc>=500 && vn.number_acc<1000){
		cout<<"Your account is a PLATIUM account!"<<endl;
		cout<<"Accumulated points: "<<vn.number_acc<<endl;
		cout<<"*Free money transfer."<<endl;
		cout<<"*Offer to experience promotions."<<endl;
		cout<<"*You will have your own service specialist, have your own line to transact, and especially serve immediately without waiting.";
		cout<<"*You will have your own transaction room, luxuriously designed and comfortable";
		cout<<"*You will be added interest rates for priority customers when depositing, reduced interest rates when borrowing capital, exemption and reduction of some fees";
		cout<<"*Preferential services associated with banks with much cheaper costs at golf courses, 5-star hotels, yachts, seaplanes...";
		cout<<"*You will be free at any lounge for domestic flights, applicable at all airports.";
		cout<<"Details of privileges when becoming a GOLD account please see our website for more details!"<<endl;
		cout<<"Thank you!"<<endl;	
	}
	if(vn.acc_money>=20000000000 && vn.number_acc>=1000){
		cout<<"Your account is a DIAMOND account!"<<endl;
		cout<<"Accumulated points: "<<vn.number_acc<<endl;
		cout<<"*Free money transfer."<<endl;
		cout<<"*Offer to experience promotions."<<endl;
		cout<<"*You will have your own service specialist, have your own line to transact, and especially serve immediately without waiting.";
		cout<<"*You will have your own transaction room, luxuriously designed and comfortable";
		cout<<"*You will be added interest rates for priority customers when depositing, reduced interest rates when borrowing capital, exemption and reduction of some fees";
		cout<<"*Preferential services associated with banks with much cheaper costs at golf courses, 5-star hotels, yachts, seaplanes...";
		cout<<"*You will be free at any lounge for domestic flights, applicable at all airports.";
		cout<<"*You will be granted 1 free annual credit card for life with a limit of up to VND 2 billion, free to issue a beautiful number account (from 4 to 8 identical numbers) and free of most fees.";
		cout<<"*You will have experts to support customers to make informed decisions in investment, maximize benefits and profits.";
		cout<<"*You will be specially designed by the bank for investment products that ordinary customers do not have the opportunity to access: fund certificates, real estate investment, foreign currencies...";
		cout<<"Details of privileges when becoming a DIAMOND account please see our website for more details!"<<endl;
		cout<<"Thank you!"<<endl;		
	}
	int choose;
	cout<<"Do you want to see the benefits of being a gold, platinum, and diamond account ? "<<endl;
	cout<<"Yes( Press: 1) OR No(Press: 2) ? "<<endl;
	cin>>choose;
	if(choose==1){
		system("cls");
		ifstream hihi("users.txt");
		string s;
		while(!hihi.eof()){
    	getline(hihi,s);
        cout<<s<<endl;
	}
	hihi.close();
	}else{
	   cout<<"Thank you for using the service!"<<endl;	
	}
}  
#endif
