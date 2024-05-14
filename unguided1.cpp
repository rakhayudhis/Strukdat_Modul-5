#include <iostream>
#include <list>
#include <vector>

using namespace std;

// Struktur data untuk mahasiswa
struct Mahasiswa {
    long long NIM; // Menggunakan long long untuk NIM
    int nilai;
};

// Class untuk hash table
class HashTable {
private:
    static const int hashGroup = 10; // Jumlah grup hash
    vector<list<Mahasiswa>> table; // Array dari linked list untuk menyimpan data

public:
    HashTable() : table(hashGroup) {}

    // Fungsi hashing sederhana
    int hashFunction(long long NIM) {
        return NIM % hashGroup;
    }

    // Menambahkan data mahasiswa ke hash table
    void tambahData(long long NIM, int nilai) {
        Mahasiswa mhs;
        mhs.NIM = NIM;
        mhs.nilai = nilai;
        int hashKey = hashFunction(NIM);
        table[hashKey].push_back(mhs);
    }

    // Menghapus data mahasiswa dari hash table berdasarkan NIM
    void hapusData(long long NIM) {
        int hashKey = hashFunction(NIM);
        for (auto it = table[hashKey].begin(); it != table[hashKey].end(); ++it) {
            if ((*it).NIM == NIM) {
                table[hashKey].erase(it);
                break;
            }
        }
    }

    // Mencari data mahasiswa berdasarkan NIM
    void cariByNIM(long long NIM) {
        int hashKey = hashFunction(NIM);
        for (auto mhs : table[hashKey]) {
            if (mhs.NIM == NIM) {
                cout << "NIM: " << mhs.NIM << ", Nilai: " << mhs.nilai << endl;
                return;
            }
        }
        cout << "Data mahasiswa dengan NIM " << NIM << " tidak ditemukan." << endl;
    }

    // Mencari data mahasiswa berdasarkan rentang nilai (80 - 90)
    void cariByRange() {
        for (const auto& group : table) {
            for (const auto& mhs : group) {
                if (mhs.nilai >= 80 && mhs.nilai <= 90) {
                    cout << "NIM: " << mhs.NIM << ", Nilai: " << mhs.nilai << endl;
                }
            }
        }
    }
};

int main() {
    HashTable hashTable;

    // Menu
    cout << "Menu:" << endl;
    cout << "1. Tambah data mahasiswa" << endl;
    cout << "2. Hapus data mahasiswa" << endl;
    cout << "3. Cari data mahasiswa berdasarkan NIM" << endl;
    cout << "4. Cari data mahasiswa berdasarkan rentang nilai (80-90)" << endl;
    cout << "5. Keluar" << endl;

    int choice;
    do {
        cout << "Pilih menu: ";
        cin >> choice;
        switch (choice) {
            case 1:
                long long NIM; // Menggunakan long long untuk NIM
                int nilai;
                cout << "Masukkan NIM mahasiswa: ";
                cin >> NIM;
                cout << "Masukkan nilai mahasiswa: ";
                cin >> nilai;
                hashTable.tambahData(NIM, nilai);
                break;
            case 2:
                cout << "Masukkan NIM mahasiswa yang ingin dihapus: ";
                cin >> NIM;
                hashTable.hapusData(NIM);
                break;
            case 3:
                cout << "Masukkan NIM mahasiswa yang ingin dicari: ";
                cin >> NIM;
                hashTable.cariByNIM(NIM);
                break;
            case 4:
                cout << "Mahasiswa dengan nilai antara 80 dan 90:" << endl;
                hashTable.cariByRange();
                break;
            case 5:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan pilih lagi." << endl;
        }
    } while (choice != 5);

    return 0;
}