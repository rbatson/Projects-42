#!/bin/bash

function print_data
{
	printf "$1$2HOSTNAME${NoColor} = $3$4$HOSTNAME${NoColor}\n"
	printf "$1$2TIMEZONE${NoColor} = $3$4$TIMEZONE${NoColor}\n"
	printf "$1$2OS${NoColor} = $3$4$OS${NoColor}\n"
	printf "$1$2DATE${NoColor} = $3$4$DATE${NoColor}\n"
	printf "$1$2UPTIME${NoColor} = $3$4$UPTIME${NoColor}\n"
	printf "$1$2UPTIME_SEC${NoColor} = $3$4$UPTIME_SEC${NoColor}\n"
	printf "$1$2IP${NoColor} = $3$4$IP${NoColor}\n"
	printf "$1$2MASK${NoColor} = $3$4$MASK${NoColor}\n"
	printf "$1$2GATEWAY${NoColor} = $3$4$GATEWAY${NoColor}\n"
	printf "$1$2RAM_TOTAL${NoColor} = $3$4$RAM_TOTAL${NoColor}\n"
	printf "$1$2RAM_USED${NoColor} = $3$4$RAM_USED${NoColor}\n"
	printf "$1$2RAM_FREE${NoColor} = $3$4$RAM_FREE${NoColor}\n"
	printf "$1$2SPACE_ROOT${NoColor} = $3$4$SPACE_ROOT${NoColor}\n"
	printf "$1$2SPACE_ROOT_USED${NoColor} = $3$4$SPACE_ROOT_USED${NoColor}\n"
	printf "$1$2SPACE_ROOT_FREE${NoColor} = $3$4$SPACE_ROOT_FREE${NoColor}\n"
}
