#include <iostream>
#include <iomanip>
#include <cctype>
using namespace std;

const int maxslot = 20;

double Vehicle_Package(char package, char vcode, int code); // Fungsi kira jumlah servis
double Weekend_Package(char weekend); // Fungsi kira weekend caj
void displayreceipt(string customer, string carplate, char vcode, char package, int code, double total,double total_sst,double weekend_price); // Cetak resit
void report(int total_customer, double total_revenue, int remainingparking); // Laporan ringkasan

int main()
{
    string namecustomer[maxslot], carplate[maxslot];
    char cartype[maxslot];
    double customertotal[maxslot];


    string customer, plate;
    char package, weekend, vcode, loop;
    double total, packageprice, weekend_price, total_revenue = 0, total_sst ;
    int code, choicemenu;
    int tcustomer = 0, remainingparking = maxslot;

    cout.setf(ios::fixed);
    cout.precision(2);

    do
    {
        if (remainingparking <= 0)
        {
            cout << "\nAll Parking Slots are full." << endl;
            break;
        }

        cout << "\nWelcome To Elevator Parking Service" << endl;
        cout << "------------------------------------" << endl;
        cout << "1 - Park Vehicle" << endl;
        cout << "2 - Display All Customer Info" << endl;
        cout << "3 - Exit" << endl;

        cout << "\nEnter Menu: ";
        cin >> choicemenu;

        if (choicemenu == 1)
        {
            cout << "\nPlease Enter Your Name: ";
            cin >> ws;
            getline(cin, customer);

            cout << "Enter Vehicle Plate: ";
            cin >> ws;
            getline(cin, plate);

            cout << "\nVehicle Type:\n c - Car\n m - Motorcycle" << endl;
            cout << "Enter Your Vehicle Type: ";
            cin >> vcode;

            if (vcode == 'c' || vcode == 'C')
            {
                cout << "\nAvailable Package:" << endl;
                cout << "A - Cleaning Service      RM 70.00" << endl;
                cout << "B - Maintenance Service   RM 200.00" << endl;
                cout << "C - Combo Service         RM 230.00" << endl;
                cout << "D - No Service            RM 0.00" << endl;

                cout << "Enter Package (A/B/C/D): ";
                cin >> package;
                package = tolower(package);
                if (package < 'a' || package > 'd') { cout << "Invalid package!\n"; continue; }

                cout << "\nCar Type:\n1 - Small Size (RM5)\n2 - Medium (RM7)\n3 - EV (RM10)" << endl;
                cout << "Enter Car Type (1/2/3): ";
                cin >> code;
                if (code < 1 || code > 3) { cout << "Invalid car type!\n"; continue; }
            }
            else if (vcode == 'm' || vcode == 'M')
            {
                cout << "\nAvailable Package:" << endl;
                cout << "A - Cleaning Service      RM 10.00" << endl;
                cout << "B - Maintenance Service   RM 25.00" << endl;
                cout << "C - Combo Service         RM 40.00" << endl;
                cout << "D - No Service            RM 0.00" << endl;

                cout << "Enter Package (A/B/C/D): ";
                cin >> package;
                package = tolower(package);
                if (package < 'a' || package > 'd') { cout << "Invalid package!\n"; continue; }

                cout << "\nMotorcycle Type:\n1 - 100-250cc (RM1)\n2 - 251-500cc (RM2)\n3 - 501-750cc (RM3)\n4 - 751-1000cc (RM4.5)" << endl;
                cout << "Enter Motorcycle Type (1/2/3/4): ";
                cin >> code;
                if (code < 1 || code > 4) { cout << "Invalid motorcycle type!\n"; continue; }
            }
            else
            {
                cout << "Invalid vehicle type!\n";
                continue;
            }

            cout << "Weekend? (y/n): ";
            cin >> weekend;
            if (tolower(weekend) != 'y' && tolower(weekend) != 'n') { cout << "Invalid weekend input!\n"; continue; }
            
			// ni formula     
            packageprice = Vehicle_Package(package, vcode, code);
            weekend_price = Weekend_Package(weekend);
            total_sst = packageprice * 0.08 ;
            total = packageprice + total_sst + weekend_price;
            total_revenue += total;

            // Simpan dalam array
            namecustomer[tcustomer] = customer;
            carplate[tcustomer] = plate;
            cartype[tcustomer] = vcode;
            customertotal[tcustomer] = total;


            displayreceipt(customer, plate, vcode, package, code, total,total_sst,weekend_price);

            tcustomer++;
            remainingparking--;

            cout << "\nNext Customer? (y/n): ";
            cin >> loop;
        }
        else if (choicemenu == 2)
        {
            cout << "\n------ List of Customers ------" << endl;
            cout << "No." << setw(20) << "Name" << setw(20) << "Plate" << setw(20) << "Vehicle Type" << endl;
            for (int i = 0; i < tcustomer; i++)
            {
                string type = (tolower(cartype[i]) == 'c') ? "Car" : "Motorcycle";
                cout << i + 1 << "." << setw(20) << namecustomer[i] << setw(20) << carplate[i] << setw(20) << type << setw(10) << customertotal[i] << endl;
            }
        }
        else if (choicemenu == 3)
        {
            break;
        }
        else
        {
            cout << "Invalid menu choice!\n";
        }

    } while (tolower(loop) == 'y');

    report(tcustomer, total_revenue, remainingparking);
    return 0;
}

