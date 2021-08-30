#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>

#include <stdio.h>
using namespace std;

class mall
{
public:
  int brands;
  void show()
  {
    ifstream x("mall.txt")
    }
  }
};
class Eproduct : public virtual mall
{
public:
  int quan;
  char name[20];
  char color[20];
  char size[20];
  int checkout;


  void cal()
  {
    
  }
  void file();
  void get();
};
void Eproduct::get()
{
  int s;
  cout << "\nChoose Brand : \n";
  cout << "\n1.J. Junaid Jamshaid";
  cout << "\n2.Ethnic Outfitters";
  cout << "\n3.Khaddi";
  cout << "\n4.Gul Ahmed";
  cout << "\n5.Al-Karam Studio \n";
  cin >> s;

  cout << "\ninput product name: \nfor instance: Shirt,Trousers,Scarf \n";
  cin >> name;
  cout << "\ninput product color: \nAvailable colors: Red,Black,Blue,Handprinted,Multicolored \n";
  cin >> color;
  cout << "\ninput size of product: \nAvailable Sizes: Small,Medium,Large,Extra-Large \n";
  cin >> size;
  cout << "\ntotal product quantity: \n";
  cin >> quan;
  cout<< "\nPlease press 1 to checkout \n";
  cin >> checkout;
  cout<< "\n======================================================================================\n";
  cout<< "\nTHANKYOU for your visit,you will be checked out shortly via message.Happy Shopping\n";
  cout<< "\n======================================================================================\n";
  cal();
  file();
}
void Eproduct::file()
{
  char file[20];
  strcpy(file, color);
  strcat(file, ".txt");
  ofstream f(file);
  f << "\nproduct name: " << name << "\nproduct id: " << color << "\ncost price of product: " << size << "\nquantity: " << quan;
  f.close();
}

class Wproduct : public virtual mall
{
protected:
  int BRAND;
  char pname[20];
  char pcolor[10];
  char psize[20];
  int postquan;
  int Wchkt;
  void cal()
  {
    cout<< "\nHappy Shopping \n";
  }
  void getstaff();
  void file();
};
void Wproduct::getstaff()
{
  cout << "\nChoose Brand: \n";
  cout << "\n1.GUCCI \n";
  cout << "\n2.Versace: \n";
  cout << "\n3.Louis Vuitton: \n";
  cout << "\n4.Dior: \n";
  cout << "\n5.ZARA: \n";

  cin >> BRAND;
  cout << "\ninput product name: \nfor instance: Shirt,Trousers,Scarf: \n";
  cin >> pname;
  cout << "\ninput product color: \nAvailable colors: Red,Black,Blue,Handprinted,Multicolored \n";
  cin >> pcolor;
  cout << "\ninput size of product: \nAvailable Sizes: Small,Medium,Large,Extra-Large \n";
  cin >> psize;
  cout << "\ntotal product quantity: \n";
  cin >> postquan;
  cout<< "\nPlease press 1 to checkout \n";
  cin >> Wchkt;
  cout<< "\n======================================================================================\n";
  cout<< "\nTHANKYOU for your visit,you will be checked out shortly via message.Happy Shopping\n";
  cout<< "\n======================================================================================\n";
  cal();
  file();
  // }
}
void Wproduct::file()
{
  char file[20];
  strcpy(file, pcolor);
  strcat(file, ".txt");
  ofstream f(file);
  f << "\nnumber of products: " << postquan << "\nproduct brand: " << BRAND << "\nproduct name :" << pname << "\nproduct color: " << pcolor;
  f.close();
}

class amount : public Wproduct, public Eproduct
{

public:
  void add();
  void update_item();
  void update_emp();
};
void amount::add()
{
  int ch;
  char name[20];
  while (1)
  {
    cout << "1.)Eastren Outfits\n2.)Westren Outfits\n3.)Exit\n";
    cout << "Enter choice\n";
    cin >> ch;
    if (ch == 1)
    {
      get();
      ofstream x("ooo.txt");
      x << brands;
      x.close();
    }
    else if (ch == 2)
    {
      getstaff();
      ofstream x("ooo.txt");
      x << brands;
      x.close();
    }
    else if (ch == 3)
      break;
    else
      cout << "Invaid Option. Please re-enter\n";
  }
}

void amount::update_item()
{
  char id[20];
  char pid[20];
  char c;
  cout << "\nINPUT product ID to modify\n";
  cin >> id;
  char file[20];
  char file2[20];
  strcpy(file, id);
  strcat(file, ".txt");
  fstream fout(file, ios::in | ios::out);
  if (!fout)
  {
    cout << "file couldn't be opened. product ID not found. \n";
  }
  else
  {
    cout << "file found! \n";
    cout << "\nupdate product name: \n";
    cin >> name;
    cout << "\nupdate total product quantity: \n";
    cin >> quan;
  }
}
void amount::update_emp()
{
  char id[20];
  char c;
  cout << "\nINPUT item ID to modify: ";
  cin >> id;
  char file[20];
  strcpy(file, id);
  strcat(file, ".txt");
  fstream fout(file, ios::in | ios::out);
  if (!fout)
  {
    cout << "file couldn't be opened. product ID not found. \n";
  }
  cout << "modify item type: \n";
  cin >> pname;
  fout << "\nnumber of items: " << postquan << "\nitem brand: " << BRAND << "\nitem name :" << pname << "\nitem color: " << pcolor;
  fout.close();
}

