#include<iostream>
#include<fstream>
using namespace std;

class shopping{
	private:
		int pcode;
		float price;
		float dis;
		string pname;
		
	public:
		void menu();
		void adm();
		void buyer(); //customer
		void add();
		void edit();
		void rem();
		void list();
		void reciept();
};

void shopping :: menu(){
	m:
	int choice;
	string email;
	string password;
	
	cout<<"\t\t\t\t\t____________________________\n";
	cout<<"\t\t\t\t\t                            \n";
	cout<<"\t\t\t\t\t    SUPERMARKET MAIN MENU   \n";
	cout<<"\t\t\t\t\t                            \n";
	cout<<"\t\t\t\t\t____________________________\n";
	cout<<"\t\t\t\t\t                            \n";
	cout<<"\t\t\t\t\t|      1) Adminitrator     |\n";
	cout<<"\t\t\t\t\t|                          |\n";
	cout<<"\t\t\t\t\t|      2) Buyer            |\n";
	cout<<"\t\t\t\t\t|                          |\n";
	cout<<"\t\t\t\t\t|      3) Exit             |\n";
	cout<<"\t\t\t\t\t                            \n";
	cout<<"\n\t\t\t\t\t     Please Select:       \n";
	cin>>choice;
	
	switch(choice){
		case 1:
			cout<<"\t\t\t Please Login \n";
			cout<<"\t\t\t Enter Email  \n";
			cin>>email;
			cout<<"\t\t\t Password     \n";
			cin>>password;
			
			if(email=="roby@email.com" && password=="rob@123"){
				adm();
			}
			else{
				cout<<"INVALID ADMINISTRATOR";
			}
			break;
			
		case 2:
			buyer();
		case 3:
			exit(0);
		default:
			cout<<"Please select from given options";
	}
	goto m;
}

void shopping :: adm(){
	m:
	int choice;
	cout<<"\n\n\n\t\t\t Administrator Menu   ";
	cout<<"                                  ";
	cout<<"\n\t\t\t|  1) Add the product    |";
	cout<<"        |                        |";
	cout<<"\n\t\t\t|  2) Modify the product |";
	cout<<"        |                        |";
	cout<<"\n\t\t\t|  3) Delete the product |";
	cout<<"        |                        |";
	cout<<"\n\t\t\t|  4) Back to main menu  |";
	
	cout<<"\n\n\t Please enter your choice ";
	cin>>choice;
	switch(choice){
		case 1:
			add();
			break;
		case 2:
			edit();
			break;
		case 3:
			rem();
			break;
		case 4:
			menu();
			break;
		default:
			cout<<"INVALID CHOICE";
	}
	goto m;
}

void shopping :: buyer(){
	m:
	int choice;
	cout<<"\t\t\t    Buyer        \n";
	cout<<"                       \n";
	cout<<"\t\t\t 1) Buy Product  \n";
	cout<<"                       \n";
	cout<<"\t\t\t 2) Go back      \n";
	cout<<"\t\t\t    Enter your choice      \n";
	
	cin>>choice;
	switch(choice){
		case 1:
			reciept();
			break;
		case 2:
			menu();
		default:
			cout<<"INVALID CHOICE";
	}
	goto m;
}

void shopping :: add(){
	m:
	fstream data;
	int c;
	int token=0;
	float p;
	float d;
	string n;
	
	cout<<"\n\n\t\t\t Add new product";
	cout<<"\n\n\t\t\t Product code";
	cin>>pcode;
	cout<<"\n\n\t Name of the product";
	cin>>pname;
	cout<<"\n\n\t Price of the product";
	cin>>price;
	cout<<"\n\n\t Discount on the product";
	cin>>dis;
	
	data.open("database.txt", ios::in);
	
	if(!data){
		data.open("database.txt", ios::app| ios::out);
		data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<endl;
		data.close();
	}
	else{
		data>>c>>n>>p>>d;
		while(!data.eof()){
			if(c==pcode) token++;
			data>>c>>n>>p>>d;
		}
		data.close();
		if(token==1) goto m;
		else{
			data.open("database.txt", ios::app| ios::out);
			data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<endl;
			data.close();
		}
	}
	cout<<"\n\n\t\t Record Inserted";
}

