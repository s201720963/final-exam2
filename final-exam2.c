#include <stdio.h>
#include <stdlib.h>

typedef struct{
    double weight[20];
    double height[20];
}human;

human ary[20];

int window();
void operate(int token);
void BMI();
void calorie();
void user_list();

int main()
{
    int month, day, i, j;
    char *id;
    char *pw;
        char *in_pw = "201720963";

    id = (char *)malloc(sizeof(char) *10);
    pw = (char *)malloc(sizeof(char) *10);

    month = (*(id+4) -'0') *10 + (*(id+5) -'0');
    day = (*(id+6) -'0') *10 + (*(id+7) - '0');
    
    while(1)
    {
        printf("input: ");
        scanf("%s", id);

        if(month < 1 || month > 12)
        {
            printf("error \n");
            continue;
        }
        else if(day < 1 || day > 31)
        {
            printf("error \n");
            continue;
        }
        else
            break;
    }
    while(1)
    {
        printf("input: ");
        scanf("%s", pw);

        for(i = 0; i < 9; i++)
        {
            if(*(pw+i) != *(in_pw +i))
            {
                j = 0;
                break;
            }
            j = 1;
        }
        if(j)
        {
            printf("error \n");
            continue;
        }
        else
            printf("login \n");
            break;
    }

    free(id);
    free(pw);
    operate(int token);

    return 0;
}
int window()
{
    int token;

    printf("1.BMI 2.Calorie 3.user_list 0.exit \n");
    printf("input: ");
    scanf("%d", &token);

    return token;
}
void operate(int token)
{
    int c;

    while((c = window()) != 0)
    {
        switch(c)
        {
            case 0: exit(1);
                break;
            case 1: BMI();
                break;
            case 2: calorie();
                break;
            case 3: user_list();
                break;
            default: printf("error \n");
                break;
        }
    }
}
void BMI()
{
    int i;
    double bmi = 0;
    int count = 1;

    for(i  = 0; i < 3; i++)
    {
        printf("input: ");
        scanf("%lf %lf", &ary[i].weight[i], &ary[i].height[i]);

        bmi = ary[i].weight[i] / (ary[i].height[i] * ary[i].height[i]) * 10000;

        if(bmi > 30)
            printf("overweight \n");
        else if(bmi >= 25)
            printf("middleweight \n");
        else if(bmi >= 19)
            printf("nomal \n");
        else
            printf("underweight \n");

        printf("user_%d \n", count);
        printf("bmi:%.1f \n", bmi);
        count++;
    }
}
void calorie()
{
    int i;
    int gender;
    int age;
    double result = 0;
    int count = 1;

    for(i = 0; i < 3; i++)
    {
        printf("input age gender: ");
        scanf("%d %d", &age, &gender);

        if(gender ==  1)
        {
            result = 66 +(13 * ary[i]. weight[i]) + (5 * ary[i].height[i]) -(6 * age);
        }
        else if(gender == 2)
        {
            result = 655.1 + (9 * ary[i].weight[i]) + (1.43 * ary[i].height[i]) - (4 * age);
        }
        else
            printf("error \n");

        printf("user_%d \n", count);
        printf("result: %.1f \n", result);
        count++;
    }
}
void user_list()
{
    int i;
    int count = 1;

    for(i = 0; i < 3; i++)
    {
        printf("user_%d \n", count);
        printf("weight: %.1f \n", ary[i].weight[i]);
        printf("height: %.1lf \n", ary[i].height[i]);
        count++;
    }
}







