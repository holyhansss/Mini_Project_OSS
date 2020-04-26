#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "base.h"

// Function: print_all_records()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// Read data from data.txt and print them out
void print_all_records(Record records[]){
  
  int num_of_members = load_all_members(records);
  
  printf("\nAll Member's Records\n****************************************\n");
  printf("   Name\t\t\t  age\t\t\t Classname\t\t\t\tEmail\n");
  //printing out all members records
  for(int j=0;j<num_of_members;j++){
    printf("%s %s\t\t %2d %20s%30s\n",records[j].name.firstName,records[j].name.lastName,records[j].age,records[j].classname,records[j].email);
  }
  printf("\n");

  //save to Report.txt, data.txt
  save_report(records,num_of_members);
  save_data(records,num_of_members);

}


// Function: add_a_record()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// Get a name, age, and classname and save it to the data.txt
void add_a_record(Record records[]){
	// TODO: Modify this function as you need
  int num_of_members = load_all_members(records);

  printf("Input Members Detail\n");
  printf("Last Name? ");
  scanf("%s",records[num_of_members].name.lastName);
  printf("First Name? ");
  scanf("%s",records[num_of_members].name.firstName);
  printf("Age? ");
  scanf("%d",&records[num_of_members].age);
  printf("Classname(Math, English, History)? ");
  scanf("%s",records[num_of_members].classname);
  printf("Email Address?");
  scanf("%s",records[num_of_members].email);

  getchar();
 //create new member
  FILE* fp1;
  fp1 = fopen("data.txt","a");
  
  fprintf(fp1,"%s %s %d %s %s 0\n",records[num_of_members].name.lastName,records[num_of_members].name.firstName,records[num_of_members].age,records[num_of_members].classname,records[num_of_members].email);

  printf("Finished adding a new member!!!\n");
  getchar();
  printf("\n");
  fclose(fp1);

  //save to Report.txt, data.txt
  save_report(records,num_of_members);

}

void update_members_detail(Record records[]){
  int num_of_members = load_all_members(records);
  char info_first[24],info_last[24];
  int num=0;
  int k;

  printf("Who's Information do you want to update?");
  printf("\nType ""quit"" to quit");
  printf("\nType Firstname: ");
  scanf("%s",info_first);
  printf("Type Lastname: ");
  scanf("%s",info_last);
  getchar();
  if(strcmp(info_last,"quit") != 0 && strcmp(info_first,"quit")!=0){
    for(int i=0;i<num_of_members;i++){
      if(strcmp(info_last,records[i].name.lastName) == 0 && strcmp(info_first,records[i].name.firstName) == 0){
        num++;
        printf("%s %s %d %s\n",records[i].name.firstName,records[i].name.lastName,records[i].age,records[i].email);
        k=i;
        
      }
    }
  int type;
  char change_to[50];
  if(num == 1){
    printf("Which information do you want to update?\n");
    printf("1. Lastname 2.Firstname 3.age 4.email 5.Class (type as number): ");
    scanf("%d",&type);
    printf("change to: ");
    scanf("%s",change_to);
    if(type == 1){
      strcpy(records[k].name.lastName,change_to);
    }
    else if(type == 2){
      strcpy(records[k].name.firstName,change_to);
    }
    else if(type == 3){
      records[k].age = atoi(change_to);
    }
    else if(type == 4){
      strcpy(records[k].email,change_to);
    }
    else if(type == 5){
      strcpy(records[k].classname,change_to);

    }
  
    }
  }

  //save to Report.txt, data.txt
  save_report(records,num_of_members);
  save_data(records,num_of_members);
 
  printf("Sucessfully changed!\n");
  
}

void delete_member(Record records[]){

  int num_of_members = load_all_members(records);
  char info_first[24],info_last[24];
  int k;

  printf("Who's Information do you want to delete?");
  printf("\nType ""quit"" to quit");
  printf("\nType Firstname: ");
  scanf("%s",info_first);
  printf("Type Lastname: ");
  scanf("%s",info_last);
  getchar();

  if(strcmp(info_last,"quit") != 0 && strcmp(info_first,"quit")!=0){
    for(int i=0;i<num_of_members;i++){
      if(strcmp(info_last,records[i].name.lastName) == 0 && strcmp(info_first,records[i].name.firstName) == 0){
        strcpy(records[i].name.firstName,"0");
        strcpy(records[i].name.lastName,"0");
        records[i].age = 0;
        strcpy(records[i].email,"0");
        strcpy(records[i].classname,"0");
        records[i].studyTime = 0;
      }
    }
  }

  //save to Report.txt, data.txt
  save_report(records,num_of_members);
  save_data(records,num_of_members);
}

int load_all_members(Record records[]){

  int i=0;
  //get records from file "data.txt"
  FILE* fp1;
  fp1 = fopen("data.txt","r");
  while(fscanf(fp1,"%s %s %d %s %s %d",records[i].name.firstName,records[i].name.lastName,&records[i].age,records[i].classname,records[i].email,&records[i].studyTime) !=EOF){
  i++;
  }
  //i = number of membets + 1
  fclose(fp1);
  return i;
}

void save_report(Record records[],int num_of_members){

  FILE* fp2;
  fp2 = fopen("report.txt","w");

  for(int k=0;k < num_of_members;k++){
  fprintf(fp2,"---------------------------\n");
  fprintf(fp2,"Name %s %s\t | Age: %d\n\tClassname: %s\n",records[k].name.firstName,records[k].name.lastName,records[k].age,records[k].classname);
  fprintf(fp2,"Email: %s\n",records[k].email);
  fprintf(fp2,"Studyrime: %d\n",records[k].studyTime);
  fprintf(fp2,"---------------------------\n");
  fprintf(fp2,"\n");
  }
  fclose(fp2);
}

void save_data(Record records[],int num_of_members){

  FILE* fp;
  fp = fopen("data.txt","w");
  
  for(int i=0;i<num_of_members;i++){
  fprintf(fp,"%s %s %d %s %s %d\n",records[i].name.firstName,records[i].name.lastName,records[i].age,records[i].classname,records[i].email,records[i].studyTime);  
  }

  fclose(fp);
}
