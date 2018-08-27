#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void printRecords();
void addRecords();
void CapitalLetter();
void deleteRecord();
void searchZip();
void searchSRange();
void medianScore();

struct student
{
    char firstName[21];
    char lastname[21];
    float scores;
    char zip[6];
    struct student* next;
};
struct student* head;

int main()
{
    int i,menuInput,numRecords;
    menuInput=1;


    puts("Please indicate the number of records you want to enter (min 5):");
    scanf("%d",&numRecords);
    printf("----------------------------------------\n");
    puts("Please input records of students (enter a new line after each record), with following format:\nfirst name last name score zip code\n");
    struct student* temp;

    for(i=0; i<numRecords; i++)
    {
        float tempScore;
        temp=(struct student*)malloc(sizeof(struct student));
        scanf("%s%s%f%s",temp->firstName,temp->lastname,&tempScore,temp->zip);
        temp->scores=tempScore;
        temp->next=NULL;
        if(i==0)
        {
            head=temp;
        }
        else if (i==1)
        {
            (head->next)=temp;
        }
        else
        {
            struct student *current=head;
            while(current!=NULL)
            {
                if((current->next)==NULL)
                {
                    (current->next)=temp;
                    break;
                }
                current=(current->next);
            }
        }

    }

    CapitalLetter();

    while (menuInput!= 0)
    {
        printf("----------------------------------------\n");
        puts("Print records (press 1) ");
        puts("Add a new record (press 2) ");
        puts("Delete Record(s) (press 3) ");
        puts("Search by zip code (press 4) ");
        puts("Search by score range (press 5) ");
        puts("Find median score (press 6)  ");
        puts("Exit the program (press 0) ");
        printf("\nEnter your choice: ");
        scanf("%d",&menuInput);
        printf("----------------------------------------\n");
        switch(menuInput)
        {

        case 1:
            printRecords();
            break;

        case 2:
            addRecords();
            break;

        case 3:
            deleteRecord();
            break;

        case 4:
            searchZip();
            break;

        case 5:
            searchSRange();
            break;

        case 6:
            medianScore();
            break;
        case 0:
            exit(0);
            break;
        }


    }

    return 0;
}

void printRecords()
{
    struct student *temp=head;
    printf("\n");
    while(temp!=NULL)
    {
        printf("Firstname: %s\tLastname: %s\tScore: %0.2f\tZipCode: %s\n",temp->firstName,temp->lastname,temp->scores,temp->zip);
        temp=(temp->next);

    }

    printf("\n");
}

void addRecords()
{
    int i,addNumber;
    puts("Please enter the number of records you want to add: ");
    scanf("%d",&addNumber);


    printf("----------------------------------------\n");
    puts("Please input records of students (enter a new line after each record), with following format:\nfirst name last name score zip code");
    struct student* temp;
    printf("\n");
    for(i=0; i<addNumber; i++)
    {
        float tempScore;
        temp=(struct student*)malloc(sizeof(struct student));
        scanf("%s%s%f%s",temp->firstName,temp->lastname,&tempScore,temp->zip);
        temp->scores=tempScore;
        temp->next=NULL;
        if((head->next)==NULL)
        {
            (head->next)=temp;
        }
        else
        {
            struct student *current=head;
            while(current!=NULL)
            {
                if((current->next)==NULL)
                {
                    (current->next)=temp;
                    break;
                }
                current=(current->next);
            }
        }

    }
    CapitalLetter();
    printf("\nThe records were added!\nThe updated list is:\n");
    printRecords();
}

void CapitalLetter()
{
    struct student *temp=head;
    while(temp!=NULL)
    {
        if((((temp->lastname)[0])>96)&&(((temp->lastname)[0])<123))
        {
            (temp->lastname)[0]=((temp->lastname)[0])-32;
        }
        if((((temp->firstName)[0])>96)&&(((temp->firstName)[0])<123))
        {
            (temp->firstName)[0]=((temp->firstName)[0])-32;
        }
        temp=(temp->next);

    }

}

void deleteRecord()
{
    char tempLN[21];
    int i;
    i=0;
    printf("Please enter the Last Name of Student you want to delete from record: \n");
    scanf("%s",&tempLN);
    if((tempLN[0]>96)&&(tempLN[0]<123))
    {
        tempLN[0]=tempLN[0]-32;
    }
    struct student *temp=head;
    struct student *prev;
    while ((temp != NULL) && (strcmp(temp->lastname,tempLN)==0))
    {
        head = temp->next;
        free(temp);
        printf("----------------------------------------\n");
        return;
    }




    while (temp != NULL && (strcmp(temp->lastname,tempLN)!=0))
    {
        prev = temp;
        temp = temp->next;


    }
    if (temp== NULL)
    {
        printf("The given last name was not found in Records.\n");
        return;
    }

    prev->next = temp->next;

    free(temp);

}

void searchZip()
{
    char givenZip[6];
    int counter=0;
    struct student *temp=head;
    printf("\n");
    printf("Please enter the zip that you want to search in student records: \n");
    scanf("%s",&givenZip);
    printf("----------------------------------------\n\n");
    while(temp!=NULL)
    {
        if(strcmp(temp->zip,givenZip)==0)
        {
            printf("Firstname: %s\tLastname: %s\tScore: %0.2f\tZipCode: %s\n",temp->firstName,temp->lastname,temp->scores,temp->zip);
            counter++;
        }
        temp=(temp->next);
    }
    if(counter==0)
    {
        printf("No records found from given Zip-Code!");
    }

    printf("\n");

}

void searchSRange()
{
    float maxScore, minScore;
    int counter=0;
    struct student *temp=head;
    printf("Please enter the Min Score Range: \n");
    scanf("%f",&minScore);
    printf("Please enter the Max Score Range: \n");
    scanf("%f",&maxScore);

    printf("----------------------------------------\n\n");
    while(temp!=NULL)
    {
        if(((temp->scores)>minScore)&&((temp->scores)<maxScore))
        {
            printf("Firstname: %s\tLastname: %s\tScore: %0.2f\tZipCode: %s\n",temp->firstName,temp->lastname,temp->scores,temp->zip);
            counter++;
        }
        temp=(temp->next);
    }
    if(counter==0)
    {
        printf("No records found from given Score Range!");
    }

    printf("\n");

}

void medianScore()
{
    int numRecord=0,i,j,counter=0;
    float tempScore;
    struct student *temp=head;
    while(temp!=NULL)
    {
        numRecord++;
        temp=(temp->next);

    }

    float scoreArray[numRecord],median;
    numRecord=0;
    temp=head;
    while(temp!=NULL)
    {
        scoreArray[numRecord]=(temp->scores);
        temp=(temp->next);
        numRecord++;
    }

    for (i=0; i<numRecord-1; i++)
    {
        for (j=0; j<numRecord-1-i; j++)
        {
            if (scoreArray[j]>scoreArray[j+1])
            {
                tempScore=scoreArray[j];
                scoreArray[j]=scoreArray[j+1];
                scoreArray[j+1]= tempScore;
            }
        }
    }


    if(numRecord%2==0)
    {
        median=((scoreArray[numRecord/2] + scoreArray[numRecord/2 - 1]) / 2.0);
    }
    else
    {
        median=scoreArray[numRecord/2];
    }
    printf("\nThe median is %0.2f.\n",median);
    for(i=0; i<numRecord; i++)
    {
        if(scoreArray[i]>median)
        {
            counter++;
        }

    }
    printf("%d students scored above median score.\n\n",counter);


}







