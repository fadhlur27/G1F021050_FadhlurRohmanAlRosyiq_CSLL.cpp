#include <iostream>
using namespace std;

// Deklarasi struktur untuk Circular Single Linked List
struct Tas{
  string merek, jenis, tipe, harga;

  Tas *next;
};

Tas *head, *tail, *newNode, *cur, *del;

// create Circular Single Linked List
void createCircularSingleLinkedList(string dataBaru[4] ){

  head = new Tas();
  head->merek = dataBaru[0];
  head->jenis = dataBaru[1];
  head->tipe = dataBaru[2];
  head->harga = dataBaru[3];
  tail = head;
  tail->next = head;

}

// add first
void addFirst( string data[4] ){
  if( head == NULL ){
    cout << "Buat Linked Listnya dulu!!" << endl;
  }else{
    newNode = new Tas();
    newNode->merek = data[0];
    newNode->jenis = data[1];
    newNode->tipe = data[2];
    newNode->harga = data[3];
    newNode->next = head;
    tail->next = newNode;
    head = newNode;
  }
}

// add Last
void addLast( string data[4] ){
  if( head == NULL ){
    cout << "Buat Linked Listnya dulu!!" << endl;
  }else{
    newNode = new Tas();
    newNode->merek = data[0];
    newNode->jenis = data[1];
    newNode->tipe = data[2];
    newNode->harga = data[3];
    newNode->next = head;
    tail->next = newNode;
    tail = newNode;
  }
}

// add Middle
void addMiddle(string data[4], int posisi)
{
  if( head == NULL ){
    cout << "Buat Linked Listnya dulu!!" << endl;
  }else{
    if( posisi == 1 ){
      cout << "Posisi satu bukan posisi tengah!!!" << endl;
    }else{
      newNode = new Tas();
      newNode->merek = data[0];
      newNode->jenis = data[1];
      newNode->tipe = data[2];
      newNode->harga = data[3];

      // tranversing
      int nomor = 1;
      cur = head;
      while (nomor < posisi - 1)
      {
        cur = cur->next;
        nomor++;
      }
      newNode->next = cur->next;
      cur->next = newNode;
    }
  }
}

// remove First
void removeFirst(){
  if( head == NULL ){
    cout << "Buat Linked Listnya dulu!!" << endl;
  }else{
    del = head;
    head = head->next;
    tail->next = head;
    delete del;
  }
}

// remove last
void removeLast()
{
  if( head == NULL ){
    cout << "Buat Linked Listnya dulu!!" << endl;
  }else{
    del = tail;
    cur = head;
    while( cur->next != tail ){
      cur = cur->next;
    }
    tail = cur;
    tail->next = head;
    delete del;
  }
}

// remove middle
void removeMiddle(int posisi)
{
  if( head == NULL ){
    cout << "Buat Linked Listnya dulu!!" << endl;
  }else{
    // tranversing
    int nomor = 1;
    cur = head;
    while( nomor < posisi - 1 ){
      cur = cur->next;
      nomor++;
    }
    del = cur->next;
    cur->next = del->next;
    delete del;
  }
}


void printCircular()
{
  if( head == NULL ){
    cout << "Buat Linked Listnya dulu!!" << endl;
  }else{
    cout << " List Tas " << endl;
    cout << "________________________________________________________________" << endl; 
    cout << "| MEREK\t\t| JENIS\t\t| TIPE\t\t| HARGA\t\t|" << endl;
    cout << "________________________________________________________________" << endl; 
    cur = head;
    while (cur->next != head)
    {
      // print
      cout << "| " << cur->merek << "\t| " << cur->jenis << "\t| " << cur->tipe << "\t|" << cur->harga << "\t\t|" << endl;
      cur = cur->next;
    }
    cout << "| " << cur->merek << "\t| " << cur->jenis << "\t| " << cur->tipe << "\t|" << cur->harga << "\t\t|" << endl;
    cout << "_________________________________________________________________" << endl;
  }
}


int main(){
  string dataBaru[4] = {"CATNIP 308", "TAS KULIT", "TAS SELEMPANG", "160000"};
  createCircularSingleLinkedList(dataBaru);

  printCircular();

  string data[4] = {"EIGER", "NYLON", "TAS SELEMPANG", "275000"};
  addFirst(data);

  printCircular();

  string data2[4] = {"CONVERSE", "KANVAS", "TAS RANSEL", "500000"};
  addLast(data2);

  printCircular();

  string data3[4] = {"VOYEJ", "GENUINE LEATHER", "POUCH", "775000"};
  addMiddle(data3, 5);

  printCircular();

  removeMiddle(6);

  printCircular();

  removeFirst();

  printCircular();

  removeLast();

  printCircular();
}
