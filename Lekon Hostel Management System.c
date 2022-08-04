/* MINI PROJECT ON HOSTEL MANAGEMENT */
/* PROGRAM IN C-LANGUAGE */
/* LEKON - HOSTEL MANAGEMENT */
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
struct Student
{
    int rollnumber;
    char name[100];
    char phone[100];
    int  roomno;
    struct Student *next;
    
}*head;
void insert(int rollnumber, char* name, char* phone,int roomno)
{
    struct Student *temp;
    struct Student * student = (struct Student *) malloc(sizeof(struct Student));
    student->rollnumber = rollnumber;
    student->roomno = roomno;
    strcpy(student->name, name);
    strcpy(student->phone, phone);
    student->next = NULL;
    
    if(head==NULL){
        head = student;
        temp = head;
    }
    else{
        temp->next= student;
        temp = temp->next;
    }
    
}
void search(int roomno)
{
    struct Student * temp = head;
    while(temp!=NULL){
        if(temp->roomno==roomno){
            printf("Room number        : %d\n", temp->roomno);
            printf("Name of the student: %s\n", temp->name);
            printf("Roll Number        : %d\n", temp->rollnumber);
            printf("Phone              : %s\n", temp->phone);
            return;
        }
        temp = temp->next;
    }
    printf("This room is not allotted to any student this room is empty");
}
void search1(int rollnumber)
{
    struct Student * temp = head;
    while(temp!=NULL){
        if(temp->rollnumber==rollnumber){
            printf("Room number        : %d\n", temp->roomno);
            printf("Name of the student: %s\n", temp->name);
            printf("Roll Number        : %d\n", temp->rollnumber);
            printf("Phone              : %s\n", temp->phone);
            return;
        }
        temp = temp->next;
    }
    printf("Student with roll number %d is not found !!!\n", rollnumber);
}
void update(int roomno)
{
    
    struct Student * temp = head;
    while(temp!=NULL)
    {
        if(temp->roomno==roomno)
        {
            printf("Record with room number %d Found !!!\n", roomno);
            printf("Enter new student name: ");
            scanf("%s", temp->name);
            printf("Enter new roll number : ");
            scanf("%d",&temp->rollnumber);
            printf("Enter new phone number: ");
            scanf("%s", temp->phone);
            printf("Updation Successful!!!\n");
            return;
        }
        temp = temp->next;
    }
    printf("room with this room number %d is not allocated to any body !!!\n", roomno);
    
}
void Delete(int roomno)
{
    struct Student * temp = head;
    while(temp!=NULL)
    {
        
        if(temp->roomno==roomno)
        {
            printf("Record with room number %d Found !!!\n", roomno);
            strcpy(temp->name," ");
            temp->rollnumber=0;
            strcpy(temp->phone," ");
            printf("Successfully Vacated the room with room number '%d' ,Now this room is ready for new allottement !!!\n",roomno);
            return;
        }
        temp = temp->next;    
    }
    if(roomno>temp->roomno)
    {
    printf("Already room number %d is vacate !!!\n",roomno);
    }
    
}
void display()
{
    struct Student * temp = head;
    while(temp!=NULL){
        printf("\nRoom number        : %d\n",temp->roomno);
        printf("Name of the student: %s\n", temp->name);
        printf("Roll Number        : %d\n", temp->rollnumber);
        printf("Phone              : %s\n", temp->phone);
        temp = temp->next;
        
    }
}
int main()
{
    head = NULL;
    int roomno=0;
    int choice;
    char name[100];
    char phone[100];
    int rollnumber;
    printf("\n\t\t\t\t\t\t  ***************************");
    printf("\n\t\t\t\t\t\t  **LEKON-HOSTEL MANAGEMENT**");
    printf("\n\t\t\t\t\t\t  ***************************");
    printf("\n\n\nFOLLOW THE BELOW INSTRUCTIONS :- \n");
    printf("****** *** ***** ************ ");
    printf("\n=> to Allot a room to the student  - 1\n=> to search Room details          - 2\n=> to Vacate the room              - 3\n=> to update Room allottemet       - 4\n=> to display all the Room details - 5\n=> to search for student details   - 6\n=> to quit                         - 7\n");
    l:
    printf("\nEnter Choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
            case 1:
                printf("\nAlloted Room number       : %d\n",++roomno);
                printf("Enter name of the student : ");
                scanf("%s", name);
                printf("Enter roll number         : ");
                scanf("%d", &rollnumber);
                printf("Enter phone number        : ");
                scanf("%s", phone);
                insert(rollnumber, name, phone,roomno);
                goto l;
                break;
            case 2:
                printf("Enter room number to search: ");
                scanf("%d", &roomno);
                search(roomno);
                goto l;
                break;
            case 3:
                printf("Enter room number to vacate the room: ");
                scanf("%d", &roomno);
                Delete(roomno);
                goto l;
                break;
            case 4:
                printf("Enter room number to update: ");
                scanf("%d", &roomno);
                update(roomno);
                goto l;
                break;
            case 5:
                display();
                goto l;
                break;
            case 6:
                printf("Enter roll number to search: ");
                scanf("%d", &rollnumber);
                search1(rollnumber);
                goto l;
                break;
            case 7: exit(0);
            
            default: printf("WRONG CHOICE IS ENTERED PLEASE TRY AGAIN");
            goto l;
    }
}
