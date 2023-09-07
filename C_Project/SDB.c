#include "STD.h"
#include "SDB.h"
static uint32 entry = 0;

//intialize the ids of the struct students with 0
void intialize_Struct()
{
    for(int i = 0 ; i < 10 ; i++)
    {
        students[i].Student_ID = 0;
    }
}

//check if the database is full or not
bool SDB_IsFull()
{
    if(entry > 9)
        return true;
    else
        return false;

}

//get the used size of the database
uint8 SDB_GetUsedSize()
{
    uint8 size = 0;

    for(int i = 0 ;i< 10 ;i++)
    {
        if(students[i].Student_ID != 0)
            size++;
        else
            break;
    }

    return size;

}

//add a new entry to the database
bool SDB_AddEntry()
{

    if(SDB_IsFull() || entry >9)
        return false;
    else
    {
       printf("Please enter the student %d id : ",entry+1);
       while(!scanf("%d",&students[entry].Student_ID) )
       {
           printf("Please Enter a valid input\n");
           printf("Please enter the student %d id : ",entry+1);
           flush();
       }

       printf("Please enter the student %d year : ",entry+1);
       while(!scanf("%d",&students[entry].Student_year) )
       {
           printf("Please Enter a valid input\n");
           printf("Please enter the student %d year : ",entry+1);
           flush();
       }

       printf("Please enter the student %d course 1 id : ",entry+1);
       while(!scanf("%d",&students[entry].Course1_ID) )
       {
           printf("Please Enter a valid input\n");
           printf("Please enter the student %d course 1 id : ",entry+1);
           flush();
       }

       printf("Please enter the student %d course 1 grade : ",entry+1);
       while(!scanf("%d",&students[entry].Course1_grade) )
       {
           printf("Please Enter a valid input\n");
           printf("Please enter the student %d course 1 grade : ",entry+1);
           flush();
       }

       printf("Please enter the student %d course 2 id : ",entry+1);
       while(!scanf("%d",&students[entry].Course2_ID) )
       {
           printf("Please Enter a valid input\n");
           printf("Please enter the student %d course 2 id : ",entry+1);
           flush();
       }

       printf("Please enter the student %d course 2 grade : ",entry+1);
       while(!scanf("%d",&students[entry].Course2_grade) )
       {
           printf("Please Enter a valid input\n");
           printf("Please enter the student %d course 2 grade : ",entry+1);
           flush();
       }

       printf("Please enter the student %d course 3 id : ",entry+1);
       while(!scanf("%d",&students[entry].Course3_ID) )
       {
           printf("Please Enter a valid input\n");
           printf("Please enter the student %d course 3 id : ",entry+1);
           flush();
       }

       printf("Please enter the student %d course 3 grade : ",entry+1);
       while(!scanf("%d",&students[entry].Course3_grade) )
       {
           printf("Please Enter a valid input\n");
           printf("Please enter the student %d course 3 grade : ",entry+1);
           flush();
       }
       printf("\n");
    }

    entry++;
    return true;
}

//delete an entry from the database
void SDB_DeletEntry (uint32 id)
{

    int i = Get_Entry(id);

    students[i].Student_ID=0;
    students[i].Student_year=0;
    students[i].Course1_ID=0;
    students[i].Course1_grade=0;
    students[i].Course2_ID=0;
    students[i].Course2_grade=0;
    students[i].Course3_ID=0;
    students[i].Course3_grade=0;
    Shift_Data(i);
    entry--;

}

//read the data of certain entry if exist
bool SDB_ReadEntry (uint32 id)
{
    if(SDB_IsIdExist(id))
    {
        int i = Get_Entry(id);
        printf("Student's id : %d\nStudent's year : %d\nCourse 1 id : %d\nCourse 1 grade : %d\nCourse 2 id : %d\nCourse 2 grade : %d\nCourse 3 id : %d\nCourse 3 grade : %d\n\n",students[i].Student_ID,students[i].Student_year,students[i].Course1_ID,students[i].Course1_grade,students[i].Course2_ID,students[i].Course2_grade,students[i].Course3_ID,students[i].Course3_grade);
    }
    else
    {
        return false;
    }

    return true;
}

//have an array of the actual ids in the database
void SDB_GetList (uint8* Count, uint32* List)
{
    uint8 ctr = 0;
    uint32 j = 0;
    for(int i = 0;i<10;i++)
    {
        if(students[i].Student_ID != 0)
        {
            List[j] = students[i].Student_ID;
            j++;
            ctr++;
        }

    }
    *Count = ctr;

}

//check if a certain exist in the database or not
bool SDB_IsIdExist (uint32 id)
{
    for(int i = 0 ; i< 10;i++)
    {
        if(students[i].Student_ID == id)
            return true;
    }

    return false;
}

//used to clear the input of the user, if he enters a non valid input
void flush()
{
    char c;
    while((c=getchar())!='\n');
    return;
}

//used for getting the entry of a certain id
int Get_Entry(uint32 id)
{
    for(int i = 0 ; i<10;i++)
    {
        if(students[i].Student_ID == id)
            return i;
    }
}

//used for shifting the data after deleting an entry
void Shift_Data(int start)
{
    for(int i = start ; i < 10 ; i++)
    {
        if(i == 9)
        {
            students[i].Student_ID = 0;
            students[i].Course1_grade = 0;
            students[i].Course1_ID = 0;
            students[i].Course2_grade = 0;
            students[i].Course2_ID = 0;
            students[i].Course3_grade = 0;
            students[i].Course3_ID = 0;
            students[i].Student_year = 0;
            break;
        }

        students[i] = students[i+1];
    }
}

