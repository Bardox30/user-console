#include <stdio.h>
#include <string.h>

int main()
{    
    char user[100][20], pass[100][10], userSearch[20], passSearch[10], tempUser[20], tempPass[10], menuRegister;
    int found = 0; // 1 (true) if it is found
    int inner, outer, didSwap, ctr, menu, plusPass=0, plussUser=0;

    //  ALGORITHM
    for (outer=0; outer<99; outer++)
    {
        didSwap=0; // Becomes 1 (true) if list is not yet ordered
        for (inner=outer; inner<100; inner++) 
        {
            if (strcmp(user[inner], user[outer])<0)
            {
                strcpy(tempUser, user[inner]);    
                strcpy(tempPass, pass[inner]); 

                strcpy(user[inner], user[outer]);
                strcpy(pass[inner], pass[outer]);
                strcpy(user[outer], tempUser);
                strcpy(pass[outer], tempPass);
                didSwap = 1; 
            }
        }
        if (didSwap == 0)
        {
            break;
        }
    }

    // MENU'S LOOP
    
    do
    {
        printf("\nWelcome to this menu. Choose an option.\n\n(1)LOGIN\n(2)REGISTER\n(3)LISTAR USUARIOS\n(4)QUIT\n\n");
        printf("Go to: ");
        scanf(" %d", &menu);
        switch (menu)
        {
        //  LOGIN
        case 1:
            system("cls");
            printf("User: ");
            scanf(" %s", userSearch);
            printf("Password: ");
            scanf(" %s", passSearch);


            for (ctr=0; ctr<100; ctr++)
            {
                if ((strcmp(userSearch, user[ctr])==0) && (strcmp(passSearch, pass[ctr])==0)) // Do they match?
                {
                    found = 1; 
                    break;      
                }

            }

            if (found)
            {
                printf("You entered sucessfully, %s.", user[ctr]);
            }
            else    
            {
                printf("Some of the data you have entered is uncorrect.");
                printf("\n %s was not found.\n", userSearch);
            }
            break;
        
        //  REGISTER
        case 2:            
            system("cls");
            printf("\nWelcome to register, you can create a new user here.\n\n");
            printf("Do you want to create a new user? (Y/N): ");
            scanf(" %c", &menuRegister);
            if((menuRegister=='y') || (menuRegister=='Y'))
            {
                printf("\nFine. Let\'s create a new user!!\n");
                printf("Write the name for the user: ");
                scanf("%s", &user[plussUser]);
                printf("What is you password for the new user: ");
                scanf("%s", &pass[plusPass]);
                plussUser++;
                plusPass++;
            }
            else
            {
                printf("\nOkay. We\'ll return to the menu then.\n");
            }

            break;
        
        // LIST ALL USERS
        case 3:
            system("cls");            
            printf("List of user:\n");
            for(ctr=0; ctr<plussUser; ctr++)
            {
                printf("%s\n", user[ctr]);
            }
            break;

        default:
            printf("\nPlease insert a valid option please.\n");
            break;
        }
    } while (menu!=4);
    
    return(0);
}
