# Elevator Parking Service Management System (C++)

A console-based C++ program that manages vehicle parking and optional vehicle services for up to 20 customers.

## Features
- Menu-driven interface: park a vehicle, display all customers, or exit
- Supports cars and motorcycles, each with its own service packages and vehicle-type fees
- Tiered pricing: service package + vehicle type fee + weekend surcharge (RM5) + 8% SST
- Itemized receipt for every customer
- Summary report: total customers, remaining parking slots and total revenue
- Input validation for package, vehicle type and weekend choices

## Pricing

| Vehicle | Cleaning | Maintenance | Combo | No Service |
|---|---|---|---|---|
| Car | RM70 | RM200 | RM230 | RM0 |
| Motorcycle | RM10 | RM25 | RM40 | RM0 |

Vehicle type fee: Car RM5 / RM7 / RM10 (small / medium / EV). Motorcycle RM1 / RM2 / RM3 / RM4.50 (by engine size).

SST (8%) is calculated on the package and vehicle fee. The weekend surcharge is added separately.

## Concepts Used
Functions, arrays, switch and if-else control structures, loops, formatted output (iomanip).

## How to Run
1. Compile: `g++ elevator_parking_system.cpp -o parking`
2. Run: `./parking` (on Windows: `parking.exe`)

## Author
Zulfahmie Bin Abd Hamid, Diploma in Mechanical Engineering, UiTM Permatang Pauh
