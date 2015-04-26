#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#define MAX_LINE_LEN 128

int *Pnm,*PstoC;            //*Pnm: To Main Menu Selection  //*PstoC: To Student Counter
int Pass=0,Fail=0;
int flag=1;                 // for integer check in whole programe
float RnkAvg[6]={0,0,0,0,0,0};

void Select();              // To Main menu
int getInt();               // To filter Integer from Char
void slcChk();              // To Check Input in main menu & Create Recursive Function
void fun1();                // Main task Function to main menu
void MrkChk(int,int);       // To check Subject marks and store marks
void MGrd(int);             // To Grade check and store
void Ranking(float);        // To find highers marks and Rank the students

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%    Main Student Structure     %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
struct Student{
    int id;
    char name[15];              // Structure of Array >> This is for store Student Name

    struct Subject              // Structure within Structure >> Out of Structure
    {
        char Sbnm[10];          // Out of Structure Array >> This is for store Subject Name
        char Grade[2];          // Out of Structure Array >> This is for store Grade
        float AEmarks[2];       // for Assignments marks & End exm marks
    }sub[8],grd[9],marks[8];    // sub Array for 8 Subjects grd Array for Store each subjects Grade

    float fmarks[9];            // Inner Structure Array >> This is for store 8 Final Marks & final Avg grade
    int FP;                     // This is for store student state pass or fail
    float Tot;                  // Student total marks
    float Avg;                  // Student Average
}S[5];                          // Inner Structure Variable >> For Store 5 Students


