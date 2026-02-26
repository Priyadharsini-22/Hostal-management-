 #include <stdio.h> 
#include <stdlib.h> 
struct student { 
 int id; 
 char name[50]; 
 int room_no; 
 char dept[30]; 
}; 
void addStudent() { 
 struct student s; 
 FILE *fp; 
 fp = fopen("hostel.txt", "a"); 
 printf("Enter Student ID: ");  scanf("%d", &s.id);
 printf("Enter Name: "); 
 scanf("%s", s.name); 
 printf("Enter Room Number: ");  scanf("%d", &s.room_no); 
 printf("Enter Department: "); 
 scanf("%s", s.dept); 
 fwrite(&s, sizeof(s), 1, fp); 
 fclose(fp); 
 printf("Record Added Successfully!\n"); } 
void displayStudent() { 
 struct student s; 
 FILE *fp; 
 fp = fopen("hostel.txt", "r"); 
 while(fread(&s, sizeof(s), 1, fp)) {  printf("\nID: %d", s.id); 
 printf("\nName: %s", s.name);  printf("\nRoom No: %d", s.room_no);  printf("\nDepartment: %s\n", s.dept);  }
 fclose(fp); 
} 
int main() { 
 int choice; 
 while(1) { 
 printf("\n--- Hostel Management System ---");  printf("\n1. Add Student"); 
 printf("\n2. Display Students"); 
 printf("\n3. Exit"); 
 printf("\nEnter your choice: "); 
 scanf("%d", &choice); 
 switch(choice) { 
 case 1: 
 addStudent(); 
 break; 
 case 2: 
 displayStudent(); 
 break; 
 case 3: 
 exit(0); 
 default:
 printf("Invalid Choice!");  } 
 } 
 return 0; 
}
