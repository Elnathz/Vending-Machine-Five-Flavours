// judul : Program App Vending Machine Kelompok 6
// 11-11-2024, Kost
// Ahmad Naufal Zakirin, Farros Rifantiarno Ramadhani, Mohamad Ezza Fisabili
#include <iostream>
#include <string>
#include <limits> // Library untuk numeric_limits pada header
using namespace std;

// kamus
int menu, pilihan, pilihansisa;
string nota[100]; // untuk memberi nota kepada user hal apa saja yang dibeli dan diberi batasan 100 karna dianggap stok hanya ada 100
int x, banyakBeli;

// kumpulan fungsi dan prosedur
int merubahKePoin(int uang);
int penguranganPembelianPoin(int poin, int harga);
int menambahPoin(int uangTambahan, int poinAwal);
int mengembalikanKeUang(int poinAwal);

void menuFiveFlavours();
void header();
void sistemPembelianMakanan(int pilihan, int &x);
void saldoKurangMakanan(int pilihan);
void pembelianMakanan(int pilihan);
void sistemPembelianMinuman(int pilihan, int &x);
void pembelianMinuman(int pilihan);
void memilihMenuMakanan();
void memilihMenuMinuman();
void tambahanSaldo();
void transaksiSelesai();
void transaksiSelesai();
void menuUtama();
void menuSaldoPoinKurang();

struct makanan
{
    string nama[5] = {"Onigiri", "Sushi", "Ramen", "Hotdog", "Burger"};
    int poin[5] = {10, 10, 12, 15, 15};
};

struct minuman
{
    string nama[5] = {"Fanta", "Coca-Cola", "Sprite", "Aqua", "Teh Pucuk"};
    int poin[5] = {5, 5, 5, 3, 4};
};

struct komponenUang
{
    int uangAwal;
    int uangTambahan;
    int kembalian;
};

struct komponenPoin
{
    int poinAwal;
    int poinTambahan;
};

struct komponenMenu
{
    makanan menuMakanan;
    minuman menuMinuman;
};

struct komponenUser
{
    komponenUang uang;
    komponenPoin poin;
};

komponenMenu jenisMenu;
komponenUser user;

// deskripsi
int main()
{
    x = 0;
    banyakBeli = 0;
    header(); // menampilkan menu dan memasukkan uang kemudian dirubah ke poin
    while (user.poin.poinAwal >= 0)
    {
        while (user.poin.poinAwal > 2) // ketika poin lebih dari 2 maka akan memasuki looping ini
        {
            menuUtama(); // prosedur menu utama
            break;
        }
        while (user.poin.poinAwal >= 0 & user.poin.poinAwal < jenisMenu.menuMinuman.poin[3]) // ketika poin kurang dari sama dengan harga aqua maka akan memasuki sini. karna harga aqua adalah harga terendah.
        {
            menuSaldoPoinKurang(); // memilih antara menambah saldo atau mengakhiri transaksi
            break;
        }
    }
}

// kumpulan fungsi dan prosedur

// fungsi
int merubahKePoin(int uang)
{
    int poin = uang / 1000;
    return poin;
}

int penguranganPembelianPoin(int poin, int harga)
{
    poin = poin - harga;
    return poin;
}

int menambahPoin(int uangTambahan, int poinAwal)
{
    int poinTambahan = uangTambahan / 1000;
    poinAwal += poinTambahan;
    return poinAwal;
}

int mengembalikanKeUang(int poinAwal)
{
    poinAwal *= 1000; // mengubah ke rupiah
    int sisaUang = poinAwal;
    return sisaUang;
}

// prosedur
void menuFiveFlavours()
{
    cout << "__________________________________________" << endl;
    cout << "| Menu Makanan dan Minuman Five Flavours |" << endl;
    cout << "| Onigiri (10 poin) | Fanta     (5 poin) |" << endl;
    cout << "| Sushi   (10 poin) | Coca-Cola (5 poin) |" << endl;
    cout << "| Ramen   (12 poin) | Sprite    (5 poin) |" << endl;
    cout << "| Hotdog  (15 poin) | Aqua      (3 poin) |" << endl;
    cout << "| Burger  (15 poin) | Teh Pucuk (4 poin) |" << endl;
    cout << "------------------------------------------" << endl << endl;
}

