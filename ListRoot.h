#ifndef BAITAPKTLTUSELIST_H // neu chua dinh nghia
#define BAITAPKTLTUSELIST_H

#include<iostream>
#include<fstream>
#include<queue>
#include<stack>
#include<windows.h>
#include<string.h>
#include<conio.h>
#include<string>
#include<sstream>
#include<iomanip>
#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;



#define file            "BaiTapKTLT.txt"
#define fileStudentName "BaiTapKTLTStudentName.txt"
#define fileStudentPass "BaiTapKTLTStudentPass.txt"
#define fileAdminPass   "BaiTapKTLTAdminPass.txt"
#define fileHopThuDenCuaAdmin   "BaiTapKTLTHopThuDenCuaAdmin.txt"
#define fileHopThuDenCuaStudent "BaiTapKTLTHopThuDenCuaStudent.txt"
#define fileGuiThuCuaAdmin      "BaiTapKTLTGuiThuCuaAdmin.txt"
#define fileGuiThuCuaStudent    "BaiTapKTLTGuiThuCuaStudent.txt"

int StudentAmount;
int Direction;
string AdminPass;
string AdminPass2;
string ThongBaoChung;
int ComeBack;
int MessAmount;
int Language = 1;

HANDLE hStdin;

struct Transcript                             // Bang diem
{
	string ClassCode;                       // Ma lop
	string StudentCode;                     // Ma HV
	string StudentName;                     // ten HV
	string StudentPass;                   // Mat khau tai khoan
	int Day;                              // Ngay thang nam sinh
	int Month;
	int Year;
	float DTBTL;                           // diem TB tich luy
	string HocLuc;                         // Hoc luc
	string ThuDen;
	string ThuGui;
};

// Buoc 1: Khai bao cau truc du lieu danh su dung sach lien ket
struct Node                                  // Khai bao Node
{
	Transcript data;
	struct Node *Next;
	//struct Node *Previous;
};

struct List                                  // Khai bแo List
{
	Node *Head;
	Node *Tail;
};

struct HopThuDenAdmin
{
	string StudentCode;
	string ThuDen;
};

Transcript Member;
HopThuDenAdmin Object;

struct Node2
{
	Transcript data;
	struct Node2 *Next;
	struct Node2 *Previous;
};

struct List2
{
	Node2 *Head;
	Node2 *Tail;
};

struct STRING
{
	string str;
};

struct Frame // Khung hinh console
{
	int X_high;
	int X_low;
	int Y_high;
	int Y_low;
};

//Estimate  Uoc tinh
void resizeConsole(int width,int height)       // Ham thay doi kich co khung cmd voi tham so truyen vao la chieu rong va chieu cao ( mac  dinh ngang 80 dong, dai 400)
{
	HWND console = GetConsoleWindow();
	RECT r; 
	GetWindowRect(console, &r); // Lay ve kich thuoc vung cua cua so
	MoveWindow(console, r.left,r.top,width,height,TRUE);
}


void gotoxy(int x,int y)                      // Ham dich chuyen con tro den toa do x,y (io, window, conio)
{
	HANDLE hConsoleOuput;
	COORD Cursor_an_Pos = {x-1,y-1};
	hConsoleOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOuput, Cursor_an_Pos);
	//GetConsoleCursorInfo();
}

void textcolor(int x)                        // Khi goi ham nay tat ca Output phia sau se bi thay doi mau (255 mเu)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}

void XoaConTro()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}

void HienConTro()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = TRUE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
//==============================================================================================================================//==============================================================================================================================
//==============================================================================================================================//==============================================================================================================================
//==============================================================================================================================//==============================================================================================================================
//==============================================================================================================================//==============================================================================================================================
//==============================================================================================================================//==============================================================================================================================
//==============================================================================================================================//==============================================================================================================================
//==============================================================================================================================//==============================================================================================================================
void ToMau(int x,int y,string str,int color1)  // Ham nay dung de to mau cho 1 doan code o toa do (x,y)
{
	gotoxy(x,y);        // dua con tro toi vi tri (x,y)
	textcolor(color1);   // setcolor cho no
	cout<<str;            // in ra dong ki tu voi mau chi dinh
}

void ToMauChar(int x,int y,char str,int color1)  // Ham nay dung de to mau cho 1 doan code o toa do (x,y)
{
	gotoxy(x,y);        // dua con tro toi vi tri (x,y)
	textcolor(color1);   // setcolor cho no
	cout<<str;            // in ra dong ki tu voi mau chi dinh
}


void ToMauInt(int x,int y,int a,int color)
{
	gotoxy(x,y);
	textcolor(color);
	ostringstream convertInt;
	convertInt<<a;
	string result = convertInt.str();
	cout<<result;
}

void ToMauFloat(int x,int y,float a,int color)
{
	gotoxy(x,y);
	textcolor(color);
	ostringstream convertFloat; // ostringstream de chuyen sang output la string
	convertFloat<<a;
	string result = convertFloat.str(); // convert
	cout<<result;
}

