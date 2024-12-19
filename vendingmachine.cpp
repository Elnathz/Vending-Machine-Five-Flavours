// judul : Program App Vending Machine Kelompok 6
// 11-11-2024, Kost 
// Ahmad Naufal zakirin, Farros Rifantiarno Ramadhani, Mohamad Ezza Fisabili
#include <iostream>
using namespace std;

// kamus
int menu, pilihan, pilihansisa;
string nota[1000]; // untuk memberi nota kepada user hal apa saja yang dibeli
int x, banyakBeli;

// kumpulan fungsi dan prosedur
    int tambahanSaldo();
    int memilihMenuMakanan();
    int memilihMenuMinuman();
    void transaksiSelesai(); // menampilkan ketika transaksi telah selesai
    void menuFiveFlavours();
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
    /*
    menu yang disajikan oleh Five Flavours
    makanan1= onigiri(10 poin)
    makanan2= sushi(10 poin)
    makanan3= ramen (12 poin)
    makanan4= hotdog(15 poin)
    makanan5= burger(15 poin)

    minuman1 = fanta (5 poin)
    minuman2 = coca-cola (5 poin)
    minuman3 = sprite (5 poin)
    minuman4 = aqua (3 poin)
    minuman5 = teh pucuk (4 poin)
    */

    cout << "===========================================" << endl;
    cout << "       Vending Machine Five Flavours       " << endl;
    cout << "===========================================" << endl;
    cout << "Masukan Uang Anda (Pecahan Kertas 1000, 2000, 5000, dst) : ";
    cin >> user.uang.uangAwal;
    user.poin.poinAwal = user.uang.uangAwal/1000;
    cout << "Jumlah saldo poin anda : " << user.poin.poinAwal << endl << endl;
    menuFiveFlavours();
    while (user.poin.poinAwal >= 0)
    {
        while (user.poin.poinAwal > 2) // ketika poin lebih dari 2 maka akan memasuki looping ini
        {
            while (x<1000)
            {
                cout << "---------------------------------------------------------------------------------------------------" << endl;
                cout << "Pilih menu makanan, minuman, menambahkan saldo poin, atau mengakhiri transaksi (1, 2, 3, atau 0) : ";
                cin >> menu;
                cout << "---------------------------------------------------------------------------------------------------" << endl;
                
                cout << endl;
                if (menu == 1)
                {
                    memilihMenuMakanan();
                    switch (pilihan)
                    {
                        case 1:
                        {
                            if (user.poin.poinAwal == 10 || user.poin.poinAwal >= 10)
                            {
                                user.poin.poinAwal = user.poin.poinAwal - jenisMenu.menuMakanan.poin[pilihan];
                                cout << "Makanan yang anda beli adalah Onigiri sebesar 10 poin" << endl;
                                cout << "Sisa saldo poin anda adalah : " << user.poin.poinAwal << endl;
                                nota[x] = jenisMenu.menuMakanan.nama[0];
                                x++;
                                banyakBeli++;
                                break;
                            }
                            else
                            {
                                cout << "Saldo anda kurang sebesar " << user.poin.poinAwal-jenisMenu.menuMakanan.poin[pilihan] << " poin untuk membeli Onigiri" << endl;
                                break;
                            }
                            break;
                        }
                        case 2:
                        {
                            if (user.poin.poinAwal == 10 || user.poin.poinAwal >= 10)
                            {
                                user.poin.poinAwal = user.poin.poinAwal - jenisMenu.menuMakanan.poin[pilihan];
                                cout << "Makanan yang anda beli adalah Sushi sebesar 10 poin" << endl;
                                cout << "Sisa saldo poin anda adalah : " << user.poin.poinAwal << endl;
                                nota[x] = jenisMenu.menuMakanan.nama[1];
                                x++;
                                banyakBeli++;
                                break;
                            }
                            else
                            {
                                cout << "Saldo anda kurang sebesar " << user.poin.poinAwal - jenisMenu.menuMakanan.poin[pilihan] << " poin untuk membeli Sushi" << endl;
                                break;
                            }
                            break;
                        }
                        case 3:
                        {
                            if (user.poin.poinAwal == 12 || user.poin.poinAwal >= 12)
                            {
                                user.poin.poinAwal = user.poin.poinAwal - jenisMenu.menuMakanan.poin[pilihan];
                                cout << "Makanan yang anda beli adalah Ramen sebesar 12 poin" << endl;
                                cout << "Sisa saldo poin anda adalah : " << user.poin.poinAwal << endl;
                                nota[x] = jenisMenu.menuMakanan.nama[2];
                                x++;
                                banyakBeli++;
                                break;
                            }
                            else
                            {
                                cout << "Saldo anda kurang sebesar " << user.poin.poinAwal - jenisMenu.menuMakanan.poin[pilihan] << " poin untuk membeli Ramen" << endl;
                                break;
                            }
                            break;
                        }
                        case 4:
                        {
                            if (user.poin.poinAwal == 15 || user.poin.poinAwal >= 15)
                            {
                                user.poin.poinAwal = user.poin.poinAwal - jenisMenu.menuMakanan.poin[pilihan];
                                cout << "Makanan yang anda beli adalah Hotdog sebesar 15 poin" << endl;
                                cout << "Sisa saldo poin anda adalah : " << user.poin.poinAwal << endl;
                                nota[x] = jenisMenu.menuMakanan.nama[3];
                                x++;
                                banyakBeli++;
                                break;
                            }
                            else
                            {
                                cout << "Saldo anda kurang sebesar " << user.poin.poinAwal - jenisMenu.menuMakanan.poin[pilihan] << " poin untuk membeli Hotdog" << endl;
                                break;
                            }
                            break;
                        }
                        case 5:
                        {
                            if (user.poin.poinAwal == 15 || user.poin.poinAwal >= 15)
                            {
                                user.poin.poinAwal = user.poin.poinAwal - jenisMenu.menuMakanan.poin[pilihan];
                                cout << "Makanan yang anda beli adalah Burger sebesar 15 poin" << endl;
                                cout << "Sisa saldo poin anda adalah : " << user.poin.poinAwal << endl;
                                nota[x] = jenisMenu.menuMakanan.nama[4];
                                x++;
                                banyakBeli++;
                                break;
                            }
                            else
                            {
                                cout << "Saldo anda kurang sebesar " << user.poin.poinAwal - jenisMenu.menuMakanan.poin[pilihan] << " poin untuk membeli Burger" << endl;
                                break;
                            }
                            break;
                        }
                        default:
                        {
                            cout << "Kembali ke menu utama" << endl;
                            break;
                        }
                        break;
                    }
                    break;
                }
                else if (menu == 2)
                {
                    memilihMenuMinuman();
                    switch (pilihan)
                    {
                        case 1:
                        {
                            if (user.poin.poinAwal == 5 || user.poin.poinAwal >= 5)
                            {
                                user.poin.poinAwal = user.poin.poinAwal - jenisMenu.menuMinuman.poin[pilihan];
                                cout << "Minuman yang anda beli adalah Fanta" << endl;
                                cout << "Sisa saldo poin anda adalah : " << user.poin.poinAwal << endl;
                                nota[x] = jenisMenu.menuMinuman.nama[0];
                                x++;
                                banyakBeli++;
                                break;
                            }
                            else
                            {
                                cout << "Saldo anda kurang sebesar " << user.poin.poinAwal-jenisMenu.menuMinuman.poin[pilihan] << " poin untuk membeli Fanta" << endl;
                                break;
                            }
                        }
                        case 2:
                        {
                            if (user.poin.poinAwal == 5 || user.poin.poinAwal >= 5)
                            {
                                user.poin.poinAwal = user.poin.poinAwal - jenisMenu.menuMinuman.poin[pilihan];
                                cout << "Minuman yang anda beli adalah Coca-Cola" << endl;
                                cout << "Sisa saldo poin anda adalah : " << user.poin.poinAwal << endl;
                                nota[x] = jenisMenu.menuMinuman.nama[1];
                                x = x+1;
                                banyakBeli++;
                                cout << x << endl;
                                break;
                            }
                            else
                            {
                                cout << "Saldo anda kurang sebesar " << user.poin.poinAwal -jenisMenu.menuMinuman.poin[pilihan] << " poin untuk membeli Coca-Cola" << endl;
                                break;
                            }
                        }
                        case 3:
                        {
                            if (user.poin.poinAwal == 5 || user.poin.poinAwal >= 5)
                            {
                                user.poin.poinAwal = user.poin.poinAwal - jenisMenu.menuMinuman.poin[pilihan];
                                cout << "Minuman yang anda beli adalah Sprite" << endl;
                                cout << "Sisa saldo poin anda adalah : " << user.poin.poinAwal << endl;
                                nota[x] = jenisMenu.menuMinuman.nama[2];
                                x++;
                                banyakBeli++;
                                break;
                            }
                            else
                            {
                                cout << "Saldo anda kurang sebesar " << user.poin.poinAwal-jenisMenu.menuMinuman.poin[pilihan] << " poin untuk membeli Sprite" << endl;
                                break;
                            }
                        }
                        case 4:
                        {
                            if (user.poin.poinAwal == 3 || user.poin.poinAwal >= 3)
                            {
                                user.poin.poinAwal = user.poin.poinAwal - jenisMenu.menuMinuman.poin[pilihan];
                                cout << "Minuman yang anda beli adalah Aqua" << endl;
                                cout << "Sisa saldo poin anda adalah : " << user.poin.poinAwal << endl;
                                nota[x] = jenisMenu.menuMinuman.nama[3];
                                x++;
                                banyakBeli++;
                                break;
                            }
                            else
                            {
                                cout << "Saldo anda kurang sebesar " << user.poin.poinAwal-jenisMenu.menuMinuman.poin[pilihan] << " poin untuk membeli Aqua" << endl;
                                break;
                            }
                        }
                        case 5:
                        {
                            if (user.poin.poinAwal == 4 || user.poin.poinAwal >= 4)
                            {
                                user.poin.poinAwal = user.poin.poinAwal - jenisMenu.menuMinuman.poin[pilihan];
                                cout << "Minuman yang anda beli adalah Teh Pucuk" << endl;
                                cout << "Sisa poin anda adalah : " << user.poin.poinAwal << endl;
                                nota[x] = jenisMenu.menuMinuman.nama[4];
                                x++;
                                banyakBeli++;
                                break;
                            }
                            else
                            {
                                cout << "Saldo anda kurang sebesar " << user.poin.poinAwal-jenisMenu.menuMinuman.poin[pilihan] << " poin untuk membeli Teh Pucuk" << endl;
                                break;
                            }
                        }
                        default:
                        {
                            cout << "Kembali ke menu utama" << endl;
                            break;
                        }
                        break;
                    }
                    break;
                }
                else if(menu == 3)
                {
                    tambahanSaldo();
                }
                else if(menu == 0)
                {
                    transaksiSelesai();
                    return 0;
                }
                else // inputan selain 1, 2, 3, dan 0 
                {
                    cout << "Inputan salah/menu tidak tersedia" << endl;
                    break;
                }
            }
            break;
        }
        cout << endl;
        while (user.poin.poinAwal <= 2) // ketika poin kurang dari sama dengan 2 maka akan memasuki looping ini karena minimal membeli makanan/minuman > 2
        {
            cout << "Saldo poin Anda kurang untuk melakukan transaksi" << endl;
            cout << "Apakah Anda ingin menambah saldo atau menyelesaikan transaksi (1: Menambah saldo 2: Mengakhiri) : ";
            cin >> pilihansisa;
            cout << endl;
            if (pilihansisa == 1)
            {
                tambahanSaldo();
            }
            else if(pilihansisa == 2)
            {
                transaksiSelesai();
                return 0;
            }
            else // inputan selain 1 dan 2
            {
                cout << "Inputan salah/menu tidak tersedia" << endl;
            }
            break;
        }
    }
}

