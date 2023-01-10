#!/bin/bash

function print_data
{

	printf "$2$1HOSTNAME${NoColor} = $4$3$HOSTNAME${NoColor}\n"
	printf "$2$1TIMEZONE${NoColor} = $4$3$TIMEZONE${NoColor}\n"
	printf "$2$1OS${NoColor} = $4$3$OS${NoColor}\n"
	printf "$2$1DATE${NoColor} = $4$3$DATE${NoColor}\n"
	printf "$2$1UPTIME${NoColor} = $4$3$UPTIME${NoColor}\n"
	printf "$2$1UPTIME_SEC${NoColor} = $4$3$UPTIME_SEC${NoColor}\n"
	printf "$2$1IP${NoColor} = $4$3$IP${NoColor}\n"
	printf "$2$1MASK${NoColor} = $4$3$MASK${NoColor}\n"
	printf "$2$1GATEWAY${NoColor} = $4$3$GATEWAY${NoColor}\n"
	printf "$2$1RAM_TOTAL${NoColor} = $4$3$RAM_TOTAL${NoColor}\n"
	printf "$2$1RAM_USED${NoColor} = $4$3$RAM_USED${NoColor}\n"
	printf "$2$1RAM_FREE${NoColor} = $4$3$RAM_FREE${NoColor}\n"
	printf "$2$1SPACE_ROOT${NoColor} = $4$3$SPACE_ROOT${NoColor}\n"
	printf "$2$1SPACE_ROOT_USED${NoColor} = $4$3$SPACE_ROOT_USED${NoColor}\n"
	printf "$2$1SPACE_ROOT_FREE${NoColor} = $4$3$SPACE_ROOT_FREE${NoColor}\n"
}

function print_default_info
{
	printf "Column 1 background = default"; get_color_default ${defaultcolorbackground}
	printf "Column 1 font color = default"; get_color_default ${defaultcolorfont}
	printf "Column 2 background = default"; get_color_default ${defaultcolorbackground}
	printf "Column 2 font color = default"; get_color_default ${defaultcolorfont}
}

function print_color_info
{
	printf "Column 1 background = ${column1_background}"; get_color ${column1_background}
	printf "Column 1 font color = ${column1_font_color}"; get_color ${column1_font_color}
	printf "Column 2 background = ${column2_background}"; get_color ${column2_background}
	printf "Column 2 font color = ${column2_font_color}"; get_color ${column2_font_color}
}

function get_color
{
	case "$1" in
			1) printf " (white)\n";;
			2) printf " (red)\n";;
			3) printf " (green)\n";;
			4) printf " (blue)\n";;
			5) printf " (purple)\n";;
			6) printf " (black)\n";;
	esac
}

function get_color_default
{
	case "$1" in
			"\e[1;37m") printf " (white)\n";;
			"\e[0;31m") printf " (red)\n";;
			"\e[0;32m") printf " (green)\n";;
			"\e[0;34m") printf " (blue)\n";;
			"\e[0;35m") printf " (purple)\n";;
			"\e[0;30m") printf " (black)\n";;
			"\e[47m") printf " (white)\n";;
			"\e[41m") printf " (red)\n";;
			"\e[42m") printf " (green)\n";;
			"\e[44m") printf " (blue)\n";;
			"\e[45m") printf " (purple)\n";;
			"\e[40m") printf " (black)\n";;
	esac
}