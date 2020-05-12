#include <stdio.h>
#include <string.h>
#include "base.h"
#include "extras.h"
#include "record.h"
/**
*1. add new member to class
*2. Print all members
*3. Search memebr (name/age/classname)
*4. Update member detail
*5. Delete a member
*6. Delete multiple member
*7. Save to a data file.
*8. Make a new data file of class
*9. Optimize the records(defragmentation)
*10. Sort (name/age/classname)
*11. rank member by Depending on their watching time in selected file.
*12. Quit
*/
#define MAX_RECORDS 1000

// function prototypes
void input_handler(char[], Record[]);
void display_menu();

// main function
int main(){

	Record records[MAX_RECORDS];
  //load_all_members at the beginning.
  
	char user_input[64] = "";
	while(strcmp(user_input, "99") != 0){
    //load_all_members(records);
		display_menu();
		printf("\nSelect a menu> ");
		fgets(user_input, 64, stdin);
		user_input[strlen(user_input)-1] = '\0';
		input_handler(user_input, records);
	}

	return 0;
}

// Function: input_handler()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// - Handles the user input and invokes functions that correspond to the user input
void input_handler(char input[], Record records[]){
  
	// TODO: Modify this function as you need

	if(!strcmp(input, "1"))
		add_a_record(records);
	else if(!strcmp(input, "2"))
		print_all_records(records);	
	else if(!strcmp(input,"3"))
    update_members_detail(records);
  else if(!strcmp(input, "4"))
		defragment(records);
	else if(!strcmp(input, "5"))
		display_stats(records);	
  else if(!strcmp(input, "6"))
    delete_member(records);
  else if(!strcmp(input, "7"))
    arrange_data(records);
  else if(!strcmp(input, "8"))
    update_studytime(records);
  else if(!strcmp(input, "9"))
    print_studytime_ranking(records);
  else if(!strcmp(input, "10"))
    delete_conditionally(records);
	else if(!strcmp(input, "99"))
		printf("Terminating... bye!\n"); // Quit - no operation (an empty statement with a semi-colon)
	else
		printf("Unknown menu: %s \n\n", input);
}


// Function: display_menu()
// Input: none
// Output: none
// - Leave a brief information about the function
void display_menu(){

	// TODO: Modify this function as you need

	printf("******************************\n");
	printf(" Membership management system \n");
	printf("******************************\n");
	printf(" 1. Add a new membber\n");
	printf(" 2. Print all members\n");
  	printf(" 3. update member's detail\n");
	printf(" 4. Optimize (defragment) the records\n");
	printf(" 5. Member statistics\n");
	printf(" 6. Delete a member\n");
  	printf(" 7. Arrange Data(Sorting)\n");
  	printf(" 8. Update StudyTime\n");
  	printf(" 9. Show Rank (StudyTime)\n");
    printf(" 10. Delete with condition (StudyTime)\n");
  	printf(" 99. Quit\n");
}