void menuFiveFlavours()
    {
        cout << "Menu Makanan dan Minuman Five Flavours" << endl;
        cout << "Onigiri (10 poin) | Fanta     (5 poin)" << endl;
        cout << "Sushi   (10 poin) | Coca-Cola (5 poin)" << endl;
        cout << "Ramen   (12 poin) | Sprite    (5 poin)" << endl;
        cout << "Hotdog  (15 poin) | Aqua      (3 poin)" << endl;
        cout << "Burger  (15 poin) | Teh Pucuk (4 poin)" << endl;
    }

int memilihMenuMakanan()
    {
        cout << "Menu Makanan Five Flavours" << endl;
        cout << "1: Onigiri (10 poin)" << endl;
        cout << "2: Sushi   (10 poin)" << endl;
        cout << "3: Ramen   (12 poin)" << endl;
        cout << "4: Hotdog  (15 poin)" << endl;
        cout << "5: Burger  (15 poin)" << endl;
        cout << "0: Kembali ke menu utama" << endl;
        cout << "Pilih makanan yang mau anda tukarkan : ";
        cin >> pilihan;
        cout << endl;
        return pilihan;
    }

int memilihMenuMinuman()
    {
        cout << "Menu Minuman Five Flavours" << endl;
        cout << "1: Fanta (5 poin)" << endl;
        cout << "2: Coca-Cola (5 poin)" << endl;
        cout << "3: Sprite (5 poin)" << endl;
        cout << "4: Aqua (3 poin)" << endl;
        cout << "5: Teh Pucuk (4 poin)" << endl;
        cout << "0: Kembali ke pilihan menu" << endl;
        cout << "Pilih minuman yang mau anda tukarkan : ";
        cin >> pilihan;
        cout << endl;
        return pilihan;
}

int tambahanSaldo()
{
    cout << "Masukan Uang Anda(Pecahan Kertas 1000, 2000, 5000, dst) : ";
    cin >> user.uang.uangTambahan;
    user.poin.poinTambahan = user.uang.uangTambahan/1000;
    user.poin.poinAwal = user.poin.poinAwal + user.poin.poinTambahan;
    cout << "Saldo poin Anda kini menjadi : " << user.poin.poinAwal << endl;
    return user.poin.poinAwal;
}

void transaksiSelesai()
{
    x = 0;
    user.uang.kembalian = user.poin.poinAwal * 1000;
    if(banyakBeli>0)
    {
        cout << "Makanan atau minuman yang anda beli adalah  : " << endl;
        do 
        {
            cout << x+1 << ". " << nota[x] << endl;
            x++;
        } while (x < banyakBeli);
    }
    cout << endl;
    cout << "Terima kasih telah berbelanja di Vending Machine Five Flavours" << endl;
    cout << "Uang anda kembali sebesar : " << user.uang.kembalian << endl;
}