void Gan(Transcript &a, Transcript &b) // Gan bang diem
{
	a.ClassCode   = b.ClassCode;
	a.Day         = b.Day;
	a.Month       = b.Month;
	a.Year        = b.Year;
	a.DTBTL       = b.DTBTL;
	a.HocLuc      = b.HocLuc;
	a.StudentCode = b.StudentCode;
	a.StudentName = b.StudentName;
	a.StudentPass = b.StudentPass;
	a.ThuDen      = b.ThuDen;
	a.ThuGui      = b.ThuGui;
}




char ComeIn(char c)
{
	if(c==' ') return '@';
	if(c=='a') return 'b';
	if(c=='b') return 'c';
	if(c=='c') return 'd';
	if(c=='d') return 'e';
	if(c=='e') return 'f';
	if(c=='f') return 'g';
	if(c=='g') return 'h';
	if(c=='h') return 'i';
	if(c=='i') return 'j';
	if(c=='j') return 'k';
	if(c=='k') return 'l';
	if(c=='l') return 'm';
	if(c=='m') return 'n';
	if(c=='n') return 'o';
	if(c=='o') return 'p';
	if(c=='p') return 'q';
	if(c=='q') return 'r';
	if(c=='r') return 's';
	if(c=='s') return 't';
	if(c=='t') return 'u';
	if(c=='u') return 'v';
	if(c=='v') return 'w';
	if(c=='w') return 'x';
	if(c=='x') return 'y';
	if(c=='y') return 'z';
	if(c=='z') return 'a';
	
	if(c=='A') return 'B';
	if(c=='B') return 'C';
	if(c=='C') return 'D';
	if(c=='D') return 'E';
	if(c=='E') return 'F';
	if(c=='F') return 'G';
	if(c=='G') return 'H';
	if(c=='H') return 'I';
	if(c=='I') return 'J';
	if(c=='J') return 'K';
	if(c=='K') return 'L';
	if(c=='L') return 'M';
	if(c=='M') return 'N';
	if(c=='N') return 'O';
	if(c=='O') return 'P';
	if(c=='P') return 'Q';
	if(c=='Q') return 'R';
	if(c=='R') return 'S';
	if(c=='S') return 'T';
	if(c=='T') return 'U';
	if(c=='U') return 'V';
	if(c=='V') return 'W';
	if(c=='W') return 'X';
	if(c=='X') return 'Y';
	if(c=='Y') return 'Z';
	if(c=='Z') return 'A';
	
	if(c=='0') return '3';
	if(c=='1') return '4';
	if(c=='2') return '5';
	if(c=='3') return '6';
	if(c=='4') return '7';
	if(c=='5') return '8';
	if(c=='6') return '9';
	if(c=='7') return '0';
	if(c=='8') return '1';
	if(c=='9') return '2';
	
	if(c=='?') return '/';
	if(c=='/') return '?';
	if(c=='>') return '.';
	if(c=='<') return ',';
	if(c=='.') return '>';
	if(c==',') return '<';
	if(c==':') return ';';
	if(c==';') return ':';	
	
	if(c=='!') return '#';
	if(c=='#') return '!';
	if(c=='$') return '%';
	if(c=='%') return '$';
}

char GoOut(char c)
{
	if(c=='b') return 'a';
	if(c=='c') return 'b';
	if(c=='d') return 'c';
	if(c=='e') return 'd';
	if(c=='f') return 'e';
	if(c=='g') return 'f';
	if(c=='h') return 'g';
	if(c=='i') return 'h';
	if(c=='j') return 'i';
	if(c=='k') return 'j';
	if(c=='l') return 'k';
	if(c=='m') return 'l';
	if(c=='n') return 'm';
	if(c=='o') return 'n';
	if(c=='p') return 'o';
	if(c=='q') return 'p';
	if(c=='r') return 'q';
	if(c=='s') return 'r';
	if(c=='t') return 's';
	if(c=='u') return 't';
	if(c=='v') return 'u';
	if(c=='w') return 'v';
	if(c=='x') return 'w';
	if(c=='y') return 'x';
	if(c=='z') return 'y';
	if(c=='a') return 'z';
	
	if(c=='B') return 'A';
	if(c=='C') return 'B';
	if(c=='D') return 'C';
	if(c=='E') return 'D';
	if(c=='F') return 'E';
	if(c=='G') return 'F';
	if(c=='H') return 'G';
	if(c=='I') return 'H';
	if(c=='J') return 'I';
	if(c=='K') return 'J';
	if(c=='L') return 'K';
	if(c=='M') return 'L';
	if(c=='N') return 'M';
	if(c=='O') return 'N';
	if(c=='P') return 'O';
	if(c=='Q') return 'P';
	if(c=='R') return 'Q';
	if(c=='S') return 'R';
	if(c=='T') return 'S';
	if(c=='U') return 'T';
	if(c=='V') return 'U';
	if(c=='W') return 'V';
	if(c=='X') return 'W';
	if(c=='Y') return 'X';
	if(c=='Z') return 'Y';
	if(c=='A') return 'Z';
	
	if(c=='0') return '7';
	if(c=='1') return '8';
	if(c=='2') return '9';
	if(c=='3') return '0';
	if(c=='4') return '1';
	if(c=='5') return '2';
	if(c=='6') return '3';
	if(c=='7') return '4';
	if(c=='8') return '5';
	if(c=='9') return '6';
	
	if(c=='?') return '/';
	if(c=='/') return '?';
	if(c=='.') return '>';
	if(c==',') return '<';
	if(c=='>') return '.';
	if(c=='<') return ',';
	if(c==':') return ';';
	if(c==';') return ':';
	if(c=='@') return ' ';
	
	if(c=='!') return '#';
	if(c=='#') return '!';
	if(c=='$') return '%';
	if(c=='%') return '$';
}


