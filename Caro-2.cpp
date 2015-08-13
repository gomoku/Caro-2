#include <iostream.h>
#include <string.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <graphics.h>

int M[22][23];
int Col=240, Row=220, I=10, J=11;
int Play=1,cont=1;
char Player1[10],Player2[10];

void Win(char name[]);
void Choi();
int Thang(int , int , int );
void XuatVT(int , int , int );
void Chu(int , int , int );
void Khung(int , int , int );
void Khoidau();
void Nen();
void Phien(char st[], int ,int );
void KTDH(void);

void main(void)
{ Khoidau();
KTDH();
do{ Play=1;Col=240; Row=220; I=10; J=11;
for(int i=0; i<22; i++)
for(int j=0; j<23; j++)
M[i][j]=0;
cleardevice();
Nen();
Choi();
}while(cont==1);
closegraph();
}

void Win(char name[])
{
settextstyle(1,0,9);
setcolor(15);
outtextxy(10,10,name);
outtextxy(10,100," won");
}

void Choi()
{ char key;
Khung(Col,Row,1);
XuatVT(I,J,3);
char Chuoi[236]=" This is program demo CARO game between two players. Press F2 to new game, F10 to quit game and when you finish a game, press any key to a new game. This program was written by................................";
int l=strlen(Chuoi);
Phien(Player1,170,15+BLINK);
do{ do{ settextstyle(2,0,5);
setcolor(15);
outtextxy(1,460,Chuoi);
delay(200);
setcolor(1);
outtextxy(1,460,Chuoi);
char st=Chuoi[0];
for(int i=0; i<l; i++)
Chuoi[i]=Chuoi[i+1];
Chuoi[l]=st;
}while(!kbhit());
key=getch();
if(key==0) key=getch();
if(key==77)
{ Khung(Col,Row,3);
XuatVT(I,J,1);
Col=Col+20; J++;
if(Col==480) {Col=20; J=0;}
Khung(Col,Row,1);
XuatVT(I,J,3);
}
if(key==75)
{ Khung(Col,Row,3);
XuatVT(I,J,1);
Col=Col-20; J--;
if(Col==0) {Col=460;J=22;}
Khung(Col,Row,1);
XuatVT(I,J,3);
}
if(key==80)
{ Khung(Col,Row,3);
XuatVT(I,J,1);
Row=Row+20; I++;
if(Row==460) {Row=20; I=0;}
Khung(Col,Row,1);
XuatVT(I,J,3);
}
if(key==72)
{ Khung(Col,Row,3);
XuatVT(I,J,1);

Row=Row-20; I--;
if(Row==0) {Row=440; I=21;}
Khung(Col,Row,1);
XuatVT(I,J,3);
}
if(key==13)
if(M[i][J]==0)
{ Chu(Col,Row,Play);
if(Play==1)
{ M[i][J]=1;
if(Thang(I,J,Play)==Play)
{ Win(Player1);getch();
Play=-1;return;
}
Play=-1;
Phien(Player1,170,5);
Phien(Player2,270,15+BLINK);
}
else
{ M[i][J]=-1;
if(Thang(I,J,Play)==Play)
{ Win(Player2);getch();
Play=1;return;
}
Play=1;
Phien(Player2,270,5);
Phien(Player1,170,15+BLINK);
}
}
if(key==60) break;
if(key==68) {cont=0;return;}
}while(key!=68);
}

