#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>
using namespace std;

const int SIZE = 9;
string vg_n[SIZE];
int p[SIZE];
int k = 0;

const int s = 9;
string Vg_Name_Pointers[s] = {"potatoes", "onions", "tomatoes", "eggplant", "groud", "carrots", "cauliflower", "cabbage", "peas"}, Vg_Age[s] = {"Two_days", "Two_days", "One_day", "Three_days", "Three_days", "Two_days", "Two_days", "Three_days", "Two_days"};
int Vg_price_Pointers[s] = {120, 170, 180, 100, 80, 90, 100, 90, 150};
string *Vg_Age_ptr, *Vg_Name_ptr;
int *Vg_price_ptr;

double totalPrice_Pointers = 0;
int totalPrice_Variable = 0;
int totalPrice_Arrays = 0;

void withVariable();
void withArrays();
void withPointers();

void addRecord_withPointers();
void editRecord_withPointers();
void viewRecord_withPointers();
void searchRecord_withPointers();
void deleteRecord_withPointers();

void addRecord_Arrays();
void editRecord_Arrays();
void viewRecord_Arrays();
void searchRecord_Arrays();
void deleteRecord_Arrays();

void addRecord_withVariable();
void editRecord_withVariable();
void viewRecord_withVariable();
void searchRecord_withVariable();
void deleteRecord_withVariable();

int main()
{
    ofstream del[5];
    char option;
    bool error = false;

    cout << "\n----------Welcome----------" << endl;
    cout << "Vegetable Management System" << endl;
    cout << "\nTo Run through Pointers: Enter p: ";
    cout << "\nTo Run through Array: Enter a: ";
    cout << "\nTo Run through Simple Variable : Enter s: " << endl;

    do
    {
        if (error)
        {
            cout << "\nRe-Enter : ";
        }
        cin >> option;
        switch (option)
        {
        case 'p':
            error = false;
            withPointers();

            del[0].open("cart_Pointers.txt", ios::trunc);
            del[0].close();
            break;
        case 'a':
            error = false;
            withArrays();

            del[1].open("cart_Arrays.txt", ios::trunc);
            del[1].close();
            break;
        case 's':
            error = false;
            withVariable();

            del[2].open("cart_Simple.txt", ios::trunc);
            del[2].close();
            del[3].open("f1.txt", ios::trunc);
            del[3].close();
            del[4].open("f2.txt", ios::trunc);
            del[4].close();
            break;
        default:
            cout << "\nInput Error";
            error = true;
            break;
        }
    } while (error);
    return 0;
}

