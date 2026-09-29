#include <iostream>
#include <memory>
#include <vector>
#include <string>

using namespace std;

class Payment
{
protected:
    string id;
    float price;

public:
    Payment(string i, float p)
    {
        id = i;
        price = p;
    }

    virtual void makePayment() const = 0;

    virtual ~Payment()
    {
    }
};

// Card Payment
class Card : public Payment
{
private:
    string cardNo;

public:
    Card(string i, float p, string c)
        : Payment(i, p), cardNo(c)
    {
    }

    void makePayment() const override
    {
        cout << "Payment through Credit Card" << endl;
        cout << "Transaction ID: " << id << endl;
        cout << "Amount: Rs. " << price << endl;
        cout << "Card Number: " << cardNo << endl;
        cout << "Status: Successful" << endl;
        cout << endl;
    }
};

// UPI Payment
class UPI : public Payment
{
private:
    string userId;

public:
    UPI(string i, float p, string u)
        : Payment(i, p), userId(u)
    {
    }

    void makePayment() const override
    {
        cout << "Payment through UPI" << endl;
        cout << "Transaction ID: " << id << endl;
        cout << "Amount: Rs. " << price << endl;
        cout << "UPI ID: " << userId << endl;
        cout << "Status: Successful" << endl;
        cout << endl;
    }
};

// Net Banking Payment
class NetBanking : public Payment
{
private:
    string bank;

public:
    NetBanking(string i, float p, string b)
        : Payment(i, p), bank(b)
    {
    }

    void makePayment() const override
    {
        cout << "Payment through Net Banking" << endl;
        cout << "Transaction ID: " << id << endl;
        cout << "Amount: Rs. " << price << endl;
        cout << "Bank Name: " << bank << endl;
        cout << "Status: Successful" << endl;
        cout << endl;
    }
};

int main()
{
    vector<unique_ptr<Payment>> paymentList;

    paymentList.push_back(
        make_unique<NetBanking>("N401", 32000, "HDFC Bank")
    );

    paymentList.push_back(
        make_unique<Card>("C402", 1750, "XXXX-3652")
    );

    paymentList.push_back(
        make_unique<UPI>("U403", 6400, "arpita@upi")
    );

    cout << "===== PAYMENT SYSTEM =====" << endl;
    cout << endl;

    for (const auto& p : paymentList)
    {
        p->makePayment();
    }

    return 0;
}