void admin()
{
  while (1)
  {
    cout << "\n\t\t\t==============================\n";
    cout << "\n\t\t\t     WELCOME TO THE CITY MALL  \n";
    cout << "\n\t\t\t==============================\n\n";
    cout << "\n\t\t\t* * * * * * * * * * * * * * * *\n";
    cout << "\n\t\t\t1. Clothes\n\n\t\t\t2. Shoestore\n\n\t\t\t3. Bookstore\n\n\t\t\t4. Games Store\n\n\t\t\t5.Exit\n";
    cout << "\n\n\t\t\tSelect your choice\n";
    int u;
    cin >> u;
    if (u == 1)
    {
      amount a;
      a.show();
      a.add();
    }
    else if (u == 2)
    {
      char shoeM[20];
      char Sstyle[20];
      char Scolor[10];
      int Sz;
      int Np;
      int Schkt;
      cout << "\nWELCOME TO THE ShoeStore \n";
      cout << "\n=============================\n";
      cout << "\nPlease select the material \nIn Stock; Leather,Textile,Plastic,Velvet,Fiber\n";
      cin >> shoeM;
      cout << "\nPlease select the style\nFor Men ; Shoes or Sandles\nFor Women ; Heels or Flats\n";
      cin >> Sstyle;
      cout << "\nPlease choose the color \nAvailable in ; Black,Grey and Blue\n";
      cin >> Scolor;
      cout << "\nPlease enter the size\n";
      cin >> Sz;
      cout << "\nPlease enter the no of pairs to be purchased \n";
      cin >> Np;
      cout<< "\nPlease press 1 to checkout \n";
      cin >> Schkt;
      cout<< "\n======================================================================================\n";
      cout<< "\nTHANKYOU for your visit,you will be checked out shortly via message.Happy Shopping\n";
      cout<< "\n======================================================================================\n";

     
    }
    else if (u == 3)
    {
      char Bname[20];
      char Aname[20];
      int copies;
      int Bchkt;
      cout << "\nWELCOME TO THE BOOKSTORE \n";
      cout << "\n=============================\n";
      cout << "\nPlease enter the book you are looking for \n";
      cin >> Bname;
      cout << "\nPlease enter the Author's name \n";
      cin >> Aname;
      cout << "\nPlease enter the no of copies \n";
      cin >> copies;
      cout<< "\nPlease press 1 to checkout \n";
      cin >> Bchkt;
      cout<< "\n======================================================================================\n";
      cout<< "\nTHANKYOU for your visit,you will be checked out shortly via message.Happy Shopping\n";
      cout<< "\n======================================================================================\n";
      
    }
    else if (u == 4)
    {
      char Gname[20];
      char Psname[20];
      int Drives;
      int Gchkt;
      cout << "\nWELCOME TO THE Games Store \n";
      cout << "\n=============================\n";
      cout << "\nPlease enter the Video Game you are looking for \n";
      cin >> Gname;
      cout << "\nPlease select the play station\nIn Stock for; Ps3 and Ps4\n";
      cin >> Psname;
      cout << "\nPlease enter the no of drives \n";
      cin >> Drives;
      cout<< "\nPlease press 1 to checkout \n";
      cin >> Gchkt;
      cout<< "\n======================================================================================\n";
      cout<< "\nTHANKYOU for your visit,you will be checked out shortly via message.Happy Shopping\n";
      cout<< "\n======================================================================================\n";
    }
    else if (u == 5)
    {
      break;
    }
    else
      cout << "Invalid option. Please select one of the available options\n";
  }
}

int main()
{
  int ch;
  while (1)
  {
    cout << "\n \t\t\t=========================\n";
    cout << "\n\t\t\tWELCOME TO THE CITY MALL  \n";
    cout << "\n \t\t\t=========================\n\n";
    cout << "\n \t\t\t* * * * * * * * * * * * ";
    cout << "\n\t\t\t  1. VIEW MENU";
    cout << "\n\t\t\t  2. EXIT";
    cout << "\n\t\t\t* * * * * * * * * * * *\n";
    cout << "\n\t\t\t Enter Your choice: ";
    cin >> ch;
    switch (ch)
    {
    case 1:
      admin();
      break;
    case 2:
      exit(0);
      break;
    default:
      cout << "Enter valid choice\n";
      break;
    }
  }
  return 0;
}

