#include <stdio.h>
#include <conio.h>
#include <cstring>

int main()
{
    int i; // number 1-4;
    char y; // to continue use program (y=yes n=no)
    char usr[50];// saved username, 50 is limited character
    char pass[50];// saved password (NO SECURITYYYYYYY)

	//check key username & password (for comparision with usr or pass)
    char inputtedUsr[50]; // key username
    char inputtedPass[50]; // key password

	//account creation check
	bool _hasAcc=false; //prevent create more than 1 account
    bool _isYou=false; //to check that you try login your account (even you forgot ur password) or not (as same as hasAcc but check that is it actually youuu???)
    do
	{
		printf("\n|********************************************************|\n");
	    printf("|-----------<LOG IN REGISTER PROGRAM COMPLETE>-----------|\n");
		printf("|________________________________________________________|\n");
	    printf("\nPRESS 1 to Log In\nPRESS 2 to Sign Up\nPRESS 3 to Reset Password\nPRESS 4 to Exit\n\nEnter Number: ");
	    scanf("%d", &i);

		getchar();

	    switch(i)
	    {
	    	case 1: // Log In
	    		if (_hasAcc) {
		    		printf("Enter Your Username: \n");
					fgets(inputtedUsr, sizeof(inputtedUsr), stdin);
					inputtedUsr[strcspn(inputtedUsr, "\n")] = '\0';

					printf("Enter Your Password: \n");
					fgets(inputtedPass, sizeof(inputtedPass), stdin);
					inputtedPass[strcspn(inputtedPass, "\n")] = '\0';

					if (strcmp(inputtedUsr, usr) == 0 && strcmp(inputtedPass, pass) == 0) //check username & password
						printf("Log In Successfully\n");
					else
						printf("Wrong Username or Password\n"); //let's user figure it out, That's how most log in website work Maybe?

		    		_isYou = true;
					break;
		    	}else
		    		printf("You don't have an account yet or Already Log in\n");
	    		break;
	    	case 2: // Create Account
				if (!_hasAcc) {
					printf("Enter Your Username: \n");
					fgets(inputtedUsr, sizeof(inputtedUsr), stdin);
					inputtedUsr[strcspn(inputtedUsr, "\n")] = '\0';
					strcpy(usr, inputtedUsr);

					printf("Enter Your Password: \n");
					fgets(inputtedPass, sizeof(inputtedPass), stdin);
        			inputtedPass[strcspn(inputtedPass, "\n")] = '\0';
					strcpy(pass, inputtedPass);
					_hasAcc = true;
					printf("Account Create Successfully \n");
				}else
					printf("You already have an Account, The maximum Account is 1 \n");
				break;
	    	case 3: //Reset Password if you forgot your password
	    		if (_isYou) {
		    		printf("Enter Your New Password: \n");
					fgets(inputtedPass, sizeof(inputtedPass), stdin);
        			inputtedPass[strcspn(inputtedPass, "\n")] = '\0';
					strcpy(pass, inputtedPass);
					printf("Done! Password reset \n");
		    	}else
		    		printf("You Don't Create Your Account Yet...'");
	    		break;
	    	case 4: //Closed Program
				//printf("Exit");
	    		return 0; // closed program
	    	default: //Unlisted Keys
	    		printf("INVALID KEY!");
		}
	    printf("\nDo you still want to using this Program? [ Y / N ] :  ");
	    	y = getche();
    }                                            
        while(y == 'y' || y == 'Y');
}