void withPointers()
{
    char option;
    cout << "\nRunning with Pointers" << endl;
    // Display welcome message
    cout << "\n----------Welcome----------" << endl;
    cout << "Vegetable Management System" << endl;

    do
    {
        // Display menu options
        cout << endl;
        cout << "-------------------------------------";
        cout << "\nTo see Menu, Enter m : ";
        cout << "\nTo Order, Enter o : ";
        cout << "\nTo empty your cart, Enter d : ";
        cout << "\nTo search in you cart, Enter s : ";
        cout << "\nTo edit your cart, Enter e : ";
        cout << "\nTo exit, Enter 0 : ";

        cout << "\n";

        // Get user input
        cin >> option;

        switch (option)
        {
        case 'm':
            viewRecord_withPointers();
            break;
        case 'o':
            addRecord_withPointers();
            break;
        case 'd':
            deleteRecord_withPointers();
            break;
        case 's':
            searchRecord_withPointers();
            break;
        case 'e':
            editRecord_withPointers();
            break;
        }

    } while (option != '0');
}
void withArrays()
{
    cout << "\nRunning with Arrays" << endl;
    char option;

    // Display welcome message
    cout << "\n----------Welcome----------" << endl;
    cout << "Vegetable Management System" << endl;

    do
    {
        // Display menu options
        cout << endl;
        cout << "-------------------------------------";
        cout << "\nTo see Menu, Enter m : ";
        cout << "\nTo Order, Enter o : ";
        cout << "\nTo empty your cart, Enter d : ";
        cout << "\nTo search in you cart, Enter s : ";
        cout << "\nTo edit your cart, Enter e : ";
        cout << "\nTo exit, Enter 0 : ";

        cout << "\n";

        // Get user input
        cin >> option;

        switch (option)
        {
        case 'm':
            viewRecord_Arrays();
            break;
        case 'o':
            addRecord_Arrays();
            break;
        case 'd':
            deleteRecord_Arrays();
            break;
        case 's':
            searchRecord_Arrays();
            break;
        case 'e':
            editRecord_Arrays();
            break;
        }

    } while (option != '0');
}
void withVariable()
{
    cout << "\nRunning with Simple Variable" << endl;
    char option;
    cout << "\n----------Welcome----------" << endl;
    cout << "Vegetable Management System" << endl;
    do
    {
        cout << endl;
        cout << "-------------------------------------";
        cout << "\nTo see Menu, Enter m : ";
        cout << "\nTo Order, Enter o : ";
        cout << "\nTo empty your cart, Enter d : ";
        cout << "\nTo search in you cart, Enter s : ";
        cout << "\nTo edit your cart, Enter e : ";
        cout << "\nTo exit, Enter 0 : ";

        cout << "\n";

        cin >> option;
        // Clear the input buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (option)
        {
        case 'm':
            viewRecord_withVariable();
            break;
        case 'o':
            addRecord_withVariable();
            break;
        case 'd':
            deleteRecord_withVariable();
            break;
        case 's':
            searchRecord_withVariable();
            break;
        case 'e':
            editRecord_withVariable();
            break;
        }

    } while (option != '0');
}

// Arrays functions

// Display the menu
void viewRecord_Arrays()
{
    const int s = 9;
    string Vg_Name[s] = {"potatoes", "onions", "tomatoes", "eggplant", "groud", "carrots", "cauliflower", "cabbage", "peas"}, Vg_Age[s] = {"Two_days", "Two_days", "One_day", "Three_days", "Three_days", "Two_days", "Two_days", "Three_days", "Two_days"};
    int Vg_price[s] = {120, 170, 180, 100, 80, 90, 100, 90, 150};
    for (int i = 0; i < s; i++)
    {
        cout << left << setw(12) << Vg_Name[i] << setw(12) << Vg_price[i] << setw(12) << Vg_Age[i] << endl;
    }
}

// Add items to the cart
void addRecord_Arrays()
{
    const int s = 9;
    string Vg_Name[s] = {"potatoes", "onions", "tomatoes", "eggplant", "groud", "carrots", "cauliflower", "cabbage", "peas"}, Vg_Age[s] = {"Two_days", "Two_days", "One_day", "Three_days", "Three_days", "Two_days", "Two_days", "Three_days", "Two_days"};
    int Vg_price[s] = {120, 170, 180, 100, 80, 90, 100, 90, 150};
    double amount;
    ofstream z;
    z.open("cart_Arrays.txt", ios ::app);
    string name;
    // Prompt user to select items
    cout << "To Select items from the menu , write the exact name of the vegetable: ";

    do
    {

        // Get vegetable name
        cout << "\nVegetable Name : ";
        cin >> name;
        if (name == "0")
        {
            break;
        }

        // Get quantity in kilograms
        cout << "\nHow much do you want in kgs : ";
        cin >> amount;

        for (int i = 0; i < s; i++)
        {

            // Find the selected item in the menu and add to the cart
            if (name == Vg_Name[i])
            {
                int price = Vg_price[i] * amount;
                totalPrice_Arrays += price;
                z << name << " " << price << endl;
                vg_n[k] = name;
                p[k] = price;
                k++;
                break;
            }
        }
        cout << "If you are done ordering, Enter 0 in Vegetable Name :";
    } while (name != "0");

    z.close();
}