void shopping :: edit(){
	fstream data, data1;
	int pkey;
	int token=0;
	int c;
	float p;
	float d;
	string n;
	
	cout<<"\n\t\t\t Modify the record";
	cout<<"\n\t\t\t Product code: ";
	cin>>pkey;
	
	data.open("database.txt", ios::in);
	if(!data) cout<<"\n\n File doesn't exist";
	else {
		data1.open("database1.txt", ios::app|ios::out);
		data>>pcode>>pname>>price>>dis;
		while(!data.eof()){
			if(pkey==pcode){
				cout<<"\n\t\t Product new code: ";
				cin>>c;
				cout<<"\n\t\t Name of the product: ";
				cin>>n;
				cout<<"\n\t\t Price: ";
				cin>>p;
				cout<<"\n\t\t Discount: ";
				cin>>d;
				data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<endl;
				cout<<"\n\n\t\t Record edited";
				token++;
			}
			else{
				data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<endl;
			}
			data>>pcode>>pname>>price>>dis;
		}
		data.close();
		data1.close();
		
		remove("database.txt");
		rename("database1.txt", "database.txt");
		
		if(token==0) cout<<"\n\n Record not found";
	}
}

void shopping :: rem(){
	fstream data, data1;
	int pkey;
	int token=0;
	cout<<"\n\n\t Delete Product";
	cout<<"\n\n\t Product code: ";
	cin>>pkey;
	data.open("database.txt", ios::in);
	if(!data){
		cout<<"File doesn't exist";
	}
	else{
		data1.open("database1.txt", ios::app|ios::out);
		data>>pcode>>pname>>price>>dis;
		while(!data.eof()){
			if(pcode==pkey){
				cout<<"\n\n\t Product deleted successfully";
				token++;
			}
			else{
				data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
			}
			data>>pcode>>pname>>price>>dis;
		}
		data.close();
		data1.close();
		remove("database.txt");
		rename("database1.txt", "database.txt");
		
		if(token==0){
			cout<<"\n\n Record not found";
		}
	}
}

void shopping :: list(){
	fstream data;
	data.open("database.txt", ios::in);
	cout<<"\n\n__________________________________\n";
	cout<<"Product Num\t\tName\t\tPrice\n";
	cout<<"\n\n__________________________________\n";
	data>>pcode>>pname>>price>>dis;
	while(!data.eof()){
		cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
		data>>pcode>>pname>>price>>dis;	
	}
	data.close();
}

void shopping :: reciept(){
	fstream data;
	int arrc[100];
	int arrq[100];
	char choice;
	int c=0;
	float amount=0;
	float dis=0;
	float total=0;
	
	cout<<"\n\n\t\t\t RECEIPT ";
	data.open("database.txt", ios::in);
	if(!data){
		cout<<"\n\n Empty database";
	}
	else{
		data.close();
		list();
		cout<<"\n___________________________\n";
		cout<<"\n                           \n";
		cout<<"     Please place the order  \n";
		cout<<"\n                           \n";
		cout<<"\n___________________________\n";
		
		do{
			m:
			cout<<"\n\n Enter Product code: ";
			cin>>arrc[c];
			cout<<"\n\n Enter product quantity";
			cin>>arrq[c];
			
			for(int i=0;i<c;i++){
					if(arrc[c]==arrc[i]){
						cout<<"\n\n Duplicate product code.";
						goto m;
					}	
			}
			c++;
			cout<<"\n\n Do you want to buy another product? if yes press y else n ";
			cin>>choice;
			}
			while(choice == 'y');
			cout<<"\n\n\t\t\t________________________RECIEPT_________________\n";
			cout<<"\nProduct No\t Product Name\t Product quantity\t price\t Amount\t Amount with discount\n";
			for(int i=0;i<c;i++){
				data.open("database.txt", ios::in);
				data>>pcode>>pname>>price>>dis;
				while(!data.eof()){
					if(pcode==arrc[i]){
						amount=price*arrq[i];
						dis=amount - (amount*dis/100);
						total=total+dis;
						cout<<"\n"<<pcode<<"\t\t "<<pname<<"\t\t "<<arrq[i]<<"\t\t "<<price<<"\t\t "<<amount<<"\t\t "<<dis;
					}
					data>>pcode>>pname>>price>>dis;
				}
			}
			data.close();		
	}
	cout<<"\n\n______________________________________________";
	cout<<"\n Total Amount: "<<total;
}

int main(){
	shopping s;
	s.menu();
} 
