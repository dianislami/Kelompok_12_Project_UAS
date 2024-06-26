#include "header.h"

//menampilkan menu utama dari program secara keseluruhan
int main() {
    Produk dataproduk[MAX_BARANG];
    int jumlahproduk = 0;
    int pilihan;
    int nilai;

    //membaca data yang ada di dalam file external data barang
    bacaDataBarang(dataproduk, &jumlahproduk);

    //Login sebelum masuk ke menu kasir
    nilai = Login();

    //Menampilkan menu dan meminta user memilih menu
    while (nilai == 1) {
        printf("\n======= MENU KASIR =======\n");
        printf("1. Tambah Produk\n");
        printf("2. Hapus Produk\n");
        printf("3. Tambah Stok Produk\n");
        printf("4. Kurangi Stok Produk\n");
        printf("5. Tampilkan Daftar Produk\n");
        printf("6. Pembayaran\n");
        printf("7. Keluar\n");
        printf("==========================\n");
        printf("Masukkan pilihan Anda: ");
        scanf("%d", &pilihan);

        //Kode program berupa fungsi untuk setiap menu
        switch (pilihan) {
            //menu untuk menambah barang
            case 1:
                tambahBarang(dataproduk, &jumlahproduk);
                tulisDataBarang(dataproduk, jumlahproduk);
                break;
            //menu untuk menghapus barang 
            case 2:
                hapusBarang(dataproduk, &jumlahproduk);
                tulisDataBarang(dataproduk, jumlahproduk);
                break;
            //menu untuk menambah stok dari barang yang sudah ada di dalam ada di file external
            case 3:
                tambahStok(dataproduk, jumlahproduk);
                tulisDataBarang(dataproduk, jumlahproduk);
                break;
            //menu untuk mengurangi stok dari barang yang sudah ada di dalam ada di file external
            case 4:
                kurangiStok(dataproduk, jumlahproduk);
                tulisDataBarang(dataproduk, jumlahproduk);
                break;
            //menu untuk menampilkan barang barang yang telah tertera di file external
            case 5:
                tampilkanDaftarBarang(dataproduk, jumlahproduk);
                tulisDataBarang(dataproduk, jumlahproduk);
                break;
            //menu untuk memproses pembayaran yang ada di dalam program
            case 6:
                pembayaran(dataproduk, jumlahproduk);
                tulisDataBarang(dataproduk, jumlahproduk);
                break;
            //menu untuk keluar dari program
            case 7:
                exit(0);
            default:
                printf("Pilihan tidak valid.\n");
        }
    }
    return 0;
}