// Empty the cart
void deleteRecord_Arrays()
{
    for (int i = 0; i < 9; i++)
    {
        vg_n[i] = "0";
        p[i] = 0;
    }
    ofstream x;
    x.open("cart_Arrays.txt", ios::trunc);
    x.close();
    totalPrice_Arrays = 0;
    cout << "\nYour Cart is empty now.";
}

// Search for items in the cart
void searchRecord_Arrays()
{
    string name;
    double price;
    bool none = true;

    // Prompt user to enter item name
    cout << "\nEnter the item name : ";
    cin >> name;

    bool found = false;
    // Open cart file and search for the item

    for (int i = 0; i < k; i++)
    {

        if (name == vg_n[i])
        {
            found = true;
        }
    }
    // Display whether the item is present in the cart or not
    if (found)
    {
        cout << "\nThe item is present in your cart.";
    }
    else
    {
        cout << "\nThe item is not present in your cart.";
    }

    cout << endl;

    // Display the contents of the cart
    cout << "\nThis is your cart:" << endl;
    cout << left << setw(12) << "Vegetable" << setw(12) << "Price" << endl;

    for (int i = 0; i < k; i++)
    {
        if (vg_n[i] != "0")
        {
            cout << left << setw(12) << vg_n[i] << setw(12) << p[i] << endl;
            none = false;
        }
    }
    if (none)
    {
        cout << "\nYour Cart is empty.";
    }
    cout << "\nTotal Price: " << totalPrice_Arrays;
}

// Edit the cart
void editRecord_Arrays()
{
    string name;
    ofstream x;

    cout << "\nTo remove certain item from your cart.";
    cout << "\nEnter the Exact Name of that vegetable : ";
    cin >> name;
    for (int i = 0; i < k; i++)
    {

        if (name == vg_n[i])
        {
            vg_n[i] = "0";
            totalPrice_Arrays -= p[i];
            p[i] = 0;
        }
    }
    x.open("cart_Arrays.txt", ios ::trunc);
    x.close();
    x.open("cart_Arrays.txt", ios ::app);

    for (int j = 0; j < k; j++)
    {
        if (vg_n[j] != "0")
        {
            x << vg_n[j] << " " << p[j] << endl;
        }
    }
    x.close();
    cout << "The vegetable is removed from your cart.";
}

// Pointers Function

// Display the menu
void viewRecord_withPointers()
{
    Vg_Age_ptr = Vg_Age;
    Vg_Name_ptr = Vg_Name_Pointers;
    Vg_price_ptr = Vg_price_Pointers;
    for (int i = 0; i < s; i++)
    {
        cout << left << setw(12) << *Vg_Name_ptr++ << setw(12) << *Vg_price_ptr++ << setw(12) << *Vg_Age_ptr++ << endl;
    }
}

// Add items to the cart
void addRecord_withPointers()
{

    double amount;
    ofstream z;
    z.open("cart_Pointers.txt", ios ::app);
    string name;
    // Prompt user to select items
    cout << "To Select items from the menu , write the exact name of the vegetable: ";

    do
    {

        Vg_Name_ptr = Vg_Name_Pointers;
        Vg_price_ptr = Vg_price_Pointers;
        // Get vegetable name
        cout << "\nVegetable Name : ";
        cin >> name;
        if (name == "0")
        {
            break;
        }

        // Get quantity in kilograms
        cout << "\nHow much do you want in kgs : ";
        cin >> amount;

        for (int i = 0; i < s; i++)
        {

            // Find the selected item in the menu and add to the cart
            if (name == *Vg_Name_ptr)
            {
                int price = *Vg_price_ptr * amount;
                totalPrice_Pointers += price;
                z << name << " " << price << endl;
                vg_n[k] = name;
                p[k] = price;
                k++;
                break;
            }
            Vg_Name_ptr++;
            Vg_price_ptr++;
        }
        cout << "If you are done ordering, Enter 0 in Vegetable Name :";
    } while (name != "0");

    z.close();
}

