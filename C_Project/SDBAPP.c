#include "SDB.h"

void SDB_APP ()
{
    printf("Welcome to the student database using c\n\n");
    printf("Please enter the first 3 students data\n\n");

    intialize_Struct();
    SDB_AddEntry();
    SDB_AddEntry();
    SDB_AddEntry();
    int i;

    printf(" 1. To add entry, enter 1 \n 2. To get used size in database, enter 2 \n 3. To read student data, enter 3 \n 4. To get the list of all student IDs, enter 4 \n 5. To check is ID is existed, enter 5 \n 6. To delete student data, enter 6 \n 7. To check is database is full, enter 7 \n 8. To exit enter 0\n");

    while(scanf("%d",&i))
    {
        if(i == 0)
            return 0;
        else if(i == 1)
            SDB_action((uint8)i);
        else if(i == 2)
            SDB_action((uint8)i);
        else if(i == 3)
            SDB_action((uint8)i);
        else if(i == 4)
            SDB_action((uint8)i);
        else if(i == 5)
            SDB_action((uint8)i);
        else if(i == 6)
            SDB_action((uint8)i);
        else if(i == 7)
            SDB_action((uint8)i);
        else
            printf("Please enter a valid choice between 0 - 7\n");

        printf(" 1. To add entry, enter 1 \n 2. To get used size in database, enter 2 \n 3. To read student data, enter 3 \n 4. To get the list of all student IDs, enter 4 \n 5. To check is ID is existed, enter 5 \n 6. To delete student data, enter 6 \n 7. To check is database is full, enter 7 \n 8. To exit enter 0\n");

    }


}

void SDB_action (uint8 choice)
{
    uint32 id,list[10];
    uint8 size;
    bool IsFull,IsExsit;

    switch(choice)
    {
    case 1:
        IsFull = SDB_AddEntry();
        if(IsFull == false)
            printf("\nSorry the database is full\n\n");
    break;
    case 2:
        printf("\nThe use of data is  : %d\n\n",(uint32)SDB_GetUsedSize());
    break;
    case 3:
        printf("\nPlease enter the student's id : ");
        scanf("%d",&id);
        printf("\n");
        IsExsit = SDB_ReadEntry(id);
        if(IsExsit == false)
            printf("\nSorry this id doesn't exsit\n");
        printf("\n");
    break;
    case 4:
        SDB_GetList(&size,&list);
        printf("\nThe students ids in the database are : \n");
        for(int i = 0 ; i < size ; i++)
        {
            printf("%d\n",list[i]);
        }
        printf("\n");
    break;
    case 5:
        printf("\nPlease enter the id : ");
        scanf("%d",&id);
        printf("\n");
        IsExsit = SDB_IsIdExist(id);
        if(IsExsit == true)
            printf("\nThe id exist in the database.\n\n");
        else
            printf("\nThe id doesn't exist in the database.\n\n");
    break;
    case 6:
        printf("\nPlease enter the id wanted to be delete : ");
        scanf("%d",&id);
        printf("\n");
        SDB_DeletEntry(id);

    break;
    case 7:
        IsFull = SDB_IsFull();
        if(IsFull == true)
            printf("\nThe database is full.\n\n");
        else
            printf("\nThe database isn't full yet\n\n");
    break;
    }
}

