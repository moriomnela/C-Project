#include <stdio.h>
#include<stdlib.h>
#include<time.h>

 struct patient{
    int id;
    char patientName[50];
    char patientAddress[50];
    char patientDisease[50];
    char date[12];
 }p;
 struct doctor {
    int id;
    char name[50];
    char address[50];
    char specialize[50];
    char date[12];
 }d;
 FILE *fp;

int main(){
    int ch;

    while(1){
        system("cls");
        printf("<== Hospital Management System ==>\n");
        printf("1.Admit Patient\n");
        printf("2.Patient List\n");
        printf("3.Discharge Patient\n");
        printf("4.Add Doctor\n");
        printf("5.Doctors List\n");
        printf("0.Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch){
        case 0:
            exit(0);

        case 1:
            admitPatient();
            break;

        case 2:
            patientList();
            break;
        case 3:
            dischargePatient();
            break;
        case 4:
            addDoctor();
            break;
        case 5:
            doctoeList();
            break;

        default:
            printf("Invalid Choice....\n\n");
        }
        printf("\m\mPress Any Key To COntinue...");
        getch();
    }
        return 0;
}

void admitPatient(){
  char myDate[12];
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  sprintf(myDate,"%02d/%02d/%d",tm.tm_mday,tm.tm_mon+1,tm.tm_year+1900);
  strcpy(p.date,myDate);

  fp=fopen("patient.txt","ab");

  printf("Enter Patient id:");
  scanf("%d",&p.id);

  printf("Enter patient name: ");
  fflush(stdin);
  gets(p.patientName);

  printf("Enter Patient Address: ");
  fflush(stdin);
  gets(p.patientAddress);

  printf("Enter Patient Disease: ");
  fflush(stdin);
  gets(p.patientDisease);

  printf("\nPatient Added Successfully");

  fwrite(&p,sizeof(p),1,fp);
  fclose(fp);
}
void patienList(){

  system("cls");
  printf("<=== Patient List ===>\n\n");
  printf("%-10s %-30s %-30s %-20s %s\n","Id","Patient Name","Address","Disease","Date");
  printf("----------------------------------------------------\n");

  fp=fopen("patient.txt","rb");
  while(fread(&p,sizeof(p),1,fp)==1){
    printf("%-10d %-30s %-30s %-20s %s\n", p.id, p.patientName, p.patientAddress, p.disease, p.date);
  }
  fclose(fp);

}




