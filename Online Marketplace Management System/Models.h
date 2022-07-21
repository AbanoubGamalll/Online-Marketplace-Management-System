#include<iostream>
#include<string>

using namespace std;


string HomePage()
{
	cout << "                                  **************************\n";
	cout << "                                ONLINE MARKETPLACE MANAGMENT SYSTEM \n";
	cout << "                                 **************************\n";
	while (true)
	{
		cout << "1) Sell Prodact " << endl;
		cout << "2) Buy Prodact " << endl;
		cout << "3) Admin Page " << endl;
		cout << "4) Exit " << endl;
		cout << "Choose Number: ";
		string choose;
		cin >> choose;

		if (choose == "1" || choose == "2" || choose == "3" || choose == "4")
		{
			return choose;
		}
		else
		{
			cout << "Wrong Choice Try Again." << endl;
		}
	}

}

string chooseAcess()
{
	cout << "----------------------------------------------------------------------" << endl;
	cout << "1)Login" << endl;
	cout << "2)Regester" << endl;
	cout << "Choose Number: ";
	string input;
	cin >> input;
	return input;
}
/////////////////////////////////////
//Models
class CustomerModel
{
private:
	string id, name, address, phoneNumber, email, CustomerCart, password,cardid[10];
	int size = 0;
	double totalPrice = 0;
public:

	CustomerModel() {}

	string GetAddress()
	{
		return address;
	}
	string GetId()
	{
		return id;
	}
	string GetEmail()
	{
		return email;
	}
	string GetPassword()
	{
		return password;
	}
	string GetName()
	{
		return name;
	}
	string GetphoneNumber()
	{
		return phoneNumber;
	}
	string GetCustomerCart()
	{
		return CustomerCart;
	}
	
	void SetId(string id)
	{
		this->id = id;
	}
	
	void SetcardidProdactId(string id)
	{
		cardid[size] = id;
		size++;
	}

	string at(int i)
	{
		if (i < size && i>0)
		{
			return cardid[i];
		}
		else
		{
			return "-1";
		}
	}


	int getsize()
	{
		return size;
	}

	double getTotalPrice()
	{
		return totalPrice;
	}
	void SettotalPrice(double d)
	{
		totalPrice += d;
	}
	
	void SetAll(string id, string name, string address, string phoneNumber, string email, string CustomerCart, string password)
	{
		this->id = id;
		this->name = name;
		this->address = address;
		this->phoneNumber = phoneNumber;
		this->email = email;
		this->CustomerCart = CustomerCart;
		this->password = password;
	}

	void Regester()
	{
		string rid, rname, raddress, rphoneNumber, remail, rCustomerCart, rpassword;
		cout << "id: ";
		cin >> rid;
		cout << "name: ";
		cin.ignore();
		getline(cin, rname);
		cout << "phone num: ";
		cin >> rphoneNumber;
		cout << "address: ";
		cin.ignore();
		getline(cin, raddress);
		cout << "email: ";
		cin >> remail;
		cout << "Card Number: ";
		cin >> rCustomerCart;
		cout << "Password: ";
		cin.ignore();
		getline(cin, rpassword);
		SetAll(rid, rname, raddress, rphoneNumber, remail, rCustomerCart, rpassword);
	}

};

class productmodel
{

private:
	string id, name, category, seller_id;
	double price;

public:
	productmodel()
	{

	}

	void setall(string id, string name, string category, string seller_id, double price)
	{
		this->id = id;
		this->name = name;
		this->category = category;
		this->seller_id = seller_id;
		this->price = price;
	}
	void setid(string id)
	{
		this->id = id;
	}
	void setname(string name)
	{
		this->name = name;
	}
	void setcategory(string category)
	{
		this->category = category;
	}
	void setseller_id(string seller_id)
	{
		this->seller_id = seller_id;
	}
	void setprice(double price)
	{
		this->price = price;
	}

	string getid()
	{
		return id;
	}
	string getname()
	{
		return name;
	}
	string getcategory()
	{
		return category;
	}
	string getseller_id()
	{
		return seller_id;
	}
	double getprice()
	{
		return price;
	}
	void addproduct(string psaller_id)
	{
		string  pid, pname, pcategory;
		double pprice;
		cout << "id: ";
		cin >> pid;
		cout << "name: ";
		cin >> pname;
		cout << "category: ";
		cin >> pcategory;
		cout << "price: ";
		cin >> pprice;
		
		setall(pid, pname, pcategory, psaller_id, pprice);
	}

};

class SellerModel
{
private:
	string id, name, email, pass, arr[10];
	int size = 0;
public:
	SellerModel() {}

	void SetAll(string id, string email, string name, string pass)
	{
		this->id = id;
		this->email = email;
		this->name = name;
		this->pass = pass;
	}

	void SetId(string id) {
		this->id = id;
	}
	void SetEmail(string email) {
		this->email = email;
	}
	void SetName(string name) {
		this->name = name;
	}
	void SetPass(string pass) {
		this->pass = pass;

	}
	string GetId()
	{
		return id;
	}

	string GetEmail()
	{
		return email;
	}
	string GetName()
	{
		return name;
	}
	string GetPassword()
	{
		return pass;
	}

	void addSeller()
	{
		string  sid, sname, semail, spass;
		cout << "id: ";
		cin >> sid;
		cout << "name: ";
		cin.ignore();
		getline(cin, sname);
		cout << "Email: ";
		cin >> semail;
		cout << "Password: ";
		cin.ignore();
		getline(cin, spass);
		SetAll(sid, semail, sname, spass);
	};
};
