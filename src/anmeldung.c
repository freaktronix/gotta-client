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
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

//#define USERNAME 16 					// Maximale Laenge eines Benutzernamens
//#define USERPASSWORD 32 				// Maximale Laenge eines Benutzernamens
#define PORT 17420
#define IP "192.168.0.47"

//argv[0] = Programmname
//argv[n] = Uebergabeparameter(bei programmstart)

int main(int argc, char *argv[]) 
{
	int iStatus = 0;
	int iSocket = -1, iConnect = -1, iSend = -1;
	unsigned long addr;	
	char cUsername[USERNAME];			// Benutzername
	char cUserpassword[USERPASSWORD];		// Benutzerpasswort
	
	memset(cUsername, 0, sizeof(char) * USERNAME);
	memset(cUserpassword, 0, sizeof(char) * USERPASSWORD);

	struct sockaddr_in server;

	memset(&server, 0, sizeof(server));

	addr = inet_addr(IP);
	memcpy((char*)&server.sin_addr, &addr, sizeof(addr));
	server.sin_family = AF_INET;
	server.sin_port = htons(PORT);

	printf("Willkommen bei gotta.\nBitte geben Sie Ihren Benutzernamen ein: ");
	scanf("%s", &cUsername[0]);

	printf("Bitte geben Sie Ihr Passwort ein: ");
	scanf("%s", &cUserpassword[0]);

	iSocket = socket(AF_INET, SOCK_STREAM, 0);	// AF_INET = IPv4; SOCK_STREAM = TCP

	printf("%s \n", strerror(errno));

	if(iSocket < 0)
		iStatus |= 0x01;
	else
		iConnect = connect(iSocket, (struct sockaddr*)&server, sizeof(server));

	printf("%s \n", strerror(errno));

	if(iConnect < 0)
	 	iStatus |= 0x02;
	else	
		iSend = send(iSocket, &cUsername, strlen(cUsername), 0);

	printf("%s \n", strerror(errno));

	if(iSend < 0)
		iStatus |= 0x04;
	else		
		iSend = send(iSocket, &cUserpassword, strlen(cUserpassword), 0);

	printf("%s \n", strerror(errno));

	if(iSend < 0)
		iStatus |= 0x08;

	close(iSocket);

	switch(iStatus)
	{
		case 0x00:
			printf("Sendevorgang war erfolgreich!\n");
			break;

		default:
			printf("Verbindungsfehler: %x !\n", iStatus);
			break;				
	}

	return iStatus;
}
