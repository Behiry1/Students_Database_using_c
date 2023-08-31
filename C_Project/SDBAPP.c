#include "SDB.h"
void SDB_APP ()
{
    intialize_Struct();
    SDB_AddEntry();
    //SDB_AddEntry();
    //SDB_AddEntry();
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
    //SDB_DeletEntry()

}

void SDB_action (uint8 choice)
{


}

