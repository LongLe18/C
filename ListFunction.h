#ifndef BAITAPKTLTUSELISTFUNCTION_H
#define BAITAPKTLTUSELISTFUNCTION_H



#include "ListPrint.h"

#define file            "BaiTapKTLT.txt"
#define fileStudentName "BaiTapKTLTStudentName.txt"
#define fileStudentPass "BaiTapKTLTStudentPass.txt"
#define fileAdminPass   "BaiTapKTLTAdminPass.txt"
#define fileHopThuDenCuaAdmin   "BaiTapKTLTHopThuDenCuaAdmin.txt"
#define fileHopThuDenCuaStudent "BaiTapKTLTHopThuDenCuaStudent.txt"
#define fileGuiThuCuaAdmin      "BaiTapKTLTGuiThuCuaAdmin.txt"
#define fileGuiThuCuaStudent    "BaiTapKTLTGuiThuCuaStudent.txt"
#define fileFoolPeople          "BaiTapKTLTFoolPeople.txt"

// Duoc dinh nghia o "ListRoot.h"
void AddHead(List &l,Transcript);
void AddTail(List &l,Transcript);
void DelHead(List &l);
void DelTail(List &l);
void Init(List &l); 


int PASSADMIN(string str);
int USERADMIN(string str);   
void ReadAdminPass();                                   

string Encrypt(string);
string Decrypt(string);
char ComeIn(char);
char GoOut(char);

void AddToListFromFile(List &l);               // Tao ma hoc vien
void TaskForFoolPeople(List &l);
void MENUforMember(List &l,Transcript Member); // Menu sv



/*-----------------------------------------------------------------------------------------*/
//==============================================================================================================================//==============================================================================================================================
//==============================================================================================================================//==============================================================================================================================
//==============================================================================================================================//==============================================================================================================================
//==============================================================================================================================//==============================================================================================================================
//==============================================================================================================================//==============================================================================================================================
//==============================================================================================================================//==============================================================================================================================



void ReadAdminPass() // Doc PassAdmin tu BaiTapKTLTAdminPass.txt
{
	ifstream fileInput(fileAdminPass);
	
	getline(fileInput,AdminPass);	// Gan AdminPass = du lieu trong fileInput (ten dan nhap)
	AdminPass = Decrypt(AdminPass); // Decode user ( vi pass da dc ComeIn)
	int m = AdminPass.length();
	while(AdminPass[m-1] == ' ')              // Xu li du lieu tu file, xoa dau " "
	{
	    AdminPass.erase(AdminPass.begin()+m-1); 
	    m = AdminPass.length();
	}
		 
	getline(fileInput,AdminPass2); // Gan AdminPass2 = du lieu trong fileInput (mat khau
	AdminPass2 = Decrypt(AdminPass2); // Decode pass
	int n = AdminPass2.length();
	while(AdminPass2[m-1] == ' ')              // Xu li du lieu tu file, xoa dau " "
	{
	    AdminPass2.erase(AdminPass2.begin()+m-1);
	    m = AdminPass2.length();
	}
	
	fileInput.close();
}



//==============================================================================================================================
//==============================================================================================================================

void ChuanHoaCode(string &str)
{
	while(str[0] == ' ')             
	    str.erase(str.begin());
	
	int m = str.length();
	while(str[m-1] == ' ')              // Xu li du lieu tu file, xoa dau " " sau ten
	{
	    str.erase(str.begin()+m-1);
	    m = str.length();
	}
		 
	for(int i=0 ; i<str.length() ; i++)
		str[i] = toupper(str[i]);
}

string CreateStudentPassAuto(string Name,int Day,int Month)
{
	string StudentPass = "";
	int m = Name.length();
	while(Name[m-1] == ' ')              // xoa dau " " neu co
	{
	    Name.erase(Name.begin()+m-1);
	    m = Name.length();
	}
	for(int i=0;i<m;i++)
	   	if(Name[i] == ' ')
	   	   	Name.erase(Name.begin()+i);    // Xoa " "
	
		 
	StudentPass += Name;      // Cong Name da dc xu li vao PassAuto
	
	ostringstream convertDay, convertMonth;
	convertDay<<Day;
	convertMonth<<Month;
	if(Day<10)
	   	StudentPass += '0';
	StudentPass += convertDay.str();
	if(Month<10)
	   	StudentPass += '0';
	StudentPass += convertMonth.str();
	
	
	return StudentPass;
}

