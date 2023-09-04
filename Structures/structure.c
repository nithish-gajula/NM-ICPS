#include <stdio.h>

struct  Subjects
{
    int science;
    int maths;
    int social;
};

struct Student
{
    char name[50];
    int rollno;
    struct Subjects marks;
};

void printStudents(struct Student s, int students){

    printf("\nStudent name : %s",s.name);
    printf("\nStudent rollno : %d",s.rollno);
    printf("\nStudent marks in science : %d",s.marks.science);
    printf("\nStudent marks in maths : %d",s.marks.maths);
    printf("\nStudent marks in social : %d",s.marks.social);

}

int main(){

    

    int students;
    printf("\nEnter No.of students : ");
    scanf("%d", &students);
    struct Student s[students];

    printf("size = %d",sizeof(s[0]));

    for(int i=0; i<students; i++){
        printf("\nEnter Student %d details ---------------",i);
        printf("\nEnter student name : ");
        scanf("%s",s[i].name);
        printf("Enter student rollno : ");
        scanf("%d",&s[i].rollno);
        printf("Enter marks in science : ");
        scanf("%d",&s[i].marks.science);
        printf("Enter marks in maths : ");
        scanf("%d",&s[i].marks.maths);
        printf("Enter marks in social : ");
        scanf("%d",&s[i].marks.social);
    }

    for (int i = 0; i < students; i++)
    {
        printStudents(s[i],students);
    }
    

    return 0;
}