void header()
{
    cout << "===========================================" << endl;
    cout << "       Vending Machine Five Flavours       " << endl;
    cout << "===========================================" << endl;
    menuFiveFlavours();
    while (user.poin.poinAwal <= 0)
    {
        cout << "Masukan Uang Anda (Pecahan Kertas 1000, 2000, 5000, dst) : ";
        cin >> user.uang.uangAwal;

        // Cek apakah input adalah angka dan positif
        if (cin.fail() || user.uang.uangAwal <= 0) // jika inputan uang tidak sesuai dengan tipe data
        {
            cin.clear(); // Membersihkan pesan error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // menghapus inputan yang salah sampai end line
            cout << "Input tidak valid. Harap masukkan angka dan positif." << endl << endl;
        }
        // Cek apakah uang adalah kelipatan 1000
        else if (user.uang.uangAwal % 1000 != 0) // jika uang tidak kelipatan 1000
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // menghapus inputan yang salah sampai end line
            cout << "Input tidak valid. Harap masukkan pecahan 1000, 2000, 5000, dst." << endl << endl;
        }
        else // jika inputan berhasil
        {
            user.poin.poinAwal = merubahKePoin(user.uang.uangAwal);
            break;
        }
    }
    cout << "Jumlah saldo poin anda : " << user.poin.poinAwal << endl << endl;
}

void sistemPembelianMakanan(int pilihan, int &x)
{
    // Kurangi poin sesuai harga makanan
    user.poin.poinAwal -= jenisMenu.menuMakanan.poin[pilihan - 1];

    // Tampilkan pesan pembelian
    cout << "Makanan yang anda beli adalah " << jenisMenu.menuMakanan.nama[pilihan - 1] << " sebesar " << jenisMenu.menuMakanan.poin[pilihan - 1] << " poin" << endl;
    cout << "Sisa saldo poin anda adalah : " << user.poin.poinAwal << endl;

    // Simpan nama makanan ke dalam nota
    nota[x] = jenisMenu.menuMakanan.nama[pilihan - 1];
    x++;          // Increment index nota
    banyakBeli++; // Tambah jumlah pembelian
    cout << endl;
}

void saldoKurangMakanan(int pilihan)
{
    cout << "Saldo anda kurang sebesar " << jenisMenu.menuMakanan.poin[pilihan - 1] - user.poin.poinAwal << " poin untuk membeli " << jenisMenu.menuMakanan.nama[pilihan - 1] << endl;
}

void pembelianMakanan(int pilihan)
{
    if (pilihan > 0 && user.poin.poinAwal >= jenisMenu.menuMakanan.poin[pilihan - 1])
    {
        sistemPembelianMakanan(pilihan, x);
    }
    else if (pilihan > 0 && user.poin.poinAwal < jenisMenu.menuMakanan.poin[pilihan - 1])
    {
        saldoKurangMakanan(pilihan);
    }
    else
    {
        cout << "Kembali ke menu utama" << endl;
    }
}

void sistemPembelianMinuman(int pilihan, int &x)
{
    // Kurangi poin sesuai harga makanan
    user.poin.poinAwal -= jenisMenu.menuMinuman.poin[pilihan - 1];

    // Tampilkan pesan pembelian
    cout << "Minuman yang anda beli adalah " << jenisMenu.menuMinuman.nama[pilihan - 1] << " sebesar " << jenisMenu.menuMinuman.poin[pilihan - 1] << " poin" << endl;
    cout << "Sisa saldo poin anda adalah : " << user.poin.poinAwal << endl;

    // Simpan nama makanan ke dalam nota
    nota[x] = jenisMenu.menuMinuman.nama[pilihan - 1];
    x++;          // Increment index nota
    banyakBeli++; // Tambah jumlah pembelian
    cout << endl;
}

void saldoKurangMinuman(int pilihan)
{
    cout << "Saldo anda kurang sebesar " << jenisMenu.menuMinuman.poin[pilihan - 1] - user.poin.poinAwal << " poin untuk membeli " << jenisMenu.menuMinuman.nama[pilihan - 1] << endl;
}

void pembelianMinuman(int pilihan)
{
    if (pilihan > 0 && user.poin.poinAwal >= jenisMenu.menuMinuman.poin[pilihan - 1])
    {
        sistemPembelianMinuman(pilihan, x);
    }
    else if (pilihan > 0 && user.poin.poinAwal < jenisMenu.menuMinuman.poin[pilihan - 1])
    {
        saldoKurangMinuman(pilihan);
    }
    else
    {
        cout << "Kembali ke menu utama" << endl << endl;
    }
}

