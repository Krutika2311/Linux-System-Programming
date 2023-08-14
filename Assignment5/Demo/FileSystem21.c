#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>

#pragma pack(1)
struct Student
{
    int Rollno;
    char Sname[20];
    float Marks;
    int Age;
};

int main(int argc, char *argv[])
{
    struct Student sobj;
    char Fname[20];
    int fd = 0;

    // sobj.Rollno = 11;
    // sobj.Marks = 89.99f;
    // sobj.Age = 25;
    // strcpy(sobj.Sname,"Krutika");

    printf("Enter the file name :\n");
    scanf("%s",Fname);

    fd = open(Fname,O_RDONLY);

    read(fd,&sobj,sizeof(sobj));

    // write(fd,&sobj,sizeof(sobj));

    printf("Roll number : %d \n",sobj.Rollno);
    printf("Name : %s \n",sobj.Sname);
    printf("Marks : %f \n",sobj.Marks);
    printf("Age : %d \n",sobj.Age);

    close(fd);

    return 0;
}