int main()  //@@@@@@@@@@@!!!!!!!!!!!!!!!@@@@@@@@@@@@      MAIN        @@@@@@@@@@@!!!!!!!!!!!!!@@@@@@@@@@@@@@@@@
{
    int nm,stoC=0;
    char buff[100];
    char buff1[100];
    Pnm=&nm;
    PstoC=&stoC;
    time_t now = time (0);
    strftime (buff, 100, "%Y-%m-%d", localtime (&now));     // Date
    strftime (buff1, 100, "%H:%M:%S", localtime (&now));    // Time

    printf("&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&");
    printf("\n&&\t\t****\tStudent Report Programme\t****\t\t&&");
    printf("\n&&\t\t****\t Developed By S.Priyanga  \t****\t\t&&");
    printf("\n&&\t\t****\t  s.priyanga22@gmail.com  \t****\t\t&&");
    printf("\n&&\t\t****\t  Date : %s\t\t****\t\t&&",buff);
    printf("\n&&\t\t****\t  Time : %s\t\t****\t\t&&",buff1);
    printf("\n&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n\n");
    printf("\n%%%%%% Guidlines use of the Software ....!!!");
    printf("\n *01. System Can Store 5 Students");
    printf("\n *02. Under Each Student can store 8 subjects");
    printf("\n *03. Each Subject have Assigment marks and End exam Marks");
    printf("\n *04. Final Mark of subject = (Assigment_mark * 0.2) + (End_exam_Mark * 0.8)");
    printf("\n *05. Don't Use space between two words");
    printf("\n *06. Grading Criteria");
    printf("\n\t\t100-85\tA+");
    printf("\n\t\t 84-70\tA");
    printf("\n\t\t 69-65\tA-");
    printf("\n\t\t 64-60\tB+");
    printf("\n\t\t 59-55\tB");
    printf("\n\t\t 54-45\tC+");
    printf("\n\t\t 44-40\tC");
    printf("\n\t\t 39-35\tD+");
    printf("\n\t\t 34-30\tD");
    printf("\n\t\t 29- 0\tF");
    printf("\n\nPress any key to Start ...");
    getch();
    printf("\n\n");
    Select();
    slcChk();

    printf("\n\n\t\t%%%%%%Thank You ....!!!");
    printf("\n\t\tIf You find any Bug of this Programme Please Inform me ;) :D \n");

    printf("\n\t\t*****   Programe Created By ....  *****\n");
    printf("\n\t\tSrimal Priyanga");
    printf("\n\t\ts.priyanga22@gmail.com");
    printf("\n\n\t\t*****   ........................  *****");

    printf("\n\n\t\tPress any key to Exit....");
    getch();
    return 0;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%    Selection Menu Function     %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
void Select()
{
    int P=0;
    while(P<69){
        printf("%%");
        P++;
    }
    printf("\n%%\t\t\t\t\t\t\t\t    %%\n%%\t\t\t1. Add Student\t\t\t\t    %%");
    printf("\n%%\t\t\t2. View Student Reports\t\t\t    %%");
    printf("\n%%\t\t\t3. Re-New Student Details\t\t    %%");
    printf("\n%%\t\t\t4. View All Records\t\t\t    %%");
    printf("\n%%\t\t\t5. View Student Rankings\t\t    %%");
    printf("\n%%\t\t\t6. Exit\t\t\t\t\t    %%\n");
    printf("\nEnter the number from above Menu\n");
    *Pnm= getInt(); //scanf("%d",&*Pnm);

    P=0;
    while(P<69){
        printf("%%");
        P++;
    }
    return;
}

//%%%%%%%%%%%%%%%%%    Entered Selection Check funtion whether it Valid Seletion or not     %%%%%%%%%%%%%%%
void slcChk()
{
    if (*Pnm<=0){
        printf("\nXXXXX  Invalide Selection ...");
        printf("\nXXXXX  Enter Again ...");
        printf("\n:");
        *Pnm= getInt(); //scanf("%d",&*Pnm);
        slcChk();
    }

    while (*Pnm<6){
        fun1();
        Select();
    }

    if (*Pnm>6){
        printf("\nXXXXX  Invalide Selection ...");
        printf("\nXXXXX  Enter Again ...");
        printf("\n:");
        *Pnm= getInt(); //scanf("%d",&*Pnm);

        slcChk();
    }
    else
        return;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%    Sutedent Add & View Function  Ranking   %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
void fun1()
{
    int i,j,m,v,tmp,tmpPF;
    switch(*Pnm)
    {
/**/case 1:
        if (*PstoC<5){
            printf("\n:::Allredy Stored %d Students you can store %d more Students:::",*PstoC,5-*PstoC);
            printf("\n\n******Student ID\t: 0000%d",*PstoC+1);
            printf("\nEnter the Student Name\t: ");
            scanf("%s",&S[*PstoC].name);

            for(i=0; i<8; ++i){
                printf("\nEnter Subject%d Name\t: ",i+1);
                scanf("%s",&S[*PstoC].sub[i].Sbnm);
                flag=0;
                MrkChk(i,0);
                flag=1;
                MGrd (i);
                S[*PstoC].Tot += S[*PstoC].fmarks[i];
            }

            S[*PstoC].Avg = S[*PstoC].Tot/8;
            S[*PstoC].fmarks[8]=S[*PstoC].Avg;
            MGrd (8); //final grade check

            if(S[*PstoC].fmarks[8]>=40){
                S[*PstoC].FP=1;
                ++Pass;
            }
            else{
                S[*PstoC].FP=0;
                ++Fail;
            }
            Ranking(S[*PstoC].Avg);
            printf("\n\tStudent %d Registration Done...!!!!!!!!!!!!\n\n",++*PstoC);
        }
        else{
            printf("\n\n\nXXXXX  *You Stored Maximum Students..!\n\n");
        }
    getch();
    break;

/**/case 2:
    if (*PstoC>0){
        printf("\n\nEnter Student ID <00001 To 00005>\t: ");
        v= getInt(); //scanf("%d",&v);

        if ((v>5)||(v<1))
            printf("XXXX Invalid Selection Try again....!!\n\n");
        else if (v<=*PstoC){
            v--;
            printf("Student Name\t\t: %s",S[v].name);
            printf("\n\n  ***Subjects\tAsgnmnt Mrks\tEnd Xm Mrks\t***Final Marks\t***Grade");
            for(i=0; i<8; ++i){
                    printf("\n     %d.%s",i+1,&S[v].sub[i].Sbnm);
                    printf("\t   %0.2f",S[v].marks[i].AEmarks[0]);
                    printf("\t   %0.2f",S[v].marks[i].AEmarks[1]);
                    printf("\t   %0.2f",S[v].fmarks[i]);
                    printf("\t   %c",S[v].grd[i].Grade[0]);
                    printf("%c",S[v].grd[i].Grade[1]);
            }
                printf("\n\n\t\t\tTotal Marks of Student\t: %0.2f",S[v].Tot);
                printf("\n\t\t\tAverage\t\t\t:  %0.2f %%",S[v].Avg);
                printf("\n\t\t\tFinal Grade\t\t:  %c",S[v].grd[8].Grade[0]);
                printf("%c",S[v].grd[8].Grade[1]);

                if(S[v].FP==1)
                printf("\n\t\t\tState\t\t\t:  Pass");
                else
                printf("\n\t\t\tState\t\t\t:  Fail");
                printf("\n\t\t\tDone...!\n\n");
        }
        else
            printf("XXXX There is no student registered under this index\n\n");
    }
    else{
        printf("\nXXXX  There is no any Registerd Students Details");
        printf("\nXXXX  First You Need to Register Students... !!\n\n");
    }

    getch();
    break;

/**/case 3:
    if (*PstoC>0){
        printf("\n");
        for(i=0; i<*PstoC; i++){
            printf("\nStudent ID: 0000%d",++i);
            printf("\tName: %s",S[--i].name);
        }
        printf("\n\nEnter Student ID whos you need to Re-New: ");
        v= getInt(); //scanf("%d",&v);

        if ((v>*PstoC)||(v<1))
            printf("XXXX Invalid Selection Try again....!!\n\n");
        else if (v<=PstoC){
            printf("\n\n\tStudent ID\t: %d",v);
            tmp=*PstoC;
            *PstoC=--v;
                printf("\nEnter the Student Name\t: ");
                scanf("%s",&S[*PstoC].name);
                S[*PstoC].Tot=0;
                for(i=0; i<8; ++i){
                    printf("\nEnter Subject %d Name\t: ",i+1);
                    scanf("%s",&S[*PstoC].sub[i].Sbnm);
                    flag=0;
                    MrkChk(i,0);
                    flag=1;
                    MGrd (i);
                    S[*PstoC].Tot += S[*PstoC].fmarks[i];
                }
                for(j=0; j<5; ++j){                  // For Rankings
                    if (RnkAvg[j]==S[*PstoC].Avg){
                        m=j;
                            for (m; m<6; ++m){
                                RnkAvg[m]=RnkAvg[++j];
                            }
                    break;
                    }
                    else
                    continue;
                }

                S[*PstoC].Avg = S[*PstoC].Tot/8;
                tmpPF=S[*PstoC].fmarks[8];
                S[*PstoC].fmarks[8]=S[*PstoC].Avg;
                MGrd (8);
                if(S[*PstoC].fmarks[8]>=40){
                    S[*PstoC].FP=1;
                    if(tmpPF<40){
                        --Fail;
                        ++Pass;
                    }
                }
                else{
                    S[*PstoC].FP=0;
                    if(tmpPF>=40){
                        ++Fail;
                        --Pass;
                    }
                }
                Ranking(S[*PstoC].Avg);
                printf("\n\tStudent %d Registration Done...!!!!!!!!!!!!\n\n",++*PstoC);
        *PstoC=tmp;
      }
      else{
          printf("\nXXXXX  Invalide Selection ...");
          printf("\nXXXXX  Try Again ...\n");
      }
    }

    else{
        printf("\nXXXX  There is no any Registerd Students Details");
        printf("\nXXXX  First You Need to Register Students... !!\n\n");
    }

    getch();
    break;

/**/case 4:
    if (*PstoC>0)
    {
        for(v=0; v<*PstoC; ++v){
            printf("\n\n\n%%%%%%%%%%%%%%%%%%%%%%%%%%\tDetails Of Student   %d\t..........................||",++v);
            printf("\nStudent ID\t: 0000%d",v--);
            printf("\t\t\tStudent Name\t: %s",S[v].name);
            printf("\n\n  ***Subjects\tAsgnmnt Mrks\tEnd Xm Mrks\t***Final Marks\t***Grade");
            for(i=0; i<8; ++i){
                    printf("\n     %d.%s",i+1,&S[v].sub[i].Sbnm);
                    printf("\t   %0.2f",S[v].marks[i].AEmarks[0]);
                    printf("\t   %0.2f",S[v].marks[i].AEmarks[1]);
                    printf("\t   %0.2f",S[v].fmarks[i]);
                    printf("\t   %c",S[v].grd[i].Grade[0]);
                    printf("%c",S[v].grd[i].Grade[1]);
            }
                printf("\n\n\t\t\tTotal Marks of Student\t: %0.2f",S[v].Tot);
                printf("\n\t\t\tAverage\t\t\t:  %0.2f %%",S[v].Avg);
                printf("\n\t\t\tFinal Grade\t\t:  %c",S[v].grd[8].Grade[0]);
                printf("%c",S[v].grd[8].Grade[1]);

                if(S[v].FP==1)
                printf("\n\t\t\tState\t\t\t:  Pass");
                else
                printf("\n\t\t\tState\t\t\t:  Fail");
                printf("\n\n\t\t*******  Done.........!!!!!!!\n\n");
        }

    }

    else
    {
        printf("\nXXXX  There is no any Registerd Students Details");
        printf("\nXXXX  First You Need to Register Students... !!\n\n");
    }

    getch();
    break;

/**/case 5:
    if (RnkAvg[0]>0)
    {
        printf("\n\n\n\n\t\t*******  Student Rankings...  *******\n\n");
        printf("\n\t\tName\t\t#Final Grade\t#Total Mrks\t   #Avg\n\n");
        for (i=0; i<=*PstoC; i++){
                if (i==0)
                printf("1st Place");
                else if (i==1)
                printf("2nd Place");
                else if (i==2)
                printf("3rd Place");
                else if (i==3)
                printf("4th Place");
                else if (i==4)
                printf("5th Place");
                else
                    break;

                for (j=0; j<5; ++j){
                        if (RnkAvg[i]==S[j].Avg){
                            printf("\t%s",S[j].name);
                            printf("\t\t  %c",S[j].grd[8].Grade[0]);
                            printf("%c",S[j].grd[8].Grade[1]);
                            printf("\t\t %0.2f",S[j].Tot);
                            printf("\t\t  %0.2f%% \n",S[j].Avg);
                            break;
                        }
                        else
                        continue;
                }
            }
            printf("\n\n\t\t\tNumber of Student Pass\t: %d",Pass);
            printf("\n\n\t\t\tNumber of Student Fail\t: %d",Fail);
            printf("\n\n\n\n\t\t*******  Done .........  !!!  *******\n\n");
    }

    else{
        printf("\nXXXX  There is no any Registerd Students Details");
        printf("\nXXXX  First You Need to Register Students... !!\n\n");
    }

    getch();
    break;
}               // .........End of Switch...............

    return;
}   // .........End of Function...............

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%    Mark Check Funtion, this is for check mark whether it <0 or >100
void MrkChk(int i,int k)
{
    for(k;k<2;k++){
        if(k==0){
            printf("\tEnter Marks of Assignments:");
            S[*PstoC].marks[i].AEmarks[k]=getInt();

            if(S[*PstoC].marks[i].AEmarks[k]>100){
            printf("\tXXXXX  You Entered Marks Greater than 100 !!!!!!!!!");
            printf("\n\t##Again \b");
            MrkChk(i,0);
            break;
            }
            else if(S[*PstoC].marks[i].AEmarks[k]<0){
                printf("\tXXXXX  You Entered Marks Less than 0 !!!!!!!!!");
                printf("\n\t##Again \b");
                MrkChk(i,0);
                break;
            }
            else
                continue;
        }
        else{
            printf("\tEnter Marks of End Exam: ");
            S[*PstoC].marks[i].AEmarks[k]=getInt();

            if(S[*PstoC].marks[i].AEmarks[k]>100){
                printf("\tXXXXX  You Entered Marks Greater than 100 !!!!!!!!!");
                printf("\n\t##Again \b");
                MrkChk(i,1);
            }
            else if(S[*PstoC].marks[i].AEmarks[k]<0){
                printf("\tXXXXX  You Entered Marks Less than 0 !!!!!!!!!");
                printf("\n\t##Again \b");
                MrkChk(i,1);
            }
            else
                break;
        }
    }
 // Calculate Final marks ==================================
    S[*PstoC].fmarks[i] = (S[*PstoC].marks[i].AEmarks[0] * 0.2) + (S[*PstoC].marks[i].AEmarks[1] * 0.8);
    return;
}

// ================================== Integer check Function ==================================
int getInt() {
    static char line[MAX_LINE_LEN];
    static char junk[MAX_LINE_LEN];
    bool inputOk;
    int sp;

        for (inputOk = false; inputOk == false; ) {
            fgets(line,MAX_LINE_LEN,stdin);
            inputOk = (sscanf(line,"%d%s",&sp,junk) == 1);
            if (inputOk == false) {
                if(flag==0){
                    printf(" ");
                    flag=1;
                }
                else
                printf("#### Invalid Input Try again : ");
            }
        }
    return sp;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%    Grade Check Funtion, Grade can be F,D,D+,C,C+,B,B+,A-,A,A+
void MGrd(int i)
{
    if (S[*PstoC].fmarks[i]>=85){
        S[*PstoC].grd[i].Grade[0]='A';
        S[*PstoC].grd[i].Grade[1]='+';
    }
    else if (S[*PstoC].fmarks[i]>=70){
        S[*PstoC].grd[i].Grade[0]='A';
        S[*PstoC].grd[i].Grade[1]=' ';
    }
    else if (S[*PstoC].fmarks[i]>=65){
        S[*PstoC].grd[i].Grade[0]='A';
        S[*PstoC].grd[i].Grade[1]='-';
    }
    else if (S[*PstoC].fmarks[i]>=60){
        S[*PstoC].grd[i].Grade[0]='B';
        S[*PstoC].grd[i].Grade[1]='+';
    }
    else if (S[*PstoC].fmarks[i]>=55){
        S[*PstoC].grd[i].Grade[0]='B';
        S[*PstoC].grd[i].Grade[1]=' ';
    }
    else if (S[*PstoC].fmarks[i]>=45){
        S[*PstoC].grd[i].Grade[0]='C';
        S[*PstoC].grd[i].Grade[1]='+';
    }
    else if (S[*PstoC].fmarks[i]>=40){
        S[*PstoC].grd[i].Grade[0]='C';
        S[*PstoC].grd[i].Grade[1]=' ';
    }
    else if (S[*PstoC].fmarks[i]>=35){
        S[*PstoC].grd[i].Grade[0]='D';
        S[*PstoC].grd[i].Grade[1]='+';
    }
    else if (S[*PstoC].fmarks[i]>=30){
        S[*PstoC].grd[i].Grade[0]='D';
        S[*PstoC].grd[i].Grade[1]=' ';
    }
    else{
        S[*PstoC].grd[i].Grade[0]='F';
        S[*PstoC].grd[i].Grade[1]=' ';
    }

    return;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%    Ranking Function ...............................................

void Ranking(float tmp)
{
    if (tmp>RnkAvg[0]){
        RnkAvg[4]=RnkAvg[3];
        RnkAvg[3]=RnkAvg[2];
        RnkAvg[2]=RnkAvg[1];
        RnkAvg[1]=RnkAvg[0];
        RnkAvg[0]=tmp;
    }
    else if (tmp>RnkAvg[1]){
        RnkAvg[4]=RnkAvg[3];
        RnkAvg[3]=RnkAvg[2];
        RnkAvg[2]=RnkAvg[1];
        RnkAvg[1]=tmp;
    }
    else if (tmp>RnkAvg[2]){
        RnkAvg[4]=RnkAvg[3];
        RnkAvg[3]=RnkAvg[2];
        RnkAvg[2]=tmp;
    }
    else if (tmp>RnkAvg[3]){
        RnkAvg[4]=RnkAvg[3];
        RnkAvg[3]=tmp;
    }
    else
        RnkAvg[4]=tmp;
}

