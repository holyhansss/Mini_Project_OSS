#include <stdio.h>
#include "extras.h"
#include "base.h"
#include <string.h>
// Function: defragment()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: 1 if successful, otherwise 0
// - Leave a brief information about the function
int defragment(Record records[]){
	// TODO: Modify this function as you need

  int num_of_members = load_all_members(records);
  int num =0;
  for(int i=0;i<num_of_members;i++){
    if(strcmp(records[i].name.firstName, "0")==0 &&strcmp(records[i].name.lastName, "0")==0){
        for(int j=i;j<num_of_members-1;j++){
          strcpy(records[j].name.firstName,records[j+1].name.firstName);
          strcpy(records[j].name.lastName,records[j+1].name.lastName);
          records[i].age = records[i+1].age;
          strcpy(records[j].email,records[j+1].email);
          strcpy(records[j].classname,records[j+1].classname);
          num++;
        }
    }
  }
  
  //save to Report.txt, data.txt
  if(num >= 1){
  save_report(records,num_of_members-1);
  save_data(records,num_of_members-1);
  printf("successfully Optimized!!\n\n");
  return 1;
  }
  else return 0;	// TODO: return 1 if defragment succeed; return 0 otherwise 
}

void arrange_data(Record records[]){
  int num_of_members = load_all_members(records);
  Record temp[1];

  printf("Arranging by Age\n");
    for(int i=0;i<num_of_members;i++){
      for(int j=i;j<num_of_members;j++){
        if(records[i].age > records[j].age){
          temp[0] = records[i]; 
          records[i] = records[j];
          records[j] = temp[0];
        }
      }
    }

  printf("successfully Arranged!!!\n\n");
  save_report(records,num_of_members);
  save_data(records,num_of_members);

}

void display_stats(Record records[]){
	// TODO: Modify this function as you need
  int num_of_members = load_all_members(records);
  int input;
  char str[20];
  int inputAge;
  printf("Pick informantion\n");
  printf("1. Firstname 2. Lastname 3. Age 4. Classname 5. email (type number): ");
  scanf("%d",&input);

  if(input == 1){
    printf("Input Firstname: ");
    scanf("%s",str);
    for(int i=0;i<num_of_members;i++){
      if(strcmp(records[i].name.firstName,str)==0){
        printf("%s %s\t\t %2d %20s%30s\n",records[i].name.firstName,records[i].name.lastName,records[i].age,records[i].classname,records[i].email);
      }
    }
    printf("\n");
  }

  if(input == 2){
    printf("Input Lastname: ");
    scanf("%s",str);
    for(int i=0;i<num_of_members;i++){
      if(strcmp(records[i].name.lastName,str)==0){
        printf("%s %s\t\t %2d %20s%30s\n",records[i].name.firstName,records[i].name.lastName,records[i].age,records[i].classname,records[i].email);
      }
    }
    printf("\n");
  }

  if(input == 3){
    printf("Input Age: ");
    scanf("%d",&inputAge);
    for(int i=0;i<num_of_members;i++){
      if(inputAge == records[i].age){
        printf("%s %s\t\t %2d %20s%30s\n",records[i].name.firstName,records[i].name.lastName,records[i].age,records[i].classname,records[i].email);
      }
    }
    printf("\n");
  }

  if(input == 4){
    printf("Input Classname: ");
    scanf("%s",str);
    for(int i=0;i<num_of_members;i++){
      if(strcmp(records[i].classname,str)==0){
        printf("%s %s\t\t %2d %20s%30s\n",records[i].name.firstName,records[i].name.lastName,records[i].age,records[i].classname,records[i].email);
      }
    }
    printf("\n");
  }
  char *strEmail;

  if(input == 5){
   
    printf("Input Only after @ \nEx)gmail.com,naver.com etc...\n");
    printf("Input Email: ");
    scanf("%s",str);
    for(int j=0;j<num_of_members;j++){
        strtok(records[j].email,"@");
        strEmail = strtok(NULL,"@");
      
      if(strcmp(str,strEmail)==0){
        printf("%s %s\t\t %2d %20s%20s@%s\n",records[j].name.firstName,records[j].name.lastName,records[j].age,records[j].classname,records[j].email,strEmail);
      }
    }
    printf("\n");
  }
  getchar();
}

void update_studytime(Record records[]){
  int num_of_members = load_all_members(records);
  char fname[24];
  char lname[24];
  int minute;
  printf("Who's study time do you want to update?\n");
  printf("Firstname: ");
  scanf("%s",fname);
  printf("Lastname: ");
  scanf("%s",lname);

  for(int i=0;i<num_of_members;i++){
    if(strcmp(records[i].name.firstName,fname) == 0 && strcmp(records[i].name.lastName,lname) == 0){
      printf("How long did %s %s studied? (In minute)",records[i].name.firstName,records[i].name.lastName);
      scanf("%d",&minute);
      records[i].studyTime = records[i].studyTime + minute;
    }
  }  
  printf("successfully Updated!!!\n\n");
  save_report(records,num_of_members);
  save_data(records,num_of_members);
  getchar();
}
void print_studytime_ranking(Record records[]){

  int num_of_members = load_all_members(records);
  Record temp[1];

  
    for(int i=0;i<num_of_members;i++){
      for(int j=i;j<num_of_members;j++){
        if(records[i].studyTime < records[j].studyTime){
          temp[0] = records[i]; 
          records[i] = records[j];
          records[j] = temp[0];
        }
      }
    }
  for(int i=0;i<num_of_members;i++){
    printf("%d: %s %s : %d\n",i+1,records[i].name.firstName,records[i].name.lastName,records[i].studyTime);
  }
  printf("\n");
}

//Adding a new feature writer : YunPC #2
//Erase the records of students who have studied below a certain time. 
void delete_conditionally(Record records[]){
     int num_of_members = load_all_members(records);
    int time;

  printf("Erase the records of students who have studied below a certain time.");
  printf("\nPlease enter the time.");
  scanf("%d", &time);
  getchar();

    for(int i=0;i<num_of_members;i++){
      if(records[i].studyTime < time){
        strcpy(records[i].name.firstName,"0");
        strcpy(records[i].name.lastName,"0");
        records[i].age = 0;
        strcpy(records[i].email,"0");
        strcpy(records[i].classname,"0");
        records[i].studyTime = 0;
      }
    }

  //save to Report.txt, data.txt
  save_report(records,num_of_members);
  save_data(records,num_of_members);
}

