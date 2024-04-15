#include<stdio.h>
#include<string.h>

void generateAssignmentCode();
void generatePlusCode();
void generateDivCode();

int i, choice, j, length, address = 100;
char expression[10], exp[10], expPart1[10], expPart2[10], id1[5], operator[5], id2[5];

void main()
{
    while(1)
    {
        printf("\n1. Assignment\n2. Arithmetic\n3. Relational\n4. Exit\nEnter the choice:");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("\nEnter the expression with assignment operator:");
                scanf("%s", expression);
                length = strlen(expression);
                expPart2[0] = '\0';
                i = 0;
                while(expression[i] != '=')
                {
                    i++;
                }
                strncat(expPart2, expression, i);
                strrev(expression);
                expPart1[0] = '\0';
                strncat(expPart1, expression, length - (i + 1));
                strrev(expPart1);
                printf("Three address code:\ntemp=%s\n%s=temp\n", expPart1, expPart2);
                break;

            case 2:
                printf("\nEnter the expression with arithmetic operator:");
                scanf("%s", exp);
                strcpy(expression, exp);
                length = strlen(expression);
                expPart1[0] = '\0';
                for(i = 0; i < length; i++)
                {
                    if(expression[i] == '+' || expression[i] == '-')
                    {
                        if(expression[i + 2] == '/' || expression[i + 2] == '*')
                        {
                            generateAssignmentCode();
                            break;
                        }
                        else
                        {
                            generatePlusCode();
                            break;
                        }
                    }
                    else if(expression[i] == '/' || expression[i] == '*')
                    {
                        generateDivCode();
                        break;
                    }
                }
                break;

            case 3:
                printf("Enter the expression with relational operator");
                scanf("%s%s%s", &id1, &operator, &id2);
                if(((strcmp(operator, "<") == 0) || (strcmp(operator, ">") == 0) || (strcmp(operator, "<=") == 0) || (strcmp(operator, ">=") == 0) || (strcmp(operator, "==") == 0) || (strcmp(operator, "!=") == 0)) == 0)
                    printf("Expression is error");
                else
                {
                    printf("\n%d\tif %s%s%s goto %d", address, id1, operator, id2, address + 3);
                    address++;
                    printf("\n%d\t T:=0", address);
                    address++;
                    printf("\n%d\t goto %d", address, address + 2);
                    address++;
                    printf("\n%d\t T:=1", address);
                }
                break;

            case 4:
                exit(0);
        }
    }
}

void generatePlusCode()
{
    strrev(expression);
    j = length - i - 1;
    strncat(expPart1, expression, j);
    strrev(expPart1);
    printf("Three address code:\ntemp=%s\ntemp1=%c%ctemp\n", expPart1, expression[j + 1], expression[j]);
}

void generateDivCode()
{
    strncat(expPart1, expression, i + 2);
    printf("Three address code:\ntemp=%s\ntemp1=temp%c%c\n", expPart1, expression[i + 2], expression[i + 3]);
}

void generateAssignmentCode()
{
    strrev(expression);
    j = length - i - 1;
    strncat(expPart1, expression, j);
    strrev(expPart1);
    printf("Three address code:\ntemp=%s\ntemp1=%c%ctemp\n", expPart1, expression[j + 1], expression[j]);
}