int Thang(int x, int y, int s)
{ if(M[x][y-4]!=-s&&M[x][y-3]==s&&M[x][y-2]==s&&M[x][y-1]==s&&M[x][y]==s&&M[x][y+1]!=-s)
return(s);
if(M[x][y-3]!=-s&&M[x][y-2]==s&&M[x][y-1]==s&&M[x][y]==s&&M[x][y+1]==s&&M[x][y+2]!=-s)
return(s);
if(M[x][y-2]!=-s&&M[x][y-1]==s&&M[x][y]==s&&M[x][y+1]==s&&M[x][y+2]==s&&M[x][y+3]!=-s)
return(s);
if(M[x][y-1]!=-s&&M[x][y]==s&&M[x][y+1]==s&&M[x][y+2]==s&&M[x][y+3]==s&&M[x][y+4]!=-s)
return(s);

if(M[x-4][y]!=-s&&M[x-3][y]==s&&M[x-2][y]==s&&M[x-1][y]==s&&M[x][y]==s&&M[x+1][y]!=-s)
return(s);
if(M[x-3][y]!=-s&&M[x-2][y]==s&&M[x-1][y]==s&&M[x][y]==s&&M[x+1][y]==s&&M[x+2][y]!=-s)
return(s);
if(M[x-2][y]!=-s&&M[x-1][y]==s&&M[x][y]==s&&M[x+1][y]==s&&M[x+2][y]==s&&M[x+3][y]!=-s)
return(s);
if(M[x-1][y]!=-s&&M[x][y]==s&&M[x+1][y]==s&&M[x+2][y]==s&&M[x+3][y]==s&&M[x+4][y]!=-s)
return(s);

if(M[x-4][y-4]!=-s&&M[x-3][y-3]==s&&M[x-2][y-2]==s&&M[x-1][y-1]==s&&M[x][y]==s&&M[x+1][y+1]!=-s)
return(s);
if(M[x-3][y-3]!=-s&&M[x-2][y-2]==s&&M[x-1][y-1]==s&&M[x][y]==s&&M[x+1][y+1]==s&&M[x+2][y+2]!=-s)
return(s);
if(M[x-2][y-2]!=-s&&M[x-1][y-1]==s&&M[x][y]==s&&M[x+1][y+1]==s&&M[x+2][y+2]==s&&M[x+3][y+3]!=-s)
return(s);
if(M[x-1][y-1]!=-s&&M[x][y]==s&&M[x+1][y+1]==s&&M[x+2][y+2]==s&&M[x+3][y+3]==s&&M[x+4][y+4]!=-s)
return(s);

if(M[x-4][y+4]!=-s&&M[x-3][y+3]==s&&M[x-2][y+2]==s&&M[x-1][y+1]==s&&M[x][y]==s&&M[x+1][y-1]!=-s)
return(s);
if(M[x-3][y+3]!=-s&&M[x-2][y+2]==s&&M[x-1][y+1]==s&&M[x][y]==s&&M[x+1][y-1]==s&&M[x+2][y-2]!=-s)
return(s);
if(M[x-2][y+2]!=-s&&M[x-1][y+1]==s&&M[x][y]==s&&M[x+1][y-1]==s&&M[x+2][y-2]==s&&M[x+3][y-3]!=-s)
return(s);
if(M[x-1][y+1]!=-s&&M[x][y]==s&&M[x+1][y-1]==s&&M[x+2][y-2]==s&&M[x+3][y-3]==s&&M[x+4][y-4]!=-s)
return(s);

return(0);
}

void XuatVT(int x, int y, int color)
{ settextstyle(1,0,1);
setcolor(color);
char c1[3],c2[3],c3[3];
itoa(x+1,c1,10);
itoa(y+1,c2,10);
outtextxy(580,30,c1);
outtextxy(580,60,c2);
}

void Chu(int x, int y, int status)
{ settextstyle(1,0,1);
if(status==1)
{ setcolor(14);
outtextxy(x-5,y-13,"O");
}
if(status==-1)
{ setcolor(5);
outtextxy(x-5,y-13,"X");
}
}
void Khung(int x, int y, int color)
{ setcolor(color);
line(x-3,y-10,x-7,y-10);
line(x-7,y-10,x-7,y-3);
line(x-7,y+3,x-7,y+8);
line(x-7,y+8,x-3,y+8);
line(x+3,y+8,x+7,y+8);
line(x+7,y+8,x+7,y+3);
line(x+7,y-3,x+7,y-10);
line(x+7,y-10,x+3,y-10);
}

void Khoidau()
{ window(1,1,80,25);textbackground(0);textcolor(15); clrscr();
gotoxy(40-5,2);cout<<"CARO GAME";
window(10,4,26,4);textbackground(1);textcolor(14); clrscr();
cout<<" Player 1's name ";
do{ window(14,6,50,6);textbackground(0);clrscr();
window(14,6,22,6);textbackground(3);textcolor(5);c lrscr();
fflush(stdin);gets(Player1);
}while(strlen(Player1)>8);
if(strlen(Player1)==0) strcpy(Player1,"Player 1");
window(54,4,70,4);textbackground(1);textcolor(14); clrscr();
cout<<" Player 2's name ";
do{ window(58,6,79,6);textbackground(0);clrscr();
window(58,6,66,6);textbackground(3);textcolor(5);c lrscr();
fflush(stdin);gets(Player2);
}while(strlen(Player2)>8);
if(strlen(Player2)==0) strcpy(Player2,"Player 2");
return;
}

