
#include <stdio.h>
#include <math.h>
#include <string.h>

using namespace std;

float usd_bs(float cash, float &cambio)
{

    cambio = cash * 30.1;
    return cambio;
}

float usd_mxn(float cash, float &cambio)
{

    cambio = cash * 16.79;
    return cambio;
}

float bs_usd(float cash, float &cambio)
{

    cambio = cash * 0.031;
    return cambio;
}

float bs_mxn(float cash, float &cambio)
{

    cambio = cash * 0.53;
    return cambio;
}

float mxn_bs(float cash, float &cambio)
{

    cambio = cash * 1.89;
    return cambio;
}

float mxn_usd(float cash, float &cambio)
{

    cambio = cash * 0.060;
    return cambio;
}

int main()
{
    char country[50], option[50], option2[50], country_money[50];
    float cash, cambio;

    printf("Welcome to the automated system for currency conversion!\nPlease choose a country's currency:\n");
    printf("1. USD\n2. Bs\n3. MXN\n");
    scanf("%s", option);

    while (strcmp(option, "1") != 0 && strcmp(option, "2") != 0 && strcmp(option, "3"))
    {
        printf("Comando no admitido\n");
        scanf("%s", option);
    }

    if (strcmp(option, "1") == 0)
    {
        strcpy(country, "USD");
    }

    else if (strcmp(option, "2") == 0)
    {
        strcpy(country, "Bs");
    }

    else if (strcmp(option, "3") == 0)
    {
        strcpy(country, "MXN");
    }

    printf("Your money is currently in %s.\n", country);
    printf("please, tell us, how much money do you have.\n");
    scanf("%f", &cash);
    printf("You have: %.2f %s\n", cash, country);

    do
    {
        printf("Do you want to see your money in other money types? (y/n) ");
        scanf("%s", option2);

        switch (option2[0])
        {

        case 'y':


            do
            {
                printf("Choose an option.\n");
                printf("1. USD\n");
                printf("2. Bs \n");
                printf("3. MXN\n");

                scanf("%s", country_money);

            } while (strcmp(country_money, "1") != 0 && strcmp(country_money, "2") != 0 && strcmp(country_money, "3") != 0);


            if (strcmp(country, "USD") == 0 && strcmp(country_money, "2") == 0)
            {
                usd_bs(cash, cambio);
                strcpy(country_money, "Bs");
            }

            else if (strcmp(country, "USD") == 0 && strcmp(country_money, "3") == 0)
            {
                usd_mxn(cash, cambio);
                strcpy(country_money, "MXN");
            }

            else if (strcmp(country, "Bs") == 0 && strcmp(country_money, "1") == 0)
            {
                bs_usd(cash, cambio);
                strcpy(country_money, "USD");
            }

            else if (strcmp(country, "Bs") == 0 && strcmp(country_money, "3") == 0) 
            {
                bs_mxn(cash, cambio);
                strcpy(country_money, "MXN");
            }

            else if (strcmp(country, "MXN") == 0 && strcmp(country_money, "1") == 0)
            {
                mxn_usd(cash, cambio);
                strcpy(country_money, "USD");
            }

            else if (strcmp(country, "MXN") == 0 && strcmp(country_money, "2") == 0)
            {
                mxn_bs(cash, cambio);
                strcpy(country_money, "Bs");
            }

            else
            {
                printf("Error\n");
            }

            printf("Thank you, your have %.2f %s.\n", cambio, country_money);
break;

        case 'n':
            printf("Entendido, tenga buen dia.\n");
            break;

        default:
            printf("Error\n");
            break;
        }
    } while (strcmp(option2, "y") != 0 && strcmp(option2, "n") != 0);

    printf("Thanks for using!");
    return 0;
}