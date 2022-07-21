#include<iostream>
#include<map>
#include<iterator>
#include"Models.h"


using namespace std;

map<string, CustomerModel> Customer;
map<string, productmodel> product;
map<string, SellerModel> Seller;
string productid, Customertid, Sellertid;

void inicial()
{
	Seller["s1"].SetAll("id1", "a1", "ab1", "pass1");
	Seller["s2"].SetAll("id2", "a2", "ab2", "pass1");
	Seller["s3"].SetAll("id3", "a3", "ab3", "pass1");
	Seller["s4"].SetAll("id4", "a4", "ab4", "pass1");
	////////////////////////////////////////////////////////////////////////////////
	Customer["id1"].SetAll("id1", "a1", "ab1", "abc1", "abcd1", "abcdf1", "pass1");
	Customer["id2"].SetAll("id2", "a2", "ab2", "abc2", "abcd2", "abcdf2", "pass2");
	Customer["id3"].SetAll("id3", "a3", "ab3", "abc3", "abcd3", "abcdf3", "pass3");
	Customer["id4"].SetAll("id4", "a4", "ab4", "abc4", "abcd4", "abcdf4", "pass4");
	////////////////////////////////////////////////////////////////////////////////
	product["id1"].setall("id1", "aaa", "food", "123", 120.0);
	product["id2"].setall("id2", "bbb", "electronics", "`321", 16000.0);
	product["id3"].setall("id3", "ccc", "vehichles", "555", 90000.0);
	product["id4"].setall("id3", "ddd", "food", "555", 90000.0);
	product["id5"].setall("id4", "fff", "food", "555", 90000.0);
	////////////////////////////////////////////////////////////////////////////////
}


////////////////////////////////////////////////////////////////////////////////
//Customer
string loginCustomer()
{
	string id, pass;
	cout << "Enter your ID: ";
	cin >> id;
	if (Customer.find(id) == Customer.end())
	{
		cout << "ID Not Found" << endl;
		return "-1";
	}
	else {
		cout << "Enter Your Password: ";
		cin.ignore();
		getline(cin, pass);
		if (Customer[id].GetPassword() == pass)
		{
			cout << "Email Is Correct" << endl;
		}
		else
		{
			cout << "Password IS Notcorrect" << endl;
			return "-1";
		}
	}
	return id;
}

string CheckCustomerByID(string id)
{
	Customertid = "-1";
	bool check = false;
	for (auto it = Customer.begin(); it != Customer.end(); it++)
	{
		if (it->second.GetId() == id)
		{
			Customertid = it->first;
			check = true;
			break;
		}
	}
	return Customertid;
}

string regesterCustomer()
{
	CustomerModel c;
	c.Regester();
	
	while (true)
	{
		Customertid = CheckCustomerByID(c.GetId());

		if (Customertid == "-1")
		{
			Customer[c.GetId()] = c;
			cout << "account is added." << endl;
			break;
		}
		else
		{
			string x;
			cout << "Enter New ID: ";
			cin >> x;
			c.SetId(x);
		}
	}

	return c.GetId();
}
///////////////////////////////////////////////////////////////////////////////
//Prodact
string SearchProdactByID()
{
	productid = "-1";
	string id;
	cout << "Enter product ID:";
	cin >> id;
	bool check = false;
	for (auto it = product.begin(); it != product.end(); it++)
	{
		if (it->second.getid() == id)
		{
			cout << "find" << endl;
			productid = it->first;
			check = true;
			break;
		}
	}
	if (check == false)
	{
		cout << "this product is not found" << endl;
	}
	return productid;
}

string CheckProdactByID(string id)
{
	productid = "-1";
	bool check = false;
	for (auto it = product.begin(); it != product.end(); it++)
	{
		if (it->second.getid() == id)
		{
			productid = it->first;
			check = true;
			break;
		}
	}
	return productid;
}

