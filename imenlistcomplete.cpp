#include <iostream>
#include <cstdlib>
#include <stdlib.h>

using namespace std;
struct node
{
  int urut; //data yang ada pada node
  node *next;
};


node *awal_ptr = NULL;
  node *posisi;         //digunakan untuk membaca sepanjang list
  int option = 0, pos, value;
  int banyakdata,posisi_hapus,poshapus;

void tambah_awal_list()
{
  node *baru;
  baru = new node;
  cout << "Masukkan Data     : ";
  cin >> baru->urut;
  baru->next = NULL;
  if(awal_ptr == NULL)
  {
    awal_ptr=baru;
    awal_ptr->next = NULL;
  }
  else
  {
    baru->next = awal_ptr;
    awal_ptr = baru;
  }
}

void insert_position()
  {
  	if(awal_ptr == NULL)
  {
    cout<<"masukan dulu data, baru sisipikan data oke";
  }
  else{
    node *pre=new node;
    node *cur=new node;
    node *temp=new node;
    cur=awal_ptr;
    cout<<"masukan pada data berapa yang anda ingin sisipkan =";cin>>pos;
    for(int i=1;i<pos;i++)
    {
      pre=cur;
      cur=cur->next;
    }
    cout<<"masukan data yang anda ingin sisipkan =";cin>>value;
    temp->urut=value;
    pre->next=temp;	
    temp->next=cur;}
  }

void menambah_node_di_akhir()
  {
  node *temp, *temp2;   // Temporary pointers
  // menciptakan node baru
  temp = new node;
  cout << "Masukkan urut     : ";
  cin >>   temp->urut;
  temp->next = NULL;

// Set up link pada node
  if (awal_ptr == NULL)
  {
    awal_ptr = temp;
    posisi = awal_ptr;
  }
  else
  {
    temp2 = awal_ptr;
    // node tidak NULL – list tidak kosong
    while (temp2->next != NULL)
    {
      temp2 = temp2->next;
      // Memindahkan pada next link dalam rantai
    }
  temp2->next = temp;
  }
}

void hapus_awal_node()
{
  node *temp;
  temp = awal_ptr;
  awal_ptr = awal_ptr->next;
  delete temp;
}

void hapus_akhir_node()
{
  node *temp1, *temp2;
  if (awal_ptr == NULL)
    cout << "List kosong!" << endl;
  else
  {
    temp1 = awal_ptr;
    if (temp1->next == NULL)
    {
      delete temp1;
      awal_ptr = NULL;
    }
    else
    {
      while (temp1->next != NULL)
      {
        temp2 = temp1;
        temp1 = temp1->next;
      }
      delete temp1;
      temp2->next = NULL;
    }

   }
}

void Hapus_tengah_list()
{
  node *hapus, *bantu;
  if(awal_ptr != NULL)
  {
    cout<<" Akan dihapus pada data ke : ";
    cin>>posisi_hapus;
    banyakdata=1;
    bantu=awal_ptr;
    while(bantu->next != NULL)
    {
      bantu=bantu->next;
      banyakdata++;
    }
    if((posisi_hapus<1)||(posisi_hapus>banyakdata))
    {
      cout<<"Belum ada data !! masukkan Data dula aja...\n";
    }
    else
    {
      bantu=awal_ptr;
      poshapus=1;
      while(poshapus<(posisi_hapus-1))
      {
        bantu=bantu->next;
        poshapus++;
      }
      hapus=bantu->next;
      bantu->next=hapus->next;
      delete hapus;
    }
 }
 else 
    cout<<"Data Masih kosong, tidak bisa hapus data dari tengah! ";
}

void display_list()
{
  node *temp;
  temp = awal_ptr;
  cout << endl;
cout << "DATA ";
  if (temp == NULL)
    cout << "List kosong!" << endl;
  else
  {
    while (temp != NULL)
    {  // Menampilkan detail data

     cout << "" << temp->urut << ",";

     if (temp == posisi)
        cout << "     <<<< posisi node";
//     cout << endl;
     temp = temp->next;
    }
    cout << "] ";
    cout << "Akhir list!" << endl;
  }

}

void tampilkan_awal_list()
{
  node *temp;
  temp = awal_ptr;
  cout << endl;
cout << "DATA ";
  if (temp == NULL)
    cout << "List kosong!" << endl;
  else
  {
  	cout << " [ " << awal_ptr -> urut << " ] ";
  }
}



int main()
{
	int pos,value;
	int banyakdata,posisi_hapus,poshapus;
 cout << "===============================" << endl;
  cout << "NAMA : chairil hilman syah" << endl;
  cout << "NIM : 0110217054" << endl;
  cout << "STRUKTUR DATA DAN ALGORITMA" << endl;
  cout << "===============================" << endl;
  awal_ptr = NULL;
  do
  {
//    clrscr();
    cout << endl;
    cout << "MENU PILIHAN : " << endl;
    cout << "0. Keluar program." << endl;
    cout << "1. Tambah awal list." << endl;
    cout << "2. Tambah akhir list." << endl;
    cout << "3. tambah tengah."<< endl;
    cout << "4. Hapus awal list."<< endl;
    cout << "5. hapus akhir list." << endl;
    cout << "6. hapus tengah list" << endl;
    cout << "7. tampilkan awal list" << endl;
    cout << "8. tampilkan semua list" << endl;
    cout << endl << " Pilihan >> ";
    cin >> option;

switch (option)
  {
  case 1 : tambah_awal_list();
    break;
  case 2 : menambah_node_di_akhir();
    break;
  case 3 : insert_position();
    break;
  case 4 : hapus_awal_node();
    break;
  case 5 : hapus_akhir_node();
    break;
  case 6 : Hapus_tengah_list();
  	break ;
  case 7 : tampilkan_awal_list();
  	break ;
  case 8 : display_list();
  	break ;
  }
 }
while (option != 0);
}
