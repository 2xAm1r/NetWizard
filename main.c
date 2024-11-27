#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void wifi();
void port();
void listConnectedDevices();
void setDNS();
void resetDNS();
void showNetworkAdaptersInfo();
void manageFirewall();
void manageDHCP();
void checkServerPing();
void mainMenu();
void clearScreen();
char adapterName[50];

int main()
{
    mainMenu();
    return 0;
}

void clearScreen()
{
    system("cls");
    system("color F");
}

void mainMenu()
{
    int mode;
    while (1)
    {
        clearScreen();

        printf("\t\t\t\t\tCreated By https://github.com/2xAm1r\n\n");
        printf("\t\tNetWizard Pro");
        printf("\t\t\t\t\t\t\t\tVERSION 1.0.0\n\n");

        printf("\n\n\t\t\tSelect Your Mode:\n\n");
        printf("\t\t\t\t\t\t[1] Wifi Password\n");
        printf("\t\t\t\t\t\t[2] Check Open Port\n");
        printf("\t\t\t\t\t\t[3] List Connected Devices\n");
        printf("\t\t\t\t\t\t[4] Show Network Adapter Info\n");
        printf("\t\t\t\t\t\t[5] Manage Firewall\n");
        printf("\t\t\t\t\t\t[6] Check Server Ping\n");
        printf("\t\t\t\t\t\t[7] Set DNS\n");
        printf("\t\t\t\t\t\t[8] Reset DNS\n");
        printf("\t\t\t\t\t\t[0] Exit\n");

        char option;
        scanf(" %c", &option);

        if (option == '0')
        {
            return;
        }

        switch (option)
        {
        case '1':
            wifi();
            break;

        case '2':
            port();
            break;

        case '3':
            listConnectedDevices();
            break;

        case '4':
            showNetworkAdaptersInfo();
            break;

        case '5':
            manageFirewall();
            break;

        case '6':
            checkServerPing();
            break;

        case '7':
            setDNS();
            break;

        case '8':
            resetDNS();
            break;

        case '0':
            clearScreen();
            exit(0);
            break;

        default:
            printf("Invalid option. Please try again.\n");
            system("pause");
            break;
        }
    }
}

void wifi()
{
    int back;
    while (1)
    {
        clearScreen();
        printf("\nFetching WiFi profiles and passwords...\n");
        system("for /f \"tokens=2 delims=:\" %i in ('netsh wlan show profiles ^| findstr \"All User Profile\"') do @echo %i & netsh wlan show profile name=%i key=clear | findstr \"Key Content\"");

        printf("\n\n[0] Back\n");
        char backOption;
        scanf(" %c", &backOption);

        if (backOption == '0')
        {
            break;
        }
    }
}

void port()
{
    int back;
    while (1)
    {
        int portNum;
        char ipAddress[100];
        char command[150];

        clearScreen();
        printf("\nEnter the IP address to scan: ");
        scanf("%s", ipAddress);
        printf("Enter the port number to check: ");
        scanf("%d", &portNum);

        sprintf(command, "powershell -Command \"Test-NetConnection -ComputerName %s -Port %d\"", ipAddress, portNum);

        printf("\nChecking port %d on %s...\n", portNum, ipAddress);
        system(command);

        printf("\n\n[0] Back\n");
        char backOption;
        scanf(" %c", &backOption);

        if (backOption == '0')
        {
            break;
        }
    }
}

void listConnectedDevices()
{
    int back;
    while (1)
    {
        clearScreen();
        printf("\nFetching list of connected devices...\n");
        system("arp -a");

        printf("\n\n[0] Back\n");
        char backOption;
        scanf(" %c", &backOption);

        if (backOption == '0')
        {
            break;
        }
    }
}

void showNetworkAdaptersInfo()
{
    clearScreen();
    printf("Fetching network adapters information...\n");

    system("ipconfig");

    printf("\n\n[0] Back\n");
    char backOption;
    scanf(" %c", &backOption);

    if (backOption == '0')
    {
        return;
    }
}

void manageFirewall()
{
    int choice;
    char command[200];

    while (1)
    {
        clearScreen();
        printf("Select an option to manage the firewall:\n");
        printf("[1] Check Firewall Status\n");
        printf("[2] Enable Firewall\n");
        printf("[3] Disable Firewall\n");
        printf("[0] Back\n");

        scanf("%d", &choice);

        if (choice == 0)
            break;

        if (choice == 1)
        {
            printf("Checking Firewall Status...\n");
            system("netsh advfirewall show allprofiles");
        }
        else if (choice == 2)
        {
            printf("Enabling Firewall...\n");
            system("netsh advfirewall set allprofiles state on");
        }
        else if (choice == 3)
        {
            printf("Disabling Firewall...\n");
            system("netsh advfirewall set allprofiles state off");
        }
        else
        {
            printf("Invalid choice. Try again.\n");
            continue;
        }

        system("pause");
    }
}