string SearchProdactByCategory()
{
	productid = "-1";
	string category;
	cout << "enter your product category :";
	cin >> category;
	int count = 0;

	for (auto it = product.begin(); it != product.end(); it++)
	{
		if (it->second.getcategory() == category)
		{
			if (count == 0)
			{
				cout << "Id		" << "Category	" << "Name	    " << "price" << endl;
				cout << "----------------------------------------------------------------------" << endl;
			}
			cout << it->second.getid()
				<< "		" << it->second.getcategory()
				<< "		" << it->second.getname()
				<< "	    " << it->second.getprice() << endl;
			productid = it->first;
			count++;
		}
	}
	if (count == 0)
	{
		cout << "Category is not found" << endl;
	}
	else
	{
		cout << "----------------------------------------------------------------------" << endl;
	}

	if (count != 1 && count != 0) {
		productid = SearchProdactByID();
	}
	return productid;
}

string SearchProdactByName()
{
	 productid = "-1";
	string category;
	cout << "enter your product category :";
	cin >> category;
	int count = 0;

	for (auto it = product.begin(); it != product.end(); it++)
	{
		if (it->second.getname() == category)
		{
			if (count == 0)
			{
				cout << "Id		" << "Category	" << "Name	    " << "price" << endl;
				cout << "----------------------------------------------------------------------" << endl;
			}
			cout << it->second.getid()
				<< "		" << it->second.getcategory()
				<< "		" << it->second.getname()
				<< "	    " << it->second.getprice() << endl;
			productid = it->first;
			count++;
		}
	}
	if (count == 0)
	{
		cout << "Category is not found" << endl;
	}
	else
	{
		cout << "----------------------------------------------------------------------" << endl;
	}

	if (count != 1 && count != 0) {
		productid = SearchProdactByID();
	}
	return productid;
}

void AddProduct(string id)
{
	productmodel p;
	p.addproduct(id);
	while (true)
	{
		productid = CheckProdactByID(p.getid());

		if (productid == "-1")
		{
			product[p.getid()] = p;
			cout << "Prodact Is Added" << endl;
			break;
		}
		else
		{
			string s;
			cout << "Enter New ID: ";
			cin >> s;
			p.setid(s);
		}
	}
}

string chooseSearch()
{
	string choose;
	cout << "----------------------------------------------------------------------" << endl;
	cout << " choose to search" << endl;
	cout << "1) search by category" << endl;
	cout << "2) search by name" << endl;
	cout << "3) Show All Prdact" << endl;
	cout << "4) Show My Cart" << endl;
	cout << "5) Go to main " << endl;

	cout << "Choose Number: ";

	cin >> choose;
	return choose;
}

string ShowAllProdact()
{
	cout << "Id		" << "Category		" << "Name	" << "price		" << endl;
	cout << "----------------------------------------------------------------------" << endl;
	for (auto it = product.begin(); it != product.end(); it++)
	{
		cout << it->second.getid()
			<< "		" << it->second.getcategory()
			<< "		" << it->second.getname()
			<< "	    " << it->second.getprice() << endl;
	}
	cout << "----------------------------------------------------------------------" << endl;
	string id = SearchProdactByID();
	return id;
}

void ConfiremAndAdd(string pid)
{
	cout << "Do you want to buy prodact "<<product[pid].getname()<<" (y/n): ";
	string input; 
	cin >> input;
	if (input == "y" || input == "Y")
	{
		double x = product[pid].getprice();
		Customer[Customertid].SetcardidProdactId(pid);
		Customer[Customertid].SettotalPrice(x);
		cout << "prodact is added to your card" << endl;
		cout << "Your Total Price is: "<< Customer[Customertid].getTotalPrice() << endl;

	}
}

string CustomerPage(string cid)
{
	Customertid = cid;
	while (true)
	{
		cout << "HELLO: " + Customer[cid].GetName() << endl;
		string choose = chooseSearch();
		//search by category
		if (choose == "1")
		{
			productid = SearchProdactByCategory();
			if (productid != "-1")
			{
				ConfiremAndAdd(productid);
				//confirm and add to Userlist
			}
		}
		//search by name
		else if (choose == "2")
		{
			productid = SearchProdactByName();
			if (productid != "-1")
			{
				ConfiremAndAdd(productid);
				//confirm and add to Userlist
			}
		}
		//Show All Prodact
		else if (choose == "3")
		{
			productid = ShowAllProdact();
			while (productid == "-1")
			{
				productid = SearchProdactByID();
			}
			if (productid != "-1") { 
				ConfiremAndAdd(productid); 
				 }
		}
		else if (choose == "4")
		{
			cout << "Your Total Price is: " << Customer[Customertid].getTotalPrice() << endl;
			
		}
		else if (choose == "5")
		{
			return productid;
		}
		else
		{
			cout << "Wrong Choice Try Again." << endl;
		}
	}
	
}
///////////////////////////////////////////////////////////////////////////////
//Seller
string addAccountSeller()
{
	SellerModel m;
	m.addSeller();
	Seller[m.GetId()] = m;
	return m.GetId();
}

