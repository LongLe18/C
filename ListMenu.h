
#ifndef BAITAPKTLTUSELISTMENU_H
#define BAITAPKTLTUSELISTMENU_H

#include "ListFunction.h"

void MENUforMember(List &l,Transcript Member)
{
	textcolor(7);
	PrintEmpty();
	
    
a:  while(true)
         {
         	textcolor(7);
         	PrintEmpty();
         	gotoxy(30,2);
         	textcolor(14);
         	cout<<"ษออออออออออออออออออออออออออออออออออออป";
	        gotoxy(30,3);
	        cout<<"บ~  Xin Chao, "<<setw(21)<<setfill('.')<<Member.StudentName<<" ~บ";
	        ToMau(30,4,"ศออออออออออออออออออออออออออออออออออออผ",14);
	        ToMau(90,3,"Made By: ",12);
	     	ToMau(99,3,"Le Ngoc Long ~ CNTT2",11);
	     	ToMau(90,4,"Email: ",12);
	     	ToMau(97,4,"long9a11to3@gmail.com",11);

	        XoaConTro();
	        
	        // In ra thong bao chung cua quan tri vien
	        //PrintThongBaoChung();
	        
	        int luachon;
	        
	        // Su kien chuot cho menu student
	        luachon = MouseEventToButtonOfMenuForMember(700,130,150,110,    700,130,200,160,   700,130,250,210,  700,130,300,260,  700,130,350,310);
	        
	        // Xem thong tin ca nhan /////////////////////////////////////////////////////////////////////////////////////////////
	        if(luachon == 1) 
	        {
	          	PrintEmpty();
	          	//PrintOneTranscript(Member);
	          	int x = MouseEventToButtonBack(1040,910,185,95); // click vao button "QUAY LAI"
	          	if(x == 1)
	          	  	{
	          	  		textcolor(7);
	          	  	 	goto a;
					}
	          	
			}
			// Xem TIn nhan cua Ban Quan Tri//////////////////////////////////////////////////////////////////////////////////////
		    if(luachon == 2)
		    {
		      	HopThuDenCuaStudent(l,Member); // Ket thuc ham nay dang co getch() => bam phim bat gi
		      	int x = MouseEventToButtonBack(1040,910,185,95); // => click vao 'QUAY LAI'
	          	if(x == 1) // 
	          	   goto a;
			}
			// Gui y kien cho ban quan tri ////////////////////////////////////////////////////////////////////////////////////////
			if(luachon == 3)
			{
			  	//GuiTinNhanChoQuanTriVien(l,Member);
			}
			// Doi mat khau ///////////////////////////////////////////////////////////////////////////////////////////////////////  
			if(luachon == 4)
			{
f:			  	int wrong = 0;
			  	int kt = 0;
					
			  	gotoxy(42,15);
			    cout<<"                                   ";
			    gotoxy(42,17);
			    cout<<"                                   ";
				gotoxy(42,19);
			    cout<<"                                   ";
			    
			  	string OldPass;
			  	string NewPass1;
			  	string NewPass2;
			  	PrintChangePass(); // GIao dien
			  	
f1:             int x = MouseEventToSelectChangePass(695,130,420,290,   945,820,195,105,   945,820,490,400);
                
                if(x == 1) // cac dong nhap.
                {
                
			    	do{ 
						textcolor(221);
			      		if(wrong == 3)
			        	{	
				    		textcolor(7);
							goto a;
						}
				 		gotoxy(42,16);
			      		cin>>OldPass;
			      		if(OldPass != Member.StudentPass)                       // Nhap mat khau cu
			        	{
				        	ToMau(94,16,"! Nhap Sai (qua 3 lan se Huy)",4);
				        	textcolor(7);
				        	gotoxy(42,16);
				        	cout<<"                                   ";
				        	wrong++;
						}
				   		else{
				   			ToMau(94,16,"                              ",4);
				   			ToMau(94,16,"๛ Hoan thanh",10);
				   		}
					} while(OldPass != Member.StudentPass);  // mat khau cu
                
                
                	wrong = 0;
                	do{
				  		textcolor(238);
                  		if(wrong == 3)
                    	{
					    	textcolor(7);
							goto a;
						}
                  		gotoxy(42,19);
				  		cin>>NewPass1;
				  		if(NewPass1 == OldPass)                        // Nhap mat khau moi lan 1
				    	{
					    	ToMau(94,19,"! Mat khau moi trung Mat khau cu",4);
					    	gotoxy(42,19);
					    	cout<<"                                    ";
					    	wrong++;
				    	}
				   		else{
					   		ToMau(94,19,"                               ",4);
					   		ToMau(94,19,"๛ Hoan thanh",10);
					   		textcolor(7);
				   		}	
					} while(NewPass1 == OldPass); // mat khau moi
				
					wrong = 0;
					do{
				  		textcolor(238);
				  		if(wrong == 3)
				    	{
					    	textcolor(7);
							goto a;
						}
				     
						gotoxy(42,20);
						cin>>NewPass2;
						if(NewPass2 != NewPass1)                                // Nhap mat khau moi lan 2
					    {
					    	ToMau(94,20,"! Mat khau nhap lai khong khop",4);
					    	gotoxy(42,20);
					    	cout<<"                                    ";
					    	wrong++;
						}
					  	else{
						  	ToMau(94,20,"                                  ",4);
						  	ToMau(94,20,"๛ Hoan thanh",10);
						  	textcolor(7);
					  	}
					} while(NewPass2 != NewPass1); // nhap lai mat khau
				
					kt = 1;		
					XoaConTro();
					goto f1;	
				}
			    
			    if(x == 2) //  Quay ve menu
			    {
			      	textcolor(7);
			      	goto a;
			    } 
				
				if(x == 3) // Luu mat khau
				{ 
				    ToMau(103,21,"ษอออออออออออออออป",6);
	                ToMau(103,22,"บ               บ",6);
                    ToMau(103,23,"บ      LUU      บ",6);
                    ToMau(103,24,"บ    MAT KHAU   บ",6);
                    ToMau(103,25,"บ               บ",6);
                    ToMau(103,26,"ศอออออออออออออออผ",6);
					
					if(kt == 0)
					{
						ToMau(100,27,"Yeu Cau nhap mat khau!",14);
						Sleep(2000);
						textcolor(7);
						goto f; // Neu chua doi? tro lai doi mat khau
					}
					// Neu da nhap day du mat khau => Co hoac Khong
					else{ 
						ToMau(100,27,"                      ",0);
						int choose;

	                    choose = MouseEventToYesOrNoChangePass(475,330,635,535,    995,850,635,535);
	            
	                    if(choose == 1) // Co
	                    {
	              	        ofstream fileOutput;
			                fileOutput.open(fileStudentPass,ios::out); // Sua trong file StudentPass
			        
	              	        for(Node *p=l.Head ; p!=NULL ; p=p->Next)
	              	        {
	              	   	        if(p->data.StudentCode != Member.StudentCode)       // Neu ma hoc vien khac nhau thi cu the in lai vao file
	              	   	        	fileOutput<<p->data.StudentPass<<"\n";
	              	   	        else{                                       
	              	   	            p->data.StudentPass = NewPass2;         // Neu trung roi thi thay doi StudentPass
	              	   	            fileOutput<<Encrypt(NewPass2)<<"\n";
	              	            }
					        }
	              	        cout<<"\n\n\t\t     Doi mat khau thanh cong!!!";
	              	        fileOutput.close();
	              	        
	              	        textcolor(7);
                            goto a;
	                    }
		                else{ // Khong
		         	        textcolor(7);
	  	                    goto f;
	                    } 
					}
				}    
			}      

			// Thoat ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			if(luachon == 5)
			{
			  	PrintEmpty();
				
			    int choose;
			    choose = MouseEventToYesOrNoExit(470,350,370,300,    905,795,370,300); // Co or Khong
			    
			    if(choose == 1) // Co
			    {
			      	textcolor(7);
			      	return;
				}	
				if(choose == 2) textcolor(7); // Khong
			}
		}
}