void Nen()
{
setcolor(1);
setfillstyle(1,1);
rectangle(480,1,640,480);
rectangle(1,460,480,480);
floodfill(500,200,1);
floodfill(200,470,1);
setbkcolor(3);
setcolor(6);
for(int i=0; i<24; i++)
line(1,20*i,480,20*i);
for(i=0; i<25; i++)
line(20*i,1,20*i,460);
settextstyle(1,0,1);
setcolor(3);
outtextxy(500,30,"Hang = ");
outtextxy(500,60,"Cot = ");
settextstyle(2,0,5);
setcolor(15);
outtextxy(500,150,"Player 1's name");
outtextxy(500,250,"Player 2's name");
settextstyle(1,0,3);
setcolor(5);
outtextxy(510,170,Player1);
outtextxy(510,270,Player2);
}

void Phien(char st[], int col,int mau)
{ settextstyle(1,0,3);
setcolor(mau);
outtextxy(510,col,st);
}

void KTDH(void)
{ int L;
char* grPats = "C:\borlandc\BGI";
do{ int grDR = DETECT;
int grMD;
initgraph(&grDR,&grMD,grPats);
L = graphresult();
if(L!=grOk)
{ cout<<"\n Loi Khoi tao do hoa: "<<grapherrormsg(L);
if(L==grFileNotFound) // neu co loi duong dan thi nhap lai
{ cout<<"\n Cho duong dan toi BGI hoac an <Ctrl-Break> de dung Chuong trinh\n";
cout<<" Duong dan la: ";
fflush(stdin);
gets(grPats);
}
else exit(0);
}
} while(L!=grOk);
return;
}
///////////////////////////

[=========> Bổ sung bài viết <=========]

Đây là code caro của C++ ne ban tham khảo thử
/////////////////////

#include <iostream.h>
#include <string.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <graphics.h>

int M[22][23];
int Col=240, Row=220, I=10, J=11;
int Play=1,cont=1;
char Player1[10],Player2[10];

void Win(char name[]);
void Choi();
int Thang(int , int , int );
void XuatVT(int , int , int );
void Chu(int , int , int );
void Khung(int , int , int );
void Khoidau();
void Nen();
void Phien(char st[], int ,int );
void KTDH(void);

void main(void)
{ Khoidau();
KTDH();
do{ Play=1;Col=240; Row=220; I=10; J=11;
for(int i=0; i<22; i++)
for(int j=0; j<23; j++)
M[i][j]=0;
cleardevice();
Nen();
Choi();
}while(cont==1);
closegraph();
}

void Win(char name[])
{
settextstyle(1,0,9);
setcolor(15);
outtextxy(10,10,name);
outtextxy(10,100," won");
}

