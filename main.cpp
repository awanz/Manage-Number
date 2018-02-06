#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;
int angka[100];
int angka2[100];
int pilih, jumlah, i, cari, a, b, ubah, ubah2, gede, hapus;
string numb;

void tulis(){
    ofstream myfile;
    ofstream myfile2;
    myfile.open ("main.txt");
    myfile2.open ("log.txt");
    int i = 0;
    while(i < jumlah){
        if(i == 0){
            myfile << angka[i];
            myfile << "\n";
            gede = angka[i];
        }else{
            if(gede > angka[i]){
                myfile2 << angka[i];
                myfile2 << "\n";
            }else{
                myfile << angka[i];
                myfile << "\n";
                gede = angka[i];
            }
        }

        i++;
    }

    myfile.close();
}


void cariData(){
    int i;
    ifstream ip("main.txt");
    ifstream ip2("log.txt");
	if(!ip.is_open()){
		cout << "main.txt tidak dapat dibuka" << endl;
	}else{
	    i = 0;
        while(ip.good()){
            getline(ip,numb,'\n');
            if(atoi(numb.c_str()) == cari){
                cout << cari << " berada di file main.txt di index ke-" << i << endl;
                break;
            }
            i++;
        }
        ip.close();
        i = 0;
        while(ip2.good()){
            getline(ip2,numb,'\n');
            if(atoi(numb.c_str()) == cari){
                cout << cari << " berada di file log.txt di index ke-" << i << endl;
                break;
            }
            i++;
        }
        ip.close();
	}
}

void updateData(){
    int i;
    ifstream ip("main.txt");
    ifstream ip2("log.txt");
	if(!ip.is_open()){
		cout << "main.txt tidak dapat dibuka" << endl;
	}else{
	    i = 0;
	    b = 0;
        while(ip.good()){
            getline(ip,numb,'\n');
            if(atoi(numb.c_str()) == ubah){
                b = 1;
                break;
            }
            i++;
        }
        ip.close();
        i = 0;
        while(ip2.good()){
            getline(ip2,numb,'\n');
            if(atoi(numb.c_str()) == ubah){
                b = 2;
                break;
            }
            i++;
        }
        ip2.close();
	}

	if ( b == 0){
        cout << "Angka yang di update tidak ditemukan" << endl;
	}else if(b == 1){
        i = 0;
	    cout << "Proses update data main.." << endl;
	    ifstream ip("main.txt");
        while(ip.good()){
            getline(ip,numb,'\n');
            angka2[i] = atoi(numb.c_str());
            i++;
        }
        ip.close();


        ofstream myfile;
        myfile.open ("main.txt");
        int j = 0;
        while(j < i-1){
            if(angka2[j] == ubah){
                myfile << ubah2;
                myfile << "\n";
            }else{
                myfile << angka2[j];
                myfile << "\n";
            }

            j++;
        }
        myfile.close();

	}else if(b == 2){
        i = 0;
	    cout << "Proses update data log.." << endl;
	    ifstream ip("log.txt");
        while(ip.good()){
            getline(ip,numb,'\n');
            angka2[i] = atoi(numb.c_str());
            i++;
        }
        ip.close();
        ofstream myfile;
        myfile.open ("log.txt");
        int j = 0;
        while(j < i-1){
            if(angka2[j] == ubah){
                myfile << ubah2;
                myfile << "\n";
            }else{
                myfile << angka2[j];
                myfile << "\n";
            }

            j++;
        }
        myfile.close();
	}
}

void hapusData(){
    int i;
    ifstream ip("main.txt");
    ifstream ip2("log.txt");
	if(!ip.is_open()){
		cout << "main.txt tidak dapat dibuka" << endl;
	}else{
	    i = 0;
	    b = 0;
        while(ip.good()){
            getline(ip,numb,'\n');
            if(atoi(numb.c_str()) == hapus){
                b = 1;
                break;
            }
            i++;
        }
        ip.close();
        i = 0;
        while(ip2.good()){
            getline(ip2,numb,'\n');
            if(atoi(numb.c_str()) == hapus){
                b = 2;
                break;
            }
            i++;
        }
        ip2.close();
	}

	if ( b == 0){
        cout << "Angka yang di update tidak ditemukan" << endl;
	}else if(b == 1){
        i = 0;
	    cout << "Proses hapus data di main.." << endl;
	    ifstream ip("main.txt");
        while(ip.good()){
            getline(ip,numb,'\n');
            angka2[i] = atoi(numb.c_str());
            i++;
        }
        ip.close();


        ofstream myfile;
        myfile.open ("main.txt");
        int j = 0;
        cout << i << endl;
        while(j < i-1){
            if(angka2[j] == hapus){
                myfile << "\n";
            }else{
                myfile << angka2[j];
                myfile << "\n";
            }

            j++;
        }
        myfile.close();

	}else if(b == 2){
        i = 0;
	    cout << "Proses hapus data di log.." << endl;
	    ifstream ip("log.txt");
        while(ip.good()){
            getline(ip,numb,'\n');
            angka2[i] = atoi(numb.c_str());
            i++;
        }
        ip.close();


        ofstream myfile;
        myfile.open ("log.txt");
        int j = 0;
        while(j < i-1){
            if(angka2[j] == hapus){
                myfile << "\n";
            }else{
                myfile << angka2[j];
                myfile << "\n";
            }

            j++;
        }
        myfile.close();
	}
}
int main()
{
    cout << "==========================" << endl;
    cout << " Manage Number" << endl;
    cout << " Nama: Jajang Hermawan" << endl;
    cout << " NIM: 1301178281" << endl;
    cout << "==========================" << endl;
    cout << "Menu:" << endl;
    cout << "1. Insert" << endl;
    cout << "2. Find" << endl;
    cout << "3. Update" << endl;
    cout << "4. Delete" << endl;
    cout << "Pilih Menu: ";
    cin >> pilih;
    cout << endl;

    switch (pilih){
    case 1:
        cout << "Masukan angka jumlah data: ";
        cin >> jumlah;
        i=0;
        while(i < jumlah){
            cout << "Masukan angka: ";
            cin >> angka[i];
            i++;
        }

        tulis();
        break;
    case 2:
        cout << "Masukan angka yang di cari: ";
        cin >> cari;
        cariData();
        break;
    case 3:
        cout << "Masukan angka lama: ";
        cin >> ubah;
        cout << "Masukan angka baru: ";
        cin >> ubah2;
        updateData();
        break;
    case 4:
        cout << "Masukan angka yang akan dihapus: ";
        cin >> hapus;
        hapusData();
        break;
    default:
        cout << "Pilihan salah!" << endl;
        break;
    }
    return 0;
}
