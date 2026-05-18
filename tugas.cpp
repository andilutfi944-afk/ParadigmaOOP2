#include <iostream>
#include <string>
using namespace std;

class RekeningBank {
protected:
    string namaNasabah;
    double saldo;

public:
    RekeningBank(string nama, double saldoAwal) {
        namaNasabah = nama;
        saldo = saldoAwal;
    }

    virtual void potongAdmin() = 0;

    void tampilkanSaldo() {
        cout << "Nasabah : " << namaNasabah << endl;
        cout << "Saldo   : Rp " << saldo << endl;
    }

    virtual ~RekeningBank() {}
};
class RekeningSyariah : public RekeningBank {
public:
    RekeningSyariah(string nama, double saldoAwal)
        : RekeningBank(nama, saldoAwal) {}

    void potongAdmin() override {
        cout << "Rekening Syariah bebas biaya admin." << endl;
    }
};
class RekeningKonvensional : public RekeningBank {
public:
    RekeningKonvensional(string nama, double saldoAwal)
        : RekeningBank(nama, saldoAwal) {}

    void potongAdmin() override {
        saldo -= 15000;
        cout << "Biaya admin Rp 15.000 telah dipotong." << endl;
    }
};
class RekeningPremium : public RekeningBank {
public:
    RekeningPremium(string nama, double saldoAwal)
        : RekeningBank(nama, saldoAwal) {}

    void potongAdmin() override {
        if (saldo > 10000000) {
            cout << "Saldo di atas Rp 10.000.000, bebas biaya admin." << endl;
        } else {
            saldo -= 50000;
            cout << "Biaya admin Rp 50.000 telah dipotong." << endl;
        }
    }
};

int main() {

    RekeningBank* rekening1 = new RekeningSyariah("Andi", 5000000);
    RekeningBank* rekening2 = new RekeningKonvensional("Budi", 3000000);
    RekeningBank* rekening3 = new RekeningPremium("Cahyo", 8000000);
    RekeningBank* rekening4 = new RekeningPremium("Dina", 15000000);

    cout << "=== Rekening Syariah ===" << endl;
    rekening1->potongAdmin();
    rekening1->tampilkanSaldo();

    cout << endl;

    cout << "=== Rekening Konvensional ===" << endl;
    rekening2->potongAdmin();
    rekening2->tampilkanSaldo();

    cout << endl;

    cout << "=== Rekening Premium 1 ===" << endl;
    rekening3->potongAdmin();
    rekening3->tampilkanSaldo();

    cout << endl;

    cout << "=== Rekening Premium 2 ===" << endl;
    rekening4->potongAdmin();
    rekening4->tampilkanSaldo();

    delete rekening1;
    delete rekening2;
    delete rekening3;
    delete rekening4;

    return 0;
}