void AddToListFromFile(List &l)
{
    
    Transcript One; // bang diem "ListRoot.h"
	ifstream fileInput1(file);
	ifstream fileInput2(fileStudentName);
	ifstream fileInput3(fileStudentPass);
	ifstream fileInput4(fileGuiThuCuaStudent);
	ifstream fileInput5(fileHopThuDenCuaStudent);
    
    int i = 0;
	while(!fileInput1.eof() or !fileInput2.eof())
	{	
		if(fileInput1.eof() or fileInput2.eof()) break;
		fileInput1>>One.ClassCode;
		fileInput1>>One.StudentCode;
		fileInput1>>One.Day;
		fileInput1>>One.Month;
		fileInput1>>One.Year;
		fileInput1>>One.DTBTL;	
		
	    getline(fileInput2,One.StudentName);
	    One.StudentName = Decrypt(One.StudentName);
	    
		int m = One.StudentName.length();
		while(One.StudentName[m-1] == ' ')              // Xu li du lieu tu file, xoa dau " "
	    {
	        One.StudentName.erase(One.StudentName.begin()+m-1);
	        m = One.StudentName.length();
		}
		 
		getline(fileInput3,One.StudentPass);
		One.StudentPass = Decrypt(One.StudentPass);
	
		int n = One.StudentPass.length();
		while(One.StudentPass[n-1] == ' ')              // Xu li du lieu tu file, xoa dau " "
		    {
		        One.StudentPass.erase(One.StudentPass.begin()+n-1);
		        n = One.StudentPass.length();
			}
		 	
		// Doc vao du lieu Thu gui den va Thu gui di  
		getline(fileInput4,One.ThuGui);
		One.ThuGui = Decrypt(One.ThuGui);
		
		getline(fileInput5,One.ThuDen);
		One.ThuDen = Decrypt(One.ThuDen);
			  
	    if(One.DTBTL >= 3.6)
		   	One.HocLuc = "Xuat Sac";
		else
	    	if(One.DTBTL >= 3.2)
	        	One.HocLuc = "Gioi";
			else{
			  	if(One.DTBTL >= 2.5) One.HocLuc = "Kha";
			  	else{
			  	 	if(One.DTBTL >=2.0)
			  	 		One.HocLuc = "TB";
			  	 	else
			  	 		One.HocLuc = "Yeu";
				    }
		    }
		  
		i++;
		
		AddTail(l,One);	
	}
	
    DelTail(l);
    StudentAmount = i-1;
    
	fileInput1.close();	
	fileInput2.close();
	fileInput3.close();
	fileInput4.close();
	fileInput5.close();
}