// Fungsi jumlah harga pakej + jenis kenderaan
double Vehicle_Package(char package, char vcode, int code)
{
    double packageprice = 0, vehicleprice = 0;
    package = tolower(package);
    vcode = tolower(vcode);

    if (vcode == 'm') // Motorcycle
    {
        switch (package)
        {
            case 'a': packageprice = 10.00; break;
            case 'b': packageprice = 25.00; break;
            case 'c': packageprice = 40.00; break;
            case 'd': packageprice = 0.00; break;
        }
        switch (code)
        {
            case 1: vehicleprice = 1.00; break;
            case 2: vehicleprice = 2.00; break;
            case 3: vehicleprice = 3.00; break;
            case 4: vehicleprice = 4.50; break;
        }
    }
    else if (vcode == 'c') // Car
    {
        switch (package)
        {
            case 'a': packageprice = 70.00; break;
            case 'b': packageprice = 200.00; break;
            case 'c': packageprice = 230.00; break;
            case 'd': packageprice = 0.00; break;
        }
        switch (code)
        {
            case 1: vehicleprice = 5.00; break;
            case 2: vehicleprice = 7.00; break;
            case 3: vehicleprice = 10.00; break;
        }
    }
    return packageprice + vehicleprice;
}

// Fungsi weekend
double Weekend_Package(char weekend)
{
    return (tolower(weekend) == 'y') ? 5.00 : 0.00;
}

// Fungsi papar resit
void displayreceipt(string name, string plate, char vcode, char package, int code, double total, double total_sst, double weekend_price)
{
    string vehicle = (tolower(vcode) == 'c') ? "Car" : "Motorcycle";
    string packname;
    double packprice = 0;
    double vehicleprice = 0;
    
    if (vehicle == "Car")
{
    if (package == 'a') { packname = "Cleaning"; packprice = 70.00; }
    else if (package == 'b') { packname = "Maintenance"; packprice = 200.00; }
    else if (package == 'c') { packname = "Combo"; packprice = 230.00; }
    else { packname = "No Service"; }

    switch (code)
    {
        case 1: vehicleprice = 5.00; break;
        case 2: vehicleprice = 7.00; break;
        case 3: vehicleprice = 10.00; break;
    }
}
else
{
    if (package == 'a') { packname = "Cleaning"; packprice = 10.00; }
    else if (package == 'b') { packname = "Maintenance"; packprice = 25.00; }
    else if (package == 'c') { packname = "Combo"; packprice = 40.00; }
    else { packname = "No Service"; }

    switch (code)
    {
        case 1: vehicleprice = 1.00; break;
        case 2: vehicleprice = 2.00; break;
        case 3: vehicleprice = 3.00; break;
        case 4: vehicleprice = 4.50; break;
    }
}

    
    if (vehicle == "Car")
    {
        if (package == 'a') { packname = "Cleaning"; packprice = 70.00; }
        else if (package == 'b') { packname = "Maintenance"; packprice = 200.00; }
        else if (package == 'c') { packname = "Combo"; packprice = 230.00; }
        else { packname = "No Service"; }
    }
    else
    {
        if (package == 'a') { packname = "Cleaning"; packprice = 10.00; }
        else if (package == 'b') { packname = "Maintenance"; packprice = 25.00; }
        else if (package == 'c') { packname = "Combo"; packprice = 40.00; }
        else { packname = "No Service"; }
    }

    cout << "\n------------- RECEIPT -------------" << endl;
    cout << "Customer Name   : " << name << endl;
    cout << "Vehicle Plate   : " << plate << endl;
    cout << "Vehicle Type    : " << vehicle << " (RM" << vehicleprice << ")" << endl;
    cout << "Package Chosen  : " << packname << " (RM" << packprice << ")" << endl;
    cout << "Weekend Charge  : RM" << weekend_price << endl;
    cout << "Total SST (8%)  : RM" << total_sst << endl;
    cout << "Total Price     : RM" << total << endl;
    cout << "-----------------------------------\n";
}

// Fungsi report
void report(int total_customer, double total_revenue, int remainingparking)
{
    cout << "\n========== SUMMARY REPORT ==========" << endl;
    cout << "Total Customers     : " << total_customer << endl;
    cout << "Remaining Parking   : " << remainingparking << endl;
    cout << "Total Revenue       : RM" << total_revenue << endl;
    cout << "====================================" << endl;
}
