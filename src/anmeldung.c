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

#define USERNAME 16 					// Maximale Laenge eines Benutzernamens
#define USERPASSWORD 32 				// Maximale Laenge eines Benutzernamens

int main(void)
{
	int iSocket, iConnect;	
	char cUsername[USERNAME];			// Benutzername
	char cUserpassword[USERPASSWORD];		// Benutzerpasswort

	memset(cUsername, 0, sizeof(char) * USERNAME);
	memset(cUserpasword, 0, sizeof(char) * USERPASSWORD);

	printf("Willkommen bei gotta.\nBitte geben Sie Ihren Benutzernamen ein: ");
	scanf("%s", &cUsername[0]);

	printf("Bitte geben Sie Ihr Passwort ein: ");
	scanf("%s", &cUserpassword[0]);

	iSocket = socket(AF_INET, SOCK_STREAM, 0);

	if(iSocket < 0)
		return iSocket;

	// iConnect = connect(iSocket, );	

	return 0;
}