void LogIn(List &l)
{
	int wrong = 0;
	int temp = 0;
	string PASS;
	string NAME;
	
a:  textcolor(14);
	
    cout<<"\n\n\n";
    ToMau(15, 4, "²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²", 2);
    ToMau(15, 5, "²ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍo0oÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»²                           ²²²²²²²²²²²²²²²²²²²", 2);
    ToMau(15, 6, "²º                   DANG NHAP TAI KHOAN                  º²                           ²ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»²", 2);
    ToMau(15, 7, "²ÌÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¹²                           ²º               º²", 2);
    ToMau(15, 8, "²º               :                                        º²                           ²º      DANG     º²", 2);
    ToMau(15, 9, "²ÇÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¶²                           ²º      NHAP     º²", 2);
    ToMau(15, 10, "²º               :                                        º²                           ²º               º²", 2);
    ToMau(15, 11, "²ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍo0oÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼²                           ²ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼²", 2);
    ToMau(15, 12, "²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²                           ²²²²²²²²²²²²²²²²²²²", 2);
    
//    cout<<"              ²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²\n";
//    cout<<"              ²ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍo0oÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»²                           ²²²²²²²²²²²²²²²²²²²\n";
//    cout<<"              ²º                    DANG NHAP TAI KHOAN                 º²                           ²ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»²\n";
//    cout<<"              ²ÌÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¹²                           ²º               º²\n";
//    cout<<"              ²º               :                                        º²                           ²º      DANG     º²\n";                                             
//	cout<<"              ²ÇÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¶²                           ²º      NHAP     º²\n";
//	cout<<"              ²º               :                                        º²                           ²º               º²\n";
//	cout<<"              ²ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍo0oÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼²                           ²ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼²\n";
//	cout<<"              ²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²                           ²²²²²²²²²²²²²²²²²²²";
	
	ToMau(36,6,"DANG NHAP TAI KHOAN",12);
	ToMau(102,14,"²²²²²²²²²²²²²²²²²²²",14);
    ToMau(102,15,"²ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»²",14);
    ToMau(102,16,"²º               º²",14);                                             
	ToMau(102,17,"²º     THOAT     º²",14);
	ToMau(102,18,"²º  CHUONG TRINH º²",14);
	ToMau(102,19,"²º               º²",14);
	ToMau(102,20,"²ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼²",14);
	ToMau(102,21,"²²²²²²²²²²²²²²²²²²²",14);
	
	ToMau(102, 5,"²²²²²²²²²²²²²²²²²²²",2);
    ToMau(102, 6,"²                 ²",2);
    ToMau(102, 7,"²                 ²",2);                                             
	ToMau(102, 8,"²                 ²",2);
	ToMau(102, 9,"²                 ²",2);
	ToMau(102,10,"²                 ²",2);
	ToMau(102,11,"²                 ²",2);
	ToMau(102,12,"²²²²²²²²²²²²²²²²²²²",2);
	
	ToMau(102,14,"²²²²²²²²²²²²²²²²²²²",4);
    ToMau(102,15,"²                 ²",4);
    ToMau(102,16,"²                 ²",4);                                             
	ToMau(102,17,"²                 ²",4);
	ToMau(102,18,"²                 ²",4);
	ToMau(102,19,"²                 ²",4);
	ToMau(102,20,"²                 ²",4);
	ToMau(102,21,"²²²²²²²²²²²²²²²²²²²",4);
	
	ToMau(17,8,"Ten nguoi dung",14);
	ToMau(20,10,"Mat Khau",14);	
	
	ToMau(10,30,"Made By: ",12);
	ToMau(19,30,"Le Ngoc Long ~ CNTT2",11);
	ToMau(10,31,"Email: ",12);
	ToMau(17,31,"long9a11to3@gmail.com",11);
	
	ToMau(55,14,"Quen mat khau! Help!",10);
	gotoxy(1,1);
	XoaConTro();
	//PrintFrame(11);
	
	int choose;
	int kt = 0;
	
c:	textcolor(7);
    if(wrong == 4)       // dem so lan sai
    {
      	gotoxy(10,15);
      	textcolor(15);
      	cout<<"OUT!";
      	exit(0);
	}
    choose = MouseEventToButtonForLogIn(695,150,160,130,  695,150,191,161, 950,815, 195,110  ,950,815,350,265,  590,430,260,240   ); // (5 Muc)
	
	if(choose == 1) // Click vao ten nguoi dung
	{
		ToMau(34,8,"                             ",0);
		gotoxy(0,0);
	    gotoxy(34,8);
		  
		HienConTro();  
		textcolor(15);
		fflush(stdin);
		getline(cin,NAME); 
		fflush(stdin);
		goto c;
    }
    
    if(choose == 2) // CLick vao mat khau
    {
	    ToMau(34,10,"                             ",0);
	    gotoxy(34,10);
		  
		HienConTro();  
		fflush(stdin);
		gotoxy(34,10);
		textcolor(255);
		cin>>PASS;
		goto c;
	}
	
	if(choose == 3) // click vao dang nhap
	{
		if(USERADMIN(NAME) == 1 and PASSADMIN(PASS) == 1)     // Neu nhap mat khau Dung Admin
	   		Direction = 2;
		else // Neu nhap mat khau or user ADMIN sai thi kiem tra student
		{	   
	    	for (Node *p=l.Head ; p!=NULL ; p=p->Next)
	   	    	if (NAME == p->data.StudentName) // Ten dang nhap = ten sv trong data
	   	      		if (PASS == p->data.StudentPass) // pass dang nhap = pass sv trong data
	   	        	{
		   	        	Gan(Member,p->data);
		   	        	temp = 1;
		   	        	break;
					}
	   
		    if(temp == 1)  // Tai khoan va mat khau STUDENT dung
		      	Direction = 1;      
		    else // Nhap sai  
			{	      
		      	ToMau(20,20,"TAI KHOAN KHONG TON TAI. VUI LONG DANG NHAP LAI!",12);
		      	Sleep(1000);
		      	ToMau(20,20,"                                                ",12);
			  	textcolor(15);
			  	wrong++;	// Tang so lan sai		  
		      	goto c;
		    }        
    	}
	}
   
   
   if(choose == 4)  //  click Thoat
    {
        PrintEmpty();
        End();
	    exit(0);
	}
   
   if(choose == 5)  // click Quen mat khau
    {
     	textcolor(7);     	
     	TaskForFoolPeople(l);
     	goto a;
	}
      
}