void Choi()
{ char key;
Khung(Col,Row,1);
XuatVT(I,J,3);
char Chuoi[236]=" This is program demo CARO game between two players. Press F2 to new game, F10 to quit game and when you finish a game, press any key to a new game. This program was written by................................";
int l=strlen(Chuoi);
Phien(Player1,170,15+BLINK);
do{ do{ settextstyle(2,0,5);
setcolor(15);
outtextxy(1,460,Chuoi);
delay(200);
setcolor(1);
outtextxy(1,460,Chuoi);
char st=Chuoi[0];
for(int i=0; i<l; i++)
Chuoi[i]=Chuoi[i+1];
Chuoi[l]=st;
}while(!kbhit());
key=getch();
if(key==0) key=getch();
if(key==77)
{ Khung(Col,Row,3);
XuatVT(I,J,1);
Col=Col+20; J++;
if(Col==480) {Col=20; J=0;}
Khung(Col,Row,1);
XuatVT(I,J,3);
}
if(key==75)
{ Khung(Col,Row,3);
XuatVT(I,J,1);
Col=Col-20; J--;
if(Col==0) {Col=460;J=22;}
Khung(Col,Row,1);
XuatVT(I,J,3);
}
if(key==80)
{ Khung(Col,Row,3);
XuatVT(I,J,1);
Row=Row+20; I++;
if(Row==460) {Row=20; I=0;}
Khung(Col,Row,1);
XuatVT(I,J,3);
}
if(key==72)
{ Khung(Col,Row,3);
XuatVT(I,J,1);

Row=Row-20; I--;
if(Row==0) {Row=440; I=21;}
Khung(Col,Row,1);
XuatVT(I,J,3);
}
if(key==13)
if(M[i][J]==0)
{ Chu(Col,Row,Play);
if(Play==1)
{ M[i][J]=1;
if(Thang(I,J,Play)==Play)
{ Win(Player1);getch();
Play=-1;return;
}
Play=-1;
Phien(Player1,170,5);
Phien(Player2,270,15+BLINK);
}
else
{ M[i][J]=-1;
if(Thang(I,J,Play)==Play)
{ Win(Player2);getch();
Play=1;return;
}
Play=1;
Phien(Player2,270,5);
Phien(Player1,170,15+BLINK);
}
}
if(key==60) break;
if(key==68) {cont=0;return;}
}while(key!=68);
}

int Thang(int x, int y, int s)
{ if(M[x][y-4]!=-s&&M[x][y-3]==s&&M[x][y-2]==s&&M[x][y-1]==s&&M[x][y]==s&&M[x][y+1]!=-s)
return(s);
if(M[x][y-3]!=-s&&M[x][y-2]==s&&M[x][y-1]==s&&M[x][y]==s&&M[x][y+1]==s&&M[x][y+2]!=-s)
return(s);
if(M[x][y-2]!=-s&&M[x][y-1]==s&&M[x][y]==s&&M[x][y+1]==s&&M[x][y+2]==s&&M[x][y+3]!=-s)
return(s);
if(M[x][y-1]!=-s&&M[x][y]==s&&M[x][y+1]==s&&M[x][y+2]==s&&M[x][y+3]==s&&M[x][y+4]!=-s)
return(s);

if(M[x-4][y]!=-s&&M[x-3][y]==s&&M[x-2][y]==s&&M[x-1][y]==s&&M[x][y]==s&&M[x+1][y]!=-s)
return(s);
if(M[x-3][y]!=-s&&M[x-2][y]==s&&M[x-1][y]==s&&M[x][y]==s&&M[x+1][y]==s&&M[x+2][y]!=-s)
return(s);
if(M[x-2][y]!=-s&&M[x-1][y]==s&&M[x][y]==s&&M[x+1][y]==s&&M[x+2][y]==s&&M[x+3][y]!=-s)
return(s);
if(M[x-1][y]!=-s&&M[x][y]==s&&M[x+1][y]==s&&M[x+2][y]==s&&M[x+3][y]==s&&M[x+4][y]!=-s)
return(s);

if(M[x-4][y-4]!=-s&&M[x-3][y-3]==s&&M[x-2][y-2]==s&&M[x-1][y-1]==s&&M[x][y]==s&&M[x+1][y+1]!=-s)
return(s);
if(M[x-3][y-3]!=-s&&M[x-2][y-2]==s&&M[x-1][y-1]==s&&M[x][y]==s&&M[x+1][y+1]==s&&M[x+2][y+2]!=-s)
return(s);
if(M[x-2][y-2]!=-s&&M[x-1][y-1]==s&&M[x][y]==s&&M[x+1][y+1]==s&&M[x+2][y+2]==s&&M[x+3][y+3]!=-s)
return(s);
if(M[x-1][y-1]!=-s&&M[x][y]==s&&M[x+1][y+1]==s&&M[x+2][y+2]==s&&M[x+3][y+3]==s&&M[x+4][y+4]!=-s)
return(s);

if(M[x-4][y+4]!=-s&&M[x-3][y+3]==s&&M[x-2][y+2]==s&&M[x-1][y+1]==s&&M[x][y]==s&&M[x+1][y-1]!=-s)
return(s);
if(M[x-3][y+3]!=-s&&M[x-2][y+2]==s&&M[x-1][y+1]==s&&M[x][y]==s&&M[x+1][y-1]==s&&M[x+2][y-2]!=-s)
return(s);
if(M[x-2][y+2]!=-s&&M[x-1][y+1]==s&&M[x][y]==s&&M[x+1][y-1]==s&&M[x+2][y-2]==s&&M[x+3][y-3]!=-s)
return(s);
if(M[x-1][y+1]!=-s&&M[x][y]==s&&M[x+1][y-1]==s&&M[x+2][y-2]==s&&M[x+3][y-3]==s&&M[x+4][y-4]!=-s)
return(s);

return(0);
}