// Empty the cart
void deleteRecord_withPointers()
{
    Vg_Name_ptr = vg_n;
    Vg_price_ptr = p;

    for (int i = 0; i < 9; i++)
    {
        *Vg_Name_ptr = "0";
        *Vg_price_ptr = 0;
        Vg_Name_ptr++;
        Vg_price_ptr++;
    }
    ofstream x;
    x.open("cart_Pointers.txt", ios::trunc);
    x.close();
    totalPrice_Pointers = 0;
    cout << "\nYour Cart is empty now.";
}

// Search for items in the cart
void searchRecord_withPointers()
{
    Vg_Name_ptr = vg_n;
    Vg_price_ptr = p;
    string name;
    double price;
    bool none = true;

    // Prompt user to enter item name
    cout << "\nEnter the item name : ";
    cin >> name;

    bool found = false;
    // Open cart file and search for the item

    for (int i = 0; i < k; i++)
    {

        if (name == *Vg_Name_ptr)
        {
            found = true;
        }
        Vg_Name_ptr++;
    }
    // Display whether the item is present in the cart or not
    if (found)
    {
        cout << "\nThe item is present in your cart.";
    }
    else
    {
        cout << "\nThe item is not present in your cart.";
    }

    cout << endl;
    Vg_Name_ptr = vg_n;
    Vg_price_ptr = p;
    // Display the contents of the cart
    cout << "\nThis is your cart:" << endl;
    cout << left << setw(12) << "Vegetable" << setw(12) << "Price" << endl;

    for (int i = 0; i < k; i++)
    {
        if (*Vg_Name_ptr != "0")
        {
            cout << left << setw(12) << *Vg_Name_ptr << setw(12) << *Vg_price_ptr << endl;
            none = false;
        }
        Vg_Name_ptr++;
        Vg_price_ptr++;
    }
    if (none)
    {
        cout << "\nYour Cart is empty.";
    }
    {
        cout << "\nTotal Price: " << totalPrice_Pointers;
    }
}

// Edit the cart
void editRecord_withPointers()
{
    Vg_Name_ptr = vg_n;
    Vg_price_ptr = p;
    string name;
    ofstream x;

    cout << "\nTo remove certain item from your cart.";
    cout << "\nEnter the Exact Name of that vegetable : ";
    cin >> name;
    for (int i = 0; i < k; i++)
    {

        if (name == *Vg_Name_ptr)
        {
            *Vg_Name_ptr = "0";
            totalPrice_Pointers -= *Vg_price_ptr;
            *Vg_price_ptr = 0;
            break;
        }
        Vg_Name_ptr++;
        Vg_price_ptr++;
    }
    x.open("cart_Pointers.txt", ios ::trunc);
    x.close();
    x.open("cart_Pointers.txt", ios ::app);
    Vg_Name_ptr = vg_n;
    Vg_price_ptr = p;
    for (int j = 0; j < k; j++)
    {
        if (*Vg_Name_ptr != "0")
        {
            x << *Vg_Name_ptr << " " << *Vg_price_ptr << endl;
        }
        Vg_Name_ptr++;
        Vg_price_ptr++;
    }
    x.close();
    cout << "The vegetable is removed from your cart.";
}

// Simple Varaible Function

void viewRecord_withVariable()
{
    string Vg_Name, Vg_Genre, Vg_Age;
    int Vg_price;
    ifstream x;
    x.open("menu_Simple.txt");
    cout << left << setw(12) << "Name" << setw(12) << "Price/kg" << setw(12) << "Shelf Life" << endl;
    while (x >> Vg_Name >> Vg_price >> Vg_Age)
    {

        cout << left << setw(12) << Vg_Name << setw(12) << Vg_price << setw(12) << Vg_Age << endl;
    }
    x.close();
}