string loginSeller()
{
	string id, pass;
	cout << "Enter your ID: ";
	cin >> id;
	if (Seller.find(id) == Seller.end())
	{
		cout << "ID Not Found" << endl;
		return "-1";
	}
	else {
		cout << "Enter Your Password: ";
		cin.ignore();
		getline(cin, pass);
		if (Seller[id].GetPassword() == pass)
		{
			cout << "Email Is Correct" << endl;
		}
		else
		{
			cout << "Password IS Notcorrect" << endl;
			return "-1";
		}
	}
	return id;
}

string regesterSeller()
{
	string Sellerid;
	SellerModel c;
	c.addSeller();

	while (true)
	{
		if (Seller.find(c.GetId()) == Seller.end())
		{
			Seller[c.GetId()] = c;
			cout << "account is added." << endl;
			break;
		}
		else
		{
			string x;
			cout << "Enter New ID: ";
			cin >> x;
			c.SetId(x);
		}
	}

	return c.GetId();
}

void ShowMyProdact(string sid)
{

	bool check = false;
	for (auto it = product.begin(); it != product.end(); it++)
	{
		if (it->second.getseller_id() == sid)
		{
			if (check == false)
			{
				cout << "Id		" << "Category	" << "Name	    " << "price" << endl;
				cout << "----------------------------------------------------------------------" << endl;
			}
			cout << it->second.getid()
				<< "		" << it->second.getcategory()
				<< "		" << it->second.getname()
				<< "	    " << it->second.getprice() << endl;
			productid = it->first;
			check = true;
		}
	}
	if (check == false)
	{
		cout << "You dont have prodact" << endl;
	}
	else
	{
		cout << "----------------------------------------------------------------------" << endl;

	}

}

void SellerPage(string id)
{
	
	while (true)
	{
		cout << "1)Add prodact"<<endl;
		cout << "2)Show my prodact";
		string input;
		cin >> input;
		if (input == "1")
		{
			AddProduct(id);
			break;
		}
		else if (input == "2")
		{
			ShowMyProdact(id);
			break;
		}
		else
		{
			cout << "Wrong Choice Try Again." << endl;
		}
	}
	
}

///////////////////////////////////////////////////////////////////////////////

int main() {

	inicial();
	while (true)
	{
		string choose = HomePage();
		//Sell Prodact (Seller)
		if (choose == "1")
		{
			Sellertid = "-1";
			while (true)
			{
				string input = chooseAcess();
				if (input == "1")
				{
					Sellertid = loginSeller();
					break;
				}
				else if (input == "2")
				{
					Sellertid = regesterSeller();
					break;
				}
				else
				{
					cout << "Wrong Choice Try Again." << endl;
				}
			}
			if (Sellertid != "-1") {
				SellerPage(Sellertid);
			}
		}
		//Buy Prodact (Customer)
		else if (choose == "2") {
			Customertid = "-1";
			while (true)
			{
				string input = chooseAcess();
				if (input == "1")
				{
					Customertid = loginCustomer();
					break;
				}
				else if (input == "2")
				{
					Customertid = regesterCustomer();
					break;
				}
				else
				{
					cout << "Wrong Choice Try Again." << endl;
				}
			}
			if (Customertid != "-1") {
				CustomerPage(Customertid);
			}
		}
		//Admin Page
		else if (choose == "3") {
			//	loginAdmin();
		}
		else if (choose == "4") {
			cout << "GoodBye" << endl;
			return 0;
		}
	}
	return 0;
}