string Encrypt(string str)     // Ma hoa du lieu dau vao
{
	int n = str.length();
	string mahoa="";
	
	for(int i=0; i<n ;i++)
	    mahoa += ComeIn(str[i]);
	
	return mahoa;
}

string Decrypt(string str)    // Giai ma du lieu trong database
{
	int n = str.length();
	string giaima="";
	
	for(int i=0; i<n ;i++)
	    giaima += GoOut(str[i]);
	
	return giaima;
}



int PASSADMIN(string str)
{	
	if(str == AdminPass)
	   return 1;
	else 
	   return 0;
}

int PASSADMIN2(string str)
{
	if(str == AdminPass2)
	   return 1;
	else 
	   return 0;
}

int USERADMIN(string str)
{
	if(str == "quantrivien")
	   return 1;
	else 
		return 0;
}

int KiemTraPass2()
{
	int test = -3; // kiem tra mat khau cho phep nhap 3 lan
a:	if(test == 0)
	    return 0;
	
	ToMau(32,35,"ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป",4);
	ToMau(32,36,"บ                                                                          บ",4);
	ToMau(32,37,"ศออออออออออออออออออออออออออออออออออออออo0oอออออออออออออออออออออออออออออออออผ",4);
	
	ToMau(34,36,"Nhap mat khau cap 2: ",14);
	string str;
	gotoxy(55,36);
	textcolor(255);
	cin>>str;
	
	if(PASSADMIN2(str) == 1)
	{
	  	return 1;
	}
	else{
	 	test ++;
	 	goto a;
	}	   
}

// Buoc 2: Khoi tao danh sach lien ket
void Init(List &l)
{
	l.Head=l.Tail=NULL;                     // Khoi tao phan tu dau va cuoi = NULL
}

// Buoc 3: Tao Node trong danh sach lien ket
Node *GetNode(Transcript Data)
{
	Node *p = new Node();                        // cap phat bo nho cho con tro p
	if(p==NULL)
	{
	  	printf("Khong du bo nho de cap phat con tro!");
	  	return NULL;                           // Tra ve rong
	}
	  
	p->data.ClassCode   = Data.ClassCode;                            // Dua data vเo trong Node
	p->data.Day         = Data.Day;                           
	p->data.Month       = Data.Month;                           
	p->data.Year        = Data.Year;                            
	p->data.DTBTL       = Data.DTBTL;                            
	p->data.HocLuc      = Data.HocLuc;                           
	p->data.StudentName = Data.StudentName;                          
	p->data.StudentCode = Data.StudentCode;                            
	p->data.StudentPass = Data.StudentPass;
	p->data.ThuDen      = Data.ThuDen;
	p->data.ThuGui      = Data.ThuGui;
	
	p->Next = NULL;                           // Khoi tao moi lien ket
	//p->Previous = NULL;
	return p;                                  // tra ve node p
}


void AddHead(List &l,Transcript x)
{
	Node *p = GetNode(x);
	if(l.Head == NULL)
	{
	  	l.Head = l.Tail = p;
	}
	else{
	 	p->Next = l.Head;
	 	l.Head = p;
	}
}


void AddTail(List &l,Transcript x)                // Them vao cuoi danh sach
{
	Node *p = GetNode(x);
	if(l.Head == NULL)
	{
		l.Head = l.Tail = p;               // Neu danh sach rong thi add luon
	}
	else{
		l.Tail->Next = p;                  // Con tro cua phan tu cuoi tro vao p
		l.Tail = p;                         // Cap nhat lai cuoi danh sach
	}
}


// Xoa phan tu dau
void DelHead(List &l)
{
	if(l.Head==NULL) 
	   cout<<"Ko co phan tu nao de xoa";
	else{
		Node *p=l.Head;
		l.Head=l.Head->Next;
		delete p;
	}
}


// Xoa phan tu cuoi
void DelTail(List &l)
{
	if(l.Head==NULL) 
	   cout<<"Ko co phan tu nao de xoa";
	else{
		Node *g;
		for(Node *p=l.Head ; p!=NULL ; p=p->Next)
		{
		   	if(p==l.Tail)
		   	{		   	  	
		   	  	l.Tail=g;
		   	  	g->Next=NULL;
		   	  	delete p;
			}
			g=p;
		}
	}
}



void GuiThuChoStudent(List &l,Transcript Member,string str);
void GuiThuChoAdmin(List &l,Transcript Member,string message);
/*--------------------------------------------------------------------------------------*/

#endif