void checkServerPing()
{
    char server[100];
    printf("Enter the server address (e.g., google.com): ");
    scanf("%s", server);
    printf("Pinging %s...\n", server);
    char command[200];
    sprintf(command, "ping %s", server);
    system(command);
}

void setDNS()
{
    int choice, adapterChoice;
    char command[200];
    char primaryDNS[50], secondaryDNS[50];

    const char *dnsOptions[][3] = {
        {"Shecan DNS", "178.22.122.100", "185.51.200.2"},
        {"Begzar DNS", "185.55.225.25", "185.55.226.26"},
        {"403 DNS", "10.202.10.202", "10.202.10.102"},
        {"Radar DNS", "10.202.10.10", "10.202.10.11"},
        {"Electro DNS", "78.157.42.100", "78.157.42.101"}};

    while (1)
    {
        clearScreen();
        printf("Select the network adapter to configure DNS:\n");
        printf("[1] Wi-Fi\n");
        printf("[2] LAN (Ethernet)\n");
        printf("[0] Back\n");

        scanf("%d", &adapterChoice);

        if (adapterChoice == 0)
            break;

        if (adapterChoice == 1)
        {
            strcpy(adapterName, "Wi-Fi");
        }
        else if (adapterChoice == 2)
        {
            strcpy(adapterName, "Ethernet");
        }
        else
        {
            printf("Invalid choice. Please try again.\n");
            system("pause");
            continue;
        }

        printf("Select a DNS to apply:\n");
        for (int i = 0; i < 5; i++)
        {
            printf("[%d] %s\n", i + 1, dnsOptions[i][0]);
        }
        printf("[6] Custom DNS (Enter your own)\n");
        printf("[0] Back\n");

        scanf("%d", &choice);

        if (choice == 0)
            break;

        if (choice >= 1 && choice <= 5)
        {
            printf("\nSetting DNS to %s on %s...\n", dnsOptions[choice - 1][0], adapterName);
            sprintf(command, "netsh interface ip set dns name=\"%s\" source=static addr=%s register=PRIMARY", adapterName, dnsOptions[choice - 1][1]);
            system(command);
            sprintf(command, "netsh interface ip add dns name=\"%s\" addr=%s index=2", adapterName, dnsOptions[choice - 1][2]);
            system(command);
            printf("DNS successfully set to %s on %s.\n", dnsOptions[choice - 1][0], adapterName);
        }
        else if (choice == 6) // Custom DNS
        {
            printf("Enter the Primary DNS: ");
            scanf("%s", primaryDNS);
            printf("Enter the Secondary DNS (or leave blank): ");
            scanf("%s", secondaryDNS);

            printf("\nSetting Custom DNS on %s...\n", adapterName);
            sprintf(command, "netsh interface ip set dns name=\"%s\" source=static addr=%s register=PRIMARY", adapterName, primaryDNS);
            system(command);

            if (strlen(secondaryDNS) > 0)
            {
                sprintf(command, "netsh interface ip add dns name=\"%s\" addr=%s index=2", adapterName, secondaryDNS);
                system(command);
            }

            printf("Custom DNS successfully set to %s on %s.\n", primaryDNS, adapterName);
            if (strlen(secondaryDNS) > 0)
            {
                printf("Secondary DNS set to %s.\n", secondaryDNS);
            }
        }
        else
        {
            printf("Invalid selection. Try again.\n");
            system("pause");
            continue;
        }

        system("pause");
    }
}

void resetDNS()
{
    int back;
    int adapterChoice;
    char command[200];

    while (1)
    {
        clearScreen();
        printf("Select the network adapter to reset DNS:\n");
        printf("[1] Wi-Fi\n");
        printf("[2] LAN (Ethernet)\n");
        printf("[0] Back\n");

        scanf("%d", &adapterChoice);

        if (adapterChoice == 0)
            break;

        if (adapterChoice == 1)
        {
            strcpy(adapterName, "Wi-Fi");
        }
        else if (adapterChoice == 2)
        {
            strcpy(adapterName, "Ethernet");
        }
        else
        {
            printf("Invalid choice. Please try again.\n");
            system("pause");
            continue;
        }

        printf("\nResetting DNS to automatic on %s...\n", adapterName);
        sprintf(command, "netsh interface ip set dns name=\"%s\" source=dhcp", adapterName);
        system(command);

        printf("DNS reset successfully to automatic on %s.\n", adapterName);
        system("pause");
    }
}