void addRecord_withVariable()
{
    ifstream y;
    ofstream z;
    string Vg_Name, name;
    int Vg_price;
    double amount;
    cout << "To Select items from the menu , write the exact name of the vegetable: ";
    y.open("veggies2.txt");
    z.open("cart_Simple.txt", ios::app);
    do
    {

        cout << "\nVegetable Name : ";
        cin >> Vg_Name;
        if (Vg_Name == "0")
        {
            break;
        }

        cout << "\nHow much do you want in kgs : ";
        cin >> amount;
        y.clear(); // Clear any error flags
        y.seekg(0, ios::beg);
        while (y >> name >> Vg_price)
        {
            if (name == Vg_Name)
            {
                totalPrice_Variable += Vg_price * amount;
                z << name << " " << Vg_price * amount << endl;
                break;
            }
        }
        cout << "If you are done ordering, Enter 0 in Vegetable Name :";
    } while (Vg_Name != "0");
    y.close();
    z.close();
}

void deleteRecord_withVariable()
{

    ofstream del;
    del.open("cart_Simple.txt", ios::trunc);
    del.close();
    totalPrice_Variable = 0;
    cout << "\nYour Cart is empty now.";
}

void searchRecord_withVariable()
{
    string Vg_name, name;
    double price;
    cout << "\nEnter the item name : ";
    cin >> Vg_name;
    ifstream s, s1;
    bool found = false;
    s.open("cart_Simple.txt");
    while (s >> name)
    {
        if (name == Vg_name)
        {
            found = true;
        }
    }
    if (found)
    {
        cout << "\nThe item is present in your cart.";
    }
    else
    {
        cout << "\nThe item is not present in your cart.";
    }

    s.close();
    cout << endl;
    cout << "\nThis is your cart:" << endl;
    cout << left << setw(12) << "Vegetable" << setw(12) << "Price" << endl;
    s1.open("cart_Simple.txt");
    while (s1 >> name >> price)
    {
        cout << left << setw(12) << name << setw(12) << price << endl;
    }
    cout << "\nTotal Price: " << totalPrice_Variable;
    s1.close();
}

void editRecord_withVariable()
{
    string a, b, c, name, n, nn;

    ifstream x;
    ofstream y;
    y.open("f1.txt");
    x.open("cart_Simple.txt");

    while (getline(x, a))
    {
        y << a << endl;
    }
    x.close();
    y.close();
    cout << "\nTo remove certain item from your cart.";
    cout << "\nEnter the item name and price with space b/w them : ";
    getline(cin, name);
    // phele cart_Simple.txt file ka sara data f1.txt mai aya , uske baad f1.txt file se f2.txt mai aya , mgr sirf wohi data f2.txt mai ayai ga ju user ku nhi chayai huga, uskai baad f2.txt file se data cart_Simple.txt file mai jai ga

    ifstream j;
    ofstream k;
    k.open("f2.txt");
    j.open("f1.txt");
    while (getline(j, n))
    {
        if (n != name)
        {
            k << n << endl;
        }
    }
    k.close();
    j.close();

    ifstream jj;
    ofstream kk;
    kk.open("cart_Simple.txt");
    jj.open("f2.txt");
    while (getline(jj, nn))
    {
        kk << nn << endl;
    }
    kk.close();
    jj.close();

// ye isleye keya hai kuinke , jab cart mai sirf aik item huta hai tu aur usku jab hum edit function se remove krte hai , tu totalPrice_Variable mai junk value a jati hai , is code is junk value nhi ayai gi
    ifstream file;
    file.open("cart_Simple.txt");
    file.seekg(0, ios::end);
    if (file.tellg() == 0)
    {
        totalPrice_Variable = 0;
        file.close();
    }
    else
    {
        file.close();

        // ye code totalPrice_Variable mai changes ke leye hai , taka old totalPrice_Variable se us item ki  amount remove hujai ju user ne remove krai thi.
        string ITEM;
        int newPrice, New;
        ifstream priceKeleye;
        priceKeleye.open("cart_Simple.txt");
        while (priceKeleye >> ITEM >> newPrice)
        {

            New = 0;
            New += newPrice;
        }
        int diff = totalPrice_Variable - New;
        totalPrice_Variable = totalPrice_Variable - diff;
        priceKeleye.close();
    }
        cout << "\nThe item is removed.";
}