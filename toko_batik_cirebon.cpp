#include <iostream>
#include <string>
#include <queue>
#include <windows.h>

using namespace std;

struct Barang
{
    string nama;
    int harga;
};

struct Keranjang
{
    string namaPemesan;
    Barang barang;
    int jumlah;
    bool isMember;
    Keranjang *next;
};

Keranjang *keranjangHead = NULL;
queue<Keranjang *> historyPemesananQueue;


Barang daftarBarang[] = {
    {"Batik Megamendung Ukuran S", 140000},
    {"Batik MU Ukuran M", 140000},
    {"Batik BERSAMA Ukuran L", 150000}};
    
void clearScreen() {
    system("cls");
}

void tampilkanDaftarBarang()
{
	clearScreen();
    cout << "Daftar Barang Tersedia:\n";
    for (int i = 0; i < sizeof(daftarBarang) / sizeof(daftarBarang[0]); ++i)
    {
        cout << i + 1 << ". " << daftarBarang[i].nama << " - Rp" << daftarBarang[i].harga << "\n";
    }
}

Keranjang *cariKeranjang(string namaPemesan)
{
    Keranjang *current = keranjangHead;
    while (current != NULL)
    {
        if (current->namaPemesan == namaPemesan)
        {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void tambahPesanan(Keranjang *keranjang, Barang barang, int jumlah)
{
	clearScreen();
    Keranjang *newPesanan = new Keranjang;
    newPesanan->namaPemesan = keranjang->namaPemesan;
    newPesanan->barang = barang;
    newPesanan->jumlah = jumlah;
    newPesanan->isMember = keranjang->isMember;
    newPesanan->next = NULL;

    Keranjang *current = keranjang;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = newPesanan;
}

void belanjaBarang()
{
	clearScreen();
    string namaPemesan;
    cout << "Masukkan nama pemesan: ";
    cin >> namaPemesan;

    Keranjang *keranjang = cariKeranjang(namaPemesan);
    if (keranjang == NULL)
    {
        keranjang = new Keranjang;
        keranjang->namaPemesan = namaPemesan;
        keranjang->barang = {"", 0};
        keranjang->jumlah = 0;
        keranjang->isMember = false;
        keranjang->next = keranjangHead;
        keranjangHead = keranjang;
    }

    tampilkanDaftarBarang();
    int pilihan, jumlah;
    cout << "Pilih barang (nomor): ";
    cin >> pilihan;
    cout << "Masukkan jumlah: ";
    cin >> jumlah;

    if (pilihan > 0 && pilihan <= sizeof(daftarBarang) / sizeof(daftarBarang[0]))
    {
        tambahPesanan(keranjang, daftarBarang[pilihan - 1], jumlah);
        cout << "Barang berhasil ditambahkan ke keranjang.\n";
    }
    else
    {
        cout << "Pilihan tidak valid.\n";
    }
}

void bayarBarang()
{
	clearScreen();
    string namaPemesan;
    cout << "Masukkan nama pemesan: ";
    cin >> namaPemesan;

    Keranjang *keranjang = cariKeranjang(namaPemesan);
    if (keranjang == NULL || keranjang->next == NULL)
    {
        cout << "Keranjang tidak ditemukan atau kosong.\n";
        return;
    }

    int totalHarga = 0;
    int totalJumlah = 0;
    Keranjang *current = keranjang->next; // skip dummy node
    while (current != NULL)
    {
        totalHarga += current->barang.harga * current->jumlah;
        totalJumlah += current->jumlah;
        current = current->next;
    }

    double diskon = 0;
    if (totalJumlah >= 7)
    {
        diskon = 0.20;
    }
    else if (totalJumlah >= 5)
    {
        diskon = 0.15;
    }
    else if (totalJumlah >= 2)
    {
        diskon = 0.10;
    }

    if (keranjang->isMember)
    {
        diskon += 0.05; // Diskon tambahan untuk member
    }

    int totalDiskon = static_cast<int>(totalHarga * diskon);
    int hargaSetelahDiskon = totalHarga - totalDiskon;

    cout << "Rincian Harga:\n";
    cout << "Total harga sebelum diskon: Rp" << totalHarga << "\n";
    cout << "Total diskon: Rp" << totalDiskon << " (" << diskon * 100 << "%)\n";
    cout << "Total harga setelah diskon: Rp" << hargaSetelahDiskon << "\n";

    int pembayaran;
    do
    {
        cout << "Masukkan jumlah pembayaran: ";
        cin >> pembayaran;

        if (pembayaran < hargaSetelahDiskon)
        {
            cout << "Pembayaran kurang. Silakan masukkan jumlah pembayaran yang cukup.\n";
        }
    } while (pembayaran < hargaSetelahDiskon);

    cout << "Pembayaran berhasil.\n";
    current = keranjang->next; // skip dummy node
    while (current != NULL)
    {
        historyPemesananQueue.push(current);
        current = current->next;
    }
    keranjang->next = NULL;
    if (totalJumlah >= 15)
    {
        keranjang->isMember = true;
        cout << "Selamat, Anda menjadi member!\n";
    }
}

void hapusPesanan()
{
	clearScreen();
    string namaPemesan;
    cout << "Masukkan nama pemesan: ";
    cin >> namaPemesan;

    Keranjang *keranjang = cariKeranjang(namaPemesan);
    if (keranjang == NULL || keranjang->next == NULL)
    {
        cout << "Keranjang tidak ditemukan atau kosong.\n";
        return;
    }

    if (keranjang->next->next == NULL)
    {
        delete keranjang->next;
        keranjang->next = NULL;
    }
    else
    {
        Keranjang *current = keranjang->next;
        while (current->next->next != NULL)
        {
            current = current->next;
        }
        delete current->next;
        current->next = NULL;
    }
    cout << "Pesanan terakhir dihapus.\n";
}

void tampilkanPesanan()
{
	clearScreen();
    string namaPemesan;
    cout << "Masukkan nama pemesan: ";
    cin >> namaPemesan;

    Keranjang *keranjang = cariKeranjang(namaPemesan);
    if (keranjang == NULL || keranjang->next == NULL)
    {
        cout << "Keranjang tidak ditemukan atau kosong.\n";
        return;
    }

    cout << "Pesanan dalam keranjang:\n";
    Keranjang *current = keranjang->next; // skip dummy node
    while (current != NULL)
    {
        cout << current->barang.nama << " - " << current->jumlah << " pcs\n";
        current = current->next;
    }
}

void tampilkanHistoryPemesanan()
{
	clearScreen();
    if (historyPemesananQueue.empty())
    {
        cout << "Tidak ada history pemesanan.\n";
        return;
    }

    cout << "History pemesanan:\n";
    queue<Keranjang *> tempQueue = historyPemesananQueue;
    while (!tempQueue.empty())
    {
        Keranjang *pesanan = tempQueue.front();
        tempQueue.pop();
        cout << pesanan->barang.nama << " - " << pesanan->jumlah << " pcs\n";
    }
}

void memberingDanEditMember()
{
	clearScreen();
    string namaPemesan;
    cout << "Masukkan nama pemesan: ";
    cin >> namaPemesan;

    Keranjang *keranjang = cariKeranjang(namaPemesan);
    if (keranjang == NULL)
    {
        cout << "Pemesan tidak ditemukan.\n";
        return;
    }

    if (keranjang->isMember)
    {
        cout << "Anda adalah member.\n";
        cout << "Apakah Anda ingin mengedit alamat? (y/n): ";
        char pilihan;
        cin >> pilihan;
        if (pilihan == 'y')
        {
            string alamatBaru;
            cout << "Masukkan alamat baru: ";
            cin >> alamatBaru;
            // Update alamat member (implementasi alamat tidak ada di struktur saat ini)
            cout << "Alamat diperbarui.\n";
        }
    }
    else
    {
        cout << "Anda bukan member.\n";
    }
}

int main()
{
    int pilihan;
    do
    {
        cout << "Menu:\n";
        cout << "1. Belanja Barang\n";
        cout << "2. Bayar Barang\n";
        cout << "3. Hapus Pesanan\n";
        cout << "4. Tampilkan Pesanan\n";
        cout << "5. History Pemesanan\n";
        cout << "6. Membering dan Edit Member\n";
        cout << "7. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            belanjaBarang();
            break;
        case 2:
            bayarBarang();
            break;
        case 3:
            hapusPesanan();
            break;
        case 4:
            tampilkanPesanan();
            break;
        case 5:
            tampilkanHistoryPemesanan();
            break;
        case 6:
            memberingDanEditMember();
            break;
        case 7:
            cout << "Keluar dari program.\n";
            break;
        default:
            cout << "Pilihan tidak valid.\n";
            break;
        }
    } while (pilihan != 7);

    return 0;
}