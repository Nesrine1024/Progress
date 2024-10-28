#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <libgen.h>
#include <string.h>
#define MAX_NAME_LETTERS 50
int main()
{
    char name[MAX_NAME_LETTERS],name_in_grade[MAX_NAME_LETTERS],name_of_subject[MAX_NAME_LETTERS],name_in_continuos_assissment_grade[MAX_NAME_LETTERS];
    int input_password, input_registration_number, password, registration_number;
    float grad_of_continuos_assessment,exam_grades;
    FILE *PASSWORDSREGISTRATIONNUMBERNAMES=fopen("the_file_of_passwords_&_registration_numbers&names.txt","r");

    if(PASSWORDSREGISTRATIONNUMBERNAMES==NULL){
        printf("The file is empty or not found.\n");
        return 0;
    } 
    int found=0;
    printf("Enter the password: ");
    scanf("%d",&input_password);
    printf("Enter the registration number: ");
    scanf("%d",&input_registration_number);

    while(fscanf(PASSWORDSREGISTRATIONNUMBERNAMES,"%d %d %s",&password,&registration_number,name)!=EOF){
        if (input_password==password && input_registration_number==registration_number){
            printf("Welcome %s!\n",name);

            found=1;
            break;
        } 
    }
    if(!found){
        printf("The password or registration number is invalid, please try again later.\n");
    }
    fclose(PASSWORDSREGISTRATIONNUMBERNAMES);//The name & registration number & password PART;
    int choose;
    printf("Choose:\n1.Exam grades.    2.Continous assessment.    3.Academic transcripts.\n");
    scanf("%d",&choose);///
    FILE *EXAMGRADES;
    FILE *SUBJECTES;
    FILE *GRADES_OF_CONTINUOS_ASSESSMENTS;
    FILE *SUBJECTES_OF_CONTINUOS_ASSESSMENTS;
    EXAMGRADES=fopen("Exam_grades.txt","r");
    SUBJECTES=fopen("The_subjects.txt","r");
    GRADES_OF_CONTINUOS_ASSESSMENTS=fopen("Continous_assessment_grades.txt","r");
    SUBJECTES_OF_CONTINUOS_ASSESSMENTS=fopen("Continous_assessment's_subjects.txt","r");
    //////////
    if (EXAMGRADES==NULL || SUBJECTES==NULL || GRADES_OF_CONTINUOS_ASSESSMENTS==NULL || SUBJECTES_OF_CONTINUOS_ASSESSMENTS==NULL) {
            printf("The file is empty or not found.\n");
            return 0;
        }
        switch(choose)
        {
        case 1:
        if(choose==1){
            while(fscanf(EXAMGRADES,"%s",name_in_grade)!=EOF){
                if(strcmp(name_in_grade,name)==0){
                    while(fscanf(SUBJECTES,"%s",name_of_subject)!=EOF && fscanf(EXAMGRADES,"%f",&exam_grades)!=EOF){
                    printf("The grade of Subject %s is: %.2f\n",name_of_subject,exam_grades);
        }
        fclose(EXAMGRADES);
        fclose(SUBJECTES);
            }
        }}
            break;
        case 2:
        if(choose==2){
            while(fscanf(GRADES_OF_CONTINUOS_ASSESSMENTS,"%s",name_in_continuos_assissment_grade)!=EOF){
                if(strcmp(name_in_continuos_assissment_grade,name)==0){
                   while(fscanf(SUBJECTES_OF_CONTINUOS_ASSESSMENTS,"%s",name_in_continuos_assissment_grade)!=EOF && fscanf(GRADES_OF_CONTINUOS_ASSESSMENTS,"%f",&grad_of_continuos_assessment)!=EOF){
                   printf("The continuos assessment's grade of Subject %s is: %.2f\n",name_of_subject,grad_of_continuos_assessment);
        }
        fclose(GRADES_OF_CONTINUOS_ASSESSMENTS);
        fclose(SUBJECTES_OF_CONTINUOS_ASSESSMENTS);
            }
        }}
        break;
        default:
        printf("Invalid choice.\n");
            break;
        }
    return 0;
    
}