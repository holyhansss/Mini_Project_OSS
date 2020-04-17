#ifndef _RECORD_H_
#define _RECORD_H_

// type defition
typedef struct{
  char firstName[20];
  char lastName[20];
} Name;

typedef struct{
	Name name;
  int age;
  char classname[20];
  char email[50];
  int studyTime;
	// TODO: define your own structure type here

} Record;


#endif
