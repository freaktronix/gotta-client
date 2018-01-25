/* Version: 0.0.1
*  Datum: 22.01.2018
*  Beschreibung: Konsolenprogramm fuer Benutzereingabe
*  -Benutzernamen enthalten keine Leerzeichen und bestehen aus einem Wort
*  -Benutzernamen haben eine max. Laenge
*  -Laengere Namen werden "abgeschnitten"
*/


#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>

#define IUsernameLen 16 							// Maximale Laenge eines Benutzernamens
#define IUsernameLen_scanf "%" IUsernameLen "s" 	// 

#define IUserpasswordLen 32 						// Maximale Laenge eines Benutzernamens
#define IUserpasswordLen_scanf "%" IUsernameLen "s" // 

int main(void)
{
	int iSocket, iConnect;	
	char cUsername[iUsernameLen];			// Benutzername
	char cUserpassword[iUserpasswordLen];	// Benutzerpasswort

	memset(cUsername, 0, sizeof(char) * IUsernameLen);
	memset(cUserpasword, 0, sizeof(char) * IUserpasswordLen);

	printf("Willkommen bei gotta.\n\nBitte geben Sie Ihren Benutzernamen ein: ");
	scanf("IUsernameLen_scanf", &cUsername[0]);

	printf("Bitte geben Sie Ihr Passwort ein: ");
	scanf("IUserpasswordLen_scanf", &cUserpassword[0]);

	iSocket = socket(AF_INET, SOCK_STREAM, 0);

	if(iSocket < 0)
		return iSocket;

	// iConnect = connect(iSocket, );	

	return 0;
}