void TaskForFoolPeople(List &l)
{
	string maHV;
	int kt = 0;
	
a:	int choose = MouseEventForFoolPeople(730,395,335,265,  890,750,330,245,  1045,910,190,110, maHV); // (3 muc)
	
	
	if(choose == 1) //  Chon vao o nhap
	{
		textcolor(7);
		ToMau(65,17,"                      ",7);
		gotoxy(65,17);
		cin>>maHV;
		for(Node *p=l.Head ; p!=NULL ; p=p->Next )
		{
			if(maHV == p->data.StudentCode) // Kiem tra ma sv tu danh sach (file BaiTapKTLT.txt)
			{
			  	kt = 1;
			  	
			  	int x = 0;
			  	ifstream fileInput(fileFoolPeople);
			  	
			  	int i=1;
			  	while(!fileInput.eof())
			  	{
				  	string str;
				  	getline(fileInput,str);
				  	
				  	if(str == maHV)
				  	{
					  	PrintEmpty();	
					  	x=1;
					  	break;
					}
				}
				
			  	if(x == 0) // Neu chua co ma sv trong file FoolPeople.txt 
			  	{
				  	fileInput.close();
				  	
		            ofstream fileOutput; // ghi ra file FoolPeople.txt  	
	                fileOutput.open(fileFoolPeople,ios::app);
	     	        
	     	        fileOutput<<maHV<<"\n";
	                fileOutput.close();
				   	break;	
				}			  	
			}
		}
		
	goto a;
	}
	if(choose == 2)
	{
		if(kt == 0)
		{
			ToMau(95,20,"Ma hoc vien khong ton tai!",12);
			Sleep(1000);
			ToMau(95,20,"                          ",7);
			goto a;
		}
		else{
			
			PrintEmpty();
			ToMau(45,17,"ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿",5);
			ToMau(45,18,"³- Da gui thanh cong cho quan tri vien!...                                                       ³",14);
			ToMau(45,20,"³- De nghi Dong chi len phong quan tri vien de nhan lai thong tin Tai khoan tai P415, toa S11... ³",14);
			ToMau(45,22,"³- Dong chi mang theo The hoc vien de xac nhan va 50.000 VND le phi!...                          ³",14);
			ToMau(45,24,"³- Lan sau Dong chi nho rut kinh nghiem, khong nen de mat Tai khoan!...                          ³",14);
			ToMau(45,26,"³- Xin tran trong cam on!                                                                        ³",14);
			ToMau(45,28,"³                                                                   - Ban Quan Tri -             ³",6);
			ToMau(45,29,"ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ",5);
		
			for(int i=18 ; i<=28 ; i++)
			{
				   	ToMau(45,i,"³",5);
				   	ToMau(142,i,"³",5);
			}
		
			int choose1 = MouseEventToButtonBack(1040,910,200,110);
		
			if(choose1 == 1) return;
		
		}
	}
	
	if(choose == 3)
	{
		return;
	}
}



//==============================================================================================================================//==============================================================================================================================
//==============================================================================================================================
//==============================================================================================================================//==============================================================================================================================
//==============================================================================================================================
//==============================================================================================================================
//==============================================================================================================================

void GuiThuChoStudent(List &l,Transcript Member,string str)
{
	
	ofstream fileOutput1;
	ofstream fileOutput2;
	
	fileOutput1.open(fileGuiThuCuaAdmin,ios::out);
	fileOutput2.open(fileHopThuDenCuaStudent,ios::out);
	
	for(Node *p=l.Head ; p!=NULL ; p=p->Next)
	   {
	   	if(p->data.StudentCode != Member.StudentCode)
	   	  {
	   	  	fileOutput1<<Encrypt(p->data.StudentCode)<<"\n";
	   	  	fileOutput1<<Encrypt(p->data.ThuDen)<<"\n";
	   	  	fileOutput2<<Encrypt(p->data.ThuDen)<<"\n";
		  }
		else
		  {
		  	p->data.ThuDen = str;
		  	fileOutput1<<Encrypt(p->data.StudentCode)<<"\n";
	   	  	fileOutput1<<Encrypt(p->data.ThuDen)<<"\n";
	   	  	fileOutput2<<Encrypt(p->data.ThuDen)<<"\n";
	   	  	break;
		  }
	   }
	
	fileOutput1.close();
	fileOutput2.close();
}