void memilihMenuMakanan()
{
    cout << "Menu Makanan Five Flavours" << endl;
    cout << "1: Onigiri (10 poin)" << endl;
    cout << "2: Sushi   (10 poin)" << endl;
    cout << "3: Ramen   (12 poin)" << endl;
    cout << "4: Hotdog  (15 poin)" << endl;
    cout << "5: Burger  (15 poin)" << endl;
    cout << "0: Kembali ke menu utama" << endl << endl;
    cout << "Pilih makanan yang mau anda tukarkan : ";
    cin >> pilihan;
    cout << endl;
    pembelianMakanan(pilihan);
}

void memilihMenuMinuman()
{
    cout << "Menu Minuman Five Flavours" << endl;
    cout << "1: Fanta     (5 poin)" << endl;
    cout << "2: Coca-Cola (5 poin)" << endl;
    cout << "3: Sprite    (5 poin)" << endl;
    cout << "4: Aqua      (3 poin)" << endl;
    cout << "5: Teh Pucuk (4 poin)" << endl;
    cout << "0: Kembali ke pilihan menu" << endl;
    cout << "Pilih minuman yang mau anda tukarkan : ";
    cin >> pilihan;
    cout << endl;
    pembelianMinuman(pilihan);
}

void tambahanSaldo()
{
    while (user.poin.poinTambahan <= 0)
    {
        cout << "Masukan Uang Anda(Pecahan Kertas 1000, 2000, 5000, dst) : ";
        cin >> user.uang.uangTambahan;
        // Cek apakah input adalah angka dan positif
        if (cin.fail() || user.uang.uangTambahan <= 0) // jika inputan uang tidak sesuai dengan tipe data
        {
            cin.clear(); // Membersihkan pesan error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // menghapus inputan yang salah sampai end line
            cout << "Input tidak valid. Harap masukkan angka dan positif." << endl << endl;
        }
        // Cek apakah uang adalah kelipatan 1000
        else if (user.uang.uangTambahan % 1000 != 0) // jika uang tidak kelipatan 1000
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // menghapus inputan yang salah sampai end line
            cout << "Input tidak valid. Harap masukkan pecahan 1000, 2000, 5000, dst." << endl << endl;
        }
        else // jika inputan berhasil
        {
            user.poin.poinTambahan = merubahKePoin(user.uang.uangTambahan);
            break;
        }
    }
    user.poin.poinAwal = menambahPoin(user.uang.uangTambahan, user.poin.poinAwal);
    cout << "Saldo poin Anda kini menjadi : " << user.poin.poinAwal << endl << endl;
}

void transaksiSelesai()
{
    x = 0;
    user.uang.kembalian = mengembalikanKeUang (user.poin.poinAwal);
    user.poin.poinAwal = -9999;
    if (banyakBeli > 0)
    {
        cout << "Makanan atau minuman yang anda beli adalah  : " << endl;
        do
        {
            cout << x + 1 << ". " << nota[x] << endl;
            x++;
        } while (x < banyakBeli);
        cout << endl;
    }
    cout << "Terima kasih telah berbelanja di Vending Machine Five Flavours" << endl;
    cout << "Uang anda kembali sebesar : Rp" << user.uang.kembalian << endl << endl;
}

void menuUtama()
{
    cout << "---------------------------------------------------------------------------------------------------" << endl;
    cout << "Pilih menu makanan, minuman, menambahkan saldo poin, atau mengakhiri transaksi (1, 2, 3, atau 0) : ";
    cin >> menu;
    cout << "---------------------------------------------------------------------------------------------------" << endl << endl;
    if (menu == 1)
    {
        memilihMenuMakanan();
    }
    else if (menu == 2)
    {
        memilihMenuMinuman();
    }
    else if (menu == 3)
    {
        tambahanSaldo();
    }
    else if (menu == 0)
    {
        transaksiSelesai();
    }
    else // inputan selain 1, 2, 3, dan 0
    {
        cout << "Inputan salah/menu tidak tersedia" << endl << endl;
    }
}

void menuSaldoPoinKurang()
{
    cout << "Saldo poin Anda kurang untuk melakukan transaksi" << endl;
    cout << "Apakah Anda ingin menambah saldo atau menyelesaikan transaksi (1: Menambah saldo 2: Mengakhiri) : ";
    cin >> pilihansisa;
    cout << endl;
    if (pilihansisa == 1)
    {
        tambahanSaldo();
    }
    else if (pilihansisa == 2)
    {
        transaksiSelesai();
    }
    else // inputan selain 1 dan 2
    {
        cout << "Inputan salah/menu tidak tersedia" << endl << endl;
    }
}