//==============================================================================================================================
//==============================================================================================================================
//==============================================================================================================================
//==============================================================================================================================

void MENU()
{	

    ReadAdminPass();
    
	List DanhSach;
	Init(DanhSach);
	
	AddToListFromFile(DanhSach); // Doc du lieu tu cac file
	
	ReSetStudentPass(DanhSach);  // reset lai mat khau trong fixbug
	
	Start();
	
a:	textcolor(7);
    PrintEmpty();
    LogIn(DanhSach);   
	textcolor(7);
	
	if(Direction == 1) // Dang nhap tai khoan sinh vien (bien Direction duoc dinh nghia o ham LogIn "ListFunction.h")
	{
		MENUforMember(DanhSach,Member);
		goto a;
	}	   
	else // Neu Direction = 2 (Dang nhap tai khoan admin)
		while(true)
	    {	    	
b:	     	XoaConTro();
	     	PrintEmpty();
	     	//PrintFrame(10);
	     	textcolor(7);
            int luachon;
            
            // Su kien chuot cho menu Admin (10 muc)
		    luachon = MouseEventToButtonOfMenu(690,130,165,130,    690,130,215,180,   690,130,265,230,   690,130,320,280,   690,130,370,334,   690,130,420,385,   690,130,470,435,   690,130,520,485,    690,130,570,535  ,    690,130,620,585,    1035,945,190,170,    1035,945,225,205,    1035,945,260,240);		    
		    if (luachon == 10) // Thoat
		    {
		    	PrintEmpty();
		    	int choose;
		    	choose = MouseEventToYesOrNoExit(470,350,370,300,    905,795,370,300);
		    	
		    	if (choose == 1) // Co
		    	{		    		
		    		textcolor(7);
		    		goto a;
				}
				if (choose == 2) textcolor(7);
			}
		}
}
//==============================================================================================================================
//==============================================================================================================================


#endif
