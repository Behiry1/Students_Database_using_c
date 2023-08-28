#include "STD.h"
#include "SDB.h"
void intialize_Struct()
{
    for(int i = 0 ; i < 10 ; i++)
    {
        students[i].Student_ID = 0;
    }
}

bool SDB_IsFull()
{
    if(students[9].Student_ID == 0)
        return false;
    else
        return true;

}

uint8 SDB_GetUsedSize()
{
    uint8 size = 0;

    for(int i = 0 ;i< 9 ;i++)
    {
        if(students[i].Student_ID != -1)
            size++;
        else
            break;
    }

    return size;

}

bool SDB_AddEntry()
{
    static uint32 entry = 0;

    if(SDB_IsFull() || entry >9)
        return false;
    else
    {
       printf("Please enter the student %d id\n",entry+1);
       while(!scanf("%d",&students[entry].Student_ID) )
       {
           printf("Please Enter a valid input\n");
           printf("Please enter the student %d id\n",entry+1);
           flush();
       }

       printf("Please enter the student %d year\n",entry+1);
       while(!scanf("%d",&students[entry].Student_year) )
       {
           printf("Please Enter a valid input\n");
           printf("Please enter the student %d year\n",entry+1);
           flush();
       }

       printf("Please enter the student %d course 1 id\n",entry+1);
       while(!scanf("%d",&students[entry].Course1_ID) )
       {
           printf("Please Enter a valid input\n");
           printf("Please enter the student %d course 1 id\n",entry+1);
           flush();
       }

       printf("Please enter the student %d course 1 grade\n",entry+1);
       while(!scanf("%d",&students[entry].Course1_grade) )
       {
           printf("Please Enter a valid input\n");
           printf("Please enter the student %d course 1 grade\n",entry+1);
           flush();
       }

       printf("Please enter the student %d course 2 id\n",entry+1);
       while(!scanf("%d",&students[entry].Course2_ID) )
       {
           printf("Please Enter a valid input\n");
           printf("Please enter the student %d course 2 id\n",entry+1);
           flush();
       }

       printf("Please enter the student %d course 2 grade\n",entry+1);
       while(!scanf("%d",&students[entry].Course2_grade) )
       {
           printf("Please Enter a valid input\n");
           printf("Please enter the student %d course 2 grade\n",entry+1);
           flush();
       }

       printf("Please enter the student %d course 3 id\n",entry+1);
       while(!scanf("%d",&students[entry].Course3_ID) )
       {
           printf("Please Enter a valid input\n");
           printf("Please enter the student %d course 3 id\n",entry+1);
           flush();
       }

       printf("Please enter the student %d course 3 grade\n",entry+1);
       while(!scanf("%d",&students[entry].Course3_grade) )
       {
           printf("Please Enter a valid input\n");
           printf("Please enter the student %d course 3 grade\n",entry+1);
           flush();
       }

    }

    entry++;
    return true;
}

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

}

bool SDB_ReadEntry (uint32 id)
{
    if(SDB_IsIdExist(id))
    {
        int i = Get_Entry(id);
        printf("%d\n%d\n%d\n%d\n%d\n&d\n%d\n%d\n",students[i].Student_ID,students[i].Student_year,students[i].Course1_ID,students[i].Course1_grade,students[i].Course2_ID,students[i].Course2_grade,students[i].Course3_ID,students[i].Course3_grade);
    }
    else
    {
        return false;
    }

    return true;
}

void SDB_GetList (uint8 * count, uint32 * list)
{
    int j = 0;
    for(int i = 0;i<9;i++)
    {
        if(students[i].Student_ID !=0)
        {
            list[j] = students[i].Student_ID;
            j++;
            count++;
        }

    }

}

bool SDB_IsIdExist (uint32 id)
{
    for(int i = 0 ; i< 9;i++)
    {
        if(students[i].Student_ID == id)
            return true;
    }

    return false;
}

void flush()
{
    char c;
    while((c=getchar())!='\n');
    return;
}

int Get_Entry(uint32 id)
{
    for(int i = 0 ; i<9;i++)
    {
        if(students[i].Student_ID == id)
            return i;
    }
}