void HopThuDenCuaStudent(List &l,Transcript Member)
{
	//PrintEmpty();
	
	for(Node *p=l.Head ; p!=NULL ; p=p->Next)
	    if(p->data.StudentCode == Member.StudentCode)
	    {
	      	Member.ThuDen = p->data.ThuDen;
	      	break;
		}
	
	ToMau(30,12,"ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»",2);
	ToMau(30,13,"º                                                        º",2);
	ToMau(30,14,"ÌÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¹",2);
	ToMau(30,15,"º                                                        º",2);
	ToMau(30,16,"º                                                        º",2);
	ToMau(30,17,"º                                                        º",2);
	ToMau(30,18,"º                                                        º",2);
	ToMau(30,19,"º                                                        º",2);
	ToMau(30,20,"º                                                        º",2);
	ToMau(30,21,"ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼",2);
	
	ToMau(55,13,"BAN QUAN TRI",14);
	
	if(Member.ThuDen == "" or Member.ThuDen == " ")
	   ToMau(60,18,"(rong)",7);
	int i=0;
	int x=32;
	int y=15;
	while(i <= Member.ThuDen.length() )
	{
	    if(x == 85)
	    {
	     	x = 32;
	     	y++;
		}
	    ToMauChar(x++,y,Member.ThuDen[i],15);
	    i++;
	}
		 
	getch();
}

void GuiThuChoAdmin(List &l,Transcript Member,string message)
{
	
	ToMau(40,30,"Ban co muon gui khong: ",14);
	int luachon;
	ToMau(40,31,"Nhap lua chon: ",14);
	cin>>luachon;
	
	if(luachon == 1)
	{
	  	MessAmount ++;
	  	ofstream fileOutput1;
	  	ofstream fileOutput2;
	  	
	  	fileOutput1.open(fileGuiThuCuaStudent,ios::out);
	  	fileOutput2.open(fileHopThuDenCuaAdmin,ios::out);
	  	
	  	for(Node *p=l.Head ; p!=NULL ; p=p->Next )
	  	{
	  	   	if(p->data.StudentCode != Member.StudentCode)
	  	   	{
	  	   	  	fileOutput1<<Encrypt(p->data.ThuGui)<<"\n";
	  	   	  	fileOutput2<<Encrypt(p->data.StudentCode)<<"\n";
	  	   	  	fileOutput2<<Encrypt(p->data.ThuGui)<<"\n";
			}
	  	   	if(p->data.StudentCode == Member.StudentCode) 
	        {
	      	    p->data.ThuGui = message;                          
	      	    fileOutput1<<Encrypt(p->data.ThuGui)<<"\n";
	      	    fileOutput2<<Encrypt(p->data.StudentCode)<<"\n";
	      	    fileOutput2<<Encrypt(p->data.ThuGui)<<"\n";
		    }
		}
		fileOutput1.close();    
		fileOutput2.close();    
	}
	if(luachon == 2)
	   return ; 
		
}

void HopThuDenCuaAdmin(List &l, HopThuDenAdmin Array[])
{
	ifstream fileInput;
	fileInput.open(fileHopThuDenCuaAdmin);
	int i=1;
	
	while(!fileInput.eof())
	    {
	     	getline(fileInput,Object.StudentCode);
	     	Object.StudentCode = Decrypt(Object.StudentCode);  // giai ma StudentCode trong file
	     	getline(fileInput,Object.ThuDen);
	     	Object.ThuDen = Decrypt(Object.ThuDen);            // giai ma Thu trong file
	     	
	     	int m = Object.ThuDen.length();
	        while(Object.ThuDen[m-1] == ' ')              // xoa dau " " neu co
	        {
	            Object.ThuDen.erase(Object.ThuDen.begin()+m-1);
	            m = Object.ThuDen.length();
		    }
		    if(!Object.ThuDen.empty())
		    {
		      	Array[i].StudentCode = Object.StudentCode;
		      	Array[i].ThuDen = Object.ThuDen;
		      	i++;
			}
		       //cout<<" - "<<Object.StudentCode<<" : "<<Object.ThuDen<<"\n";
		}
	fileInput.close();
	
}

void ReSetStudentPass(List &l)
{
	ofstream fileOuput;
	fileOuput.open(fileStudentPass,ios::out);
	
	for(Node *p=l.Head ; p!=NULL ; p=p->Next)
	{
		string str = CreateStudentPassAuto(p->data.StudentName,p->data.Day,p->data.Month);
		fileOuput<<Encrypt(str)<<"\n";
	}
	fileOuput.close();
}



#endif