void XuatVT(int x, int y, int color)
{ settextstyle(1,0,1);
setcolor(color);
char c1[3],c2[3],c3[3];
itoa(x+1,c1,10);
itoa(y+1,c2,10);
outtextxy(580,30,c1);
outtextxy(580,60,c2);
}

void Chu(int x, int y, int status)
{ settextstyle(1,0,1);
if(status==1)
{ setcolor(14);
outtextxy(x-5,y-13,"O");
}
if(status==-1)
{ setcolor(5);
outtextxy(x-5,y-13,"X");
}
}
void Khung(int x, int y, int color)
{ setcolor(color);
line(x-3,y-10,x-7,y-10);
line(x-7,y-10,x-7,y-3);
line(x-7,y+3,x-7,y+8);
line(x-7,y+8,x-3,y+8);
line(x+3,y+8,x+7,y+8);
line(x+7,y+8,x+7,y+3);
line(x+7,y-3,x+7,y-10);
line(x+7,y-10,x+3,y-10);
}

void Khoidau()
{ window(1,1,80,25);textbackground(0);textcolor(15); clrscr();
gotoxy(40-5,2);cout<<"CARO GAME";
window(10,4,26,4);textbackground(1);textcolor(14); clrscr();
cout<<" Player 1's name ";
do{ window(14,6,50,6);textbackground(0);clrscr();
window(14,6,22,6);textbackground(3);textcolor(5);c lrscr();
fflush(stdin);gets(Player1);
}while(strlen(Player1)>8);
if(strlen(Player1)==0) strcpy(Player1,"Player 1");
window(54,4,70,4);textbackground(1);textcolor(14); clrscr();
cout<<" Player 2's name ";
do{ window(58,6,79,6);textbackground(0);clrscr();
window(58,6,66,6);textbackground(3);textcolor(5);c lrscr();
fflush(stdin);gets(Player2);
}while(strlen(Player2)>8);
if(strlen(Player2)==0) strcpy(Player2,"Player 2");
return;
}

void Nen()
{
setcolor(1);
setfillstyle(1,1);
rectangle(480,1,640,480);
rectangle(1,460,480,480);
floodfill(500,200,1);
floodfill(200,470,1);
setbkcolor(3);
setcolor(6);
for(int i=0; i<24; i++)
line(1,20*i,480,20*i);
for(i=0; i<25; i++)
line(20*i,1,20*i,460);
settextstyle(1,0,1);
setcolor(3);
outtextxy(500,30,"Hang = ");
outtextxy(500,60,"Cot = ");
settextstyle(2,0,5);
setcolor(15);
outtextxy(500,150,"Player 1's name");
outtextxy(500,250,"Player 2's name");
settextstyle(1,0,3);
setcolor(5);
outtextxy(510,170,Player1);
outtextxy(510,270,Player2);
}

void Phien(char st[], int col,int mau)
{ settextstyle(1,0,3);
setcolor(mau);
outtextxy(510,col,st);
}

void KTDH(void)
{ int L;
char* grPats = "C:\borlandc\BGI";
do{ int grDR = DETECT;
int grMD;
initgraph(&grDR,&grMD,grPats);
L = graphresult();
if(L!=grOk)
{ cout<<"\n Loi Khoi tao do hoa: "<<grapherrormsg(L);
if(L==grFileNotFound) // neu co loi duong dan thi nhap lai
{ cout<<"\n Cho duong dan toi BGI hoac an <Ctrl-Break> de dung Chuong trinh\n";
cout<<" Duong dan la: ";
fflush(stdin);
gets(grPats);
}
else exit(0);
}
} while(L!=grOk);
return;
}
