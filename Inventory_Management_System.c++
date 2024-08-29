#include <iostream>
#include <vector>
#include <string>
using namespace std;

int menu()
{
    int choice;
    cout << "Menu: " << endl
        << "1. Add Product" << endl
        << "2. Update Product" << endl
        << "3. Delete Product" << endl
        << "4. Show All Products" << endl
        << "5. Exit" << endl
        << "Enter Your choice:";
    cin >> choice;
    cin.ignore();
    return choice;
}

struct product
{
    string name;
    string des;
    int id;
    int units;
    double price;
};

struct shop
{
    vector<product> products;

    void add_product(const product& p)
    {
        products.push_back(p);
    }

    bool check_if_found(int id)
    {
        for (const product& it : products)
        {
            if (it.id == id)
            {
                return true;
            }
        }
        return false;
    }

    void update_product(int id, const product& p)
    {
        for (product& it : products)
        {
            if (it.id == id)
            {
                it = p;
                break;
            }
        }
    }

    void delete_product(int id)
    {
        for (auto it = products.begin(); it != products.end(); ++it)
        {
            if (it->id == id)
            {
                products.erase(it);
                break;
            }
        }
    }

    void show_all()
    {
        for (const product& p : products)
        {
            cout << "ID: " << p.id
                << ", Name: " << p.name
                << ", Price: " << p.price
                << ", Description: " << p.des
                << ", Units in Stock: " << p.units << endl;
        }
    }
};

int main()
{
    shop s;
    product p;
    int choice = menu();
    while (choice != 5)
    {
        switch (choice)
        {
		case 1:
		{
			cout << "Enter Product ID: ";
			cin >> p.id;
			if (p.id <= 0) {
				cout << "Invalid input";
				break;
			}
			cin.ignore();
			cout << "Enter Product Name: ";
			getline(cin, p.name);
			cout << "Enter Product Price: ";
			cin >> p.price;
			if (p.price <= 0) {
				cout << "Invalid input";
				break;
			}
			cin.ignore();
			cout << "Enter Product Description: ";
			getline(cin, p.des);
			cout << "Enter Product Units in Stock: ";
			cin >> p.units;
			if (p.units < 0) {
				cout << "Invalid input" << endl;
				break;
			}

			if (!s.check_if_found(p.id))
			{
				s.add_product(p);
				cout << "Product added successfully." << endl;
			}
			else
			{
				cout << "Product with ID: " << p.id << " already exists." << endl;
			}

			break;
		}
		case 2:
		{
			int id;
			cout << "Enter Product ID to update: ";
			cin >> id;
			p.id = id;
			cin.ignore();
			cout << "Enter new Product Name: ";
			getline(cin, p.name);
			cout << "Enter new Product Price: ";
			cin >> p.price;
			cin.ignore();
			cout << "Enter new Product Description: ";
			getline(cin, p.des);
			cout << "Enter new Product Units in Stock: ";
			cin >> p.units;
			s.update_product(id, p);
			cout << "Product updated successfully." << endl;
			break;
		}

		case 3:
		{
			int id2;
			cout << "Enter the ID to delete: ";
			cin >> id2;
			if (!s.check_if_found(id2))
			{
				cout << "Product Does not exist." << endl;
			}
			else
			{
				s.delete_product(id2);
				cout << "Product is Deleted successfully." << endl;
			}
			break;
		}


		case 4:
		{
			s.show_all();
			break;
		}

		default: {
			cout << "Invalid choice, please select again." << endl;
			break;
		}

		}

        choice = menu();
    }

    if (choice == 5)
    {
        cout << "Thanks for using our program! :)" << endl;
    }
    return 0;
}
