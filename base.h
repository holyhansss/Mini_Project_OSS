#ifndef _BASE_H_
#define _BASE_H_

#include "record.h"

// function prototypes
int load_all_members(Record[]);
void save_report(Record[],int);
void save_data(Record[],int);
void print_all_records(Record[]);
void add_a_record(Record[]);
void update_members_detail(Record[]);
void delete_member(Record[]);
#endif
