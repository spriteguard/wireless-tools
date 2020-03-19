#include <stdio.h>
#include "iwlib.h"

int main(int argc, char **argv)
{
		wireless_scan_head scanHead;
		wireless_scan *scanResult;
		int sock = iw_sockets_open();
		iw_scan(sock, "wlo1", 29, &scanHead);
		scanResult = scanHead.result;
		while( scanResult ) {
				printf("%s - %x\n", scanResult->b.essid, scanResult->b.auth);
				scanResult = scanResult->next;
		}

		return 0;
}
