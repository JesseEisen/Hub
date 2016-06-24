#!/usr/bin/env  bash

# This tool is used to insert url into file 
# and sync to github

function CreateNewDay()
{
	LineNo=`grep -n content index.html | cut -b 1,2`
	echo "$1"
	sed -i "${LineNo} a${1}" index.html
	let LineNo=LineNo+1
	echo "$2"
	sed -i "${LineNo} a${2}" index.html
	let LineNo=LineNo+1
	sed -i "${LineNo} a${3}" index.html
}

function InsertNewOne()
{
	LineNo=`grep -n ul index.html|head -1|cut -b 1,2`
	sed -i "${LineNo} a${1}" index.html
}

function usage ()
{
	echo "Usage: gatherUrl [-n|i] description url "
	echo "       gatherUrl -u comment"
	echo ""
	echo "Example:"
	echo -e "\t gatherUrl -n github_link https://github.com/JesseEisen"
	exit -1
}

if [ "$#" -gt 3 ];then
   usage
fi   

dates=`date +%F_%b_%a | tr '-' '.'|tr '_' ' '`
header2=" <h2>""$dates""</h2><ul>"
desc=`echo "$2" | tr '_' " "`
item=" <li><a herf=\""$3"\">"$desc"</a></li>"
end=" </ul>"


case $1 in
	-n) 
		CreateNewDay "$header2" "$item" "$end"
	;;
	-i) 
		InsertNewOne "$item"
	;;
	-u)
		git pull
		git add .
		git commit -m "$2"
		git push -u origin gh-pages
		echo "push to github done"
		;;
	*)  echo "wrong flag"
		usage
	;;
esac

echo "done"

