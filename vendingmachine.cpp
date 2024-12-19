// judul : Program App Vending Machine Kelompok 6
// 11-11-2024, Kost 
// Ahmad Naufal, Farros Rifantiarno Ramadhani, Mohamad Ezza Fisabili
#include <iostream>
using namespace std;

// kamus
int uang, uangtambahan, poin, poin_tambahan, menu, pilihan, pilihansisa, kembalian;


void transaksiSelesai(); // menampilkan ketika transaksi telah selesai

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

struct komponenMenu
{
    makanan menuMakanan;
    minuman menuMinuman;
};

komponenMenu jenisMenu; 

// deskripsi
int main()
{
    int x = 0;
    while(x < 5)
    {
        cout << jenisMenu.menuMakanan.nama[x] << endl;
        x++;
    }

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
    cin >> uang;
    poin = uang / 1000;
    cout << "Jumlah saldo poin anda : " << poin << endl << endl;

    while (poin >= 0)
    {
        while (poin > 2) // ketika poin lebih dari 2 maka akan memasuki looping ini
        {
            cout << "---------------------------------------------------------------------------------------------------" << endl;
            cout << "Pilih menu makanan, minuman, menambahkan saldo poin, atau mengakhiri transaksi (1, 2, 3, atau 0) : ";
            cin >> menu;
            cout << "---------------------------------------------------------------------------------------------------" << endl;
            
            cout << endl;
            if (menu == 1)
            {
                cout << "Menu Makanan Five Flavours" << endl;
                cout << "1: Onigiri (10 poin)" << endl;
                cout << "2: Sushi (10 poin)" << endl;
                cout << "3: Ramen (12 poin)" << endl;
                cout << "4: Hotdog (15 poin)" << endl;
                cout << "5: Burger (15 poin)" << endl;
                cout << "0: Kembali ke menu utama" << endl;
                cout << "Pilih makanan yang mau anda tukarkan : ";
                cin >> pilihan;
                cout << endl;
                switch (pilihan)
                {
                    case 1:
                    {
                        if (poin == 10 || poin >= 10)
                        {
                            poin = poin - jenisMenu.menuMakanan.poin[0];
                            cout << "Makanan yang anda beli adalah Onigiri sebesar 10 poin" << endl;
                            cout << "Sisa saldo poin anda adalah : " << poin << endl;
                            break;
                        }
                        else
                        {
                            cout << "Saldo anda kurang sebesar " << poin-jenisMenu.menuMakanan.poin[0] << " poin untuk membeli Onigiri" << endl;
                            break;
                        }
                        break;
                    }
                    case 2:
                    {
                        if (poin == 10 || poin >= 10)
                        {
                            poin = poin - jenisMenu.menuMakanan.poin[1];
                            cout << "Makanan yang anda beli adalah Sushi sebesar 10 poin" << endl;
                            cout << "Sisa saldo poin anda adalah : " << poin << endl;
                            break;
                        }
                        else
                        {
                            cout << "Saldo anda kurang sebesar " << poin - jenisMenu.menuMakanan.poin[1] << " poin untuk membeli Sushi" << endl;
                            break;
                        }
                        break;
                    }
                    case 3:
                    {
                        if (poin == 12 || poin >= 12)
                        {
                            poin = poin - jenisMenu.menuMakanan.poin[2];
                            cout << "Makanan yang anda beli adalah Ramen sebesar 12 poin" << endl;
                            cout << "Sisa saldo poin anda adalah : " << poin << endl;
                            break;
                        }
                        else
                        {
                            cout << "Saldo anda kurang sebesar " << poin - jenisMenu.menuMakanan.poin[2] << " poin untuk membeli Ramen" << endl;
                            break;
                        }
                        break;
                    }
                    case 4:
                    {
                        if (poin == 15 || poin >= 15)
                        {
                            poin = poin - jenisMenu.menuMakanan.poin[3];
                            cout << "Makanan yang anda beli adalah Hotdog sebesar 15 poin" << endl;
                            cout << "Sisa saldo poin anda adalah : " << poin << endl;
                            break;
                        }
                        else
                        {
                            cout << "Saldo anda kurang sebesar " << poin - jenisMenu.menuMakanan.poin[3] << " poin untuk membeli Hotdog" << endl;
                            break;
                        }
                        break;
                    }
                    case 5:
                    {
                        if (poin == 15 || poin >= 15)
                        {
                            poin = poin - jenisMenu.menuMakanan.poin[4];
                            cout << "Makanan yang anda beli adalah Burger sebesar 15 poin" << endl;
                            cout << "Sisa saldo poin anda adalah : " << poin << endl;
                            break;
                        }
                        else
                        {
                            cout << "Saldo anda kurang sebesar " << poin - jenisMenu.menuMakanan.poin[4] << " poin untuk membeli Burger" << endl;
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
                switch (pilihan)
                {
                    case 1:
                    {
                        if (poin == 5 || poin >= 5)
                        {
                            poin = poin - jenisMenu.menuMinuman.poin[0];
                            cout << "Minuman yang anda beli adalah Fanta" << endl;
                            cout << "Sisa saldo poin anda adalah : " << poin << endl;
                            break;
                        }
                        else
                        {
                            cout << "Saldo anda kurang sebesar " << poin-jenisMenu.menuMinuman.poin[0] << " poin untuk membeli Fanta" << endl;
                            break;
                        }
                    }
                    case 2:
                    {
                        if (poin == 5 || poin >= 5)
                        {
                            poin = poin - jenisMenu.menuMinuman.poin[1];
                            cout << "Minuman yang anda beli adalah Coca-Cola" << endl;
                            cout << "Sisa saldo poin anda adalah : " << poin << endl;
                            break;
                        }
                        else
                        {
                            cout << "Saldo anda kurang sebesar " << poin-jenisMenu.menuMinuman.poin[1] << " poin untuk membeli Coca-Cola" << endl;
                            break;
                        }
                    }
                    case 3:
                    {
                        if (poin == 5 || poin >= 5)
                        {
                            poin = poin - jenisMenu.menuMinuman.poin[2];
                            cout << "Minuman yang anda beli adalah Sprite" << endl;
                            cout << "Sisa saldo poin anda adalah : " << poin << endl;
                            break;
                        }
                        else
                        {
                            cout << "Saldo anda kurang sebesar " << poin-jenisMenu.menuMinuman.poin[2] << " poin untuk membeli Sprite" << endl;
                            break;
                        }
                    }
                    case 4:
                    {
                        if (poin == 3 || poin >= 3)
                        {
                            poin = poin - jenisMenu.menuMinuman.poin[3];
                            cout << "Minuman yang anda beli adalah Aqua" << endl;
                            cout << "Sisa saldo poin anda adalah : " << poin << endl;
                            break;
                        }
                        else
                        {
                            cout << "Saldo anda kurang sebesar " << poin-jenisMenu.menuMinuman.poin[3] << " poin untuk membeli Aqua" << endl;
                            break;
                        }
                    }
                    case 5:
                    {
                        if (poin == 4 || poin >= 4)
                        {
                            poin = poin - jenisMenu.menuMinuman.poin[4];
                            cout << "Minuman yang anda beli adalah Teh Pucuk" << endl;
                            cout << "Sisa poin anda adalah : " << poin << endl;
                            break;
                        }
                        else
                        {
                            cout << "Saldo anda kurang sebesar " << poin-jenisMenu.menuMinuman.poin[4] << " poin untuk membeli Teh Pucuk" << endl;
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
                cout << "Masukan Uang Anda (Pecahan Kertas 1000, 2000, 5000, dst) : ";
                cin >> uangtambahan;
                poin_tambahan = uangtambahan / 1000;
                poin = poin + poin_tambahan;
                cout << "Saldo poin Anda kini menjadi : " << poin << endl;
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
            break;
        }
        cout << endl;
        while (poin <= 2) // ketika poin kurang dari sama dengan 2 maka akan memasuki looping ini karena minimal membeli makanan/minuman > 2
        {
            cout << "Saldo poin Anda kurang untuk melakukan transaksi" << endl;
            cout << "Apakah Anda ingin menambah saldo atau menyelesaikan transaksi (1: Menambah saldo 2: Mengakhiri) : ";
            cin >> pilihansisa;
            cout << endl;
            if (pilihansisa == 1)
            {
                cout << "Masukan Uang Anda(Pecahan Kertas 1000, 2000, 5000, dst) : ";
                cin >> uangtambahan;
                poin_tambahan = uangtambahan / 1000;
                poin = poin + poin_tambahan;
                cout << "Saldo poin Anda kini menjadi : " << poin << endl;
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

void transaksiSelesai()
{
    kembalian = poin*1000;
    cout << "Terima kasih telah berbelanja di Vending Machine Five Flavours" << endl;
    cout << "Uang anda kembali sebesar : " << kembalian << endl;
}